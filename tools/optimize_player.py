#!/usr/bin/env python3
"""Compile, validate and measure a finite set of player movement realizations.

Every run owns new build directories. The selected project remains editable;
the search does not replace checked-in generated files or compiler settings.
"""
import argparse
import importlib.util
import json
import os
from pathlib import Path
import re
import shlex
import shutil
import signal
import subprocess
import tempfile
import time

GAME = Path(__file__).resolve().parents[1]
ROOT = GAME.parents[1]
spec = importlib.util.spec_from_file_location("measured_search", ROOT / "backends/msx-neo8/tools/optimize.py")
search = importlib.util.module_from_spec(spec)
spec.loader.exec_module(search)


def input_identity(solver):
    """Common inputs, excluding each candidate's explicit physical choices."""
    files = [GAME / "Makefile", ROOT / "experimental/relational/program_image.py",
             ROOT / "backends/msx-neo8/tools/optimize.py"]
    for directory in ("gameplay", "src", "tools", "tests", "vendor/sdcc_msx/inc", "vendor/sdcc_msx/src",
                      "vendor/sdcc_msx/util"):
        files.extend(p for p in (GAME / directory).rglob("*") if p.is_file() and
                     "__pycache__" not in p.parts and p.suffix != ".pyc")
    files.extend((ROOT / "lib").rglob("*.vx"))
    commands = {name: os.environ.get(variable, name) for variable, name in
                (("CC", "cc"), ("CXX", "g++"), ("SDCC", "sdcc"), ("SDASZ80", "sdasz80"), ("PYTHON", "python3"))}
    commands.update({name: name for name in ("openmsx", "make", "pkg-config")})
    environment = ("CC", "CXX", "CFLAGS", "CPPFLAGS", "LDFLAGS", "SDCC", "SDASZ80", "PYTHON",
                   "MAKEFLAGS", "MAKEOVERRIDES", "MFLAGS", "PATH", "PKG_CONFIG_PATH", "LD_LIBRARY_PATH",
                   "CPATH", "C_INCLUDE_PATH", "CPLUS_INCLUDE_PATH", "LIBRARY_PATH",
                   "SDCC_INCLUDE", "SDCC_LIB", "SDCC_HOME", "SOURCE_DATE_EPOCH")
    return {"solver_sha256": search.fingerprint(solver),
            "files": {str(p.relative_to(ROOT)): search.fingerprint(p) for p in sorted(set(files))},
            "environment": {name: os.environ.get(name) for name in environment},
            "tools": {name: {"command": command, "sha256": search.fingerprint(shutil.which(shlex.split(command)[0]))}
                      for name, command in commands.items()}}


def checked_baseline(previous, identity, choices):
    if previous.get("input_identity") != identity:
        raise ValueError("baseline inputs changed or were not recorded; run a fresh optimization search")
    entry = next(e for e in previous["candidates"]
                 if e["candidate"]["name"] == "baseline" and e["status"] == "accepted")
    if entry["candidate"] != choices:
        raise ValueError("baseline build preferences changed; run a fresh optimization search")
    return search.checked(entry["measurement"])


def callback_metrics(profiles):
    """Guard other callbacks too: a RAM-plan change can affect their storage."""
    result = {}
    for family, groups in profiles.items():
        for elapsed, group in groups.items():
            if elapsed == "samples":
                continue
            result[f"{family}_dt{elapsed}_stack"] = group["additional_stack_bytes"]
            result[f"{family}_dt{elapsed}_us"] = group["mean_us"]
    return result


def encounter_metrics(log):
    match = re.search(r"vexel: crowd frame ([\d.]+) us mean,.*additional stack (\d+) bytes", log)
    if not match:
        raise ValueError("missing encounter measurements")
    return {"encounter_us": float(match[1]), "encounter_stack": int(match[2])}


