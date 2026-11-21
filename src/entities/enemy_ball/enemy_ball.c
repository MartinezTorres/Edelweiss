#include <common.h>
#include "enemy_ball_sprite.h"

USING_MODULE(enemy_ball_sprite, PAGE_D);

#if EDW_VEXEL
#include "vx_bind_ball_tick.h"
#include "vx_bind_ball_leg.h"
#include "vx_bind_ball_reply.h"
#include "vx_bind_ball_home.h"
#include "vx_sprite_assets.h"
#endif

static void on_spawn(Entity *entity) {
	
	uint8_t spawn_idx = entity->spawn_idx;

    sprites[spawn_idx].enabled = true;
    sprites[spawn_idx].patternBlackRequired = true;
    sprites[spawn_idx].patternColorRequired = true;
#if EDW_VEXEL
    VX_BIND_ball_tick_LOCAL;
    vx_bind_ball_tick_frame.a0=0;vx_bind_ball_tick_frame.a1=0;
    vx_bind_ball_tick_frame.a2=1;vx_bind_ball_tick_frame.a3=entity->orientation;vx_bind_ball_tick_run();
    sprites[spawn_idx].spriteInfo=nullptr;
    sprites[spawn_idx].resourceRequest=edw_ball_sprite(vx_bind_ball_tick_frame.result.v3);
#else
    sprites[spawn_idx].spriteInfoSegment = MODULE_SEGMENT(enemy_ball_sprite, PAGE_D);
    
    if (entity->orientation == E_LEFT) {
		sprites[spawn_idx].spriteInfo = &enemy_ball_2_0;
	} else {
		sprites[spawn_idx].spriteInfo = &enemy_ball_3_0;
	}
#endif

	sprites[spawn_idx].pos.i = entity->pos.i;
	sprites[spawn_idx].pos.j = entity->pos.j;

	entity->invulnerable_frames = 0;
	entity->push_frames = 0;
	
}

static void on_despawn(Entity *entity) {

	uint8_t spawn_idx = entity->spawn_idx;

    sprites[spawn_idx].enabled = false;
#if EDW_VEXEL
    sprites[spawn_idx].resourceRequest=0;sprites[spawn_idx].spriteInfo=nullptr;
#endif
}

