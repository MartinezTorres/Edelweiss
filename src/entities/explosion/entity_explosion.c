#include <common.h>
#include <entities/explosion/entity_explosion_sprite.h>

USING_MODULE(entity_explosion_sprite, PAGE_D);

static void on_spawn(Entity *entity) {
	
	uint8_t idx = entity->spawn_idx;
	
    sprites[idx].enabled = true;
    sprites[idx].patternBlackRequired = true;
    sprites[idx].patternColorRequired = true;
	sprites[idx].overrideColors = false;
	sprites[idx].spriteInfoSegment = MODULE_SEGMENT(entity_explosion_sprite, PAGE_D);	
	sprites[idx].spriteInfo = &explosion_0_0;

	sprites[idx].pos = entity->pos;

	entity->animation_counter = 0;
}

static void on_despawn(Entity *entity) {

	uint8_t idx = entity->spawn_idx;
    sprites[idx].enabled = false;
}

static uint8_t on_update(Entity *entity) {

	uint8_t idx = entity->spawn_idx;

	for (uint8_t i=0; i<state.isr_count_delta; i++) {
		
		if (entity->animation_counter==6) sprites[idx].spriteInfo = &explosion_1_0;
		if (entity->animation_counter==12) sprites[idx].spriteInfo = &explosion_2_0;
		if (entity->animation_counter==18) sprites[idx].spriteInfo = &explosion_3_0;
		if (entity->animation_counter==24) return false;
		entity->animation_counter++;
	}

	return true;
}

static const struct T_Entity_Callbacks callbacks = {
	on_spawn, on_despawn, on_update, on_hit_null
};

void init_explosion(uint8_t idx) {

	Entity *entity = &state.entities[idx];

	entity->spawn_auto = false;
	entity->spawn_idx = -1;
	entity->spawn_priority = 4;

	entity->segment = MODULE_SEGMENT(entity_explosion, PAGE_C);
	entity->callbacks = &callbacks;
}
