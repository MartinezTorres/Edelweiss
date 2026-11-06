# Edelweiss

An MSX1 game with a Linux/SDL development build. The lumberjack rescue and
town-hall axe reward now run from Vexel; the renderer, audio, collision system,
entity storage and optimized assembly remain in the existing engine.

The original C quest is available with `GAMEPLAY=reference`. Both variants use
the same modernized build and engine, so they can be compared directly.

## Build and play

Required tools: Make, a C compiler, a C++14 compiler, Python 3, pkg-config and
SDL2 development headers for Linux; SDCC and sdasz80 for MSX. The integration
was verified with SDCC 4.2.0, SDL2 2.30.0 and openMSX 19.1.

```sh
make -j4                    # Linux executable and Konami-5 cartridge
make run                    # Linux / SDL
make run-msx                # openMSX, C-BIOS_MSX1, KonamiSCC mapper
make GAMEPLAY=reference -j4 # Retained C quest
```

Outputs are `build/vexel/linux/weiss` and `build/vexel/msx/weiss.rom`, or the
equivalent paths under `build/reference`. `make linux` and `make msx` build
only that target. The SDL game uses the existing keyboard controls: arrow keys
for movement and space for interaction; dialogue accepts the original key-row
inputs.

`CC`, `CXX`, `SDCC`, `SDASZ80`, `CFLAGS`, `MAX_ALLOCS` and `BUILD_ROOT` are
overridable. Use a fresh `BUILD_ROOT` when changing toolchains or compilation
flags. SDCC explicitly uses `--sdcccall 0` to match the existing assembly ABI.
The default allocation search budget is 2,000, adjustable with `MAX_ALLOCS`.

The runtime and module linker are pinned under `vendor/sdcc_msx`; provenance
and local patches are recorded in its [UPSTREAM.md](vendor/sdcc_msx/UPSTREAM.md).
Builds do not access the network, the old `sdcc_msx` symlink/working directory,
Java, or stale generated files in `tmp/`. Required graphics are already checked
in as C. `Makefile.legacy` preserves the old build recipe for reference.
Historical `out/` and `tmp/` artifacts are not overwritten.

This remains an independent Git repository. No part of the game is added to
the surrounding Vexel repository.

## Edit the gameplay

The source is [gameplay/lumberjack.vx](gameplay/lumberjack.vx). It receives a
phase and an event, and returns three bytes: next phase, command and text ID.
It does not receive entity pointers, resource addresses or a copy of the world.

```sh
# When this repository is in vexel_lang/ext/edelweiss:
make -C ../..
make generate
make -j4
make test

# When Vexel lives elsewhere:
make generate VEXEL=/path/to/vexel_lang/build/vexel
```

The portable generated C, interface, resolution report and input hashes are
kept in `generated/lumberjack`. An ordinary game build uses that projection
without requiring a Vexel installation. A source/projection hash mismatch
fails the build with instructions to regenerate.

The [integration notes](docs/vexel-quest.md) describe ownership, bank placement,
the synchronous engine adapter and the limits of this first migration.

## Check behaviour and inspect placement

```sh
make test        # Original C vs Vexel traces, UBSan, text bounds, linker checks
make -j4 smoke   # Both complete engines on SDL and openMSX, no display required
```

`smoke` builds separate `*-smoke` profiles, skips the title and brings the NPC
to the player. It uses real entity callbacks, drawing, mapper changes and the
game ISR; dialogue is acknowledged automatically after its usual display delay.
It checks following, delivery, the reward and mapper restoration. This does
not automate walking the complete route or replace a full playthrough.

Screenshots and observed stack/timing reports are in `build/smoke`. All three
MSX dialogue captures are compared between the two variants. The ordinary
build contains neither the scenario driver nor automatic acknowledgement.

Every MSX build leaves editable SDCC `.asm`, `.lst`, `.rel` and `.sym` files
under its `msx/` directory, and the cartridge has `.areas.map`, `.symbols.map`,
`.sym` and `.memory.json` reports. The linker rejects modules larger than an
8 KiB bank, resident ROM overflowing page A, and globals reaching the map's
fixed address at `0xD000`.

The measured first slice keeps the cartridge at 416 KiB, adds 100 bytes of
global RAM, and adds 12 bytes to the deepest observed stack use in the smoke
scenario. These are measurements of this build and path, not a whole-game
stack proof. See the integration notes for the complete comparison.
