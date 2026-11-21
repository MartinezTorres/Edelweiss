# Vexel gameplay integration

This migration starts from Edelweiss `fecb997` and the supplied `sdcc_msx`
checkout. The playable lumberjack milestone is committed as `f2b5fdc`.
The integration now implements the lumberjack conversation, following decision,
axe reward, pear exchange, Fish'n'Ships, university, Food'n'Stuff, saloon
passwords, world interactions, pickup/drop rules, town dispatch/content and
ghost and skeleton behaviour, shared combat and weapon rules while keeping
the C branches for comparison.
The original local library edit and untracked files are left untouched.

## One gameplay program

`make generate` resolves `gameplay/quests.vx --program --mode serial` once.
The root imports gameplay and `sprite_assets.vx`; exported runtime entries and
the exported `sprite_catalog` build value participate in the same solve.
Adding an exported entry therefore cannot silently leave it out of generation.
The C adapter must provide its embedding or generation fails.

Vexel emits `program-image.json`: a catalog of generated artifacts and ordinary
C units with their activation owners. The game exporter validates this image
and uses the named units for the existing Konami-5 placement groups. It does
not infer helper numbers, function order or C boundaries from text. The whole
image, including unused alternative projections, remains inspectable under
`generated/quests`; only selected interfaces are linked into the game.

The typed bindings still use their compiler-selected interfaces. Shared storage
requires the explicit `c_disjoint` contracts in the root. `player_motion` keeps
separate storage across its synchronous callbacks, even though the game is
single threaded. This is necessary when those callbacks invoke another binding.
The existing host and MSX checks exercise these nested lifetimes.

The shared solve also propagates integer bounds across native arguments,
captures, results and loop state. These facts reach the ordinary, banked, value
and fixed-binding C projections before their interfaces are selected. For this
game, the report proves bounds of 65..80 for password helper arguments and
0..2 / 0..1 for two player-motion state leaves. These are implementation facts;
the source types and runtime boundary checks keep their existing meaning.
`source-plan.json` records the analysis in `value_ranges`. Tighter bounds permit
simpler generated expressions, but do not by themselves establish a game-wide
speed or stack improvement.

The solver can now select smaller private scalar storage from those bounds,
independently of the source arithmetic width. The `transport_types` records
show both types for native arguments, captures, results and retained loop
cells. The eligible values in this game already use narrow source types;
private width selection has not established a game performance gain.
Public C bindings retain their declared interfaces.

Function result graphs can also answer queries using the argument and capture
bounds of an individual invocation. This keeps successive state snapshots
distinct while retaining a shared native implementation. The report records
these tighter facts in `value_ranges.call_results` and the bounded analysis
cost in `value_ranges.contexts`. Conditional queries also use the guards of
individual value branches and loop transfers. Such facts expire outside their
branch; wrapping conversions and separate state snapshots remain distinct.
Queries now share answers across structurally identical expressions in the
same function and fact environment. The proof-sharing comparison recorded 49,059
cache hits, 18 cached call contexts at peak, and 15 nested branch environments.
It reached the 16,384 contextual-query budget and retained conservative
facts there. The extra reuse establishes two more 0..2 loop-state bounds;
those leaves already have byte storage. These are analysis results, not a
measured game speed or stack improvement.

Changing the readiness induction hypotheses invalidates cached answers without
renewing the work budget. In that generation, the ordinary player-motion
projection conservatively retains one additional readiness flag and its
transfer temporary (two byte-sized fields). Eight alternative projection files
change; the generated code embedded by the playable game, including its region
binding, is byte-identical. The ordinary projection compiles, and the host game
checks pass. `build/shared-proofs-validation.json` in the Vexel repository records
the comparison and validation; that comparison covered 299 generated code files.

Shared native argument and capture domains now also account for each invocation's
execution path. The compiler combines every caller before choosing a private
interface, distinguishing loop condition calls from guarded body calls.
`value_ranges.call_inputs` exposes those guarded sites and their input bounds.
The current materialized game calls have no enclosing path predicates, so that
list is empty here. These guarded input facts add no narrower incoming domains
to the current game image.

Sprite descriptors consume the structured catalog in the program report. The
final ROM verifier still checks asset banks, addresses, bounds and relocated
descriptor contents. One source resolution does not replace those link checks.
The generation manifest records every published product and tool provenance;
ordinary builds need no solver. Edited obsolete generated products cause
generation to stop for review; unchanged obsolete products are removed.

The MSX Makefile runs SDCC through `tools/sdcc_guard.py`, with one invocation at
a time across guarded Vexel/Edelweiss projects. Each compiler has a 2 GiB
address-space limit and a 180-second timeout. Resource measurements are kept in
the build profile's `sdcc-resources.jsonl`. `SDCC_MEMORY_MB` and `SDCC_TIMEOUT`
are explicit build settings. Parallel host compilation can still use Make jobs.

## Boundary and ownership

`gameplay/lumberjack.vx` is a pure transition function. Its state machine is:

```
waiting --contact--> introduction --dialogue closed--> request
request --dialogue closed--> following --town hall--> thanks
thanks --dialogue closed--> completed
```

Unexpected events do nothing. A cancelled transient interaction returns to
waiting; completed is terminal. Tests cover the transition table, repeated
events and cancellation. The engine adapter accepts contact and town-hall
entry events and supplies dialogue completion internally.

The C adapter reconstructs the initial phase from the actual lumberjack's
following flag. Transient dialogue phases live only within that invocation.
Spawning, despawning and starting a new game continue to own the authoritative
entity state. There is no second persistent quest-state array to synchronize.
An absent entity is rejected before an engine slot is accessed. Delivery
despawns the follower and disables its automatic spawning, preventing a second
reward through ordinary game events.

The output is `(phase, command, text ID)`, three logical byte fields in the
shared payload arena. `quest_interact` reads all leaves before applying any effect.
The test sink deliberately overwrites the released payload during dialogue;
the transition must still finish correctly. Commands initialize the existing
eight-entry follower trail, despawn through the original callback, equip the
axe and update the infobar. No full `T_State` copy or heap allocation is used.

`gameplay/pear.vx` receives only `(has_pear, has_boots, accepted)` and produces
`(choices, consume_pear, grant_boots, credit, text)`. A missing pear makes YES
unavailable and prevents any reward, even for a forged acceptance. Declining
preserves inventory. Accepting consumes the pear and grants boots if missing,
otherwise 100 rupees. The existing engine retains currency arithmetic and its
999-rupee display cap; these are not new Vexel numeric rules.

`quest_exchange_pear` asks for the offer, runs a bounded yes/no menu, then asks
for the result using the selected answer and current inventory. It copies the
result leaves into locals before consuming the pear, applying the reward,
updating the infobar and displaying the acknowledgement. Input, cursor drawing
and the existing 60-frame reward delay remain C UI operations. The left, right,
confirm ordering is preserved, including simultaneous clicks. A second visit
cannot earn a second reward without another pear. No persistent exchange state
or generic command interpreter is needed.

`gameplay/quests.vx` imports all gameplay entry points with an explicit 20-byte payload
budget. Their serial projections share offset zero. The current projection
uses 16-bit slots to accommodate 500-rupee purchases; the largest result has
ten logical byte fields (the password). The engine finishes consuming one invocation before starting
another. All interactions use the same text buffer described below.

The three town services add these pure rules:

- `stew` returns an offer or refusal, a debit, a new maximum health and a text
  ID. The 40-health ceiling takes precedence over affordability, as before.
- `university` returns the next phase, choice count, debit, weapon and text ID.
  It welcomes the player, skips learned abilities, and reevaluates funds for
  the second course after the first purchase. The adapter follows those
  phases; it does not decide which course to offer.
- `shop_stock` returns each row's text ID and affordability. `shop_trade`
  returns completion, debit, healing, item, weapon, text and random-request
  fields. Insufficient funds leave the menu open at the selected row. All
  effects are copied before any drawing, weapon initialization or random draw.

A shop query initially supplies `book_roll=255` (not drawn). Only an affordable
ordinary book requests randomness; the adapter draws once and reruns the pure
rule with that value. Buying a first spell book, leaving or failing to afford
a book consumes no random value. A fixed draw gives reproducible behaviour on
both targets. The old eight outcomes are retained, including outcome seven's
lack of an acknowledgement and the unpurchasable weapon's joke response.

`gameplay/password.vx` owns password encoding, case normalization, validation,
cheat recognition and the resulting inventory policy. `password_encode` takes
four values and returns ten character bytes; `password_decode` takes a length,
ten bytes and the selected weapon, and returns a typed effect record. The
adapter copies bounded input into RAM, reads all result fields while the rule
bank is mapped, and applies nothing for a rejected result. No caller pointer
crosses the Vexel ABI. Runtime conditional branches with a byte input use an
explicit byte zero to retain that type; fixed range loops expand during
resolution.

The canonical layout is the **original SDCC/MSX layout**, not the old GCC
bitfield layout. The four bytes before obfuscation are:

| Byte | Meaning | Valid restored values |
|---|---|---|
| 0 | lamp, boots, coat, pear in bits 0..3 | upper four bits zero |
| 1 | ownership of the eight weapons | paw (bit 0) owned |
| 2 | rupees divided by 16 | 0..62; upper two bits zero |
| 3 | maximum health divided by 2 | 3..20; upper three bits zero |

XOR the bytes with `82 46 38 73` (hex), emit each byte's low nibble then high
nibble as `A`..`P`, and append two checksum letters, high nibble first. Starting
at `0x46`, each of the eight emitted letters updates the checksum with
`((checksum + letter) & 255) ^ 0x37`. For example, the initial inventory
(paw, six maximum health, no items or money) is `CIHEIDAHJB`; all items and
weapons with 999 rupees and 40 health produces `NIJLGAHGIA` and restores 992
rupees. This rounding is retained intentionally. Legitimate old MSX passwords
remain usable; the incompatible historical Linux encoding is not auto-detected.

Both checksum characters, alphabet, length, reserved bits and game bounds must
pass before any mutation. Restoring also heals fully, keeps the current weapon
if owned or falls back to the paw, initializes its engine entities and rebuilds
both infobar buffers. Loading a weaker checkpoint therefore clears obsolete
hearts and icons. `NISHI` grants all items/weapons, 999 rupees and 40 health;
`MSX2` changes only money to 999. Input is case-insensitive. These codes do not
store position, quest completion or other world progression.

The common saloon UI remains C and uses the same shared text buffer as the
other quests. It preserves the prior keyboard-routine enable state and the
original ten-character automatic submission / Enter behaviour. The restore
response now separates its last two lines, avoiding a write beyond the popup.
The corrected C reference uses explicit bytes too: no uninitialized decode
accumulator or compiler-dependent bitfield union remains in production.

`gameplay/world.vx` receives tile classes, tile coordinates and the relevant
equipment flags. It owns route destinations, the upward-facing requirement,
lamp gating, well dialogue/counter progression and boots warnings. Tile IDs
are translated from renderer assets in C; movement, scrolling and the existing
entry/exit animations stay in the engine. Route results are copied before any
animation. Feet are sampled after travel, preserving the original ordering.
The well counter commits after the arrival message, and remains unchanged
once it reaches five. The unfinished cave at `(6,50)` still does nothing and
rocks still warn without damage; this migration does not invent those mechanics.

`gameplay/drops.vx` owns probability thresholds and collection rewards. A
`drop_roll` query with the sentinel 256 asks whether randomness is needed;
skip or unknown probability modes retain the supplied item without drawing.
Other modes request exactly one draw. The adapter supplies the low byte of
the existing `rand16`, then consumes the result before selecting a sprite.
Low/medium/high distributions are unchanged. `drop_collect` returns health
and rupee credit; collision, delay, blinking, expiry and entity removal stay
in C. Currency uses the existing unsigned arithmetic and ISR's 999 cap.

Collection marks the item consumed immediately in both profiles. The existing
spawn helper invokes the update callback but ignores its removal result;
without this mark, an item collected on spawn could pay again on the next
update. The next normal engine update now removes it without another reward.

Text IDs are resolved in `quest_text`, a page-D module. That module copies the
selected, bounded string into a 96-byte RAM buffer. Its caller restores page D
before drawing or waiting. The font renderer and ISR may freely replace that
ROM window: the displayed text belongs to the adapter until the dialogue
finishes. Invalid IDs and insufficient capacity are rejected, and every
successful copy includes a terminator. C pointers remain private engine
implementation details.

The foreground owns one invocation and one output. The ISR never enters the
quests, and the current despawn callback does not reenter them. Adding another
caller or a callback that can invoke gameplay requires revisiting this
contract; the serial projection is not a general concurrency guarantee.

`gameplay/town.vx` owns building dispatch, the four teleporting houses,
signboard selection/repeat suppression and the monster-house sequence.
House choice requests a first `rand7` draw and a second only when bit 2 of
the first is clear. The adapter never prefetches the second draw. Both tunnel
languages are retained, selected by a value input and copied before travel.
Unknown doors still run entry/exit without a service or random draw.
The board rule keeps the existing one-byte remembered column, including
updating it for unknown columns. Repeat reads produce no text.

The monster house returns one append-text/damage/wait step at a time. All
three bites run, even at zero health, with 30 frames after each and a final
60-frame pause. Results are copied before drawing or waiting. These are
synchronous scene steps; ordinary world AI remains paused, as before.

`gameplay/ghost.vx` receives coordinates, anchors, signed byte velocities,
player position and cadence/health values. The engine supplies six random
low bits at spawn. The last two draws are retained even though both branches
of the old position expression used the same offset. Spawning still uses
anchor minus 256/512. The rules update once every four cycles according to
spawn slot, restore maximum life on active ticks, combine anchor attraction
and player pursuit, and select a sprite frame. Positions wrap at 16 bits and
velocities at 8 bits. The source writes signed `delta / 512`; Vexel's general
value emitter lowers this to a biased arithmetic shift with truncation towards
zero. Ordinary helper functions expose both axes and frame selection to one
`ghost_update` observation; no explicit materialization barrier is needed.

The common invulnerability/pushing/death gate runs before any ghost projection.
It can spawn a Vexel-backed drop without overlapping a live ghost result.
All ghost outputs are copied before sprite and collision effects. The C
reference replaces left-shifting a negative velocity with multiplication by
two, removing C undefined behaviour while preserving the original MSX result.
The two redundant spawn draws are standalone calls in the reference: SDCC
4.2 otherwise removes them with the identical conditional arms. This corrects
a historical Linux/MSX difference in random-stream consumption; both profiles
now perform the six calls written in the original C source.

## Execution and placement

`gameplay/skeleti.vx` models the skeleton's existing state machine without
introducing an attack that the original game did not have. `skeleti_tick`
decides cadence. On an active tick the adapter obtains the reset draw;
`skeleti_draws` then decides whether two additional draws are required.
`skeleti_update` receives those values and the current entity/player state,
and returns action, delay, proposed coordinates and a frame ID. Waiting can
still reset the routine, but consumes only the reset draw. Choosing a new
routine consumes exactly three draws. Neither a skipped tick nor a failed
common entity gate consumes any draws.

The map rejects an obstructed position without reverting the chosen routine,
delay or animation, matching the C reference. Frame 255 means leave the pending
sprite request alone, including a null request already consumed by the ISR.
The adapter alone translates a frame ID to a pointer plus its sprite bank.
Home-distance comparisons explicitly narrow `position +/- 512` to 16 bits in
both implementations: this preserves the original MSX behaviour and fixes the
Linux reference's previous promotion to a wider signed integer.

These three sources use the total integer value projection, embedded
in the skeleton callback's page-C bank. The adapter uses the generated delay
predicate and its case functions after obtaining the requested random values.
No effects intervene between predicate and case. Waiting passes five inputs
instead of twelve, without reading player coordinates or anchors. The generator
validates the reported input dependencies as well as the output layout. The
full value header remains available for inspection. The host test checks all routines,
waiting/reset behaviour, exact draw and effect order, blocked movement,
pending sprite ownership, skipped/dead ticks and wrapping boundaries against
an independent oracle as well as comparing C and Vexel traces.

The adapter and lumberjack/pear rules compile into the `quest` page-C module.
The new pure service rules occupy `quest_services` in page B. Every service
evaluation and result read occurs while that bank is mapped; all fields are
copied before restoring the previous page B and invoking drawing or effects.
The same foreground can therefore reuse page B for the popup and infobar.
Text copies run in page D. Building and NPC modules enter the adapter through
the existing resident page-C trampoline, which restores their mapping.

The saloon has its own `password` page-C adapter, including the encoder and
its specialized checksum helper. The decoder and its helpers occupy
`password_rules` in page B. The checked-shift helper has the same semantics as
Vexel's portable runtime and lives in the page-C adapter, which remains mapped
throughout a decode. The shared `vx_trap` entry is resident
because either page-C adapter can call it. Text remains page D. The ordinary
runtime helper and fault handler do not depend on a NEO-8 mapper.

World rules and drop rules occupy separate page-B modules. Their existing
page-C callbacks map the rule bank, read all output fields and restore page B
before an effect. Tile queries explicitly map the overworld bank. World
dialogue uses the same page-D copier and owned text buffer as the town quests.
These five new entry points reuse the existing 20-byte result arena; no new
production global state or text buffer is needed.

Town rules use their own page-B module and the existing page-D text copier.
Ghost value headers live in the ghost page-C callback bank, avoiding mapper
switches. The backend proves that this graph contains only total integer
calculations, keeps narrow types and shares repeated values. Results belong
to the caller instead of passing through the byte arena and indexed readers.
The game-specific `vx_ghost_math.h` workaround has been removed.

The generated dependency split exposes `vx_ghost_update_branch(cycle,slot)`
and a body for its true case. An inactive tick returns before acquiring the
other entity fields. The body needs slot, maximum life, positions, anchors,
velocities and player coordinates; it does not recheck cadence. The adapter
introduces no effects between predicate and body, so their inputs form one
coherent snapshot. Results are applied before sprite/collision effects.
The generator checks these input dependencies against the solver's report.
This is a target interface to one complete Vexel graph, not a second copy of
the cadence rule in C. The false case is all zero and has no engine effects.

`vx_value_ghost_spawn.h`, `vx_value_ghost_update.h` and
`vx_value_ghost_update_cases.h` are emitted directly by the general solver;
`vx_ghost.inc` selects the spawn and dependency-split headers. The full update
interface remains available for inspection. The original arena projection
also remains in `vx_bridges.c`; the engine's ghost does not use that arena.
No new global RAM is needed. Host arithmetic has defined wrapping/shift
formulas, and the Z80 realization uses its verified native signed operations
while preserving the SDCC shared-operand safeguards.

The generator retains the complete portable `vx_bridges.c` and also packages
its unchanged function bodies into `vx_quests.inc`, `vx_services.inc` and
`vx_password.inc`, `vx_password_encode.inc`, `vx_world.inc`, `vx_drops.inc`,
`vx_town.inc`; `vx_ghost.inc` includes the typed value headers. It checks the
embedding for every discovered export (including the experimental movement
region). Helpers are grouped using program-image units and source ownership;
numbering and specialization counts do not determine placement. Unexpected
ownership fails generation for review.
The four explicit `&~` helpers in `password.vx` keep normalization, byte decoding,
checksum calculation and validation from expanding repeatedly into every result
field. Constant arguments produce eight specialized C functions. All of them
are placed with their password callers; ownership is checked against the plan
before splitting. The eight-byte checksum has different specializations for
encoding and decoding, so neither calls the other's bank.
Generated outputs are hashed; the normal build compiles the selected interfaces.
The drop adapter now selects fixed-frame value headers; `vx_drops.inc` is retained
as an inspectable alternative. This is the small
Konami-5 embedding's placement policy, not a new Vexel lowering pass.

`src/gameplay/vx_runtime.h` supplies the ABI declarations for this embedding.
Its `VX_RESIDENT` is deliberately empty. SDCC's `__nonbanked` attribute would
move code into `_HOME`; the legacy linker cannot place a banked module's
`_HOME`. It now rejects that combination explicitly. The game already has a
resident trampoline, so the generated step needs no separate resident wrapper.

This uses Vexel's unbanked `vx_bridges.c` projection. The generated plan also
describes the standard NEO-8 packaging, which this build does **not** apply.
The C embedding, legacy linker and measured reports supply the actual Konami-5
placement here. There is no claim that the solver proves all legacy pointers,
all engine call paths, or the engine's complete memory layout.

The adapter pumps the explicit Vexel state machine synchronously. `large_message`
retains its existing wait/input behaviour: world AI pauses, rendering and the
ISR continue, and a town-door caller resumes only after reward completion.
Making the entire engine nonblocking would require explicit continuations for
door entry/exit and other cutscenes; it is outside this slice.

