#include <common.h>
#include <entities/entity_weapon_arrow_sprite.h>

USING_MODULE(entity_weapon_arrow_sprite, PAGE_D);

static void on_spawn(Entity *entity) {
	
	uint8_t idx = entity->spawn_idx;
	Entity *wolfi = &state.entities[0];
	
    sprites[idx].enabled = true;
    sprites[idx].patternBlackRequired = true;
    sprites[idx].patternColorRequired = true;
	sprites[idx].overrideColors = false;
	sprites[idx].spriteInfoSegment = 
		MODULE_SEGMENT(entity_weapon_arrow_sprite, PAGE_D);	
	
	switch (state.entities[0].orientation) {
	case E_REST:
	case E_DOWN:
		sprites[idx].spriteInfo = &weapon_arrow_2_0;
		entity->vel.i = 16*6;
		entity->vel.j = 0;
		break;
	case E_UP:
		sprites[idx].spriteInfo = &weapon_arrow_0_0;
		entity->vel.i = -16*6;
		entity->vel.j = 0;
		break;
	case E_LEFT:
		sprites[idx].spriteInfo = &weapon_arrow_3_0;
		entity->vel.i = 0;
		entity->vel.j = -16*6;
		break;
	case E_RIGHT:
		sprites[idx].spriteInfo = &weapon_arrow_1_0;
		entity->vel.i = 0;
		entity->vel.j = 16*6;
		break;
	}


	entity->pos.i = state.entities[0].pos.i + entity->vel.i*3;
	entity->pos.j = state.entities[0].pos.j + entity->vel.j*3;

	sprites[idx].pos.i = entity->pos.i;
	sprites[idx].pos.j = entity->pos.j;
}

static void on_despawn(Entity *entity) {

	uint8_t idx = entity->spawn_idx;
	
	entity->enabled = false;
    sprites[idx].enabled = false;
}

static uint8_t on_update(Entity *entity) {

	uint8_t idx = entity->spawn_idx;

	for (uint8_t i=0; i<state.isr_count_delta; i++) {
		
		entity->pos.i += entity->vel.i;
		entity->pos.j += entity->vel.j;
	}
	sprites[idx].pos.i = entity->pos.i;
	sprites[idx].pos.j = entity->pos.j;

	return true;
}


static uint8_t on_hit(Entity *entity, Entity *weapon) {
	
	UNUSED(entity);
	UNUSED(weapon);
	return false;
}


void init_weapon_bow(uint8_t idx) {

	Entity *entity = &state.entities[idx];
	Entity *wolfi = &state.entities[0];

	entity->enabled = true;
	entity->spawn_idx = -1;
	entity->spawn_priority = 1;

	entity->anchor.i = 0;
	entity->anchor.j = 0;

	entity->push.i = 0;
	entity->push.j = 0;

	entity->life = 0;
	entity->maximum_life = 0;
	entity->invulnerable_frames = 0;

	entity->damage = 2;

	entity->segment = MODULE_SEGMENT(entity_weapon_bow, PAGE_C);
	entity->on_spawn   = on_spawn;
	entity->on_despawn = on_despawn;
	entity->on_update  = on_update;
	entity->on_hit  = on_hit;
}

