#include "resampler.hpp"

#include <algorithm>
#include <cmath>

namespace {

constexpr double PI = 3.14159265358979323846;
// Cutoff as a fraction of the lower rate's Nyquist frequency; the Blackman
// transition band fits between it and Nyquist.
constexpr double PASSBAND = 0.85;
// Sinc zero crossings on each side of the centre tap.
constexpr int ZERO_CROSSINGS = 32;
// Kernel table entries per input sample, linearly interpolated.
constexpr int PHASES = 512;

double cutoff_for(int p_in_rate, int p_out_rate) {
	// Cycles per input sample.
	return 0.5 * PASSBAND * std::min(1.0, double(p_out_rate) / p_in_rate);
}

} // namespace

double Resampler::half_width_for(int p_in_rate, int p_out_rate) {
	return ZERO_CROSSINGS / (2.0 * cutoff_for(p_in_rate, p_out_rate));
}

void Resampler::configure(int p_in_rate, int p_out_rate, int p_max_backlog) {
	in_rate = p_in_rate;
	out_rate = p_out_rate;
	half_width = half_width_for(p_in_rate, p_out_rate);

	const double cutoff = cutoff_for(p_in_rate, p_out_rate);
	table.resize(size_t(half_width * PHASES) + 2);
	for (size_t i = 0; i < table.size(); ++i) {
		const double distance = double(i) / PHASES;
		if (distance >= half_width) {
			table[i] = 0.0f;
			continue;
		}
		const double x = 2.0 * cutoff * distance;
		const double sinc = x == 0.0 ? 1.0 : std::sin(PI * x) / (PI * x);
		const double w = distance / half_width;
		const double window = 0.42 + 0.5 * std::cos(PI * w) + 0.08 * std::cos(2.0 * PI * w);
		table[i] = float(2.0 * cutoff * sinc * window);
	}

	size_t size = 1;
	while (size < size_t(2.0 * half_width) + 4 + size_t(p_max_backlog)) {
		size <<= 1;
	}
	history.assign(size, StereoFrame());
	mask = int64_t(size) - 1;
	reset();
}

void Resampler::reset() {
	std::fill(history.begin(), history.end(), StereoFrame());
	pushed = 0;
	pos = 0;
	frac = 0;
}

void Resampler::push(StereoFrame p_frame) {
	history[pushed & mask] = p_frame;
	++pushed;
}

bool Resampler::pop(StereoFrame &r_frame) {
	const double t = double(frac) / out_rate;
	const int64_t last = pos + int64_t(std::floor(t + half_width));
	if (last >= pushed) {
		return false;
	}
	const int64_t first = std::max<int64_t>(0, pos + int64_t(std::ceil(t - half_width)));

	StereoFrame out;
	for (int64_t n = first; n <= last; ++n) {
		const float h = kernel(double(pos - n) + t);
		const StereoFrame &x = history[n & mask];
		out.left += x.left * h;
		out.right += x.right * h;
	}
	r_frame = out;

	frac += in_rate;
	while (frac >= out_rate) {
		frac -= out_rate;
		++pos;
	}
	return true;
}

float Resampler::kernel(double p_distance) const {
	const double scaled = std::fabs(p_distance) * PHASES;
	const size_t i = size_t(scaled);
	if (i + 1 >= table.size()) {
		return 0.0f;
	}
	const float f = float(scaled - double(i));
	return table[i] + (table[i + 1] - table[i]) * f;
}