## Validation and cost

The supported Vexel frontend from `vexel_lang` revision `edea4f1` generated this
projection. `generated/quests/manifest.json` records its executable hash,
hashes of the entry file and all gameplay source files and generated artifact hashes. No compiler
changes were needed. Ordinary builds validate these hashes without a solver.

Verified with SDCC 4.2.0, its sdasz80, GCC, SDL2 2.30.0 and openMSX 19.1 using
C-BIOS_MSX1 and KonamiSCC. The retained C reference receives the same toolchain
and engine compatibility fixes as the Vexel build.

The first milestone (`f2b5fdc`, lumberjack only) measured:

| Measurement | C reference | Vexel slice |
|---|---:|---:|
| Cartridge size | 425,984 bytes | 425,984 bytes |
| Occupied ROM, excluding bank padding | 423,772 bytes | 425,257 bytes |
| Ordinary global RAM | 3,678 bytes | 3,778 bytes |
| End of ordinary globals | `0xCE5E` | `0xCEC2` |
| Space before fixed map at `0xD000` | 418 bytes | 318 bytes |
| Additional stack depth observed during smoke scenario | 182 bytes | 194 bytes |
| Scenario emulated time, including dialogue delays | 2.9240 s | 2.9251 s |

That 100-byte RAM difference was the three-byte output, 96-byte owned text buffer
and one fault byte. That smoke profile added two reporting bytes to
each variant. Its stack measurement starts inside the scenario driver and
observes writes in the stack region, including interrupts. It is a path
measurement, not a static worst-case bound; startup and other gameplay paths
are outside it. Dialogue timing dominates the elapsed-time measurement.

At the pear-exchange milestone (`800ccbd`):

| Measurement | C reference | Vexel quests |
|---|---:|---:|
| Cartridge size | 425,984 bytes | 434,176 bytes |
| Occupied ROM, excluding bank padding | 423,873 bytes | 426,219 bytes |
| Ordinary global RAM | 3,678 bytes | 3,780 bytes |
| End of ordinary globals | `0xCE5E` | `0xCEC4` |
| Space before fixed map at `0xD000` | 418 bytes | 316 bytes |
| Additional stack depth observed during extended scenario | 182 bytes | 192 bytes |
| Extended scenario emulated time, including display waits | 8.2614 s | 8.3282 s |

Relative to the playable milestone, the second Vexel quest adds 962 occupied
ROM bytes and two RAM bytes. It crosses a cartridge bank boundary, increasing
the image from 416 to 424 KiB. The current reference includes the popup-bank
repair described below, which itself adds 101 ROM bytes. Resident production
code still ends at `0x5EBD` in both variants. The Vexel adapter and both rules
occupy 2,972 bytes in their page-C module; the text module occupies 507 bytes
in page D. Neither needs another text buffer or persistent gameplay state.

The extended smoke profile adds eight RAM bytes per variant for its reports
and input queue. These bytes and the resident input helper are absent from
ordinary builds. Stack and elapsed-time figures cover the whole scenario,
including the lumberjack, door entry, five pear visits and fixed display waits.

At the three-town-service milestone (`70d7247`), ordinary globals occupied 3,789 bytes
(`0xC000..0xCECC`), leaving 307 bytes before the fixed map. That is 111 bytes
above the corrected C reference: the 14-byte result arena, 96-byte text buffer
and one fault byte. The three services add nine RAM bytes over the pear
milestone. That smoke driver used 13 additional RAM bytes per variant.

The production adapter/quest bank occupies 4,774 bytes, the service-rule bank
7,232 bytes and the text bank 1,657 bytes. Occupied ROM is 432,951 bytes for
Vexel and 424,084 for the corrected C reference; resident code still ends at
`0x5EBD` in both. These measurements use the same toolchain and flags as above.
The complete 19-visit smoke run takes 51.1828 emulated seconds for C and
51.6000 for Vexel, including rendering and fixed waits. Additional stack use
observed from scenario entry is 182 bytes for C and 192 for Vexel; these remain
measurements of the exercised paths, including interrupts, rather than a
whole-game bound.

At the saloon-password milestone (`1b91580`), production costs were:

| Measurement | Corrected C reference | Vexel gameplay |
|---|---:|---:|
| Cartridge size | 434,176 bytes | 450,560 bytes |
| Occupied ROM, excluding bank padding | 426,117 bytes | 442,249 bytes |
| Ordinary global RAM | 3,774 bytes | 3,795 bytes |
| End of ordinary globals (exclusive) | `0xCEBE` | `0xCED3` |
| Space before fixed map at `0xD000` | 322 bytes | 301 bytes |
| Resident ROM end (exclusive) | `0x5EBD` | `0x5ECB` |

The Vexel build adds six global bytes over the town-services milestone: its
result arena grows from 14 to 20 bytes. The saloon shares the existing 96-byte
text buffer. The corrected reference now uses that buffer too; the remaining
21-byte difference is the Vexel result arena and fault byte. No extra persistent
password or gameplay state is allocated in production.

The saloon adapter, encoder and checked-shift helper occupy 4,166 bytes in page
C; the decoder and its materialized helpers occupy 6,774 bytes in page B.
The existing quest and service banks occupy 4,760 and 7,232 bytes; the shared
text bank occupies 1,920 bytes. Moving the fault handler to resident ROM costs
14 bytes there and frees 14 from the quest bank. The smoke-only input queue,
saved password and reports occupy 33 bytes per variant. Materialized helper
results use automatic storage. The 24-visit run observes 204 additional stack
bytes for C and 268 for Vexel, from scenario entry and including interrupts.
Elapsed emulated times are 70.6478 and 71.2755 seconds, including all display
waits. These are exercised-path measurements, not whole-game bounds.

At the world-interaction/drop milestone (`4af6401`), production costs were:

| Measurement | Corrected C reference | Vexel gameplay |
|---|---:|---:|
| Cartridge size | 434,176 bytes | 450,560 bytes |
| Occupied ROM, excluding bank padding | 426,016 bytes | 448,521 bytes |
| Ordinary global RAM | 3,774 bytes | 3,795 bytes |
| Space before fixed map at `0xD000` | 322 bytes | 301 bytes |
| Resident ROM end (exclusive) | `0x5EBD` | `0x5ECB` |

The new world-rule bank uses 5,743 bytes and the drop-rule bank 1,375 bytes.
The shared text bank grows to 2,120 bytes. Production global RAM and resident
ROM are unchanged; the existing bank padding accommodates the added code
without growing the cartridge image. The connected smoke driver uses 38
additional RAM bytes per profile, including its input queue and reports.
The full connected run takes 111.3616 emulated seconds for C and 112.1960 for
Vexel, including the existing town visits, real scrolling and fixed waits.
Additional stack usage observed from scenario entry is 240 bytes for C and
285 for Vexel, including interrupts. These remain exercised-path measurements,
not a whole-game stack bound. All 60 captured popups match between profiles;
the 24 building exits and the world warning restore both map buffers.

Before the shared combat migration, with town interactions, ghosts and skeletons
migrated and the shared sprite resource boundary enabled, production costs were:

| Measurement | Corrected C reference | Vexel gameplay |
|---|---:|---:|
| Cartridge size | 434,176 bytes | 458,752 bytes |
| Occupied ROM, excluding bank padding | 426,692 bytes | 455,408 bytes |
| Ordinary global RAM | 3,774 bytes | 3,795 bytes |
| Space before fixed map at `0xD000` | 322 bytes | 301 bytes |
| Resident ROM end (exclusive) | `0x5EBD` | `0x5ECB` |

The town-rule bank uses 4,951 bytes, the ghost callback/rules bank 2,081 bytes,
the skeleton callback/rules bank 3,151 bytes (C: 1,914), and the text bank 2,809
bytes. Skeleton migration adds 1,209 occupied ROM bytes while global RAM,
cartridge allocation and resident ROM remain unchanged. The resource boundary
adds another 255 ROM bytes with no RAM or cartridge-size increase. The smoke
profile adds 40 RAM bytes per variant; the encounter profile adds 31 for C and
36 for Vexel, including five bytes of resource-test metadata.

The general typed value projection replaces the earlier four-call arena
embedding and game-local arithmetic macros:

| Ghost callback, average of 32 updates | C reference | Earlier Vexel | Typed value Vexel |
|---|---:|---:|---:|
| Active update | 1,843.09 us | 5,236.76 us | 1,959.86 us |
| Skipped update | 550.40 us | 1,477.61 us | 547.05 us |

Active updates are about 2.67 times faster than the previous Vexel embedding
and remain about 6.3% slower than the C reference. Skipped updates match C
within 1%. The ghost bank also shrinks by 1,289 bytes, with unchanged global
RAM. These results establish that the resolver's information can remove most
of the earlier abstraction cost; they do not establish a general speed advantage
over C. The first generic-runtime version had taken 60.97 ms per active update.

The batches include the real trampoline, common entity gate, collision work,
loop overhead and any intervening ISR. They are not isolated arithmetic costs
or worst-case bounds. An individual ghost moves once every four game cycles;
this is not a whole-game frame-rate measurement. Further enemy migration should
profile multiple active enemies as well as individual callbacks.
`make ghost-benchmark` rebuilds both MSX smoke profiles and reruns this same
scenario at 10x emulation speed, retaining every functional/VRAM check. Reports
and captures go to `build/ghost-benchmark`; all timings use emulated time.

### Mixed encounter in the ordinary game loop

`make encounter` runs four skeletons and four ghosts for 32 ordinary game-loop
iterations, then exercises contact damage, a real weapon hit, death, explosion
and drop creation over another 32 iterations. It uses the real player/enemy
callbacks, map flags, renderer and cooperative ISR (`wait_frame`/`yield`).
The initial crowd fills slots 4..11; two ghosts leave before the weapon hit
to reserve slots for the explosion and drop. The existing engine cannot
allocate those effects while that pool is full. The player starts on clear
ground so knockback does not open an unrelated automatic map interaction.

The MSX `rand7` reads the CPU refresh register, so different instruction
sequences cannot reproduce the same random stream. This test-only build uses
a deterministic byte stream for skeletons; production retains `rand7`.
Ghosts and drops use seeded production `rand16`. All 32 crowd snapshots match
between the reference and Vexel, including positions, velocity/routine,
delay, health and slot assignment. Combat checks use actual elapsed ISR
ticks, so they verify outcomes rather than demanding identical timer traces.
Both complete engines pass the same scene on SDL.

On C-BIOS MSX1 with the existing Konami-SCC mapper, SDCC 4.2, emulated time:

| Observed measurement | C reference | Vexel gameplay |
|---|---:|---:|
| Crowd loop period, mean / maximum | 33.602 / 40.128 ms | 33.614 / 40.534 ms |
| Crowd frame scope, mean / maximum | 33.268 / 39.886 ms | 33.285 / 40.293 ms |
| Crowd update body, mean | 15.363 ms | 15.582 ms |
| Combat frame scope, mean / maximum | 36.005 / 61.100 ms | 36.961 / 61.318 ms |
| Additional stack observed from loop entry | 111 bytes | 121 bytes |
| Bank-restoration checkpoints | 192 passed | 192 passed |

The frame scope begins before `wait_frame` and ends after the entity scheduler
and automatic spawn scan. It includes the wait, ISR/rendering and input. The
body begins after input. Loop periods include the small test hook between
frames; the debugger reads live entity fields using target layout metadata,
without adding a state-copy loop to the game. Scenario setup and weapon
injection occur outside the frame scope. Full samples and screenshots are
under `build/encounter`. The run tracks actual mapper register writes as well
as the software bank shadow at loop entry, after the wait, and after updates.

Vexel's crowd update body costs about 1.4% more here; the mean loop period
changes by less than 0.1% because waiting absorbs much of that difference.
This establishes a usable integration, not a speed advantage or a 60 Hz claim.
Maximum times and stack use describe these paths, not worst-case bounds.
The shared sprite resource binding validates placement and confines address use to
the renderer. Other banked sprite lifetimes still belong to the C adapters;
the resolver does not yet prove arbitrary engine boundaries automatically.

The optimization pass used the existing case interface first, then changed
the general value emitter to avoid duplicate parameter snapshots and emit
branch-independent result stores once. Computed shared operands retain their
SDCC safeguards. SDCC already reuses storage across branch-local scopes; the
remaining benefit came from removing unnecessary temporaries, without adding
an allocator or changing the Vexel game rules.

| Vexel encounter revision | Crowd update mean | Observed additional stack |
|---|---:|---:|
| Original full value interface | 16.134 ms | 143 bytes |
| Existing dependency split | 15.663 ms | 135 bytes |
| Split plus general emitter simplification | 15.593 ms | 121 bytes |

This cuts measured crowd update work by 3.4% and observed stack use by 22 bytes
relative to the first skeleton migration. The production skeleton bank falls
from 4,177 to 3,123 bytes (1,054 bytes, about 25%); the C reference ROM remains
byte-identical. Cartridge allocation and global RAM stay unchanged.
The full update's declared generated
temporaries fall from 34 bytes to zero; that declaration count is separate from
the caller's result storage and the measured machine stack. Before/intermediate
ROMs, assembly and measurements are retained locally in
`build/skeleti-optimization`; the final encounter is reproducible with
`make encounter`.

A subsequent trial returned the tick and random-request decisions as C scalars
instead of writing one-field result structs. Host and Z80 correctness checks
passed, but this SDCC build increased the crowd update mean from 15.593 to
15.799 ms, used 366 more encounter ROM bytes and raised observed additional stack from
121 to 122 bytes. Both helpers were already inlined in the callback. The trial
was reverted; the result-buffer interface above remains the measured choice.
Local evidence and the discarded candidate are under `build/scalar-optimization`.
This result concerns this embedding and compiler configuration, not scalar
returns in general.

The complete 67-capture scenario takes 133.4455 emulated seconds for C and
134.3820 for Vexel, including all display waits and scrolling. Additional
stack usage observed from scenario entry is 240 and 285 bytes respectively,
unchanged from the world-interaction scenario. This remains an exercised-path
measurement, including interrupts, rather than a whole-game stack bound.

Popup comparisons read VRAM patterns, colors and placement in both name tables
for every dialogue, including the lumberjack. Comparing the entire screenshot
would also compare unrelated sprite/infobar animation phases; those legitimately
differ with execution timing. Background color, inventory, health rendering and
map restoration retain their independent checks, and full screenshots remain
available for inspection.

`make test` compares deterministic traces from the **production** original C
callbacks and Vexel-backed callbacks under UBSan. It checks dialogue ordering,
follower trail initialization, repeated contact, one reward, reset and despawn
before delivery. Pear cases cover unavailable YES, declining, changing one's
mind, both rewards, repeat visits, simultaneous clicks and the existing currency
arithmetic. Rendering and infobar stubs overwrite the released projection to
check that effects use owned values. Small linker fixtures cover XL2/XL3 word
and byte relocations, resident ROM overflow, map overlap and unplaceable banked
resident sections.

`make smoke` runs both complete engines on Linux and an emulated MSX1. It
compares three lumberjack and nine pear popup renderings. It compares the popup's VRAM patterns, colors and placement in
both name tables; the surrounding world continues animating independently.
It also checks that the popup tiles are actually present, so two missing menus
cannot pass by equality alone. Screenshots are retained for visual inspection.

The scenario exercises real mapper switches, renderer/ISR activity and the
original spawn/despawn callbacks, then checks the bank shadows are restored.
The pear cases use a small RAM input queue read by a resident test helper:
the page-C scenario module is unmapped while the town hall or Vexel adapter
runs. The scenario now runs the normal door-entry and exit animations for each
pear visit. It saves the map tiles before any pear menu and verifies that both
screen buffers match those tiles after every exit, without scrolling. This
catches stale dialogues even if both implementations share the bug. Route
navigation and unrelated quests still need ordinary playtesting.
No physical MSX test has been performed.

Town-service validation extends this to payments at exact balances and just
below them, healing and health caps, consecutive courses, learned abilities,
stock progression, immediate weapon initialization, all eight ordinary-book
draws and failed purchases followed by leaving. Host traces compare the real
C and Vexel adapters under UBSan, with sinks overwriting the released payload.
The full-engine scenario also visits all three services, compares 29 more
popup renderings and verifies restoration of both map buffers after all 19
building exits. Its random source is fixed only in the smoke profile.

Password checks add seven fixed MSX vectors, each checksum nibble failing
independently, malformed lengths/alphabet, reserved bits with a valid checksum,
impossible health/currency, lowercase, cheats, selected-weapon fallback and
UI keyboard-state restoration. Rejections compare the entire state and verify
that no effect sink ran; successful sinks overwrite the released arena.

The full-engine scenario adds five saloon visits after purchasing equipment:
record a password, clear inventory, restore, initialize and spawn a real bow
projectile, reject a corrupt checksum, then exercise both commands. In MSX
smoke builds, every displayed password is also compared with the frozen
original bitfield encoder compiled by SDCC. Both name tables are checked for
obsolete hearts after restoring six health over forty. Ten saloon popup
captures join the 29 service captures, and all 24 building exits must restore
the map without scrolling. These checks remain separate from production.

World checks compare every implemented mountain route and every secret-passage
pair, including left/right entrance tiles, with the retained C trigger callback.
They cover lamp refusal, direction gating, the unfinished cave, well counters
0/1/2/4/5/255, exact dialogue and boots warnings on each rock class. Frame waits
and dialogue sinks overwrite the shared result arena to exercise ownership.
Drop checks use the real spawn/despawn helper and callbacks. They test both
sides of all twelve probability thresholds, upper-byte truncation, draw counts,
all four rewards, health caps, one-time collection and animation/expiry boundaries.

The full-engine world scenario runs after the town visits. It positions the
player on real map tiles, then uses the actual trigger callbacks, collision,
scrolling, renderer and ISR. It collects a coin to fund a lamp, travels through
the mountain, saves equipment at the saloon, loses it and is refused entry,
then restores the password and travels again. Well visits cover first/repeat/
last/silent dialogue; the route continues through a secret passage both ways
and verifies boots warnings. Pickups also exercise heart healing and the ISR's
money cap. The random source and repositioning are smoke-only. Nine small-popup
captures compare text and placement, and both complete map name tables must
be restored after the rock warning without scrolling.

Town validation compares all twelve house destinations in both languages,
first/second random-draw counts, service dispatch, all nine boards, repeat and
unknown-board behaviour, and the monster's text/damage/wait order at several
health levels. Ghost checks compare C and Vexel callbacks with an independent
fixed-width arithmetic oracle, including signed extremes, coordinate wrap,
spawn bits, frame variants, skipped ticks and collision/death gates. Effect
stubs overwrite the released result arena.

The connected scenario adds three house trips, a repeated signboard read,
all three monster bites with map restoration, and the real ghost spawn/update/
death chain including explosion and drop callbacks. A 32-update active batch
and a 32-update skipped batch measure MSX callback costs, including the
resident trampoline and any intervening ISR work. These are batch averages,
not worst-case bounds or whole-game frame timings.

## Small baseline repairs

- Use the installed tools and pinned local library instead of missing private
  SDCC paths; keep the legacy stack calling convention.
- Teach the module linker modern XL3 objects as well as XL2. Check resident
  overflow before bank free-space arithmetic, and reserve the map's actual
  `0xD000` boundary instead of allowing globals up to `0xF000`.
- Allow SDL's software renderer and give the window the game's name.
- Correct the death-animation sprite backup: an eleven-element buffer was
  accessed at indices 1 through 11; it now uses 0 through 10.
- Correct the host debug print's `sizeof` argument type.
- Clear the entire `0xC000..0xCFFF` global arena at startup. Clearing only its
  first 1,032 bytes left the minimap cache uninitialized; the first player
  update could send `0xFFFF` as a VRAM address and accidentally set VDP register
  7 to white. The smoke test now checks the actual background register as well
  as its RAM shadow, independently of the reference screenshots.
- Restore the black backdrop and display-enable bit on game entry, including
  when the player skips the title during a flash or while it is blanked.
- Keep the popup bank mapped while the original C pear menu moves its cursor.
  Previously only the initial drawing mapped that bank; navigation could call
  an unmapped renderer. This repair makes the retained MSX reference usable.
- Request a map redraw on door exit. The ISR restores both screen buffers
  during the exit animation, removing the building's dialogue without waiting
  for the player to scroll. This adds five ROM bytes and no RAM to each build
  relative to the pear milestone above.
- Map `largepopup` when the three town services call its functions, and keep
  that bank mapped during reference-menu cursor writes. They previously
  mapped the different `popup` module and left cursor calls unguarded.
