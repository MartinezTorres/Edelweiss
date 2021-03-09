NAME := weiss

include sdcc_msx/Makefile.in

CCFLAGS_MSX   += -DKONAMI5
CCFLAGS_MSX   += --all-callee-saves --opt-code-speed --std-sdcc11
#CCFLAGS_MSX   += --reserve-regs-iy --callee-saves-bc

OPENMSX_BIN = /opt/openMSX/bin/openmsx
#OPENMSX_PARAM = -command "profile::section_scope_bp frame 0xFD9F; profile_osd p;" 

ADDR_DATA = 0xC000

#CCZ80 = sdcc_msx/bin/sdcc-3.9.0/bin/sdcc
CCZ80 = sdcc_msx/bin/sdcc-4.0.0/bin/sdcc
ASM = sdcc_msx/bin/sdcc-4.0.0/bin/sdasz80
MAX_ALLOCS = 4000


tmp/%.rel: %.c tmp/inc/resources.h $(HEADERS)
	@echo -n $(MSG)
	@mkdir -p $(@D)
	@$(CCZ80) -S -D MSX $(INCLUDES) $(CCFLAGS_MSX) $< -o tmp/$*.asm
	@#cp tmp/$*.asm tmp/$*.asm.mdl.asm
	@#echo -n `java -jar mdl.jar tmp/$*.asm -dialect sdcc -po speed -asm-dialect tmp/$*.asm.mdl.asm | grep summary | cut -f 1 -d. | cut -f 3 -d:`
	@echo -n `java -jar mdl.jar tmp/$*.asm -dialect sdcc -ro -po speed -ro -po speed -ro -asm-dialect tmp/$*.asm.mdl.ro.asm | grep summary | cut -f 1 -d. | cut -f 3 -d:`
	@#$(ASM) -ogslp $@ tmp/$*.asm.mdl.asm
	@#$(ASM) -ogslp $@ tmp/$*.asm.mdl.ro.asm
	@$(ASM) -ogslp $@ tmp/$*.asm
	@echo " "`grep "size" tmp/$*.sym | awk 'strtonum("0x"$$4) {print $$2": "strtonum("0x"$$4)" bytes"}'` 

