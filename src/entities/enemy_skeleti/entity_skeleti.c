#include <common.h>
#include "entity_skeleti_sprite.h"

USING_MODULE(entity_skeleti_sprite, PAGE_D);

#ifdef EDW_ENCOUNTER
#include "../../../tests/encounter.h"
#define skeleti_random encounter_random
#else
#define skeleti_random rand7
#endif
#if EDW_VEXEL
#include "vx_bind_skeleti_tick.h"
#include "vx_bind_skeleti_draws.h"
#include "vx_bind_skeleti_move.h"
#include "vx_bind_skeleti_wait.h"
#include "vx_value_skeleti_update_cases.h"
#include "vx_sprite_assets.h"
#endif

static void on_spawn(Entity *entity) {
	
	uint8_t spawn_idx = entity->spawn_idx;

    sprites[spawn_idx].enabled = true;
    sprites[spawn_idx].patternBlackRequired = true;
    sprites[spawn_idx].patternColorRequired = true;
#if EDW_VEXEL
    sprites[spawn_idx].spriteInfo=nullptr;
    sprites[spawn_idx].resourceRequest=edw_skeleti_sprite(2);
#else
    sprites[spawn_idx].spriteInfoSegment = MODULE_SEGMENT(entity_skeleti_sprite, PAGE_D);
    sprites[spawn_idx].spriteInfo = &skeleti_1_0;
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
    sprites[spawn_idx].resourceRequest=0;
    sprites[spawn_idx].spriteInfo=nullptr;
#endif
}