- Initialize newly selected shop and university weapons before updating the
  infobar. Previously ownership and the icon changed but attack entities could
  retain the previous weapon's initialization. Both implementations receive
  this repair.
- Consume a collected drop before returning from its callback, preventing a
  second payout when the spawn helper has already invoked that callback.

The optimized graphics transfers and audio assembly remain engine operations.

## What this establishes, and what remains

Ghosts and skeletons use the same resource boundary. `gameplay/sprite_assets.vx`
lists their families; `ghost_assets.vx` and `skeleti_assets.vx` declare the asset
modules and ordered frame symbols as ordinary compile-time Vexel values.
The generator resolves them into `vx_sprite_assets.h`, `vx_sprite_assets.inc`
and `vx_sprite_assets.json`. Gameplay publishes only a nonzero byte handle;
zero means no pending request. The handle replaces an unused byte in each
sprite slot, preserving the existing layout. Handles 1–12 select ghost frames,
13–22 skeleton frames; these are build-local identities, not a save-file ABI.
Spawn/despawn clears old requests and legacy pointers. Skeleton spawn queues
its initial frame; update result 255 leaves the pending handle untouched,
including zero when a previous request has already been consumed.

The rendering sink keeps a request while the sprite is disabled or offscreen.
A newer request replaces the pending one, including across families. One
descriptor table lives alongside the renderer in page B. Each descriptor pairs
the asset's bank with its address; both are relocated by the linker. Once
visible, the sink selects a descriptor, maps page D, uploads patterns and colors,
and restores the previous page-D mapping. No resolved address escapes that
operation. The renderer borrows the existing legacy upload fields as temporary
storage, then clears the pointer before restoring the mapping. This shares the
established upload path without introducing persistent pointers into gameplay.
Invalid handles are discarded without reading a table entry.
Color overrides still apply. Other sprite families retain their existing
pointer-and-bank interface.

The legacy linker now exports full module, section and symbol placement in
`weiss.rom.layout.json`. The Vexel build checks both resource families against
those final facts: module/page ownership, section and window bounds, physical
ROM offsets, and the actual bank/address descriptors. The descriptor table must
reside with the renderer in page B and fit its section. A failed check fails the
build; the accepted binding is recorded in `weiss.rom.resources.json`.
Ordinary game builds use the checked-in projection; `make generate` resolves
the declaration again and fingerprints the binding tools and outputs.

The host tests exercise all declared frames, deferred and replaced requests,
single consumption, color overrides, invalid handles, legacy rendering and
slot cleanup for both families. Link checks include distinct banks containing
assets at the same CPU address. After its timed combat sequence, `make encounter`
queues all 22 frames while an unrelated ROM bank occupies page D, keeps them pending
offscreen, then consumes it through the real renderer. openMSX compares all
96 pattern bytes and both colors with the linked ROM and checks the physical
mapper register as well as the software shadow. This phase is outside the
encounter timing and stack measurement.

This is an explicit embedding contract, not a proof of arbitrary C pointer
lifetimes. It relies on the engine serializing publication and rendering; it
does not add a concurrent queue. Adding a family supplies declarations to the
same generator rather than another renderer branch. Linker validation checks
placement rather than searching
for a better placement or changing mapper hardware.

The first, ghost-only resource boundary changed
the mean crowd loop from 33.605 to 33.633 ms (+0.084%) and mean update work from
15.593 to 15.578 ms. Observed additional stack remains 121 bytes. The combat
frame mean/maximum changes from 36.003/61.039 to 36.952/62.080 ms; its timers use
elapsed ISR ticks, so execution paths can shift with timing. These measurements
establish the cost of the boundary, not a general speedup. Production ROM grows
by 274 bytes, global RAM remains 3,795 bytes, and the C reference production ROM
is byte-identical. That baseline and its logs are in `build/resource-boundary`.
`make test`, `make encounter` and the complete `make smoke` pass. Both native
SDL profiles and both MSX profiles preserve the 67 captured dialogue layouts,
map restoration, black background, inventory effects and ghost lifecycle.

The shared ghost/skeleton binding adds the second family while reducing
occupied ROM by 19 bytes against the ghost-only implementation. Global RAM
stays at 3,795 bytes and observed encounter stack remains 121 bytes. Mean crowd
loop time changes from 33.633 to 33.614 ms; worst crowd frames fall from 41.092
to 40.293 ms. Mean combat frames are effectively unchanged (36.952 to 36.961 ms),
and the observed maximum falls from 62.080 to 61.318 ms. These are workload
measurements, not worst-case guarantees. The selected implementation uses the
existing upload fields within the sink; a candidate keeping the selected
pointer in a C local produced worse target code and was discarded.
Detailed comparisons and that candidate are in `build/shared-sprite-resources`.
The linker moved the ghost assets from bank 44 to bank 53 during this change;
the generated descriptors followed the move without gameplay edits. Final
validation passed `make test`, `make encounter`, and the complete SDL/MSX
smoke scenario with openMSX at 10x speed. All 67 dialogue captures still match.

### Shared combat and cardinal knockback

`gameplay/combat.vx` now owns three pure decisions: `combat_hit` accepts or
rejects contact and selects damage/reaction, `combat_tick` advances immunity
and recovery, and `combat_death` selects available explosion/drop entities.
Player, ghost, skeleton and ball callbacks use the same reaction adapter.
The player death cutscene and its inventory/health penalty remain C.

This deliberately changes both the C reference and Vexel gameplay. A new hit
requires positive life, positive damage and no remaining immunity. Damage
saturates at zero. Accepted hits grant 60 display ticks of immunity and a
six-tick slide at three pixels per tick: 18 pixels on clear ground. The
dominant axis points away from the aggressor; its facing breaks equal-axis
ties and exact overlap. A resting aggressor at exact overlap pushes downward.
Direction comes from the two entities' coordinates, not scratch state left
by a preceding collision query. There is no normalization loop or diagonal
speed variation. Coordinates use the existing 1/32-pixel representation.

The adapter checks each one-pixel step against the existing foot collision
query. A wall clears displacement but leaves the remaining recovery timer;
coordinate wrap and the map's foot-sampling bounds stop movement before a
map read. Timers saturate rather than underflow when more ticks elapse than
remain. Rejected contact changes neither direction nor timers. Player movement,
weapon switching and new attacks pause through the final reaction tick; already
spawned weapons continue independently. Enemy AI and contact attacks pause too.
Sprite position follows every shove step even when the ordinary AI cadence
would skip that update. The player camera follows the displaced position.
No extra entity fields or heap allocation are introduced. The fixed-frame
realization described below adds reusable calculation workspace.

Dead enemies resolve before movement, placing their effects at the impact
position. Effects use the first available matching entity; the second explosion
checks its own slot rather than the unrelated bomb slot used by the old code.
Allocation can still fail when visible slots are full. The adapter consumes
the caller-owned result before invoking any spawn callback, restores the
enemy's home/health state, clears reaction state, and asks the scheduler to
despawn it. The existing drop rules decide the reward.

The hit projection stays in the collision bank. A page-D combat module holds
the recovery and death adapters, entered through resident code which restores
the caller's bank. The map's resident collision routine restores its temporary
page-C/page-D mappings before returning. The ordinary healthy case is expressed
as a constant branch in Vexel. Its generated predicate needs only life,
immunity and recovery; the resident adapter consumes the generated constant
case and bypasses the combat bank only when it describes an unchanged result
with no effects. Other results take the normal path. This uses the existing
general value/case emitter, without a combat-specific compiler optimization.
The generator checks field layouts and branch dependencies.

Host checks cover direction/ties/overlap, zero damage, rejected repeats,
identical distance with one/two/three-tick batches, large elapsed values,
visibility, walls/map edges and occupied/full effect slots. Enemy callback
checks require a stunned update to skip AI, randomness and contact effects.
The full encounter additionally exercises actual SDCC hit arithmetic, timer
saturation, all six player steps while contrary movement/attack/switch input
is held, and a wall found in the real map. These checks run after the timed
encounter, so they do not inflate its timings or stack measurements.
The resource test now chooses a bank absent from both sprite families instead
of assuming bank zero is unrelated; final placement remains linker-selected.

Production costs before selecting fixed frames were:

| Measurement | Revised C reference | Vexel gameplay |
|---|---:|---:|
| Cartridge size | 434,176 bytes | 458,752 bytes |
| Occupied ROM | 427,345 bytes | 457,895 bytes |
| Ordinary global RAM | 3,774 bytes | 3,795 bytes |
| Resident ROM end (exclusive) | `0x5CB8` | `0x5E59` |
| Observed additional encounter stack | 111 bytes | 154 bytes |

Vexel adds 2,487 occupied ROM bytes over the shared-sprite baseline, with no
global RAM or image-size increase. Moving the common reaction out of resident
code leaves its end 114 bytes lower despite the new resident predicate. The
combat bank uses 2,034 bytes, collision bank 1,827, and resident collision
wrappers/predicate 548. The generator's constant-case result is consumed and
checked in C; SDCC retains some of those local copies/checks rather than folding
them all away. There is no promise of zero abstraction cost.

The Vexel crowd frame mean is 33.308 ms (previously 33.285), and complete loop
mean is 33.638 ms (previously 33.614). Mean update work is 16.328 ms, up 4.8%
from 15.582; observed additional stack grows from 121 to 154 bytes. The revised
C reference measures 33.240 ms per crowd frame and 14.459 ms update work.
Vexel combat frames average 34.890 ms with a 52.337 ms observed maximum, but
combat behaviour and the death/drop fixture intentionally changed, so this
is not a like-for-like speedup claim. The first candidate performed every
update in the reaction bank; the generated resident predicate removes most
of that overhead. Reports and comparisons are in `build/combat-migration`.
Validation passed `make test`, both ordinary Linux/MSX builds, `make encounter`,
and the complete SDL/MSX smoke scenario at 10x emulation speed. All 67 dialogue
captures and 24 building-exit map restorations agree; all 22 delayed sprite
uploads match their linked assets. The smoke scenario's observed additional
stack stays at 240 bytes for C and 285 for Vexel. These scenarios validate the
mechanics and integration; the subjective feel still benefits from playtesting.

### Fixed RAM for exclusive calculations

The first fixed-frame integration used a second storage realization of eligible pure integer
graphs. `vx_fixed_NAME.h` places flattened inputs, shared calculations and
results in a static frame. Every calculation still executes on each call.
The generated entry takes no C arguments and writes its named result fields,
so SDCC can use direct RAM addresses instead of stack-relative parameters,
locals and result-pointer accesses. The ordinary value and arena interfaces
remain available.

Selection requires the solver's closed activation graph to exclude overlap,
recursion and open boundary calls. The C adapter owns the frame from its first
input write through result consumption. All engine effects happen outside this
interval. In particular, death decisions are copied before spawning effects;
an outer entity pointer and pending drop choice remain automatic because they
can survive a nested callback. A host check reenters combat from the spawn
callback and verifies that the outer pending drop survives frame reuse.

Combat hit, tick and death used 21, 13 and 6 bytes respectively. Drop selection
and collection used 8 and 6, embedded directly in the existing drop entity bank.
The resident healthy-result workspace used another 5 bytes. The total was 59
bytes against a manual `combat_frame_budget=64`; generation rejected
an unavailable fixed interface or a budget overflow. Its report recorded this
selection in `embedding_frames`. Target `sizeof` assertions and final linker
RAM checks cover the actual allocation. Including a fixed header in another
translation unit would allocate another frame and require updating the budget.

Drop selection releases its result before obtaining a random value, then
refills every input before calling again. There is no longer a separate
`drop_rules` bank call in the game. Its ordinary generated `vx_drops.inc`
remains available for inspection. This migration followed an openMSX stack
trace identifying the old drop projection as the deepest remaining call during
enemy death after switching combat to fixed frames.

This was selective storage planning, not a whole-engine static allocator.
That implementation kept fixed frames distinct. C engine frames, return addresses,
compiler spills and arithmetic helpers can still use stack storage. The
ordinary solver arena frame budget does not silently allocate these optional
headers; this embedding explicitly selects and budgets them.

Measured costs for the same gameplay and encounter are:

| Measurement | Before fixed frames | Fixed combat/drop frames |
|---|---:|---:|
| Observed additional encounter stack | 154 bytes | 129 bytes |
| Mean crowd update work | 16.328 ms | 16.253 ms |
| Mean combat update work | 18.079 ms | 17.884 ms |
| Mean crowd frame including waits | 33.308 ms | 33.306 ms |
| Occupied production ROM | 457,895 bytes | 457,663 bytes |
| Production globals | 3,795 bytes | 3,854 bytes |
| Space before map at `0xD000` | 301 bytes | 242 bytes |

The cartridge remains 458,752 bytes; resident ROM ends at `0x5E5E`. Encounter
stack falls by 25 bytes (16.2%), and mean combat update work by 1.1%. Complete
frame timing is almost unchanged because rendering and display waits remain.
The C reference's memory and encounter measurements are unchanged. These are
workload observations, not whole-program stack bounds. The host integration,
nested callback, Z80 value-interface and full mixed encounter checks pass,
including all 22 sprite resource uploads. Before/after reports are retained in
`build/fixed-combat/comparison.json`, with the solver, manifest and tested ROM
hashes. Both production Linux/MSX builds and the complete SDL/MSX smoke run
pass. All 67 dialogue captures agree and all 24 building exits restore the map.
The longer dialogue/world scenario still observes 285 additional stack bytes
for Vexel and 240 for C; its peak is not reduced by this combat/drop selection.

### Solver-selected storage before sharing

The next integration replaced that manual selection with `c_binding`
metadata on the Vexel source definitions. Each binding names its full or
specialized case interface, gives an estimated relative call frequency, and
states the engine's lifetime contract. Frequencies are optimization hints,
not measured execution counts. `quests.vx` supplies a 128-byte
`value_frame_bytes` allowance through an ordinary `prefer` relationship.

The solver verifies eligibility and chooses the frames in descending frequency
order, then by smaller size and identity. The resulting plan selects ten fixed
bindings totaling exactly 128 bytes: combat hit/tick/death/idle (45), ghost
movement (32), skeleton tick/draws/movement/waiting (45), and drop collection
(6). Ghost spawning and drop rolling remain automatic because they do not fit
the remaining allowance. Lowering the budget changes generated storage while
the C adapters keep the same declaration, input assignment, run and result API.
The generator validates interface layouts and case dependencies; it does not
choose which functions become static.

`src/gameplay/value_frames.c` compiles the solver's `vx_binding_frames.c` once.
Fixed frames have external linkage and one allocation per named binding;
including a binding header in another caller does not allocate another copy.
For automatic bindings, `VX_BIND_name_LOCAL` declares a frame in the owning
C scope. The run entry calls a parameterless function for fixed storage or
passes the automatic frame's address. Both reuse the same source graph and
arithmetic safeguards. Keeping computation in a function prevents SDCC from
incorrectly forwarding a just-published input inside a larger adapter. The
encounter trace caught this in skeleton cadence during the first macro-only
candidate; the calculation and test expectations were preserved.

The engine's `exclusive` contract covers the first input write through final
result consumption. Random draws, map calls and spawn callbacks remain outside
that interval. The solver also requires its own activation-exclusion proof;
an open contract or possible source overlap keeps storage automatic. Death
choices and outer C engine state still survive nested callbacks in separate
storage. These are explicit C boundary facts, not a claim that Vexel analyzes
arbitrary C callers. This first selection kept fixed frames distinct.

The generic value checks compile one unchanged C client under zero, partial
and full budgets, including restricted-input traps, selected cases, nested
automatic lifetimes and copying before fixed-frame reuse. Different solver
traversal orders produce the same plan. Z80 checks exercise both zero-budget
and fixed plans against the existing independent integer vectors.

The corrected game encounter passes with identical crowd decisions, contact,
weapon/death/drop behavior, bank restoration and all 22 sprite resource checks.
Compared with the previous manual combat/drop selection:

| Measurement | Manual selection | Solver selection |
|---|---:|---:|
| Selected fixed workspace | 59 bytes | 128 bytes |
| Observed additional encounter stack | 129 bytes | 121 bytes |
| Mean crowd update work | 16.253 ms | 16.467 ms |
| Mean combat update work | 17.884 ms | 18.118 ms |
| Mean crowd frame including waits | 33.306 ms | 33.316 ms |
| Occupied production ROM | 457,663 bytes | 456,202 bytes |
| Production globals | 3,854 bytes | 3,923 bytes |
| Space before map at `0xD000` | 242 bytes | 173 bytes |

The image remains 458,752 bytes; resident ROM ends at `0x5E65`. Stack growth
falls by eight bytes (6.2%), while update work grows about 1.3%. Complete frame
time is nearly unchanged. This policy delivers automatic storage selection
and stack relief, not a speed-optimal plan; frequencies alone do not predict
SDCC instruction cost. C reference measurements remain unchanged. The evidence
is retained in `build/selected-frames`, including the initial macro-only
candidate's incorrect cadence assembly. Fixed frame sizes are checked on Z80
and their total agrees with final linked RAM.

Both production Linux/MSX builds and the full SDL/MSX smoke run pass. All 67
dialogue captures and 24 building exits agree. The smoke scenario's stack peak
remains 285 bytes for Vexel and 240 for C. Its active ghost callback measures
1.964 ms (previously 1.991), while skipped callbacks measure 0.602 ms
(previously 0.592), including the trampoline and ISR. The before/after reports,
selected plan and solver/manifest/ROM hashes are in
`build/selected-frames/comparison.json`. The solver regression suite and final
host/Z80 binding checks also passed.

### Shared fixed workspaces

The current integration adds `c_disjoint` metadata in `quests.vx`: every pair
of the twelve named bindings has disjoint input-preparation through
result-consumption lifetimes. The existing adapters already copy or consume
results before random draws, map calls and spawn callbacks. Their C interface
stays unchanged; the external contract lives beside the RAM allowance.

The solver checks eligibility as before, then packs a candidate only into a
slot whose every existing member explicitly excludes it. Exclusion is not
transitive, and neither these facts nor a larger budget can promote an open
or otherwise ineligible binding. It minimizes incremental RAM for each
candidate in the existing frequency/size/identity order. Missing facts keep
storage separate; this remains a deterministic heuristic.

All twelve bindings now fit in one 32-byte typed C union, the size of ghost
movement. Their independent sizes sum to 149 bytes. Compared with the previous
ten bindings in 128 bytes, sharing saves 96 bytes and also moves ghost spawning
and drop rolling off automatic frames. The 128-byte allowance remains an upper
bound. `value_bindings` reports both physical and unshared totals, slot members
and contract origins. Target `sizeof` assertions check each frame and union.
`vx_binding_types.h` carries frame types, `vx_binding_storage.h` declares slots,
and `vx_binding_frames.c` owns their single allocation. Each binding uses a
typed union member; no byte-arena casts or unrelated-pointer aliasing are used.

The generic host/Z80 checks run the same C client with automatic, separate
fixed and shared storage, including mixed-width members and copied results.
Host checks retain a result across another binding when only a nontransitive
chain of exclusions exists. The game's drop mock invokes the skeleton tick
binding from random and collision callbacks, overwriting the shared workspace;
drop calculation must republish every input after the random draw. The combat
mock still reenters during spawning and checks the outer pending drop choice.

The real MSX encounter retains identical decisions, contacts, weapon/death/drop
behavior, bank restoration and all 22 sprite resource checks:

| Measurement | Separate selected frames | Shared workspace |
|---|---:|---:|
| Selected fixed workspace | 128 bytes / 10 bindings | 32 bytes / 12 bindings |
| Observed additional encounter stack | 121 bytes | 111 bytes |
| Mean crowd update work | 16.467 ms | 16.461 ms |
| Mean combat update work | 18.118 ms | 17.996 ms |
| Mean crowd frame including waits | 33.316 ms | 33.315 ms |
| Occupied production ROM | 456,202 bytes | 455,925 bytes |
| Production globals | 3,923 bytes | 3,827 bytes |
| Space before map at `0xD000` | 173 bytes | 269 bytes |

The image remains 458,752 bytes and resident ROM ends at `0x5E65`. Encounter
stack drops another ten bytes (8.3%), matching the C reference's observed 111.
Combat update work falls about 0.7%, while crowd timing is essentially unchanged.
Sharing saves RAM; the extra stack reduction follows from also selecting the
previously automatic drop-roll and ghost-spawn bindings. The larger dialogue
scenario and these encounter observations are not whole-program stack bounds.

