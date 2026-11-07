#!/usr/bin/env python3
"""Compare the original gameplay callbacks with the Vexel-backed callbacks."""
import os
from pathlib import Path
import shlex
import subprocess

ROOT = Path(__file__).resolve().parents[1]
BUILD = ROOT / "build/tests"
BUILD.mkdir(parents=True, exist_ok=True)
CC = shlex.split(os.environ.get("CC", "cc"))
FLAGS = ["-std=gnu99", "-O1", "-g", "-DLINUX", "-Isrc", "-Ivendor/sdcc_msx/inc",
         "-Isrc/gameplay", "-Igenerated/quests", "-ffunction-sections", "-fdata-sections",
         "-fsanitize=undefined", "-fno-sanitize-recover=all", "-Wl,--gc-sections"]


def build_run(name, sources, extra=()):
    binary = BUILD / name
    subprocess.run([*CC, *FLAGS, *extra, *sources, "-o", str(binary)], cwd=ROOT, check=True)
    result = subprocess.run([str(binary)], cwd=ROOT, check=True, capture_output=True, text=True)
    (BUILD / f"{name}.txt").write_text(result.stdout)
    return result.stdout


step = build_run("quest-step", ["tests/quest_step.c", "src/gameplay/quest_text.c",
                               "generated/quests/vx_bridges.c"])
sources = ["tests/quest_integration.c", "src/common.c", "src/entities/npcs/entity_lumberjack.c",
           "src/entities/npcs/entity_npcs_sprites.c", "src/entities/wolfi/wolfi_in_town_hall.c",
           "src/gameplay/quest.c", "src/gameplay/quest_runtime.c", "src/gameplay/quest_services.c", "src/gameplay/quest_text.c"]
reference = build_run("quest-reference", sources, ["-DEDW_VEXEL=0"])
vexel = build_run("quest-vexel", sources, ["-DEDW_VEXEL=1"])
assert reference == vexel, "Original C and Vexel gameplay traces differ"
print(step, end="")
print("Original C and Vexel: identical lumberjack and pear choice/inventory/dialogue traces (UBSan)")

services = ["tests/services_integration.c", "src/gameplay/quest.c", "src/gameplay/quest_runtime.c", "src/gameplay/quest_services.c", "src/gameplay/quest_text.c",
            *["src/entities/wolfi/wolfi_in_" + name + ".c" for name in
              ("fish_n_ships", "university", "food_n_stuff")]]
reference = build_run("services-reference", services, ["-DEDW_VEXEL=0"])
vexel = build_run("services-vexel", services, ["-DEDW_VEXEL=1"])
assert reference == vexel, "Original C and Vexel town-service traces differ"
print("Town services: identical menus, payments, health, equipment and explicit random draws (UBSan)")

passwords = ["tests/password_integration.c", "src/gameplay/password.c", "src/gameplay/password_rules.c",
             "src/gameplay/quest.c", "src/gameplay/quest_runtime.c", "src/gameplay/quest_text.c"]
reference = build_run("password-reference", passwords, ["-DEDW_VEXEL=0"])
vexel = build_run("password-vexel", passwords, ["-DEDW_VEXEL=1"])
assert reference == vexel, "C and Vexel password traces differ"
print("Passwords: fixed MSX vectors, bad input, atomic restores, equipment and UI agree (UBSan)")

world = ["tests/world_integration.c", "src/entities/wolfi/wolfi_triggers.c",
         "src/entities/wolfi/wolfi_door_warp_enter.c", "src/entities/wolfi/wolfi_door_warp_exit.c",
         "src/gameplay/world_rules.c", "src/gameplay/quest_text.c"]
reference = build_run("world-reference", world, ["-DEDW_VEXEL=0"])
vexel = build_run("world-vexel", world, ["-DEDW_VEXEL=1"])
assert reference == vexel, "C and Vexel world interaction traces differ"
print("World: routes, lamp gate, wells, boots warnings and dispatch agree (UBSan)")

drops = ["tests/drops_integration.c", "src/common.c", "src/entities/drop_item/entity_drop_item.c",
         "src/gameplay/drop_rules.c"]
reference = build_run("drops-reference", drops, ["-DEDW_VEXEL=0"])
vexel = build_run("drops-vexel", drops, ["-DEDW_VEXEL=1"])
assert reference == vexel, "C and Vexel pickup/drop traces differ"
print("Drops: probability boundaries, draw counts, one-time rewards and lifetime agree (UBSan)")

town = ["tests/town_integration.c", "src/entities/wolfi/wolfi_in_town_door.c",
        "src/entities/wolfi/wolfi_reads_info_boards.c", "src/entities/wolfi/wolfi_in_monster_house.c",
        "src/entities/wolfi/wolfi_takes_damage.c", "src/entities/wolfi/wolfi_door_warp_enter.c",
        "src/entities/wolfi/wolfi_door_warp_exit.c", "src/gameplay/town_rules.c", "src/gameplay/quest_text.c"]
reference = build_run("town-reference", town, ["-DEDW_VEXEL=0"])
vexel = build_run("town-vexel", town, ["-DEDW_VEXEL=1"])
assert reference == vexel, "Town interaction traces differ"
print("Town: house routes, random consumption, languages, boards and monster scene agree (UBSan)")

ghost = ["tests/ghost_integration.c", "src/entities/enemy_ghosti/entity_ghosti.c"]
reference = build_run("ghost-reference", ghost, ["-DEDW_VEXEL=0"])
vexel = build_run("ghost-vexel", ghost, ["-DEDW_VEXEL=1"])
assert reference == vexel, "Ghost behaviour traces differ"
print("Ghost: fixed-width oracle, random draws, movement, cadence and effects agree (UBSan)")
