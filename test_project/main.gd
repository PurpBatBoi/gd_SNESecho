extends Node2D

# Puts AudioEffectSNESEcho on the Master bus and plays a short pluck every
# 1.5 seconds so the echo can be heard. Tweak the effect in the Audio panel
# (bottom dock) while the scene runs.

const MIX_RATE := 32000

func _ready() -> void:
	var echo := AudioEffectSNESEcho.new()
	echo.echo_delay = 5
	echo.echo_feedback = 70
	AudioServer.add_bus_effect(0, echo)

	var player := AudioStreamPlayer.new()
	player.stream = make_pluck()
	add_child(player)

	var timer := Timer.new()
	timer.wait_time = 1.5
	timer.autostart = true
	timer.timeout.connect(player.play)
	add_child(timer)
	player.play()

func make_pluck() -> AudioStreamWAV:
	var frames := MIX_RATE / 8
	var data := PackedByteArray()
	data.resize(frames * 2)
	for i in frames:
		var t := float(i) / MIX_RATE
		var s := sin(TAU * 440.0 * t) * exp(-t * 30.0) * 0.6
		data.encode_s16(i * 2, int(s * 32767.0))
	var wav := AudioStreamWAV.new()
	wav.format = AudioStreamWAV.FORMAT_16_BITS
	wav.mix_rate = MIX_RATE
	wav.data = data
	return wav
