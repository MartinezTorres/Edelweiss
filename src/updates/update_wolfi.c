#include "common.h"

USING_MODULE(wolfi, PAGE_D);

void spawn_wolfi(Entity *entity, uint8_t entityIdx) {
	
    sprites[entityIdx].enabled = true;
    sprites[entityIdx].patternBlackRequired = true;
    sprites[entityIdx].patternColorRequired = true;
    sprites[entityIdx].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[entityIdx].spriteInfo = &wolfi_2_0;
	
}

void despawn_wolfi(Entity *entity, uint8_t entityIdx) {

    sprites[entityIdx].enabled = false;
}

uint8_t update_wolfi(Entity *entity, uint8_t entityIdx) {

	//if (isr.globalFrameCount3 == 0) return true;


	if (state.joy==0) {

		// SPRITE POS
		sprites[entityIdx].pos.i = entity->pos.i;
		sprites[entityIdx].pos.j = entity->pos.j;

		entity->animationCounter = 0;
		return true;
	}
	
	for (uint8_t i=0; i<isr.deltaFrames; i++) {
		
		if (++entity->info[0] > 2) {
			entity->info[0]=0;
			continue;
		}

			
		uint16_t tpi = entity->pos.i + 14*32;
		uint16_t tpj1 = entity->pos.j + 4*32;
		uint16_t tpjm1 = entity->pos.j + 6*32;
		uint16_t tpjm2 = entity->pos.j + 9*32;
		uint16_t tpj2 = entity->pos.j + 11*32;
		
		entity->animationCounter++;
		if (state.joy & J_UP) {
			
			for (int i=0; i<2; i++) {
				uint8_t flags = overworld_get_flags(tpi-32, tpj1) | overworld_get_flags(tpi-32, tpj2);
				flags |= overworld_get_flags(tpi-32, tpjm1) | overworld_get_flags(tpi-32, tpjm2);
				if ((flags & 0x1) == 0) {
					entity->pos.i -= 32;
					tpi-=32;
				} else {
					//entity->pos.i -= 32;
				}
			}
			sprites[entityIdx].spriteInfo = (entity->animationCounter & 0x04? &wolfi_1_0 : &wolfi_1_1) ;
		}
		if (state.joy & J_DOWN) {

			for (int i=0; i<2; i++) {
				uint8_t flags = overworld_get_flags(tpi+32, tpj1) | overworld_get_flags(tpi+32, tpj2);
				flags |= overworld_get_flags(tpi+32, tpjm1) | overworld_get_flags(tpi+32, tpjm2);
				if ((flags & 0x1) == 0) {
					entity->pos.i += 32;
					tpi+=32;
				} else {
					//entity->pos.i += 32;
				}
			}

			sprites[entityIdx].spriteInfo = (entity->animationCounter & 0x04? &wolfi_2_0 : &wolfi_2_1);
		}
		if (state.joy & J_RIGHT) {

			for (int i=0; i<2; i++) {
				uint8_t flags = overworld_get_flags(tpi, tpj2+32);
				if ((flags & 0x1) == 0) {
					entity->pos.j += 32;
					tpj1+=32;
					tpj2+=32;
				} else {
					//entity->pos.j += 32;
				}
			}
			sprites[entityIdx].spriteInfo = (entity->animationCounter & 0x04? &wolfi_3_0 : &wolfi_3_1);
		} 
		if (state.joy & J_LEFT) {

			for (int i=0; i<2; i++) {
				uint8_t flags = overworld_get_flags(tpi, tpj1-32);
				if ((flags & 0x1) == 0) {
					entity->pos.j -= 32;
					tpj1-=32;
					tpj2-=32;
				} else {
					//entity->pos.j -= 32;
				}
			}
			sprites[entityIdx].spriteInfo = (entity->animationCounter & 0x04? &wolfi_4_0 : &wolfi_4_1);
		}
	}
			
	// SPRITE POS
	sprites[entityIdx].pos.i = entity->pos.i;
	sprites[entityIdx].pos.j = entity->pos.j;


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
		if (i>13 && isr.targetPos.i<(uint8_t)(127-23)) isr.targetPos.i = map.pos.i+1;
		
		uint8_t j = (state.entities[0].pos.j>>8) - map.pos.j;
		if (j<10 && isr.targetPos.j>0) isr.targetPos.j = map.pos.j-1;
		if (j>20 && isr.targetPos.j<(uint8_t)(255-31)) isr.targetPos.j = map.pos.j+1;

		isr.updateScroll |= (map.pos.j != isr.targetPos.j);
		isr.updateScroll |= (map.pos.i != isr.targetPos.i);
	}

	infoBarUpdateMap();

	return true;
}
