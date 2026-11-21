#!/usr/bin/env python3
"""Measure the real Z80 callbacks exercised after the ordinary encounter."""
import argparse, hashlib, json, os, re, subprocess, statistics
from pathlib import Path
game=Path(__file__).resolve().parents[1]
parser=argparse.ArgumentParser(description=__doc__)
parser.add_argument('--build-root', default='build')
parser.add_argument('--report-dir', default='callbacks')
parser.add_argument('--passive', action='store_true', help='Measure pickup, fairy and follower callbacks')
parser.add_argument('--family', help='Measure only this family within the selected callback group')
args=parser.parse_args()
build=game/args.build_root
out=build/args.report_dir
out.mkdir(parents=True,exist_ok=True)
label='passive' if args.passive else 'actors'
specs=([
    ('drops','entity_drop_item','src/entities/drop_item/entity_drop_item',('on_update',)),
    ('fairy','entity_fairy','src/entities/fairy/entity_fairy',('on_update_top','on_update_bottom')),
    ('follower','entity_lumberjack','src/entities/npcs/entity_lumberjack',('on_update',)),
] if args.passive else [
    ('melee','entity_weapon_slash','src/entities/weapons/entity_weapon_slash',('on_update',)),
    ('arrow','entity_weapon_bow','src/entities/weapons/entity_weapon_bow',('on_update',)),
    ('fire','entity_weapon_fire','src/entities/weapons/entity_weapon_fire',('on_update',)),
    ('bomb','entity_weapon_bomb','src/entities/weapons/entity_weapon_bomb',('on_update',)),
    ('spark','entity_spark','src/entities/spark/entity_spark',('on_update',)),
    ('explosion','entity_explosion','src/entities/explosion/entity_explosion',('on_update',)),
    ('ball','enemy_ball','src/entities/enemy_ball/enemy_ball',('on_update',)),
    ('player','entity_wolfi','src/entities/wolfi/entity_wolfi',('player_control',)),
])
if args.family:
    specs=[spec for spec in specs if spec[0]==args.family]
    if not specs:parser.error('--family must belong to the selected callback group')
results={}
provenance={}
for variant in ('reference','vexel'):
    profile=build/(variant+'-encounter')
    rom=profile/'msx/weiss.rom'
    provenance[variant]={'rom_sha256':hashlib.sha256(rom.read_bytes()).hexdigest()}
    symbols={n:int(a,16) for n,a in re.findall(r'(\w+): equ ([0-9A-Fa-f]+)h',Path(str(rom)+'.sym').read_text())}
    layout=json.loads(Path(str(rom)+'.layout.json').read_text())['modules']
    report=out/(label+'-'+variant+'-timing.txt');report.write_text('pending\n')
    script=out/(label+'-'+variant+'-timing.tcl')
    code='''set throttle on
set speed 1000
set renderer SDL
set measure_phase none
set call_active 0
set call_samples {}
debug set_watchpoint write_mem {0xf104 0xf37f} {} {
    if {$call_active && $::wp_last_address < $call_low} {set call_low $::wp_last_address}
}
'''
    for family,module_name,path,functions in specs:
        module=next(m for m in layout if m['name']==module_name)
        area=next(a for a in module['areas'] if a['name']=='_CODE')
        listing=(profile/('msx/'+path+'.lst')).read_text()
        entries={area['address']+int(re.search(r'^\s+([0-9A-F]{6})\s+\d+ _'+fn+':',listing,re.M)[1],16) for fn in functions}
        bank=module['segment'];mapper=symbols['_mapper_current_segments']+2
        driver_bank=next(m for m in layout if m['name']=='actor_policies')['segment'] if family=='player' else bank
        code+=f'''debug set_bp {symbols['_encounter_'+family]} {{[debug read memory {mapper}] == {driver_bank}}} {{set measure_phase {family}}}
'''
        for pc in sorted(entries):
            # The fairy's bottom callback may forward to its top callback.
            # Measure the enclosing invocation once in either implementation.
            code+=f'''debug set_bp {pc} {{!$call_active && $measure_phase eq "{family}" && [debug read memory {mapper}] == {bank}}} {{
    set call_active 1
    set call_entry [reg SP]
    set call_low $call_entry
    set call_started [machine_info time]
    set call_return [expr {{[debug read memory $call_entry] | ([debug read memory [expr {{$call_entry+1}}]] << 8)}}]
    set call_rbp [debug set_bp $call_return [format {{[reg SP] == %d}} [expr {{$call_entry+2}}]] {{
        lappend call_samples [list $measure_phase [expr {{1e6*([machine_info time]-$call_started)}}] [expr {{$call_entry-$call_low}}]]
        set call_active 0
        debug remove_bp $call_rbp
    }}]
}}
'''
    code+=f'''debug set_watchpoint write_mem {symbols['_edw_encounter_marker']} {{}} {{
    if {{$::wp_last_value == 4 || $::wp_last_value == 128}} {{
        set f [open {{{report}}} w]
        puts $f "status=$::wp_last_value"
        foreach row $call_samples {{puts $f $row}}
        close $f
        exit
    }}
}}
after time 55 {{exit}}
after realtime 55 {{exit}}
'''
    script.write_text(code)
    env=dict(os.environ,SDL_VIDEODRIVER='dummy',SDL_AUDIODRIVER='dummy',OPENMSX_USER_DATA=str(out/('openmsx-time-'+variant)))
    with (out/(label+'-'+variant+'-timing.log')).open('w') as log:
        r=subprocess.run(['openmsx','-machine','C-BIOS_MSX1','-carta',str(rom),'-romtype','KonamiSCC','-script',str(script)],cwd=game,env=env,stdout=log,stderr=subprocess.STDOUT,timeout=65)
    lines=report.read_text().splitlines();assert r.returncode==0 and lines[0]=='status=4',report.read_text()
    rows={family:[] for family,_,_,_ in specs}
    for line in lines[1:]:
        family,t,s=line.split();rows[family].append((float(t),int(s)))
    result={}
    for family,data in rows.items():
        expected={'melee':2000,'arrow':100,'fire':100,'bomb':48,'spark':120,'explosion':40,'ball':40,'player':192,'drops':50,'fairy':512,'follower':48}[family]
        assert len(data)==expected,(family,len(data))
        elapsed=((0,1,2,255) if family=='melee' else (0,1,3,255) if family=='bomb' else (0,1,2,3) if family=='player' else
                 ((1,) if family in ('ball','fairy','follower') else (0,1,2,3,255)))
        result[family]={}
        for k,dt in enumerate(elapsed):
            subset=([row for i,row in enumerate(data) if (i//3)%4==k] if family=='player' else
                    (data if family in ('ball','fairy','follower') else data[k::len(elapsed)]))
            result[family][str(dt)]={'mean_us':statistics.mean(r[0] for r in subset),'max_us':max(r[0] for r in subset),'additional_stack_bytes':max(r[1] for r in subset),'calls':len(subset)}
        result[family]['samples']=data
    results[variant]=result
    print(variant,{f:{k:{'mean_us':round(v['mean_us'],3),'stack_bytes':v['additional_stack_bytes']} for k,v in r.items() if k!='samples'} for f,r in result.items()},flush=True)
(out/(label+'-callback-timing.json')).write_text(json.dumps(results,indent=2)+'\n')
(out/'provenance.json').write_text(json.dumps({'roms':provenance,'scope':'callback entry to return; includes nested calls, excludes entry return address and surrounding engine frames','timing':'openMSX MSX1 emulated time; scenario samples, not worst-case bounds'},indent=2)+'\n')
