#!/usr/bin/env python3
"""Measure linked password entries against an independent Python codec.

Build an ordinary Vexel game first, then pass its profile, generated directory
and a separate evidence directory. Measurements exclude caller argument stores,
result readers and interrupts; they are sampled costs, not a stack bound.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import random
import re
import statistics
import subprocess


def encode(items, weapons, rupees, life):
    packed = [items & 15, weapons, (rupees >> 4) & 63, (life >> 1) & 31]
    code = []
    for value, key in zip(packed, (0x82, 0x46, 0x38, 0x73)):
        value ^= key
        code.extend((65+(value & 15), 65+(value >> 4)))
    checksum = 0x46
    for value in code:
        checksum = ((checksum+value) & 255) ^ 0x37
    return [*code, 65+(checksum >> 4), 65+(checksum & 15)]


def decode(length, *arguments):
    code, current = list(arguments[:-1]), arguments[-1]
    code = [c-32 if 97 <= c <= 122 else c for c in code]
    packed = [(((code[2*i]-65) & 255) | (((code[2*i+1]-65) << 4) & 255)) ^ key
              for i, key in enumerate((0x82, 0x46, 0x38, 0x73))]
    checksum = 0x46
    for value in code[:8]:
        checksum = ((checksum+value) & 255) ^ 0x37
    valid = (length == 10 and all(65 <= c <= 80 for c in code)
             and code[8:] == [65+(checksum >> 4), 65+(checksum & 15)]
             and packed[0] & 0xf0 == 0 and packed[2] & 0xc0 == 0 and packed[3] & 0xe0 == 0
             and packed[2] <= 62 and 3 <= packed[3] <= 20 and packed[1] & 1 != 0)
    kind = (2 if length == 5 and code[:5] == list(b'NISHI') else
            3 if length == 4 and code[:4] == list(b'MSX2') else 1 if valid else 0)
    selected = current if current < 8 and packed[1] & (1 << current) else 0
    return [kind, 15 if kind == 2 else packed[0] & 15,
            255 if kind == 2 else packed[1], 999 if kind >= 2 else packed[2] << 4,
            40 if kind == 2 else (packed[3] << 1) & 255,
            (current if current < 8 else 0) if kind == 2 else selected, 37+kind]


def workload():
    rng = random.Random(0x505542)
    enc = [[rng.randrange(256), rng.randrange(256), rng.randrange(65536), rng.randrange(256)] for _ in range(256)]
    enc[:8] = [[v, v, v*257, v] for v in (0, 1, 15, 127, 128, 254, 255, 0)]
    dec = []
    for n in range(256):
        code = encode(rng.randrange(16), rng.randrange(128)*2+1,
                      rng.randrange(63)*16, rng.randrange(3, 21)*2)
        length = 10
        if n & 1:
            code = [v+32 for v in code]
        if 128 <= n < 192:
            if n & 2:
                code[n % 10] ^= 0x80
            else:
                length = n % 10
        if n >= 192:
            special = b'NISHI' if n & 2 else b'MSX2'
            code = list(special)+[0]*(10-len(special))
            length = len(special)
        dec.append([length, *code, n])
    return {'password_encode': (enc, encode), 'password_decode': (dec, decode)}


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('profile', type=Path, help='built game profile, e.g. build/vexel')
    parser.add_argument('generated', type=Path, help='matching generated image, e.g. generated/quests')
    parser.add_argument('output', type=Path, help='directory for workload, emulator script and measurements')
    args = parser.parse_args()
    profile, generated, out = args.profile.resolve(), args.generated.resolve(), args.output.resolve()
    out.mkdir(parents=True, exist_ok=True)
    (out/'results.json').write_text(json.dumps({'validated': False,
        'reason': 'No completed measurement for this invocation.'}, indent=2)+'\n')
    rom = profile/'msx/weiss.rom'
    symbols = {n: int(a, 16) for n, a in re.findall(r'(\w+): equ ([0-9A-Fa-f]+)h', Path(str(rom)+'.sym').read_text())}
    if not 0x4000 <= symbols['_main'] < 0x6000:
        raise ValueError('probe return trampoline requires main in the resident cartridge page')
    modules = {m['name']: m for m in json.loads(Path(str(rom)+'.layout.json').read_text())['modules']}
    sources = {s['name']: s for s in json.loads((generated/'resolution.json').read_text())['sources']}
    tasks, expected, descriptions, artifacts = [], [], [], []
    for name, (vectors, oracle) in workload().items():
        source = sources[name]
        inputs = [leaf for parameter in source['parameters'] for leaf in parameter['leaves']]
        widths = [int(re.fullmatch(r'#u(8|16|32)', x['logical_type'])[1])//8 for x in inputs]
        entries = []
        for listing in (profile/'msx').rglob('*.lst'):
            found = re.search(r'^\s+([0-9A-F]{6})\s+\d+ _vx_'+name+r'::?\s*$', listing.read_text(), re.M)
            if found:
                module = modules[listing.stem]
                area = next(a for a in module['areas'] if a['name'] == '_CODE')
                entries.append((area['address']+int(found[1], 16), module['page'], module['segment']))
                artifacts.append(listing)
        if len(entries) != 1:
            raise RuntimeError(f'{name}: expected one linked entry, found {entries}')
        pc, page, segment = entries[0]
        if page not in range(4) or not 0x4000+page*0x2000 <= pc < 0x6000+page*0x2000:
            raise ValueError(f'{name}: entry is outside its declared mapper page')
        width = source['element_bits']//8
        payload = symbols['_vx_payload']+source['offset']
        if width not in (1, 2, 4) or payload < 0xc000 or payload+source['bytes'] > 0xf000:
            raise ValueError(f'{name}: unsupported payload encoding or overlap with probe stack')
        if not all(leaf['stored'] for leaf in source['leaves']):
            raise RuntimeError(f'{name}: probe requires a fully stored result image')
        descriptions.append({'name': name, 'pc': pc, 'page': page, 'segment': segment,
                             'argument_bytes': widths, 'payload_element_bytes': width, 'samples': len(vectors)})
        for row, values in enumerate(vectors):
            if len(values) != len(widths):
                raise ValueError(f'{name}: argument layout changed; update the workload')
            data = [byte for value, size in zip(values, widths) for byte in value.to_bytes(size, 'little')]
            answer = oracle(*values)
            image = b''.join(value.to_bytes(width, 'little') for value in answer)
            if len(answer) != len(source['leaves']) or len(image) != source['bytes']:
                raise ValueError(f'{name}: result layout changed; update the oracle')
            tasks.append([pc, page, segment, payload, len(image),
                          '{'+' '.join(map(str, data))+'}'])
            expected.append({'name': name, 'row': row, 'inputs': values, 'values': answer, 'image': image.hex()})
    (out/'workload.json').write_text(json.dumps({'entries': descriptions, 'samples': expected}, indent=2)+'\n')
    output = out/'samples.txt'
    text = '''set throttle off
set renderer none
set active 0
set sample 0
set tasks {
'''+''.join('{'+ ' '.join(map(str, row))+'}\n' for row in tasks)+'}\n'
    text += f'set output [open {{{output}}} w]\nset return_pc {symbols["_main"]}\n'
    text += '''proc next_sample {} {
    if {$::sample == [llength $::tasks]} {puts $::output "done";close $::output;exit;return}
    lassign [lindex $::tasks $::sample] pc page segment payload size inputs
    reg IFF 0
    foreach register {AF BC DE HL IX IY} {reg $register [expr {(0x5a73*($::sample+1))&65535}]}
    reg SP 0xf300
    debug write memory 0xf300 [expr {$::return_pc&255}]
    debug write memory 0xf301 [expr {$::return_pc>>8}]
    set offset 0xf302
    foreach byte $inputs {debug write memory $offset $byte;incr offset}
    if {$page != 0} {debug write memory [lindex {0x5000 0x7000 0x9000 0xb000} $page] $segment}
    for {set i 0} {$i<$size} {incr i} {debug write memory [expr {$payload+$i}] 0xa5}
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
        if {[reg SP] != 0xf302} {error "unbalanced ordinary probe stack"}
        lassign [lindex $::tasks $::sample] pc page segment payload size inputs
        set elapsed [expr {1e6*([machine_info time]-$::begin)}]
        set data [binary encode hex [debug read_block memory $payload $size]]
        puts $::output "$::sample $elapsed [expr {0xf300-$::low+2}] $data"
        set ::active 0
        incr ::sample
    }
    next_sample
}
after time 30 {error "ordinary probe emulated-time budget exhausted"}
after realtime 90 {exit}
'''
    script = out/'probe.tcl'
    script.write_text(text)
    env = dict(os.environ, SDL_VIDEODRIVER='dummy', SDL_AUDIODRIVER='dummy', OPENMSX_USER_DATA=str(out/'openmsx'))
    with (out/'openmsx.log').open('w') as log:
        result = subprocess.run(['openmsx', '-machine', 'C-BIOS_MSX1', '-carta', str(rom), '-romtype', 'KonamiSCC', '-script', str(script)],
                                env=env, stdout=log, stderr=subprocess.STDOUT, timeout=100)
    lines = output.read_text().splitlines()
    if result.returncode or not lines or lines[-1] != 'done' or len(lines) != len(expected)+1:
        raise RuntimeError(f'incomplete password probe; see {out / "openmsx.log"}')
    mismatches, measurements = [], {}
    for row, line in enumerate(lines[:-1]):
        index, elapsed, stack, image = line.split()
        if int(index) != row:
            raise RuntimeError(f'password sample order mismatch at row {row}')
        answer = expected[row]
        if image != answer['image']:
            mismatches.append(dict(answer, actual=image))
        measurements.setdefault(answer['name'], []).append({'index': answer['row'], 'us': float(elapsed), 'stack_bytes': int(stack)})
    measurements = {name: {'samples': rows, 'mean_us': statistics.mean(r['us'] for r in rows),
                           'max_us': max(r['us'] for r in rows), 'stack_bytes': max(r['stack_bytes'] for r in rows)}
                    for name, rows in measurements.items()}
    artifacts += [out/'workload.json', rom, Path(str(rom)+'.sym'), Path(str(rom)+'.layout.json'), generated/'resolution.json', generated/'manifest.json', profile/'msx/settings.txt', script, output, Path(__file__)]
    report = {'validated': not mismatches, 'measurements': measurements, 'mismatches': mismatches,
              'scope': 'Isolated linked ordinary SDCC ABI-0 entries, IRQ disabled. Stack includes entry return address but excludes caller argument publication and result-reader calls. Independent Python codec oracle; sampled inputs are not a worst-case proof.',
              'artifacts': [{'path': str(p), 'sha256': hashlib.sha256(p.read_bytes()).hexdigest()} for p in artifacts]}
    (out/'results.json').write_text(json.dumps(report, indent=2)+'\n')
    print(json.dumps({'validated': report['validated'], 'mismatches': len(mismatches),
                      'measurements': {n: {k: v for k, v in m.items() if k != 'samples'} for n, m in measurements.items()}}, indent=2))
    if mismatches:
        raise RuntimeError(f'{len(mismatches)} password samples failed; see {out / "results.json"}')


if __name__ == '__main__':
    main()
