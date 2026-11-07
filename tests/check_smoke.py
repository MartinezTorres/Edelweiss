#!/usr/bin/env python3
"""Run both full-engine quest profiles on SDL and openMSX without a display."""
import json
import argparse
import os
from pathlib import Path
import re
import subprocess

ROOT = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("--build-root", default="build")
BUILD = ROOT / parser.parse_args().build_root
OUTPUT = BUILD / "smoke"
OUTPUT.mkdir(parents=True, exist_ok=True)
results = {}


def popup_image(path):
    # Compare the actual 88x32 popup patterns/colors and its placement in both
    # name tables. The surrounding world keeps animating at different phases.
    data = path.read_bytes()
    assert len(data) == 960, f"Incomplete popup capture: {path}"
    columns = []
    for table in range(2):
        for row in range(4):
            start = 704 + table * 128 + row * 32
            tiles = bytes(range(10 + row % 2, 32, 2))
            column = data[start:start + 32].find(tiles)
            assert column >= 0, f"Popup is not visible in name table: {path}"
            columns.append(column)
    assert len(set(columns)) == 1, f"Misaligned popup: {path}"
    return data[:704], columns


def small_popup_image(path):
    data = path.read_bytes()
    assert len(data) == 848, f"Incomplete small popup capture: {path}"
    positions = []
    for table in range(2):
        names = data[336 + table * 256:592 + table * 256]
        position = names.find(bytes(range(10, 31, 3)))
        assert position >= 0 and position % 32 <= 25, f"Small popup missing: {path}"
        for row in (1, 2):
            assert names[position + row * 32:position + row * 32 + 7] == bytes(range(10 + row, 31, 3)), path
        positions.append(position)
    assert positions[0] == positions[1], f"Small popup buffers disagree: {path}"
    return data[:336], positions

