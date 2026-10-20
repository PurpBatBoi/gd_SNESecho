// Standalone tests for the Godot-free echo path. Build and run from the repo root:
//   g++ -std=c++17 -O2 -Isrc tests/snes_echo_test.cpp src/snes_echo_core.cpp src/resampler.cpp src/snes_echo_processor.cpp -o /tmp/snes_echo_test && /tmp/snes_echo_test

#include "snes_echo_core.hpp"
#include "snes_echo_processor.hpp"

#include <cmath>
#include <cstdio>
#include <vector>

static int failures = 0;

#define CHECK_EQ(actual, expected)                                                             \
	do {                                                                                       \
		const long long a_ = (actual), e_ = (expected);                                        \
		if (a_ != e_) {                                                                        \
			std::printf("FAIL %s:%d: %s == %lld, expected %lld\n", __FILE__, __LINE__, #actual, a_, e_); \
			++failures;                                                                        \
		}                                                                                      \
	} while (0)

static SnesEchoParams newest_tap_params(uint8_t p_delay) {
	SnesEchoParams p;
	p.echo_volume_left = p.echo_volume_right = 127;
	p.feedback = 0;
	p.fir = { 0, 0, 0, 0, 0, 0, 0, 127 };
	p.delay = p_delay;
	return p;
}

// An entry written now is read back one ring later: 512 samples per EDL block.
// 16384 is stored, read as 8192 (15-bit), FIR7 gives (8192*127)>>6 = 16256,
// EVOL gives (16256*127)>>7 = 16129.
static void test_impulse_returns_after_one_ring() {
	SnesEchoCore core;
	const SnesEchoParams p = newest_tap_params(1);
	for (int n = 0; n < 1100; ++n) {
		const SnesEchoSample out = core.step(p, { int16_t(n == 0 ? 16384 : 0), 0 });
		CHECK_EQ(out.left, n == 512 ? 16129 : 0);
		CHECK_EQ(out.right, 0);
	}
}

// EDL 0 is a single-entry ring: the echo is one sample late.
static void test_edl_zero_is_one_sample() {
	SnesEchoCore core;
	const SnesEchoParams p = newest_tap_params(0);
	CHECK_EQ(core.step(p, { 16384, 0 }).left, 0);
	CHECK_EQ(core.step(p, { 0, 0 }).left, 16129);
	CHECK_EQ(core.step(p, { 0, 0 }).left, 0);
}

// An EDL change waits for the ring index to wrap to 0.
static void test_edl_change_waits_for_wrap() {
	SnesEchoCore core;
	SnesEchoParams p = newest_tap_params(1);
	for (int n = 0; n < 600; ++n) {
		if (n == 100) {
			p.delay = 2;
		}
		const SnesEchoSample out = core.step(p, { int16_t(n == 0 ? 16384 : 0), 0 });
		CHECK_EQ(out.left, n == 512 ? 16129 : 0);
	}
}

// Products wrap at 16 bits, the FIR's final add saturates. With two -16384
// history samples on FIR6 = FIR7 = 127 the filter saturates to -8000h, and EFB
// -128 against it gives +8000h, which wraps to -8000h (a saturating multiply
// would write 7FFEh). Reading that entry back proves which one was written.
static void test_feedback_multiply_wraps() {
	SnesEchoCore core;
	SnesEchoParams p;
	p.echo_volume_left = p.echo_volume_right = 127;
	p.fir = { 0, 0, 0, 0, 0, 0, 127, 127 };
	p.delay = 0;
	p.feedback = 0;
	core.step(p, { -32768, 0 }); // ring <- -8000h
	core.step(p, { -32768, 0 }); // history -4000h; ring <- -8000h
	p.feedback = -128;
	core.step(p, { 0, 0 }); // FIR = -8000h; ring <- wrap(+8000h) = -8000h
	p.feedback = 0;
	// History -4000h, -4000h again: FIR saturates to -8000h, EVOL -> -32512.
	// Had the write saturated to 7FFEh this would read -2.
	CHECK_EQ(core.step(p, { 0, 0 }).left, -32512);
}

// Through the full host-rate chain, the dry path is delayed to line up with
// the wet path: an impulse's echo lands EDL*512 SNES samples after the dry one.
static void test_processor_aligns_dry_and_wet(int p_mix_rate) {
	SnesEchoProcessor processor;
	processor.configure(p_mix_rate);
	SnesEchoParams p = newest_tap_params(1);
	p.dry_volume_left = p.dry_volume_right = 127;
	p.echo_volume_left = p.echo_volume_right = 64;

	const int frames = processor.get_latency() + p_mix_rate / 20;
	std::vector<float> out(frames);
	for (int n = 0; n < frames; ++n) {
		out[n] = processor.process(p, { n == 0 ? 0.5f : 0.0f, 0.0f }).left;
	}

	const int dry_at = processor.get_latency();
	CHECK_EQ(std::lround(out[dry_at] * 1e4f), std::lround(0.5f * 127.0f / 128.0f * 1e4f));

	const double expected_wet = dry_at + 512.0 * p_mix_rate / SnesEchoCore::SAMPLE_RATE;
	int peak = dry_at + 1;
	for (int n = dry_at + 1; n < frames; ++n) {
		if (std::fabs(out[n]) > std::fabs(out[peak])) {
			peak = n;
		}
	}
	if (std::fabs(peak - expected_wet) > 1.0) {
		std::printf("FAIL %d Hz: wet peak at %d, expected %.2f\n", p_mix_rate, peak, expected_wet);
		++failures;
	}
	std::printf("%d Hz: latency %d frames, wet peak %d (expected %.2f), peak %.4f\n",
			p_mix_rate, dry_at, peak, expected_wet, out[peak]);
}

// A tone well inside the passband survives 48k -> 32k -> 48k with its level.
static void test_processor_passband_level() {
	const int rate = 48000;
	SnesEchoProcessor processor;
	processor.configure(rate);
	SnesEchoParams p = newest_tap_params(0);
	p.dry_volume_left = p.dry_volume_right = 0;
	p.echo_volume_left = p.echo_volume_right = 127;
	// The ring is read back as 15-bit samples (half scale), so FIR7 127 is a
	// gain of 127/128.
	p.fir = { 0, 0, 0, 0, 0, 0, 0, 127 };

	double peak = 0.0;
	for (int n = 0; n < rate; ++n) {
		const float x = 0.5f * float(std::sin(2.0 * 3.14159265358979 * 1000.0 * n / rate));
		const float y = processor.process(p, { x, x }).left;
		if (n > rate / 2) {
			peak = std::max(peak, double(std::fabs(y)));
		}
	}
	// Expected 0.5 * FIR 127/128 * EVOL 127/128; allow 0.1 dB for resampler
	// ripple and rounding.
	const double expected = 0.5 * 127.0 / 128.0 * 127.0 / 128.0;
	const double db = 20.0 * std::log10(peak / expected);
	if (std::fabs(db) > 0.1) {
		std::printf("FAIL passband level off by %.3f dB\n", db);
		++failures;
	}
	std::printf("1 kHz passband error %.4f dB\n", db);
}

int main() {
	test_impulse_returns_after_one_ring();
	test_edl_zero_is_one_sample();
	test_edl_change_waits_for_wrap();
	test_feedback_multiply_wraps();
	test_processor_aligns_dry_and_wet(48000);
	test_processor_aligns_dry_and_wet(44100);
	test_processor_aligns_dry_and_wet(32000);
	test_processor_passband_level();
	std::printf(failures ? "%d FAILURES\n" : "all passed\n", failures);
	return failures ? 1 : 0;
}
