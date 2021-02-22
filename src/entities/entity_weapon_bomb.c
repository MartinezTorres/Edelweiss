#include <common.h>
#include <entities/entity_weapon_bomb_sprite.h>

USING_MODULE(entity_weapon_bomb_sprite, PAGE_D);

void spawn_weapon_bomb(Entity *entity, uint8_t active_entity_index) {
	
    sprites[active_entity_index].enabled = true;
    sprites[active_entity_index].patternBlackRequired = true;
    sprites[active_entity_index].patternColorRequired = true;
	sprites[active_entity_index].overrideColors = false;
	sprites[active_entity_index].spriteInfoSegment = 
		MODULE_SEGMENT(entity_weapon_bomb_sprite, PAGE_D);	

	entity->pos.i = state.entities[0].pos.i;
	entity->pos.j = state.entities[0].pos.j;

	sprites[active_entity_index].pos.i = entity->pos.i;
	sprites[active_entity_index].pos.j = entity->pos.j;

	entity->animationCounter = 0;
}

void despawn_weapon_bomb(Entity *entity, uint8_t active_entity_index) {
	
	entity->enabled = false;
    sprites[active_entity_index].enabled = false;
}

uint8_t update_weapon_bomb(Entity *entity, uint8_t active_entity_index) {

	for (uint8_t i=0; i<isr.deltaFrames; i++) {
		
		if (entity->animationCounter<120) {
			sprites[active_entity_index].spriteInfo = &weapon_bomb_0_0;
		} else if (entity->animationCounter<180) {
			
			sprites[active_entity_index].pattern1Color = 
				(entity->animationCounter&0x8?BGray:BLightRed);

		} else if (entity->animationCounter<186) {
			sprites[active_entity_index].spriteInfo = &weapon_bomb_1_0;
		} else if (entity->animationCounter<190) {
			sprites[active_entity_index].spriteInfo = &weapon_bomb_2_0;
			uint8_t tile16 =  overworld_get_tile16(entity->pos.i+0x100, entity->pos.j+0x100);
			//debug_printf("Tile: %d\n",tile16);
			if (tile16==30 || tile16==95 || tile16==162) {
				overworld_set_map_index(entity->pos.i+0x100, entity->pos.j+0x100, 1);
				
				uint8_t rowScreen8 =  (((entity->pos.i+0x100)>>10)<<2) - map.pos.i;
				uint8_t colScreen8 =  (((entity->pos.j+0x100)>>10)<<2) - map.pos.j;
				for (uint8_t ii=0; ii<4; ii++) {
					for (uint8_t jj=0; jj<4; jj++) {
						uint8_t row = rowScreen8+ii;
						uint8_t col = colScreen8+jj;

						//debug_printf("Row: %d, Col; %d\n",row, col);

						if (row<24 && col<32)
							overworld_draw_tile8(row,col);
					}
				}
				overworld_free();
				isr.requestPatternNameTransfer = 3;
			}
		} else if (entity->animationCounter<194) {
			sprites[active_entity_index].pos.i = entity->pos.i-0x96;
			sprites[active_entity_index].pos.j = entity->pos.j-0x68;
		} else if (entity->animationCounter<198) {
			sprites[active_entity_index].pos.i = entity->pos.i+0x46;
			sprites[active_entity_index].pos.j = entity->pos.j-0x78;
		} else if (entity->animationCounter<202) {
			sprites[active_entity_index].pos.i = entity->pos.i-0x66;
			sprites[active_entity_index].pos.j = entity->pos.j+0x48;
		} else if (entity->animationCounter<206) {
			sprites[active_entity_index].pos.i = entity->pos.i+0x86;
			sprites[active_entity_index].pos.j = entity->pos.j+0x98;
		} else if (entity->animationCounter<210) {
			sprites[active_entity_index].spriteInfo = &weapon_bomb_3_0;
			sprites[active_entity_index].pos.i = entity->pos.i-0x56;
			sprites[active_entity_index].pos.j = entity->pos.j-0x68;
		} else if (entity->animationCounter<214) {
			sprites[active_entity_index].pos.i = entity->pos.i+0x76;
			sprites[active_entity_index].pos.j = entity->pos.j-0x58;
		} else if (entity->animationCounter<218) {
			sprites[active_entity_index].pos.i = entity->pos.i-0x96;
			sprites[active_entity_index].pos.j = entity->pos.j+0x48;
		} else if (entity->animationCounter<222) {
			sprites[active_entity_index].pos.i = entity->pos.i+0x66;
			sprites[active_entity_index].pos.j = entity->pos.j+0x88;
		} else if (entity->animationCounter<226) {
			return false;
		}

		entity->animationCounter++;
	}

	return true;
}
