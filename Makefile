.DEFAULT_GOAL := all
.DELETE_ON_ERROR:

# The legacy checkout and historical out/ and tmp/ stay untouched.
GAMEPLAY ?= vexel
BUILD_ROOT ?= build
GENERATED ?= generated/quests
PLAYER_REGION ?= 0
PLAYER_REGION_BANKED ?= 1
VALUE_FRAME_BYTES ?= $(if $(filter 1,$(PLAYER_REGION)),128,96)
# Spend ROM on specialized pure paths; every linked module still must fit 8 KiB.
VALUE_CHOICE_BRANCHES ?= 8
SMOKE ?= 0
ENCOUNTER ?= 0
BUILD := $(BUILD_ROOT)/$(GAMEPLAY)$(if $(filter 1,$(SMOKE)),-smoke,)$(if $(filter 1,$(ENCOUNTER)),-encounter,)
SDCC ?= sdcc
SDASZ80 ?= sdasz80
PYTHON ?= python3
MAX_ALLOCS ?= 2000
SDCC_MEMORY_MB ?= 2048
SDCC_TIMEOUT ?= 180
SDCC_RUN = $(PYTHON) tools/sdcc_guard.py --memory-mb $(SDCC_MEMORY_MB) --timeout $(SDCC_TIMEOUT) --log $(BUILD)/sdcc-resources.jsonl $(SDCC)
VEXEL_ROOT ?= ../..
VEXEL ?= $(VEXEL_ROOT)/build/vexel

ifeq ($(filter $(GAMEPLAY),reference vexel),)
$(error GAMEPLAY must be reference or vexel)
endif

rwildcard = $(foreach d,$(wildcard $(addsuffix *,$1)),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))
SOURCES := $(sort $(call rwildcard,src/ vendor/sdcc_msx/src/,*.c))
ifeq ($(SMOKE),1)
SOURCES += tests/quest_smoke.c tests/quest_smoke_input.c tests/world_smoke.c tests/scene_smoke.c
CPPFLAGS += -DEDW_SMOKE=1
endif
ifeq ($(ENCOUNTER),1)
ifeq ($(SMOKE),1)
$(error SMOKE and ENCOUNTER are separate scenarios)
endif
SOURCES += tests/encounter.c tests/actor_policies.c
CPPFLAGS += -DEDW_ENCOUNTER=1
endif
ASSEMBLY := $(sort $(call rwildcard,src/ vendor/sdcc_msx/src/,*.s))
# These scenarios enter the game directly. An unreferenced legacy-linker
# module defaults to resident page A, so omit the unused title bank entirely.
ifneq ($(filter 1,$(SMOKE) $(ENCOUNTER)),)
SOURCES := $(filter-out src/gameplay/title_sequence.c,$(SOURCES))
endif
ifeq ($(ENCOUNTER),1)
$(BUILD)/linux/src/entities/weapons/entity_weapon_slash.o $(BUILD)/msx/src/entities/weapons/entity_weapon_slash.rel: tests/melee_encounter.h
$(foreach n,bow fire,$(BUILD)/linux/src/entities/weapons/entity_weapon_$(n).o $(BUILD)/msx/src/entities/weapons/entity_weapon_$(n).rel): tests/projectile_encounter.h
$(BUILD)/linux/src/entities/weapons/entity_weapon_bomb.o $(BUILD)/msx/src/entities/weapons/entity_weapon_bomb.rel: tests/bomb_encounter.h
$(BUILD)/linux/src/entities/drop_item/entity_drop_item.o $(BUILD)/msx/src/entities/drop_item/entity_drop_item.rel: tests/drops_encounter.h
$(BUILD)/linux/src/entities/fairy/entity_fairy.o $(BUILD)/msx/src/entities/fairy/entity_fairy.rel: tests/fairy_encounter.h
$(BUILD)/linux/src/entities/npcs/entity_lumberjack.o $(BUILD)/msx/src/entities/npcs/entity_lumberjack.rel: tests/follower_encounter.h
endif
INCLUDES := -Isrc -Ivendor/sdcc_msx/inc -I$(BUILD)/inc -Isrc/gameplay -I$(GENERATED)
CPPFLAGS += -DEDW_PLAYER_REGION=$(PLAYER_REGION) -DEDW_VEXEL=$(if $(filter vexel,$(GAMEPLAY)),1,0)
CPPFLAGS += -DEDW_PLAYER_REGION_BANKED=$(PLAYER_REGION_BANKED)
CFLAGS ?= -O2 -g
SDL_CFLAGS := $(shell pkg-config --cflags sdl2)
SDL_LIBS := $(shell pkg-config --libs sdl2)
HOST_FLAGS := -std=gnu99 $(CFLAGS) -Wall -Wextra -Wno-unused-parameter
SDCCFLAGS := -mz80 --sdcccall 0 --std-sdcc99 --disable-warning 110 --disable-warning 126 \
 --max-allocs-per-node $(MAX_ALLOCS) --allow-unsafe-read --nostdlib --no-xinit-opt
