#!/usr/bin/env python3
"""Small object-format and layout checks for the legacy Konami linker."""
from pathlib import Path
import subprocess
import sys

ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build/tests/linker"
BUILD.mkdir(parents=True, exist_ok=True)
LINKER = Path(sys.argv[1]).resolve()


def fixture(width, name, code_size=8, data_size=4, banked_home=False):
    # Header plus LD HL,data; LD A,<data; LD B,>data; RET. ASxxxx stores
    # a byte relocation in a width-byte field and then contracts it to one.
    word = lambda n: " ".join(f"{(n >> (8*i)) & 255:02X}" for i in range(width))
    object_file = BUILD / (name + ".rel")
    extra = "S _MAPPER_MODULE_fixture_PAGE_C Ref000000\n" if banked_home else ""
    object_file.write_text(
        f"XL{width}\nH 3 areas 1 global symbols\nM fixture\n{extra}"
        "A _HEADER0 size 10 flags 8 addr 4000\n"
        f"A _CODE size {code_size:X} flags 0 addr 0\n"
        f"A _DATA size {data_size:X} flags 0 addr 0\n"
        "S _data Def000000\n"
        + ("A _HOME size 1 flags 0 addr 0\n" if banked_home else "")
        + f"T {word(0x4000)}\nR 00 00 00 00\n"
        f"T {word(0x4000)} 41 42\nR 00 00 00 00\n"
        f"T {word(0)}\nR 00 00 01 00\n"
        f"T {word(0)} 21 00 00 3E {word(0)} 06 {word(0)} C9\n"
        f"R 00 00 01 00 00 {width+1:02X} 02 00 "
        f"09 {width+4:02X} 02 00 89 {2*width+5:02X} 02 00\n")
    rom = BUILD / (name + ".rom")
    result = subprocess.run([str(LINKER), str(object_file), str(rom)],
                            capture_output=True, text=True)
    return rom, result


for width in (2, 3):
    rom, result = fixture(width, f"xl{width}")
    assert result.returncode == 0, result.stderr
    assert rom.read_bytes()[16:24] == bytes.fromhex("21 00 C0 3E 00 06 C0 C9")
for name, options, message in (
    ("ram-overflow", {"data_size": 4097}, "Globals overlap"),
    ("rom-overflow", {"code_size": 8192}, "Resident ROM exceeds"),
    ("banked-home", {"banked_home": True}, "unplaceable _HOME"),
):
    rom, result = fixture(3, name, **options)
    assert result.returncode != 0 and message in result.stderr, result.stderr
print("linker: XL2/XL3 word/byte relocations and ROM/RAM/section guards passed")
