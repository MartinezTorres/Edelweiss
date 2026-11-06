#!/usr/bin/env python3
"""Export the portable Vexel projection; ordinary game builds need no solver."""
import argparse
import hashlib
import json
import re
from pathlib import Path
import shutil
import subprocess
import tempfile

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "gameplay/quests.vx"
OUTPUT = ROOT / "generated/quests"
FILES = ("vexel.h", "vx_bridges.c", "source-plan.json")
PARTS = ("vx_quests.inc", "vx_services.inc")


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
            [str(solver), str(SOURCE), "--source", "lumberjack", "--source", "pear",
             "--source", "stew", "--source", "university", "--source", "shop_stock", "--source", "shop_trade",
             "--mode", "serial", "--emit-c", str(target)],
            cwd=ROOT, capture_output=True, text=True)
        if result.returncode:
            raise SystemExit(result.stderr or result.stdout or "Vexel resolution failed")
        plan = json.loads(result.stdout)
        # Keep the solver's full report alongside the editable C projection.
        for name in FILES:
            shutil.copyfile(target / name, OUTPUT / name)
        # Package the portable projection into two legacy mapper modules.
        # Keep its bodies/ABI unchanged, and fail if this fixed embedding's
        # assumptions stop matching a future solver emission.
        code = (target / "vx_bridges.c").read_text()
        functions = re.findall(r"^void vx_(\w+)\(", code, re.M)
        if functions != ["lumberjack", "pear", "stew", "university", "shop_stock", "shop_trade"] or plan["runtime_functions"]:
            raise SystemExit("Projection layout changed; review the Konami-5 module split")
        quests, marker, services = code.partition("void vx_stew(")
        (OUTPUT / PARTS[0]).write_text(quests)
        (OUTPUT / PARTS[1]).write_text('#include "vexel.h"\n' + marker + services)
        (OUTPUT / "resolution.json").write_text(json.dumps(plan, indent=2) + "\n")
    paths = [Path(item["path"]) for item in plan["source_inputs"]]
    paths += [OUTPUT / name for name in (*FILES, *PARTS)]
    manifest = {"solver_sha256": digest(solver), "files": {
        str(path.relative_to(ROOT)): digest(path) for path in paths}}
    (OUTPUT / "manifest.json").write_text(json.dumps(manifest, indent=2) + "\n")


if __name__ == "__main__":
    main()
