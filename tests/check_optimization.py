#!/usr/bin/env python3
"""A retained measurement is reusable only for its recorded inputs and choices."""
import copy
import importlib.util
import json
from pathlib import Path
import shutil
import subprocess
import tempfile

game = Path(__file__).resolve().parents[1]
spec = importlib.util.spec_from_file_location("player_search", game / "tools/optimize_player.py")
search = importlib.util.module_from_spec(spec)
spec.loader.exec_module(search)
original_which = search.shutil.which
with tempfile.TemporaryDirectory() as temporary:
    root = Path(temporary)
    search.ROOT = root
    search.GAME = root / "ext/game"
    for name in ("ext/game/Makefile", "ext/game/src/player.c", "ext/game/gameplay/player.vx",
                 "ext/game/vendor/sdcc_msx/util/module_linker.cc",
                 "experimental/relational/program_image.py", "backends/msx-neo8/tools/optimize.py",
                 "lib/core.vx", "vexel"):
        path = root / name
        path.parent.mkdir(parents=True, exist_ok=True)
        path.write_text("original " + name)
    # Tool discovery is independent of the fixture's source tree.
    search.shutil.which = lambda name: str(root / "vexel")
    solver = root / "vexel"
    identity = search.input_identity(solver)
    choices = {"name": "baseline", "frame_bytes": 96, "choice_branches": 8}
    report = {"input_identity": identity, "candidates": [{"candidate": choices, "status": "accepted",
              "measurement": {"validated": True, "metrics": {"stack": 12},
              "artifacts": [{"path": str(solver), "sha256": search.search.fingerprint(solver)}]}}]}
    search.checked_baseline(report, identity, choices)
    for name in ("src/player.c", "gameplay/player.vx", "vendor/sdcc_msx/util/module_linker.cc"):
        path = search.GAME / name
        before = path.read_text()
        path.write_text("changed")
        try:
            search.checked_baseline(report, search.input_identity(solver), choices)
            raise AssertionError("stale source measurement accepted: " + name)
        except ValueError:
            pass
        path.write_text(before)
    for variable in ("CFLAGS", "CPATH", "LIBRARY_PATH", "SDCC_INCLUDE"):
        previous = search.os.environ.get(variable)
        try:
            search.os.environ[variable] = (previous or "") + " changed-for-fixture"
            assert search.input_identity(solver) != identity, variable
        finally:
            if previous is None: search.os.environ.pop(variable)
            else: search.os.environ[variable] = previous
    added = search.GAME / "src/new.c"
    added.write_text("new input")
    assert search.input_identity(solver) != identity
    added.unlink()
    for change in ("missing-identity", "choices", "artifact"):
        candidate = copy.deepcopy(report)
        expected = dict(choices)
        if change == "missing-identity": candidate.pop("input_identity")
        if change == "choices": expected["frame_bytes"] = 35
        if change == "artifact": candidate["candidates"][0]["measurement"]["artifacts"][0]["sha256"] = "stale"
        try:
            search.checked_baseline(candidate, identity, expected)
            raise AssertionError("invalid reused baseline accepted: " + change)
        except ValueError:
            pass
search.shutil.which = original_which
print("Optimization: unchanged inputs reusable; changed source, input set, preferences and artifacts rejected")

spec = importlib.util.spec_from_file_location("storage_search", game / "tools/optimize_storage.py")
storage = importlib.util.module_from_spec(spec)
spec.loader.exec_module(storage)
def binding(name, reuse, uses, entry='full'):
    return {'name':name, 'entry':entry, 'scratch_policy':'value_scratch_reuse.'+name,
            'frequency':4, 'codegen':{'scratch_reuse':reuse, 'scratch_reuses':uses}}
baseline = {'value_bindings':{'bindings':[binding('active',True,3),binding('disabled',False,0),
            binding('capped',False,0),binding('branch',True,3,'case')]}}
reusable = {'value_bindings':{'bindings':[binding('active',True,3),binding('disabled',True,3),
            binding('capped',False,0),binding('branch',True,3,'case')]}}
choices,domains,weights = storage.discover(baseline,reusable)
assert choices == {'value_scratch_reuse.active':1,'value_scratch_reuse.disabled':0}
assert domains == {'value_scratch_reuse.active':(1,0),'value_scratch_reuse.disabled':(0,1)}
assert weights == {'active':4,'disabled':4}
for report in (baseline,reusable):
    for b in report['value_bindings']['bindings']:
        b['output_policy']='value_output_schedule.'+b['name']
        b['codegen'].update(output_schedule=b['name']!='disabled',early_outputs=0)
