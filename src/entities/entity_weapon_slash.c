#include <common.h>
#include <entities/entity_weapon_slash_large_sprite.h>
#include <entities/entity_weapon_slash_small_sprite.h>

USING_MODULE(entity_weapon_slash_small_sprite, PAGE_D);
USING_MODULE(entity_weapon_slash_large_sprite, PAGE_D);


//enum    { E_REST, E_LEFT, E_RIGHT,  E_UP, E_DOWN };
static const TSpriteInterlaced * const sprite_table[5][5] = {
{ &weapon_slash_large_1_3, &weapon_slash_large_2_3, &weapon_slash_large_3_3, &weapon_slash_large_3_2, &weapon_slash_large_3_1},
{ &weapon_slash_large_3_2, &weapon_slash_large_3_1, &weapon_slash_large_3_0, &weapon_slash_large_2_0, &weapon_slash_large_1_0},
{ &weapon_slash_large_0_1, &weapon_slash_large_0_2, &weapon_slash_large_0_3, &weapon_slash_large_1_3, &weapon_slash_large_2_3},
{ &weapon_slash_large_2_0, &weapon_slash_large_1_0, &weapon_slash_large_0_0, &weapon_slash_large_0_1, &weapon_slash_large_0_2},
{ &weapon_slash_large_1_3, &weapon_slash_large_2_3, &weapon_slash_large_3_3, &weapon_slash_large_3_2, &weapon_slash_large_3_1},
};

static const TSpriteInterlaced * const sprite_table_small[5][5] = {
{ &weapon_slash_small_1_3, &weapon_slash_small_2_3, &weapon_slash_small_3_3, &weapon_slash_small_3_2, &weapon_slash_small_3_1},
{ &weapon_slash_small_3_2, &weapon_slash_small_3_1, &weapon_slash_small_3_0, &weapon_slash_small_2_0, &weapon_slash_small_1_0},
{ &weapon_slash_small_0_1, &weapon_slash_small_0_2, &weapon_slash_small_0_3, &weapon_slash_small_1_3, &weapon_slash_small_2_3},
{ &weapon_slash_small_2_0, &weapon_slash_small_1_0, &weapon_slash_small_0_0, &weapon_slash_small_0_1, &weapon_slash_small_0_2},
{ &weapon_slash_small_1_3, &weapon_slash_small_2_3, &weapon_slash_small_3_3, &weapon_slash_small_3_2, &weapon_slash_small_3_1},
};

static const int8_t sprite_offsets[5][5][2] = {
{ {8,14}, {14,8}, {16,0}, {14,-8}, {8,-14}},
{ {14,-8}, {8,-14}, {0,-16}, {-8,-14}, {-14,-8}},
{ {-14,8}, {-8,14}, {0,16}, {8,14}, {14,8}},
{ {-8,-14}, {-14,-8}, {-16,0}, {-14,8}, {-8,14}},
{ {8,14}, {14,8}, {16,0}, {14,-8}, {8,-14}},
};


void spawn_weapon_slash(Entity *entity, uint8_t active_entity_index) {
	
    sprites[active_entity_index].enabled = true;
    sprites[active_entity_index].patternBlackRequired = true;
    sprites[active_entity_index].patternColorRequired = true;
    switch (entity->type) {
	case E_PAW:
		sprites[active_entity_index].overrideColors = false;
		sprites[active_entity_index].spriteInfoSegment = 
			MODULE_SEGMENT(entity_weapon_slash_small_sprite, PAGE_D);	
		break;
	case E_CLAW:
		sprites[active_entity_index].overrideColors = false;
		sprites[active_entity_index].spriteInfoSegment = 
			MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D);	
		break;
	case E_SWORD:
		sprites[active_entity_index].overrideColors = true;
		sprites[active_entity_index].pattern0Color = BGray;
		sprites[active_entity_index].pattern1Color = BLightBlue;
		sprites[active_entity_index].spriteInfoSegment = 
			MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D);	
		break;
	case E_AXE:
		sprites[active_entity_index].overrideColors = true;
		sprites[active_entity_index].pattern0Color = BDarkRed;
		sprites[active_entity_index].pattern1Color = BDarkBlue;
		sprites[active_entity_index].spriteInfoSegment = 
			MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D);	

		{
			uint16_t i = state.entities[0].pos.i + 0x100 + (sprite_offsets[state.entities[0].type][2][0]<<4);
			uint16_t j = state.entities[0].pos.j + 0x100 + (sprite_offsets[state.entities[0].type][2][1]<<4);
			
			uint8_t tile16 =  overworld_get_tile16(i,j);
			debug_printf("Tile: %d\n",tile16);
			debug_printf("Segment: %d\n", sprites[active_entity_index].spriteInfoSegment);
			if (tile16==116 || tile16==85) {
				overworld_set_map_index(i, j, 1);
				
				uint8_t rowScreen8 =  ((i>>10)<<2) - map.pos.i;
				uint8_t colScreen8 =  ((j>>10)<<2) - map.pos.j;
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
		}




		break;
	case E_BUTTER_KNIFE:
	default:
		sprites[active_entity_index].overrideColors = true;
		sprites[active_entity_index].pattern0Color = BWhite;
		sprites[active_entity_index].pattern1Color = BLightYellow;
		sprites[active_entity_index].spriteInfoSegment = 
			MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D);	
		break;
	}
	entity->animationCounter = 0;
}

void despawn_weapon_slash(Entity *entity, uint8_t active_entity_index) {
	
	entity->enabled = false;
    sprites[active_entity_index].enabled = false;
}

uint8_t update_weapon_slash(Entity *entity, uint8_t active_entity_index) {

	for (uint8_t i=0; i<isr.deltaFrames; i++) {
		
		if (entity->type==E_PAW) {
			sprites[active_entity_index].spriteInfo = 
				sprite_table_small[state.entities[0].type][entity->animationCounter>>1];
		} else {
			sprites[active_entity_index].spriteInfo = 
				sprite_table[state.entities[0].type][entity->animationCounter>>1];
		}
			
		entity->pos.i = state.entities[0].pos.i + 
			(sprite_offsets[state.entities[0].type][entity->animationCounter>>1][0]<<4);

		entity->pos.j = state.entities[0].pos.j + 
			(sprite_offsets[state.entities[0].type][entity->animationCounter>>1][1]<<4);

		entity->animationCounter++;
	}

	sprites[active_entity_index].pos.i = entity->pos.i;
	sprites[active_entity_index].pos.j = entity->pos.j;

	return entity->animationCounter<10;
}
