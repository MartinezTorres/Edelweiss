#include <common.h>
#include <entities/weapons/entity_weapon_bomb_sprite.h>

USING_MODULE(entity_weapon_bomb_sprite, PAGE_D);

static void on_spawn(Entity *entity) {
	
	uint8_t idx = entity->spawn_idx;
//	Entity *wolfi = &state.entities[0];
	
    sprites[idx].enabled = true;
    sprites[idx].patternBlackRequired = true;
    sprites[idx].patternColorRequired = true;
	sprites[idx].overrideColors = false;
	sprites[idx].spriteInfoSegment = MODULE_SEGMENT(entity_weapon_bomb_sprite, PAGE_D);	

	entity->pos.i = state.entities[0].pos.i;
	entity->pos.j = state.entities[0].pos.j;

	sprites[idx].pos.i = entity->pos.i;
	sprites[idx].pos.j = entity->pos.j;

	entity->animation_counter = 0;
}

static void on_despawn(Entity *entity) {

	uint8_t idx = entity->spawn_idx;

	entity->spawn_auto = false;
    sprites[idx].enabled = false;
}

static uint8_t on_update(Entity *entity) {

	uint8_t idx = entity->spawn_idx;

	for (uint8_t i=0; i<state.isr_count_delta; i++) {
		
		if (entity->animation_counter<120) {
			sprites[idx].spriteInfo = &weapon_bomb_0_0;
		} else if (entity->animation_counter<180) {
			
			sprites[idx].pattern1Color = 
				(entity->animation_counter&0x8?BGray:BLightRed);

		} else if (entity->animation_counter<186) {
			sprites[idx].spriteInfo = &weapon_bomb_1_0;
		} else if (entity->animation_counter<190) {
			sprites[idx].spriteInfo = &weapon_bomb_2_0;
			uint8_t tile16 =  overworld_get_tile16(entity->pos.i+0x100, entity->pos.j+0x100);
			//debug_printf("Tile: %d\n",tile16);
			if (tile16==TILE_LARGE_ROCK_SAND || 
				tile16==TILE_LARGE_ROCK_GRAVE || 
				tile16==TILE_LARGE_ROCK_MIXED || 
				tile16==TILE_DOOR_MOUNTAIN_COVERED) {
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
				state.request_pattern_name_transfer = 3;
			}
		} else if (entity->animation_counter<194) {
			sprites[idx].pos.i = entity->pos.i-0x96;
			sprites[idx].pos.j = entity->pos.j-0x68;
		} else if (entity->animation_counter<198) {
			sprites[idx].pos.i = entity->pos.i+0x46;
			sprites[idx].pos.j = entity->pos.j-0x78;
		} else if (entity->animation_counter<202) {
			sprites[idx].pos.i = entity->pos.i-0x66;
			sprites[idx].pos.j = entity->pos.j+0x48;
		} else if (entity->animation_counter<206) {
			sprites[idx].pos.i = entity->pos.i+0x86;
			sprites[idx].pos.j = entity->pos.j+0x98;
		} else if (entity->animation_counter<210) {
			sprites[idx].spriteInfo = &weapon_bomb_3_0;
			sprites[idx].pos.i = entity->pos.i-0x56;
			sprites[idx].pos.j = entity->pos.j-0x68;
		} else if (entity->animation_counter<214) {
			sprites[idx].pos.i = entity->pos.i+0x76;
			sprites[idx].pos.j = entity->pos.j-0x58;
		} else if (entity->animation_counter<218) {
			sprites[idx].pos.i = entity->pos.i-0x96;
			sprites[idx].pos.j = entity->pos.j+0x48;
		} else if (entity->animation_counter<222) {
			sprites[idx].pos.i = entity->pos.i+0x66;
			sprites[idx].pos.j = entity->pos.j+0x88;
		} else if (entity->animation_counter<226) {
			return false;
		}

		entity->animation_counter++;
	}

	return true;
}

static const struct T_Entity_Callbacks callbacks = {
	on_spawn, on_despawn, on_update, on_hit_null
};

void init_weapon_bomb(uint8_t idx) {

	Entity *entity = &state.entities[idx];

	entity->spawn_auto = true;
	entity->spawn_idx = -1;
	entity->spawn_priority = 1;

	entity->damage = 2;

	entity->segment = MODULE_SEGMENT(entity_weapon_bomb, PAGE_C);
	entity->callbacks = &callbacks;
}

