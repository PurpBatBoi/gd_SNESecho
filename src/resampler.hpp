#pragma once

#include <cstdint>
#include <vector>

struct StereoFrame {
	float left = 0.0f;
	float right = 0.0f;
};

// Streaming windowed-sinc (Blackman) resampler between two fixed integer rates.
// The read position is kept as an exact fraction, so long runs never drift.
class Resampler {
public:
	// Lookahead pop() needs past the read position, in input samples.
	static double half_width_for(int p_in_rate, int p_out_rate);

	// `p_max_backlog` is how many input samples may be pushed ahead of what
	// pop() consumes, beyond its own lookahead.
	void configure(int p_in_rate, int p_out_rate, int p_max_backlog = 0);
	void reset();

	void push(StereoFrame p_frame);
	// Returns false until enough input has arrived for the next output sample.
	bool pop(StereoFrame &r_frame);

private:
	float kernel(double p_distance) const;

	int in_rate = 1;
	int out_rate = 1;
	double half_width = 0.0;
	std::vector<float> table;
	std::vector<StereoFrame> history;
	int64_t mask = 0;
	int64_t pushed = 0;
	// Read position: pos + frac / out_rate input samples.
	int64_t pos = 0;
	int64_t frac = 0;
};
