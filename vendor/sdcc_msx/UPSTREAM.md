This is the runtime/header subset and module linker from Manuel Martinez's
[`sdcc_msx`](https://github.com/MartinezTorres/sdcc_msx), revision
`0948ce6584bb99b3d3187be2bc8c5e6f5d93fefb`.
The accompanying LICENSE is unchanged.

The supplied Edelweiss checkout already had `#include <cstdint>` added to
`util/module_linker.cc`; this copy preserves it. The original `sdcc_msx`
working directory is left untouched. The historical repository records that
path as a symlink to `../../sdcc_msx`, rather than as a pinned submodule.

Edelweiss changes to this copy:

- Reject resident ROM overflow before bank allocation, and reject ordinary
  RAM that overlaps the game's fixed map at `0xD000`.
- Read both XL2 and XL3 ASxxxx objects, contracting byte relocation fields
  according to the object address width. Z80 instructions retain 16-bit addresses.
- Reject nonempty `_HOME` sections in banked modules; the legacy packer cannot
  place them. Emit a `.memory.json` report alongside the maps and symbols.
- Name the SDL window Edelweiss and fall back to its software renderer when
  acceleration is unavailable (including the dummy driver used by smoke tests).