static uint8_t on_update(Entity *entity) {

	uint8_t spawn_idx = entity->spawn_idx;

	Entity *wolfi = &state.entities[0];

	uint8_t reaction=combat_update(spawn_idx);
	if (reaction!=COMBAT_READY) return reaction!=COMBAT_DEAD;
	
#if EDW_VEXEL
    VX_BIND_skeleti_tick_LOCAL;
    vx_bind_skeleti_tick_frame.a0=state.game_cycles;
    vx_bind_skeleti_tick_frame.a1=spawn_idx;
    vx_bind_skeleti_tick_run();
    if(!vx_bind_skeleti_tick_frame.result.v0)return true;
#else
	if (((state.game_cycles+spawn_idx)&3) != 0) return true;
#endif

	// MOVEMENT
	{
#if !EDW_VEXEL
		uint16_tp anchor16;
		anchor16.i = ((uint16_t)(entity->anchor8.i))<<8;
		anchor16.j = ((uint16_t)(entity->anchor8.j))<<8;
#endif
		uint16_tp old_pos;
		old_pos = entity->pos;
		
#if EDW_VEXEL
        uint8_t reset=skeleti_random(),choice=0,wait=0;
        VX_BIND_skeleti_draws_LOCAL;
        vx_bind_skeleti_draws_frame.a0=entity->skeleti_action;
        vx_bind_skeleti_draws_frame.a1=entity->skeleti_delay;
        vx_bind_skeleti_draws_frame.a2=reset;
        vx_bind_skeleti_draws_run();
        if(vx_bind_skeleti_draws_frame.result.v0) { choice=skeleti_random();wait=skeleti_random(); }
        /* All random effects precede frame acquisition and case selection. */
        if(vx_skeleti_update_branch(entity->skeleti_delay)) {
            VX_BIND_skeleti_wait_LOCAL;
            vx_bind_skeleti_wait_frame.a0=entity->skeleti_action;
            vx_bind_skeleti_wait_frame.a1=entity->skeleti_delay;
            vx_bind_skeleti_wait_frame.a2=reset;
            vx_bind_skeleti_wait_frame.a5=old_pos.i;
            vx_bind_skeleti_wait_frame.a6=old_pos.j;
            vx_bind_skeleti_wait_run();
            entity->skeleti_action=vx_bind_skeleti_wait_frame.result.v0;entity->skeleti_delay=vx_bind_skeleti_wait_frame.result.v1;
            entity->pos.i=vx_bind_skeleti_wait_frame.result.v2;entity->pos.j=vx_bind_skeleti_wait_frame.result.v3;
            if(vx_bind_skeleti_wait_frame.result.v4!=255) sprites[spawn_idx].resourceRequest=edw_skeleti_sprite(vx_bind_skeleti_wait_frame.result.v4);
        } else {
            VX_BIND_skeleti_move_LOCAL;
            vx_bind_skeleti_move_frame.a0=entity->skeleti_action;
            vx_bind_skeleti_move_frame.a2=reset;
            vx_bind_skeleti_move_frame.a3=choice;
            vx_bind_skeleti_move_frame.a4=wait;
            vx_bind_skeleti_move_frame.a5=old_pos.i;
            vx_bind_skeleti_move_frame.a6=old_pos.j;
            vx_bind_skeleti_move_frame.a7=(uint16_t)entity->anchor8.i<<8;
            vx_bind_skeleti_move_frame.a8=(uint16_t)entity->anchor8.j<<8;
            vx_bind_skeleti_move_frame.a9=wolfi->pos.i;
            vx_bind_skeleti_move_frame.a10=wolfi->pos.j;
            vx_bind_skeleti_move_frame.a11=state.isr_count;
            vx_bind_skeleti_move_run();
            entity->skeleti_action=vx_bind_skeleti_move_frame.result.v0;entity->skeleti_delay=vx_bind_skeleti_move_frame.result.v1;
            entity->pos.i=vx_bind_skeleti_move_frame.result.v2;entity->pos.j=vx_bind_skeleti_move_frame.result.v3;
            if(vx_bind_skeleti_move_frame.result.v4!=255) sprites[spawn_idx].resourceRequest=edw_skeleti_sprite(vx_bind_skeleti_move_frame.result.v4);
        }
#else
		if ((skeleti_random() & 63)==0) {
			entity->skeleti_action = 0;
		}

		if (entity->skeleti_delay) {
			entity->skeleti_delay--;
		} else switch (entity->skeleti_action) {
		case 0: // Select Routine Randomly
			entity->skeleti_action = (skeleti_random() & 7);
			entity->skeleti_delay = (skeleti_random()>>4);
			break;
		case 1: // Close distance vertically
			if (wolfi->pos.i > entity->pos.i) {
				entity->pos.i += 64;
				sprites[spawn_idx].spriteInfo = (state.isr_count & 0x08? &skeleti_2_0 : &skeleti_2_1);
			} else {
				entity->skeleti_action = 0;
			}
			break;
		case 2: // Close distance vertically
			if (wolfi->pos.i < entity->pos.i) {
				entity->pos.i -= 64;
				sprites[spawn_idx].spriteInfo = (state.isr_count & 0x08? &skeleti_1_0 : &skeleti_1_1);
			} else {
				entity->skeleti_action = 0;
			}
			break;
		case 3: // Close distance horizontally
			if (wolfi->pos.j > entity->pos.j) {
				entity->pos.j += 64;
				sprites[spawn_idx].spriteInfo = (state.isr_count & 0x08? &skeleti_3_0 : &skeleti_3_1);
			} else {
				entity->skeleti_action = 0;
			}
			break;
		case 4: // Close distance horizontally
			if (wolfi->pos.j < entity->pos.j) {
				entity->pos.j -= 64;
				sprites[spawn_idx].spriteInfo = (state.isr_count & 0x08? &skeleti_4_0 : &skeleti_4_1);
			} else {
				entity->skeleti_action = 0;
			}
			break;
		case 5: // Return home vertically
			if (anchor16.i > (uint16_t)(entity->pos.i + 0x200u)) {
				entity->pos.i += 64;
				sprites[spawn_idx].spriteInfo = (state.isr_count & 0x08? &skeleti_2_0 : &skeleti_2_1);
			} else if (anchor16.i < (uint16_t)(entity->pos.i - 0x200u)) {
				entity->pos.i -= 64;
				sprites[spawn_idx].spriteInfo = (state.isr_count & 0x08? &skeleti_1_0 : &skeleti_1_1);
			} else {
				entity->skeleti_action = 0;
			}
			break;
		case 6: // Return home horizontally
			if (anchor16.j > (uint16_t)(entity->pos.j + 0x200u)) {
				entity->pos.j += 64;
				sprites[spawn_idx].spriteInfo = (state.isr_count & 0x08? &skeleti_3_0 : &skeleti_3_1);
			} else if (anchor16.j < (uint16_t)(entity->pos.j - 0x200u)) {
				entity->pos.j -= 64;
				sprites[spawn_idx].spriteInfo = (state.isr_count & 0x08? &skeleti_4_0 : &skeleti_4_1);
			} else {
				entity->skeleti_action = 0;
			}
			break;
		default:
			sprites[spawn_idx].spriteInfo = (state.isr_count & 0x08? &skeleti_0_0 : &skeleti_0_1);
			entity->skeleti_action = 0;
			break;
		}
#endif
	
		uint8_t flags = overworld_get_entity_flags(entity->pos.i, entity->pos.j);

		if ( (flags & MAP_OBSTACLE) != 0) entity->pos = old_pos;

	
	}

	sprites[spawn_idx].pos.i = entity->pos.i;
	sprites[spawn_idx].pos.j = entity->pos.j;

	if (collision_wolfi(spawn_idx))
		hit_wolfi(spawn_idx);

	return true;
}

static const struct T_Entity_Callbacks callbacks = {
	on_spawn, on_despawn, on_update, on_hit_default
};

void init_skeleti(uint8_t spawn_idx, uint8_t i, uint8_t j) {

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

	entity->life = 8;
	entity->maximum_life = 8;
	entity->invulnerable_frames = 0;
	entity->push_frames = 0;

	entity->damage = 2;

	entity->segment = MODULE_SEGMENT(entity_skeleti, PAGE_C);
	entity->callbacks = &callbacks;

}

#ifdef EDW_ENCOUNTER
void encounter_skeleti(void) {
    uint8_t k;
    for(k=0;k<4;++k) {
        uint8_t id=ENTITY_SKELETI_0+k;
        init_skeleti(id,98+3*k,8+6*k);
        state.entities[id].spawn_auto=false;state.entities[id].skeleti_action=1+k;
        spawn_entity(id);
    }
}
#endif
