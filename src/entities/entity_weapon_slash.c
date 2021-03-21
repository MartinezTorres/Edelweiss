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
	
	uint8_t spawn_idx = entity->spawn_idx;
	Entity *wolfi = &state.entities[0];

	entity->orientation = wolfi->orientation;
	entity->animation_counter = 0;
	
	
    sprites[spawn_idx].enabled = true;
    sprites[spawn_idx].patternBlackRequired = true;
    sprites[spawn_idx].patternColorRequired = true;
    switch (entity->weapon_type) {
	case E_PAW:
		sprites[spawn_idx].overrideColors = false;
		sprites[spawn_idx].spriteInfoSegment = 
			MODULE_SEGMENT(entity_weapon_slash_small_sprite, PAGE_D);	
		break;
	case E_CLAW:
		sprites[spawn_idx].overrideColors = false;
		sprites[spawn_idx].spriteInfoSegment = 
			MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D);	
		break;
	case E_SWORD:
		sprites[spawn_idx].overrideColors = true;
		sprites[spawn_idx].pattern0Color = BGray;
		sprites[spawn_idx].pattern1Color = BLightBlue;
		sprites[spawn_idx].spriteInfoSegment = 
			MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D);	
		break;
	case E_AXE:
		sprites[spawn_idx].overrideColors = true;
		sprites[spawn_idx].pattern0Color = BDarkRed;
		sprites[spawn_idx].pattern1Color = BDarkBlue;
		sprites[spawn_idx].spriteInfoSegment = 
			MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D);	

		{
			
			uint16_tp p;
			p.i = wolfi->pos.i + (sprite_offsets[entity->orientation][2][0]<<4) + 0x100;
			p.j = wolfi->pos.j + (sprite_offsets[entity->orientation][2][1]<<4) + 0x100;
			
			uint8_t tile16 =  overworld_get_tile16(p.i, p.j);
			//debug_printf("Tile: %d\n",tile16);
			//debug_printf("Segment: %d\n", sprites[spawn_idx].spriteInfoSegment);
			if (tile16==116 || tile16==85) {
				overworld_set_map_index(p.i, p.j, 1);
				
				uint8_t rowScreen8 =  ((p.i>>10)<<2) - map.pos.i;
				uint8_t colScreen8 =  ((p.j>>10)<<2) - map.pos.j;
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
				state.request_pattern_name_transfer = true;
			}
		}




		break;
	case E_BUTTER_KNIFE:
	default:
		sprites[spawn_idx].overrideColors = true;
		sprites[spawn_idx].pattern0Color = BWhite;
		sprites[spawn_idx].pattern1Color = BLightYellow;
		sprites[spawn_idx].spriteInfoSegment = 
			MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D);	
		break;
	}

	
	if (entity->weapon_type==E_PAW) {

		if (entity->orientation==E_UP) {

			entity->pos.i = wolfi->pos.i - (5 << 5);
			entity->pos.j = wolfi->pos.j;
			weapon_collision_detection(spawn_idx, 10, 16+10+10);

		} else if (entity->orientation==E_DOWN) {

			entity->pos.i = wolfi->pos.i + (5 << 5);
			entity->pos.j = wolfi->pos.j;
			weapon_collision_detection(spawn_idx, 10, 16+10+10);

		} else if (entity->orientation==E_LEFT) {

			entity->pos.i = wolfi->pos.i;
			entity->pos.j = wolfi->pos.j - (5 << 5);
			weapon_collision_detection(spawn_idx, 16+10+10, 10);
			
		} else {

			entity->pos.i = wolfi->pos.i;
			entity->pos.j = wolfi->pos.j + (5 << 5);
			weapon_collision_detection(spawn_idx, 16+10+10, 10);

		}
		
	} else {


		if (entity->orientation==E_UP) {

			entity->pos.i = wolfi->pos.i - (6 << 5);
			entity->pos.j = wolfi->pos.j;
			weapon_collision_detection(spawn_idx, 12, 16+12+12);

		} else if (entity->orientation==E_DOWN) {

			entity->pos.i = wolfi->pos.i + (6 << 5);
			entity->pos.j = wolfi->pos.j;
			weapon_collision_detection(spawn_idx, 12, 16+12+12);

		} else if (entity->orientation==E_LEFT) {

			entity->pos.i = wolfi->pos.i;
			entity->pos.j = wolfi->pos.j - (6 << 5);
			weapon_collision_detection(spawn_idx, 16+12+12, 12);
			
		} else {

			entity->pos.i = wolfi->pos.i;
			entity->pos.j = wolfi->pos.j + (6 << 5);
			weapon_collision_detection(spawn_idx, 16+12+12, 12);
		}
	}
	
	
}

static void on_despawn(Entity *entity) {

	uint8_t spawn_idx = entity->spawn_idx;
	
	entity->spawn_auto = false;
    sprites[spawn_idx].enabled = false;
}

static uint8_t on_update(Entity *entity) {

	uint8_t spawn_idx = entity->spawn_idx;
	Entity *wolfi = &state.entities[0];

	for (uint8_t i=0; i<state.isr_count_delta; i++) {
		
		if (entity->weapon_type==E_PAW) {
			sprites[spawn_idx].spriteInfo = 
				sprite_table_small[entity->orientation][entity->animation_counter>>1];
		} else {
			sprites[spawn_idx].spriteInfo = 
				sprite_table[entity->orientation][entity->animation_counter>>1];
		}
			
		entity->pos.i = wolfi->pos.i + (sprite_offsets[entity->orientation][entity->animation_counter>>1][0]<<4);

		entity->pos.j = wolfi->pos.j + (sprite_offsets[entity->orientation][entity->animation_counter>>1][1]<<4);

		entity->animation_counter++;
		if (entity->animation_counter ==10) return false; // despawn
	}

	sprites[spawn_idx].pos.i = entity->pos.i;
	sprites[spawn_idx].pos.j = entity->pos.j;

	return true;
}

static const struct T_Entity_Callbacks callbacks = {
	on_spawn, on_despawn, on_update, on_hit_null
};

void init_weapon_slash(uint8_t idx, uint8_t weapon_type) {

	Entity *entity = &state.entities[idx];

	entity->spawn_auto = true;
	entity->spawn_idx = -1;
	entity->spawn_priority = 0;

	entity->weapon_type = weapon_type;

	switch (entity->weapon_type) {
	case E_PAW:
		entity->damage = 1;
		break;
	case E_CLAW:
		entity->damage = 4;
		break;
	case E_SWORD:
		entity->damage = 8;
		break;
	case E_AXE:
		entity->damage = 2;
		break;
	case E_BUTTER_KNIFE:
	default:
		entity->damage = 16;
		break;
	}
	
	entity->segment = MODULE_SEGMENT(entity_weapon_slash, PAGE_C);
	entity->callbacks = &callbacks;
}
