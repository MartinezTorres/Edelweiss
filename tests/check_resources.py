#!/usr/bin/env python3
"""Reject unsafe resource layouts independently of the game link."""
import copy
import importlib.util
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
spec = importlib.util.spec_from_file_location("assets", ROOT / "tools/sprite_assets.py")
assets = importlib.util.module_from_spec(spec)
spec.loader.exec_module(assets)
declaration = {"table_module":"renderer", "table_page":1, "table":"frames", "sprite_bytes":98, "none":0,
    "families":[{"name":n,"module":n,"page":3,"frames":[{"handle":i+1,"symbol":n}]}
                for i,n in enumerate(("one","two"))]}
def module(name,page,segment,symbol,size):
    return {"name":name,"page":page,"segment":segment,"areas":[{
        "name":"_CODE","address":0x4000+8192*page,"rom_offset":8192*segment,"size":size,
        "symbols":[{"name":"_"+symbol,"offset":0}]}]}
layout = {"modules":[module("renderer",1,1,"frames",6),module("one",3,2,"one",98),module("two",3,3,"two",98)]}
# Two distinct resources have the same CPU address but different bank numbers.
rom = bytearray(32768);rom[8192:8198]=bytes((2,0,0xA0,3,0,0xA0))
frames=assets.validate(declaration,layout,rom)["frames"]
assert [f["rom_offset"] for f in frames]==[16384,24576]
for case in ("page","module","bounds","physical","table_address","table_bank","table_window","table_bounds","handles"):
    bad=copy.deepcopy(layout);decl=copy.deepcopy(declaration);data=rom.copy()
    m=bad["modules"][1];a=m["areas"][0]
    if case=="page":m["page"]=2
    if case=="module":m["name"]="elsewhere"
    if case=="bounds":a["size"]-=1
    if case=="physical":a["rom_offset"]+=8192
    if case=="table_address":data[8193]=1
    if case=="table_bank":data[8192]=3
    if case=="table_window":bad["modules"][0]["page"]=3
    if case=="table_bounds":bad["modules"][0]["areas"][0]["size"]-=1
    if case=="handles":decl["families"][1]["frames"][0]["handle"]=1
    try:assets.validate(decl,bad,data)
    except ValueError:pass
    else:raise AssertionError("Accepted unsafe resource "+case)
print("Resources: same-address/different-bank assets resolve; bad windows, bounds, descriptors and handles are rejected")
