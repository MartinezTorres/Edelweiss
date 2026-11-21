#!/usr/bin/env python3
"""Measure the real frame loop with four skeletons/four ghosts on MSX1."""
import argparse
import json
import os
from pathlib import Path
import re
import statistics
import subprocess

ROOT = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument("--build-root", default="build")
parser.add_argument("--msx-only", action="store_true")
args = parser.parse_args()
BUILD = ROOT / args.build_root
OUT = BUILD / "encounter"
OUT.mkdir(parents=True, exist_ok=True)
results = {}
snapshots = {}
for variant in ("reference", "vexel"):
    profile = BUILD / (variant + "-encounter")
    env = dict(os.environ, SDL_VIDEODRIVER="dummy", SDL_AUDIODRIVER="dummy",
               OPENMSX_USER_DATA=str(OUT / ("openmsx-" + variant)))
    if not args.msx_only:
        run = subprocess.run([str(profile / "linux/weiss")], cwd=ROOT, env=env,
                             capture_output=True, text=True, timeout=45)
        (OUT / (variant + "-linux.log")).write_text(run.stdout + run.stderr)
        assert run.returncode == 0 and "EDW_ENCOUNTER_OK" in run.stdout, run.stdout + run.stderr[-2000:]
    rom = profile / "msx/weiss.rom"
    symbols = {name: int(address, 16) for name, address in re.findall(
        r"(\w+): equ ([0-9A-Fa-f]+)h", Path(str(rom) + ".sym").read_text())}
    marker = symbols["_edw_encounter_marker"]
    error = symbols["_edw_encounter_error"]
    frame = symbols["_edw_encounter_frame"]
    entities = symbols["_edw_encounter_entities"]
    layout = symbols["_edw_encounter_layout"]
    checks = symbols["_edw_encounter_checks"]
    combat_checks = symbols["_edw_combat_checks"]
    melee_checks = symbols["_edw_melee_checks"]
    projectile_checks = symbols["_edw_projectile_checks"]
    actor_checks = symbols["_edw_actor_checks"]
    ball_hash = symbols["_edw_ball_hash"]
    player_hash = symbols["_edw_player_hash"]
    mapper = symbols["_mapper_current_segments"]
    resource_hook = ""
    resource_report = ""
    if variant == "vexel":
        resource_frame = symbols["_edw_resource_frame"]
        resource_vram = symbols["_edw_resource_vram"]
        resource_colors = symbols["_edw_resource_colors"]
        resource_absent_bank = symbols["_edw_resource_absent_bank"]
        resource_report = f'puts $f "resource_absent_bank=[debug read memory {resource_absent_bank}]"'
        resource_hook = rf"""
    if {{$mark == 6}} {{
        if {{[dict get $physical 3] != [debug read memory {resource_absent_bank}] || [debug read memory {mapper+3}] != [debug read memory {resource_absent_bank}]}} {{incr bank_errors}}
    }}
    if {{$mark == 7}} {{
        if {{[dict get $physical 3] != [debug read memory {resource_absent_bank}] || [debug read memory {mapper+3}] != [debug read memory {resource_absent_bank}]}} {{incr bank_errors}}
        set vram [expr {{[debug read memory {resource_vram}] | ([debug read memory {resource_vram+1}] << 8)}}]
        lappend resources [list [debug read memory {resource_frame}] [binary encode hex [debug read_block VRAM $vram 96]][binary encode hex [debug read_block memory {resource_colors} 2]]]
    }}
"""
    report = OUT / (variant + "-msx.txt")
    report.write_text("pending\n")
    script = OUT / (variant + ".tcl")
    script.write_text(rf"""
set speed 1000
set throttle on
set sound_driver null
set renderer SDL
set entry 0
set low 65535
set bank_checks 0
set bank_errors 0
set physical [dict create]
set baseline {{}}
set edw_samples {{}}
set edw_periods {{}}
set previous_start 0
set snapshots {{}}
set resources {{}}
set resource_phase 0
foreach {{address page}} {{0x7000 1 0x9000 2 0xb000 3}} {{
    debug set_watchpoint write_mem $address {{}} "dict set physical $page \$::wp_last_value"
}}
debug set_watchpoint write_mem {marker} {{}} {{
    set mark $::wp_last_value
    if {{$mark == 1}} {{
        set started [machine_info time]
        if {{$previous_start != 0}} {{lappend edw_periods [expr {{1e6*($started-$previous_start)}}]}}
        set previous_start $started
        if {{$entry == 0}} {{
            set entry [reg SP]
            set low $entry
            set baseline [debug read_block memory {mapper + 1} 3]
            debug set_watchpoint write_mem {{0xf104 0xf37f}} {{}} {{
                if {{!$resource_phase && $::wp_last_address < $low}} {{set low $::wp_last_address}}
            }}
        }}
    }}
    if {{$mark >= 1 && $mark <= 3}} {{
        incr bank_checks
        if {{[debug read_block memory {mapper + 1} 3] ne $baseline}} {{incr bank_errors}}
        foreach page {{1 2 3}} {{
            if {{![dict exists $physical $page] ||
                [dict get $physical $page] != [debug read memory [expr {{{mapper}+$page}}]]}} {{incr bank_errors}}
        }}
    }}
    if {{$mark == 2}} {{set body [machine_info time]}}
    if {{$mark == 3}} {{
        lappend edw_samples [list [expr {{1e6*([machine_info time]-$started)}}] [expr {{1e6*([machine_info time]-$body)}}]]
    }}
    if {{$mark == 5}} {{
        set blob {{}}
        for {{set k 0}} {{$k < 8}} {{incr k}} {{
            set pointer [expr {{[debug read memory [expr {{{entities}+2*$k}}]] |
                ([debug read memory [expr {{{entities}+2*$k+1}}]] << 8)}}]
            append blob [debug read_block memory [expr {{$pointer+[debug read memory {layout+1}]}}] 4]
            if {{$k < 4}} {{
                foreach offset {{{layout+3} {layout+4}}} {{
                    append blob [debug read_block memory [expr {{$pointer+[debug read memory $offset]}}] 1]
                }}
            }} else {{append blob [debug read_block memory [expr {{$pointer+[debug read memory {layout+2}]}}] 2]}}
            foreach offset {{{layout+5} {layout+6}}} {{
                append blob [debug read_block memory [expr {{$pointer+[debug read memory $offset]}}] 1]
            }}
        }}
        lappend snapshots [binary encode hex $blob]
        if {{[debug read memory {frame}] == 32}} {{screenshot -raw "{OUT}/{variant}.png"}}
    }}
    if {{$mark == 8}} {{set resource_phase 1}}
{resource_hook}
    if {{$mark == 4 || $mark == 128}} {{
        set f [open {{{report}}} w]
        puts $f "status=$mark"
        puts $f "error=[debug read memory {error}]"
        puts $f "checks=[debug read memory {checks}]"
        puts $f "combat_checks=[debug read memory {combat_checks}]"
        puts $f "melee_checks=[debug read memory {melee_checks}]"
        puts $f "projectile_checks=[debug read memory {projectile_checks}]"
        puts $f "actor_checks=[debug read memory {actor_checks}]"
        puts $f "ball_hash=[expr {{[debug read memory {ball_hash}] | ([debug read memory {ball_hash+1}] << 8)}}]"
        puts $f "player_hash=[expr {{[debug read memory {player_hash}] | ([debug read memory {player_hash+1}] << 8)}}]"
        if {{$mark == 128}} {{
            puts $f "failure_entities=[binary encode hex [debug read_block memory {entities} 16]]"
            puts $f "failure_layout=[binary encode hex [debug read_block memory {layout} 7]]"
        }}
        {resource_report}
        puts $f "frames=[debug read memory {frame}]"
        puts $f "bank_checks=$bank_checks"
        puts $f "bank_errors=$bank_errors"
        puts $f "entry_sp=$entry"
        puts $f "lowest_stack_write=$low"
        puts $f "additional_stack_bytes=[expr {{$entry-$low}}]"
        foreach sample $edw_samples {{puts $f "sample=$sample"}}
        foreach period $edw_periods {{puts $f "period=$period"}}
        foreach snapshot $snapshots {{puts $f "snapshot=$snapshot"}}
        foreach resource $resources {{puts $f "resource=$resource"}}
        close $f
        exit
    }}
}}
after time 30 {{
    set f [open {{{report}}} w]
    puts $f "timeout frame=[debug read memory {frame}] [cpuregs]"
    close $f
    exit
}}
after realtime 20 {{
    set f [open {{{report}}} w]
    puts $f "wall timeout time=[machine_info time] frame=[debug read memory {frame}] [cpuregs]"
    close $f
    exit
}}
""")
    run = subprocess.run(["openmsx", "-machine", "C-BIOS_MSX1", "-carta", str(rom),
                          "-romtype", "KonamiSCC", "-script", str(script)],
                         cwd=ROOT, env=env, capture_output=True, text=True, timeout=45)
    (OUT / (variant + "-msx.log")).write_text(run.stdout + run.stderr)
    data = report.read_text()
    assert run.returncode == 0 and "status=4\n" in data, data + run.stderr
    metrics = {k: int(v) for k, v in re.findall(r"^(\w+)=(\d+)$", data, re.M)}
    assert metrics["frames"] == 64 and metrics["checks"] == 15, metrics
    assert metrics["combat_checks"] == 15, metrics
    assert metrics["melee_checks"] == 15, metrics
    assert metrics["projectile_checks"] == 7, metrics
    assert metrics["actor_checks"] == 255, metrics
    assert metrics["bank_errors"] == 0 and metrics["bank_checks"] == 192, metrics
    if variant == "vexel":
        bindings = json.loads(Path(str(rom) + ".resources.json").read_text())
        assert all(f["segment"] != metrics["resource_absent_bank"] for f in bindings["frames"]), "Test requires an unrelated bank"
        assert {f["family"] for f in bindings["frames"]} == {"ghost", "skeleti", "melee_small", "melee_large", "arrow", "fire", "bomb", "spark", "explosion", "ball", "player", "drop", "fairy", "lumberjack"}
        asset_bytes = rom.read_bytes()
        actual = [(int(i), blob) for i, blob in re.findall(r"^resource=(\d+) ([0-9a-f]+)$", data, re.M)]
        expected = [(i, asset_bytes[f["rom_offset"]:f["rom_offset"]+98].hex())
                    for i, f in enumerate(bindings["frames"])]
        assert actual == expected, "Delayed resource upload differs from linked asset bytes"
        metrics["resource_frames_checked"] = len(actual)
    samples = [[float(x) for x in row.split()] for row in re.findall(r"^sample=(.+)$", data, re.M)]
    assert len(samples) == 64
    periods = [float(x) for x in re.findall(r"^period=(.+)$", data, re.M)]
    assert len(periods) == 63
    snapshots[variant] = re.findall(r"^snapshot=(.+)$", data, re.M)
    assert len(snapshots[variant]) == 64
    for name, subset in (("crowd", samples[:32]), ("combat", samples[32:])):
        metrics[name] = {"frame_mean_us": statistics.mean(row[0] for row in subset),
                         "frame_max_us": max(row[0] for row in subset),
                         "body_mean_us": statistics.mean(row[1] for row in subset)}
    metrics["samples_us"] = samples
    metrics["periods_us"] = periods
    metrics["crowd"]["loop_period_mean_us"] = statistics.mean(periods[:31])
    metrics["crowd"]["loop_period_max_us"] = max(periods[:31])
    metrics["memory"] = json.loads(Path(str(rom) + ".memory.json").read_text())
    results[variant] = metrics

