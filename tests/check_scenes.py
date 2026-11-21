#!/usr/bin/env python3
"""Run the real intro/death on SDL and Z80; record scene and scheduler costs."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import statistics
import subprocess

ROOT = Path(__file__).resolve().parents[1]
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--build-root', default='build')
parser.add_argument('--msx-only', action='store_true')
parser.add_argument('--variant', choices=('reference', 'vexel'))
args = parser.parse_args()
build = ROOT / args.build_root
out = build / 'scenes'
out.mkdir(parents=True, exist_ok=True)
results = {}
for variant in ((args.variant,) if args.variant else ('reference', 'vexel')):
    profile = build / (variant + '-smoke')
    env = dict(os.environ, SDL_VIDEODRIVER='dummy', SDL_AUDIODRIVER='dummy', EDW_SCENES='1',
               OPENMSX_USER_DATA=str(out / ('openmsx-' + variant)))
    host = None
    if not args.msx_only:
        run = subprocess.run([str(profile / 'linux/weiss')], env=env, cwd=ROOT,
                             capture_output=True, text=True, timeout=90)
        (out / (variant + '-linux.log')).write_text(run.stdout + run.stderr)
        match = re.search(r'EDW_SCENES_OK: ticks=(\d+) hash=(\d+)', run.stdout)
        assert run.returncode == 0 and match, run.stderr[-2000:]
        host = list(map(int, match.groups()))
    rom = profile / 'msx/weiss.rom'
    symbols = {n: int(a, 16) for n, a in re.findall(
        r'(\w+): equ ([0-9A-Fa-f]+)h', Path(str(rom) + '.sym').read_text())}
    modules = json.loads(Path(str(rom) + '.layout.json').read_text())['modules']
    report = out / (variant + '-msx.txt')
    report.write_text('pending\n')
    code = '''set throttle on
set speed 1000
set renderer SDL
set phase 0
set low 65535
set scene_samples {}
set scene_large {}
set scene_small {}
array set active {intro 0 world 0}
array set started {}
array set entry {}
array set clow {}
array set return_bp {}
debug set_watchpoint write_mem {0xf000 0xf37f} {} {
    if {$phase && $::wp_last_address < $low} {set low $::wp_last_address}
    foreach name {intro world} {
        if {$active($name) && $::wp_last_address < $clow($name)} {set clow($name) $::wp_last_address}
    }
}
proc complete {name} {
    global active started entry clow scene_samples return_bp
    lappend scene_samples [list $name [expr {1e6*([machine_info time]-$started($name))}] [expr {$entry($name)-$clow($name)}]]
    set active($name) 0
    debug remove_bp $return_bp($name)
}
proc begin {name} {
    global active started entry clow return_bp
    set active($name) 1
    set entry($name) [reg SP]
    set clow($name) $entry($name)
    set started($name) [machine_info time]
    set ret [expr {[debug read memory [reg SP]] | ([debug read memory [expr {[reg SP]+1}]] << 8)}]
    set return_bp($name) [debug set_bp $ret [format {[reg SP] == %d} [expr {[reg SP]+2}]] "complete $name"]
}
'''
    for label, module_name, path, function, page in [
        ('intro', 'entity_wolfi', 'src/entities/wolfi/entity_wolfi', 'on_update_intro', 2),
        ('world', 'world_orchestration', 'src/gameplay/world_orchestration', 'world_update_entities', 2),
    ]:
        module = next(m for m in modules if m['name'] == module_name)
        area = next(a for a in module['areas'] if a['name'] == '_CODE')
        listing = (profile / ('msx/' + path + '.lst')).read_text()
        entry = area['address'] + int(re.search(r'^\s+([0-9A-F]{6})\s+\d+ _' + function + ':', listing, re.M)[1], 16)
        code += f'''debug set_bp {entry} {{$phase == 1 && !$active({label}) && [debug read memory {symbols['_mapper_current_segments']+page}] == {module['segment']}}} {{begin {label}}}
'''
    code += f'''debug set_watchpoint write_mem {symbols['_edw_smoke_messages']} {{}} {{
    if {{$phase && $::wp_last_value}} {{
        set pixels {{}}
        foreach address {{0x0050 0x0850 0x2050 0x2850}} {{append pixels [debug read_block VRAM $address 176]}}
        lappend scene_large [binary encode hex $pixels]
    }}
}}
debug set_watchpoint write_mem {symbols['_edw_smoke_small_messages']} {{}} {{
    if {{$phase && $::wp_last_value}} {{
        set pixels {{}}
        foreach address {{0x0850 0x2850}} {{append pixels [debug read_block VRAM $address 168]}}
        lappend scene_small [binary encode hex $pixels]
    }}
}}
'''
    quest_bank = next(m for m in modules if m['name'] == 'quest_smoke')['segment']
    code += f'''debug set_bp {symbols['_quest_smoke']} {{[debug read memory {symbols['_mapper_current_segments']+2}] == {quest_bank}}} {{debug write memory {symbols['_edw_scene_only']} 1}}
debug set_watchpoint write_mem {symbols['_edw_scene_stage']} {{}} {{
    set phase $::wp_last_value
    if {{$phase == 1}} {{set scene_entry [reg SP];set low $scene_entry}}
    if {{$phase == 2 || $phase == 3}} {{screenshot -raw "{out}/{variant}-$phase.png"}}
}}
debug set_watchpoint write_mem {symbols['_edw_smoke_status']} {{}} {{
    if {{$::wp_last_value == 3 || $::wp_last_value == 128}} {{
        set f [open {{{report}}} w]
        puts $f "status=$::wp_last_value"
        puts $f "stage=[debug read memory {symbols['_edw_scene_stage']}]"
        puts $f "ticks=[expr {{[debug read memory {symbols['_edw_scene_ticks']}] | ([debug read memory {symbols['_edw_scene_ticks']+1}] << 8)}}]"
        puts $f "hash=[expr {{[debug read memory {symbols['_edw_scene_hash']}] | ([debug read memory {symbols['_edw_scene_hash']+1}] << 8)}}]"
        puts $f "stack=[expr {{$scene_entry-$low}}]"
        foreach sample $scene_samples {{puts $f "sample=$sample"}}
        foreach pixels $scene_large {{puts $f "large=$pixels"}}
        foreach pixels $scene_small {{puts $f "small=$pixels"}}
        close $f
        exit
    }}
}}
after time 90 {{exit}}
after realtime 80 {{exit}}
'''
    script = out / (variant + '.tcl')
    script.write_text(code)
    with (out / (variant + '-msx.log')).open('w') as log:
        run = subprocess.run(['openmsx', '-machine', 'C-BIOS_MSX1', '-carta', str(rom), '-romtype',
                              'KonamiSCC', '-script', str(script)], cwd=ROOT, env=env,
                             stdout=log, stderr=subprocess.STDOUT, timeout=90)
    rows = report.read_text().splitlines()
    assert rows and rows[0] != 'pending', (report, (out / (variant + '-msx.log')).read_text()[-1500:])
    values = dict(line.split('=', 1) for line in rows if not line.startswith('sample='))
    assert run.returncode == 0 and values.get('status') == '3' and values.get('stage') == '3', values
    sequence = [int(values['ticks']), int(values['hash'])]
    if host is not None:
        assert host == sequence, (variant, host, sequence)
    timings = {}
    for family in ('intro', 'world'):
        scene_samples = [(float(parts[1]), int(parts[2])) for line in rows if line.startswith('sample=')
                   for parts in [line[7:].split()] if parts[0] == family]
        assert len(scene_samples) == sequence[0], (family, len(scene_samples), sequence)
        # Dialogue and ISR waits are deliberately included in whole-scene means.
        timings[family] = {'calls': len(scene_samples), 'median_us': statistics.median(t for t, _ in scene_samples),
                          'mean_us': statistics.mean(t for t, _ in scene_samples), 'max_us': max(t for t, _ in scene_samples),
                          'additional_stack_bytes': max(s for _, s in scene_samples)}
    dialogues = {kind: [line.split('=', 1)[1] for line in rows if line.startswith(kind+'=')]
                 for kind in ('large', 'small')}
    assert len(dialogues['large']) == 5 and len(dialogues['small']) == 3, {k: len(v) for k,v in dialogues.items()}
    results[variant] = {'dialogues': dialogues, 'ticks': sequence[0], 'state_hash': sequence[1], 'observed_stack_bytes': int(values['stack']),
                        'callbacks': timings, 'rom_sha256': hashlib.sha256(rom.read_bytes()).hexdigest()}
    print(variant, {k:v for k,v in results[variant].items() if k != 'dialogues'}, flush=True)
if not args.variant:
    assert results['reference']['ticks'] == results['vexel']['ticks']
    assert results['reference']['state_hash'] == results['vexel']['state_hash']
    assert results['reference']['dialogues'] == results['vexel']['dialogues'], 'Scene dialogue patterns differ'
(out / ((args.variant + '-results.json') if args.variant else 'results.json')).write_text(json.dumps(results, indent=2) + '\n')
print('Scenes: intro progression, death restoration and mapper preservation passed')
