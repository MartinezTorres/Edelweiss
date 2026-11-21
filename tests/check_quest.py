#!/usr/bin/env python3
"""Compare the original gameplay callbacks with the Vexel-backed callbacks."""
import os
from pathlib import Path
import shlex
import subprocess

ROOT = Path(__file__).resolve().parents[1]
BUILD = Path(os.environ.get("EDW_TEST_BUILD", ROOT / "build/tests"))
BUILD.mkdir(parents=True, exist_ok=True)
CC = shlex.split(os.environ.get("CC", "cc"))
GENERATED = os.environ.get("EDW_GENERATED", "generated/quests")
FLAGS = ["-std=gnu99", "-O1", "-g", "-DLINUX", "-Isrc", "-Ivendor/sdcc_msx/inc",
         "-Isrc/gameplay", "-I" + GENERATED, "-ffunction-sections", "-fdata-sections",
         "-fsanitize=undefined", "-fno-sanitize-recover=all", "-Wl,--gc-sections"]
if "EDW_PLAYER_REGION" in os.environ:
    FLAGS.append("-DEDW_PLAYER_REGION=" + os.environ["EDW_PLAYER_REGION"])
if "EDW_PLAYER_REGION_BANKED" in os.environ:
    FLAGS.append("-DEDW_PLAYER_REGION_BANKED=" + os.environ["EDW_PLAYER_REGION_BANKED"])


def build_run(name, sources, extra=()):
    binary = BUILD / name
    if "-DEDW_VEXEL=1" in extra:
        sources = [*sources, "src/gameplay/value_frames.c"]
    subprocess.run([*CC, *FLAGS, *extra, *sources, "-o", str(binary)], cwd=ROOT, check=True, timeout=180)
    result = subprocess.run([str(binary)], cwd=ROOT, check=True, capture_output=True, text=True, timeout=60)
    (BUILD / f"{name}.txt").write_text(result.stdout)
    return result.stdout


step = build_run("quest-step", ["tests/quest_step.c", "src/gameplay/quest_text.c",
                               GENERATED + "/vx_bridges.c"])
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

orchestration = ["tests/orchestration_integration.c", "src/common.c", "src/gameplay/world_orchestration.c",
                 "src/entities/wolfi/wolfi_door_warp_migrate.c"]
reference = build_run("orchestration-reference", orchestration, ["-DEDW_VEXEL=0"])
vexel = build_run("orchestration-vexel", orchestration, ["-DEDW_VEXEL=1"])
assert reference == vexel, "World orchestration or callback ordering differs"
print("Orchestration: clock wrap, spawn windows, callback order, scroll, trail and reveal agree (UBSan)")

scenes = ["tests/scenes_integration.c", "src/entities/wolfi/entity_wolfi_sprite.c"]
reference = build_run("scenes-reference", scenes, ["-DEDW_VEXEL=0"])
vexel = build_run("scenes-vexel", scenes, ["-DEDW_VEXEL=1"])
assert reference == vexel, "Scripted scene state or ordered effects differ"
print("Scenes: intro, montage, batched ticks, clipping, death and shared workspace reuse agree (UBSan)")

title = ["tests/title_integration.c", "src/common.c", "src/gameplay/title_sequence.c", "src/gameplay/quest_runtime.c"]
reference = build_run("title-reference", title, ["-DEDW_VEXEL=0"])
vexel = build_run("title-vexel", title, ["-DEDW_VEXEL=1"])
assert reference == vexel, "Title sequence or cancellation differs"
print("Title: complete presentation, random draws, actor cadence and phase cancellation agree (UBSan)")
print(build_run("remaining-policies", ["tests/remaining_policies.c"], ["-DEDW_VEXEL=1"]), end="")

drops = ["tests/drops_integration.c", "src/common.c", "src/entities/drop_item/entity_drop_item.c"]
reference = build_run("drops-reference", drops, ["-DEDW_VEXEL=0"])
vexel = build_run("drops-vexel", drops, ["-DEDW_VEXEL=1"])
assert reference == vexel, "C and Vexel pickup/drop traces differ"
print("Drops: probability boundaries, draw counts, one-time rewards and lifetime agree (UBSan)")

