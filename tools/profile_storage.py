#!/usr/bin/env python3
"""Validate and measure linked pure bindings over reproducible input vectors.

The emulator stops at main after C startup, then invokes each actual linked
helper with its normal SDCC ABI and mapper window. Interrupts stay disabled.
These are isolated helper samples, not gameplay timings or stack proofs.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import random
import re
import shlex
import statistics
import subprocess

GAME = Path(__file__).resolve().parents[1]
ROOT = GAME.parents[1]


def digest(path):
    return hashlib.sha256(Path(path).read_bytes()).hexdigest()


def scalar(type_name):
    match = re.fullmatch(r'#([ui])(8|16|32)', type_name)
    if not match:
        raise ValueError('probe requires a native integer scalar: '+type_name)
    return int(match[2])//8, match[1]=='i'


def vectors(inputs, count):
    """Boundary/bit patterns plus a fixed random sample; no workload claim."""
    rng = random.Random(0x5658454c)
    rows = []
    for index in range(count):
        row = []
        for position, item in enumerate(inputs):
            lo, hi = item['min'], item['max']
            edges = [lo, hi, 0, 1, -1, 7, 8, 9, 10, 13, 14, 20, 21, 127, 128, 255, 256, 32767, 32768]
            # First rotate boundaries across arguments, then share boundaries
            # to exercise equal-coordinate/flag cases instead of repeating the
            # same rows. Remaining inputs are independent reproducible draws.
            if index<len(edges):value=edges[(index+position)%len(edges)]
            elif index<2*len(edges):value=edges[index-len(edges)]
            else:value=rng.randint(lo,hi)
            row.append(max(lo, min(hi, value)))
        rows.append(row)
    return rows


def describe(profile, generated, names, count):
    if not 1 <= count <= 4096 or (names is not None and (not names or len(set(names)) != len(names))):
        raise ValueError('provide distinct bindings and 1..4096 samples')
    report = json.loads((generated/'resolution.json').read_text())
    bindings = {b['name']:b for b in report['value_bindings']['bindings']}
    sources = {s['name']:s for s in report['sources']}
    rom = profile/'msx/weiss.rom'
    layout = json.loads(Path(str(rom)+'.layout.json').read_text())['modules']
    symbols = {n:int(a,16) for n,a in re.findall(r'(\w+): equ ([0-9A-Fa-f]+)h',Path(str(rom)+'.sym').read_text())}
    modules = {m['name']:m for m in layout}
    if not 0x4000 <= symbols['_main'] < 0x6000:
        raise ValueError('probe return trampoline requires main in the resident cartridge page')
    listings = sorted((profile/'msx').rglob('*.lst'))
    entries = {}
    for listing in listings:
        for match in re.finditer(r'^\s+([0-9A-F]{6})\s+\d+ (_vx_bind_\w+_(?:run|compute)):\s*$',listing.read_text(),re.M):
            entries.setdefault(match[2], []).append((listing,int(match[1],16)))
    def symbol_for(binding):
        return '_vx_bind_'+binding['name']+('_run' if binding['storage']=='fixed' else '_compute')
    if names is None:
        names = sorted(b['name'] for b in bindings.values() if b['entry']=='full' and symbol_for(b) in entries)
        if not names:
            raise ValueError('project has no linked full pure bindings')
    specs = []
    for name in names:
        b = bindings[name]
        if b['entry']!='full':
            raise ValueError('only full pure bindings can be invoked in isolation: '+name)
        source = sources[b['source']]
        all_inputs = [leaf for parameter in source['parameters'] for leaf in parameter['leaves']]
        inputs = [dict(all_inputs[i],field='a'+str(i)) for i in b['inputs']]
        outputs = [dict(leaf,field='v'+str(i)) for i,leaf in enumerate(source['leaves'])]
        for item in inputs+outputs:
            item['bytes'],item['signed'] = scalar(item['logical_type'])
        frame = symbols['_vx_binding_slot_'+str(b['slot'])] if b['storage']=='fixed' else 0xd000
        if b['bytes']>0x1800 or frame<0xc000 or frame+b['bytes']>0xf000:
            raise ValueError('probe frame overlaps its reserved stack: '+name)
        symbol = symbol_for(b)
        found = []
        for listing,offset in entries.get(symbol, []):
            module = modules[listing.stem]
            area = next(a for a in module['areas'] if a['name']=='_CODE')
            if module['page'] not in range(4) or (module['page']==0 and module['segment']!=0):
                raise ValueError('probe requires the game\'s resident KonamiSCC mapping')
            if offset>=area['size']:
                raise ValueError('helper entry is outside its linked area')
            found.append({'pc':area['address']+offset,'page':module['page'],'segment':module['segment'],
                          'listing':str(listing),'listing_sha256':digest(listing),'module':module['name']})
        if not found:
            raise ValueError('binding has no linked helper: '+name)
        result_bytes = sum(item['bytes'] for item in outputs)
        input_bytes = sum(item['bytes'] for item in inputs)
        if input_bytes+result_bytes>b['bytes']:
            raise ValueError('binding layout is inconsistent: '+name)
        # SDCC's emitted sizeof assertion establishes the sum-of-fields layout.
        # Inputs come first and the result comes last; scratch stays opaque.
        specs.append({'name':name,'storage':b['storage'],'frame':frame,'frame_bytes':b['bytes'],
                      'result_offset':b['bytes']-result_bytes,'inputs':inputs,'outputs':outputs,
                      'vectors':vectors(inputs,count),'instances':found})
    return rom,symbols,specs


def host_oracle(generated, specs, out):
    text='#include <stdio.h>\n#include <stdlib.h>\n'
    text+=''.join('#include "vx_bind_'+s['name']+'.h"\n' for s in specs)
    text+='void vx_trap(uint8_t code){exit(code);}\nint main(void){unsigned row;\n'
    for number,spec in enumerate(specs):
        name=spec['name'];rows=spec['vectors'];count=len(spec['inputs'])
        table=','.join('{'+','.join(str(v & 0xffffffff)+'UL' for v in row)+'}' for row in rows)
        text+='{ VX_BIND_'+name+'_LOCAL;\n'
        if count:text+=f'static const uint32_t input[{len(rows)}][{count}]={{'+table+'};\n'
        text+=f'for(row=0;row<{len(rows)};++row){{\n'
        for i,item in enumerate(spec['inputs']):
            ctype=('int' if item['signed'] else 'uint')+str(8*item['bytes'])+'_t'
            text+=f'vx_bind_{name}_frame.{item["field"]}=({ctype})input[row][{i}];\n'
        text+=f'vx_bind_{name}_run(); printf("{number} %u",row);\n'
        for item in spec['outputs']:
            mask=(1<<(item['bytes']*8))-1
            text+=f'printf(" %lu",(unsigned long)((uint32_t)vx_bind_{name}_frame.result.{item["field"]}&{mask}UL));\n'
        text+='puts("");}}\n'
    text+='return 0;}\n'
    path=out/'oracle.c';path.write_text(text)
    command=shlex.split(os.environ.get('CC','cc'))+['-std=c11','-O2','-fsanitize=undefined','-fno-sanitize-recover=all',
             '-I'+str(generated),'-I'+str(ROOT/'backends/msx-neo8/runtime'),str(path),
             str(generated/'vx_binding_frames.c'),'-o',str(out/'oracle')]
    (out/'oracle-command.json').write_text(json.dumps(command,indent=2)+'\n')
    built=subprocess.run(command,capture_output=True,text=True,timeout=120)
    (out/'oracle-build.log').write_text(built.stdout+built.stderr)
    if built.returncode:raise ValueError('host oracle failed to build; see '+str(out/'oracle-build.log'))
    result=subprocess.run([str(out/'oracle')],capture_output=True,text=True,timeout=60)
    (out/'oracle.txt').write_text(result.stdout)
    if result.returncode:raise ValueError('host oracle trapped or failed: '+result.stderr)
    expected={}
    for line in result.stdout.splitlines():
        number,row,*values=map(int,line.split());expected[number,row]=values
    if len(expected)!=sum(len(s['vectors']) for s in specs):raise ValueError('incomplete host oracle')
    return expected


def profile(profile_dir, generated, names, out, count=256):
    profile_dir,generated,out=map(lambda p:Path(p).resolve(),(profile_dir,generated,out))
    out.mkdir(parents=True,exist_ok=True)
    rom,symbols,specs=describe(profile_dir,generated,names,count)
    (out/'workload.json').write_text(json.dumps(specs,indent=2)+'\n')
    expected=host_oracle(generated,specs,out)
    rows=[]
    for number,spec in enumerate(specs):
        for instance,entry in enumerate(spec['instances']):
            for row,values in enumerate(spec['vectors']):
                data=[]
                for value,item in zip(values,spec['inputs']):
                    data.extend((value>>(8*i))&255 for i in range(item['bytes']))
                rows.append([number,instance,row,entry['pc'],entry['page'],entry['segment'],spec['frame'],
                             spec['frame_bytes'],spec['result_offset'],sum(x['bytes'] for x in spec['outputs']),
                             int(spec['storage']=='automatic'),'{'+ ' '.join(map(str,data))+'}'])
    samples=out/'samples.txt';samples.write_text('pending\n')
    code='''set throttle off
set renderer none
set active 0
set started 0
set sample 0
set tasks {\n'''+''.join('{'+ ' '.join(map(str,row))+'}\n' for row in rows)+'''}
'''
    code+=f'set output [open {{{samples}}} w]\nset return_pc {symbols["_main"]}\n'
    code+='''proc next_sample {} {
    if {$::sample == [llength $::tasks]} {puts $::output "done"; close $::output; exit; return}
    lassign [lindex $::tasks $::sample] binding instance index pc page segment frame size offset bytes automatic inputs
    reg IFF 0
    foreach register {AF BC DE HL IX IY} {reg $register [expr {(0x5a73*($::sample+1))&65535}]}
    reg SP 0xf300
    debug write memory 0xf300 [expr {$::return_pc&255}]
    debug write memory 0xf301 [expr {$::return_pc>>8}]
    if {$automatic} {
        debug write memory 0xf302 [expr {$frame&255}]
        debug write memory 0xf303 [expr {$frame>>8}]
    }
    if {$page != 0} {debug write memory [lindex {0x5000 0x7000 0x9000 0xb000} $page] $segment}
    for {set i 0} {$i<$size} {incr i} {debug write memory [expr {$frame+$i}] 0xa5}
    set i 0;foreach byte $inputs {debug write memory [expr {$frame+$i}] $byte;incr i}
    set ::low 0xf300
    set ::begin [machine_info time]
    set ::active 1
    reg PC $pc
}
debug set_watchpoint write_mem {0xc000 0xf2ff} {$::active && $::wp_last_address >= [reg SP]} {
    if {$::wp_last_address < $::low} {set ::low $::wp_last_address}
}
debug set_bp $return_pc {([debug read ioports 0xa8]&12)==4} {
    if {$::active} {
        if {[reg SP] != 0xf302} {error "unbalanced probe stack"}
        lassign [lindex $::tasks $::sample] binding instance index pc page segment frame size offset bytes automatic inputs
        set elapsed [expr {1e6*([machine_info time]-$::begin)}]
        set data [binary encode hex [debug read_block memory [expr {$frame+$offset}] $bytes]]
        puts $::output "$binding $instance $index $elapsed [expr {0xf300-$::low+2}] $data"
        set ::active 0
        incr ::sample
    }
    set ::started 1
    next_sample
}
after time 30 {error "probe emulated-time budget exhausted"}
after realtime 90 {exit}
'''
    script=out/'probe.tcl';script.write_text(code)
    env=dict(os.environ,SDL_VIDEODRIVER='dummy',SDL_AUDIODRIVER='dummy',OPENMSX_USER_DATA=str(out/'openmsx'))
    with (out/'openmsx.log').open('w') as log:
        result=subprocess.run(['openmsx','-machine','C-BIOS_MSX1','-carta',str(rom),'-romtype','KonamiSCC','-script',str(script)],
                              env=env,stdout=log,stderr=subprocess.STDOUT,timeout=100)
    lines=samples.read_text().splitlines()
    if result.returncode or not lines or lines[-1]!='done':raise ValueError('target probe did not complete; see '+str(out/'openmsx.log'))
    if len(lines)!=len(rows)+1:raise ValueError('target probe lost samples')
    measurements={}
    mismatches=0;counterexamples=[]
    seen=set()
    for line,task in zip(lines[:-1],rows):
        number,instance,index,elapsed,stack,data=line.split()
        number,instance,index=int(number),int(instance),int(index)
        if [number,instance,index]!=task[:3] or (number,instance,index) in seen:
            raise ValueError('target sample identity or order changed')
        seen.add((number,instance,index))
        spec=specs[number];raw=bytes.fromhex(data);values=[];offset=0
        if len(raw)!=task[9]:raise ValueError('incomplete target result')
        for item in spec['outputs']:
            values.append(int.from_bytes(raw[offset:offset+item['bytes']],'little'));offset+=item['bytes']
        if values!=expected[number,index]:
            mismatches+=1
            if len(counterexamples)<64:
                counterexamples.append({'binding':spec['name'],'module':spec['instances'][instance]['module'],
                    'index':index,'inputs':spec['vectors'][index],'expected':expected[number,index],'actual':values})
        key=spec['name']+'@'+spec['instances'][instance]['module']
        entry=measurements.setdefault(key,{'binding':spec['name'],'module':spec['instances'][instance]['module'],
            'storage':spec['storage'],'frame_bytes':spec['frame_bytes'],'samples':[]})
        entry['samples'].append({'index':index,'us':float(elapsed),'stack_bytes':int(stack)})
    for entry in measurements.values():
        entry['mean_us']=statistics.mean(row['us'] for row in entry['samples'])
        entry['max_us']=max(row['us'] for row in entry['samples'])
        entry['stack_bytes']=max(row['stack_bytes'] for row in entry['samples'])
    provenance=[rom,Path(str(rom)+'.layout.json'),Path(str(rom)+'.sym'),generated/'manifest.json',
                out/'workload.json',out/'oracle.c',out/'oracle',out/'oracle.txt',out/'oracle-command.json',script,samples,Path(__file__)]
    provenance += [Path(e['listing']) for s in specs for e in s['instances']]
    report={'validated':not mismatches,'measurements':measurements,
            'mismatches':mismatches,'counterexamples':counterexamples,
            'selection':{'mode':'all-linked-full' if names is None else 'explicit',
                         'bindings':[s['name'] for s in specs]},
            'scope':'Isolated linked SDCC ABI-0 helper entry through return, IRQ disabled. Stack includes entry return address, excludes caller-owned frame and argument publication. Samples are not a worst-case proof or a gameplay distribution.',
            'artifacts':[{'path':str(p),'sha256':digest(p)} for p in provenance]}
    (out/'results.json').write_text(json.dumps(report,indent=2)+'\n')
    if mismatches:
        raise ValueError(f'{mismatches} target results differ; counterexamples retained in {out/"results.json"}')
    return report


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--profile',type=Path,required=True)
    parser.add_argument('--generated',type=Path,required=True)
    selected=parser.add_mutually_exclusive_group(required=True)
    selected.add_argument('--binding',action='append')
    selected.add_argument('--all-full',action='store_true',help='Probe every linked full pure binding; excludes guarded cases and execution regions')
    parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--samples',type=int,default=256)
    args=parser.parse_args()
    if not 1<=args.samples<=4096:parser.error('--samples must be in 1..4096')
    result=profile(args.profile,args.generated,args.binding,args.output,args.samples)
    print(json.dumps({k:{n:v for n,v in entry.items() if n!='samples'} for k,entry in result['measurements'].items()},indent=2))


if __name__=='__main__':main()
