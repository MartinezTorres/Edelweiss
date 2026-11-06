# Vexel gameplay integration

This migration starts from Edelweiss `fecb997` and the supplied `sdcc_msx`
checkout. The playable lumberjack milestone is committed as `f2b5fdc`.
The integration now implements the lumberjack conversation, following decision,
axe reward and town-hall pear exchange while keeping the C branches for comparison.
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

The output is `(phase, command, text ID)`, occupying three bytes in the shared
payload arena. `quest_interact` reads all leaves before applying any effect.
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

`gameplay/quests.vx` imports both sources with an explicit five-byte payload
budget. Their serial projections share offset zero: three bytes for lumberjack,
five for pear, five total. The engine finishes consuming one invocation before
starting another; no caller relies on a particular ordering of the two quests.
Both use the same text buffer described below.

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

## Execution and placement

The portable Vexel projection and its adapter compile together into the `quest`
page-C module. NPC and town-hall modules enter through the existing resident
page-C trampoline, which restores their mapping before returning. The text
copy runs in page D; popup and infobar code run in page B.

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
hashes of all three source files and generated artifact hashes. No compiler
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
compares three full lumberjack images and nine pear popup renderings. For the
pear captures, it compares the popup's VRAM patterns, colors and placement in
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

The optimized renderer, audio and assembly implementations are unchanged.

## What this establishes, and what remains

This is a working route for moving decisions into Vexel while retaining the
engine and both targets. It provides a concrete resource-lifetime boundary
where banked text can no longer escape into gameplay as a raw address.

Most gameplay is still C. These two interactions establish that relevant state
and small typed results also handle choice-dependent inventory effects with
the same adapter and owned text storage. Another shop or conversation can use
this boundary without a generic VM. Suspending scenes across ordinary gameplay
frames would still require an explicit continuation design.
Asset IDs do not yet cover all sprite/audio/map consumers, and the legacy
engine's other pointer lifetimes remain its responsibility.

NEO-8 and the newer megalinker are separate backend work: the current renderer
contains mapper register writes and layout assumptions specific to Konami-5.
This first comparison intentionally retains those assumptions. There is no
RAM mapper, new heap, LLM optimization loop, or general engine scheduler added
by this slice.