passive = ["tests/passive_integration.c", "src/common.c",
           "src/entities/fairy/entity_fairy.c", "src/entities/fairy/entity_fairy_sprite.c",
           "src/entities/npcs/entity_lumberjack.c", "src/entities/npcs/entity_npcs_sprites.c"]
reference = build_run("passive-reference", passive, ["-DEDW_VEXEL=0"])
vexel = build_run("passive-vexel", passive, ["-DEDW_VEXEL=1"])
assert reference == vexel, "Fairy/follower behavior traces differ"
print(vexel, end="")

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
print(build_run("sprite-resources", ["tests/sprite_resources.c", "src/sprites.c",
    "src/entities/enemy_ghosti/entity_ghosti_sprite.c", "src/entities/enemy_skeleti/entity_skeleti_sprite.c",
    "src/entities/weapons/entity_weapon_slash_small_sprite.c", "src/entities/weapons/entity_weapon_slash_large_sprite.c",
    *["src/entities/weapons/entity_weapon_"+n+"_sprite.c" for n in ("arrow","fire","bomb")],
    *["src/entities/"+n+"/entity_"+n+"_sprite.c" for n in ("spark","explosion","wolfi","drop_item","fairy")],
    "src/entities/npcs/entity_npcs_sprites.c", "src/entities/enemy_ball/enemy_ball_sprite.c"], ["-DEDW_VEXEL=1"]), end="")

skeleti = ["tests/skeleti_integration.c", "src/entities/enemy_skeleti/entity_skeleti.c"]
reference = build_run("skeleti-reference", skeleti, ["-DEDW_VEXEL=0"])
vexel = build_run("skeleti-vexel", skeleti, ["-DEDW_VEXEL=1"])
assert reference == vexel, "Skeleti behaviour traces differ"
print("Skeleti: routine/delay, conditional draws, wrap boundaries, obstacles and effect order agree (UBSan)")

combat = ["tests/combat_integration.c", "src/gameplay/combat.c", "src/collisions.c", "src/collisions_d.c"]
reference = build_run("combat-reference", combat, ["-DEDW_VEXEL=0"])
vexel = build_run("combat-vexel", combat, ["-DEDW_VEXEL=1"])
assert reference == vexel, "Revised C and Vexel combat traces differ"
print(reference, end="")

melee = ["tests/melee_integration.c", "src/entities/weapons/entity_weapon_slash.c",
         "src/entities/weapons/entity_weapon_slash_small_sprite.c", "src/entities/weapons/entity_weapon_slash_large_sprite.c"]
reference = build_run("melee-reference", melee, ["-DEDW_VEXEL=0"])
vexel = build_run("melee-vexel", melee, ["-DEDW_VEXEL=1"])
assert reference == vexel, "Melee state, frame or effect traces differ"
print("Melee: damage, palettes, hitboxes, axe effects, callback lifetimes, animation and expiration agree (UBSan)")

projectiles = ["tests/projectiles_integration.c", *["src/entities/weapons/entity_weapon_"+n+".c" for n in ("bow","fire","bomb")],
               *["src/entities/weapons/entity_weapon_"+n+"_sprite.c" for n in ("arrow","fire","bomb")]]
reference = build_run("projectiles-reference", projectiles, ["-DEDW_VEXEL=0"])
vexel = build_run("projectiles-vexel", projectiles, ["-DEDW_VEXEL=1"])
assert reference == vexel, "Projectile/bomb state, frame or ordered effect traces differ"
print("Projectiles: launch, wrapping movement, frames, bomb boundaries and ordered map effects agree (UBSan)")

for name, sources in {
    "effects": ["tests/effects_integration.c", *["src/entities/"+n+"/entity_"+n+x+".c" for n in ("spark","explosion") for x in ("","_sprite")]],
    "ball": ["tests/ball_integration.c", "src/entities/enemy_ball/enemy_ball.c", "src/entities/enemy_ball/enemy_ball_sprite.c"],
    "player": ["tests/player_integration.c", "src/entities/wolfi/entity_wolfi_sprite.c", "src/gameplay/player_motion.c"],
}.items():
    reference = build_run(name+"-reference", sources, ["-DEDW_VEXEL=0"])
    vexel = build_run(name+"-vexel", sources, ["-DEDW_VEXEL=1"])
    assert reference == vexel, name+" state or ordered effect traces differ"
    print(name+": C/Vexel state, effect order and boundaries agree (UBSan)")
