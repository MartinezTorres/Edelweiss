# Edelweiss

An MSX1 game with a Linux/SDL development build. The lumberjack rescue, axe
reward, town-hall pear exchange, Fish'n'Ships, university, Food'n'Stuff,
saloon passwords, world routes and pickup/drop rules now run from Vexel.
The renderer, audio, collision system, entity storage and
optimized assembly remain in the engine.

The corrected C reference quests are available with `GAMEPLAY=reference`. Both variants use
the same modernized build and engine, so they can be compared directly.

## Build and play

Required tools: Make, a C compiler, a C++14 compiler, Python 3, pkg-config and
SDL2 development headers for Linux; SDCC and sdasz80 for MSX. The integration
was verified with SDCC 4.2.0, SDL2 2.30.0 and openMSX 19.1.

```sh
make -j4                    # Linux executable and Konami-5 cartridge
make run                    # Linux / SDL
make run-msx                # openMSX, C-BIOS_MSX1, KonamiSCC mapper
make GAMEPLAY=reference -j4 # Retained C quests
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

The entry file [gameplay/quests.vx](gameplay/quests.vx) imports the gameplay rules:

- [lumberjack.vx](gameplay/lumberjack.vx) receives a phase and an event, and
  returns the next phase, command and text ID.
- [pear.vx](gameplay/pear.vx) receives pear ownership, boots ownership and the
  player's answer. It returns the available choice count, pear consumption,
  boots reward, rupee credit and text ID.
- [stew.vx](gameplay/stew.vx) controls eligibility, payment and health upgrades.
- [university.vx](gameplay/university.vx) controls course progression, offers,
  payment and learned abilities.
- [shop.vx](gameplay/shop.vx) selects stock, affordability and purchase
  effects. Ordinary books request an explicit random draw before committing.
- [password.vx](gameplay/password.vx) encodes the original MSX password layout,
  validates input and selects restore or cheat effects.
- [world.vx](gameplay/world.vx) selects mountain and secret-passage destinations,
  lamp refusals, well dialogue/progression and boots warnings.
- [drops.vx](gameplay/drops.vx) selects drop probabilities and collection rewards.
  Randomness is an explicit input, requested only when the rule needs a draw.

The rules share a 20-byte result arena and receive only relevant state.
The C adapter handles input and rendering, copies results before applying
effects, and reuses one 96-byte text buffer. No entity or banked text pointer
crosses into Vexel.

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
kept in `generated/quests`. An ordinary game build uses that projection
without requiring a Vexel installation. A source/projection hash mismatch
fails the build with instructions to regenerate.

At the saloon, record the ten letters the wizard shows. Type those letters
(case-insensitive) to restore items, weapons, maximum health and rupees;
ten characters submit automatically, or Enter submits a shorter answer.
Rupees round down to a multiple of 16, matching the old MSX format. A valid
restore heals fully and keeps the selected weapon if owned, otherwise selects
the paw. This is an inventory checkpoint, not a save of position or world
progress. The legacy `NISHI` and `MSX2` commands remain available.
Old MSX passwords are preserved; the old Linux bitfield encoding was different.

The [integration notes](docs/vexel-quest.md) describe ownership, bank placement,
the synchronous engine adapter and the limits of this migration.

## Check behaviour and inspect placement

```sh
make test        # Original C vs Vexel traces, UBSan, text bounds, linker checks
make -j4 smoke   # Both complete engines on SDL and openMSX, no display required
```

`smoke` builds separate `*-smoke` profiles, skips the title and brings the NPC
to the player. It uses real entity callbacks, drawing, mapper changes and the
game ISR; dialogue is acknowledged automatically after its usual display delay.
It checks the quests, town-service menus, payments, healing, acquired weapons,
random book selection, password save/reset/restore, dialogue removal on exit and mapper restoration. This does
not automate walking the complete route or replace a full playthrough. A connected
world scenario collects money, buys a lamp, travels, saves/restores equipment,
uses wells and secret passages, and checks boots, healing and one-time pickups.

Screenshots and observed stack/timing reports are in `build/smoke`. Three
lumberjack popups, nine pear popups, 39 service/password popups and nine world
popups are compared between variants. For the popups, the check compares their VRAM patterns, colors and placement while
allowing the surrounding world to keep animating.
The ordinary build contains neither the scenario driver nor scripted input.

Every MSX build leaves editable SDCC `.asm`, `.lst`, `.rel` and `.sym` files
under its `msx/` directory, and the cartridge has `.areas.map`, `.symbols.map`,
`.sym` and `.memory.json` reports. The linker rejects modules larger than an
8 KiB bank, resident ROM overflowing page A, and globals reaching the map's
fixed address at `0xD000`.

ROM growth is acceptable up to roughly 16 MB with a future mapper. RAM, stack
usage, bank safety and execution speed take priority. The current Konami-5
embedding places the service rules in a separate 8 KiB bank and shares the
existing text buffer. See the integration notes for measured costs; observed
stack depths cover the exercised paths, not the entire game.
