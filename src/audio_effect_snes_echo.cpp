#include "audio_effect_snes_echo.hpp"

#include <godot_cpp/classes/audio_server.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void AudioEffectSNESEchoInstance::_process(const void *p_src_buffer, AudioFrame *p_dst_buffer, int32_t p_frame_count) {
	const AudioFrame *src = static_cast<const AudioFrame *>(p_src_buffer);
	// One copy per mix block, so the editor changing a property mid-block
	// cannot split a block across two settings.
	const SnesEchoParams params = base->get_params();
	for (int32_t i = 0; i < p_frame_count; i++) {
		const StereoFrame out = processor.process(params, { src[i].left, src[i].right });
		p_dst_buffer[i].left = out.left;
		p_dst_buffer[i].right = out.right;
	}
}

Ref<AudioEffectInstance> AudioEffectSNESEcho::_instantiate() {
	Ref<AudioEffectSNESEchoInstance> instance;
	instance.instantiate();
	instance->base = Ref<AudioEffectSNESEcho>(this);
	instance->processor.configure(int(AudioServer::get_singleton()->get_mix_rate()));
	return instance;
}

void AudioEffectSNESEcho::set_echo_delay(int p_blocks) { params.delay = uint8_t(CLAMP(p_blocks, 0, 15)); }
int AudioEffectSNESEcho::get_echo_delay() const { return params.delay; }

void AudioEffectSNESEcho::set_echo_feedback(int p_feedback) { params.feedback = int8_t(CLAMP(p_feedback, -128, 127)); }
int AudioEffectSNESEcho::get_echo_feedback() const { return params.feedback; }

void AudioEffectSNESEcho::set_echo_volume_left(int p_volume) { params.echo_volume_left = int8_t(CLAMP(p_volume, -128, 127)); }
int AudioEffectSNESEcho::get_echo_volume_left() const { return params.echo_volume_left; }
void AudioEffectSNESEcho::set_echo_volume_right(int p_volume) { params.echo_volume_right = int8_t(CLAMP(p_volume, -128, 127)); }
int AudioEffectSNESEcho::get_echo_volume_right() const { return params.echo_volume_right; }

void AudioEffectSNESEcho::set_dry_volume_left(int p_volume) { params.dry_volume_left = int8_t(CLAMP(p_volume, -128, 127)); }
int AudioEffectSNESEcho::get_dry_volume_left() const { return params.dry_volume_left; }
void AudioEffectSNESEcho::set_dry_volume_right(int p_volume) { params.dry_volume_right = int8_t(CLAMP(p_volume, -128, 127)); }
int AudioEffectSNESEcho::get_dry_volume_right() const { return params.dry_volume_right; }

void AudioEffectSNESEcho::set_fir_coefficient(int p_tap, int p_coefficient) {
	ERR_FAIL_INDEX(p_tap, 8);
	params.fir[p_tap] = int8_t(CLAMP(p_coefficient, -128, 127));
}
int AudioEffectSNESEcho::get_fir_coefficient(int p_tap) const {
	ERR_FAIL_INDEX_V(p_tap, 8, 0);
	return params.fir[p_tap];
}

void AudioEffectSNESEcho::set_echo_write_enabled(bool p_enabled) { params.write_enabled = p_enabled; }
bool AudioEffectSNESEcho::is_echo_write_enabled() const { return params.write_enabled; }

void AudioEffectSNESEcho::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_echo_delay", "blocks"), &AudioEffectSNESEcho::set_echo_delay);
	ClassDB::bind_method(D_METHOD("get_echo_delay"), &AudioEffectSNESEcho::get_echo_delay);
	ClassDB::bind_method(D_METHOD("set_echo_feedback", "feedback"), &AudioEffectSNESEcho::set_echo_feedback);
	ClassDB::bind_method(D_METHOD("get_echo_feedback"), &AudioEffectSNESEcho::get_echo_feedback);
	ClassDB::bind_method(D_METHOD("set_echo_volume_left", "volume"), &AudioEffectSNESEcho::set_echo_volume_left);
	ClassDB::bind_method(D_METHOD("get_echo_volume_left"), &AudioEffectSNESEcho::get_echo_volume_left);
	ClassDB::bind_method(D_METHOD("set_echo_volume_right", "volume"), &AudioEffectSNESEcho::set_echo_volume_right);
	ClassDB::bind_method(D_METHOD("get_echo_volume_right"), &AudioEffectSNESEcho::get_echo_volume_right);
	ClassDB::bind_method(D_METHOD("set_dry_volume_left", "volume"), &AudioEffectSNESEcho::set_dry_volume_left);
	ClassDB::bind_method(D_METHOD("get_dry_volume_left"), &AudioEffectSNESEcho::get_dry_volume_left);
	ClassDB::bind_method(D_METHOD("set_dry_volume_right", "volume"), &AudioEffectSNESEcho::set_dry_volume_right);
	ClassDB::bind_method(D_METHOD("get_dry_volume_right"), &AudioEffectSNESEcho::get_dry_volume_right);
	ClassDB::bind_method(D_METHOD("set_fir_coefficient", "tap", "coefficient"), &AudioEffectSNESEcho::set_fir_coefficient);
	ClassDB::bind_method(D_METHOD("get_fir_coefficient", "tap"), &AudioEffectSNESEcho::get_fir_coefficient);
	ClassDB::bind_method(D_METHOD("set_echo_write_enabled", "enabled"), &AudioEffectSNESEcho::set_echo_write_enabled);
	ClassDB::bind_method(D_METHOD("is_echo_write_enabled"), &AudioEffectSNESEcho::is_echo_write_enabled);

	ADD_PROPERTY(PropertyInfo(Variant::INT, "echo_delay", PROPERTY_HINT_RANGE, "0,15,1,suffix:x16ms"), "set_echo_delay", "get_echo_delay");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "echo_feedback", PROPERTY_HINT_RANGE, "-128,127,1"), "set_echo_feedback", "get_echo_feedback");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "echo_write_enabled"), "set_echo_write_enabled", "is_echo_write_enabled");

	ADD_GROUP("Echo Volume", "echo_volume_");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "echo_volume_left", PROPERTY_HINT_RANGE, "-128,127,1"), "set_echo_volume_left", "get_echo_volume_left");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "echo_volume_right", PROPERTY_HINT_RANGE, "-128,127,1"), "set_echo_volume_right", "get_echo_volume_right");

	ADD_GROUP("Dry Volume", "dry_volume_");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "dry_volume_left", PROPERTY_HINT_RANGE, "-128,127,1"), "set_dry_volume_left", "get_dry_volume_left");
	ADD_PROPERTY(PropertyInfo(Variant::INT, "dry_volume_right", PROPERTY_HINT_RANGE, "-128,127,1"), "set_dry_volume_right", "get_dry_volume_right");

	ADD_GROUP("FIR Filter", "fir_");
	for (int tap = 0; tap < 8; tap++) {
		ADD_PROPERTYI(PropertyInfo(Variant::INT, "fir_" + itos(tap), PROPERTY_HINT_RANGE, "-128,127,1"), "set_fir_coefficient", "get_fir_coefficient", tap);
	}
}