LINUX_OBJECTS := $(addprefix $(BUILD)/linux/,$(SOURCES:.c=.o))
MSX_OBJECTS := $(addprefix $(BUILD)/msx/,$(SOURCES:.c=.rel) $(ASSEMBLY:.s=.rel))
LINKER := $(BUILD_ROOT)/tools/module_linker
# Bootstrap older objects and recover a deleted dependency file. Assembly
# objects have no C preprocessor dependency file and do not enter this set.
DEPENDENCY_OBJECTS := $(LINUX_OBJECTS) $(addprefix $(BUILD)/msx/,$(SOURCES:.c=.rel))
UNTRACKED_OBJECTS := $(foreach o,$(DEPENDENCY_OBJECTS),$(if $(wildcard $(basename $(o)).d),,$(o)))
.PHONY: missing-dependencies
ifneq ($(strip $(UNTRACKED_OBJECTS)),)
$(UNTRACKED_OBJECTS): missing-dependencies
endif

.PHONY: all linux msx run run-msx reference generate check-generated test smoke ghost-benchmark encounter optimize-player optimize-storage
all: linux msx
linux: $(BUILD)/linux/weiss
msx: $(BUILD)/msx/weiss.rom
reference:
	$(MAKE) GAMEPLAY=reference all
generate:
	$(PYTHON) tools/generate_quest.py --solver $(VEXEL) --output "$(GENERATED)" --player-region $(PLAYER_REGION) --prefer value_frame_bytes=$(VALUE_FRAME_BYTES) --prefer value_choice_branches=$(VALUE_CHOICE_BRANCHES)
optimize-player:
	$(PYTHON) tools/optimize_player.py --solver $(VEXEL) --frame-bytes $(VALUE_FRAME_BYTES) --choice-branches $(VALUE_CHOICE_BRANCHES)
optimize-storage:
	$(PYTHON) tools/optimize_storage.py --solver $(VEXEL) --frame-bytes $(VALUE_FRAME_BYTES) --choice-branches $(VALUE_CHOICE_BRANCHES)
check-generated:
	$(PYTHON) tools/generate_quest.py --check --output "$(GENERATED)"
test: check-generated $(LINKER)
	CC="$(CC)" EDW_TEST_BUILD="$(BUILD_ROOT)/tests" EDW_GENERATED="$(GENERATED)" EDW_PLAYER_REGION="$(PLAYER_REGION)" EDW_PLAYER_REGION_BANKED="$(PLAYER_REGION_BANKED)" $(PYTHON) tests/check_quest.py
	$(PYTHON) tests/check_linker.py $(LINKER)
	$(PYTHON) -B tests/check_resources.py
	$(PYTHON) -B tests/check_optimization.py
smoke:
	$(MAKE) GAMEPLAY=reference SMOKE=1 all
	$(MAKE) GAMEPLAY=vexel SMOKE=1 all
	$(PYTHON) tests/check_smoke.py --build-root "$(BUILD_ROOT)"
ghost-benchmark:
	$(MAKE) GAMEPLAY=reference SMOKE=1 msx
	$(MAKE) GAMEPLAY=vexel SMOKE=1 msx
	$(PYTHON) tests/check_smoke.py --build-root "$(BUILD_ROOT)" --msx-only --speed 1000 --report-dir ghost-benchmark
encounter:
	$(MAKE) GAMEPLAY=reference ENCOUNTER=1 all
	$(MAKE) GAMEPLAY=vexel ENCOUNTER=1 all
	$(PYTHON) tests/check_encounter.py --build-root "$(BUILD_ROOT)"
run: linux
	$(BUILD)/linux/weiss
run-msx: msx
	openmsx -machine C-BIOS_MSX1 -carta $(BUILD)/msx/weiss.rom -romtype KonamiSCC

# All required assets are already checked in as C.
$(BUILD)/inc/resources.h:
	@mkdir -p $(@D)
	@printf '/* Assets are checked in under src/. */\n' > $@

# Compare effective build settings before deciding whether objects are current.
# Changing a command-line preference in the same BUILD_ROOT must not silently
# reuse objects compiled with another ABI, generated directory or allocator.
.PHONY: build-settings
$(BUILD)/linux/settings.txt: build-settings
	@mkdir -p $(@D)
	@{ $(CC) --version; printf '%s\n' '$(CC)' '$(HOST_FLAGS)' '$(CPPFLAGS)' '$(INCLUDES)' '$(SDL_CFLAGS)' '$(SDL_LIBS)' '$(LDFLAGS)' '$(LINUX_OBJECTS)'; } > $@.next
	@cmp -s $@.next $@ || cp $@.next $@

