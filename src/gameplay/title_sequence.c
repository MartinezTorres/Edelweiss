#include <common.h>
#include "world_orchestration.h"
#include "title_sequence.h"
#if EDW_VEXEL
#include "title_sequence.inc"
#else
static bool title_wait_frame() {

	wait_frame();

	state.isr_count_delta = 1;

	// UPDATE SPAWNED ENTITIES
	for (uint8_t i=0; i<12; i++) {

		int8_t idx = state.spawns[i];

		if (idx<0) continue;
		Entity *entity = &state.entities[idx];

        if(!world_call_update(entity))despawn_entity(idx);

	}

	// UPDATE SPRITES
	{
		uint8_t old_map_j = map.pos.j;
		map.pos.j = 0;

		CALL_PAGE(sprites, PAGE_B, updateSpriteISR());
		map.pos.j = old_map_j;
	}

	if (state.isr_count == 16*12) state.isr_count=0;
	if ((state.isr_count&15) == 0) {
		if (state.entities[state.isr_count>>4].spawn_auto) {
			spawn_entity(state.isr_count>>4);
		}
	}


	update_keyboard_and_joystick();
	if (keyboard[8] != 255) return true;
	return false;
}

void title_routine(void) {


    msxhal_install_isr(nullptr);
    wait_frame();

    mapper_load_module(titlemap, PAGE_B);
    titlemap_init();
    CALL_PAGE(sprites, PAGE_B, sprites_init());

    TMS99X8.sprites16 = true;
    TMS99X8_syncFlags();


    msxhal_install_isr(title_isr);

    memset(&state,0,sizeof(state));
	for (uint8_t i=0; i<12; i++)
		state.spawns[i] = -1;
	state.num_spawns=0;

	for (uint8_t i=0; i<96; i++)
		state.entities[i].spawn_idx = -1;

	for (uint8_t i=0; i<12; i++) {
		trampoline_page_c_uint8_t(MODULE_SEGMENT(entity_spark, PAGE_C), init_spark, i);
		state.entities[i].spark_type = 1+(i%2);
		state.entities[i].spawn_auto = false;
		state.entities[i].spawn_priority = 0;
		do {
			state.entities[i].pos.j = rand16()&255;
		} while (state.entities[i].pos.j>224);
		state.entities[i].pos.j += 16;
		state.entities[i].pos.j <<= 5;

		do {
			state.entities[i].pos.i = rand16()&255;
		} while (state.entities[i].pos.i>80);
		state.entities[i].pos.i += 40;
		state.entities[i].pos.i <<= 5;

		//spawn_entity(i);
	}



	//init_overworld_entities();

	map.pos.j = 0;
	map.pos.i = 24;

	TMS99X8.blankScreen = false;
	TMS99X8_syncAllRegisters();

	if (title_wait_frame()) return;
    {

        for (uint8_t i=0; i<12; i++) {

			titlemap_draw_row(i);
			titlemap_draw_row(23-i);
			if (title_wait_frame()) return;
			titlemap_draw_col(31-i);
			titlemap_draw_col(i);
			if (title_wait_frame()) return;
			titlemap_copyPN1full();
			titlemap_copyPN0full();
			titlemap_free();
			if (title_wait_frame()) return;
        }
    }

	TMS99X8.blankScreen = true;
	TMS99X8_syncAllRegisters();
    //debugBorder(5);

    for (uint8_t i=0; i<32; i+=1) {

		map.pos.j = (i&7)*32;
		map.pos.i = 24+(i/8)*24;
		if (title_wait_frame()) return;
		titlemap_free2();
		titlemap_draw_col(1);
		titlemap_draw_col(2);
		if (title_wait_frame()) return;
		titlemap_draw_col(3);
		titlemap_draw_col(4);
		if (title_wait_frame()) return;
		titlemap_draw_col(5);
		titlemap_draw_col(6);
		titlemap_free0();
		if (title_wait_frame()) return;
		titlemap_copyPN1full();
		titlemap_copyPN0full();
		titlemap_free1();

		if (i==30) TMS99X8_setBorderColor(BGray);
	}
	if (title_wait_frame()) return;
	titlemap_free();
	TMS99X8_setBorderColor(BWhite);
    //debugBorder(0);

	for (uint8_t i=0; i<12; i++) {
		state.entities[i].spawn_auto = true;
	}


    {
		map.pos.j = 32;
		map.pos.i = 0;
        for (uint8_t i=0; i<48; i++) {

			if (map.pos.j==0) {
				map.pos.j = 32;
			} else {
				map.pos.j = 0;
			}
			for (uint8_t j=1; j<31; j+=2) {
				if (title_wait_frame()) return;
				titlemap_draw_col(j);
				titlemap_draw_col(j+1);

				//debug_printf("C %d %d %d %d\n", j, map.bank[0].numUsedPatterns, map.bank[1].numUsedPatterns, map.bank[2].numUsedPatterns);
				//debug_printf("D %d %d %d %d\n", j, map.bank[0].numTilesToReleaseL, map.bank[1].numTilesToReleaseL, map.bank[2].numTilesToReleaseL);

			}
			if (title_wait_frame()) return;
			titlemap_draw_tile8(22,31);
			titlemap_draw_tile8(16,31);
			titlemap_draw_tile8(23,31);
			if (title_wait_frame()) return;
			titlemap_copyPN1full();
			titlemap_copyPN0full();
			TMS99X8_setBorderColor(BBlack);
			if (title_wait_frame()) return;
			titlemap_free0();
			if (title_wait_frame()) return;
			titlemap_free1();
			if (title_wait_frame()) return;
			titlemap_free2();
			for (uint8_t j=1; j<33; j+=2) {
				if (title_wait_frame()) return;
			}
        }

        configuration.attract_mode = 9;
        return;
    }
}



#endif
