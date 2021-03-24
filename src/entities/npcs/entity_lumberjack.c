#include <common.h>
#include <entities/npcs/entity_npcs_sprites.h>

USING_MODULE(entity_npcs_sprites, PAGE_D);

static void on_spawn(Entity *entity) {
	
	uint8_t spawn_idx = entity->spawn_idx;

    sprites[spawn_idx].enabled = true;
    sprites[spawn_idx].patternBlackRequired = true;
    sprites[spawn_idx].patternColorRequired = true;
    sprites[spawn_idx].spriteInfoSegment = MODULE_SEGMENT(entity_npcs_sprites, PAGE_D);
    sprites[spawn_idx].spriteInfo = &npcs_0_0;

	sprites[spawn_idx].pos = entity->pos;
}

static void on_despawn(Entity *entity) {

	uint8_t spawn_idx = entity->spawn_idx;

	if (entity->is_following) {
		entity->spawn_auto = false;
		entity->is_following = false;
		state.follower_entity_spawn_idx = 0;
	}
    sprites[spawn_idx].enabled = false;
}

static uint8_t on_update(Entity *entity) {

	uint8_t spawn_idx = entity->spawn_idx;

	Entity *wolfi = &state.entities[0];
	
	if (entity->is_following) {
		
		if (entity->orientation == E_LEFT) {
			
			entity->selected_orientation = E_LEFT;			
		}

		if (entity->orientation == E_RIGHT) {

			entity->selected_orientation = E_RIGHT;			
		}

		if (entity->selected_orientation == E_LEFT) {

			sprites[spawn_idx].spriteInfo = (wolfi->animation_counter & 0x04? &npcs_0_0 : &npcs_0_1);						
		}

		if (entity->selected_orientation == E_RIGHT) {

			sprites[spawn_idx].spriteInfo = (wolfi->animation_counter & 0x04? &npcs_0_2 : &npcs_0_3);						
		}

	} else {

		if (collision_wolfi(spawn_idx)) {
			
			
			large_message("I WAS CUTTING\nWOOD WHEN THE\nMONSTERS APPEARED.");
			large_message("I CAN'T RETURN ALONE!\nBRING ME TO THE\nTOWN HALL, PLEASE.");
			
			
			entity->is_following = true;
			entity->orientation = E_LEFT;
			entity->selected_orientation = E_LEFT;

			for (uint8_t i=0; i<8; i++) {
				state.history_wolfi_pos[i] = entity->pos;
				state.history_wolfi_visibility[i] = true;
				state.history_wolfi_orientation[i] = E_LEFT;

			}
			state.follower_entity_spawn_idx = entity->spawn_idx;
		}
	}

	return true;
}

static const struct T_Entity_Callbacks callbacks = {
	on_spawn, on_despawn, on_update, on_hit_default
};

void init_lumberjack(uint8_t spawn_idx, uint8_t i, uint8_t j) {

	Entity *entity = &state.entities[spawn_idx];

	entity->spawn_auto = true;
	entity->spawn_idx = -1;
	entity->spawn_priority = 4;

	entity->is_following = false;

	entity->pos.i = ((uint16_t)i)<<8;
	entity->pos.j = ((uint16_t)j)<<8;

	entity->segment = MODULE_SEGMENT(entity_lumberjack, PAGE_C);
	entity->callbacks = &callbacks;

}
