#include <common.h>
#include <entities/entity_wolfi_sprite.h>

USING_MODULE(entity_wolfi_sprite, PAGE_D);


void spawn_wolfi(Entity *entity_skip, uint8_t entityIdx) {
	
    sprites[entityIdx].enabled = true;
    sprites[entityIdx].patternBlackRequired = true;
    sprites[entityIdx].patternColorRequired = true;
    sprites[entityIdx].spriteInfoSegment = MODULE_SEGMENT(entity_wolfi_sprite, PAGE_D);
    sprites[entityIdx].spriteInfo = &wolfi_1_0;
	
}

void despawn_wolfi(Entity *entity_skip, uint8_t entityIdx) {

    sprites[entityIdx].enabled = false;
}

uint8_t update_wolfi(Entity *entity_skip, uint8_t entityIdx) {

	//if (isr.globalFrameCount3 == 0) return true;

	if (state.entities[0].invulnerable_frames) {
		for (uint8_t i=0; i<isr.deltaFrames; i++) {
			if (state.entities[0].invulnerable_frames) {
				state.entities[0].invulnerable_frames--;
			}
		}
		if ((state.entities[0].invulnerable_frames>>2) & 1) {
			sprites[entityIdx].enabled = false;
		} else {
			sprites[entityIdx].enabled = true;
		}
	}

	if (state.keyboard[8]==255) {

		// SPRITE POS
		sprites[entityIdx].pos.i = state.entities[0].pos.i;
		sprites[entityIdx].pos.j = state.entities[0].pos.j;

		state.entities[0].animationCounter = 0;
		return true;
	}
	
	
	tmp.old_pos = state.entities[0].pos;
	
	for (uint8_t i=0; i<isr.deltaFrames; i++) {
		
		if (++state.entities[0].info[0] > 2) {
			state.entities[0].info[0]=0;
			continue;
		}
		
		uint16_t tpi = state.entities[0].pos.i + 14*32;
		uint16_t tpj1 = state.entities[0].pos.j + 4*32;
		uint16_t tpjm1 = state.entities[0].pos.j + 6*32;
		uint16_t tpjm2 = state.entities[0].pos.j + 9*32;
		uint16_t tpj2 = state.entities[0].pos.j + 11*32;
		
		state.entities[0].animationCounter++;
		if (~state.keyboard[8] & K_UP) {
			
			for (int i=0; i<2; i++) {
				uint8_t flags = overworld_get_flags(tpi-32, tpj1) | overworld_get_flags(tpi-32, tpj2);
				flags |= overworld_get_flags(tpi-32, tpjm1) | overworld_get_flags(tpi-32, tpjm2);
				if ((flags & 0x1) == 0) {
					state.entities[0].pos.i -= 32;
					tpi-=32;
				} else {
					//state.entities[0].pos.i -= 32;
				}
			}
			state.entities[0].type = E_UP;
			sprites[entityIdx].spriteInfo = (state.entities[0].animationCounter & 0x04? &wolfi_1_0 : &wolfi_1_1) ;
		}
		if (~state.keyboard[8] & K_DOWN) {

			for (int i=0; i<2; i++) {
				uint8_t flags = overworld_get_flags(tpi+32, tpj1) | overworld_get_flags(tpi+32, tpj2);
				flags |= overworld_get_flags(tpi+32, tpjm1) | overworld_get_flags(tpi+32, tpjm2);
				if ((flags & 0x1) == 0) {
					state.entities[0].pos.i += 32;
					tpi+=32;
				} else {
					//state.entities[0].pos.i += 32;
				}
			}

			state.entities[0].type = E_DOWN;
			sprites[entityIdx].spriteInfo = (state.entities[0].animationCounter & 0x04? &wolfi_2_0 : &wolfi_2_1);
		}
		if (~state.keyboard[8] & K_RIGHT) {

			for (int i=0; i<2; i++) {
				uint8_t flags = overworld_get_flags(tpi, tpj2+32);
				if ((flags & 0x1) == 0) {
					state.entities[0].pos.j += 32;
					tpj1+=32;
					tpj2+=32;
				} else {
					//state.entities[0].pos.j += 32;
				}
			}
			state.entities[0].type = E_RIGHT;
			sprites[entityIdx].spriteInfo = (state.entities[0].animationCounter & 0x04? &wolfi_3_0 : &wolfi_3_1);
		} 
		if (~state.keyboard[8] & K_LEFT) {

			for (int i=0; i<2; i++) {
				uint8_t flags = overworld_get_flags(tpi, tpj1-32);
				if ((flags & 0x1) == 0) {
					state.entities[0].pos.j -= 32;
					tpj1-=32;
					tpj2-=32;
				} else {
					//state.entities[0].pos.j -= 32;
				}
			}
			state.entities[0].type = E_LEFT;
			sprites[entityIdx].spriteInfo = (state.entities[0].animationCounter & 0x04? &wolfi_4_0 : &wolfi_4_1);
		}


		
		// Triggers
		{

			uint16_t tpi = state.entities[0].pos.i + 14*32;
			uint16_t tpjm1 = state.entities[0].pos.j + 6*32;
			uint16_t tpjm2 = state.entities[0].pos.j + 9*32;

			uint8_t flags = overworld_get_flags(tpi, tpjm1) | overworld_get_flags(tpi, tpjm2);
			if (flags & 0x2) TRAMPOLINE_PAGE_C( wolfi_triggers );
		}
		
		
	}
			
	// SPRITE POS
	sprites[entityIdx].pos.i = state.entities[0].pos.i;
	sprites[entityIdx].pos.j = state.entities[0].pos.j;


	// SCROLLING			
	if (0) {
		if ( ( (state.entities[0].pos.j + 0x80) >> 8) < 16 ) {
			
			isr.targetPos.j = 0;
		
		} else if ( ( (state.entities[0].pos.j + 0x80) >> 8) > (256-16) ) {

			isr.targetPos.j = (uint8_t)(255-31);
			
		} else {
			
			isr.targetPos.j = ( (state.entities[0].pos.j + 0x80) >> 8)-16;
		}

		if ( ( (state.entities[0].pos.i + 0x80 ) >> 8) < 11 ) {
			
			isr.targetPos.i = 0;
		
		} else if ( ( (state.entities[0].pos.i + 0x80 ) >> 8) > (128-14) ) {

			isr.targetPos.i = 127-23;
			
		} else {
			
			isr.targetPos.i = ( (state.entities[0].pos.i + 0x80) >> 8) - 11;
		}

		isr.updateScroll |= (map.pos.j != isr.targetPos.j);
		isr.updateScroll |= (map.pos.i != isr.targetPos.i);
	}

	{

		uint8_t i = (state.entities[0].pos.i>>8) - map.pos.i;
		if (i<8 && isr.targetPos.i>0) isr.targetPos.i =  map.pos.i-1;
		if (i>13 && isr.targetPos.i<(uint8_t)(129-23)) isr.targetPos.i = map.pos.i+1;
		
		uint8_t j = (state.entities[0].pos.j>>8) - map.pos.j;
		if (j<10 && isr.targetPos.j>0) isr.targetPos.j = map.pos.j-1;
		if (j>20 && isr.targetPos.j<(uint8_t)(255-31)) isr.targetPos.j = map.pos.j+1;

		isr.updateScroll |= (map.pos.j != isr.targetPos.j);
		isr.updateScroll |= (map.pos.i != isr.targetPos.i);
	}

	IN_MODULE(infobar, PAGE_B, infobar_update_map());

	return true;
}
