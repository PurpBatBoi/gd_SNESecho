#pragma once

#include "snes_echo_processor.hpp"

#include <godot_cpp/classes/audio_effect.hpp>
#include <godot_cpp/classes/audio_effect_instance.hpp>

using namespace godot;

class AudioEffectSNESEcho;

class AudioEffectSNESEchoInstance : public AudioEffectInstance {
	GDCLASS(AudioEffectSNESEchoInstance, AudioEffectInstance)
	friend class AudioEffectSNESEcho;

	Ref<AudioEffectSNESEcho> base;
	SnesEchoProcessor processor;

protected:
	static void _bind_methods() {}

public:
	void _process(const void *p_src_buffer, AudioFrame *p_dst_buffer, int32_t p_frame_count) override;
	// Keep running on a silent bus so the echo tail rings out.
	bool _process_silence() const override { return true; }
};

// The SNES S-DSP echo (delay + 8-tap FIR + feedback) as an audio bus effect.
// Properties take the hardware register values, so SNES presets copy over.
class AudioEffectSNESEcho : public AudioEffect {
	GDCLASS(AudioEffectSNESEcho, AudioEffect)

	SnesEchoParams params;

protected:
	static void _bind_methods();

public:
	Ref<AudioEffectInstance> _instantiate() override;

	const SnesEchoParams &get_params() const { return params; }

	void set_echo_delay(int p_blocks);
	int get_echo_delay() const;

	void set_echo_feedback(int p_feedback);
	int get_echo_feedback() const;

	void set_echo_volume_left(int p_volume);
	int get_echo_volume_left() const;
	void set_echo_volume_right(int p_volume);
	int get_echo_volume_right() const;

	void set_dry_volume_left(int p_volume);
	int get_dry_volume_left() const;
	void set_dry_volume_right(int p_volume);
	int get_dry_volume_right() const;

	void set_fir_coefficient(int p_tap, int p_coefficient);
	int get_fir_coefficient(int p_tap) const;

	void set_echo_write_enabled(bool p_enabled);
	bool is_echo_write_enabled() const;
};
