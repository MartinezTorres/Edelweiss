#include <common.h>
#include <entities/explosion/entity_explosion_sprite.h>

USING_MODULE(entity_explosion_sprite, PAGE_D);

#if EDW_VEXEL
#include "vx_bind_effect_step.h"
#include "vx_sprite_assets.h"
#endif

static void on_spawn(Entity *entity) {
	
	uint8_t idx = entity->spawn_idx;
	
    sprites[idx].enabled = true;
    sprites[idx].patternBlackRequired = true;
    sprites[idx].patternColorRequired = true;
	sprites[idx].overrideColors = false;
#if EDW_VEXEL
    sprites[idx].spriteInfo=nullptr;
    sprites[idx].resourceRequest=edw_explosion_sprite(0);
#else
	sprites[idx].spriteInfoSegment = MODULE_SEGMENT(entity_explosion_sprite, PAGE_D);	
	sprites[idx].spriteInfo = &explosion_0_0;
#endif

	sprites[idx].pos = entity->pos;

	entity->animation_counter = 0;
}

static void on_despawn(Entity *entity) {

	uint8_t idx = entity->spawn_idx;
    sprites[idx].enabled = false;
#if EDW_VEXEL
    sprites[idx].resourceRequest=0;sprites[idx].spriteInfo=nullptr;
#endif
}

static uint8_t on_update(Entity *entity) {

	uint8_t idx = entity->spawn_idx;

#if EDW_VEXEL
    VX_BIND_effect_step_LOCAL;
    uint8_t live,frame;
    vx_bind_effect_step_frame.a0=entity->animation_counter;vx_bind_effect_step_frame.a1=state.isr_count_delta;
    vx_bind_effect_step_run();
    entity->animation_counter=vx_bind_effect_step_frame.result.v1;
    live=vx_bind_effect_step_frame.result.v0;frame=vx_bind_effect_step_frame.result.v2;
    if(frame!=255) {
        sprites[idx].resourceRequest=edw_explosion_sprite(frame);
    }
    return live;
#else
	for (uint8_t i=0; i<state.isr_count_delta; i++) {
		
		if (entity->animation_counter==6) sprites[idx].spriteInfo = &explosion_1_0;
		if (entity->animation_counter==12) sprites[idx].spriteInfo = &explosion_2_0;
		if (entity->animation_counter==18) sprites[idx].spriteInfo = &explosion_3_0;
		if (entity->animation_counter==24) return false;
		entity->animation_counter++;
	}

	return true;
#endif
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

#ifdef EDW_ENCOUNTER
#define EDW_EFFECT_TEST encounter_explosion
#define EDW_EFFECT_INIT init_explosion
#define EDW_EFFECT_SPARK 0
#define EDW_EFFECT_FIRST EDW_EXPLOSION_SPRITE_FIRST
#include "../../../tests/effects_encounter.h"
#endif