Both production Linux/MSX builds and the complete SDL/MSX smoke run pass.
All 67 dialogue captures agree and all 24 building exits restore the map.
The broader smoke scenario retains its 285-byte Vexel stack peak (240 for C).
Its active ghost callback measures 1.959 ms, down from 1.964 ms; skipped
callbacks remain 0.602 ms, including the trampoline and ISR. Reference ROMs
are byte-for-byte unchanged. Before/after measurements, the selected plan,
and solver, manifest, Linux executable and ROM hashes are recorded in
`build/shared-frames/comparison.json`. Logs in that directory retain host,
production, encounter and smoke checks; generic solver logs are under the
parent project's `build/shared-frame-*.log`. The full solver regression suite,
final host/Z80 value checks and generated-file freshness checks all pass.

These contracts describe the existing C engine; Vexel does not infer arbitrary
C lifetimes. C locals retained across callbacks, return addresses and compiler
spills still use their normal storage. Sharing is not a whole-program stack
bound or a claim of cycle-optimal code generation.

### Password decoder stack allocation

The 285-byte dialogue/world peak was in password restoration. The optional
`--stack-detail` mode of `tests/check_smoke.py` captures the deepest write's PC,
SP, IX/IY, physical mapper banks, scenario checkpoint and stack bytes. It
observes the existing ROM without adding game instrumentation. The snapshot
preserves the pending write byte and starts at the deepest touched address;
it is a workload observation, not a bound on all possible stack use.

In the saved Vexel ROM, the peak PC is `0x8019`, inside `vx_shift` in physical
bank `0x34`. The saved IX chain and call instructions establish:

`quest_saloon → password_restore → vx_password_decode → vx_flow_6 → vx_shift`.

The first return addresses are `0x67C6` (the helper in page B, bank `0x2C`),
`0x7365` (the decoder), `0x8E90` (restore) and `0x9195` (saloon). These belong
to the archived ROM and listings, not future builds. The decoder reserves
100 bytes in SDCC's frame while calling its helpers; 88 are generated buffers
and temporaries. This is separate from the shared 32-byte binding workspace.

`quests.vx` now supplies `[[prefer(frame_ram_bytes,quest_local_frame_bytes)]]`
with an allowance of 88. The existing solver selects only `vx_password_decode`
as `static-exclusive`: its graph is closed, nonrecursive and has no overlapping
activation owners. The source still computes and publishes fresh results on
every call. The adapter copies the result before effects such as weapon
initialization can enter other engine code. No C adapter or language-backend
change is needed for this allocation choice.

The generated decoder now reserves 12 stack bytes, with the other 88 in fixed
RAM. Production globals rise from 3,827 to 3,915 bytes, leaving 181 bytes before
the map buffer; occupied ROM falls from 455,925 to 455,590 bytes. The cartridge
remains 458,752 bytes and resident ROM ends at `0x5E65`. The encounter retains
its 111-byte observed stack peak and identical crowd/combat timings.

The full SDL/MSX smoke scenario falls from 285 to 242 additional stack bytes
(15.1%). All 67 dialogue captures agree, all 24 exits restore the map, and the
C reference remains at 240 bytes. The new deepest PC is `0xA26B` inside
`printf_`'s `_out_rev`, reached from the existing tile diagnostic in
`wolfi_triggers.c`. It is a C engine formatting path, not a Vexel temporary
frame. The diagnostic remains enabled, so this comparison retains that work.

An emulator entry/return probe compares the same seven decoder calls in the
saved and current smoke ROMs. Their mean duration falls from 27.296 to 26.575
ms (2.6%); the maximum falls from 31.412 to 30.655 ms. Additional stack writes
within these calls fall from 160 to 72 bytes. Timings include any intervening
ISR and describe these inputs, not a universal speedup. The larger scenario's
elapsed time is effectively unchanged because it includes display/input waits.

Host password vectors and integration checks, production Linux/MSX builds,
the real encounter, complete SDL/MSX smoke run and generated-file checks pass.
Reference executables/ROMs and encounter behavior, stack use and timings remain
unchanged. `build/smoke-stack/comparison.json` records before/after results,
both storage plans and solver/manifest/plan/executable/ROM hashes. That directory
retains the archived listings, raw stack snapshots and the paired timing probe.

### Melee rules and deferred weapon sprites

`gameplay/melee.vx` owns paw, claw, sword, axe and butter-knife damage,
palette selection, hit rectangle size/position, axe target/cut eligibility,
and the twenty-tick swing's position, frame and lifetime. Five named bindings
join the existing disjoint-lifetime group. All seventeen selected bindings
share one 35-byte workspace, three bytes larger than before. Their separate
sizes total 223 bytes; the ordinary password-local allocation remains 88.
The C adapter retains entity storage, collision calls, map writes and drawing.
The original C implementation remains under `GAMEPLAY=reference` on both targets.

The old update loop applies each elapsed tick, but intermediate positions and
frames have no effects or observers. The Vexel rule computes the final tick
once. Zero elapsed ticks leave the pending frame untouched; the twentieth tick
updates the entity/frame and expires before copying the sprite position, just
as the original callback does. Position arithmetic wraps at sixteen bits.
Already-expired counters return inactive without a table access; the legacy
engine only calls live swings with counters zero through nineteen.

Effects delimit the shared workspace's lifetime. The axe adapter copies its
target coordinates before querying or writing the map, then takes fresh player
position inputs for hit detection after those effects. Hit dimensions are
consumed before entering collision callbacks. The host differential test
deliberately reuses the shared workspace and moves the player inside the map
query, checking both retained coordinates and the refreshed hit snapshot.

`gameplay/melee_assets.vx` adds twelve small and twelve large frames to the
existing resource family declarations. Handles 23–34 select small frames and
35–46 select large frames in this build. Gameplay publishes a logical handle;
the renderer resolves the linked bank/address at consumption and restores the
previous mapping. Spawn/despawn clear pending requests and legacy pointers
before slot reuse. This also avoids retaining an earlier weapon's frame when
the first update has no elapsed ticks. Weapon color overrides are preserved.

The host tests compare actual C/Vexel adapters, including axe cuts, clipped
redraws, callback effects, moving-player inputs, delayed frames and expiration.
After the timed encounter, the real MSX callbacks are checked for all five
weapons, five orientation values, live counters and zero/single/batched elapsed
ticks. Independent legacy offset/frame tables check the results. All 46 resource
frames are also uploaded after their asset bank has been paged out; VRAM patterns,
colors and restored banks match the linked cartridge.

An emulator entry/return probe of those callbacks gives the following means.
Each row covers the same 500 weapon/orientation/counter combinations per variant:

| Elapsed input | C callback | Vexel callback |
| --- | ---: | ---: |
| 0 ticks | 0.512 ms | 0.442 ms |
| 1 tick | 0.972 ms | 1.088 ms |
| 2 ticks | 1.408 ms | 1.088 ms |
| 255 ticks, clamped at expiration | 5.230 ms | 1.046 ms |

The single-tick path is about 12% slower; batching two ticks saves about 23%.
The large-batch row averages differing remaining lifetimes, not 255 executed
ticks. Observed additional stack within the callback falls from 25 to 19 bytes.
These measurements exclude renderer work and are not whole-program stack bounds
or a universal speedup. The Vexel encounter retains its 111-byte stack peak and
16.461 ms crowd update work. Mean combat update work falls from 17.996 to
17.898 ms; the C reference encounter is unchanged.

Production occupied ROM rises from 455,590 to 455,949 bytes and globals from
3,915 to 3,918, leaving 178 bytes before the map at `0xD000`. The cartridge
remains 458,752 bytes, with resident ROM ending at `0x5E65`. No additional
engine state or manually static adapter locals are introduced. Before/after
reports, selected storage plans, callback timing probes and artifact hashes
are retained in `build/melee/comparison.json` and its directory.

Host differential/resource tests, production Linux/MSX builds, SDL/MSX
encounters and the complete dialogue/world smoke run pass. All 67 dialogue
captures agree and all 24 building exits restore both map buffers. The broader
smoke stack peak remains 242 bytes (240 for C). The C production/smoke ROMs
and the Vexel solver executable are byte-for-byte unchanged. This slice uses
the existing solver and storage planner without a weapon-specific backend rule.

### Arrows, fire and bomb effect boundaries

`gameplay/projectiles.vx` now owns arrow/fire/bomb launch position and damage,
arrow/fire velocities and movement, and fire animation. Arrow and fire motion
is a fixed-width velocity-times-elapsed calculation. The Vexel
`projectile_distance` helper exposes addition/shift fast paths for zero through
three ticks, while retaining multiplication for the full elapsed-byte domain. Velocity is widened before
multiplication, positions wrap at sixteen bits, and fire's counter wraps at
eight bits. Zero elapsed ticks retain pending animation requests. The fire
adapter preserves the original spawn sprite position until the first update.
The original callbacks remain available in the C reference.

`gameplay/bomb.vx` advances the fuse, blinking color, explosion frames and
sprite offsets, and decides which observed tile kinds can be destroyed.
Its result is a small state patch plus the number of consumed ticks and a map
query request. Before tick 186 it can combine a pure stretch into one step.
Ticks 186–189 each stop at their own query: the adapter publishes the frame,
performs the query and any map writes/redraws, then advances the counter and
resumes. Four elapsed detonation ticks still issue four ordered queries;
later queries observe any changes made by earlier ones. This preserves the
existing behavior instead of assuming map queries are interchangeable.

After tick 189, the remaining sprite motion can again be calculated directly.
A batch crossing a frame or color interval retains that interval's last write,
even if the final tick only changes sprite position. Processing tick 221 leaves
a live entity with counter 222; attempting tick 222 expires it without another
increment. This distinction is observable when a batch ends exactly there.
At most seven rule invocations are needed for one valid full-duration update,
including all four map queries and expiration. Ordinary gameplay currently
supplies at most three elapsed ticks; the existing scheduler's larger-delay
clamp remains unchanged.

All result fields are consumed before engine callbacks reuse the shared
workspace. The adapter retains only the resume counter and remaining duration
across effects. Position reads after a map query/write are refreshed as in the
original C. The host differential test deliberately consumes pending sprite
requests, changes position and invokes another binding inside callbacks. It
compares event order and state against the independent C loop, including zero
elapsed time, phase boundaries, wrapping positions and large batches.

Four additional bindings bring the total to twenty-one. Their frames are
2 bytes (`bomb_cut`), 21 (`bomb_step`), 25 (`projectile_move`) and 24
(`projectile_spawn`), so all still fit the existing 35-byte union. This is a
source-level transition rule using the existing solver and binding machinery.
The game embedding now supplies the portable Vexel `vx_mul` runtime operation
in resident ROM; generated code can call it while any weapon bank is mapped.

`projectile_assets.vx` adds four arrow, four fire and four bomb frames, for
58 handles across seven families. Delayed uploads resolve the physical bank
and address only when the renderer consumes a handle. Spawn/despawn clear
requests and raw pointers before slot reuse. The target checks exercise the
actual projectile callbacks and uncover a real covered mountain doorway with
a bomb update crossing detonation. Resource validation includes every linked
frame with its asset bank initially absent.

The target run also found a compiler error that the host could not reveal:
SDCC forwarded a selected byte operand incorrectly in `counter + spent`.
The generated C was correct, but the Z80 code added `spent` to itself. The
solver's general pure-value emitter now protects this case with an isolated
byte-add function when it reuses a computed operand. The independent `advance`
oracle checks the fix in automatic/fixed storage, and the real bomb callback
checks it in the game's build. See the parent project's
[SDCC operand notes](../../../docs/sdcc-operands.md). This is a general emission
fix; the bomb arithmetic remains in Vexel.

An emulator probe measures actual callback entry through return for the same
orientation/counter inputs. Mean elapsed times in milliseconds are:

| Callback | C, 1 tick | Vexel, 1 tick | C, 2 ticks | Vexel, 2 ticks | C, 3 ticks | Vexel, 3 ticks |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| Arrow | 0.538 | 0.730 | 0.819 | 0.741 | 1.101 | 0.815 |
| Fire | 0.597 | 0.824 | 0.915 | 0.835 | 1.234 | 0.908 |

Single-tick motion is 36–38% slower; two ticks save about 9%, and three save
about 26%. Zero-tick calls are also slower (arrow 0.257→0.695 ms, fire
0.278→0.731 ms). The original general-multiplication projection was slower
still: the Vexel fast paths cut single-tick times from 1.258/1.350 ms to the
values above. This is a measured tradeoff, not a general speedup claim.
Observed callback stack for normal zero-to-three-tick updates is 21 bytes for
arrow and 23 for fire, versus C maxima of 15/16; the multiplication fallback
reaches 33/35 bytes. Their selected value buffers remain in the shared RAM slot.

Across the bomb phase-boundary cases, mean callback time is 1.182→1.117 ms
for one tick and 1.733→1.571 ms for three ticks. The observed maximum callback
stack falls from 82 to 41 bytes, including map effects. Some individual
boundary crossings are slower; these means cover the specified test inputs.
The large-batch tests cover the complete interface, while normal gameplay's
elapsed limit remains three. Timings exclude later sprite uploads and are
workload observations rather than whole-program stack or speed bounds.

Production occupied ROM grows from 455,949 to 458,977 bytes (+3,028), and the
image from 458,752 to 466,944 bytes (one additional 8 KiB bank). Resident ROM
ends at `0x5EE5`. Global RAM remains 3,918 bytes, leaving the same 178 bytes
before the map buffer; the ordinary-local fixed allowance remains 88 bytes.
The encounter retains its 111-byte additional stack peak. Crowd update work
is unchanged at 16.461 ms; combat update work rises from 17.898 to 17.987 ms
(about 0.5%) because the general operand fix also protects an existing melee
calculation. The timed encounter covers the existing enemies and melee;
the separate callback probes above measure the new weapon paths.

Host differential/resource tests, both production builds, the SDL/MSX
encounter and all 58 frame uploads pass. The full dialogue/world smoke matches
all 67 captures and restores both map buffers at all 24 building exits. Its
observed stack peak remains 242 bytes (240 for C). The parent solver suite,
host/Z80 value projection regressions and generated-file freshness check also
pass. The C production and smoke ROMs are byte-for-byte unchanged; the solver
executable changes with the operand fix. Measurements, source/artifact hashes,
callback probes and archived ROMs/listings are in
`build/projectiles/comparison.json` and its directory.

This migration preserves the original movement-only arrow/fire callbacks.
Adding projectile impacts, wall collision or new lifetime rules is a separate
gameplay change. The engine's drawing, collision services and assembly remain
the physical implementation of requested effects.

### Effects, ball patrol and normal player controls

`gameplay/effects.vx` defines the shared spark/explosion timeline. It returns
only the final counter, last frame write and lifetime status for an elapsed
interval. Arriving at counter 24 is distinct from trying to execute tick 24;
zero elapsed ticks preserve pending requests, and byte wrap retains the legacy
behavior even for an initially out-of-range counter. Spark color variants use
a separate pure frame-selection rule. The adapters publish the last requested
frame, without replaying invisible intermediate uploads.

`gameplay/ball.vx` owns the ball enemy's alternating-update gate, wait counter,
facing frame, horizontal patrol, obstacle response and return toward its anchor.
The two horizontal legs are deliberately ordered. A left leg can turn right and
execute a right leg during the same callback; changing the second `if` into an
`else` would change the game. Each leg publishes its tentative state before the
map query. Its reply uses fresh entity state after that query, and rejection
restores the original position. Host tests reuse the shared binding workspace
and change position inside callbacks to check this lifetime boundary.

`gameplay/player.vx` owns keyboard normalization, ownership-based weapon cycling,
attack-slot selection, the two-out-of-three movement cadence, proposed movement,
corner-slide decisions, facing/animation and camera targets. The C adapter still
performs elapsed-tick/substep iteration and engine effects. It switches weapons
and attacks before moving, retains the two collision substeps per active tick,
and tries horizontal then vertical sliding after a blocked diagonal query.
It preserves query order, copies continuation coordinates before effects, and
reads live state again after each query. A hit still gates input through the
existing combat service. Scripted opening/death scenes and door transitions
remain engine code.

Two old edge cases are corrected in both the reference and Vexel variants:
no movement query means no stale trigger observation, and cycling an empty
weapon inventory terminates with the current selection. Unsupported weapon IDs
cannot spawn an attack. Ball anchor comparisons explicitly wrap at sixteen bits,
so host integer promotion no longer changes behavior at the coordinate boundary.

`gameplay/actor_assets.vx` adds twelve spark, four explosion, four ball and ten
player frames. There are now 88 handles in eleven families. All player sprite
publishers—including the scripted intro, triggers and door transitions—replace
the same pending handle; a transition cannot leave an old gameplay request that
later overrides its animation. The renderer and optimized assembly remain the
physical upload implementation. Spawn/despawn clear migrated requests before
slot reuse.

The fourteen new bindings bring the total to 35, still overlaid in the existing
35-byte workspace. No new compiler feature or scheduler was needed. Ordinary
continuation values remain automatic when they must survive engine callbacks;
the source disjointness contract never treats those values as dead. The old
player controller's five manually static scratch bytes are removed. The
password decoder retains its separate 88-byte fixed allowance.

Measurements distinguish source reuse from execution speed. The shared effect
timeline is faster for one-to-three elapsed ticks and uses less callback stack.
Ball/player callbacks are currently slower than the C reference because their
observable map queries remain, with binding publication and result copies around
them. An experiment selecting only the active/blocked ball branches saved one
stack byte but increased mean callback time (2.416 to 2.435 ms on the test matrix).
The final implementation keeps the simpler full bindings. Both measurements
are retained in `build/actors`; branch specialization is not assumed to be a win.

The direct Z80 callback probe reports these mean times (milliseconds). Effect
rows cover phase boundaries, wrapping counters and all spark variants. Player
rows cover the sixteen direction-key combinations and all three cadence states;
ball covers directions, wait states and both sides of its anchor.

| Callback | C, 1 tick | Vexel, 1 tick | C, 2 ticks | Vexel, 2 ticks | C, 3 ticks | Vexel, 3 ticks | C / Vexel observed stack |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| Spark | 0.400 | 0.334 | 0.538 | 0.361 | 0.648 | 0.361 | 23 / 14 bytes |
| Explosion | 0.325 | 0.317 | 0.457 | 0.326 | 0.568 | 0.326 | 15 / 13 bytes |
| Player controls | 1.342 | 1.869 | 2.194 | 3.212 | 3.046 | 4.555 | 21 / 28 bytes |

The ball advances on its game-cycle gate rather than elapsed ticks: its matrix
averages 1.824 ms in C and 2.416 ms in Vexel, with observed callback stack of
57 and 74 bytes. Thus the effects gain speed and stack space, while ball/player
movement currently pays overhead. The player measurement includes map effects
but excludes the combat gate, view/infobar update and later sprite uploads.
Zero-tick effects are slower (spark 0.251→0.319 ms, explosion 0.177→0.311 ms).
These figures are workload measurements, not whole-program bounds or universal
speedups. The large elapsed-byte cases test the interface; ordinary gameplay
still clamps its elapsed count to at most three.

Production occupied ROM rises from 458,977 to 463,785 bytes (+4,808), while the
image remains 466,944 bytes. Resident ROM still ends at `0x5EE5`. Global RAM
falls from 3,918 to 3,913 bytes, leaving 183 bytes before the map at `0xD000`.
The revised C reference uses 428,499 occupied ROM bytes, a 434,176-byte image,
and 3,769 RAM bytes. Both variants include the explicit gameplay edge-case
fixes, so the reference artifacts intentionally change.

Host differential tests compare the actual adapters, including simultaneous
keys, wrap boundaries, waiting, nested workspace reuse, corner slides and effect
order. Ownership selection and free attack slots have independent checks.
The encounter adds a shared-timeline oracle, ball/player matrices against the
real map, and target checks for ownership/slot decisions. All 88 sprite frames
are uploaded with their resource bank initially absent. These test drivers are
excluded from production; additional policy checks occupy a separate test bank.

The final host UBSan suite, Linux/MSX production builds, SDL/MSX encounter and
generated-file freshness checks pass. The complete dialogue/world smoke matches
all 67 captures and restores both map buffers at all 24 exits. Its observed
stack peak remains 242 bytes (240 for C); the encounter remains at 111 bytes
for both variants. These broader peaks do not negate the increased stack in
the individual ball/player callbacks above. The solver executable is unchanged.
Final measurements, storage plans, source/artifact hashes, smoke captures and
editable SDCC listing/ROM snapshots are retained in `build/actors/comparison.json`
and its directory.

This is a working route for moving decisions into Vexel while retaining the
engine and both targets. It provides a concrete resource-lifetime boundary
where banked text can no longer escape into gameplay as a raw address.