reusable['value_bindings']['bindings'][1]['codegen'].update(output_schedule=True,early_outputs=2)
with_schedules, schedule_domains, schedule_weights=storage.discover(baseline,reusable,True)
assert with_schedules==dict(choices,**{'value_output_schedule.disabled':0})
assert schedule_domains['value_output_schedule.disabled']==(0,1)
assert schedule_weights==weights
probe = {'measurements':{
    'active@one':{'binding':'active','stack_bytes':2,'mean_us':3,'samples':[{'index':0,'us':3}]},
    'active@two':{'binding':'active','stack_bytes':4,'mean_us':5,'samples':[{'index':0,'us':5}]},
    'disabled@one':{'binding':'disabled','stack_bytes':1,'mean_us':2,'samples':[{'index':0,'us':2}]}}}
metrics = storage.probe_metrics(probe,weights)
assert metrics['helper_stack']==4 and metrics['weighted_helper_us']==24
assert metrics['active@two:sample:0']==5 and metrics['active@two:stack']==4
print("Storage search: applicable reuse/schedule choices, source caps, per-instance guards and shared frequency weights passed")

# The C/reference project is independent of solver revisions and pure-helper
# vector counts. Its other inputs, generated includes and measured artifacts
# remain mandatory; no new target build is needed to exercise cache invalidation.
with tempfile.TemporaryDirectory() as temporary:
    root=Path(temporary);profile=root/'reference';profile.mkdir()
    binary=profile/'image';binary.write_bytes(b'validated C image')
    validation=root/'results.json'
    validation.write_text(json.dumps({'reference':{'additional_stack_bytes':'8',
        'ghost_active_us':'12.5','ghost_skipped_us':'3.25'}}))
    identity={'solver_sha256':'first','probe':{'samples':16},'files':{'source':'original'},
              'reference_generated_sha256':'generated','environment':{'CFLAGS':'-O2'}}
    cache=storage.search.MeasurementCache(root/'cache',storage.reference_identity(identity))
    measurement=storage.reference_measurement(profile,validation,storage.search.tree_fingerprint(profile))
    cache.save({},measurement)
    changed=copy.deepcopy(identity);changed.update(solver_sha256='second',probe={'samples':32})
    reused=storage.cached_reference(storage.search.MeasurementCache(root/'cache',storage.reference_identity(changed)))
    assert reused['directory']==str(profile) and reused['metrics']['stack']==8
    for key,value in [('files',{'source':'edited'}),('reference_generated_sha256','edited'),
                      ('environment',{'CFLAGS':'-O0'})]:
        edited=dict(identity,**{key:value})
        assert storage.cached_reference(storage.search.MeasurementCache(root/'cache',storage.reference_identity(edited))) is None
    wrong=copy.deepcopy(measurement);wrong['directory']=str(root/'different')
    cache.save({},wrong)
    assert storage.cached_reference(cache) is None
    cache.save({},measurement)
    binary.write_bytes(b'edited image')
    assert storage.cached_reference(cache) is None
    try:
        cache.save({},measurement)
        raise AssertionError('a reference changed since validation entered the cache')
    except ValueError:
        pass
print("Reference reuse: solver/vector changes reusable; source, generated inputs, flags, directory substitution and edited images rejected")

# Editable candidate directories are independent artifacts. A copied manifest
# must not validate the untouched original instead of the selected copy.
(game/'build').mkdir(exist_ok=True)
with tempfile.TemporaryDirectory(prefix='generation-check-',dir=game/'build') as temporary:
    root=Path(temporary);original=root/'original';copied=root/'copied';original.mkdir()
    source=root/'input.vx';source.write_text('&^entry(){1}')
    (original/'resolution.json').write_text('{}\n')
    (original/'vx_support_value_test.h').write_text('/* original */\n')
    files=[source,*original.iterdir()]
    manifest={'files':{str(p.relative_to(game)):storage.search.fingerprint(p) for p in files}}
    (original/'manifest.json').write_text(json.dumps(manifest))
    shutil.copytree(original,copied)
    command=['python3',str(game/'tools/generate_quest.py'),'--check','--output',str(copied)]
    assert subprocess.run(command,capture_output=True,timeout=30).returncode==0
    (copied/'vx_support_value_test.h').write_text('/* edited copy */\n')
    assert subprocess.run(command,capture_output=True,timeout=30).returncode!=0
    shutil.copyfile(original/'vx_support_value_test.h',copied/'vx_support_value_test.h')
    (original/'vx_support_value_test.h').unlink()
    assert subprocess.run(command,capture_output=True,timeout=30).returncode==0
print("Copied generation: validates local products, rejects local edits and does not require old product paths")
