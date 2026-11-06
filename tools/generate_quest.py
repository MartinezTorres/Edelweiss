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
PARTS = ("vx_quests.inc", "vx_services.inc", "vx_password.inc", "vx_password_encode.inc")


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
             "--source", "password_encode", "--source", "password_decode",
             "--mode", "serial", "--emit-c", str(target)],
            cwd=ROOT, capture_output=True, text=True)
        if result.returncode:
            raise SystemExit(result.stderr or result.stdout or "Vexel resolution failed")
        plan = json.loads(result.stdout)
        # Keep the solver's full report alongside the editable C projection.
        for name in FILES:
            shutil.copyfile(target / name, OUTPUT / name)
        # Package the portable projection into legacy mapper modules.
        # Keep its bodies/ABI unchanged, and fail if this fixed embedding's
        # assumptions stop matching a future solver emission.
        code = (target / "vx_bridges.c").read_text()
        functions = re.findall(r"^void vx_(\w+)\(", code, re.M)
        if functions != ["flow_0", "flow_1", "flow_2", "flow_3", "flow_4", "flow_5", "flow_6", "flow_7", "lumberjack", "pear", "stew", "university", "shop_stock", "shop_trade", "password_encode", "password_decode"] or len(plan["runtime_functions"]) != 8:
            raise SystemExit("Projection layout changed; review the Konami-5 module split")
        # Helper 2 belongs only to encoding; the others only to decoding.
        # Encoding stays with its page-C adapter, decoding runs in page B.
        frames = {f["name"]: f for f in plan["frame_planning"]["functions"]}
        for i in range(8):
            owner = "vx_password_encode" if i == 2 else "vx_password_decode"
            if frames[f"vx_flow_{i}"]["source_occurrences"] != [owner]:
                raise SystemExit("Password helper ownership changed; review bank placement")
        prelude, helper_marker, helpers_and_sources = code.partition("void vx_flow_0(")
        helpers, arena_marker, sources = helpers_and_sources.partition("uint8_t vx_payload[")
        code = prelude + arena_marker + sources
        quests, marker, services = code.partition("void vx_stew(")
        services, password_marker, password = services.partition("void vx_password_encode(")
        (OUTPUT / PARTS[0]).write_text(quests)
        (OUTPUT / PARTS[1]).write_text('#include "vexel.h"\n' + marker + services)
        before_encode_helper, encode_helper_marker, after_encode_helper = helpers.partition("void vx_flow_2(")
        encode_helper, next_helper_marker, decode_helpers = after_encode_helper.partition("void vx_flow_3(")
        encode, decode_marker, decode = password.partition("void vx_password_decode(")
        (OUTPUT / PARTS[2]).write_text('#include "vexel.h"\n' + helper_marker + before_encode_helper + next_helper_marker + decode_helpers + decode_marker + decode)
        (OUTPUT / PARTS[3]).write_text('#include "vexel.h"\n' + encode_helper_marker + encode_helper + password_marker + encode)
        (OUTPUT / "resolution.json").write_text(json.dumps(plan, indent=2) + "\n")
    paths = [Path(item["path"]) for item in plan["source_inputs"]]
    paths += [OUTPUT / name for name in (*FILES, *PARTS)]
    manifest = {"solver_sha256": digest(solver), "files": {
        str(path.relative_to(ROOT)): digest(path) for path in paths}}
    (OUTPUT / "manifest.json").write_text(json.dumps(manifest, indent=2) + "\n")


if __name__ == "__main__":
    main()