Scripted opening/death sequences, door/well/hole transition timing, and world
update/spawn orchestration remain C. Fairy motion, lumberjack following
animation and pickup lifetime/visibility now have Vexel policies (see below).
Relevant state and small typed results now cover choice-dependent inventory
effects, multi-stage offers, world travel, well progression and explicit
randomness with the same adapter and owned text storage.
Suspending scenes across ordinary gameplay
frames would still require an explicit continuation design.
Asset IDs do not yet cover all sprite/audio/map consumers, and the legacy
engine's other pointer lifetimes remain its responsibility.

NEO-8 and the newer megalinker are separate backend work: the current renderer
contains mapper register writes and layout assumptions specific to Konami-5.
This first comparison intentionally retains those assumptions. There is no
RAM mapper, new heap, LLM optimization loop, or general engine scheduler added
by this slice.

The project accepts ROM growth up to approximately 16 MB with a future mapper.
RAM, stack use, bank safety and execution speed take priority over cartridge
size. Current bank-size checks remain necessary for the Konami-5 layout.

### Stack costs in the generated C

The next pass changes the Vexel C generator, with no edits to gameplay rules,
engine adapters, RAM allowances or SDCC flags. Fixed Vexel fields were already
in RAM, but SDCC still spilled intermediate words and predicates onto its stack.
The generator now selects paths before evaluating wide stores, uses byte
transfers/equality for stable wide fields, and simplifies wide control
predicates. Branch expansion is bounded. Byte-only predicates retain their
previous emission, since rewriting them increased stack use in the combat path.
The existing volatile operands and computation call boundary remain necessary.

Measured callback costs before and after this compiler pass:

| Callback matrix | Before, mean ms | After, mean ms | Observed stack, before → after |
| --- | ---: | ---: | ---: |
| Player, one tick | 1.869 | 1.854 | 28 → 26 bytes |
| Player, two ticks | 3.212 | 3.181 | 28 → 26 bytes |
| Player, three ticks | 4.555 | 4.509 | 28 → 26 bytes |
| Ball, cycle-gated | 2.416 | 2.402 | 74 → 74 bytes |
| Spark, one tick | 0.334 | 0.334 | 14 → 14 bytes |
| Explosion, one tick | 0.317 | 0.317 | 13 → 13 bytes |

The generated player slide helper itself falls from six to three additional
stack bytes; other calls limit the complete controller's saving to two bytes.
Player and ball still cost more than their hand-written C reference. Removing
SDCC's frame pointer saved additional bytes but slowed the moving-player matrix
by about 25%, so that option was rejected. There is no blanket static-local or
register-preservation annotation.

Production occupied ROM is 463,804 bytes (+19), image size 466,944 bytes, and
global RAM remains 3,913 bytes with the same 35-byte binding workspace and
183-byte gap before the map. These callback measurements include nested calls
but exclude the entry return address and surrounding engine frames; they are
not worst-case bounds. Packaged Vexel MSX projects now also report each emitted
C binding helper's assembly stack analysis, separately from its RAM frame and
the ordinary source-entry stack proof.

After `make encounter`, `python3 -B tests/profile_actor_callbacks.py` repeats
the callback matrices on openMSX and writes samples, stack measurements and ROM
hashes into `build/callbacks`. This pass's before/after data, listings and broader
validation results are retained in `build/stack-aware`.

## Movement execution regions and measured selection

`gameplay/player_motion.vx` describes one complete movement occurrence. It owns
keyboard normalization, tick cadence, both movement steps, diagonal/horizontal/
vertical map attempts, and the final orientation/animation decision. The map
sink receives the pending player state and returns a fresh snapshot after the
engine query. A query may change position, keys, elapsed ticks, skip cadence,
animation or facing; the continuation consumes those new values. The final
query's flags determine whether to dispatch a trigger, and no-query updates
cannot reuse a previous invocation's flags.

The engine adapter in `src/gameplay/player_motion.c` publishes the pending
state, performs map queries, and publishes the final result. Weapon spawning
remains before the movement occurrence; sprite and trigger effects follow its
computation. There are no movement loops or slide decisions in that adapter.
Its private `Entity *` is an engine context pointing into RAM, not a Vexel
pointer or a pointer into a mapped asset bank.

With `PLAYER_REGION_BANKED=1`, the region uses a separate page-D code module.
Its page-C caller maps and restores that module around the operation. With
`PLAYER_REGION_BANKED=0`, it shares the player's page-C module; the optimized
region now fits there. The existing page-B map-query
assembly temporarily remaps C/D for flags and restores both from the mapper
shadow before returning. Live region state stays in RAM throughout. The
original optimized map assembly is unchanged.

The `region` C binding contract covers the complete input-through-result
interval, including map callbacks. The movement frame is deliberately excluded
from the other bindings' `c_disjoint` group: tests invoke a skeleton binding
inside a map query while movement remains live. An exclusive occurrence cannot
reenter itself. The generic backend also supports automatic frames; its Z80
tests exercise recursive callbacks with an `open` region contract.

The first scheduled movement frame required 88 Z80 bytes including input,
output, boundary buffers and scratch; the control-flow pass below reduces this
to 56 bytes. The other bindings share 35 bytes. Readiness invariants and
liveness first reduced the initial 106-byte region frame. Parallel
transfers save old values when copies form a cycle, and expression scratch is
reused between transfers. Small generated transfer helpers bound SDCC's
allocation search. They use the same owned frame and their actual call costs
are included in measurements.

`PLAYER_REGION=0` builds the earlier C-controlled binding chain;
`PLAYER_REGION=1` builds the complete region. Use separate `BUILD_ROOT` values
when comparing compile options. `GENERATED` selects an independent generated
project directory. `make optimize-player` performs a bounded comparison of
the chain, the scheduled region, and buffered region transfers. Each new
candidate gets isolated generated files and an editable SDL/SDCC build. Host
UBSan traces and SDL/MSX encounters must pass before callback timing and stack
samples can select it. The search retains its baseline on failures, budget
violations or measured regressions; it never rewrites the working project.
`build/player-optimization/latest.json` points to the completed report and
selected project. `commands.json`, compiler/ROM hashes and test output retain
the evidence. A previous baseline may be reused explicitly with
`--baseline-report`; artifact hashes, reference ROM and player traces are
checked before accepting it.

These measurements are scenario samples, not whole-program stack or timing
bounds. The region is also not a promise that every larger fused graph is
faster: bank placement, SDCC compilation cost, callback state publication,
fixed RAM and actual Z80 execution all participate in the decision.

The measured search retained the binding chain. Callback means, over the same
direction/cadence matrix on MSX1, were:

| Realization | 1 elapsed tick | 2 elapsed ticks | 3 elapsed ticks | Maximum additional callback stack |
| --- | ---: | ---: | ---: | ---: |
| Binding chain | 1.854 ms | 3.181 ms | 4.509 ms | 26 bytes |
| Scheduled region | 3.420 ms | 5.575 ms | 7.729 ms | 39 bytes |
| Buffered region | 3.535 ms | 5.744 ms | 7.954 ms | 39 bytes |

Both region variants passed behavior and mapper checks. The buffered frame
also displaced two other bindings from fixed storage under the 128-byte
allowance; its broader encounter stack increased from 111 to 125 bytes. The
selector now guards all measured actor groups and the encounter, not just
the player. Reports are in
`build/player-optimization/run-fc5fmcwm/selection-reviewed.json`.

The shipping default is therefore `PLAYER_REGION=0`. `make generate` supplies
a 35-byte binding allowance in this mode, so the unused region reserves no
fixed RAM. With `PLAYER_REGION=1`, generation defaults to 128 bytes. The region
remains an explicit experiment; reproducing it does not replace the default:

```sh
make PLAYER_REGION=1 GENERATED=build/region/generated BUILD_ROOT=build/region generate
make -j2 PLAYER_REGION=1 GENERATED=build/region/generated BUILD_ROOT=build/region all
```

The first experiment exposed a control-flow state-placement problem: nested loop
snapshots and boundary publication still move too many bytes, and the adapter,
bank switch and transfer helpers deepen the call chain. A fixed-RAM frame by
itself does not solve those costs. The new region and measurement loop make
that problem concrete without imposing its regression on normal gameplay.

Final validation retained the default build's 3,913-byte global RAM footprint,
463,804 occupied ROM bytes and 26-byte player-callback stack measurement.
Compiler region tests passed on host UBSan and the Z80 simulator, including
parallel-copy cycles, nested loops, conditional initialization, automatic
recursive callbacks and overlap rejection. Game host integration, linker and
resource checks passed; the default SDL/MSX encounter retained its 111-byte
observed stack peak. The explicit region also passed the full SDL/MSX dialogue
and world smoke test, including all 24 map exits and bank restoration. That
broader scenario observed 242 stack bytes for Vexel and 240 for C. The final
compiler emits byte-identical scheduled region headers to the measured
candidate. Logs and final artifacts are in `build/region-opt`.

### Control-flow optimization and placement in the player's bank

The movement source is unchanged. Vexel now constructs a control-flow graph
for the region, canonicalizes predicates, propagates branch facts, removes
dead transfers and redirects edges past decisions they already know. Common
conditional transfers decide their path before writing state. Analysis repeats
after unreachable edges and identity stores disappear. This is necessary for
nested loops: an outer decision may still need the old value even when an
inner loop has produced a replacement.

Liveness and an interference graph allow internal loop fields to reuse input,
result or boundary cells once the former contents are dead. Parallel-copy
cycles still save the old contents. The movement frame coalesces 30 bytes of
loop storage and needs no additional zero-initialization at entry. Its final
size is 52 bytes of state plus four bytes of expression/predicate scratch.
Large shared predicates use that scratch rather than duplicating volatile
expressions and spilling registers on the Z80 stack.

The C adapter now separates publication, region execution and consumption.
This prevents SDCC from retaining eight bytes of entity-field addresses across
execution. Results remain in the owned region frame across sprite calls. The
same adapter supports automatic frames when fixed storage is unavailable.
`src/gameplay/player_motion.inc` supplies either the separate module or the
player's own module; the latter measures 7,641 bytes in the encounter build,
within its 8 KiB bank. The optimized map assembly remains unchanged.

Measured callback means on the same MSX1 direction/cadence matrix:

| Realization | 0 elapsed ticks | 1 tick | 2 ticks | 3 ticks | Peak additional callback stack |
| --- | ---: | ---: | ---: | ---: | ---: |
| Existing binding chain | 0.527 ms | 1.854 ms | 3.181 ms | 4.509 ms | 26 bytes |
| Previous scheduled region | 1.266 ms | 3.420 ms | 5.575 ms | 7.729 ms | 39 bytes |
| Optimized region, same bank | 0.839 ms | 2.079 ms | 3.319 ms | 4.561 ms | 17 bytes |

The region uses 56% less sampled stack and runs 39–41% faster for moving
updates than the previous region. Compared with the binding chain, it saves
nine stack bytes but remains slower, particularly with zero or one elapsed
tick. The existing no-regression selection policy therefore retains
`PLAYER_REGION=0`; no timing threshold was relaxed. Other actor callback
measurements are unchanged. The wider encounter still peaks at 111 stack
bytes. Its region build occupies 474,616 ROM bytes and 4,016 global RAM bytes:
the region adds 58 RAM bytes over the production binding chain, including the
two-byte engine context.

To inspect the lower-stack alternative:

```sh
make PLAYER_REGION=1 PLAYER_REGION_BANKED=0 GENERATED=build/region/generated BUILD_ROOT=build/region generate
make -j2 PLAYER_REGION=1 PLAYER_REGION_BANKED=0 GENERATED=build/region/generated BUILD_ROOT=build/region all
```

`make optimize-player` now considers four candidates: the chain, a scheduled
region in the player's bank, a scheduled region in its own bank, and buffered
transfers in the player's bank. An overflowing code bank rejects a candidate.
The completed comparison for this pass is `build/region-flow/selection.json`;
the final generated code, ROMs, host traces, encounter and callback reports are
under `build/region-flow/cse-generated` and `build/region-flow/cse`. The retained
historical baseline in that selection report reserves an unused region frame;
production still reserves only the chain's 35-byte workspace.

Regression coverage includes changing guards across nested loops, loop-condition
updates, `break`, `continue`, copy cycles, callback mutations, recursive open
regions and fixed/automatic storage. Host UBSan and independent Z80 region
oracles pass, as do game host traces and the SDL/MSX encounter. Remaining speed
work concerns interface publication/consumption and repeated boundary copies;
having a fixed frame alone does not remove those costs.

The optimized region also passes the full SDL/MSX dialogue and world smoke
test: all popup comparisons, 24 building exits and bank restorations agree.
That broader scenario still observes 242 stack bytes for Vexel versus 240 for
C; the 17-byte figure above belongs specifically to the player callback matrix.
Default host, linker and resource tests pass, and rebuilding the default game
produces the exact previous cartridge hash with 3,913 bytes of global RAM.

## Pickup, fairy and follower policies

`gameplay/drops.vx` now also owns sprite selection and the complete pickup
lifetime. `drop_step` collapses elapsed ticks to the final counter and visible
state. It preserves zero elapsed updates, including collection at counter 240;
arriving at 240 remains live, while attempting that tick expires before the
collision callback. Empty items do not query collision. A visibility value of
255 means no write; the blink phase retains the C engine's enum values 0 and 8.
The adapter consumes the entire result before invoking collision, so a callback
can reuse the shared binding workspace without overwriting a live continuation.

`gameplay/fairy.vx` owns the two halves' vertical displacement from the clock
and anchor. Its quarter-wave values reproduce every sample of the original
64-phase table, with explicit sixteen-bit wrapping at either coordinate edge.
The current pure binding projection cannot lower dynamic array indexing. A
balanced selection over seventeen quarter-wave samples expresses the same
motion using the supported value graph; reflection and sign produce the other
quarters. It needs no floating point, runtime array or foreign lookup callback.
This is a representation choice for this port, not a new language facility.

`gameplay/follower.vx` owns the lumberjack's animation while following. Left or
right movement changes his remembered facing; rest/up/down preserve it. An
unrecognized remembered facing produces no sprite write. Contact/quest effects
and follower registration remain in the adapter. The original C policy paths
remain available through `GAMEPLAY=reference`.

The four new exported policies (`drop_spawn`, `drop_step`, `fairy_move`,
`lumber_draw`) join the same serial program solve as the existing gameplay.
There are now 53 runtime roots and 310 compiler-image artifacts, with 320
inspectable generated C/header/fragment files including the engine embeddings.
Their fixed frames occupy 3, 10, 8 and 7 bytes respectively; all share the
existing 35-byte binding workspace under explicit disjoint lifetime contracts.
They introduce no additional binding RAM and do not place those frames on the
stack. Callback arguments and surrounding engine calls can still use stack.

Ten sprite handles are appended to the catalog: four pickup frames, two fairy
halves and four lumberjack frames, giving 98 handles in fourteen families.
Existing handles retain their numbers. Producers keep no sprite-data pointer;
the renderer resolves a handle with the asset bank mapped, consumes it once,
and restores the mapping. Spawn/despawn clear stale requests and addresses.
The final ROM verifier checks the added descriptors, symbols, windows and bounds.

Host UBSan checks exercise the real callbacks against the retained C paths,
including every fairy clock phase, coordinate wrap, pickup boundaries and
zero/large elapsed updates, follower facing, pending requests and despawn.
The full quest checks still cover the collision callback's reuse of the binding
workspace. The encounter adds Z80 callback checks for these actors and verifies
all 98 delayed sprite uploads against the linked ROM bytes with their asset
banks absent at publication. Reproduce the checks with:

```sh
make test
make -j2 encounter
python3 tests/profile_actor_callbacks.py --passive --report-dir passive-actors-callbacks
```

The first target encounter caught an SDCC 4.2.0 operand-forwarding error in
`elapsed < room`: both compared registers held the freshly stored `room`, so
the first pickup update advanced its counter directly to 240. The host passed
because the generated C expressed the intended comparison. Vexel's pure value
generator now isolates computed unsigned byte ordering through a small target
helper, extending the existing protection for computed byte addition. This
also protects the same expression family in other policies; the game source
does not encode a special workaround. The compiler's `clamp` regression checks
all four orderings and automatic/fixed bindings with the game's allocator cap.
The helper uses call storage, so it can add stack and execution time even though
the binding workspace remains unchanged. See the parent repository's
`docs/sdcc-operands.md` for the lowering and retained failure evidence.

The fairy check also caught SDCC replacing the anchor's high byte with its
computed height: anchor zero plus twelve became `0x0c0c`. Computed word addition
now has the same publication barrier, including when the displacement is
negated. The compiler's small `compose` oracle covers both signs and wrapping;
the game's historical-wave oracle checks every fairy phase. Automatic binding
pointers also retain stable storage after a separate destination-address
miscompile was reproduced in the compiler's Z80 harness.

The callback profile compares actual C and Vexel implementations. It reports
scenario timing and observed additional stack, not worst-case bounds or a
claim that every port is faster. Scripted scenes, transition timing and world
update/spawn orchestration remain the next substantial gameplay layer.

Measured on the final MSX1 encounter ROMs, with the existing C implementation
as reference (microseconds per callback; stack is the largest additional
depth observed after callback entry):

| Callback / elapsed ticks | C mean µs | Vexel mean µs | Stack bytes C → Vexel |
| --- | ---: | ---: | ---: |
| Pickup / 0 | 447.5 | 651.2 | 22 → 16 |
| Pickup / 1 | 480.8 | 647.5 | 22 → 16 |
| Pickup / 2 | 524.2 | 627.1 | 22 → 16 |
| Pickup / 3 | 584.9 | 627.1 | 22 → 16 |
| Pickup / 255 | 8,280.7 | 477.6 | 13 → 16 |
| Fairy / all phases | 317.9 | 576.4 | 12 → 30 |
| Following lumberjack | 390.2 | 301.7 | 14 → 7 |

Following animation is about 23% faster and halves its measured stack. Pickup
updates reduce normal callback stack, but the one-tick case is about 35% slower;
collapsing a large elapsed batch is much faster. The game normally clamps elapsed
ticks to three, so the 255-tick result is an interface stress case. Fairy motion
costs about 81% more time and increases stack: its branch selection and arithmetic
barriers are currently more expensive than the C lookup table. Native constant
table lookup in pure bindings is a concrete next optimization opportunity.
These samples include boundary/invalid-facing cases and exclude later renderer
work; they are neither whole-game speedups nor worst-case stack proofs.

The final production image is 475,136 bytes with 466,672 occupied bytes. Its
resident ROM ends at `0x5F16`; all linked ROM sections fit their 8 KiB windows.
Global RAM remains 3,909 bytes, ending at `0xCF45` before the map at `0xD000`.
The complete SDL/MSX quest/world smoke matches all 67 captures and all 24 exit
restorations. Its measured stack remains 242 bytes versus 240 for C; the mixed
encounter remains 111 bytes for both implementations. All 98 delayed sprite
uploads match their linked ROM bytes with the asset bank initially absent.

The compiler value/binding Z80 suite and execution-region oracle pass. All
55 source examples retain their expected outcomes (54 resolved, one known open
type-equation example). Bounding the new dependency walk preserves all 885
generated example code files and all 99 code files in the compared value
fixtures byte for byte. Whole-game generation takes about 3m29s and peaks at
3.05 GiB RSS on this host; that is the Vexel solve, separate from the serialized
SDCC processes, which retain the 2 GiB address-space and 180-second limits.
Detailed evidence is in `build/passive-actors/validation.json`,
`build/passive-actors-callbacks/passive-callback-timing.json`,
`build/encounter/results.json` and `build/passive-actors-smoke/results.json`.


## Scripted scenes and world orchestration

The whole-game solve now includes `gameplay/scenes.vx` and
`gameplay/orchestration.vx`. They own the intro phase machine, repeated spark
choreography, fairy briefing order and quest-marker publication, death/reveal
wipes, revival health rule, door animation and signed warp-camera policy.
The world source also owns the initial actor population, frame cadence,
retention/spawn windows, camera scroll decisions and follower-trail sampling.

A scene publishes one command and a continuation. C copies the continuation
and consumes the result before calling an engine sink. Messages, waits, draws
and immediate spawn callbacks can therefore reuse the 35-byte binding workspace.
The intro's `again` result explicitly preserves transitions that execute several
phases in one active tick. This is different from advancing once per frame.
The reference intro remains in `intro_reference.inc` for differential checking.

