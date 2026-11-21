# Edelweiss

An MSX1 game with a Linux/SDL development build. The lumberjack rescue, axe
reward, town-hall pear exchange, Fish'n'Ships, university, Food'n'Stuff,
saloon passwords, world routes, pickup/drop rules, town interactions, ghost and skeleton
behaviour, shared combat and weapon rules now run from Vexel. Pickup lifetimes,
fairy motion and lumberjack following animation also use Vexel policies, with
their sprite frames published through bank-safe handles.
The title/attract sequence, menu/password input policy, contact geometry,
world update/spawn scan and new-game/equipment setup also run from Vexel.
The renderer, audio, physical map queries, entity storage and optimized
assembly remain in the engine.

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
overridable. Each platform records its effective compiler, flags, ABI defines,
generated include directory and source set. Changing them rebuilds that platform;
unchanged settings retain existing objects. C dependency files track the actual
transitive headers. SDCC explicitly uses `--sdcccall 0` to match the existing assembly ABI.
The default allocation search budget is 2,000, adjustable with `MAX_ALLOCS`.
SDCC compilations are serialized across guarded projects even with parallel
Make jobs. Each has a 2 GiB address-space cap and a 180-second timeout, controlled
by `SDCC_MEMORY_MB` and `SDCC_TIMEOUT`; `sdcc-resources.jsonl` in the build profile
records peak memory and outcomes.

The runtime and module linker are pinned under `vendor/sdcc_msx`; provenance
and local patches are recorded in its [UPSTREAM.md](vendor/sdcc_msx/UPSTREAM.md).
Builds do not access the network, the old `sdcc_msx` symlink/working directory,
Java, or stale generated files in `tmp/`. Required graphics are already checked
in as C. `Makefile.legacy` preserves the old build recipe for reference.
Historical `out/` and `tmp/` artifacts are not overwritten.

This remains an independent Git repository. No part of the game is added to
the surrounding Vexel repository.

## Edit the gameplay

The 34 Vexel source files form one program rooted at
[gameplay/quests.vx](gameplay/quests.vx). `make generate` uses one `--program`
solve for all 78 runtime entries
and the sprite catalog. The generated program image records code ownership and
all alternative projections; the exporter selects the engine's bank groups and
typed bindings from that image. Callback lifetime contracts still prevent live
workspaces from overlapping incorrectly.

The gameplay rules include:

- [world_flow.vx](gameplay/world_flow.vx) owns the complete world and title
  actor scans as effectful regions, reading fresh state after each callback.
- [orchestration.vx](gameplay/orchestration.vx) owns frame timing, camera and
  spawn-window rules, world population, new-game facts and equipment setup.
- [title.vx](gameplay/title.vx) owns title phases, spark seeding/cadence,
  cancellation and attract-mode progression.
- [interface.vx](gameplay/interface.vx) owns menu movement, cursor geometry
  and password-editor character/completion rules.
- [contact.vx](gameplay/contact.vx) owns weapon/player contact predicates,
  including the original byte-distance wrapping at world boundaries.
- [scenes.vx](gameplay/scenes.vx) owns intro, death, doors and reveal scripts.
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
- [town.vx](gameplay/town.vx) dispatches buildings, chooses tunnel destinations,
  selects signboard text and controls the monster house's three bites.
- [ghost.vx](gameplay/ghost.vx) controls ghost spawning, update cadence, motion,
  health restoration and sprite selection. The engine supplies collision queries.
- [melee.vx](gameplay/melee.vx) controls paw, claw, sword, axe and butter-knife
  damage, colors, hit rectangles, axe cutting and the twenty-tick swing.
  [melee_assets.vx](gameplay/melee_assets.vx) declares the small/large sprite frames.
- [projectiles.vx](gameplay/projectiles.vx) controls arrow/fire/bomb launch and
  damage, arrow/fire movement and fire animation.
- [bomb.vx](gameplay/bomb.vx) controls fuse, blinking, explosion animation,
  expiration and tile destruction eligibility. It stops at each map query so
  effects execute in their original order, even across a large elapsed update.
  [projectile_assets.vx](gameplay/projectile_assets.vx) declares their sprite frames.
- [skeleti.vx](gameplay/skeleti.vx) controls skeleton routines, waits, pursuit,
  returning home and animation. It requests random choices only when needed;
  the engine checks proposed movement against the map and handles contact.
