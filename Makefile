.DEFAULT_GOAL := all
.DELETE_ON_ERROR:

# The legacy checkout and historical out/ and tmp/ stay untouched.
GAMEPLAY ?= vexel
BUILD_ROOT ?= build
SMOKE ?= 0
BUILD := $(BUILD_ROOT)/$(GAMEPLAY)$(if $(filter 1,$(SMOKE)),-smoke,)
SDCC ?= sdcc
SDASZ80 ?= sdasz80
PYTHON ?= python3
MAX_ALLOCS ?= 2000
VEXEL_ROOT ?= ../..
VEXEL ?= $(VEXEL_ROOT)/build/vexel

ifeq ($(filter $(GAMEPLAY),reference vexel),)
$(error GAMEPLAY must be reference or vexel)
endif

rwildcard = $(foreach d,$(wildcard $(addsuffix *,$1)),$(call rwildcard,$d/,$2) $(filter $(subst *,%,$2),$d))
SOURCES := $(sort $(call rwildcard,src/ vendor/sdcc_msx/src/,*.c))
ifeq ($(SMOKE),1)
SOURCES += tests/quest_smoke.c tests/quest_smoke_input.c tests/world_smoke.c
CPPFLAGS += -DEDW_SMOKE=1
endif
ASSEMBLY := $(sort $(call rwildcard,src/ vendor/sdcc_msx/src/,*.s))
HEADERS := $(sort $(call rwildcard,src/ vendor/sdcc_msx/inc/,*.h *.t))
ifeq ($(SMOKE),1)
HEADERS += tests/quest_smoke_input.h tests/password_legacy.h
endif
INCLUDES := -Isrc -Ivendor/sdcc_msx/inc -I$(BUILD)/inc -Isrc/gameplay -Igenerated/quests
CPPFLAGS += -DEDW_VEXEL=$(if $(filter vexel,$(GAMEPLAY)),1,0)
CFLAGS ?= -O2 -g
HOST_FLAGS := -std=gnu99 $(CFLAGS) -Wall -Wextra -Wno-unused-parameter
SDCCFLAGS := -mz80 --sdcccall 0 --std-sdcc99 --disable-warning 110 --disable-warning 126 \
 --max-allocs-per-node $(MAX_ALLOCS) --allow-unsafe-read --nostdlib --no-xinit-opt
LINUX_OBJECTS := $(addprefix $(BUILD)/linux/,$(SOURCES:.c=.o))
MSX_OBJECTS := $(addprefix $(BUILD)/msx/,$(SOURCES:.c=.rel) $(ASSEMBLY:.s=.rel))
LINKER := $(BUILD_ROOT)/tools/module_linker

.PHONY: all linux msx run run-msx reference generate check-generated test smoke
all: linux msx
linux: $(BUILD)/linux/weiss
msx: $(BUILD)/msx/weiss.rom
reference:
	$(MAKE) GAMEPLAY=reference all
generate:
	$(PYTHON) tools/generate_quest.py --solver $(VEXEL)
check-generated:
	$(PYTHON) tools/generate_quest.py --check
test: check-generated $(LINKER)
	CC="$(CC)" $(PYTHON) tests/check_quest.py
	$(PYTHON) tests/check_linker.py $(LINKER)
smoke:
	$(MAKE) GAMEPLAY=reference SMOKE=1 all
	$(MAKE) GAMEPLAY=vexel SMOKE=1 all
	$(PYTHON) tests/check_smoke.py --build-root "$(BUILD_ROOT)"
run: linux
	$(BUILD)/linux/weiss
run-msx: msx
	openmsx -machine C-BIOS_MSX1 -carta $(BUILD)/msx/weiss.rom -romtype KonamiSCC

# All required assets are already checked in as C.
$(BUILD)/inc/resources.h:
	@mkdir -p $(@D)
	@printf '/* Assets are checked in under src/. */\n' > $@

$(BUILD)/linux/%.o: %.c $(HEADERS) $(BUILD)/inc/resources.h Makefile
	@mkdir -p $(@D)
	$(CC) $(HOST_FLAGS) $(CPPFLAGS) -DLINUX $(INCLUDES) $(shell pkg-config --cflags sdl2) -MMD -MP -c $< -o $@

$(BUILD)/linux/weiss: $(LINUX_OBJECTS)
	$(CC) $(CFLAGS) $^ $(shell pkg-config --libs sdl2) -o $@

$(BUILD)/msx/%.rel: %.c $(HEADERS) $(BUILD)/inc/resources.h Makefile
	@mkdir -p $(@D)
	$(SDCC) $(SDCCFLAGS) $(CPPFLAGS) -DMSX -DKONAMI5 $(INCLUDES) -S $< -o $(@:.rel=.asm)
	$(SDASZ80) -ogslp $@ $(@:.rel=.asm)

$(BUILD)/msx/%.rel: %.s Makefile
	@mkdir -p $(@D)
	$(SDASZ80) -ogslp $@ $<

$(LINKER): vendor/sdcc_msx/util/module_linker.cc
	@mkdir -p $(@D)
	$(CXX) -std=c++14 -O2 -g $< -o $@

$(BUILD)/msx/weiss.rom: $(MSX_OBJECTS) $(LINKER)
	$(LINKER) $(MSX_OBJECTS) $@

ifeq ($(GAMEPLAY),vexel)
$(LINUX_OBJECTS) $(MSX_OBJECTS): | check-generated
$(BUILD)/linux/src/gameplay/quest.o $(BUILD)/msx/src/gameplay/quest.rel: generated/quests/vx_quests.inc generated/quests/vexel.h
$(BUILD)/linux/src/gameplay/quest_services.o $(BUILD)/msx/src/gameplay/quest_services.rel: generated/quests/vx_services.inc generated/quests/vexel.h
$(BUILD)/linux/src/gameplay/password.o $(BUILD)/msx/src/gameplay/password.rel: generated/quests/vx_password_encode.inc generated/quests/vexel.h
$(BUILD)/linux/src/gameplay/password_rules.o $(BUILD)/msx/src/gameplay/password_rules.rel: generated/quests/vx_password.inc generated/quests/vexel.h
$(BUILD)/linux/src/gameplay/world_rules.o $(BUILD)/msx/src/gameplay/world_rules.rel: generated/quests/vx_world.inc generated/quests/vexel.h
$(BUILD)/linux/src/gameplay/drop_rules.o $(BUILD)/msx/src/gameplay/drop_rules.rel: generated/quests/vx_drops.inc generated/quests/vexel.h
endif

-include $(LINUX_OBJECTS:.o=.d)