static uint8_t on_update(Entity *entity) {

	uint8_t spawn_idx = entity->spawn_idx;



	uint8_t reaction=combat_update(spawn_idx);
	if (reaction!=COMBAT_READY) return reaction!=COMBAT_DEAD;
	
#if EDW_VEXEL
    VX_BIND_ball_tick_LOCAL;
    vx_bind_ball_tick_frame.a0=state.game_cycles;vx_bind_ball_tick_frame.a1=spawn_idx;
    vx_bind_ball_tick_frame.a2=entity->animation_counter;vx_bind_ball_tick_frame.a3=entity->orientation;
    vx_bind_ball_tick_run();
    if(!vx_bind_ball_tick_frame.result.v0)return true;
    entity->animation_counter=vx_bind_ball_tick_frame.result.v2;
    if(vx_bind_ball_tick_frame.result.v3!=255)sprites[spawn_idx].resourceRequest=edw_ball_sprite(vx_bind_ball_tick_frame.result.v3);
    if(vx_bind_ball_tick_frame.result.v1) {
        uint16_tp old;
        uint16_t ai=(uint16_t)entity->anchor8.i<<8,aj=(uint16_t)entity->anchor8.j<<8;
        uint8_t leg;
        old=entity->pos;
        for(leg=1;leg<=2;++leg) {
            VX_BIND_ball_leg_LOCAL;
            VX_BIND_ball_reply_LOCAL;
            uint8_t flags;
            vx_bind_ball_leg_frame.a0=leg;vx_bind_ball_leg_frame.a1=entity->orientation;
            vx_bind_ball_leg_frame.a2=entity->pos.j;vx_bind_ball_leg_frame.a3=aj;
            vx_bind_ball_leg_frame.a4=entity->animation_counter;vx_bind_ball_leg_run();
            if(!vx_bind_ball_leg_frame.result.v0)continue;
            entity->pos.j=vx_bind_ball_leg_frame.result.v1;
            entity->orientation=vx_bind_ball_leg_frame.result.v2;
            entity->animation_counter=vx_bind_ball_leg_frame.result.v3;
            flags=overworld_get_entity_flags(entity->pos.i,entity->pos.j);
            vx_bind_ball_reply_frame.a0=leg;vx_bind_ball_reply_frame.a1=flags&MAP_OBSTACLE;
            vx_bind_ball_reply_frame.a2=entity->pos.i;vx_bind_ball_reply_frame.a3=entity->pos.j;
            vx_bind_ball_reply_frame.a4=old.i;vx_bind_ball_reply_frame.a5=old.j;
            vx_bind_ball_reply_frame.a6=entity->orientation;vx_bind_ball_reply_frame.a7=entity->animation_counter;
            vx_bind_ball_reply_run();
            entity->pos.i=vx_bind_ball_reply_frame.result.v0;entity->pos.j=vx_bind_ball_reply_frame.result.v1;
            entity->orientation=vx_bind_ball_reply_frame.result.v2;entity->animation_counter=vx_bind_ball_reply_frame.result.v3;
        }
        {
            VX_BIND_ball_home_LOCAL;
            vx_bind_ball_home_frame.a0=entity->pos.i;vx_bind_ball_home_frame.a1=ai;vx_bind_ball_home_run();
            entity->pos.i=vx_bind_ball_home_frame.result.v0;
        }
    }
#else
	if (((state.game_cycles+spawn_idx)&1) != 0) return true;

	// MOVEMENT
	if (entity->animation_counter > 1) {
	
		entity->animation_counter--;
	
	} else if (entity->animation_counter == 1) {

		if (entity->orientation == E_LEFT) {
			sprites[spawn_idx].spriteInfo = &enemy_ball_2_0;
		} else {
			sprites[spawn_idx].spriteInfo = &enemy_ball_3_0;
		}
		entity->animation_counter--;
		
	} else {
		
		
		
		uint16_tp anchor16;
		anchor16.i = ((uint16_t)(entity->anchor8.i))<<8;
		anchor16.j = ((uint16_t)(entity->anchor8.j))<<8;
		
		uint16_tp old_pos;
		old_pos = entity->pos;
		
		if (entity->orientation == E_LEFT) {
			
			entity->pos.j -= 64;

			if ((int16_t)(anchor16.j - entity->pos.j) > 0x800) {
				entity->orientation = E_RIGHT;				
				
				entity->animation_counter = 30;  
			}

			uint8_t flags = overworld_get_entity_flags(entity->pos.i, entity->pos.j);

			if ( (flags & MAP_OBSTACLE) != 0) {
				entity->pos = old_pos;
				entity->orientation = E_RIGHT;

				entity->animation_counter = 30;  
			}
			
		}

		if (entity->orientation == E_RIGHT) {
			
			entity->pos.j += 64;

			if ((int16_t)(entity->pos.j - anchor16.j) > 0x800) {
				entity->orientation = E_LEFT;				

				entity->animation_counter = 30;  
			}

			uint8_t flags = overworld_get_entity_flags(entity->pos.i, entity->pos.j);

			if ( (flags & MAP_OBSTACLE) != 0) {
				entity->pos = old_pos;
				entity->orientation = E_LEFT;

				entity->animation_counter = 30;  
			}
		}

		if (entity->pos.i > (uint16_t)(anchor16.i + 16)) {
			entity->pos.i -= 16;
		}

		if (entity->pos.i < (uint16_t)(anchor16.i - 16)) {
			entity->pos.i += 16;
		}



	}

#endif

	sprites[spawn_idx].pos.i = entity->pos.i;
	sprites[spawn_idx].pos.j = entity->pos.j;

	if (collision_wolfi(spawn_idx))
		hit_wolfi(spawn_idx);

	return true;
}

static const struct T_Entity_Callbacks callbacks = {
	on_spawn, on_despawn, on_update, on_hit_default
};

void init_enemy_ball(uint8_t spawn_idx, uint8_t i, uint8_t j) {

	Entity *entity = &state.entities[spawn_idx];

	entity->spawn_auto = true;
	entity->spawn_idx = -1;
	entity->spawn_priority = 4;

	entity->anchor8.i = i;
	entity->anchor8.j = j;

	entity->pos.i = ((uint16_t)i)<<8;
	entity->pos.j = ((uint16_t)j)<<8;

	entity->vel.i = 0;
	entity->vel.j = 0;

	entity->push_vector.i = 0;
	entity->push_vector.j = 0;

	entity->life = 2;
	entity->maximum_life = 2;
	entity->invulnerable_frames = 0;
	entity->push_frames = 0;

	entity->damage = 1;

	entity->animation_counter = 0;  
	entity->orientation = E_LEFT;  

	entity->segment = MODULE_SEGMENT(enemy_ball, PAGE_C);
	entity->callbacks = &callbacks;

}

#ifdef EDW_ENCOUNTER
#include "../../../tests/ball_encounter.h"
#endif