`world_orchestration.c` is an engine adapter in a separate page-C bank. Moving
this work out of the resident bank preserves room for permanent mapper/dispatch
code. A resident dispatcher temporarily maps an actor into page C, then restores
the caller before returning and restores the actor's page-D data mapping.
Startup actor dispatch is also resident. The
legacy map renderer restores C but clobbers D; this explicit bank effect rules
out page D as a safe continuation bank for these operations.
The software ISR can run during an engine yield because no shared binding is
live then. Ordinary player tracking retains byte-wrapped camera distances;
warp migration uses signed distances, as the original game does.

The retention and spawn bindings select certified cases of the same Vexel
window rule. Retention only needs the outer band, while spawning also excludes
the visible rectangle. `case0` denotes a false branch and `case1` a true branch;
they are selected from the generated branch contract, not textual branch order.
All new bindings use exclusive fixed frames in the existing shared slot.

Engine primitives remain C/assembly: slot bookkeeping, callback iteration,
mapper changes, VRAM operations, dialogue rendering and waits. The title-screen
presentation and six-phase VRAM transfer scheduler also remain engine code.
This migration does not introduce a new concurrency model or hand-written
replacement for the generated policies.

`make test` compares actual adapters against the C reference with UBSan,
including an engine sink that overwrites the shared binding slot. The scene
oracle checks the complete intro, elapsed batches, all montage event times,
map clipping and death; the world oracle checks startup order, clock wrap,
callback-driven despawns, camera boundaries, trail wrap and radial reveal.
The existing smoke and encounter tests still cover town exits and ordinary play.

For the full intro/death scenario, build both `SMOKE=1` variants and run
`python3 tests/check_scenes.py`. The same executable runs the normal smoke by
default; `EDW_SCENES=1` selects the scene scenario on Linux. The MSX script
selects that scenario through a debugger flag. It records mapper checks,
per-update player-state hashes, scene stack high-water and callback timings.
Its deliberately controlled single-tick intro has 799 updates. Measured costs
are scenario observations, not whole-program stack or execution-time bounds.


### Measured optimization check

The migration adds twelve runtime roots to the existing program: 65 roots
from 30 Vexel files are resolved together. There are 53 typed binding requests;
52 share the 35-byte fixed slot, while the optional player motion region keeps
its separate automatic realization. The new policies do not enlarge that slot.

The first scene projection issued a montage command on every active montage
tick. The revised Vexel rule emits it only at the finite spark event times.
The C dispatcher is unchanged. In the controlled MSX1 intro, median callback
time fell from 2,020.648 to 1,375.314 microseconds (32%), with the same 799-update
state hash and identical five large/three small dialogue pattern captures.
This costs 671 additional code bytes in the smoke build's player module
(7,033 to 7,704 bytes), still within its 8 KiB window. The C reference's median
is 909.613 microseconds: this is an improvement to the Vexel projection, not a
claim that every migrated policy is faster than C. Whole-scene means include
blocking dialogue/ISR waits and should not be treated as pure computation cost.
The event set is explicit because the pure value projection currently supports
remainder by powers of two; this port does not add a new division primitive.

The initial combined player/test-driver module exceeded 8 KiB after this
optimization. The encounter matrix driver now lives in the existing test bank
and calls the actual player implementation through a small resident trampoline.
No size guard was relaxed and the production player logic is still exercised.
`profile_actor_callbacks.py` follows the driver's new bank when enabling its
player measurements.

The new resident callback dispatcher restores both the execution bank and the
caller's page-D mapping. Compared with the pre-migration Vexel encounter, the
measured crowd body changed from 16.834 to 17.043 ms, and combat body from 18.431
to 18.738 ms. Observed encounter stack rose from 111 to 126 bytes in both C and
Vexel after moving orchestration out of resident code. Normal dialogue smoke
remains 242 bytes for Vexel and 240 for C. The full intro/death scenario reaches
594 bytes in both variants, including the legacy dialogue/rendering engine;
this cold-path peak is not the ordinary update cost. These are scenario
high-water observations, not exhaustive stack bounds.

Evidence is written to `build/scenes/results.json`, `build/encounter/results.json`,
`build/scene-world-smoke-final/results.json` and the aggregate
`build/scene-world/validation.json`. SDCC remains serialized with a 2 GiB
address-space cap, a 180-second limit and 2,000 allocator attempts per node.
The standalone C++ solve is unchanged by this migration.


The final production Vexel image is 475,136 bytes (464 KiB), the same image
size as before this port; occupied ROM grows by 3,568 bytes to 470,240. Global
RAM remains 3,909 bytes, ending at `0xCF45` before the fixed map at `0xD000`.
The resident ROM ends at `0x5D87`, leaving 633 bytes in its window (399 bytes
more than before). The player module is 7,691 bytes and the new orchestration
module is 1,887 bytes; every linked module fits its 8 KiB window. The latest
successful SDCC runs across all six production/test profiles peak below
675 MiB RSS. The whole-game solve takes 4m17.55s and peaks at 3,345,060 KiB
RSS in this run; its solver SHA-256 remains
`32e29311986d77a3b982710ffa3e0fdcc7f00125f08a5460129bcfcdfea23273`.

## Finite rules stay in Vexel; their representation is optimized

The next optimization changes the C++ value generator, not the game adapters.
The C fairy reference indexes a signed 64-byte wave table. The first Vexel
projection expanded the quarter-wave rule into comparisons, shared volatile
intermediates, reflection and a protected word addition. Those are avoidable
realization costs; they are not a reason to return the policy to C.

The generator now evaluates sufficiently complex pure subgraphs over every
pattern of a single byte input. It proves periodicity and ignored low bits,
then chooses a narrow ROM representation whose conversion preserves the
original result. The fairy's existing Vexel rule produces exactly the original
64 signed samples, indexed by `(clock >> 1) & 63`. Its frame falls from eight
bytes to four. The real binding call remains because previous SDCC failures
showed that volatile publication alone is not a safe substitution for it.

The same pass applies without game-specific recognition to ghost movement,
melee style selection, intro event timing, spark choreography and world seed
data. Twelve selected tables have 820 bytes of planned payload. Their constants
reside with the consuming code; no table pointer is stored in game state or
carried across a bank switch. The ordinary C build remains an independent
behavior and performance reference.

Measured MSX1 costs, using the same scenarios before and after:

| Observation | C reference | Previous Vexel | Table realization |
| --- | ---: | ---: | ---: |
| Fairy callback mean | 317.918 us | 576.391 us | 341.664 us |
| Fairy additional stack | 12 bytes | 30 bytes | 18 bytes |
| Intro callback median | 909.613 us | 1,375.314 us | 1,338.997 us |
| Whole-world median during intro | 3,850.489 us | 5,424.432 us | 5,026.337 us |
| Crowd update body mean | 13,654.642 us | 17,042.599 us | 16,944.961 us |
| Combat update body mean | 14,915.295 us | 18,738.118 us | 18,667.334 us |

The fairy is 40.7% faster than the previous Vexel projection, with 40% less
observed callback stack. It remains 7.5% slower than C. Intro callback median
improves by 2.6%; the world median there improves by 7.3%. Full-scene means
include dialogue waits and are not CPU cost measurements. Normal actor
callbacks unaffected by this transformation retain their previous timings;
this does not close the remaining C/Vexel gap in player and projectile logic.
Moving state through binding inputs/results and dispatching effects remain
real costs. The tables target computation inside those boundaries.

The production ROM still occupies a 464 KiB image. Used ROM falls by 1,217
bytes to 469,023, including the new tables. The player module falls from 7,691
to 7,256 bytes, leaving 936 bytes in its 8 KiB window. Resident ROM ends at
`0x5BE3`, leaving 1,053 bytes. Global RAM remains 3,909 bytes and the shared
binding slot remains 35 bytes. Normal smoke stack remains 242 bytes for Vexel
and 240 for C; encounter stack remains 126 bytes for both, and the full
intro/death scenario remains 594 bytes for both.

Evidence is collected in `build/finite-values/validation.json`, with callback
measurements in `build/finite-values-passive` and `build/finite-values-actors`.
The saved pre-change ROM was also re-profiled for the fairy comparison, using
its original assembly listings. The intro still completes in 799 updates with
hash 39153 and identical dialogue pattern captures. Host differential tests,
the real MSX encounter, ordinary gameplay smoke and the full intro/death check
exercise the generated code. The compiler's finite-table oracle exhausts byte
inputs under automatic and fixed storage, including signed shifts/division,
32-bit wrapping and default suffixes. SDCC remains serialized and capped at
2 GiB and 180 seconds; game builds retain the 2,000-attempt allocator limit.

This is one bounded realization strategy. Multi-input tables and mutable effect
regions retain their existing lowering; the solver does not claim to have
selected a globally optimal representation. The source rules and native effect
adapters are unchanged, and no LLM optimization service is introduced here.

## Sharing a choice through its consumers

The next generator change addresses multi-input rules such as the effects
timeline. Previously, `spent = elapsed < room ? elapsed : room` produced a
volatile temporary, followed by several SDCC helper calls to safely consume
that computed value. The C++ generator can now branch on that choice first and
specialize all affected results together. The ordinary arm uses the original
input directly. The capped arm knows that consuming `24-counter` leaves the
byte counter exactly 24, even when that subtraction wraps. Ordering facts also
remove redundant comparisons within the branch.

This is a representation choice over a typed pure graph, not recognition of an
effects routine. The same pass changes bomb timing, pickup timing and combat
ticks. It preserves widths, signed conversions, the real binding call and the
SDCC operand safeguards still required by the remaining calculations. Invariant
results are computed once, and inactive paths remain inactive. Mutable effect
regions keep their existing schedule. All gameplay sources and C adapters are
unchanged in this pass.

There is a deliberately bounded cost policy: two shared-value splits per
realization, small alternatives, limited graph growth, and a dynamic addition
or byte-ordering consumer that otherwise needs operand isolation. An earlier
candidate also split choices used only in constant comparisons. That slowed
the follower from 301.668 to 350.510 us and increased its stack from seven to
twelve bytes. The final generic cost rule excludes that case; the follower and
hit-detection headers are byte-identical to the preceding generator's output.
This experiment is retained in the evidence rather than reported as a win.

Real MSX1 callback measurements at one elapsed tick:

| Callback | C reference | Previous Vexel | Specialized choices |
| --- | ---: | ---: | ---: |
| Spark | 400.412 us | 600.751 us | 294.812 us |
| Explosion | 324.622 us | 583.524 us | 277.584 us |
| Pickup | 480.843 us | 647.512 us | 487.744 us |
| Ball | 1,824.331 us | 2,452.763 us | 2,431.810 us |
| Follower | 390.180 us | 301.668 us | 301.668 us |

Spark and explosion are 50.9% and 52.4% faster than the previous Vexel build,
and 26.4% and 14.5% faster than the C reference in this scenario. Their observed
additional callback stack falls from 18 to 14 bytes and from 17 to 13 bytes.
Pickup improves by 24.7%, but its stack grows from 16 to 19 bytes; ball gains
less than 1% and grows from 74 to 77 bytes. The combat update body improves from
18,667.334 to 18,449.683 us, while the encounter-wide observed stack peak falls
from 126 to 124 bytes. Player and fairy callbacks retain their earlier costs.
These are scenario measurements, not worst-case bounds or a claim that every
Vexel callback is faster than C. In particular, the zero-tick explosion remains
slower than the C implementation.

The production image remains 464 KiB. Occupied ROM grows by 241 bytes to
469,264; the resident window ends at `0x5C00`, leaving 1 KiB. Every module fits
its 8 KiB window, including the unchanged 7,256-byte player module. Global RAM
remains 3,909 bytes, ending at `0xCF45`, and the shared binding workspace remains
35 bytes. Logical unshared binding frames total 568 bytes, down from 570. The
game is still resolved as one program of 30 Vexel files and 65 exported roots,
with 53 bindings, then emitted into separate bank-sized compilation units.

The new oracle compares the bulk update with an independent tick interpreter
for all 65,536 byte pairs on the host under UBSan. The Z80 run covers every
counter byte at seven elapsed values, unsigned ordering, word conversions and
modular arithmetic, with both automatic and fixed storage. The existing stored
operand oracle also passes on both targets. SDCC retains its serialized 2 GiB,
180-second guard and the game's 2,000-attempt allocator limit.

The full intro/death run still completes in 799 updates with hash 39153 and
the same dialogue captures, mapper preservation and 594-byte stack observation.
The intro callback median itself stays at 1,338.997 us; the whole-world median
during that scene falls from 5,026.337 to 4,522.642 us as its effect actors become
cheaper. The C reference remains at 3,850.489 us. This is an improvement to the
generated realization of the Vexel scene's work, without moving that work back
into C.

The full compiler suite, game host differential tests, real MSX encounter and
ordinary SDL/MSX quest checks pass. Ordinary smoke stack remains 242 bytes for
Vexel and 240 for C; the black background and dialogue restoration checks also
pass. The 55-example program check reports no regressions and retains the
documented open value in `type_equations.vx`. All six production/test profiles
build successfully. The latest successful SDCC invocations remain below
674 MiB RSS. Detailed measurements, the rejected candidate and artifact
fingerprints are collected in `build/shared-choices/validation.json`.

## Allowing more ROM for faster pure paths

The game now requests `value_choice_branches=8`, up from the compiler's default
of two. `make generate VALUE_CHOICE_BRANCHES=2` restores the smaller allowance;
zero disables this particular transformation. The preference controls how much
pure control flow the generator may duplicate. It does not change gameplay
values or effects, remove bank-size checks, or raise SDCC's resource limits.
The same preference is available through Vexel metadata and the solver CLI.

The larger allowance lets both arms of the combat clamp specialize their
remaining work, and lets the bomb's later timing phase specialize too. Range
checks after substitution also eliminate impossible comparisons such as an
unsigned byte being less than zero. That removes the pickup's dead zero-room
calculations. These are general changes in the C++ generator; no gameplay
formula or native adapter is replaced. The existing requirement for a useful
dynamic arithmetic/comparison consumer remains, preserving the follower's
previous timing.

Measured MSX callback means at one elapsed tick:

| Callback | C reference | Previous Vexel | Larger allowance |
| --- | ---: | ---: | ---: |
| Bomb | 1,182.017 us | 1,084.123 us | 1,032.277 us |
| Pickup | 480.843 us | 487.744 us | 477.994 us |
| Ball | 1,824.331 us | 2,431.810 us | 2,419.735 us |

Bomb improves by 4.8%, pickup by 2.0%, and ball by 0.5%. Bomb's observed callback
stack falls from 41 to 39 bytes; pickup falls from 19 to 15, and ball from 77 to
73. Spark, explosion, fairy, follower and player costs are unchanged in these
scenarios. The encounter-wide observed stack remains 124 bytes. Bomb timing is
now included in `tests/profile_actor_callbacks.py`, using the existing real-bank
48-case matrix; `--family bomb` isolates it. Its previous ROM was profiled before
the rebuild, so this comparison has a measured baseline.

The added budget controls were tested at zero, two and eight under both fixed
and automatic storage. The nested clamp oracle exposed an SDCC subtraction
error when specialization was disabled: two stored byte operands were emitted
as consecutive loads into A, losing the first operand. The generator now
protects that case with `VX_VALUE_SUB8`. Correctness is independent of choosing
the faster realization; specialization removes this helper where its operands
become original inputs or constants. The independent tick interpreter exhausts
byte pairs on the host and covers the complete counter domain at seven elapsed
values on Z80. All six budget/storage combinations and the two existing
stored-operand target checks pass.

Production occupied ROM grows by 336 bytes to 469,600, within the same 464 KiB
image. This includes the additional arithmetic safeguard in the generated
runtime headers. The player module is 7,272 bytes, leaving 920 bytes in its
8 KiB window; every other module also fits. Resident ROM ends at `0x5C1D`,
leaving 995 bytes. Global RAM remains 3,909 bytes and the shared binding slot
remains 35 bytes. Logical unshared binding frames total 562 bytes, six fewer
than before. The whole program is still solved in one run, with 30 Vexel files,
65 roots and 53 bindings.

Compiler checks, all 55 example checks (including the documented open
type-equation case), game host tests, the MSX encounter, intro/death scenario
and ordinary SDL/MSX quest smoke pass. Intro progression remains 799 updates
with hash 39153; observed full-scene stack remains 594 bytes. Ordinary smoke
stack remains 242 bytes for Vexel and 240 for C, with matching dialogue captures
and map restoration. Production, smoke and encounter Vexel profiles were rebuilt;
the independent C reference images retain their baseline hashes. The solver
fingerprint matches the generated manifest and all measured C artifacts.
Evidence is collected in `build/speed-choices/validation.json`. SDCC remains
serialized, limited to 2 GiB and 180 seconds, with peak successful invocations
below 674 MiB RSS.

## Sharing decisions across movement outputs

The C++ value emitter now recognizes distinct selected values controlled by
the same predicate. Projectile movement expresses separate signed horizontal
and vertical displacements, each with zero-, one-, two- and three-tick cases.
Previously those decisions became stored intermediate values, followed by
coordinate arithmetic and SDCC operand-isolation calls. The generator now
selects the elapsed-time path once and specializes both coordinates and the
remaining animation outputs together. An established equality also substitutes
the exact compared input in other calculations on that path.

This is a general transformation of certified pure graphs, with no projectile
name or gameplay formula in the compiler. It preserves each integer conversion,
does not infer a whole word from its low byte, and writes invariant outputs
once. The existing `value_choice_branches=8` preference budgets both kinds of
specialization. `codegen.predicate_branches` reports these new splits separately
from `shared_select_branches`.

The cost policy requires two distinct selections feeding wide arithmetic, each
with a small alternative without a nested decision. A broader first candidate
also expanded melee's nested offset lookup and ball's comparison path. Melee's
one-tick callback rose from 1,239.540 to 1,243.513 us and its observed stack rose
from 25 to 29 bytes; the largest elapsed case was 5.0% slower. Ball rose from
2,419.735 to 2,425.245 us with unchanged stack. Those expansions were rejected.
Their measurements remain in `tmp/predicate-paths/broad-candidate` in the parent
repository. No game-specific exceptions were added.

The callback profiler now includes arrows, fire and melee using their existing
real-bank encounter matrices. The previous projectile ROM was measured before
rebuilding. The melee baseline uses the saved previous ROM and a listing rebuilt
from its saved generated headers with the same guarded SDCC flags.

Measured MSX callback means:

| Callback / elapsed ticks | Previous Vexel | Joint decisions | Reduction |
| --- | ---: | ---: | ---: |
| Arrow / 1 | 809.321 us | 616.559 us | 23.8% |
| Arrow / 2 | 820.495 us | 515.708 us | 37.1% |
| Arrow / 3 | 1,012.978 us | 568.787 us | 43.8% |
| Fire / 1 | 902.629 us | 724.673 us | 19.7% |
| Fire / 2 | 913.803 us | 596.165 us | 34.8% |
| Fire / 3 | 1,106.286 us | 649.245 us | 41.3% |

For zero through three ticks, arrow's observed callback stack falls from 27 to
15 bytes and fire's from 29 to 17. The 255-tick cases still use multiplication;
their stack falls by four bytes, to 29 and 31 respectively. These are scenario
measurements, not worst-case stack bounds. The one-tick C reference remains
faster (538.057 us for arrow and 596.724 us for fire); publication and the binding
call boundary still cost time. The two- and three-tick Vexel paths are faster
than the iterative C reference.

The final realization adds four predicate splits to `projectile_move` only.
Its frame falls from 25 to 23 bytes, bringing the sum of logical binding frames
to 560 bytes; the shared slot remains 35 bytes. Only the projectile headers and
the shared type header change among the 385 generated C artifacts. The other
measured actor and passive callbacks retain their previous timings and stack.
The encounter still restores banks correctly across 64 frames, with zero bank
errors and 124 observed stack bytes for Vexel versus 126 for C.

Production occupied ROM increases by 240 bytes to 469,840, within the same
464 KiB image. The arrow and fire modules grow by 120 bytes each, to 2,082 and
2,046 bytes. Every module fits its 8 KiB window; the player remains 7,272 bytes.
Resident ROM still ends at `0x5C1D`, leaving 995 bytes, and global RAM remains
3,909 bytes. Whole-program generation still solves all 30 files, 65 roots and
53 bindings in one run before emitting separate bank-sized C modules.

All 74 compiler test commands passed during development. After narrowing the
cost policy, the host value suite, six focused Z80 projects and all 55 example
program checks passed again; the existing open value in `type_equations.vx`
remains documented. The independent predicate oracle exhausts every byte
velocity/duration pair on the host, then checks representative durations on
Z80, with expansion disabled/enabled and automatic/fixed frames. It also covers
word/dword wrapping, invariant outputs and low-byte equality without losing
the original word's upper bits.

