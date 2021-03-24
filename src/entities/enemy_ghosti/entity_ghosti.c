#include <common.h>
#include "entity_ghosti_sprite.h"

USING_MODULE(entity_ghosti_sprite, PAGE_D);

static void on_spawn(Entity *entity) {
	
	uint8_t spawn_idx = entity->spawn_idx;
    sprites[spawn_idx].enabled = true;
    sprites[spawn_idx].patternBlackRequired = true;
    sprites[spawn_idx].patternColorRequired = true;
    sprites[spawn_idx].spriteInfoSegment = MODULE_SEGMENT(entity_ghosti_sprite, PAGE_D);	

	entity->vel.i = (rand16()&1)?-1:1;
	entity->vel.j = (rand16()&1)?-2:2;
	if (rand16()&1) entity->vel.i *= 2;
	if (rand16()&1) entity->vel.j *= 2;

	uint16_tp anchor16;
	anchor16.i = ((uint16_t)(entity->anchor8.i))<<8;
	anchor16.j = ((uint16_t)(entity->anchor8.j))<<8;

	entity->pos.i = anchor16.i + ((rand16()&1)?-0x100:-0x100);
	entity->pos.j = anchor16.j + ((rand16()&1)?-0x200:-0x200);

	sprites[spawn_idx].pos.i = entity->pos.i;
	sprites[spawn_idx].pos.j = entity->pos.j;

	entity->invulnerable_frames = 0;

//    debug_printf("spawn ghosti %d %d\n", spawn_idx, state.spawns[spawn_idx]);

}

static void on_despawn(Entity *entity) {
	
	uint8_t spawn_idx = entity->spawn_idx;
    sprites[spawn_idx].enabled = false;
    
//    debug_printf("despawn ghosti %d %d\n", spawn_idx, state.spawns[spawn_idx]);
    
}

static uint8_t on_update(Entity *entity) {

	
	Entity *wolfi = &state.entities[0];
	uint8_t spawn_idx = entity->spawn_idx;
	
	if (!generic_entity_invulnerable_frames_and_pushing(spawn_idx)) return false;
	
	if (((state.game_cycles+spawn_idx)&3) != 0) return true;
	
	// Ghosts can only be killed with the butter knife
	entity->life = entity->maximum_life; 

	// MOVEMENT
	uint16_tp anchor16;
	anchor16.i = ((uint16_t)(entity->anchor8.i))<<8;
	anchor16.j = ((uint16_t)(entity->anchor8.j))<<8;

	entity->vel.i += ((int16_t)(anchor16.i - entity->pos.i))/512;
	entity->vel.j += ((int16_t)(anchor16.j - entity->pos.j))/512;
	
	if (wolfi->pos.i < entity->pos.i) {
		entity->vel.i -= 1;
	} else {
		entity->vel.i += 1;
	}

	if (wolfi->pos.j < entity->pos.j) {
		entity->vel.j -= 1;
	} else {
		entity->vel.j += 1;
	}
	
	
	entity->pos.i += ((int16_t)entity->vel.i)<<1;
	entity->pos.j += ((int16_t)entity->vel.j)<<1;

	// SPRITE ANGLE
	sprites[spawn_idx].pos.i = entity->pos.i;
	sprites[spawn_idx].pos.j = entity->pos.j;

	if ((spawn_idx&7) == 0) {
		sprites[spawn_idx].spriteInfo = (entity->vel.j>0?&ghosti_0_0 : &ghosti_0_1) ;
	} else if ((spawn_idx&7) == 1) {
		sprites[spawn_idx].spriteInfo = (entity->vel.j>0?&ghosti_1_0 : &ghosti_1_1) ;
	} else if ((spawn_idx&7) == 2) {
		sprites[spawn_idx].spriteInfo = (entity->vel.j>0?&ghosti_2_0 : &ghosti_2_1) ;
	} else if ((spawn_idx&7) == 3) {
		sprites[spawn_idx].spriteInfo = (entity->vel.j>0?&ghosti_3_0 : &ghosti_3_1) ;
	} else if ((spawn_idx&7) == 4) {
		sprites[spawn_idx].spriteInfo = (entity->vel.j>0?&ghosti_2_0 : &ghosti_2_1) ;
	} else if ((spawn_idx&7) == 5) {
		sprites[spawn_idx].spriteInfo = (entity->vel.j>0?&ghosti_2_0 : &ghosti_2_1) ;
	} else if ((spawn_idx&7) == 6) {
		sprites[spawn_idx].spriteInfo = (entity->vel.j>0?&ghosti_5_0 : &ghosti_5_1) ;		
	} else {
		sprites[spawn_idx].spriteInfo = (entity->vel.j>0?&ghosti_5_0 : &ghosti_5_1) ;
	}
	
	// COLLISION
	if (collision_wolfi(spawn_idx))
		hit_wolfi(spawn_idx);

	return true;
}

static const struct T_Entity_Callbacks callbacks = {
	on_spawn, on_despawn, on_update, on_hit_default
};

void init_ghosti(uint8_t spawn_idx, uint8_t i, uint8_t j) {

	Entity *entity = &state.entities[spawn_idx];

	entity->spawn_auto = true;
	entity->spawn_idx = -1;
	entity->spawn_priority = 6;

	entity->anchor8.i = i;
	entity->anchor8.j = j;

	entity->pos.i = (i + 2) << 8;
	entity->pos.j = (j + 2) << 8;

	entity->push_vector.i = 0;
	entity->push_vector.j = 0;

	entity->life = 16;
	entity->maximum_life = 16;
	entity->invulnerable_frames = 0;

	entity->damage = 1;

	entity->segment = MODULE_SEGMENT(entity_ghosti, PAGE_C);
	entity->callbacks = &callbacks;
}
