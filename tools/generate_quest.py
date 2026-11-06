#!/usr/bin/env python3
"""Export the portable Vexel projection; ordinary game builds need no solver."""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "gameplay/lumberjack.vx"
OUTPUT = ROOT / "generated/lumberjack"
FILES = ("vexel.h", "vx_bridges.c", "source-plan.json")


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--solver", default="../../build/vexel")
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    if args.check:
        manifest = json.loads((OUTPUT / "manifest.json").read_text())
        for name, expected in manifest["files"].items():
            if digest(ROOT / name) != expected:
                raise SystemExit(f"Stale Vexel projection: {name}; run make generate")
        return
    solver = Path(args.solver).resolve()
    OUTPUT.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix="edelweiss-vexel-") as temporary:
        target = Path(temporary) / "generated"
        result = subprocess.run(
            [str(solver), "gameplay/lumberjack.vx", "--source", "lumberjack",
             "--mode", "serial", "--emit-c", str(target)],
            cwd=ROOT, capture_output=True, text=True)
        if result.returncode:
            raise SystemExit(result.stderr or result.stdout or "Vexel resolution failed")
        plan = json.loads(result.stdout)
        # Keep the solver's full report alongside the editable C projection.
        for name in FILES:
            shutil.copyfile(target / name, OUTPUT / name)
        (OUTPUT / "resolution.json").write_text(json.dumps(plan, indent=2) + "\n")
    paths = [SOURCE, *(OUTPUT / name for name in FILES)]
    manifest = {"solver_sha256": digest(solver), "files": {
        str(path.relative_to(ROOT)): digest(path) for path in paths}}
    (OUTPUT / "manifest.json").write_text(json.dumps(manifest, indent=2) + "\n")


if __name__ == "__main__":
    main()
