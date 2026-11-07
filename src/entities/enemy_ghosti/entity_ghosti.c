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
/* Keep the hot rules here and fold their known arithmetic widths/counts. */
#include "vexel.h"
#include "vx_ghost_math.h"
#include "vx_ghost.inc"
#undef vx_shift
#undef vx_signed
#endif

static void on_spawn(Entity *entity) {
	
	uint8_t spawn_idx = entity->spawn_idx;
    sprites[spawn_idx].enabled = true;
    sprites[spawn_idx].patternBlackRequired = true;
    sprites[spawn_idx].patternColorRequired = true;
    sprites[spawn_idx].spriteInfoSegment = MODULE_SEGMENT(entity_ghosti_sprite, PAGE_D);	

#if EDW_VEXEL
    uint8_t random=0, k;
    uint16_t i,j;
    int8_t vi,vj;
    /* Keep all six legacy draws, including the two redundant position draws. */
    for(k=0;k<6;++k)random|=(uint8_t)(ghost_random()&1)<<k;
    vx_ghost_spawn((uint16_t)entity->anchor8.i<<8,(uint16_t)entity->anchor8.j<<8,random);
    i=(uint16_t)vx_ghost_spawn_read(0);j=(uint16_t)vx_ghost_spawn_read(1);
    vi=(int8_t)vx_ghost_spawn_read(2);vj=(int8_t)vx_ghost_spawn_read(3);
    entity->pos.i=i;entity->pos.j=j;entity->vel.i=vi;entity->vel.j=vj;
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
	
#if EDW_VEXEL
    uint8_t run, life, frame;
    uint16_t i,j;
    int8_t vi,vj;
    vx_ghost_tick(state.game_cycles,spawn_idx,entity->life,entity->maximum_life);
    run=(uint8_t)vx_ghost_tick_read(0);life=(uint8_t)vx_ghost_tick_read(1);
    if(!run)return true;
    vx_ghost_axis(entity->pos.i,(uint16_t)entity->anchor8.i<<8,entity->vel.i,wolfi->pos.i);
    i=(uint16_t)vx_ghost_axis_read(0);vi=(int8_t)vx_ghost_axis_read(1);
    vx_ghost_axis(entity->pos.j,(uint16_t)entity->anchor8.j<<8,entity->vel.j,wolfi->pos.j);
    j=(uint16_t)vx_ghost_axis_read(0);vj=(int8_t)vx_ghost_axis_read(1);
    vx_ghost_frame(spawn_idx,vj);frame=(uint8_t)vx_ghost_frame_read(0);
    entity->life=life;entity->pos.i=i;entity->pos.j=j;entity->vel.i=vi;entity->vel.j=vj;
    sprites[spawn_idx].pos=entity->pos;
    {
        static const TSpriteInterlaced * const frames[]={
            &ghosti_0_0,&ghosti_0_1,&ghosti_1_0,&ghosti_1_1,
            &ghosti_2_0,&ghosti_2_1,&ghosti_3_0,&ghosti_3_1,
            &ghosti_4_0,&ghosti_4_1,&ghosti_5_0,&ghosti_5_1
        };
        sprites[spawn_idx].spriteInfo=frames[frame];
    }
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