$(BUILD)/msx/settings.txt: build-settings
	@mkdir -p $(@D)
	@{ $(SDCC) --version; printf '%s\n' '$(SDCC)' '$(SDCCFLAGS)' '$(CPPFLAGS)' '$(INCLUDES)' '$(SDASZ80)' '$(MSX_OBJECTS)'; } > $@.next
	@cmp -s $@.next $@ || cp $@.next $@

$(BUILD_ROOT)/tools/settings.txt: build-settings
	@mkdir -p $(@D)
	@{ $(CXX) --version; printf '%s\n' '$(CXX)' '-std=c++14 -O2 -g'; } > $@.next
	@cmp -s $@.next $@ || cp $@.next $@

$(LINUX_OBJECTS): $(BUILD)/linux/settings.txt
$(MSX_OBJECTS): $(BUILD)/msx/settings.txt

$(BUILD)/linux/%.o: %.c $(BUILD)/inc/resources.h Makefile
	@mkdir -p $(@D)
	$(CC) $(HOST_FLAGS) $(CPPFLAGS) -DLINUX $(INCLUDES) $(SDL_CFLAGS) -MMD -MP -c $< -o $@

$(BUILD)/linux/weiss: $(LINUX_OBJECTS) $(BUILD)/linux/settings.txt
	$(CC) $(CFLAGS) $(LDFLAGS) $(LINUX_OBJECTS) $(SDL_LIBS) -o $@

$(BUILD)/msx/%.rel: %.c $(BUILD)/inc/resources.h Makefile
	@mkdir -p $(@D)
# Dependency-only preprocessing retains -MP's empty header rules in SDCC 4.2;
# the side-effect -MMD mode omits them. Both invocations use the same defines.
	$(SDCC_RUN) $(SDCCFLAGS) $(CPPFLAGS) -DMSX -DKONAMI5 $(INCLUDES) -E -Wp-MM,-MP,-MF,$(@:.rel=.d),-MT,$@ $<
	$(SDCC_RUN) $(SDCCFLAGS) $(CPPFLAGS) -DMSX -DKONAMI5 $(INCLUDES) -S $< -o $(@:.rel=.asm)
	$(SDASZ80) -ogslp $@ $(@:.rel=.asm)

$(BUILD)/msx/%.rel: %.s Makefile
	@mkdir -p $(@D)
	$(SDASZ80) -ogslp $@ $<

$(LINKER): vendor/sdcc_msx/util/module_linker.cc $(BUILD_ROOT)/tools/settings.txt
	@mkdir -p $(@D)
	$(CXX) -std=c++14 -O2 -g $< -o $@

$(BUILD)/msx/weiss.rom: $(MSX_OBJECTS) $(LINKER) $(BUILD)/msx/settings.txt
	$(LINKER) $(MSX_OBJECTS) $@
ifeq ($(GAMEPLAY),vexel)
	$(PYTHON) tools/sprite_assets.py $@ --generated "$(GENERATED)"
endif

ifeq ($(GAMEPLAY),vexel)
$(LINUX_OBJECTS) $(MSX_OBJECTS): | check-generated
$(foreach n,slash bow fire bomb,$(BUILD)/linux/src/entities/weapons/entity_weapon_$(n).o $(BUILD)/msx/src/entities/weapons/entity_weapon_$(n).rel): $(GENERATED)/vx_sprite_assets.h
$(BUILD)/msx/weiss.rom: tools/sprite_assets.py $(GENERATED)/vx_sprite_assets.json
$(BUILD)/linux/src/sprites.o $(BUILD)/msx/src/sprites.rel: $(GENERATED)/vx_sprite_assets.inc $(GENERATED)/vx_sprite_assets.h
$(BUILD)/linux/src/entities/enemy_ghosti/entity_ghosti.o $(BUILD)/msx/src/entities/enemy_ghosti/entity_ghosti.rel $(BUILD)/linux/src/entities/enemy_skeleti/entity_skeleti.o $(BUILD)/msx/src/entities/enemy_skeleti/entity_skeleti.rel: $(GENERATED)/vx_sprite_assets.h
$(BUILD)/linux/src/gameplay/quest.o $(BUILD)/msx/src/gameplay/quest.rel: $(GENERATED)/vx_quests.inc $(GENERATED)/vexel.h
$(BUILD)/linux/src/gameplay/quest_services.o $(BUILD)/msx/src/gameplay/quest_services.rel: $(GENERATED)/vx_services.inc $(GENERATED)/vexel.h
$(BUILD)/linux/src/gameplay/password.o $(BUILD)/msx/src/gameplay/password.rel: $(GENERATED)/vx_password_encode.inc $(GENERATED)/vexel.h
$(BUILD)/linux/src/gameplay/password_rules.o $(BUILD)/msx/src/gameplay/password_rules.rel: $(GENERATED)/vx_password.inc $(GENERATED)/vexel.h
$(BUILD)/linux/src/gameplay/world_rules.o $(BUILD)/msx/src/gameplay/world_rules.rel: $(GENERATED)/vx_world.inc $(GENERATED)/vexel.h
$(BUILD)/linux/src/gameplay/town_rules.o $(BUILD)/msx/src/gameplay/town_rules.rel: $(GENERATED)/vx_town.inc $(GENERATED)/vexel.h
$(BUILD)/linux/src/entities/enemy_ghosti/entity_ghosti.o $(BUILD)/msx/src/entities/enemy_ghosti/entity_ghosti.rel: $(GENERATED)/vx_ghost.inc $(GENERATED)/vexel.h $(wildcard $(GENERATED)/vx_value_*.h)
$(BUILD)/linux/src/entities/enemy_skeleti/entity_skeleti.o $(BUILD)/msx/src/entities/enemy_skeleti/entity_skeleti.rel: $(GENERATED)/vx_value_skeleti_tick.h $(GENERATED)/vx_value_skeleti_draws.h $(GENERATED)/vx_value_skeleti_update_cases.h $(GENERATED)/vx_value_runtime.h
$(BUILD)/linux/src/collisions.o $(BUILD)/msx/src/collisions.rel: $(GENERATED)/vx_value_combat_tick_cases.h $(GENERATED)/vx_value_runtime.h $(GENERATED)/vexel.h
endif

