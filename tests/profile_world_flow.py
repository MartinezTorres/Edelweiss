#!/usr/bin/env python3
"""Attribute the encounter's world-region time to its generated/native calls."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess

parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--rom', type=Path, required=True)
parser.add_argument('--listing', type=Path, required=True)
parser.add_argument('--output', type=Path, required=True)
args = parser.parse_args()
rom, listing, out = args.rom.resolve(), args.listing.resolve(), args.output.resolve()
out.mkdir(parents=True, exist_ok=True)
layout = json.loads(Path(str(rom)+'.layout.json').read_text())
symbols = {n: int(a, 16) for n, a in re.findall(r'(\w+): equ ([0-9A-Fa-f]+)h', Path(str(rom)+'.sym').read_text())}
module = next(m for m in layout['modules'] if m['name'] == 'world_orchestration')
area = next(a for a in module['areas'] if a['name'] == '_CODE')
entries = {n: area['address']+int(a, 16) for a, n in re.findall(
    r'^\s+([0-9A-F]{6})\s+\d+ _(vx_bind_world_flow_\w+|vx_value_\w+):', listing.read_text(), re.M)}
root = 'vx_bind_world_flow_run'
assert root in entries
report = out/'calls.txt'
report.write_text('pending\n')
code = '''set throttle on
set speed 1000
set renderer SDL
set flow_active 0
set flow_calls {}
set flow_samples {}
proc region_leave {name start return_sp} {
    if {[reg SP] != $return_sp} {return}
    set elapsed [expr {1e6*([machine_info time]-$start)}]
    set frame [lindex $::flow_calls end]
    if {[lindex $frame 0] ne $name} {error "Unbalanced region call: $name"}
    set ::flow_calls [lrange $::flow_calls 0 end-1]
    lappend ::flow_samples [list $name $elapsed [expr {$elapsed-[lindex $frame 1]}]]
    if {[llength $::flow_calls]} {
        set parent [lindex $::flow_calls end]
        lset parent 1 [expr {[lindex $parent 1]+$elapsed}]
        lset ::flow_calls end $parent
    } else {set ::flow_active 0}
    debug remove_bp [lindex $frame 2]
}
'''
for name, pc in entries.items():
    condition = f'[debug read memory {symbols["_mapper_current_segments"]+module["page"]}] == {module["segment"]}'
    condition += ' && !$flow_active' if name == root else ' && $flow_active'
    code += f'''debug set_bp {pc} {{{condition}}} {{
    set flow_active 1
    set sp [reg SP]
    set ret [expr {{[debug read memory $sp] | ([debug read memory [expr {{$sp+1}}]] << 8)}}]
    set end_sp [expr {{$sp+2}}]
    set bp [debug set_bp $ret [format {{[reg SP] == %d}} $end_sp] [list region_leave {name} [machine_info time] $end_sp]]
    lappend flow_calls [list {name} 0 $bp]
}}
'''
code += f'''debug set_watchpoint write_mem {symbols['_edw_encounter_marker']} {{}} {{
    if {{$::wp_last_value == 4 || $::wp_last_value == 128}} {{
        set f [open {{{report}}} w]
        puts $f "status=$::wp_last_value"
        foreach sample $flow_samples {{puts $f $sample}}
        close $f
        exit
    }}
}}
after time 70 {{exit}}
after realtime 60 {{exit}}
'''
script = out/'profile.tcl'
script.write_text(code)
env = dict(os.environ, SDL_VIDEODRIVER='dummy', SDL_AUDIODRIVER='dummy', OPENMSX_USER_DATA=str(out/'openmsx'))
with (out/'openmsx.log').open('w') as log:
    run = subprocess.run(['openmsx', '-machine', 'C-BIOS_MSX1', '-carta', str(rom),
        '-romtype', 'KonamiSCC', '-script', str(script)], env=env, stdout=log, stderr=subprocess.STDOUT, timeout=75)
rows = report.read_text().splitlines()
assert run.returncode == 0 and rows[0] == 'status=4', (rows, (out/'openmsx.log').read_text())
totals = {}
for row in rows[1:]:
    name, inclusive, own = row.split()
    result = totals.setdefault(name, {'calls': 0, 'inclusive_us': 0., 'own_us': 0.})
    result['calls'] += 1
    result['inclusive_us'] += float(inclusive)
    result['own_us'] += float(own)
assert totals[root]['calls'] == 64, totals
for result in totals.values():
    result['mean_us'] = result['inclusive_us']/result['calls']
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()
result = {'rom_sha256': sha(rom), 'listing_sha256': sha(listing), 'calls': totals}
(out/'results.json').write_text(json.dumps(result, indent=2)+'\n')
print(json.dumps(result, indent=2))