def regression_limits():
    limits = {"stack": [1, None], "ram_end": [None, 53248], "occupied_rom": [None, 16 * 1024 * 1024],
              "encounter_us": [1.02, None], "encounter_stack": [1, None]}
    for family, groups in (("player", (0, 1, 2, 3)), ("ball", (1,)),
                           ("spark", (0, 1, 2, 3, 255)), ("explosion", (0, 1, 2, 3, 255))):
        for elapsed in groups:
            limits[f"{family}_dt{elapsed}_stack"] = [1, None]
            limits[f"{family}_dt{elapsed}_us"] = [1.02, None]
    return limits


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--solver", type=Path, default=ROOT / "build/vexel")
    parser.add_argument("--seconds", type=int, default=1800)
    parser.add_argument("--jobs", type=int, default=2)
    parser.add_argument("--frame-bytes", type=int, default=96,
                        help="baseline fixed-workspace budget, as in make generate")
    parser.add_argument("--choice-branches", type=int, default=8,
                        help="branch-specialization budget shared by every candidate")
    parser.add_argument("--baseline-report", type=Path,
                        help="reuse a checked baseline from a previous selection report; recheck all hashes")
    args = parser.parse_args()
    if args.seconds <= 0 or args.jobs <= 0:
        parser.error("--seconds and --jobs must be positive")
    if not 0 <= args.frame_bytes <= 12288 or not 0 <= args.choice_branches <= 8:
        parser.error("--frame-bytes must be in 0..12288 and --choice-branches must be in 0..8")
    parent = GAME / "build/player-optimization"
    parent.mkdir(parents=True, exist_ok=True)
    workspace = Path(tempfile.mkdtemp(prefix="run-", dir=parent))
    solver = workspace / "vexel"
    # Pin the executable for the entire experiment, even if another developer
    # rebuilds the working compiler while the candidates are being measured.
    shutil.copy2(args.solver.resolve(), solver)
    identity = input_identity(solver)
    identity_path = workspace / "input-identity.json"
    identity_path.write_text(json.dumps(identity, indent=2) + "\n")
    print("Optimization evidence:", workspace, flush=True)
    started = time.monotonic()
    commands = []

    def run(command, log, *, env=None, timeout=600):
        remaining = args.seconds - (time.monotonic() - started)
        if remaining <= 0:
            raise TimeoutError("optimization wall budget exhausted")
        command = list(map(str, command))
        entry = {"argv": command, "cwd": str(GAME), "log": str(log)}
        commands.append(entry)
        (workspace / "commands.json").write_text(json.dumps(commands, indent=2) + "\n")
        began = time.monotonic()
        with Path(log).open("w") as out:
            process = subprocess.Popen(command, cwd=GAME, env=env, stdout=out, stderr=subprocess.STDOUT,
                                       start_new_session=True)
            try:
                process.wait(timeout=min(timeout, remaining))
            except BaseException:
                # Bound the whole build, including SDCC and solver children.
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
                entry.update(elapsed_seconds=time.monotonic() - began, returncode=process.poll())
                (workspace / "commands.json").write_text(json.dumps(commands, indent=2) + "\n")
        if process.returncode:
            raise RuntimeError(f"command failed ({process.returncode}); see {log}")

    # A single immutable reference is shared by all equivalence checks. A
    # resumed experiment may retain its measured baseline, but not stale files
    # or a changed player trace. New alternatives still run every validator.
    candidates = [
        {"name": "baseline", "region": 0, "banked": 1, "copy_schedule": 1, "frame_bytes": args.frame_bytes, "max_allocs": 2000},
        {"name": "region-local", "region": 1, "banked": 0, "copy_schedule": 1, "frame_bytes": 128, "max_allocs": 2000},
        {"name": "region", "region": 1, "banked": 1, "copy_schedule": 1, "frame_bytes": 128, "max_allocs": 2000},
        {"name": "region-buffered", "region": 1, "banked": 0, "copy_schedule": 0, "frame_bytes": 128, "max_allocs": 2000},
    ]
    for candidate in candidates:
        candidate["choice_branches"] = args.choice_branches
    baseline = None
    if args.baseline_report:
        previous = json.loads(args.baseline_report.read_text())
        baseline = checked_baseline(previous, identity, candidates[0])
        timing = next(Path(a["path"]) for a in baseline["artifacts"] if a["path"].endswith("/actors-callback-timing.json"))
        baseline["metrics"].update(callback_metrics(json.loads(timing.read_text())["vexel"]))
        encounter = next(Path(a["path"]) for a in baseline["artifacts"] if a["path"].endswith("/encounter.log"))
        baseline["metrics"].update(encounter_metrics(encounter.read_text()))
        baseline_rom = next(Path(a["path"]) for a in baseline["artifacts"] if a["path"].endswith("/weiss.rom"))
        reference_profile = (baseline_rom.parents[2] / "reference-encounter").resolve()
        provenance = json.loads((baseline_rom.parents[2] / "callbacks/provenance.json").read_text())
        if search.fingerprint(reference_profile / "msx/weiss.rom") != provenance["roms"]["reference"]["rom_sha256"]:
            raise ValueError("baseline reference ROM changed")
    else:
        reference = workspace / "reference"
        run(["make", f"-j{args.jobs}", "GAMEPLAY=reference", "ENCOUNTER=1", f"BUILD_ROOT={reference}", "all"],
            workspace / "reference-build.log")
        reference_profile = reference / "reference-encounter"
    projections = {}
    def evaluate(candidate, remaining):
        nonlocal baseline
        if input_identity(solver) != identity:
            raise ValueError("optimization inputs changed during measurement")
        if candidate["name"] == "baseline" and baseline is not None:
            return search.checked(baseline)
        directory = workspace / candidate["name"]
        directory.mkdir()
        schedule = candidate["copy_schedule"]
        key = schedule, candidate["frame_bytes"], candidate["region"]
        if key not in projections:
            generated = workspace / f"projection-{schedule}-{candidate['frame_bytes']}-{candidate['region']}"
            run(["python3", "tools/generate_quest.py", "--solver", solver, "--output", generated,
                 "--player-region", candidate["region"],
                 "--prefer", f"region_copy_schedule={schedule}", "--prefer", f"value_frame_bytes={candidate['frame_bytes']}",
                 "--prefer", f"value_choice_branches={candidate['choice_branches']}"], directory / "generate.log")
            projections[key] = generated
        generated = projections[key]
        env = dict(os.environ, EDW_GENERATED=str(generated), EDW_PLAYER_REGION=str(candidate["region"]),
                   EDW_PLAYER_REGION_BANKED=str(candidate["banked"]),
                   EDW_TEST_BUILD=str(directory / "host"))
        run(["python3", "tests/check_quest.py"], directory / "host-validation.log", env=env)
        shutil.copy2(directory / "host/player-vexel.txt", directory / "player-trace.txt")
        if baseline is not None:
            expected = next(a["sha256"] for a in baseline["artifacts"] if a["path"].endswith("/player-trace.txt"))
            if search.fingerprint(directory / "player-trace.txt") != expected:
                raise ValueError("candidate's player trace differs from the retained baseline")
        run(["make", f"-j{args.jobs}", "ENCOUNTER=1", f"BUILD_ROOT={directory}",
             f"GENERATED={generated}", f"PLAYER_REGION={candidate['region']}",
             f"PLAYER_REGION_BANKED={candidate['banked']}",
             f"MAX_ALLOCS={candidate['max_allocs']}", "all"], directory / "build.log")
        (directory / "reference-encounter").symlink_to(reference_profile, target_is_directory=True)
        run(["python3", "tests/check_encounter.py", "--build-root", directory], directory / "encounter.log", timeout=120)
        run(["python3", "tests/profile_actor_callbacks.py", "--build-root", directory], directory / "timing.log", timeout=150)
        profiles = json.loads((directory / "callbacks/actors-callback-timing.json").read_text())["vexel"]
        profile = profiles["player"]
        rom = directory / "vexel-encounter/msx/weiss.rom"
        layout = json.loads(Path(str(rom) + ".layout.json").read_text())["modules"]
        areas = [a for m in layout for a in m["areas"]]
        metrics = {"stack": max(profile[str(dt)]["additional_stack_bytes"] for dt in range(4)),
                   "time": sum(profile[str(dt)]["mean_us"] for dt in (1, 2, 3)),
                   "ram_end": max(a["address"] + a["size"] for a in areas if a["name"] == "_DATA"),
                   "occupied_rom": sum(a["size"] for a in areas if a["name"] != "_DATA")}
        metrics.update({f"dt{dt}_us": profile[str(dt)]["mean_us"] for dt in range(4)})
        metrics.update(callback_metrics(profiles))
        metrics.update(encounter_metrics((directory / "encounter.log").read_text()))
        evidence = [rom, Path(str(rom) + ".layout.json"), Path(str(rom) + ".sym"),
                    directory / "vexel-encounter/linux/weiss", reference_profile / "msx/weiss.rom",
                    reference_profile / "linux/weiss", generated / "manifest.json", generated / "resolution.json",
                    directory / "player-trace.txt", directory / "host-validation.log", directory / "encounter.log", directory / "encounter/results.json",
                    directory / "callbacks/actors-callback-timing.json", directory / "callbacks/provenance.json", solver, identity_path]
        if input_identity(solver) != identity:
            raise ValueError("optimization inputs changed during measurement")
        result = {"validated": True, "metrics": metrics,
                  "scope": "player callback samples in the encounter; measured stack, not a worst-case proof",
                  "artifacts": [{"path": str(p), "sha256": search.fingerprint(p)} for p in evidence]}
        print(candidate["name"], metrics, flush=True)
        if candidate["name"] == "baseline":
            baseline = result
        return result

    limits = regression_limits()
    remaining = args.seconds - (time.monotonic() - started)
    result = search.search(candidates, evaluate, workspace / "selection.json", objective=["stack", "time", "occupied_rom"],
                           limits=limits, seconds=remaining, max_candidates=4)
    result["input_identity"] = identity
    result["input_validation"] = "passed" if input_identity(solver) == identity else "failed"
    (workspace / "selection.json").write_text(json.dumps(result, indent=2) + "\n")
    if result["input_validation"] != "passed":
        raise ValueError("optimization inputs changed before selection completed")
    print("Selected:", result["selected"], "—", workspace / "selection.json", flush=True)
    (parent / "latest.json").write_text(json.dumps({"directory": str(workspace), "selected": result["selected"],
                                                  "report": str(workspace / "selection.json")}, indent=2) + "\n")


if __name__ == "__main__":
    main()