The final game passes host differential tests, the real MSX encounter,
intro/death and ordinary SDL/MSX quest smoke. Intro remains 799 updates with
hash 39153 and 594 observed full-scene stack bytes. Ordinary smoke remains
242 bytes for Vexel and 240 for C; popup captures, background and map restoration
match. Production, smoke and encounter Vexel images were rebuilt, while the C
reference images retain their baseline hashes. The generated manifest matches
the final solver and all measured C artifacts. Evidence is collected in
`build/predicate-paths/validation.json`. SDCC remains serialized and capped at
2 GiB/180 seconds; latest successful invocation peaks remain below 674 MiB.


## Remaining gameplay policies and complete world scans

The normal game now imports 34 Vexel files in one `--program --mode serial`
solve, with 78 exported runtime roots and 66 selected C bindings. This migration
covers the remaining blocks identified in the gameplay audit:

- `contact.vx` owns weapon rectangles and player contact, preserving the original
  fixed-point shift, byte-distance wrap and inclusive edges. Native code still
  enumerates physical slots and dispatches hit callbacks through the mapper.
- `interface.vx` owns ordered menu movement/confirmation, cursor coordinates,
  password character acceptance, capitalization, blinking and completion.
- `title.vx` owns the entire presentation command stream, random acceptance and
  spark placement, frame cadence, cancellation and attract-mode progression.
  `title_sequence.c` applies commands and preserves the original native sequence
  for `GAMEPLAY=reference`. Production maps the title into its own page-C bank.
- `world_flow.vx` owns both actor-scan loops and the world's spawn scan as actual
  effectful Vexel regions. Engine capabilities provide fresh slot/entity/map
  snapshots, yield, update, spawn and despawn. The source decides iteration,
  callback order, survival and spawn eligibility. Reads after callbacks observe
  their mutations; the port does not cache an earlier world snapshot.
- `orchestration.vx` also owns new-game inventory/flower/map facts, initial camera
  placement and the ordered equipment-initialization capability stream.

The renderer, physical map queries, entity storage/allocation, input/audio
hardware, mapper trampolines and optimized assembly remain native. Applying a
Vexel command still requires native state writes and capability dispatch. C
reference implementations remain independently executable. This is a migration
of the identified gameplay blocks, not an automatic translation of the engine.

The selected fixed binding storage is 68 bytes: 35 shared by pure bindings and
33 shared by the mutually exclusive world/title scan regions. A region remains
live while invoking actor callbacks, so it cannot share the pure workspace.
The normal Makefile allowance is 96 bytes; the optional 56-byte player-motion
region therefore remains automatic. Source lifetime contracts describe the
actual cooperative graph: interrupts remain disabled and engine yields service
the display. No new concurrency mechanism is introduced.

This exposed a generic region-emission defect: zero-argument sources and
void-result sinks did not create empty boundary publication sets. The emitter
now creates those sets before lowering flow. The existing loop/callback oracle
covers both forms on the host and Z80, including callbacks using another live
binding.

A first title realization also exposed a cost-policy limit. Its first four
small ROM tables exhausted the per-function count, leaving later command
arithmetic to execute repeatedly. The bounded table count is now eight, with
the same 256-byte per-table and 512-byte total limits. Enumeration still proves
all 256 byte inputs, including wrapping and signed interpretation. A five-field
regression checks that later fields receive tables and retain exact results in
both automatic and fixed storage on the host and Z80.

Host differential tests compare the complete title effect trace and its random
draws, every cancellation phase, equipment callback ordering, and world mutation
across yields/callbacks. Independent contact/input oracles cover wrap edges,
simultaneous direction/confirm input, editor characters and attract-clock wrap.
`tests/check_title.py` exercises the production ROMs, including the complete
1,894-wait sequence, skips and the attract transition. Background patterns,
colors and name tables compare exactly. Full VRAM captures are retained, but
sprite bytes are not required to match between C and Vexel: spark cadence
follows physical time, and this difference already exists in the saved
pre-migration Vexel ROM. The host title oracle compares logical spark updates
under identical clock input.

Extracting the title also exposed a native bank-ownership assumption: the world
reveal called `titlemap_copyPN*` and `titlemap_free` while the overworld bank was
mapped. Both variants now call the corresponding overworld capabilities.
Smoke/encounter profiles omit the unused title driver, so its incidental mapper
reference can no longer hide a wrong-bank dependency. The production title
continues to use titlemap capabilities in its explicitly mapped bank.

The final production cartridge remains **475,136 bytes (464 KiB)**. Occupied ROM
is 472,441 bytes, 2,601 above the saved pre-migration build. Global RAM is
**3,938 bytes**, up 29, leaving 158 bytes before the fixed map at `0xD000`.
The title driver is 2,563 bytes and the world driver 2,137 bytes; every linked
code module remains within 8 KiB. The title's full production presentation takes
35.970 seconds in openMSX, versus 35.817 for the C reference and 35.066 for the
saved earlier Vexel ROM. Its first migrated realization took 47.751 seconds;
allowing the fifth exact table (54 bytes) removed most of that regression.
Observed title stack is 55 bytes versus 50 for C and 45 in the earlier Vexel
ROM. These are end-to-end scenario measurements, including display waits, not
worst-case stack bounds or pure instruction benchmarks.

The spawn scan reads lifecycle flags first and requests coordinates only for
automatic, unspawned entities. This is expressed in Vexel; the native adapters
only provide the requested facts. It reduces the initial migration's crowded
encounter body from 25.658 to 23.401 ms and its frame from 40.381 to 34.401 ms.
The saved pre-migration build still performs less work: 16.945 ms body and
33.315 ms frame. Display waits can hide some added work, so the body regression
matters even where the total frame changes little. The complete scan region
currently pays for boundary publication/calls and a conservative control-flow
realization; migration does not yet make it faster than its former C loop.
Observed encounter stack improves from 124 to 120 bytes (C: 126).

The scripted-scene run retains 799 updates and state hash 39153. Its world
callback median is 6.145 ms, improved from the first migration's 8.401 ms but
above the previous 4.523 ms. Full-scene stack falls from 594 to 591 bytes;
the world callback's observed additional stack falls from 583 to 580 bytes.
Existing actor callback measurements remain unchanged except ball contact,
whose single-tick callback rises from 2.420 to 2.469 ms with the migrated
geometry; its observed stack remains 73 bytes. Arrow/fire single-tick callbacks
retain the earlier optimized 0.617/0.725 ms timings.

Both gameplay variants build for Linux and MSX in production, smoke and
encounter profiles. Host differential checks, complete SDL/MSX smoke and scene
checks, production title playback/skips, encounter bank restoration, all 98
delayed sprite frames, and the targeted compiler host/Z80 regressions pass.
The 55-example compiler sweep has no failures; `type_equations.vx` remains its
documented open case. Evidence and source/solver/ROM hashes are collected in
`build/remaining-gameplay/validation.json`. SDCC remains globally serialized,
with a 2 GiB address-space limit and 180-second timeout per invocation.

## Region publication lifetimes and embedding usage

The complete world scan is an optimization workload for the Vexel emitter.
This pass changes the solver and its C realization; the gameplay sources and
native engine logic retain their migration-baseline contents.

The region now consumes callback results directly while their published values
remain live and unchanged. A snapshot still gets separate storage when a later
call could overwrite a value needed by the continuation. Copy-aware interference
also lets the loop counter occupy its published slot argument: the two names
remain equal until the counter advances. Branch-only selections become direct
control-flow edges, preserving narrowing, selected numeric values and callback
order. The world frame falls from 33 to 21 bytes, with nine bytes of coalesced
state and three fewer scratch bytes; the title scan falls from eight to seven.
The two regions still share one slot and remain separate from the pure workspace.

This exposed a placement cliff. With a 22-byte world frame, the normal 96-byte
allowance excluded the optional 56-byte player region. Reducing the world frame
by one more byte let the frequency heuristic select that unused alternative,
occupying 96 bytes and moving six active pure bindings to automatic storage.
The generated plan and memory report for that rejected selection are retained
in `tmp/region-frontiers/allocation-cliff` in the surrounding Vexel repository.

The embedding now contributes its usage through the generic
`binding_frequency.IDENTITY` preference. A zero cap reserves no fixed storage
for that binding but leaves its automatic interface callable. The generator's
`--player-region` option carries the native `PLAYER_REGION` build choice into
placement, and the optimization driver's projection-cache key includes it.
The manifest records the embedding choice. Normal generation uses 56 bytes:
35 for all active pure bindings and 21 for the world/title regions. The source's
ownership contracts and the RAM allowance are unchanged. Frequency remains an
estimated placement preference, with no claim of optimal selection.

`tests/profile_world_flow.py` records inclusive and exclusive emulated time
for the actual world-region calls in the 64-frame encounter. It separates engine
boundaries, arithmetic/copy helpers and the remaining region instructions,
and fingerprints the ROM and listing. For example:

```sh
python3 tests/profile_world_flow.py \
  --rom build/vexel-encounter/msx/weiss.rom \
  --listing build/vexel-encounter/msx/src/gameplay/world_orchestration.lst \
  --output build/region-frontiers/world
```

This distinction matters: display waits and callback timing can conceal changes
in the surrounding code. The report's region-only time excludes the called
helpers; aggregate overhead adds the helpers' exclusive time back once. It
does not attribute engine work to the compiler's generated loop.

The final production image remains 475,136 bytes (464 KiB), with 472,298
occupied bytes, down 143. Global RAM falls from 3,938 to 3,926 bytes, leaving
170 bytes before the map. The world driver falls from 2,137 to 1,995 code bytes;
the title driver falls from 2,563 to 2,562. All linked modules stay within 8 KiB.

Across the 64-frame encounter, the region's own time falls from 2.536 to
1.919 ms per scan, and helper time from 0.919 to 0.606 ms. Combined overhead
falls from 3.455 to 2.524 ms, about 27%. Crowded update work falls from 23.401
to 22.457 ms; frame time changes only from 34.401 to 34.371 ms because display
waits absorb much of the saving. Observed encounter stack falls from 120 to
117 bytes. Combat update work falls from 23.063 to 22.529 ms. These are measured
scenarios, not cycle bounds or a promise that every world state improves.
Physical-clock timing also affects scheduling: actor-update calls in the
profile change from 562 to 559. The independent host oracle checks identical
inputs and exact callback order; the profile retains its actual call counts.

The production title retains all 1,894 waits, background captures and attract
transition, taking 35.970 seconds with 55 observed stack bytes. The full world
region still costs more than the earlier native scan. Its preserved engine
boundaries and arithmetic isolation helpers remain explicit costs; this pass
does not weaken their correctness contracts to obtain the timing reduction.

The scripted scene still completes 799 updates with state hash 39153. Its
world-callback median falls from 6.145 to 5.773 ms, with full-scene stack
unchanged at 591 bytes. The intro callback's relative stack measurement changes
from 559 to 562 bytes while the enclosing world callback remains at 580 bytes;
the complete scenario does not gain stack depth. The separately controlled
actor callback timing and stack probes are unchanged. Both fixed and automatic
versions of the optional player region pass the encounter and real-map checks.

Production, smoke and encounter builds pass for both Linux and MSX. The three
C reference ROMs remain byte-identical to the saved baseline. Full smoke keeps
242 observed Vexel stack bytes (240 for C), matching popup contents and restoring
both map buffers at every checked exit. Host/Z80 region and value regressions
cover the new lifetime, truth and frequency rules; the region solver also passes
ASan/UBSan checks. The 55-example sweep has no failures and the same documented
open `type_equations.vx` case. Source, solver and ROM fingerprints, resource
checks, before/after profiles and the rejected allocation are collected in
`build/region-frontiers/validation.json`. SDCC remains globally serialized with
the existing 2 GiB address-space cap, 180-second timeout and allocation-search
budget. The validator distinguishes the sanitizer environment's disabled leak
inspection from its enabled address/undefined-behavior checks.

## Native boundary implementation alternatives

The portable world graph still uses entity/slot indices and ordered queries.
The native adapter now offers equivalent C statement implementations in
`src/gameplay/native_boundaries.json`, with bodies in `native_world.inc`.
Generation supplies those offers to Vexel through `--boundary-expansion`.
The solver records availability in `boundary_contracts` and selected statements
in each region binding's `codegen.region_expansions`.

An expansion receives the same typed argument/result object as the wrapper.
It runs after argument publication and before result checking and snapshot
preservation. It does not allow caching a position across an update, postponing
a read past a callback, changing the engine footprint, or reusing a live region
frame. The C adapter remains responsible for structure layout and pointers.
These four queries access resident `state`/`map` RAM on MSX; actor dispatch and
mapper-changing operations retain their existing wrappers/trampolines.

Both implementations use the same native bodies. Each wrapper is conditionally
compiled when `VX_BIND_IDENTITY_EXPANDED_SYMBOL` is zero. The selected statement
macro must be defined before the generated region header. Missing implementations
fail compilation; the build does not silently choose a different realization.
The generation manifest fingerprints both the native offers and their C bodies,
so a measurement cannot be reused as evidence for changed adapter code.

Use `--prefer region_boundary_expansion=0` with `tools/generate_quest.py` to
retain all wrappers, or `--prefer boundary_expansion.flow_actor=0` to retain one.
The ordinary Vexel source ABI is unchanged. These are explicit physical choices;
the solver does not claim to prove arbitrary C equivalence or predict SDCC's
register allocation. Host differential traces and target measurements decide
whether an offered realization is worthwhile for this embedding.

The project's native configuration also supplies replaceable preference defaults.
Explicit `--prefer` arguments replace defaults with the same key before the
request reaches Vexel; multiple explicit/source contributions still use the
solver's minimum rule. The selected defaults expand `flow_slot` and `flow_cycle`.
Actor/flag queries retain wrappers because expanding their native pointers made
SDCC allocate a six-byte stack frame (including saved IX) in the world region.
For the aggressive alternative, pass both
`--prefer boundary_expansion.flow_actor=1` and
`--prefer boundary_expansion.flow_flags=1` to the generator.

Measured against the preceding region-publication implementation:

| Measure | Wrappers | Selected small queries | All four queries |
| --- | ---: | ---: | ---: |
| Query + orchestration work per scan | 3.925 ms | 3.825 ms | 3.660 ms |
| Crowded update body | 22.457 ms | 21.935 ms | 19.571 ms |
| Crowded frame | 34.371 ms | 34.368 ms | 33.360 ms |
| Encounter observed stack | 117 B | 117 B | 123 B |
| World module code | 1,995 B | 1,987 B | 2,149 B |
| Fixed Vexel workspace | 56 B | 56 B | 56 B |

The query/orchestration measurement sums region self-time, query wrappers where
present, and arithmetic helpers. Inlined query time moves into region self-time,
so comparing self-time alone would be misleading. The 64-scan scenario is
clock-sensitive: faster execution can change actor scheduling and update counts.
These are measured scenarios, not identical instruction traces or worst-case
bounds. Controlled actor callback timings and stack depths are unchanged, and
host oracles compare identical ordered effects under identical inputs.

The selected default saves 8 world-module bytes and 8 title-module bytes without
increasing fixed RAM or observed encounter stack. Its frame-time change is
negligible. The larger alternative is preserved for further measurement rather
than being presented as universally better. Evidence is kept in
`build/native-boundaries/validation.json`; the experimental ROMs, projections and
logs are under the parent repository's `tmp/native-boundaries/`.

## Sharing native publication storage

Vexel now allocates native boundary objects using the complete region's final
field lifetimes. A query or command borrows its typed publication object during
the synchronous call. Results still needed by the continuation remain live;
dead objects can share a C union with later publications. The native adapter
uses the generated `_DATA` macro, initializes results, preserves arguments and
retains neither the address nor an assumption about object identity. No game
Vexel rules, native query bodies, mapper operations or assembly changed here.

This allocation runs after scalar coalescing. In the world region, the slot
query's argument also holds the loop counter, so its two-byte object remains
separate across every callback. The directly expanded cycle query also keeps
its own byte, while the other six boundary objects share a five-byte slot.
This reduces boundary storage from 18 to 8 bytes and the whole world region
from 21 to 11 bytes. The title region shrinks from 7 to 5 bytes;
it shares the world region's fixed slot, so total fixed Vexel workspace falls
from 56 to 46 bytes. The optional player region remains 56 bytes and automatic.

The plan reports `region_boundary_slots`, `region_boundary_conflicts`, and the
shared/separate byte costs. `--prefer region_boundary_overlay=0` with the game
generator retains separate publications. Packing is deterministic and
conservative, not an optimality claim. Reads and writes belonging to the same
transfer conflict, protecting reversed aggregate handoffs as well as replies
retained across later calls.

The default mode `1` keeps directly expanded native objects dedicated, a target
cost heuristic recorded in `region_boundary_dedicated`, separate from lifetime
conflicts. Mode `2` also shares those objects. The fully shared world region
needed only 10 bytes, but SDCC introduced spills: encounter stack grew from 117
to 124 bytes and measured orchestration/query time from 3.825 to 4.477 ms per
scan. Saving one extra RAM byte did not justify that cost. The generic heuristic
preserves this legal candidate for measurement instead of treating minimum
frame size as the sole objective.

The aggregate regression also exposed an SDCC register-forwarding failure when
native statements publish multiple results. Generated Z80 functions now isolate
those aggregate expansions; host C still expands them directly. The selected
Edelweiss query expansions have scalar results and keep their direct emission.
`region_expansion_barriers` makes this target safeguard visible in the plan.

The final solver-generated layout matches the measured prototype's world and
frame objects byte for byte. Compared with the previous native-query release:

| Measure | Separate objects | All compatible sharing | Selected default |
| --- | ---: | ---: | ---: |
| World region | 21 B | 10 B | 11 B |
| Fixed Vexel workspace | 56 B | 45 B | 46 B |
| Production global RAM | 3,926 B | 3,915 B | 3,916 B |
| World module code | 1,987 B | 2,027 B | 1,986 B |
| Encounter observed stack | 117 B | 124 B | 117 B |
| Query + orchestration per scan | 3.825 ms | 4.477 ms | 3.813 ms |

The selected default's occupied ROM is 472,280 bytes, two fewer than before;
the allocated image remains 475,136 bytes. Title module code falls by one byte
as well. The scan speed improvement is small, with the same measured boundary
call counts as the baseline. These are scenario measurements, not universal
speed or stack bounds. Source/ROM fingerprints, complete validation and the
unselected candidate are recorded in `build/native-lifetimes/validation.json`
and the parent repository's `tmp/native-lifetimes/`.

## Pure predicate functions over published state

The world scan's window checks now use four generated pure functions at six
decision sites. Vexel derives them from the ordinary byte expressions and their
live frame inputs. Each function reads the current actor reply directly and
returns the condition; repeated sites share code but never a cached reply.
The functions stay in the consuming module and execute at the original branch.
The same selection applies to other eligible regions, including one predicate
in the optional player-motion projection.

The real function boundary prevents SDCC from forwarding earlier stored
operands through clobbered registers. Within it, the selected arithmetic only
reads immutable inputs, so it can use direct byte operations. Fixed frames
avoid passing each operand through the generic arithmetic helper; automatic
frames pass their own stable frame pointer. Boolean predicates return their
already-normalized result directly, avoiding SDCC's retained double inversion.
Numeric conditions still compare their correctly narrowed value with zero.

The initial policy is deliberately bounded: at most two byte fields, one
dynamic addition/subtraction or unsigned ordering operation, and surrounding
byte casts/constant operations/comparisons. Wider calculations and more complex
graphs retain their previous lowering. `--prefer region_predicate_functions=0`
with the generator retains the earlier realization. The plan reports distinct
functions and static call sites as `region_predicate_functions` and
`region_predicate_calls`.

Measured against the preceding native-lifetime release:

| Measure | Previous | Predicate functions |
| --- | ---: | ---: |
| Query + orchestration per scan | 3.813 ms | 3.459 ms |
| World module code | 1,986 B | 1,967 B |
| Production global RAM | 3,916 B | 3,916 B |
| Fixed Vexel workspace | 46 B | 46 B |
| Encounter observed stack | 117 B | 119 B |

The query/orchestration improvement is approximately 9.3%, with identical
measured native boundary-call counts. The profile replaces 990 generic byte
subtraction calls with 990 calls to the two active window predicates. The
observed stack cost grows by two bytes because SDCC changes its register-save
behavior in the caller. The default accepts that cost for the measured speed
gain; it does not claim that predicate extraction always reduces stack use.
The other two predicates cover spawn decisions outside this particular crowded
scan. Host differential checks and the full-game scenarios exercise those paths.

