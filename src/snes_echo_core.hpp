// The SNES S-DSP echo unit, one 32 kHz sample at a time, on 16-bit integers.
//
// The arithmetic is ported from Snaggletooth's S-DSP (src/dsp.cpp: stepEcho,
// filterEcho, stageEchoWrite, advanceEchoRing), MIT License,
// Copyright (c) 2026 Eric Tomasso — https://github.com/etroimcasso/Snaggletooth
// Its docs/s-dsp-behavior.md records which test ROM arbitrates each rule.

#pragma once

#include <array>
#include <cstdint>

// The S-DSP registers the echo path reads. Names follow the hardware.
struct SnesEchoParams {
	int8_t dry_volume_left = 127; // MVOLL — applied by SnesEchoProcessor, not the core
	int8_t dry_volume_right = 127; // MVOLR
	int8_t echo_volume_left = 40; // EVOLL
	int8_t echo_volume_right = 40; // EVOLR
	int8_t feedback = 70; // EFB
	std::array<int8_t, 8> fir = { 127, 0, 0, 0, 0, 0, 0, 0 }; // FIR0 (oldest) .. FIR7 (newest)
	uint8_t delay = 5; // EDL: ring length in 16 ms blocks of 512 samples, 0..15
	bool write_enabled = true; // FLG bit 5 clear
};

struct SnesEchoSample {
	int16_t left = 0;
	int16_t right = 0;
};

class SnesEchoCore {
public:
	static constexpr int SAMPLE_RATE = 32000;

	void reset();

	// Runs one sample. `send` is the echo input (the EON voices' sum on hardware).
	// Returns the FIR output after EVOL, ready to be added to the dry mix.
	SnesEchoSample step(const SnesEchoParams &p_params, SnesEchoSample p_send);

private:
	static constexpr int MAX_ENTRIES = 15 << 9;

	// Ring entries as written: 15-bit samples left-justified, bit 0 clear.
	std::array<int16_t, MAX_ENTRIES> ring_left{};
	std::array<int16_t, MAX_ENTRIES> ring_right{};
	std::array<int16_t, 8> history_left{};
	std::array<int16_t, 8> history_right{};
	uint8_t history_pos = 0;
	uint16_t index = 0;
	uint16_t length = 0;
};
