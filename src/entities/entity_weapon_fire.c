#include <common.h>
#include <entities/entity_weapon_fire_sprite.h>

USING_MODULE(entity_weapon_fire_sprite, PAGE_D);


static void on_spawn(Entity *entity) {
	
	uint8_t idx = entity->spawn_idx;
	Entity *wolfi = &state.entities[0];

    sprites[idx].enabled = true;
    sprites[idx].patternBlackRequired = true;
    sprites[idx].patternColorRequired = true;
	sprites[idx].overrideColors = false;
	sprites[idx].spriteInfoSegment = MODULE_SEGMENT(entity_weapon_fire_sprite, PAGE_D);	

	sprites[idx].pos.i = entity->pos.i;
	sprites[idx].pos.j = entity->pos.j;

	switch (wolfi->orientation) {
	case E_REST:
	case E_DOWN:
		entity->vel.i = 16*8-1;
		entity->vel.j = 0;
		break;
	case E_UP:
		entity->vel.i = -16*8+1;
		entity->vel.j = 0;
		break;
	case E_LEFT:
		entity->vel.i = 0;
		entity->vel.j = -16*8+1;
		break;
	case E_RIGHT:
		entity->vel.i = 0;
		entity->vel.j = 16*8-1;
		break;
	}

	entity->pos.i = wolfi->pos.i + entity->vel.i*3;
	entity->pos.j = wolfi->pos.j + entity->vel.j*3;

	entity->animation_counter = 0;
}

static void on_despawn(Entity *entity) {

	uint8_t idx = entity->spawn_idx;

	entity->enabled = false;
    sprites[idx].enabled = false;
}

static const TSpriteInterlaced * const sprite_table[4] =
{ &weapon_fire_0_0, &weapon_fire_1_0, &weapon_fire_2_0, &weapon_fire_3_0,};

static uint8_t on_update(Entity *entity) {

	uint8_t idx = entity->spawn_idx;

	for (uint8_t i=0; i<state.isr_count_delta; i++) {
		
		entity->pos.i += entity->vel.i;
		entity->pos.j += entity->vel.j;

		
		sprites[idx].spriteInfo = sprite_table[((entity->animation_counter++)>>2)&3];
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


void init_weapon_fire(uint8_t idx) {

	Entity *entity = &state.entities[idx];
	Entity *wolfi = &state.entities[0];

	entity->enabled = true;
	entity->spawn_idx = -1;
	entity->spawn_priority = 1;

	entity->anchor.i = 0;
	entity->anchor.j = 0;

	entity->push.i = 0;
	entity->push.j = 0;

	entity->life = 8;
	entity->maximum_life = 8;
	entity->invulnerable_frames = 0;

	entity->damage = 2;

	entity->segment = MODULE_SEGMENT(entity_weapon_fire, PAGE_C);
	entity->on_spawn   = on_spawn;
	entity->on_despawn = on_despawn;
	entity->on_update  = on_update;
	entity->on_hit  = on_hit;
}
