#include <common.h>
#include "entity_ghosti_sprite.h"

USING_MODULE(entity_ghosti_sprite, PAGE_D);
#ifdef EDW_SMOKE
#include "../../../tests/quest_smoke_input.h"
#define ghost_random quest_smoke_ghost_random
#else
#define ghost_random rand16
#endif
#if EDW_VEXEL
/* Embed the solver's pure value graph in the callback's existing bank. */
#include "vx_value_ghost_update_cases.h"
#include "vx_bind_ghost_spawn.h"
#include "vx_bind_ghost_move.h"
#include "vx_sprite_assets.h"
#endif

static void on_spawn(Entity *entity) {
	
	uint8_t spawn_idx = entity->spawn_idx;
    sprites[spawn_idx].enabled = true;
    sprites[spawn_idx].patternBlackRequired = true;
    sprites[spawn_idx].patternColorRequired = true;
#if EDW_VEXEL
    sprites[spawn_idx].resourceRequest=0;
    sprites[spawn_idx].spriteInfo=nullptr;
#else
    sprites[spawn_idx].spriteInfoSegment = MODULE_SEGMENT(entity_ghosti_sprite, PAGE_D);
#endif

#if EDW_VEXEL
    uint8_t random=0, k;
    VX_BIND_ghost_spawn_LOCAL;
    /* Keep all six legacy draws, including the two redundant position draws. */
    for(k=0;k<6;++k)random|=(uint8_t)(ghost_random()&1)<<k;
    vx_bind_ghost_spawn_frame.a0=(uint16_t)entity->anchor8.i<<8;
    vx_bind_ghost_spawn_frame.a1=(uint16_t)entity->anchor8.j<<8;
    vx_bind_ghost_spawn_frame.a2=random;
    vx_bind_ghost_spawn_run();
    entity->pos.i=vx_bind_ghost_spawn_frame.result.v0;entity->pos.j=vx_bind_ghost_spawn_frame.result.v1;
    entity->vel.i=vx_bind_ghost_spawn_frame.result.v2;entity->vel.j=vx_bind_ghost_spawn_frame.result.v3;
#else
	entity->vel.i = (ghost_random()&1)?-1:1;
	entity->vel.j = (ghost_random()&1)?-2:2;
	if (ghost_random()&1) entity->vel.i *= 2;
	if (ghost_random()&1) entity->vel.j *= 2;

	uint16_tp anchor16;
	anchor16.i = ((uint16_t)(entity->anchor8.i))<<8;
	anchor16.j = ((uint16_t)(entity->anchor8.j))<<8;

    /* SDCC removes a condition with identical arms, including the draw.
     * Keep the six source-level draws explicit on both targets. */
    (void)ghost_random();
    entity->pos.i = anchor16.i - 0x100;
    (void)ghost_random();
    entity->pos.j = anchor16.j - 0x200;

#endif
	sprites[spawn_idx].pos.i = entity->pos.i;
	sprites[spawn_idx].pos.j = entity->pos.j;

	entity->invulnerable_frames = 0;
	entity->push_frames = 0;

//    debug_printf("spawn ghosti %d %d\n", spawn_idx, state.spawns[spawn_idx]);

}

static void on_despawn(Entity *entity) {
	
	uint8_t spawn_idx = entity->spawn_idx;
    sprites[spawn_idx].enabled = false;
#if EDW_VEXEL
    sprites[spawn_idx].resourceRequest=0;
    sprites[spawn_idx].spriteInfo=nullptr;
#endif
    
//    debug_printf("despawn ghosti %d %d\n", spawn_idx, state.spawns[spawn_idx]);
    
}

static uint8_t on_update(Entity *entity) {

	
	Entity *wolfi = &state.entities[0];
	uint8_t spawn_idx = entity->spawn_idx;
	
	uint8_t reaction=combat_update(spawn_idx);
	if (reaction!=COMBAT_READY) return reaction!=COMBAT_DEAD;
	
#if EDW_VEXEL
    VX_BIND_ghost_move_LOCAL;
    /* The generated dependency split needs only cycle/slot on a skipped tick.
     * No effects or changes to the input state intervene before the body. */
    if(!vx_ghost_update_branch(state.game_cycles,spawn_idx))return true;
    vx_bind_ghost_move_frame.a1=spawn_idx;
    vx_bind_ghost_move_frame.a2=entity->maximum_life;
    vx_bind_ghost_move_frame.a3=entity->pos.i;
    vx_bind_ghost_move_frame.a4=entity->pos.j;
    vx_bind_ghost_move_frame.a5=(uint16_t)entity->anchor8.i<<8;
    vx_bind_ghost_move_frame.a6=(uint16_t)entity->anchor8.j<<8;
    vx_bind_ghost_move_frame.a7=entity->vel.i;
    vx_bind_ghost_move_frame.a8=entity->vel.j;
    vx_bind_ghost_move_frame.a9=wolfi->pos.i;
    vx_bind_ghost_move_frame.a10=wolfi->pos.j;
    vx_bind_ghost_move_run();
    entity->life=vx_bind_ghost_move_frame.result.v1;entity->pos.i=vx_bind_ghost_move_frame.result.v2;entity->pos.j=vx_bind_ghost_move_frame.result.v3;
    entity->vel.i=vx_bind_ghost_move_frame.result.v4;entity->vel.j=vx_bind_ghost_move_frame.result.v5;
    sprites[spawn_idx].pos=entity->pos;
    sprites[spawn_idx].resourceRequest=edw_ghost_sprite(vx_bind_ghost_move_frame.result.v6);
#else
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
	
	
	entity->pos.i += ((int16_t)entity->vel.i)*2;
	entity->pos.j += ((int16_t)entity->vel.j)*2;

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
	
#endif
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
	entity->push_frames = 0;

	entity->damage = 1;

	entity->segment = MODULE_SEGMENT(entity_ghosti, PAGE_C);
	entity->callbacks = &callbacks;
}

#ifdef EDW_SMOKE
/* The scenario reaches callbacks through the resident page-C trampoline. */
void ghost_smoke_update(void) {
    Entity *e=&state.entities[ENTITY_GHOSTI_0];
    if(!on_update(e))despawn_entity(ENTITY_GHOSTI_0);
}
#endif

#ifdef EDW_ENCOUNTER
void encounter_ghosts(void) {
    uint8_t k;
    for(k=0;k<4;++k) {
        uint8_t id=ENTITY_GHOSTI_0+k;
        init_ghosti(id,100+3*k,22+2*k);
        state.entities[id].spawn_auto=false;spawn_entity(id);
    }
}
#endif