- [drops.vx](gameplay/drops.vx) also owns pickup appearance, visibility, blinking
  and expiration, with collection still ordered after the lifetime update.
- [fairy.vx](gameplay/fairy.vx) owns the exact bobbing motion of both fairy halves.
- [follower.vx](gameplay/follower.vx) owns the lumberjack's retained horizontal
  facing and animation. These actors publish handles from
  [actor_assets.vx](gameplay/actor_assets.vx), consumed by the renderer.
- [combat.vx](gameplay/combat.vx) controls hit acceptance, damage, invulnerability,
  knockback timing/direction and enemy death effects. Knockback is a cardinal
  18-pixel slide over six display ticks; walls stop it, and repeated contact
  during immunity cannot restart it. Player movement/new attacks and enemy AI
  pause during recovery. Both gameplay profiles use this revised design.

Most rules share a 20-byte result arena and receive only relevant state.
The ghost uses the solver's typed value interface: its generated cadence
predicate runs before movement inputs are acquired, and its selected update
returns caller-owned fields. Arithmetic specialization and shared calculations
come from Vexel's general C backend.
The skeleton also selects a generated case: waiting needs five inputs instead
of twelve. Outside hit recovery, its update keeps the same random draws, map
checks and sprite rules. Combat uses a generated constant case to handle
healthy entities without mapping the reaction bank.
Ghost and skeleton sprite requests remain byte handles until the renderer consumes them.
Vexel asset declarations generate the binding table; the final MSX link checks
its bank, bounds and relocations. One descriptor table handles both families;
the renderer maps the asset bank only while
reading it, with no additional per-sprite RAM. Other sprite families still use
the legacy interface.
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
make -j4 ghost-benchmark # MSX comparison at accelerated emulation speed
make -j4 encounter # Actual frame loop: four skeletons, four ghosts, then combat
python3 tests/check_title.py # Both production ROMs: title, skipping and VRAM
```

`smoke` builds separate `*-smoke` profiles, skips the title and brings the NPC
to the player. It uses real entity callbacks, drawing, mapper changes and the
game ISR; dialogue is acknowledged automatically after its usual display delay.
It checks the quests, town-service menus, payments, healing, acquired weapons,
random book selection, password save/reset/restore, dialogue removal on exit and mapper restoration. This does
not automate walking the complete route or replace a full playthrough. A connected
world scenario collects money, buys a lamp, travels, saves/restores equipment,
uses wells and secret passages, and checks boots, healing and one-time pickups.
It also visits the teleporting houses, reads a sign twice, enters the monster
house and runs a ghost through spawning, movement and death. Ghost callback
timings are measured separately for active and skipped updates on MSX.
`ghost-benchmark` runs the same MSX scenario and dialogue checks at 10x speed,
with results in `build/ghost-benchmark`. Timings use emulated time. The typed
value backend reduced active ghost updates from 5.24 to 1.96 ms (C: 1.84 ms),
and skipped updates from 1.48 to 0.55 ms (C: 0.55 ms), without adding global RAM.

`encounter` builds separate `*-encounter` profiles and runs 64 ordinary game
loop iterations on SDL and MSX1. It compares enemy state traces, exercises real
contact damage, a weapon hit, death, explosion and drop creation, and checks
hardware mapper writes against the saved bank state. Reports in
`build/encounter` include complete loop time (wait/rendering included), update
body time, observed stack use and a screenshot. These are exercised paths,
not worst-case frame or stack bounds. The eight-enemy phase fills the enemy
slot pool; two ghosts leave before combat so the explosion and drop can spawn.
After the timed encounter, both profiles check hit directions, saturated
timers, all six player slide steps while movement/attack/switch inputs are
held, and stopping against an actual map wall. Both profiles also check melee
damage, colors, hit positions and every orientation/tick boundary on Z80.
Projectile checks cover launch/motion and bomb updates crossing the fuse,
explosion and expiration boundaries, including uncovering a real mountain door.
The Vexel profile checks all 98 frames across fourteen sprite families with their
asset bank initially paged out, including delayed consumption offscreen.
Patterns and colors must match the linked ROM, and the mapping must be restored.
Skeletons retain pending frames while waiting, including an already consumed
request, and migrated callbacks clear requests before sprite-slot reuse.

Vexel now selects fixed or automatic storage for named C bindings. Source
metadata supplies estimated relative call frequencies and explicit engine
lifetime contracts. The normal Makefile supplies a 96-byte binding allowance,
within the source's 128-byte ceiling. The 66 bindings use 56 bytes of fixed
storage: a 35-byte shared pure workspace and a separate 21-byte world/title
region workspace. Those regions remain live while actor callbacks reuse the
pure workspace. Generation supplies a zero frequency preference for the optional
player-motion region in the normal embedding, so it stays automatic and reserves
no fixed RAM. `make PLAYER_REGION=1 generate` supplies that alternative's usage
and the larger default allowance. C adapters retain the same interface across
allocation choices, and an automatically allocated binding remains callable.

After region optimization, observed additional encounter stack is 117 bytes,
down from 120 in the migration baseline (C: 126). The crowded update body falls
from 23.401 to 22.457 ms; the frame averages 34.371 ms versus 34.401 ms. Region
bookkeeping and helper time falls from 3.455 to 2.524 ms per scan in this
encounter. The earlier native scan still used less update work (16.945 ms),
so the full region remains a useful optimization target.
These timed scenes have an idle player; separate callback probes measure
movement. The [region measurements](docs/vexel-quest.md#region-publication-lifetimes-and-embedding-usage)
include title timing, scene stack and the remaining performance tradeoffs.
The frequency heuristic has no
measured cycle-cost model. An additional 88-byte `frame_ram_bytes` allowance
lets Vexel keep the password decoder's exclusive temporaries in fixed RAM.
Its SDCC stack frame falls from 100 to 12 bytes, and the dialogue/world smoke
peak falls from 285 to 242 bytes (240 for C). The remaining peak is in the
legacy tile diagnostic's formatted-print call. Production now uses 472,298
occupied ROM bytes and 3,926 global RAM bytes, with a 475,136-byte image
and 170 bytes free before the map buffer. The revised C reference uses
428,411 occupied ROM bytes and 3,769 global RAM bytes. Earlier optimization
measurements and the scope of these comparisons are in the integration notes.
The complete SDL/MSX smoke run passes with the selected plan as well.

Melee computes only the final swing state for elapsed ticks. At its migration,
a direct Z80 callback comparison reduced additional stack from 25 to 19 bytes. Single-tick
updates are about 12% slower than C; two-tick updates are about 23% faster,
and larger batches avoid the legacy per-tick loop. These timings exclude sprite
uploads. Melee publishes resource handles, and the renderer resolves their
bank and address when it consumes them. The C reference remains available.

Arrows and fire likewise compute motion directly in Vexel; bombs combine pure
state changes but stop at each observable map query. The four detonation queries
retain their order and see prior writes. Measured arrow/fire callbacks are
36–38% slower for one tick, about 9% faster for two and 26% faster for three.
Their normal callback stack rises from 15/16 to 21/23 bytes; bomb callback stack
falls from 82 to 41 bytes, including map effects. All four new bindings share
the existing workspace, so production RAM is unchanged. These are workload
measurements, not whole-program stack bounds. Arrow/fire impact behavior is
unchanged; their legacy callbacks only move and animate.

Sparks and explosions now share [effects.vx](gameplay/effects.vx), while
[ball.vx](gameplay/ball.vx) controls the ball patrol and
[player.vx](gameplay/player.vx) controls normal player input, movement decisions
and scroll targets. All player animation publishers, including door transitions,
use the same resource handles. Pickups, fairy halves and the lumberjack also
use these handles, bringing the catalog to 98 frames across fourteen families.
Effects are faster for one-to-three ticks; ball/player movement currently costs
more than C (about 32% for ball and 38–48% for moving-player samples). Their
measured callback stack also rises, from 57 to 74 and 21 to 26 bytes respectively.
The C reference retains the same edge-case fixes for stale trigger observations,
empty inventories and target-width ball comparisons. See the
[integration notes](docs/vexel-quest.md#effects-ball-patrol-and-normal-player-controls)
for the effect boundaries, performance tradeoffs and validation scope.

Pickup lifetime/visibility, fairy motion and following animation now also live
in Vexel. Following animation is about 23% faster in the MSX callback samples
and uses 7 stack bytes versus 14 for C. Pickup callbacks use less stack for
normal updates, but take longer for one tick; fairy motion currently costs more
time and stack than its C lookup table. The shared binding workspace stays at
35 bytes. See the [actor port measurements](docs/vexel-quest.md#pickup-fairy-and-follower-policies)
for the exact behavior, SDCC correctness fixes and remaining tradeoffs.

An experimental [complete movement region](gameplay/player_motion.vx) now owns
the loops and continuations across map queries. `make optimize-player` compares
its generated SDCC project with the existing binding chain, validates behavior,
then measures stack and timing. Control-flow optimization now reduces the
region to a 56-byte frame and 17 measured stack bytes when it shares the
player's bank (`PLAYER_REGION=1 PLAYER_REGION_BANKED=0`). It is still slower
than the existing chain in shorter updates, so the default retains that chain
and its 35-byte workspace;
see [the experiment and reproduction commands](docs/vexel-quest.md#movement-execution-regions-and-measured-selection).

`make optimize-storage` explores applicable per-binding scratch-storage choices
reported by Vexel. Each bounded candidate resolves the whole game, runs the
C/reference checks, builds Linux and MSX, and validates the full quest scenario.
It also invokes each affected linked helper over identical input vectors to
compare timing and stack use. The selector checks combined RAM and ROM costs,
rejects regressions in individual sampled paths, and retains an editable project
under `build/storage-optimization`. Matching measurements can be reused only
while their inputs and artifact hashes still agree. SDCC stays serialized and
limited to 2 GiB and 180 seconds per invocation. This command leaves production
preferences and `generated/quests` unchanged; see the
[measurement scope and policy](docs/vexel-quest.md#measured-scratch-storage-alternatives).
Pass `--schedules` to `tools/optimize_storage.py` to include the alternative
output schedules reported by Vexel. This extends the same bounded search and
uses the same per-sample checks; a smaller scratch frame alone does not select
a candidate.

To check every linked pure helper in a built game, run
`python3 tools/profile_storage.py --profile build/vexel --generated generated/quests --all-full --output build/value-probe`.
The probe invokes the actual ROM code with reproducible boundary, correlated and
random inputs, and compares its results with host C. Its report retains sampled
time/stack costs and counterexamples on failure. Guarded case entries and
effectful regions require their own execution context and are excluded.
The MSX Make rules now track transitive includes through SDCC dependency files,
so changing a generated support header rebuilds its consumers. They no longer
make every gameplay adapter depend on every generated binding. Dependency-only
preprocessing handles removed headers too, and a missing dependency file
rebuilds its C object instead of silently losing include tracking.

The earlier Vexel generator pass reduces moving-player callback stack from 28 to
26 bytes and improves its sampled time by about 1%, with no additional RAM.
Ball callback stack remains 74 bytes, with a small speed improvement. This is
a compiler change; the game adapters and SDCC flags are unchanged. After
`make encounter`, run `python3 -B tests/profile_actor_callbacks.py` to repeat
the callback measurements and record the ROM hashes. Details are in the
[stack notes](docs/vexel-quest.md#stack-costs-in-the-generated-c).

Screenshots and observed stack/timing reports are in `build/smoke`. Three
lumberjack popups, one signboard, nine pear popups, 39 service/password popups,
twelve world popups and three monster-house stages are compared between
variants. For the popups, the check compares their VRAM patterns, colors and placement while
allowing the surrounding world to keep animating.
The password stack investigation is in `build/smoke-stack`; the melee migration's
comparison, callback timings and smoke captures are in `build/melee`.
The projectile migration's reports are in `build/projectiles`; the latest actor/player
comparison, callback probes, ROM/listing snapshots and smoke captures are in `build/actors`.
The compiler stack pass and its before/after measurements are in `build/stack-aware`.
`tests/check_smoke.py --msx-only --speed 1000 --stack-detail` records the peak
PC, physical banks, registers and stack snapshot without changing the ROM.
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

Native adapters can now offer equivalent inline boundary statements to Vexel.
The default world plan expands the slot/cycle queries, saving about 101 µs per
scan in the measured query/orchestration work with unchanged 117-byte encounter
stack and 56-byte fixed workspace. Actor/flag expansions remain selectable;
their faster measured alternative used six additional stack bytes. See
[native boundary alternatives](docs/vexel-quest.md#native-boundary-implementation-alternatives)
for the contracts, settings and measurements.
