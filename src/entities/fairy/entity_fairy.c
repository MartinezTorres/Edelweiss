#include <common.h>
#include "entity_fairy_sprite.h"

USING_MODULE(entity_fairy_sprite, PAGE_D);

static void on_spawn_top(Entity *entity) {
	
	uint8_t idx = entity->spawn_idx;
	
    sprites[idx].enabled = true;
    sprites[idx].patternBlackRequired = true;
    sprites[idx].patternColorRequired = true;
	sprites[idx].overrideColors = false;
	sprites[idx].spriteInfoSegment = MODULE_SEGMENT(entity_fairy_sprite, PAGE_D);	
	sprites[idx].spriteInfo = &fairy_0_0;
	sprites[idx].pos = entity->pos;
}

static void on_spawn_bottom(Entity *entity) {
	
	uint8_t idx = entity->spawn_idx;
	
    sprites[idx].enabled = true;
    sprites[idx].patternBlackRequired = true;
    sprites[idx].patternColorRequired = true;
	sprites[idx].overrideColors = false;
	sprites[idx].spriteInfoSegment = MODULE_SEGMENT(entity_fairy_sprite, PAGE_D);	
	sprites[idx].spriteInfo = &fairy_1_0;
	sprites[idx].pos = entity->pos;

}

static void on_despawn(Entity *entity) {

	uint8_t idx = entity->spawn_idx;
    sprites[idx].enabled = false;
}

static const int8_t fairy_pos[] = { 0, 12, 23, 35, 46, 57, 67, 76, 85, 93, 100, 106, 111, 115, 118, 119, 120, 119, 118, 115, 111, 106, 100, 93, 85, 76, 67, 57, 46, 35, 23, 12, -0, -12, -23, -35, -46, -57, -67, -76, -85, -93, -100, -106, -111, -115, -118, -119, -120, -119, -118, -115, -111, -106, -100, -93, -85, -76, -67, -57, -46, -35, -23, -12, };

static uint8_t on_update_top(Entity *entity) {

	uint8_t spawn_idx = entity->spawn_idx;
	
	uint16_tp anchor16;
	anchor16.i = ((uint16_t)(entity->anchor8.i))<<8;
	anchor16.j = ((uint16_t)(entity->anchor8.j))<<8;

	entity->pos.i = anchor16.i + fairy_pos[(state.isr_count>>1) & 63];

	sprites[spawn_idx].pos.i = entity->pos.i;
	sprites[spawn_idx].pos.j = entity->pos.j;

	return true;
}

static uint8_t on_update_bottom(Entity *entity) {

	uint8_t spawn_idx = entity->spawn_idx;

	uint16_tp anchor16;
	anchor16.i = ((uint16_t)(entity->anchor8.i))<<8;
	anchor16.j = ((uint16_t)(entity->anchor8.j))<<8;

	entity->pos.i = anchor16.i + fairy_pos[(state.isr_count>>1) & 63];

	sprites[spawn_idx].pos.i = entity->pos.i;
	sprites[spawn_idx].pos.j = entity->pos.j;

	return true;
}

static const struct T_Entity_Callbacks callbacks_top = {
	on_spawn_top, on_despawn, on_update_top, on_hit_null
};

static const struct T_Entity_Callbacks callbacks_bottom = {
	on_spawn_bottom, on_despawn, on_update_bottom, on_hit_null
};

void init_fairy() {

	Entity *entity_top    = &state.entities[ENTITY_FAIRY_TOP];
	Entity *entity_bottom = &state.entities[ENTITY_FAIRY_BOTTOM];

	entity_top->spawn_auto = false;
	entity_top->spawn_idx = -1;
	entity_top->spawn_priority = 2;
	
	entity_top->animation_counter = 0;  
		
	entity_top->segment = MODULE_SEGMENT(entity_fairy, PAGE_C);
	entity_top->callbacks = &callbacks_top;



	entity_bottom->spawn_auto = false;
	entity_bottom->spawn_idx = -1;
	entity_bottom->spawn_priority = 2;
	
	entity_bottom->animation_counter = 0;  
		
	entity_bottom->segment = MODULE_SEGMENT(entity_fairy, PAGE_C);
	entity_bottom->callbacks = &callbacks_bottom;

}
