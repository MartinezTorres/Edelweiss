#!/usr/bin/env python3
"""Resolve sprite families into one byte handle space and verify the final ROM.

The descriptor table lives with the renderer in page B; each entry contains
the relocated page-D bank and address of an asset. No gameplay pointer escapes.
"""
import argparse
import json
from pathlib import Path
import re

ROOT = Path(__file__).resolve().parents[1]
OUTPUT = ROOT / "generated/quests"
FILES = ("vx_sprite_assets.h", "vx_sprite_assets.inc", "vx_sprite_assets.json")
TABLE = "edw_sprite_bindings"
SPRITE_BYTES = 98


def generate(plan, output=OUTPUT):
    """Consume build facts from the same solved program as the gameplay."""
    def decode(term):
        name, args = term.get("constructor"), term.get("arguments", [])
        if name == "Bytes":
            value = bytes(int(a["number"]) for a in args).decode("ascii")
            if not re.fullmatch(r"[A-Za-z_][A-Za-z_0-9]*", value):
                raise ValueError("Invalid resource identifier: " + value)
            return value
        if name == "RecordValue" and args[0].get("constructor") == "Tuple":
            return [decode(a) for a in args[1]["arguments"]]
        raise ValueError("Sprite catalog must contain tuples of identifier strings")
    facts = {q["query"]: q for q in plan["queries"]}
    catalog = decode(facts["value:sprite_catalog"]["term"])
    if not catalog or any(len(row) != 3 for row in catalog):
        raise ValueError("Sprite catalog needs (family,module,frames) rows")
    names = [row[0] for row in catalog]
    if len(names) != len(set(names)):
        raise ValueError("Duplicate sprite family")
    families, count = [], 0
    header = ['/* Generated from gameplay/sprite_assets.vx. Zero means no request. */\n'
              '#ifndef EDW_SPRITE_ASSETS_H\n#define EDW_SPRITE_ASSETS_H\ntypedef uint8_t EdwSprite;\n']
    code = ['/* Private renderer table. Its page B must remain mapped while selecting an entry. */\n'
            'typedef struct { uint8_t segment; const TSpriteInterlaced *info; } EdwSpriteBinding;\n'
            '#ifdef MSX\ntypedef char edw_binding_size_check[sizeof(EdwSpriteBinding)==3?1:-1];\n#endif\n'
            f'typedef char edw_sprite_size_check[sizeof(TSpriteInterlaced)=={SPRITE_BYTES}?1:-1];\n']
    rows = []
    for name, module, frames in catalog:
        if not isinstance(frames, list) or not frames or len(frames) != len(set(frames)):
            raise ValueError("Empty or duplicate resource names")
        first = count + 1
        count += len(frames)
        if count > 254:
            raise ValueError("Sprite families must fit nonzero byte handles (255 is invalid)")
        prefix = "EDW_" + name.upper() + "_SPRITE"
        header.append(f'#define {prefix}_COUNT {len(frames)}\n#define {prefix}_FIRST {first}\n'
                      f'static inline EdwSprite edw_{name}_sprite(uint8_t frame) {{\n'
                      f'    return frame < {prefix}_COUNT ? frame + {prefix}_FIRST : 0;\n}}\n')
        code.append(f'USING_MODULE({module}, PAGE_D);\n')
        for symbol in frames:
            code.append(f'extern const TSpriteInterlaced {symbol};\n')
            rows.append(f'    {{MODULE_SEGMENT({module}, PAGE_D), &{symbol}}},\n')
        families.append({"name": name, "module": module, "page": 3,
                         "frames": [{"handle": first+i, "symbol": symbol} for i, symbol in enumerate(frames)]})
    header.append(f'#define EDW_SPRITE_COUNT {count}\n#endif\n')
    code.append(f'const EdwSpriteBinding {TABLE}[]={{\n' + "".join(rows) + '};\n')
    declaration = {"table_module": "sprites", "table_page": 1, "table": TABLE,
                   "sprite_bytes": SPRITE_BYTES, "none": 0, "families": families}
    output.mkdir(parents=True, exist_ok=True)
    for name, content in zip(FILES, ("".join(header), "".join(code), json.dumps(declaration, indent=2)+"\n")):
        (output / name).write_text(content)


def validate(declaration, layout, rom):
    def module(name, page):
        matches = [m for m in layout["modules"] if m["name"] == name]
        if len(matches) != 1 or matches[0]["page"] != page:
            raise ValueError("Resource module/window mismatch: " + name)
        return matches[0]

    def location(owner, name, size):
        matches = [(a, s["offset"]) for a in owner["areas"] if a["name"] != "_DATA"
                   for s in a["symbols"] if s["name"] == "_" + name]
        if len(matches) != 1:
            raise ValueError("Resource absent or ambiguous in declared module: " + name)
        area, offset = matches[0]
        address, physical = area["address"] + offset, area["rom_offset"] + offset
        base = 0x4000 + 8192 * owner["page"]
        if (offset < 0 or offset + size > area["size"] or address < base or address + size > base + 8192
                or physical != owner["segment"] * 8192 + address - base
                or physical < 0 or physical + size > len(rom)):
            raise ValueError("Resource crosses its mapped section: " + name)
        return {"address": address, "rom_offset": physical}

    count = sum(len(f["frames"]) for f in declaration["families"])
    if not 1 <= count <= 254 or declaration["none"] != 0 or declaration["table_page"] != 1:
        raise ValueError("Invalid sprite handle/table contract")
    owner = module(declaration["table_module"], 1)
    table = location(owner, declaration["table"], 3 * count)
    frames = []
    for family in declaration["families"]:
        if family["page"] != 3:
            raise ValueError("Sprite assets require page D")
        asset = module(family["module"], 3)
        for frame in family["frames"]:
            i = len(frames)
            if frame["handle"] != i + 1:
                raise ValueError("Resource handles must be consecutive and nonzero")
            entry = location(asset, frame["symbol"], declaration["sprite_bytes"])
            start = table["rom_offset"] + 3 * i
            if rom[start] != asset["segment"] or int.from_bytes(rom[start+1:start+3], "little") != entry["address"]:
                raise ValueError("Relocated resource descriptor disagrees with its declaration")
            frames.append({**frame, **entry, "family": family["name"], "module": asset["name"], "segment": asset["segment"]})
    return {"table": {**table, "module": owner["name"], "page": 1, "segment": owner["segment"]},
            "sprite_bytes": declaration["sprite_bytes"], "frames": frames}


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("rom", type=Path)
    parser.add_argument("--generated", type=Path, default=OUTPUT)
    args = parser.parse_args()
    try:
        report = validate(json.loads((args.generated / FILES[2]).read_text()),
                          json.loads(Path(str(args.rom) + ".layout.json").read_text()), args.rom.read_bytes())
    except ValueError as error:
        parser.exit(1, str(error) + "\n")
    Path(str(args.rom) + ".resources.json").write_text(json.dumps(report, indent=2) + "\n")
    print("Sprite resources: linked modules, windows, bounds and descriptor relocations verified")
