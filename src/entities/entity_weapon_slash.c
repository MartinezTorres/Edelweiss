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

static void on_spawn(Entity *entity) {
	
	uint8_t idx = entity->spawn_idx;
	Entity *wolfi = &state.entities[0];
	
    sprites[idx].enabled = true;
    sprites[idx].patternBlackRequired = true;
    sprites[idx].patternColorRequired = true;
    switch (entity->weapon_type) {
	case E_PAW:
		sprites[idx].overrideColors = false;
		sprites[idx].spriteInfoSegment = 
			MODULE_SEGMENT(entity_weapon_slash_small_sprite, PAGE_D);	
		break;
	case E_CLAW:
		sprites[idx].overrideColors = false;
		sprites[idx].spriteInfoSegment = 
			MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D);	
		break;
	case E_SWORD:
		sprites[idx].overrideColors = true;
		sprites[idx].pattern0Color = BGray;
		sprites[idx].pattern1Color = BLightBlue;
		sprites[idx].spriteInfoSegment = 
			MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D);	
		break;
	case E_AXE:
		sprites[idx].overrideColors = true;
		sprites[idx].pattern0Color = BDarkRed;
		sprites[idx].pattern1Color = BDarkBlue;
		sprites[idx].spriteInfoSegment = 
			MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D);	

		{
			uint16_t i = state.entities[0].pos.i + 0x100 + (sprite_offsets[state.entities[0].weapon_type][2][0]<<4);
			uint16_t j = state.entities[0].pos.j + 0x100 + (sprite_offsets[state.entities[0].weapon_type][2][1]<<4);
			
			uint8_t tile16 =  overworld_get_tile16(i,j);
			debug_printf("Tile: %d\n",tile16);
			debug_printf("Segment: %d\n", sprites[idx].spriteInfoSegment);
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
				state.request_pattern_name_transfer = 3;
			}
		}




		break;
	case E_BUTTER_KNIFE:
	default:
		sprites[idx].overrideColors = true;
		sprites[idx].pattern0Color = BWhite;
		sprites[idx].pattern1Color = BLightYellow;
		sprites[idx].spriteInfoSegment = 
			MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D);	
		break;
	}
	entity->animation_counter = 0;
}

static void on_despawn(Entity *entity) {

	uint8_t idx = entity->spawn_idx;
	
	entity->enabled = false;
    sprites[idx].enabled = false;
}

static uint8_t on_update(Entity *entity) {

	uint8_t idx = entity->spawn_idx;

	for (uint8_t i=0; i<state.isr_count_delta; i++) {
		
		if (entity->weapon_type==E_PAW) {
			sprites[idx].spriteInfo = 
				sprite_table_small[state.entities[0].weapon_type][entity->animation_counter>>1];
		} else {
			sprites[idx].spriteInfo = 
				sprite_table[state.entities[0].weapon_type][entity->animation_counter>>1];
		}
			
		entity->pos.i = state.entities[0].pos.i + 
			(sprite_offsets[state.entities[0].weapon_type][entity->animation_counter>>1][0]<<4);

		entity->pos.j = state.entities[0].pos.j + 
			(sprite_offsets[state.entities[0].weapon_type][entity->animation_counter>>1][1]<<4);

		entity->animation_counter++;
	}

	sprites[idx].pos.i = entity->pos.i;
	sprites[idx].pos.j = entity->pos.j;

	return entity->animation_counter<10;
}

static uint8_t on_hit(Entity *entity, Entity *weapon) {
	
	UNUSED(entity);
	UNUSED(weapon);
	return false;
}


void init_weapon_slash(uint8_t idx, uint8_t weapon_type) {

	Entity *entity = &state.entities[idx];

	entity->enabled = true;
	entity->spawn_idx = -1;
	entity->spawn_priority = 0;

	entity->vel.i = 0;
	entity->vel.j = 0;

	entity->push.i = 0;
	entity->push.j = 0;

	entity->life = 6;
	entity->maximum_life = 6;

	entity->weapon_type = weapon_type;

	entity->damage = 0;

	entity->segment = MODULE_SEGMENT(entity_weapon_slash, PAGE_C);
	entity->on_spawn   = on_spawn;
	entity->on_despawn = on_despawn;
	entity->on_update  = on_update;
	entity->on_hit  = on_hit;

}
