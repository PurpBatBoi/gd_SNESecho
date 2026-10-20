# gd_SNESecho

The SNES S-DSP echo (delay ring, 8-tap FIR filter, feedback) as a Godot 4.5+ audio bus effect.

The echo runs at the SNES's native 32 kHz with the hardware's own 16-bit integer arithmetic. Multiplies wrap, additions saturate, samples are 15-bit, and echo-length changes wait for the ring to wrap, all as on the real chip. It is ported from the echo unit of [Snaggletooth](https://github.com/etroimcasso/Snaggletooth), an accuracy-first SNES emulator whose rules are checked against hardware test ROMs.

## Installation

There are no prebuilt releases yet, so build from source:

1. Install Git, Python, SCons and a C++ compiler.
2. Clone with submodules:
   ```sh
   git clone --recurse-submodules https://github.com/PurpBatBoi/gd_SNESecho.git
   cd gd_SNESecho
   ```
3. Build:
   ```sh
   scons target=template_debug     # editor / debug builds
   scons target=template_release   # exported games
   ```
   You can also use the menu in `python setup.py`.
4. The library is installed into `test_project/addons/gd_snesdelay/`. Copy that folder into your own project's `addons/`.

## Usage

1. Open the **Audio** panel at the bottom of the editor.
2. On a bus, click **Add Effect** and choose **AudioEffectSNESEcho**.
3. Click the effect to edit its settings in the inspector.

From code:

```gdscript
var echo := AudioEffectSNESEcho.new()
echo.echo_delay = 4
echo.echo_feedback = 108
AudioServer.add_bus_effect(AudioServer.get_bus_index("Master"), echo)
```

### Settings

Every setting takes the raw SNES register value, so presets from games copy over directly.

| Setting | Register | Range | Meaning |
|---|---|---|---|
| `echo_delay` | EDL | 0–15 | Echo length in 16 ms steps. 0 is a one-sample ring. |
| `echo_feedback` | EFB | −128–127 | How much of the FIR output is written back into the ring. |
| `echo_volume_left/right` | EVOL | −128–127 | Echo level. Negative values invert the phase. |
| `dry_volume_left/right` | MVOL | −128–127 | Dry level. 127 is about unity. |
| `fir_0` … `fir_7` | FIR0–7 | −128–127 | Filter coefficients. `fir_0` is applied to the oldest sample. 127 on a single tap passes the echo through at about unity gain. |
| `echo_write_enabled` | FLG bit 5 | on/off | Turn off to freeze the ring, so its contents keep repeating. |

### Presets

The effect is a Resource. To keep a preset, use **Save As…** from the inspector's resource menu. To use a saved preset, point the bus layout at the file: in `default_bus_layout.tres`, set the effect to an `ExtResource` that references your `.tres`.

### Copying settings from an SPC player

SPC players show the registers in hex. Convert each one to signed decimal: `00`–`7F` is 0 to 127, and `80`–`FF` is the hex value minus 256. For example, *Super Mario World*'s underground echo:

| Player shows | Enter |
|---|---|
| Delay `04` | `echo_delay = 4` |
| Feedback `6C` | `echo_feedback = 108` |
| EchoLv `15` / `15` | `echo_volume_left/right = 21` |
| MasterLv `7F` / `7F` | `dry_volume_left/right = 127` |
| FIR `FF 08 17 24 24 17 08 FF` | `fir_0`–`fir_7` = −1, 8, 23, 36, 36, 23, 8, −1 |

## Behaviour to be aware of

- **Latency:** the whole output, dry and echo, is delayed by about 2.5 ms. This comes from converting to and from 32 kHz, and it keeps the dry and echo signals aligned.
- **Clipping:** the final mix saturates at full scale, as the SNES mixer does, so a hot bus will clip.
- **Mix rate:** the effect reads Godot's mix rate when it is added to a bus. If you change the rate at runtime, re-add the effect.
- **Not emulated:** the SNES's final Gaussian/analog low-pass filter.

## Development

- `src/snes_echo_core.*` is the 32 kHz integer echo, with no Godot dependency.
- `src/resampler.*` and `src/snes_echo_processor.*` convert between the mix rate and 32 kHz and keep the dry signal aligned.
- `src/audio_effect_snes_echo.*` is the Godot `AudioEffect` wrapper.
- `test_project/` plays a looping pluck through the echo on the Master bus.
- `reference/faust/` holds the older Faust implementation, for comparison only. It isn't built.

To run the core tests:

```sh
g++ -std=c++17 -O2 -Isrc tests/snes_echo_test.cpp src/snes_echo_core.cpp src/resampler.cpp src/snes_echo_processor.cpp -o snes_echo_test && ./snes_echo_test
```

## Credits

- Echo arithmetic ported from [Snaggletooth](https://github.com/etroimcasso/Snaggletooth) by Eric Tomasso (MIT).
- Project template: [Godot++](https://github.com/nikoladevelops/godot-plus-plus).
- Reference Faust implementation: `snes-echo` by nyanpasu64 (BSD).

## License

MIT. See [LICENSE](LICENSE).
