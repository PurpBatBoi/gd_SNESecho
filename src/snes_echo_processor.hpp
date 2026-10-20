#pragma once

#include "resampler.hpp"
#include "snes_echo_core.hpp"

#include <vector>

// Runs the S-DSP echo on audio at the host mix rate. The echo send is resampled
// to 32 kHz, echoed bit-exactly by SnesEchoCore, and resampled back; the dry
// path stays at the host rate, delayed so it lines up with the wet path.
class SnesEchoProcessor {
public:
	void configure(int p_mix_rate);

	StereoFrame process(const SnesEchoParams &p_params, StereoFrame p_in);

	// Frames the whole output (dry and wet) lags the input by.
	int get_latency() const { return int(dry_delay.size()); }

private:
	SnesEchoCore core;
	Resampler down;
	Resampler up;
	std::vector<StereoFrame> dry_delay;
	size_t dry_pos = 0;
};
