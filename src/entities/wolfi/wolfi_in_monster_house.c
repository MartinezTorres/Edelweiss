#include <common.h>
#ifdef EDW_SMOKE
#include "../../../tests/quest_smoke_input.h"
#endif
#if EDW_VEXEL
#include <gameplay/quest.h>
#include "vexel.h"
USING_MODULE(town_rules, PAGE_B);
USING_MODULE(quest_text, PAGE_D);
#endif

void wolfi_in_monster_house() {

	uint8_t pj = ((state.entities[0].pos.j+0x80)>>8) - map.pos.j;
	int8_t pi = ((state.entities[0].pos.i+0x80)>>8) - map.pos.i - 8;
	if (pi<0) pi = 0;
	if (pi>4) pi = 4;

#if EDW_VEXEL
    uint8_t phase=0, text, life, frames, copied, k;
#endif
	IN_MODULE( popup, PAGE_B,
		popupInitCanvas(pj+2,pi);
		popupTextProperties.y = 2;
		popupTextProperties.x = 10;
#if EDW_VEXEL
        while(phase<4) {
            IN_MODULE(town_rules, PAGE_B,
                vx_town_monster(phase,state.entities[0].life);
                phase=(uint8_t)vx_town_monster_read(0);
                text=(uint8_t)vx_town_monster_read(1);
                life=(uint8_t)vx_town_monster_read(2);
                frames=(uint8_t)vx_town_monster_read(3);
            );
            if(text) {
                IN_MODULE(quest_text, PAGE_D,
                    copied=quest_text_copy(text,quest_dialogue,sizeof(quest_dialogue));
                );
                if(!copied)vx_trap(37);
                popupWriteText(quest_dialogue);
                state.entities[0].life=life;
            }
            for(k=0;k<frames;++k)wait_frame();
#ifdef EDW_SMOKE
            if(text)quest_smoke_checkpoint(69+phase);
#endif
        }
#else
		popupWriteText("NOM!\n");
		TRAMPOLINE_PAGE_C( wolfi_takes_damage );
		for (uint8_t k=0; k<30; k++) wait_frame();
#ifdef EDW_SMOKE
		quest_smoke_checkpoint(70);
#endif
		popupWriteText("    NOM!\n");
		TRAMPOLINE_PAGE_C( wolfi_takes_damage );
		for (uint8_t k=0; k<30; k++) wait_frame();
#ifdef EDW_SMOKE
		quest_smoke_checkpoint(71);
#endif
		popupWriteText("        NOM!");
		TRAMPOLINE_PAGE_C( wolfi_takes_damage );
		for (uint8_t k=0; k<30; k++) wait_frame();
#ifdef EDW_SMOKE
		quest_smoke_checkpoint(72);
#endif
#endif
	);
#if !EDW_VEXEL
    for (uint8_t k=0; k<60; k++) wait_frame();
#endif
}