-include $(LINUX_OBJECTS:.o=.d)
# Ask SDCC's preprocessor for the actual transitive includes. In particular,
# changing one generated support component must invalidate its MSX consumers.
-include $(MSX_OBJECTS:.rel=.d)


$(foreach n,bow fire,$(BUILD)/linux/src/entities/weapons/entity_weapon_$(n).o $(BUILD)/msx/src/entities/weapons/entity_weapon_$(n).rel): src/entities/weapons/projectile_vexel.inc

ACTOR_ADAPTERS := src/entities/spark/entity_spark src/entities/explosion/entity_explosion src/entities/enemy_ball/enemy_ball src/entities/wolfi/entity_wolfi
$(addprefix $(BUILD)/linux/,$(addsuffix .o,$(ACTOR_ADAPTERS))) $(addprefix $(BUILD)/msx/,$(addsuffix .rel,$(ACTOR_ADAPTERS))): $(GENERATED)/vx_sprite_assets.h
$(BUILD)/linux/src/entities/wolfi/entity_wolfi.o $(BUILD)/msx/src/entities/wolfi/entity_wolfi.rel: src/entities/wolfi/player_controls.inc src/entities/wolfi/player_vexel.inc
$(foreach s,src/gameplay/player_motion src/entities/wolfi/entity_wolfi,$(BUILD)/linux/$(s).o $(BUILD)/msx/$(s).rel): src/gameplay/player_motion.inc

ifeq ($(ENCOUNTER),1)
$(foreach n,spark explosion,$(BUILD)/linux/src/entities/$(n)/entity_$(n).o $(BUILD)/msx/src/entities/$(n)/entity_$(n).rel): tests/effects_encounter.h
$(BUILD)/linux/src/entities/enemy_ball/enemy_ball.o $(BUILD)/msx/src/entities/enemy_ball/enemy_ball.rel: tests/ball_encounter.h
$(BUILD)/linux/src/entities/wolfi/entity_wolfi.o $(BUILD)/msx/src/entities/wolfi/entity_wolfi.rel: tests/player_encounter.h
endif

$(BUILD)/linux/src/entities/wolfi/entity_wolfi.o $(BUILD)/msx/src/entities/wolfi/entity_wolfi.rel: src/entities/wolfi/intro_reference.inc src/entities/wolfi/intro_vexel.inc src/gameplay/scene_wipe.inc
$(BUILD)/linux/src/gameplay/world_orchestration.o $(BUILD)/msx/src/gameplay/world_orchestration.rel: src/gameplay/scene_wipe.inc
$(BUILD)/linux/src/gameplay/world_orchestration.o $(BUILD)/msx/src/gameplay/world_orchestration.rel: src/gameplay/world_flow.inc src/gameplay/native_world.inc
$(BUILD)/linux/src/gameplay/title_sequence.o $(BUILD)/msx/src/gameplay/title_sequence.rel: src/gameplay/title_sequence.inc src/gameplay/native_world.inc
$(foreach n,enter exit,$(BUILD)/linux/src/entities/wolfi/wolfi_door_warp_$(n).o $(BUILD)/msx/src/entities/wolfi/wolfi_door_warp_$(n).rel): src/gameplay/scene_door.inc
