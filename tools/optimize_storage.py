#!/usr/bin/env python3
"""Select bounded storage alternatives using the linked game's measured costs.

The solver publishes each binding's physical preference and effective choice.
This adapter supplies the game workload, target validation, and cost policy.
Every candidate is a whole-program solve and independently linked project.
Results stay in build/storage-optimization; source preferences are never edited.
"""
import argparse
import importlib.util
import json
import os
from pathlib import Path
import shutil
import signal
import subprocess
import tempfile
import time

GAME = Path(__file__).resolve().parents[1]
ROOT = GAME.parents[1]


def load(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


player = load('player_optimization', GAME/'tools/optimize_player.py')
search = player.search


def input_identity(solver, samples, schedules=False):
    identity = player.input_identity(solver)
    # The SDCC runtime and guard live outside the game repository. Include the
    # emulator's machine/ROM resources too: changing the platform invalidates a
    # timing measurement even if every game source file remains unchanged.
    roots = [ROOT/'backends/msx-neo8/runtime', ROOT/'backends/msx-neo8/tools',
             Path(os.environ.get('OPENMSX_SYSTEM_DATA', '/usr/share/openmsx')),
             Path('/usr/share/cbios'), Path('/usr/share/sdcc/include')]
    identity['resources'] = {str(p): search.fingerprint(p) for root in roots
                            for p in sorted(root.rglob('*')) if p.is_file() and
                            '__pycache__' not in p.parts and p.suffix != '.pyc'}
    identity['probe'] = {'samples': samples, 'schedules': schedules, 'machine': 'C-BIOS_MSX1', 'mapper': 'KonamiSCC',
                         'system_data': os.environ.get('OPENMSX_SYSTEM_DATA')}
    # The reference Make invocation uses the canonical generated include
    # directory. Even manually edited generated inputs must invalidate reuse.
    identity['reference_generated_sha256'] = search.tree_fingerprint(GAME/'generated/quests')
    return identity


def reference_identity(identity):
    """C/reference execution consumes neither the solver nor helper vectors."""
    return {'scope': 'edelweiss-reference-smoke-1',
            'inputs': {k: v for k, v in identity.items() if k not in ('solver_sha256', 'probe')}}


def cached_reference(cache):
    record = cache.load({})
    if record is None or not isinstance(record.get('directory'), str):
        return None
    directory = Path(record['directory']).resolve()
    # A valid artifact elsewhere cannot authorize using an edited directory
    # field. The complete profile must itself be covered by the checked tree.
    if not any(a.get('kind') == 'tree' and Path(a['path']).resolve() == directory
               for a in record['artifacts']):
        return None
    return record


def reference_measurement(directory, validation, before):
    """Called only after check_smoke succeeds; bind its C result to that image."""
    result = json.loads(validation.read_text())['reference']
    artifacts = [{'kind': 'tree', 'path': str(directory), 'sha256': before},
                 {'path': str(validation), 'sha256': search.fingerprint(validation)}]
    artifacts += [{'path': str(p), 'sha256': search.fingerprint(p)}
                  for p in sorted(validation.parent.glob('reference-*')) if p.is_file()]
    return {'validated': True, 'directory': str(directory),
            'metrics': {'stack': int(result['additional_stack_bytes']),
                        'ghost_us': float(result['ghost_active_us']),
                        'ghost_skipped_us': float(result['ghost_skipped_us'])},
            'scope': 'C/reference SDL and MSX smoke execution; the supplied Vexel solver and typed-helper vectors are not reference build inputs.',
            'artifacts': artifacts}


def discover(baseline, reusable, schedules=False):
    """Expose only applicable choices, including a previously disabled reuse."""
    original = {b['name']: b for b in baseline['value_bindings']['bindings']}
    choices, domains, weights = {}, {}, {}
    for b in reusable['value_bindings']['bindings']:
        if b['entry'] != 'full':
            continue
        old = original[b['name']]
        alternatives = []
        if b['codegen']['scratch_reuses']:
            alternatives.append((b['scratch_policy'], 'scratch_reuse'))
        if schedules and b['codegen'].get('early_outputs', 0):
            alternatives.append((b['output_policy'], 'output_schedule'))
        for key, field in alternatives:
            choices[key] = int(old['codegen'][field])
            domains[key] = (choices[key], 1-choices[key])
            weights[b['name']] = max(1, b['frequency'])
    return choices, domains, weights


def probe_metrics(report, weights):
    metrics = {'helper_stack': 0, 'weighted_helper_us': 0}
    counts = {}
    for item in report['measurements'].values():
        counts[item['binding']] = counts.get(item['binding'], 0)+1
    for key, item in report['measurements'].items():
        metrics['helper_stack'] = max(metrics['helper_stack'], item['stack_bytes'])
        # Frequency is an optimization hint, not a measured invocation count.
        # Multiple linked instances share that binding's weight equally.
        metrics['weighted_helper_us'] += item['mean_us']*weights[item['binding']]/counts[item['binding']]
        metrics[key+':stack'] = item['stack_bytes']
        for row in item['samples']:
            metrics[key+':sample:'+str(row['index'])] = row['us']
    return metrics


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--solver', type=Path, default=ROOT/'build/vexel')
    parser.add_argument('--seconds', type=int, default=3600)
    parser.add_argument('--jobs', type=int, default=2)
    parser.add_argument('--samples', type=int, default=256)
    parser.add_argument('--max-candidates', type=int, default=16)
    parser.add_argument('--frame-bytes', type=int, default=96)
    parser.add_argument('--choice-branches', type=int, default=8)
    parser.add_argument('--schedules', action='store_true',
                        help='Also measure output-demand schedules; expands the candidate neighborhood')
    args = parser.parse_args()
    if not 1 <= args.samples <= 4096 or not 1 <= args.max_candidates <= 64:
        parser.error('samples must be in 1..4096 and max-candidates in 1..64')
    if args.seconds <= 0 or args.jobs <= 0 or not 0 <= args.frame_bytes <= 12288 or not 0 <= args.choice_branches <= 8:
        parser.error('invalid build budget')
    parent = GAME/'build/storage-optimization'
    parent.mkdir(parents=True, exist_ok=True)
    workspace = Path(tempfile.mkdtemp(prefix='run-', dir=parent))
    solver = workspace/'vexel'
    shutil.copy2(args.solver.resolve(), solver)
    identity = input_identity(solver, args.samples, args.schedules)
    identity_path = workspace/'input-identity.json'
    identity_path.write_text(json.dumps(identity, indent=2)+'\n')
    print('Optimization evidence:', workspace, flush=True)
    cache = search.MeasurementCache(parent/'cache', identity)
    started = time.monotonic()
    commands = []

    def run(command, log, *, env=None, timeout=600):
        remaining = args.seconds-(time.monotonic()-started)
        if remaining <= 0:
            raise TimeoutError('optimization wall budget exhausted')
        command = list(map(str, command))
        entry = {'argv': command, 'cwd': str(GAME), 'log': str(log)}
        commands.append(entry)
        began = time.monotonic()
        with Path(log).open('w') as output:
            process = subprocess.Popen(command, cwd=GAME, env=env, stdout=output, stderr=subprocess.STDOUT,
                                       start_new_session=True)
            try:
                process.wait(timeout=min(timeout, remaining))
            except BaseException:
                try:
                    os.killpg(process.pid, signal.SIGTERM)
                    process.wait(timeout=2)
                except subprocess.TimeoutExpired:
                    os.killpg(process.pid, signal.SIGKILL)
                    process.wait()
                except ProcessLookupError:
                    pass
                raise
            finally:
                entry.update(elapsed_seconds=time.monotonic()-began, returncode=process.poll())
                (workspace/'commands.json').write_text(json.dumps(commands, indent=2)+'\n')
        if process.returncode:
            raise RuntimeError(f'command failed ({process.returncode}); see {log}')

    def generate(directory, preferences, log):
        command = ['python3', 'tools/generate_quest.py', '--solver', solver, '--output', directory]
        for key, value in sorted(preferences.items()):
            command += ['--prefer', key+'='+str(value)]
        run(command, log)
        return json.loads((directory/'resolution.json').read_text())

    common = {'value_frame_bytes': args.frame_bytes, 'value_choice_branches': args.choice_branches}
    baseline = generate(workspace/'discovery-baseline', common, workspace/'discovery-baseline.log')
    # Project defaults are replaceable physical preferences. Source constraints
    # still cap the solver, so this cannot enable reuse prohibited by the code.
    allow = {b['scratch_policy']: 1 for b in baseline['value_bindings']['bindings'] if b['entry']=='full'}
    if args.schedules:
        allow.update({b['output_policy']: 1 for b in baseline['value_bindings']['bindings'] if b['entry']=='full'})
    reusable = generate(workspace/'discovery-reuse', dict(common, **allow), workspace/'discovery-reuse.log')
    choices, domains, weights = discover(baseline, reusable, args.schedules)
    # Frequency is a source hint about likely payoff. Spend a bounded search
    # on hot scopes first; every attempted candidate still needs the same
    # independent oracle, linked target measurement and regression checks.
    priority = sorted(domains, key=lambda key: (-weights[key.split('.', 1)[1]], key))
    (workspace/'priority.json').write_text(json.dumps(priority, indent=2)+'\n')
    candidates = search.preference_variants(dict(common, **choices), domains,
                                          max_candidates=args.max_candidates, priority=priority)
    (workspace/'candidates.json').write_text(json.dumps(candidates, indent=2)+'\n')
    if not domains:
        print('No applicable full-binding storage alternatives.', flush=True)
        return
    names = sorted(weights)
    baseline_metrics = None
    reference_cache = search.MeasurementCache(parent/'reference-cache', reference_identity(identity))
    reference_record = cached_reference(reference_cache)
    reference = Path(reference_record['directory']) if reference_record else workspace/'reference/reference-smoke'
    (workspace/'reference-cache.json').write_text(json.dumps({
        'hit': reference_record is not None, 'profile': str(reference),
        'cache': str(reference_cache.directory)}, indent=2)+'\n')
    if reference_record:
        print('Reference checked cache hit:', reference, flush=True)

    def validate_metrics(metrics):
        nonlocal baseline_metrics
        if baseline_metrics is None:
            baseline_metrics = metrics
            # Guard every measured input and linked instance. Frequency-weighted
            # averages alone could hide a regression in a less common binding.
            limits.update({key: [1.02, None] for key in metrics if ':sample:' in key})
            limits.update({key: [1, None] for key in metrics if key.endswith(':stack')})
        elif set(metrics) != set(baseline_metrics):
            raise ValueError('candidate changed the measured helper/sample identities')

    def evaluate(candidate, remaining):
        nonlocal reference_record
        if input_identity(solver, args.samples, args.schedules) != identity:
            raise ValueError('optimization inputs changed during measurement')
        prefs = candidate['preferences']
        cached = cache.load(prefs)
        if cached is not None:
            print(candidate['name'], 'checked cache hit:', cached['directory'], flush=True)
            validate_metrics(cached['metrics'])
            return cached
        directory = workspace/candidate['name']
        directory.mkdir()
        generated = directory/'generated'
        resolution = generate(generated, prefs, directory/'generate.log')
        env = dict(os.environ, EDW_GENERATED=str(generated), EDW_TEST_BUILD=str(directory/'host'))
        run(['python3', 'tests/check_quest.py'], directory/'host-validation.log', env=env)
        if not reference.exists():
            run(['make', f'-j{args.jobs}', 'GAMEPLAY=reference', 'SMOKE=1', f'BUILD_ROOT={reference.parent}',
                 'MAX_ALLOCS=2000', 'SDCC_MEMORY_MB=2048', 'SDCC_TIMEOUT=180', 'all'],
                workspace/'reference-build.log', timeout=args.seconds)
        run(['make', f'-j{args.jobs}', 'GAMEPLAY=vexel', 'SMOKE=1', f'BUILD_ROOT={directory}',
             f'GENERATED={generated}', 'MAX_ALLOCS=2000', 'SDCC_MEMORY_MB=2048', 'SDCC_TIMEOUT=180', 'all'],
            # A complete project contains many serialized compiler jobs and
            # can wait behind another build. Bound the project by the search
            # deadline; each SDCC invocation still has its own 180-second cap.
            directory/'build.log', timeout=args.seconds)
        (directory/'reference-smoke').symlink_to(reference, target_is_directory=True)
        reference_before = search.tree_fingerprint(reference)
        run(['python3', 'tests/check_smoke.py', '--build-root', directory, '--speed', '1000'],
            directory/'smoke.log', timeout=400)
        if reference_record is None:
            reference_record = reference_measurement(reference, directory/'smoke/results.json', reference_before)
            if input_identity(solver, args.samples, args.schedules) != identity:
                raise ValueError('optimization inputs changed before reference cache publication')
            # save() rechecks the tree captured before execution, rejecting a
            # binary edited between the validation run and cache publication.
            reference_cache.save({}, reference_record)
        command = ['python3', 'tools/profile_storage.py', '--profile', directory/'vexel-smoke',
                   '--generated', generated, '--samples', args.samples, '--output', directory/'probe']
        for name in names:
            command += ['--binding', name]
        run(command, directory/'probe.log', timeout=240)
        probe = json.loads((directory/'probe/results.json').read_text())
        smoke = json.loads((directory/'smoke/results.json').read_text())['vexel']
        rom = directory/'vexel-smoke/msx/weiss.rom'
        layout = json.loads(Path(str(rom)+'.layout.json').read_text())['modules']
        areas = [a for m in layout for a in m['areas']]
        metrics = probe_metrics(probe, weights)
        metrics.update(game_stack=int(smoke['additional_stack_bytes']),
                       ghost_us=float(smoke['ghost_active_us']), ghost_skipped_us=float(smoke['ghost_skipped_us']),
                       ram_end=max(a['address']+a['size'] for a in areas if a['name']=='_DATA'),
                       shared_frame_bytes=resolution['value_bindings']['static_bytes'],
                       occupied_rom=sum(a['size'] for a in areas if a['name']!='_DATA'))
        validate_metrics(metrics)
        files = [rom, Path(str(rom)+'.layout.json'), Path(str(rom)+'.sym'),
                 directory/'vexel-smoke/linux/weiss', reference/'msx/weiss.rom', reference/'linux/weiss',
                 reference/'msx/weiss.rom.layout.json', reference/'msx/weiss.rom.sym',
                 generated/'manifest.json', generated/'resolution.json', directory/'host-validation.log',
                 directory/'smoke.log', directory/'smoke/results.json', directory/'probe/results.json', solver, identity_path]
        evidence = {str(p): search.fingerprint(p) for p in files}
        evidence.update({str(p): search.fingerprint(p) for p in (directory/'smoke').glob('*')
                         if p.is_file() and p.suffix in ('.bin', '.tcl', '.txt', '.log')})
        evidence.update({a['path']: a['sha256'] for a in probe['artifacts']})
        if input_identity(solver, args.samples, args.schedules) != identity:
            raise ValueError('optimization inputs changed during measurement')
        result = {'validated': True, 'metrics': metrics, 'directory': str(directory), 'generated': str(generated),
                  'scope': 'Sampled isolated helpers plus SDL/MSX full-engine scenario and C/reference host checks; frequency-weighted helper timing is a search score, not gameplay timing.',
                  'artifacts': [{'path': p, 'sha256': sha} for p, sha in sorted(evidence.items())]}
        result['artifacts'].append({'path': str(generated), 'kind': 'tree',
                                    'sha256': search.tree_fingerprint(generated)})
        cache.save(prefs, result)
        print(candidate['name'], {k: v for k, v in metrics.items() if ':' not in k}, flush=True)
        return result

    limits = {'game_stack': [1, None], 'helper_stack': [1, None], 'ghost_us': [1.02, None],
              'ghost_skipped_us': [1.02, None], 'ram_end': [None, 0xd000],
              'occupied_rom': [None, 16*1024*1024]}
    result = search.search(candidates, evaluate, workspace/'selection.json',
                           objective=['game_stack', 'helper_stack', 'weighted_helper_us', 'occupied_rom'],
                           limits=limits, seconds=args.seconds-(time.monotonic()-started),
                           max_candidates=args.max_candidates)
    result['input_identity'] = identity
    result['input_validation'] = 'passed' if input_identity(solver, args.samples, args.schedules)==identity else 'failed'
    selected = next(e for e in result['candidates'] if e['candidate']['name']==result['selected'])
    result['selected_preferences'] = selected['candidate']['preferences']
    result['selected_project'] = selected['measurement']['directory']
    (workspace/'selection.json').write_text(json.dumps(result, indent=2)+'\n')
    if result['input_validation'] != 'passed':
        raise ValueError('optimization inputs changed before selection completed')
    (parent/'latest.json').write_text(json.dumps({'directory': str(workspace), 'selected': result['selected'],
                                                'report': str(workspace/'selection.json')}, indent=2)+'\n')
    print('Selected:', result['selected_preferences'], '—', result['selected_project'], flush=True)


if __name__ == '__main__':
    main()
