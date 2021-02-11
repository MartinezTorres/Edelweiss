#include <common.h>
#include <entities/entity_weapon_arrow_sprite.h>

USING_MODULE(entity_weapon_arrow_sprite, PAGE_D);


void spawn_weapon_bow(Entity *entity, uint8_t active_entity_index) {
	
    sprites[active_entity_index].enabled = true;
    sprites[active_entity_index].patternBlackRequired = true;
    sprites[active_entity_index].patternColorRequired = true;
	sprites[active_entity_index].overrideColors = false;
	sprites[active_entity_index].spriteInfoSegment = 
		MODULE_SEGMENT(entity_weapon_arrow_sprite, PAGE_D);	
	
	switch (state.entities[0].type) {
	case E_REST:
	case E_DOWN:
		sprites[active_entity_index].spriteInfo = &weapon_arrow_2_0;
		entity->vel.i = 16*6;
		entity->vel.j = 0;
		break;
	case E_UP:
		sprites[active_entity_index].spriteInfo = &weapon_arrow_0_0;
		entity->vel.i = -16*6;
		entity->vel.j = 0;
		break;
	case E_LEFT:
		sprites[active_entity_index].spriteInfo = &weapon_arrow_3_0;
		entity->vel.i = 0;
		entity->vel.j = -16*6;
		break;
	case E_RIGHT:
		sprites[active_entity_index].spriteInfo = &weapon_arrow_1_0;
		entity->vel.i = 0;
		entity->vel.j = 16*6;
		break;
	}


	entity->pos.i = state.entities[0].pos.i + entity->vel.i*3;
	entity->pos.j = state.entities[0].pos.j + entity->vel.j*3;

	sprites[active_entity_index].pos.i = entity->pos.i;
	sprites[active_entity_index].pos.j = entity->pos.j;
}

void despawn_weapon_bow(Entity *entity, uint8_t active_entity_index) {
	
	entity->enabled = false;
    sprites[active_entity_index].enabled = false;
}

uint8_t update_weapon_bow(Entity *entity, uint8_t active_entity_index) {

	for (uint8_t i=0; i<isr.deltaFrames; i++) {
		
		entity->pos.i += entity->vel.i;
		entity->pos.j += entity->vel.j;
	}
	sprites[active_entity_index].pos.i = entity->pos.i;
	sprites[active_entity_index].pos.j = entity->pos.j;

	return true;
}
