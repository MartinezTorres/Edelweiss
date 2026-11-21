#include <common.h>
#if EDW_VEXEL
#include "vx_value_combat_tick_cases.h"
#include "vx_bind_combat_idle.h"
#endif

uint8_t combat_update(uint8_t spawn_idx) {
    Entity *entity=&state.entities[state.spawns[spawn_idx]];
#if EDW_VEXEL
    /* Generated constant case: no reaction bank or movement state needed.
     * Publication and callbacks are serialized by the existing engine. */
    if(vx_combat_tick_branch(entity->life,entity->invulnerable_frames,entity->push_frames)) {
        /* No call/effect can reenter while this result is live. It is dead
         * before combat_update_d can spawn an entity or call the engine. */
        VX_BIND_combat_idle_LOCAL;
        vx_bind_combat_idle_run();
        /* Keep this valid if the Vexel case changes: only an unchanged,
         * effect-free result can bypass the ordinary adapter. */
        if(vx_bind_combat_idle_frame.result.v0==COMBAT_READY && vx_bind_combat_idle_frame.result.v1==entity->invulnerable_frames &&
           vx_bind_combat_idle_frame.result.v2==entity->push_frames && !vx_bind_combat_idle_frame.result.v3 && vx_bind_combat_idle_frame.result.v4==2)
            return COMBAT_READY;
    }
#else
    if(entity->life && !entity->invulnerable_frames && !entity->push_frames)
        return COMBAT_READY;
#endif
    uint8_t old=mapper_load_module(combat,PAGE_D);
    uint8_t status=combat_update_d(spawn_idx);
    mapper_load_segment(old,PAGE_D);
    return status;
}

void on_hit_default(Entity *entity, Entity *aggressor) {

	uint8_t oldSegmentPageD = mapper_load_module(collisions_d, PAGE_D);
    on_hit_default_d(entity, aggressor);
    mapper_load_segment(oldSegmentPageD, PAGE_D);
}

void on_hit_null(Entity *entity, Entity *weapon) {
	
	UNUSED(entity);
	UNUSED(weapon);
}
