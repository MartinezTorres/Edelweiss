# Vexel gameplay integration

This migration starts from Edelweiss `fecb997` and the supplied `sdcc_msx`
checkout. The playable lumberjack milestone is committed as `f2b5fdc`.
The integration now implements the lumberjack conversation, following decision,
axe reward, pear exchange, Fish'n'Ships, university, Food'n'Stuff, saloon
passwords, world interactions, pickup/drop rules, town dispatch/content and
ghost behaviour while keeping the C branches for comparison.
The original local library edit and untracked files are left untouched.

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

`gameplay/quests.vx` imports all twenty-one source entry points with an explicit 20-byte payload
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
velocities at 8 bits. A bias before an arithmetic shift expresses signed
division by 512 towards zero without a general division helper.

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
Ghost rules and their materialized velocity helper live in the ghost page-C
callback bank, avoiding a bank switch on each update. `vx_ghost_math.h`
expands signed interpretation at the emitted 8/16-bit widths and checked shifts
with their constant parameters. It uses unsigned arithmetic and a sign bias,
avoiding negative C shifts and signed overflow. Each value operand is evaluated
once. SDCC folds the widths/counts instead of calling generic arithmetic
helpers repeatedly; the generated rule bodies remain unchanged. Unsupported
signed widths fail to compile and require a placement/runtime review. The
standalone projection harness retains the portable arithmetic helpers.
All sources reuse the 20-byte result arena.

The generator retains the complete portable `vx_bridges.c` and also packages
its unchanged function bodies into `vx_quests.inc`, `vx_services.inc` and
`vx_password.inc`, `vx_password_encode.inc`, `vx_world.inc`, `vx_drops.inc`,
`vx_town.inc` and `vx_ghost.inc`. It checks the source order and nine helper
specializations. Helpers are grouped by their reported source ownership;
adding the ghost helper can renumber password helpers without changing their
placement. Unexpected ownership or counts fail generation for review.
The four explicit `&~` helpers in `password.vx` keep normalization, byte decoding,
checksum calculation and validation from expanding repeatedly into every result
field. Constant arguments produce eight specialized C functions. All of them
are placed with their password callers; ownership is checked against the plan
before splitting. The eight-byte checksum has different specializations for
encoding and decoding, so neither calls the other's bank.
All parts are hashed and compiled by the normal build. This is the small
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

With town interactions and the ghost migrated, production costs are:

| Measurement | Corrected C reference | Vexel gameplay |
|---|---:|---:|
| Cartridge size | 434,176 bytes | 458,752 bytes |
| Occupied ROM, excluding bank padding | 426,692 bytes | 455,233 bytes |
| Ordinary global RAM | 3,774 bytes | 3,795 bytes |
| Space before fixed map at `0xD000` | 322 bytes | 301 bytes |
| Resident ROM end (exclusive) | `0x5EBD` | `0x5ECB` |

The town-rule bank uses 4,951 bytes, the ghost callback/rules bank 3,330 bytes,
and the text bank 2,809 bytes. Global RAM and resident ROM remain unchanged.
The smoke profile adds 40 RAM bytes per variant for inputs and reports.

An active ghost callback averages 1.84 ms in C and 5.24 ms with the Vexel
projection; a skipped tick averages 0.55 and 1.48 ms. The first generic-runtime
version took 60.97 ms per active callback, so constant-width arithmetic
specialization is necessary here. The remaining overhead is material:
5.24 ms is about 31% of a 60 Hz frame budget, although an individual ghost
updates its movement only once every four game cycles. This is not a whole-game
frame-rate measurement. Broader enemy migration should include further emitter/
ABI optimization and profiling with multiple active enemies.

The complete 67-capture scenario takes 133.4455 emulated seconds for C and
134.4952 for Vexel, including all display waits and scrolling. Additional
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

The optimized renderer, audio and assembly implementations are unchanged.

## What this establishes, and what remains

This is a working route for moving decisions into Vexel while retaining the
engine and both targets. It provides a concrete resource-lifetime boundary
where banked text can no longer escape into gameplay as a raw address.

Combat, other enemies, weapon behaviour and obstacle changes remain C.
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
