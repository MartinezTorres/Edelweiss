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
         "-Isrc/gameplay", "-Igenerated/lumberjack", "-ffunction-sections", "-fdata-sections",
         "-fsanitize=undefined", "-fno-sanitize-recover=all", "-Wl,--gc-sections"]


def build_run(name, sources, extra=()):
    binary = BUILD / name
    subprocess.run([*CC, *FLAGS, *extra, *sources, "-o", str(binary)], cwd=ROOT, check=True)
    result = subprocess.run([str(binary)], cwd=ROOT, check=True, capture_output=True, text=True)
    (BUILD / f"{name}.txt").write_text(result.stdout)
    return result.stdout


step = build_run("quest-step", ["tests/quest_step.c", "src/gameplay/quest_text.c",
                               "generated/lumberjack/vx_bridges.c"])
sources = ["tests/quest_integration.c", "src/common.c", "src/entities/npcs/entity_lumberjack.c",
           "src/entities/npcs/entity_npcs_sprites.c", "src/entities/wolfi/wolfi_in_town_hall.c",
           "src/gameplay/quest.c", "src/gameplay/quest_text.c"]
reference = build_run("quest-reference", sources, ["-DEDW_VEXEL=0"])
vexel = build_run("quest-vexel", sources, ["-DEDW_VEXEL=1"])
assert reference == vexel, "Original C and Vexel gameplay traces differ"
print(step, end="")
print("Original C and Vexel: identical dialogue/follow/reward/reset/cancellation traces (UBSan)")
