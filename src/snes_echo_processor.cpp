#include "snes_echo_processor.hpp"

#include <algorithm>
#include <cmath>

namespace {

constexpr float MAX_SAMPLE = 32767.0f / 32768.0f;

int16_t to_int16(float p_value) {
	return int16_t(std::lrint(std::clamp(p_value, -1.0f, MAX_SAMPLE) * 32768.0f));
}

} // namespace

void SnesEchoProcessor::configure(int p_mix_rate) {
	const int snes_rate = SnesEchoCore::SAMPLE_RATE;

	// The upsampler is primed with silence so pop() always succeeds once per
	// host frame: its own lookahead plus the downsampler's, in 32 kHz samples.
	const double lookahead = Resampler::half_width_for(snes_rate, p_mix_rate) +
			Resampler::half_width_for(p_mix_rate, snes_rate) * snes_rate / p_mix_rate;
	const int prime = int(std::ceil(lookahead)) + 2;

	down.configure(p_mix_rate, snes_rate);
	up.configure(snes_rate, p_mix_rate, prime);
	for (int i = 0; i < prime; ++i) {
		up.push(StereoFrame());
	}
	core.reset();

	// The priming delays the wet path by `prime` 32 kHz samples; match it.
	dry_delay.assign(size_t(std::max(1L, std::lround(double(prime) * p_mix_rate / snes_rate))), StereoFrame());
	dry_pos = 0;
}

StereoFrame SnesEchoProcessor::process(const SnesEchoParams &p_params, StereoFrame p_in) {
	down.push(p_in);
	StereoFrame send;
	while (down.pop(send)) {
		const SnesEchoSample echo = core.step(p_params, { to_int16(send.left), to_int16(send.right) });
		up.push({ echo.left / 32768.0f, echo.right / 32768.0f });
	}
	StereoFrame wet;
	up.pop(wet);

	const StereoFrame dry = dry_delay[dry_pos];
	dry_delay[dry_pos] = p_in;
	dry_pos = (dry_pos + 1) % dry_delay.size();

	// MVOL*dry plus EVOL*echo, saturating at 16 bits as the S-DSP mixer does.
	return {
		std::clamp(dry.left * p_params.dry_volume_left / 128.0f + wet.left, -1.0f, MAX_SAMPLE),
		std::clamp(dry.right * p_params.dry_volume_right / 128.0f + wet.right, -1.0f, MAX_SAMPLE),
	};
}