Occupied production ROM falls to 472,261 bytes; the allocated cartridge remains
475,136 bytes. Frame times depend on clock-sensitive scheduling and yields, so
the isolated query/orchestration measurement is the useful comparison here.
Neither these timings nor observed stacks are worst-case bounds. Fingerprints,
target measurements and validation are collected in
`build/predicate-kernels/validation.json`, with logs and the preceding artifacts
under the parent repository's `tmp/predicate-kernels/`.

## Runtime support selected by demand

Generated headers now include only the arithmetic support they actually call.
Previously SDCC emitted four helper definitions in every consuming module,
including unused ones. The whole-game projection now emits 14 helper/module
pairs instead of 100. This changes no game source or selected frame layout.

| Measure | Previous | Selected support |
| --- | ---: | ---: |
| Occupied production ROM | 472,261 B | 470,689 B |
| Production global RAM | 3,916 B | 3,916 B |
| Fixed Vexel workspace | 46 B | 46 B |
| Encounter observed stack | 119 B | 119 B |

The encounter, title, scripted scenes, Linux/MSX smoke, optional player-region
host checks and controlled actor callbacks pass. Controlled callback timings
and stacks are unchanged. The cartridge allocation remains 475,136 bytes.
`build/eight-hour-runtime/validation.json` records the artifacts and measurements.

The same projection also benefits from exact structural keys in the solver's
builder and control caches. On this workload, generation falls from 261.64 to
46.76 seconds and peak RSS from 3,372,248 to 1,387,396 KiB. The complete report
and all 454 generated artifacts match byte for byte. These measurements compare
the same source, boundary offers and preferences; they are not universal solver
performance bounds.

## Products at the required width

Byte and word products now use narrow arithmetic support instead of the
32-bit helper. Constant powers of two, including modular negative constants,
become shifts. The change is in Vexel's general value emitter; game logic and
handwritten assembly stay the same.

Against the preceding selective-runtime build, occupied production ROM grows
by 52 bytes to 470,741 bytes. Global RAM remains 3,916 bytes and fixed Vexel
workspace remains 46 bytes. The crowded encounter still observes 119 stack
bytes. In isolated workloads using the actual generated game headers:

| Workload | Tick reduction | Previous observed stack | New observed stack |
| --- | ---: | ---: | ---: |
| Cursor positions | 29.6% | 33 B | 27 B |
| Title pan commands | 19.8% | 37 B | 31 B |

The arrow/fire callbacks at elapsed 255 improve from 2,899/2,979 microseconds to
1,837/1,918 microseconds, with four fewer stack bytes. Elapsed one/two timings
are unchanged; elapsed three costs approximately 0.56 additional microseconds.
The title and cursor measurements cover their named arithmetic workloads, not
whole frames, and observed stacks are not worst-case bounds.

All three Linux/MSX profiles, game differential checks, optional player-region
host checks, encounter, title, scenes, smoke and callback measurements pass.
The isolated build and complete artifact fingerprints are preserved in
`build/eight-hour-multiply/validation.json`; the parent repository's
`tmp/eight-hour-20261118/multiply/` holds the compiler and arithmetic evidence.

## Finite values and measured realization choices

The value projection can now use a small intermediate domain to simplify the
rest of a calculation. It enumerates that domain under the current branch
facts, then chooses between native expressions, constants, bit tests, affine
expressions and bounded ROM tables. The resulting expressions rejoin the
ordinary value graph, so later branch simplification and temporary scheduling
can share them. A table must remove more estimated work than it introduces;
shared producers count as removed only when their last use disappears.

These estimates guide a bounded search. Actual Z80 measurements remain the
test of whether an implementation is useful. In particular, computed tables
slowed the bomb callback despite improving its estimated expression cost.
`src/gameplay/native_boundaries.json` therefore selects
`value_table_search.bomb_step=0`. This disables discovery of computed table
indices for that binding; direct-input tables and ordinary branch
specialization remain available. Disabling branch specialization as well was
measured and rejected: the isolated bomb workload took 8.27% more ticks and
three more stack bytes.

The selected implementation, measured against the start of the November 18
optimization run, has these costs:

| Measure | Before | Selected |
| --- | ---: | ---: |
| Occupied production ROM | 472,261 B | 470,986 B |
| Production global RAM | 3,916 B | 3,912 B |
| Fixed Vexel workspace | 46 B | 42 B |
| Encounter observed stack | 119 B | 119 B |
| Active melee, elapsed one | 1,239.540 us | 1,094.818 us |
| Active melee observed stack | 25 B | 29 B |
| Arrow, elapsed 255 | 2,898.972 us | 1,357.435 us |
| Arrow observed stack at elapsed 255 | 29 B | 23 B |
| Bomb, elapsed three | 1,473.325 us | 1,466.434 us |

The active melee speed gain costs four callback stack bytes. The inactive
melee path costs an additional 3.35 microseconds and two stack bytes. Player
callback measurements are unchanged; the ball callback improves by about
3.10 microseconds with unchanged stack. These are controlled callback
measurements, not whole-frame speedups or worst-case stack proofs. The
allocated cartridge remains 475,136 bytes.

The shared measured-search tool retains all nondominated validated candidates
alongside the selected lexicographic winner. A later policy can therefore
inspect the speed/stack/ROM alternatives for the same inputs. Every retained
frontier artifact is fingerprinted and checked again when the search finishes.
The tool does not treat an estimated graph cost as a measurement, and it does
not use an LLM to decide source semantics.

All Vexel gameplay still enters one serial whole-program solve; generated C
is split into bank-safe translation units for SDCC. All three Linux/MSX
profiles were rebuilt from scratch, followed by encounter, title, scripted
scene, smoke and callback checks. Every code module fits its 8 KiB bank and
global RAM stays below the map buffer. SDCC remains serialized with a 2 GiB
address-space limit, a 180-second limit per invocation and
`--max-allocs-per-node 2000`; the fresh builds peaked at 690,240 KiB RSS. The game
retains its existing KonamiSCC mapper.

`make optimize-player` now inherits the Makefile's current workspace and
branch-specialization budgets. Its reusable baseline records common source,
compiler and tool fingerprints, as well as the exact physical preferences.
Changed inputs require a fresh baseline; unchanged inputs are checked again
throughout measurement. Both Linux and MSX executables are retained as evidence.

`build/eight-hour-closure/validation.json` records exact compiler and ROM
fingerprints, the full 91-group release and sanitizer results, all 55 language
examples and 38 supported target workloads. One example intentionally leaves
an open value; its type query still resolves. Generated case interfaces now
also support invariant results and independent result guards. A caller must
inspect the partition and call its matching case on the same input snapshot;
those partial interfaces do not authorize independent effects or activations.

Known operands now pass through their complete wrapping-conversion chains into
native immediates. The focused arithmetic workload saves 6–13% of Z80 ticks
with unchanged observed stack. An expanded zero-product workload saves
3.6–6.5% of its ticks and 4–8 observed stack bytes. These are separate measured
workloads, not percentages to add or whole-frame improvements. The permanent
oracle also checks a preceding external call still runs exactly once when its
entire result is discarded by multiplication by zero.

The final zero-product change leaves all 494 generated game code files exactly
equal to the preceding fully rebuilt checkpoint. Its binaries and scenario
results are retained, with their hashes and unchanged native inputs checked.
The optional player projection also remains byte-identical to its measured
candidate. Native-immediate propagation made that local region about 12% faster
and reduced its observed stack from 23 to 17 bytes. The selected path uses 26
bytes, but still wins on speed; the local region's elapsed-zero overhead and
remaining movement cost keep it outside the current regression limits.

All six worklist/branch orderings preserve the checked host game traces, for
both player paths. Reversing module imports also preserves those traces and
passes an independently built MSX encounter and callback checks. Generated
private names and layouts can change without changing source meaning.

## Measured scratch-storage alternatives

`make optimize-storage` asks Vexel for whole-game plans and discovers full pure
bindings whose retained calculations can reuse scratch slots. The compiler
publishes the exact scoped preference identity, effective choice and reuse
count. The experiment tries a bounded neighborhood: the baseline, individual
changes, then joint changes. Within each neighborhood, higher-frequency source
scopes are tried first, with deterministic preference-name ties; the recorded
`priority.json` makes this order reviewable. This affects where a limited search
spends its time, without changing its validation or measurement requirements.
A joint candidate matters because frame overlays and bank placement can couple
otherwise separate functions.

Every fresh candidate passes the independent C/reference host checks, a fresh
Linux/MSX build, and the complete SDL/openMSX quest scenario. An isolated probe
then executes every affected linked helper over the same boundary-pattern and
fixed-seed random inputs, validating results against a host oracle. It measures
entry-through-return with interrupts disabled. Its stack count includes the
entry return address and excludes caller-owned input/frame publication; it is
an observed sample maximum, not a worst-case proof. The existing full-game
scenario separately measures its own stack and ghost callbacks.

Selection rejects any helper/instance/input more than 2% slower than baseline,
any helper stack regression, and regressions in the full-game stack or ghost
samples. It checks actual linked RAM and occupied ROM, including the linker's
bank limits. Among accepted candidates it minimizes full-game stack, maximum
helper stack, frequency-weighted helper timing, then ROM. Frequency weights are
source hints: the resulting score is not a gameplay frame-time estimate.

Use `python3 tools/optimize_storage.py --help` for wall, candidate and sample
budgets. The selected editable project and full evidence remain under
`build/storage-optimization/run-*`; `latest.json` points to the completed
selection. Production preferences and generated files are not overwritten.
The cache records the pinned solver, source/tool inputs, platform resources,
environment, workload and exact preferences, and rechecks artifact hashes on
every hit. A stale or corrupt record is a miss. Per-process SDCC limits and the
shared serialization lock also apply while several validation tools are active.

The initial 2026-11-20 experiment demonstrates the tradeoff concretely. Keeping
reuse in `player_view` while disabling it in `scene_camera` changes the camera's
frame from 16 to 18 bytes, but both fit the existing 42-byte shared allocation.
Its sampled mean falls from 397.63 to 271.39 microseconds and its observed helper
stack from 6 to 5 bytes. The player helper remains at 174.80 microseconds and
2 stack bytes. Occupied smoke ROM falls from 304,551 to 304,497 bytes; full-game
observed stack remains 242 bytes. These results describe the retained experiment
at `build/storage-optimization/run-w_eoax0y`, not a claim about every workload or
subsequent compiler revision.

## Arithmetic facts and target realizations

The 2026-11-20 optimization session keeps gameplay in one Vexel resolution.
Range facts now survive closed native arguments, captures, results and loop
snapshots, while demanded result bits can reduce the width of an operation.
The C projection still checks source inputs and preserves observable completion,
effect order and snapshots. These facts also guide scratch widths, output order
and ordinary result sharing; none requires rewriting gameplay into target C.

The checked-in preferences retain distinct scratch slots for `scene_camera`,
reuse for `player_view`, and the previously measured per-binding output-order
choices. The selected full bindings use a 40-byte shared workspace, compared
with 42 bytes at the start of this session. Their unshared frame sum falls from
661 to 652 bytes. At the rotation stage, ordinary selected static locals fell
from 88 to 86 bytes; the later publication choice below changes that plan again.
These figures describe generated storage plans, not whole-game stack bounds.
For example, `contact_box` uses 13 frame bytes, `projectile_spawn` 20,
`player_view` 15 and `scene_camera` 18. A larger camera frame is retained because
its measured execution is better and it fits the same shared allocation.

SDCC's handling of published byte operands required correctness fixes as well
as optimization. Dynamic AND/OR/XOR operands derived from retained calculations
use private register-argument barriers, and wrapped unsigned right shifts keep
explicit high-bit correction unless the immediate consumer already masks it.
The independent probe found a pre-existing collision comparison failure that
the full quest scenario did not exercise. The extracted regression and the
complete linked-binding probe now cover that path. Faster incorrect code is
excluded from selection.

`value_rotation_helpers=1` is selected for this game. Vexel recognizes unsigned
byte rotations only while both complementary shifts remain in one expression.
An inline C helper composes one-bit rotations, which SDCC emits directly in the
caller. It preserves one evaluation of the input and does not reread an expired
scratch slot. This improves the weapon-selection binding as follows:

| Realization | Sampled mean | Observed helper stack |
| --- | ---: | ---: |
| Dynamic bitwise barriers | 130.16 µs | 6 B |
| Separate rotation helper calls | 117.32 µs | 6 B |
| Selected inline rotation steps | 85.69 µs | 2 B |

All 57 full bindings, across 63 linked instances, pass the same independent
host/target oracle in that comparison. Only `player_weapon` changes between
these three candidates. Every measured input is faster with the inline choice
than with the barriers. Compared with the earlier shift-corrected implementation
at 107.34 µs and 2 stack bytes, its mean improves by about 20% with unchanged
stack and no slower sample. The measurements include entry/return and exclude
caller publication and interrupts; they are not a frame-time prediction.

The generation at that rotation stage reproduced all 517 C/header/fragment
files of its measured candidate exactly. Whole-program image units now carry their own
private helper-support headers. The embedding includes those headers alongside
the units it places in separate engine modules; shared global storage is still
emitted once. This closes the former accidental dependence on a static helper
being included by another translation unit. Generated sources remain editable
SDCC projects with the existing KonamiSCC placement and engine boundaries.

Other candidate choices remain explicit. Quotient/remainder sharing defaults
off because automatic storage can trade fewer cycles for more stack. No such
pair is selected by the current game. A proved reciprocal expression for byte
division by seven was also tested through Vexel: it was correct, but slower and
larger on the stack in both ordinary storage policies, so it was not adopted.
The bounded storage/schedule search records accepted, rejected, timed-out and
unmeasured candidates separately. Frequency hints order trials; measured target
results and the unchanged correctness checks decide which can be selected.

Evidence for the arithmetic choice is retained under
`build/eight-hour-20261120-0838/rotation-choice-0`, `rotation-choice-1` and
`inline-rotations`. The final publication candidate uses `publication-balanced`;
the completed storage search is `build/storage-optimization/run-e1wl8gsp`.
The earlier `run-cyk8sq_1` reached a whole-project deadline and selected nothing.
The detailed
compiler proof, arithmetic and bank-pressure evidence is recorded in Vexel's
`docs/relational-completion.md` and its matching eight-hour work directory.


## Public result storage and linked measurements

Ordinary public results now have two independent physical choices: snapshot
width and snapshot reuse. Each result is evaluated once, serialized completely,
then its slot can be reused for the next result. The default keeps one carrier
at the solved payload width. Per-function preferences can retain wider or
separate carriers when their generated Z80 code uses less stack or runs faster.
Source arithmetic, checks, public payload formats and activation proofs remain
unchanged by these choices.

The game retains both allowances at zero for `vx_password_decode`:

```text
calculation_publication_narrow.vx_password_decode=0
calculation_publication_reuse.vx_password_decode=0
```

The direct linked password probe explains that decision. It checks 256 encoder
and 256 decoder inputs against an independent Python codec, including lowercase,
invalid, `NISHI` and `MSX2` inputs. Measurements cover the ordinary SDCC entry
through return with interrupts disabled; stack includes the return address and
excludes caller argument stores and result-reader calls. These are sampled
costs, not worst-case bounds.

| Result realization | Encoder mean / stack | Decoder mean / stack |
| --- | ---: | ---: |
| Previous wide, separate snapshots | 1,305.19 µs / 24 B | 6,602.52 µs / 65 B |
| Narrow, separate snapshots | 1,125.56 µs / 24 B | 6,175.32 µs / 71 B |
| Narrow, shared snapshots at the old frame allowance | 1,127.52 µs / 24 B | 6,185.94 µs / 72 B |
| Selected mixed realization with the larger frame allowance | 1,127.52 µs / 24 B | 6,602.52 µs / 65 B |

The encoder mean takes 13.6% less time, with every measured input improving and
unchanged stack.
The selected decoder fragment is byte-for-byte identical to the previous
realization. Its stack remains 65 bytes. Faster decoder alternatives are kept
as measurements, rather than silently accepting their stack increase.

`quest_local_frame_bytes` is now a 256-byte allowance. The complete image plans
201 bytes of exclusive static locals, including ordinary alternatives that the
game replaces with typed bindings. That number is not the linked allocation.
The full game actually uses 3,900 bytes of global RAM, down from 3,912, and
467,375 occupied ROM bytes, down from 468,688; its image remains 475,136 bytes.
All eligible ordinary foreground locals fit the allowance. Functions whose
activation proof requires automatic storage retain that policy. The shared
binding workspace remains 40 bytes.
An inventory against the linked listings also finds that every linked ordinary
function with a nonzero planned local frame uses fixed storage. Arguments,
results, SDCC spills and engine frames still contribute to the measured stack;
the three large automatic ordinary entry alternatives are not linked by this
embedding. Increasing this local allowance further would not remove those
other costs.

Canonical generation reproduces all 517 C/header/fragment files of the measured
`publication-balanced` candidate exactly, and its generation manifest checks.
The fresh host checks, Linux/MSX builds, all 57 full bindings across 63 linked
instances, complete quest/dialogue/scene smoke run, encounters, actor/world
profiles, title flow and password probe pass. The smoke scenario still observes
242 additional stack bytes, and its ghost timing is unchanged by this final
publication choice.

Reproduce the password measurement after building the game with:

```sh
python3 tests/profile_password.py build/vexel generated/quests build/password-profile
```

The output retains input vectors, expected byte images, the emulator script,
per-input costs and fingerprints of the ROM, layout, symbols, listings and
generation metadata. A failed invocation invalidates its previous result before
starting, so an old successful report cannot masquerade as the new measurement.

The bounded storage search retained its baseline binding choices. Enabling the
`player_view` output schedule changed its mean from 174.77 to 178.96 µs with the
same 2-byte stack; some inputs exceeded the allowed 2% slowdown, so it was
rejected. The next trial exhausted the overall search deadline during its smoke
run, and the remaining five alternatives were unmeasured. This is a bounded
selection result, not an optimum claim.

The later cache-assisted replay also measures separate scratch slots for
`player_view`. Full 256-input probes cover the smoke image's 54 full bindings
across 60 linked instances. Disabling its scratch reuse increases the frame
from 15 to 16 bytes, its mean from 174.77 to 234.36 µs, and observed helper stack
from 2 to 5 bytes. All value oracles pass; the other measured instances retain
their costs. The output-scheduling alternative repeats its earlier regression.
These measurements support retaining scratch reuse and disabling output
scheduling for this binding.
Both candidates also pass the complete comparative SDL/MSX gameplay scenario.
The final replay retains the baseline and passes its input-identity and artifact
checks; neither slower realization is adopted.

The C reference still runs the full-engine ghost callback faster: 1,707.87 µs
active / 415.19 µs skipped, compared with Vexel's 1,931.76 / 602.36 µs. These
figures include the trampoline and ISR and are not pure-body or whole-game
frame-time measurements. The scenario observes 240 additional reference stack
bytes versus Vexel's 242. This remains a concrete target for further work.

A smaller common payload allowance was also rejected. The byte-only password
encoder could use less space, but mixed-width player and world results still
need the existing 20-byte arena. Its declaration now refers to
`quest_payload_bytes` directly instead of repeating a literal in the annotation.
Choosing each source's encoding independently remains a separate optimization
opportunity; changing a shared hard cap is not equivalent to that choice.


The storage adapter now caches the validated C/reference profile separately
from each Vexel measurement. Changing the solver or pure-helper sample count can
reuse that profile; source files, the canonical generated directory, tools,
platform resources and environment still identify it. Every hit rechecks the
complete reference artifact tree and its previous scenario evidence. The new
candidate still runs the comparative SDL/MSX scenario. An edited or deleted
profile becomes a cache miss, and changing a cached directory field cannot
substitute an unvalidated project. `reference-cache.json` records whether a
search reused a profile; the cache lives below
`build/storage-optimization/reference-cache`.

The end-to-end cache trial built the initial reference profile in 198.8 seconds
using 276 guarded SDCC jobs. A second search changed the helper sample count
from 16 to 17, reused that exact profile and issued no reference compilation
commands. Both searches passed their fresh comparative gameplay scenarios and
target probes, and reproduced all 517 canonical code files. A changed `PATH`
correctly caused a separate cache miss; environment identity remains strict.

The SDCC guard retains the shared lock in the compiler child and supplies an
inherited kernel CPU backstop as well as its existing memory and wall limits.
A forcibly terminated build supervisor therefore cannot release the gate while
its compiler continues running. Resource logs distinguish queue waiting from
running time and CPU consumption; waiting behind another build does not count
as a compiler taking that long to optimize its input.
