#!/usr/bin/env python3
"""Run both full-engine quest profiles on SDL and openMSX without a display."""
import json
import argparse
import os
from pathlib import Path
import re
import struct
import subprocess
import zlib

ROOT = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("--build-root", default="build")
BUILD = ROOT / parser.parse_args().build_root
OUTPUT = BUILD / "smoke"
OUTPUT.mkdir(parents=True, exist_ok=True)
results = {}


def png_image(path):
    # Same renderer/encoder on both sides. Compare image data rather than the
    # PNG's creation-time text. Identical filters + samples imply identical pixels.
    data = path.read_bytes()
    assert data[:8] == b"\x89PNG\r\n\x1a\n", f"Missing screenshot: {path}"
    offset, compressed, layout = 8, bytearray(), []
    while offset < len(data):
        size = struct.unpack_from(">I", data, offset)[0]
        kind = data[offset + 4:offset + 8]
        payload = data[offset + 8:offset + 8 + size]
        if kind == b"IDAT":
            compressed.extend(payload)
        elif kind in (b"IHDR", b"PLTE", b"tRNS"):
            layout.append((kind, payload))
        offset += size + 12
    return layout, zlib.decompress(compressed)

for variant in ("reference", "vexel"):
    profile = BUILD / (variant + "-smoke")
    env = dict(os.environ, SDL_VIDEODRIVER="dummy", SDL_AUDIODRIVER="dummy",
               OPENMSX_USER_DATA=str(OUTPUT / ("openmsx-" + variant)))
    host = subprocess.run([str(profile / "linux/weiss")], cwd=ROOT, env=env,
                          capture_output=True, text=True, timeout=30)
    (OUTPUT / (variant + "-linux.log")).write_text(host.stdout + host.stderr)
    assert host.returncode == 0 and "EDW_SMOKE_OK" in host.stdout, host.stdout + host.stderr
    rom = profile / "msx/weiss.rom"
    symbols = {name: int(address, 16) for name, address in re.findall(
        r"(\w+): equ ([0-9A-Fa-f]+)h", Path(str(rom) + ".sym").read_text())}
    status = symbols["_edw_smoke_status"]
    messages = symbols["_edw_smoke_messages"]
    report = OUTPUT / (variant + "-msx.txt")
    # A failed rerun must not consume a previous success report.
    report.write_text("pending\n")
    for i in (1, 2, 3):
        (OUTPUT / f"{variant}-dialogue-{i}.png").write_bytes(b"")
    script = OUTPUT / (variant + "-quest.tcl")
    script.write_text(f"""set throttle on
set speed 100
set maxframeskip 0
set renderer SDL
set low 65535
set entry 0
set started 0
set count 0
set background_ok 1
proc check_background {{}} {{
    global background_ok
    if {{([debug read {{VDP regs}} 7] & 15) != 1 ||
         ([debug read memory 0xf3e6] & 15) != 1}} {{
        set background_ok 0
    }}
}}
debug set_watchpoint write_mem {status} {{}} {{
    if {{$::wp_last_value != 0}} {{check_background}}
    if {{$::wp_last_value == 1}} {{
        set started [machine_info time]
        set entry [reg SP]
        set low $entry
        debug set_watchpoint write_mem {{0xf104 0xf37f}} {{}} {{
            if {{$::wp_last_address < $low}} {{set low $::wp_last_address}}
        }}
    }}
    if {{$::wp_last_value == 3 || $::wp_last_value == 128}} {{
        set f [open {{{report}}} w]
        puts $f "status=$::wp_last_value"
        puts $f "dialogues=$count"
        puts $f "background_ok=$background_ok"
        puts $f "elapsed_seconds=[expr {{[machine_info time] - $started}}]"
        puts $f "entry_sp=$entry"
        puts $f "lowest_stack_write=$low"
        puts $f "additional_stack_bytes=[expr {{$entry - $low}}]"
        close $f
        exit
    }}
}}
debug set_watchpoint write_mem {messages} {{}} {{
    set count $::wp_last_value
    if {{$count > 0 && $count <= 3}} {{
        check_background
        screenshot -raw "{OUTPUT}/{variant}-dialogue-$count.png"
    }}
}}
after time 40 {{
    set f [open {{{report}}} w]
    puts $f "timeout: [cpuregs]"
    close $f
    exit
}}
""")
    result = subprocess.run(["openmsx", "-machine", "C-BIOS_MSX1", "-carta", str(rom),
                             "-romtype", "KonamiSCC", "-script", str(script)],
                            cwd=ROOT, env=env, capture_output=True, text=True, timeout=45)
    (OUTPUT / (variant + "-msx.log")).write_text(result.stdout + result.stderr)
    data = report.read_text()
    assert result.returncode == 0 and "status=3\n" in data, data + result.stderr
    values = dict(line.split("=", 1) for line in data.splitlines())
    assert values["dialogues"] == "3", values
    assert values["background_ok"] == "1", "Game background must remain black: " + str(values)
    results[variant] = values
    print(f"{variant}: SDL and MSX full-engine quest passed; "
          f"{values['additional_stack_bytes']} additional stack bytes observed")

for i in (1, 2, 3):
    reference = OUTPUT / f"reference-dialogue-{i}.png"
    vexel = OUTPUT / f"vexel-dialogue-{i}.png"
    assert reference.stat().st_size > 1000, "Missing/blank dialogue screenshot"
    assert png_image(reference) == png_image(vexel), f"Dialogue {i} rendering differs"
(OUTPUT / "results.json").write_text(json.dumps(results, indent=2) + "\n")
print("All three MSX dialogue captures match the reference")
