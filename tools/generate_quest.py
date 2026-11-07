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
PARTS = ("vx_quests.inc", "vx_services.inc", "vx_password.inc", "vx_password_encode.inc", "vx_world.inc", "vx_drops.inc", "vx_town.inc", "vx_ghost.inc")


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
             "--source", "world_route", "--source", "world_rocks", "--source", "world_well",
             "--source", "drop_roll", "--source", "drop_collect",
             "--source", "town_door", "--source", "town_house", "--source", "town_board", "--source", "town_monster",
             "--source", "ghost_spawn", "--source", "ghost_tick", "--source", "ghost_axis", "--source", "ghost_frame",
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
        if functions != [*[f"flow_{i}" for i in range(9)], "lumberjack", "pear", "stew", "university", "shop_stock", "shop_trade", "password_encode", "password_decode", "world_route", "world_rocks", "world_well", "drop_roll", "drop_collect", "town_door", "town_house", "town_board", "town_monster", "ghost_spawn", "ghost_tick", "ghost_axis", "ghost_frame"] or len(plan["runtime_functions"]) != 9:
            raise SystemExit("Projection layout changed; review the Konami-5 module split")
        # Place materialized helpers with their source owner. Helper numbering
        # may change when another source is added; ownership must not.
        frames = {f["name"]: f for f in plan["frame_planning"]["functions"]}
        prelude, helper_marker, helpers_and_sources = code.partition("void vx_flow_0(")
        helpers, arena_marker, sources = helpers_and_sources.partition("uint8_t vx_payload[")
        helpers = helper_marker + helpers
        grouped = {"vx_password_encode": [], "vx_password_decode": [], "vx_ghost_axis": []}
        chunks = re.split(r"(?=^void vx_flow_\d+\()", helpers, flags=re.M)
        for chunk in chunks:
            if not chunk.strip():
                continue
            name = re.match(r"void (vx_flow_\d+)\(", chunk)[1]
            owners = frames[name]["source_occurrences"]
            if len(owners) != 1 or owners[0] not in grouped:
                raise SystemExit("Helper ownership changed; review bank placement")
            grouped[owners[0]].append(chunk)
        if [len(grouped[k]) for k in grouped] != [1, 7, 1]:
            raise SystemExit("Helper layout changed; review bank placement")
        code = prelude + arena_marker + sources
        quests, marker, services = code.partition("void vx_stew(")
        services, password_marker, password = services.partition("void vx_password_encode(")
        password, world_marker, world = password.partition("void vx_world_route(")
        world, drops_marker, drops = world.partition("void vx_drop_roll(")
        drops, town_marker, town = drops.partition("void vx_town_door(")
        town, ghost_marker, ghost = town.partition("void vx_ghost_spawn(")
        (OUTPUT / PARTS[4]).write_text('#include "vexel.h"\n' + world_marker + world)
        (OUTPUT / PARTS[5]).write_text('#include "vexel.h"\n' + drops_marker + drops)
        (OUTPUT / PARTS[6]).write_text('#include "vexel.h"\n' + town_marker + town)
        (OUTPUT / PARTS[7]).write_text('#include "vexel.h"\n' + "".join(grouped["vx_ghost_axis"]) + ghost_marker + ghost)
        (OUTPUT / PARTS[0]).write_text(quests)
        (OUTPUT / PARTS[1]).write_text('#include "vexel.h"\n' + marker + services)
        encode, decode_marker, decode = password.partition("void vx_password_decode(")
        (OUTPUT / PARTS[2]).write_text('#include "vexel.h"\n' + "".join(grouped["vx_password_decode"]) + decode_marker + decode)
        (OUTPUT / PARTS[3]).write_text('#include "vexel.h"\n' + "".join(grouped["vx_password_encode"]) + password_marker + encode)
        (OUTPUT / "resolution.json").write_text(json.dumps(plan, indent=2) + "\n")
    paths = [Path(item["path"]) for item in plan["source_inputs"]]
    paths += [OUTPUT / name for name in (*FILES, *PARTS)]
    manifest = {"solver_sha256": digest(solver), "files": {
        str(path.relative_to(ROOT)): digest(path) for path in paths}}
    (OUTPUT / "manifest.json").write_text(json.dumps(manifest, indent=2) + "\n")


if __name__ == "__main__":
    main()
