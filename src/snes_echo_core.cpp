#include "snes_echo_core.hpp"

namespace {

int clamp16(int p_value) {
	return p_value > 0x7FFF ? 0x7FFF : (p_value < -0x8000 ? -0x8000 : p_value);
}

// FIR: taps oldest*FIR0 ... newest*FIR7, each product SAR 6 and wrapped to 16
// bits. The first seven additions wrap; only the final (newest) one saturates.
// The output is a 15-bit sample, so its low bit is dropped before EVOL and EFB.
int filter(const std::array<int16_t, 8> &p_history, uint8_t p_newest, const std::array<int8_t, 8> &p_fir) {
	int sum = 0;
	for (int tap = 0; tap < 8; ++tap) {
		const int slot = (p_newest + 1 + tap) & 7;
		const int product = static_cast<int16_t>((p_history[slot] * p_fir[tap]) >> 6);
		sum = tap < 7 ? static_cast<int16_t>(sum + product) : clamp16(sum + product);
	}
	return sum & ~1;
}

// Write-back: send plus FIR*EFB SAR 7. The multiply wraps at 16 bits, the add
// saturates, and bit 0 is cleared because the entry holds a 15-bit sample.
int16_t write_back(int p_send, int p_fir_out, int p_feedback) {
	return static_cast<int16_t>(clamp16(p_send + static_cast<int16_t>((p_fir_out * p_feedback) >> 7)) & ~1);
}

} // namespace

void SnesEchoCore::reset() {
	*this = SnesEchoCore();
}

SnesEchoSample SnesEchoCore::step(const SnesEchoParams &p_params, SnesEchoSample p_send) {
	// The entry's words leave the ring (SAR 1 recovers the 15-bit sample) and
	// become the newest FIR history slot.
	history_left[history_pos] = static_cast<int16_t>(ring_left[index] >> 1);
	history_right[history_pos] = static_cast<int16_t>(ring_right[index] >> 1);
	const int out_left = filter(history_left, history_pos, p_params.fir);
	const int out_right = filter(history_right, history_pos, p_params.fir);
	history_pos = (history_pos + 1) & 7;

	// The same entry is written back after it was read, so an entry's data
	// returns one full ring later.
	if (p_params.write_enabled) {
		ring_left[index] = write_back(p_send.left, out_left, p_params.feedback);
		ring_right[index] = write_back(p_send.right, out_right, p_params.feedback);
	}

	// EDL is applied only when the index is 0, so a mid-ring change waits for
	// the next wrap. EDL 0 collapses to a single-entry ring.
	if (index == 0) {
		length = static_cast<uint16_t>((p_params.delay & 0x0F) << 9);
	}
	if (++index >= length) {
		index = 0;
	}

	return {
		static_cast<int16_t>((out_left * p_params.echo_volume_left) >> 7),
		static_cast<int16_t>((out_right * p_params.echo_volume_right) >> 7),
	};
}
