#!/usr/bin/env python3
"""Compare production title rendering and cancellation on the real Z80 path."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess

ROOT = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--build-root', default='build')
parser.add_argument('--variant', choices=('reference', 'vexel'))
args = parser.parse_args()
build = ROOT / args.build_root
out = build / 'title'
out.mkdir(parents=True, exist_ok=True)
results = {}
for variant in ((args.variant,) if args.variant else ('reference', 'vexel')):
    profile = build / variant
    rom = profile / 'msx/weiss.rom'
    symbols = {n: int(a, 16) for n, a in re.findall(
        r'(\w+): equ ([0-9A-Fa-f]+)h', Path(str(rom)+'.sym').read_text())}
    modules = json.loads(Path(str(rom)+'.layout.json').read_text())['modules']
    module = next((m for m in modules if m['name'] == 'title_sequence'), None)
    module = module or next(m for m in modules if m['name'] == 'main')
    code_area = next(a for a in module['areas'] if a['name'] == '_CODE')
    listing = (profile / ('msx/src/gameplay/title_sequence.lst' if module['name'] == 'title_sequence'
                           else 'msx/src/main.lst')).read_text()
    title_entry = code_area['address'] + int(re.search(
        r'^\s+([0-9A-F]{6})\s+\d+ _title_routine:', listing, re.M)[1], 16)
    wait = code_area['address'] + int(re.search(
        r'^\s+([0-9A-F]{6})\s+\d+ _title_wait_frame:', listing, re.M)[1], 16)
    mapper = symbols['_mapper_current_segments'] + module['page']
    cases = {}
    for skip in (1, 100, 250, 0):
        name = f'{variant}-{skip}'
        report = out / (name+'.txt')
        report.write_text('pending\n')
        vram = out / (name+'.vram')
        script = out / (name+'.tcl')
        script.write_text(f'''set throttle on
set speed 1000
set renderer SDL
set waits 0
set active 0
set low 65535
debug set_watchpoint write_mem {{0xf104 0xf37f}} {{}} {{
    if {{$active && $::wp_last_address < $low}} {{set low $::wp_last_address}}
}}
debug set_bp {title_entry} {{!$active && [debug read memory {mapper}] == {module['segment']}}} {{
    set active 1
    set entry [reg SP]
    set low $entry
    set started [machine_info time]
    set ret [expr {{[debug read memory $entry] | ([debug read memory [expr {{$entry+1}}]] << 8)}}]
    debug set_bp $ret [format {{[reg SP] == %d}} [expr {{$entry+2}}]] {{
        set f [open {{{vram}}} wb]
        puts -nonewline $f [debug read_block VRAM 0 16384]
        close $f
        screenshot -raw {{{out / (name+'.png')}}}
        set f [open {{{report}}} w]
        puts $f "waits=$waits"
        puts $f "attract=[debug read memory {symbols['_configuration']}]"
        puts $f "border=[expr {{[debug read {{VDP regs}} 7] & 15}}]"
        puts $f "display=[expr {{([debug read {{VDP regs}} 1] >> 6) & 1}}]"
        puts $f "stack=[expr {{$entry-$low}}]"
        puts $f "seconds=[expr {{[machine_info time]-$started}}]"
        close $f
        exit
    }}
}}
debug set_bp {wait} {{$active && [debug read memory {mapper}] == {module['segment']}}} {{
    incr waits
    if {{{skip} != 0 && $waits == {skip}}} {{keymatrixdown 8 1}}
}}
after time 100 {{exit}}
after realtime 65 {{exit}}
''')
        env = dict(os.environ, SDL_VIDEODRIVER='dummy', SDL_AUDIODRIVER='dummy',
                   OPENMSX_USER_DATA=str(out/('openmsx-'+name)))
        with (out/(name+'.log')).open('w') as log:
            run = subprocess.run(['openmsx', '-machine', 'C-BIOS_MSX1', '-carta', str(rom),
                '-romtype', 'KonamiSCC', '-script', str(script)], env=env, cwd=ROOT,
                stdout=log, stderr=subprocess.STDOUT, timeout=75)
        lines = report.read_text().splitlines()
        assert run.returncode == 0 and lines and lines[0] != 'pending', (name, (out/(name+'.log')).read_text())
        values = dict(line.split('=', 1) for line in lines)
        row = {k: float(v) if k == 'seconds' else int(v) for k, v in values.items()}
        assert row['attract'] == (0 if skip else 9), (name, row)
        assert row['waits'] == skip if skip else row['waits'] > 1000, (name, row)
        pixels = vram.read_bytes()
        row['vram_sha256'] = hashlib.sha256(pixels).hexdigest()
        # Spark cadence follows the physical clock. Even the pre-migration
        # Vexel ROM differs from C there as callback costs cross frame edges.
        # Compare all background patterns/colors/name tables exactly; retain
        # the complete capture and hash for inspecting the sprite layer.
        row['background_sha256'] = hashlib.sha256(pixels[:0x1f00]+pixels[0x2000:0x3800]).hexdigest()
        cases[str(skip)] = row
        print(name, row, flush=True)
    results[variant] = {'rom_sha256': hashlib.sha256(rom.read_bytes()).hexdigest(), 'cases': cases}

if not args.variant:
    for skip, reference in results['reference']['cases'].items():
        actual = results['vexel']['cases'][skip]
        for key in ('waits', 'attract', 'border', 'display', 'background_sha256'):
            assert reference[key] == actual[key], (skip, key, reference[key], actual[key])
(out/((args.variant+'-results.json') if args.variant else 'results.json')).write_text(json.dumps(results, indent=2)+'\n')
print('Title: production presentation and phase skips passed on Z80')
