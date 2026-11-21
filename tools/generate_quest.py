#!/usr/bin/env python3
"""Export the portable Vexel projection; ordinary game builds need no solver."""
import argparse
import hashlib
import json
import importlib.util
from pathlib import Path
import subprocess
import tempfile
import sprite_assets

ROOT = Path(__file__).resolve().parents[1]
SOURCE = ROOT / "gameplay/quests.vx"
OUTPUT = ROOT / "generated/quests"
IMAGE_READER = ROOT.parents[1] / "experimental/relational/program_image.py"
NATIVE_BOUNDARIES = ROOT / "src/gameplay/native_boundaries.json"
NATIVE_IMPLEMENTATION = ROOT / "src/gameplay/native_world.inc"


def digest(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def write_text(path, content):
    # Changing the allocation plan should only rebuild affected interfaces.
    data = content.encode()
    if not path.exists() or path.read_bytes() != data:
        path.write_bytes(data)


def check_generated(output):
    manifest = json.loads((output / "manifest.json").read_text())
    files = manifest["files"]
    # A copied generation keeps its original provenance paths. Check its
    # selected local products, not a different generation left at those paths.
    owners = [Path(name).parent for name in files if Path(name).name == "resolution.json"]
    if len(owners) != 1:
        raise SystemExit("Generation manifest needs one resolution report; run make generate")
    for name, expected in files.items():
        recorded = Path(name)
        path = output / recorded.name if recorded.parent == owners[0] else ROOT / recorded
        if not path.is_file() or digest(path) != expected:
            raise SystemExit(f"Stale Vexel projection: {path}; run make generate")


def main():
    global OUTPUT
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--solver", default="../../build/vexel")
    parser.add_argument("--check", action="store_true")
    parser.add_argument("--output", type=Path, default=OUTPUT)
    parser.add_argument("--prefer", action="append", default=[])
    parser.add_argument("--player-region", type=int, choices=(0, 1), default=0,
                        help="Account for the optional native player-region call site in storage selection")
    args = parser.parse_args()
    OUTPUT = args.output.resolve()
    if args.check:
        check_generated(OUTPUT)
        return
    solver = Path(args.solver).resolve()
    native_config = json.loads(NATIVE_BOUNDARIES.read_text())
    if not isinstance(native_config, dict) or set(native_config) != {"expansions", "preferences"}:
        raise SystemExit("Native boundary configuration needs expansions and preferences")
    native = native_config["expansions"]
    if not isinstance(native, dict) or not all(isinstance(k, str) and isinstance(v, str) for k, v in native.items()):
        raise SystemExit("Native boundary offers must map symbols to C macro names")
    preferences = native_config["preferences"]
    if not isinstance(preferences, dict) or not all(isinstance(k, str) and type(v) is int and v >= 0 for k, v in preferences.items()):
        raise SystemExit("Native boundary defaults must map preference names to nonnegative integers")
    # Project defaults are replaceable by explicit experiment choices. The
    # resulting CLI contributions still obey Vexel's normal minimum rule.
    explicit = {p.partition("=")[0] for p in args.prefer}
    args.prefer += [f"{key}={value}" for key, value in sorted(preferences.items()) if key not in explicit]
    if not args.player_region:
        args.prefer.append("binding_frequency.player_motion=0")
    OUTPUT.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory(prefix="edelweiss-vexel-") as temporary:
        target = Path(temporary) / "generated"
        result = subprocess.run(
            [str(solver), str(SOURCE), "--program", "--mode", "serial",
             *[x for name, macro in sorted(native.items()) for x in ("--boundary-expansion", name + ":" + macro)],
             *[x for p in args.prefer for x in ("--prefer", p)], "--emit-c", str(target)],
            cwd=ROOT, capture_output=True, text=True)
        if result.returncode:
            raise SystemExit(result.stderr or result.stdout or "Vexel resolution failed")
        plan = json.loads(result.stdout)
        value_outputs = {
            "drop_roll": [("item", "#u8"), ("draw", "#u8")],
            "drop_collect": [("life", "#u8"), ("credit", "#u8")],
            "drop_spawn": [("enabled", "#u8"), ("frame", "#u8")],
            "drop_step": [("live", "#u8"), ("counter", "#u8"), ("visible", "#u8")],
            "fairy_move": [("fairy_move", "#u16")],
            "lumber_draw": [("facing", "#u8"), ("frame", "#u8")],
            "ghost_spawn": [("i", "#u16"), ("j", "#u16"), ("vi", "#i8"), ("vj", "#i8")],
            "ghost_update": [("run", "#u8"), ("life", "#u8"), ("i", "#u16"), ("j", "#u16"),
                             ("vi", "#i8"), ("vj", "#i8"), ("frame", "#u8")],
            "skeleti_tick": [("skeleti_tick", "#u8")],
            "skeleti_draws": [("skeleti_draws", "#u8")],
            "skeleti_update": [("action", "#u8"), ("delay", "#u8"), ("i", "#u16"), ("j", "#u16"), ("frame", "#u8")],
            "combat_hit": [("accepted", "#u8"), ("life", "#u8"), ("immunity", "#u8"), ("ticks", "#u8"), ("di", "#i8"), ("dj", "#i8")],
            "combat_tick": [("status", "#u8"), ("immunity", "#u8"), ("ticks", "#u8"), ("steps", "#u8"), ("visible", "#u8")],
            "combat_death": [("explosion", "#u8"), ("drop", "#u8")],
            "melee_style": [("damage", "#u8"), ("override", "#u8"), ("color0", "#u8"), ("color1", "#u8"), ("axe", "#u8")],
            "melee_hit": [("i", "#u16"), ("j", "#u16"), ("height", "#u8"), ("width", "#u8")],
            "melee_axe": [("i", "#u16"), ("j", "#u16")],
            "melee_cut": [("melee_cut", "#u8")],
            "melee_update": [("live", "#u8"), ("apply", "#u8"), ("counter", "#u8"), ("i", "#u16"), ("j", "#u16"), ("frame", "#u8"), ("small", "#u8")],
        }
        value_outputs.update({
            "projectile_spawn": [("i", "#u16"), ("j", "#u16"), ("vi", "#i8"), ("vj", "#i8"), ("frame", "#u8"), ("damage", "#u8")],
            "projectile_move": [("i", "#u16"), ("j", "#u16"), ("counter", "#u8"), ("frame", "#u8")],
            "bomb_step": [("spent", "#u8"), ("counter", "#u8"), ("live", "#u8"), ("frame", "#u8"), ("color", "#u8"), ("move", "#u8"), ("di", "#i16"), ("dj", "#i16"), ("query", "#u8")],
            "bomb_cut": [("bomb_cut", "#u8")],
        })
        value_outputs.update({'effect_step': [('live', '#u8'), ('counter', '#u8'), ('frame', '#u8')],
         'spark_frame': [('spark_frame', '#u8')],
         'ball_tick': [('run', '#u8'), ('move', '#u8'), ('counter', '#u8'), ('frame', '#u8')],
         'ball_leg': [('query', '#u8'), ('j', '#u16'), ('facing', '#u8'), ('counter', '#u8')],
         'ball_reply': [('i', '#u16'), ('j', '#u16'), ('facing', '#u8'), ('counter', '#u8')],
         'ball_home': [('ball_home', '#u16')],
         'player_keys': [('player_keys', '#u8')],
         'player_weapon': [('player_weapon', '#u8')],
         'player_attack': [('player_attack', '#u8')],
         'player_tick': [('skip', '#u8'), ('counter', '#u8'), ('move', '#u8')],
         'player_move': [('i', '#u16'), ('j', '#u16')],
         'player_slide': [('i', '#u16'), ('j', '#u16'), ('qi', '#u16'), ('qj', '#u16'), ('query', '#u8')],
         'player_draw': [('facing', '#u8'), ('frame', '#u8')],
         'player_view': [('i', '#u8'), ('j', '#u8'), ('request', '#u8')]})
        value_outputs.update({'scene_intro': [('action', '#u8'), ('movie', '#u8'), ('counter', '#u8'), ('i', '#u16'), ('j', '#u16'), ('facing', '#u8'), ('frame', '#u8'), ('again', '#u8')], 'scene_spark': [('slot', '#u8'), ('i', '#u8'), ('j', '#u8'), ('initialize', '#u8'), ('statue', '#u8')], 'scene_wipe': [('op', '#u8'), ('arg', '#u8'), ('round', '#u8'), ('step', '#u8')], 'scene_revive': [('scene_revive', '#u8')], 'scene_door': [('op', '#u8'), ('i', '#u16'), ('j', '#u16'), ('facing', '#u8'), ('frame', '#u8'), ('waits', '#u8')], 'scene_camera': [('i', '#u8'), ('j', '#u8'), ('request', '#u8')], 'world_frame': [('elapsed', '#u8'), ('cycle', '#u8')], 'world_window': [('world_window', '#u8')], 'world_follow': [('world_follow', '#u8')], 'world_scroll': [('i', '#u8'), ('j', '#u8'), ('row', '#u8'), ('col', '#u8'), ('second', '#u8'), ('transfer', '#u8')]})
        value_outputs.update({
            "world_start": [("coins", "#u8"), ("weapon", "#u8"), ("flower_i", "#u8"), ("flower_j", "#u8"), ("mi", "#u8"), ("mj", "#u8"), ("patch_i", "#u16"), ("patch_next_i", "#u16"), ("patch_j", "#u16"), ("patch_value", "#u8")],
            "weapon_setup": [("kind", "#u8"), ("slot", "#u8")],
            "world_seed": [("kind", "#u8"), ("slot", "#u8"), ("i", "#u8"), ("j", "#u8")],
            "scene_brief": [("text", "#u8"), ("next", "#u8"), ("marker", "#u8"), ("i", "#u8"), ("j", "#u8")],
        })
        value_outputs.update({'contact_box': [('contact_box', '#u8')],
 'contact_player': [('contact_player', '#u8')],
 'title_attract': [('ticks', '#u8'), ('poll', '#u8'), ('keys', '#u8'), ('quit', '#u8')],
 'title_frame': [('clock', '#u8'), ('spawn', '#u8'), ('skip', '#u8')],
 'title_seed': [('accept', '#u8'), ('position', '#u16'), ('kind', '#u8')],
 'title_step': [('op', '#u8'),
                ('a', '#u8'),
                ('b', '#u8'),
                ('phase', '#u8'),
                ('round', '#u8'),
                ('step', '#u8')],
 'ui_cursor': [('x', '#u8'), ('y', '#u8')],
 'ui_editor': [('length', '#u8'),
               ('character', '#u8'),
               ('accept', '#u8'),
               ('done', '#u8'),
               ('cursor', '#u8')],
 'ui_menu': [('option', '#u8'), ('confirm', '#u8')]})
        for source in plan["sources"]:
            if source["name"] in value_outputs:
                if not source["value_projection"]["available"]:
                    raise SystemExit(source["name"] + " value projection unavailable: " + source["value_projection"]["reason"])
                fields = [(leaf["path"].removeprefix(source["name"] + "."), leaf["logical_type"])
                          for leaf in source["leaves"]]
                if fields != value_outputs[source["name"]]:
                    raise SystemExit(source["name"] + " result layout changed; review the C adapter: " + str(fields))
            if source["name"] == "ghost_update":
                value = source["value_projection"]
                if value.get("branch_inputs") != [0, 1] or value.get("case_inputs") != [[], list(range(1, 11))]:
                    raise SystemExit("Ghost input dependencies changed; review the C adapter")
            if source["name"] == "skeleti_update":
                value = source["value_projection"]
                if value.get("branch_inputs") != [1] or value.get("case_inputs") != [[0, *range(2, 12)], [0, 1, 2, 5, 6]]:
                    raise SystemExit("Skeleti input dependencies changed; review the C adapter")
            if source["name"] == "combat_tick":
                value = source["value_projection"]
                if value.get("branch_inputs") != [0, 1, 2] or value.get("case_inputs") != [[0, 1, 2, 3], []]:
                    raise SystemExit("Combat input dependencies changed; review the resident fast path")
        # These are the C adapter's required interfaces, not storage choices.
        # Vexel selects each realization from its lifetime proof and RAM budget.
        expected_bindings = {
            "combat_hit": ("combat_hit", "full", list(range(6))),
            "combat_tick": ("combat_tick", "full", list(range(4))),
            "combat_idle": ("combat_tick", "case1", []),
            "combat_death": ("combat_death", "full", list(range(4))),
            "drop_roll": ("drop_roll", "full", list(range(3))),
            "drop_collect": ("drop_collect", "full", list(range(3))),
            "drop_spawn": ("drop_spawn", "full", [0]),
            "drop_step": ("drop_step", "full", list(range(3))),
            "fairy_move": ("fairy_move", "full", [0,1]),
            "lumber_draw": ("lumber_draw", "full", list(range(3))),
            "ghost_spawn": ("ghost_spawn", "full", list(range(3))),
            "ghost_move": ("ghost_update", "case1", list(range(1,11))),
            "skeleti_tick": ("skeleti_tick", "full", list(range(2))),
            "skeleti_draws": ("skeleti_draws", "full", list(range(3))),
            "skeleti_move": ("skeleti_update", "case0", [0,*range(2,12)]),
            "skeleti_wait": ("skeleti_update", "case1", [0,1,2,5,6]),
            "melee_style": ("melee_style", "full", [0]),
            "melee_hit": ("melee_hit", "full", list(range(4))),
            "melee_axe": ("melee_axe", "full", list(range(3))),
            "melee_cut": ("melee_cut", "full", [0]),
            "melee_update": ("melee_update", "full", list(range(6))),
        }
        expected_bindings.update({
            "projectile_spawn": ("projectile_spawn", "full", list(range(4))),
            "projectile_move": ("projectile_move", "full", list(range(7))),
            "bomb_step": ("bomb_step", "full", list(range(2))),
            "bomb_cut": ("bomb_cut", "full", [0]),
        })
        expected_bindings.update({'effect_step': ('effect_step', 'full', [0, 1]),
         'spark_frame': ('spark_frame', 'full', [0, 1]),
         'ball_tick': ('ball_tick', 'full', [0, 1, 2, 3]),
         'ball_leg': ('ball_leg', 'full', [0, 1, 2, 3, 4]),
         'ball_reply': ('ball_reply', 'full', [0, 1, 2, 3, 4, 5, 6, 7]),
         'ball_home': ('ball_home', 'full', [0, 1]),
         'player_keys': ('player_keys', 'full', [0]),
         'player_weapon': ('player_weapon', 'full', [0, 1]),
         'player_attack': ('player_attack', 'full', [0, 1]),
         'player_tick': ('player_tick', 'full', [0, 1]),
         'player_move': ('player_move', 'full', [0, 1, 2]),
         'player_slide': ('player_slide', 'full', [0, 1, 2, 3, 4, 5]),
         'player_draw': ('player_draw', 'full', [0, 1, 2]),
         'player_view': ('player_view', 'full', [0, 1, 2, 3, 4, 5, 6])})
        expected_bindings['player_motion'] = ('player_motion', 'region', list(range(7)))
        expected_bindings.update({'scene_intro': ('scene_intro', 'full', [0, 1, 2, 3]), 'scene_spark': ('scene_spark', 'full', [0, 1]), 'scene_wipe': ('scene_wipe', 'full', [0, 1, 2]), 'scene_revive': ('scene_revive', 'full', [0]), 'scene_door': ('scene_door', 'full', [0, 1, 2, 3, 4]), 'scene_camera': ('scene_camera', 'full', [0, 1, 2, 3, 4, 5, 6]), 'world_frame': ('world_frame', 'full', [0, 1, 2]), 'world_keep': ('world_window', 'case1', [1, 2, 3, 4]), 'world_spawn': ('world_window', 'case0', [1, 2, 3, 4]), 'world_follow': ('world_follow', 'full', [0, 1, 2, 3, 4, 5]), 'world_scroll': ('world_scroll', 'full', [0, 1, 2, 3, 4])})
        expected_bindings.update({"world_seed": ("world_seed", "full", [0]),
                                  "scene_brief": ("scene_brief", "full", [0])})
        expected_bindings.update({'contact_box': ('contact_box', 'full', [0, 1, 2, 3, 4, 5]),
 'contact_player': ('contact_player', 'full', [0, 1, 2, 3]),
 'title_attract': ('title_attract', 'full', [0, 1, 2]),
 'title_frame': ('title_frame', 'full', [0, 1]),
 'title_seed': ('title_seed', 'full', [0, 1, 2]),
 'title_step': ('title_step', 'full', [0, 1, 2, 3]),
 'ui_cursor': ('ui_cursor', 'full', [0, 1]),
 'ui_editor': ('ui_editor', 'full', [0, 1, 2]),
 'ui_menu': ('ui_menu', 'full', [0, 1, 2, 3]),
 'world_flow': ('world_flow', 'region', [])})
        expected_bindings['title_flow'] = ('title_flow','region',[])
        expected_bindings['world_start'] = ('world_start','full',[0,1])
        expected_bindings['weapon_setup'] = ('weapon_setup','full',[0,1])
        bindings = plan["value_bindings"]["bindings"]
        if {b["name"]: (b["source"],b["entry"],b["inputs"]) for b in bindings} != expected_bindings:
            raise SystemExit("Selected binding interfaces changed; review the C adapters")
        spec = importlib.util.spec_from_file_location("program_image", IMAGE_READER)
        images = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(images)
        image = images.load(target, plan)
        # This map expresses the engine's existing Konami-5 placement contract.
        # Function identities, helper ownership and source order come from Vexel.
        groups = {
            "vx_quests.inc": ["lumberjack", "pear"],
            "vx_services.inc": ["stew", "university", "shop_stock", "shop_trade"],
            "vx_password.inc": ["password_decode"],
            "vx_password_encode.inc": ["password_encode"],
            "vx_world.inc": ["world_route", "world_rocks", "world_well"],
            "vx_drops.inc": ["drop_roll", "drop_collect"],
            "vx_town.inc": ["town_door", "town_house", "town_board", "town_monster"],
        }
        owner = {"vx_"+name: file for file, names in groups.items() for name in names}
        chunks = {file: ['#include "vexel.h"\n'] for file in groups}
        chunks["vx_quests.inc"].append((target / image["support"]).read_text())
        for unit in image["units"]:
            if unit["kind"] == "source":
                destination = owner.get(unit["symbol"])
                if destination is None:
                    # These entries are embedded through their typed bindings.
                    if unit["symbol"].removeprefix("vx_") not in {b["source"] for b in bindings}:
                        raise SystemExit("Source lacks an engine embedding: " + unit["symbol"])
                    continue
            else:
                if unit["kind"] == "boundary" and all(n not in owner for n in unit["owners"]):
                    continue  # Typed region bindings own their boundary ABI.
                destinations = {owner.get(n) for n in unit["owners"]}
                if len(destinations) != 1 or None in destinations:
                    raise SystemExit("Helper requires an explicit shared-bank placement: " + unit["symbol"])
                destination = destinations.pop()
            # A unit's private arithmetic helpers belong with its code, even
            # when the engine places it in a separate translation unit/bank.
            # The shared support also owns global storage and is emitted once.
            if unit.get("support"):
                chunks[destination].append('#include "' + unit["support"] + '"\n')
            chunks[destination].append((target / unit["fragment"]).read_text())
        # Validate every product before publishing the new generation.
        sprite_assets.generate(plan, target)
        for file, bodies in chunks.items():
            (target / file).write_text("".join(bodies))
        (target / "vx_ghost.inc").write_text('#include "vx_value_ghost_spawn.h"\n#include "vx_value_ghost_update_cases.h"\n')
        generated_files = sorted(p.name for p in target.iterdir() if p.is_file())
        # Remove only unchanged products owned by the previous generation.
        # Detect edited obsolete products before publishing any replacement.
        obsolete = []
        previous = OUTPUT / "manifest.json"
        if previous.exists():
            for name, expected in json.loads(previous.read_text())["files"].items():
                path = ROOT / name
                if path.parent == OUTPUT and path.name not in (*generated_files, "resolution.json") and path.exists():
                    if digest(path) != expected:
                        raise SystemExit("Edited obsolete generated file needs review: " + str(path))
                    obsolete.append(path)
        for path in obsolete:
            path.unlink()
        for name in generated_files:
            write_text(OUTPUT / name, (target / name).read_text())
        write_text(OUTPUT / "resolution.json", json.dumps(plan, indent=2) + "\n")
    paths = [Path(item["path"]) for item in plan["source_inputs"]]
    paths += [OUTPUT / name for name in (*generated_files, "resolution.json")]
    paths += [Path(__file__).resolve(), Path(sprite_assets.__file__).resolve()]
    paths += [NATIVE_BOUNDARIES, NATIVE_IMPLEMENTATION]
    manifest = {"solver_sha256": digest(solver), "image_reader_sha256": digest(IMAGE_READER),
                "embedding": {"player_region": bool(args.player_region)}, "files": {
        str(path.relative_to(ROOT)): digest(path) for path in paths}}
    write_text(OUTPUT / "manifest.json", json.dumps(manifest, indent=2) + "\n")


if __name__ == "__main__":
    main()