for variant in ("reference", "vexel"):
    profile = BUILD / (variant + "-smoke")
    env = dict(os.environ, SDL_VIDEODRIVER="dummy", SDL_AUDIODRIVER="dummy",
               OPENMSX_USER_DATA=str(OUTPUT / ("openmsx-" + variant)))
    host = subprocess.run([str(profile / "linux/weiss")], cwd=ROOT, env=env,
                          capture_output=True, text=True, timeout=180)
    (OUTPUT / (variant + "-linux.log")).write_text(host.stdout + host.stderr)
    assert host.returncode == 0 and "EDW_SMOKE_OK" in host.stdout, host.stdout + host.stderr
    rom = profile / "msx/weiss.rom"
    symbols = {name: int(address, 16) for name, address in re.findall(
        r"(\w+): equ ([0-9A-Fa-f]+)h", Path(str(rom) + ".sym").read_text())}
    status = symbols["_edw_smoke_status"]
    messages = symbols["_edw_smoke_messages"]
    capture = symbols["_edw_smoke_capture"]
    small_messages = symbols["_edw_smoke_small_messages"]
    world_stage = symbols["_edw_smoke_world_stage"]
    report = OUTPUT / (variant + "-msx.txt")
    # A failed rerun must not consume a previous success report.
    report.write_text("pending\n")
    for i in (1, 2, 3):
        (OUTPUT / f"{variant}-dialogue-{i}.png").write_bytes(b"")
        (OUTPUT / f"{variant}-dialogue-{i}.bin").write_bytes(b"")
    for i in range(1, 10):
        (OUTPUT / f"{variant}-pear-{i}.png").write_bytes(b"")
        (OUTPUT / f"{variant}-pear-{i}.bin").write_bytes(b"")
        (OUTPUT / f"{variant}-world-{i}.png").write_bytes(b"")
        (OUTPUT / f"{variant}-world-{i}.bin").write_bytes(b"")
    for i in (*range(20, 49), *range(50, 60)):
        (OUTPUT / f"{variant}-service-{i}.png").write_bytes(b"")
        (OUTPUT / f"{variant}-service-{i}.bin").write_bytes(b"")
    script = OUTPUT / (variant + "-quest.tcl")
    script.write_text(f"""set throttle on
set speed 100
set maxframeskip 0
set renderer SDL
set low 65535
set entry 0
set started 0
set count 0
set pear 0
set closed 0
set restored 1
set map_tiles {{}}
set background_ok 1
set health_restored 1
set small_count 0
set world_tiles {{}}
set world_restored 0
proc check_background {{}} {{
    global background_ok
    if {{([debug read {{VDP regs}} 7] & 15) != 1 ||
         ([debug read memory 0xf3e6] & 15) != 1}} {{
        set background_ok 0
    }}
}}
proc capture_popup {{base}} {{
    screenshot -raw "$base.png"
    set f [open "$base.bin" wb]
    foreach address {{0x0050 0x0850 0x2050 0x2850}} {{
        puts -nonewline $f [debug read_block VRAM $address 176]
    }}
    foreach address {{0x18c0 0x1cc0}} {{
        puts -nonewline $f [debug read_block VRAM $address 128]
    }}
    close $f
}}
proc capture_small_popup {{base}} {{
    screenshot -raw "$base.png"
    set f [open "$base.bin" wb]
    foreach address {{0x0850 0x2850}} {{
        puts -nonewline $f [debug read_block VRAM $address 168]
    }}
    foreach address {{0x1900 0x1d00}} {{
        puts -nonewline $f [debug read_block VRAM $address 256]
    }}
    close $f
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
        puts $f "pear_captures=$pear"
        puts $f "menus_closed=$closed"
        puts $f "map_restored=$restored"
        puts $f "background_ok=$background_ok"
        puts $f "health_restored=$health_restored"
        puts $f "small_messages=$small_count"
        puts $f "world_stage=[debug read memory {world_stage}]"
        puts $f "world_map_restored=$world_restored"
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
        capture_popup "{OUTPUT}/{variant}-dialogue-$count"
    }}
}}
debug set_watchpoint write_mem {small_messages} {{}} {{
    set small_count $::wp_last_value
    if {{$small_count > 0 && $small_count <= 9}} {{
        check_background
        capture_small_popup "{OUTPUT}/{variant}-world-$small_count"
    }}
}}
debug set_watchpoint write_mem {capture} {{}} {{
    set checkpoint $::wp_last_value
    if {{$checkpoint == 60}} {{
        set world_tiles [debug read_block VRAM 0x1800 704][debug read_block VRAM 0x1c00 704]
    }} elseif {{$checkpoint == 61}} {{
        set actual [debug read_block VRAM 0x1800 704][debug read_block VRAM 0x1c00 704]
        set world_restored [expr {{$world_tiles ne {{}} && $actual eq $world_tiles}}]
        screenshot -raw "{OUTPUT}/{variant}-world-closed.png"
    }}
    if {{$checkpoint == 53}} {{
        foreach {{address tile}} {{0x1ad6 10 0x1ed6 14}} {{
            for {{set i 0}} {{$i < 10}} {{incr i}} {{
                set expected [expr {{$i < 3 ? $tile : 0}}]
                if {{[debug read VRAM [expr {{$address+$i}}]] != $expected ||
                    [debug read VRAM [expr {{$address+32+$i}}]] != 0}} {{set health_restored 0}}
            }}
        }}
    }}
    if {{$checkpoint == 10}} {{
        set map_tiles [debug read_block VRAM 0x18c0 128][debug read_block VRAM 0x1cc0 128]
    }} elseif {{$checkpoint == 11}} {{
        incr closed
        set actual [debug read_block VRAM 0x18c0 128][debug read_block VRAM 0x1cc0 128]
        if {{$map_tiles eq {{}} || $actual ne $map_tiles}} {{set restored 0}}
        screenshot -raw "{OUTPUT}/{variant}-closed-$closed.png"
    }} elseif {{($checkpoint > 0 && $checkpoint <= 9) || ($checkpoint >= 20 && $checkpoint <= 59 && $checkpoint != 49)}} {{
        if {{$checkpoint <= 9}} {{set pear $checkpoint; set kind pear}} else {{set kind service}}
        check_background
        capture_popup "{OUTPUT}/{variant}-$kind-$checkpoint"
    }}
}}
after time 180 {{
    set f [open {{{report}}} w]
    puts $f "timeout: world_stage=[debug read memory {world_stage}] [cpuregs]"
    close $f
    exit
}}
""")
    result = subprocess.run(["openmsx", "-machine", "C-BIOS_MSX1", "-carta", str(rom),
                             "-romtype", "KonamiSCC", "-script", str(script)],
                            cwd=ROOT, env=env, capture_output=True, text=True, timeout=190)
    (OUTPUT / (variant + "-msx.log")).write_text(result.stdout + result.stderr)
    data = report.read_text()
    assert result.returncode == 0 and "status=3\n" in data, data + result.stderr
    values = dict(line.split("=", 1) for line in data.splitlines())
    assert values["dialogues"] == "3", values
    assert values["pear_captures"] == "9", values
    assert values["menus_closed"] == "24" and values["map_restored"] == "1", \
        "Door exit must restore both map buffers without scrolling: " + str(values)
    assert values["background_ok"] == "1", "Game background must remain black: " + str(values)
    assert values["health_restored"] == "1", "Restored hearts must replace both old health rows: " + str(values)
    assert values["small_messages"] == "9" and values["world_stage"] == "9", values
    assert values["world_map_restored"] == "1", "Small dialogue must restore both map buffers: " + str(values)
    results[variant] = values
    print(f"{variant}: SDL and MSX full-engine quest passed; "
          f"{values['additional_stack_bytes']} additional stack bytes observed")

for i in (1, 2, 3):
    reference = OUTPUT / f"reference-dialogue-{i}.png"
    vexel = OUTPUT / f"vexel-dialogue-{i}.png"
    assert reference.stat().st_size > 1000, "Missing/blank dialogue screenshot"
    assert popup_image(reference.with_suffix(".bin")) == popup_image(vexel.with_suffix(".bin")), \
        f"Dialogue {i} rendering/placement differs"
for i in range(1, 10):
    reference = OUTPUT / f"reference-pear-{i}.png"
    vexel = OUTPUT / f"vexel-pear-{i}.png"
    assert reference.stat().st_size > 1000, "Missing/blank pear screenshot"
    assert popup_image(reference.with_suffix(".bin")) == popup_image(vexel.with_suffix(".bin")), \
        f"Pear capture {i} rendering/placement differs"
for i in (*range(20, 49), *range(50, 60)):
    reference = OUTPUT / f"reference-service-{i}.bin"
    vexel = OUTPUT / f"vexel-service-{i}.bin"
    assert popup_image(reference) == popup_image(vexel), f"Service capture {i} rendering/placement differs"
for i in range(1, 10):
    reference = OUTPUT / f"reference-world-{i}.bin"
    vexel = OUTPUT / f"vexel-world-{i}.bin"
    assert small_popup_image(reference) == small_popup_image(vexel), f"World capture {i} rendering/placement differs"
(OUTPUT / "results.json").write_text(json.dumps(results, indent=2) + "\n")
print("Three lumberjack and nine pear popup renderings/placements match the reference")
print("39 service/password popup renderings/placements match; all 24 building exits restore both map buffers")
print("Nine world popups match; lamp/password travel, wells, passages, boots and pickups pass on SDL and MSX")