# Combat timers intentionally use actual elapsed ISR ticks. Before combat,
# positions, velocities, routines, delays, health and slots must match exactly.
assert snapshots["reference"][:32] == snapshots["vexel"][:32], "Crowd decision traces differ"
for key in ("ball_hash", "player_hash"):
    assert results["reference"][key] == results["vexel"][key], (key, results["reference"][key], results["vexel"][key])
(OUT / "results.json").write_text(json.dumps(results, indent=2) + "\n")
for variant, result in results.items():
    print(f"{variant}: crowd frame {result['crowd']['frame_mean_us']:.1f} us mean, "
          f"{result['crowd']['frame_max_us']:.1f} us max; "
          f"additional stack {result['additional_stack_bytes']} bytes; banks restored")
print("Eight-enemy traces agree; real contact, weapon hit, death, explosion and drop passed")
print("Combat: Z80 hit directions, timer saturation, six-tick player slide, input lock and wall stops passed")
print("Melee: Z80 damage, colors, hit positions, all orientations/tick boundaries, sprite choices and expiration passed")
print("Passive actors: pickup expiry, all fairy phases, follower facing and sprite lifetimes passed")
print("Sprite resources: all families' delayed frames match ROM patterns/colors with the asset bank initially absent")
print("Projectiles: Z80 launch, wrapping motion, animation, bomb timing and covered-door destruction passed")

print("Actors: shared effects timeline and ball/player real-map matrices agree on Z80")
