#include <common.h>
#if EDW_VEXEL
#include "vx_bind_combat_tick.h"
#include "vx_bind_combat_death.h"
#endif

uint8_t combat_update_d(uint8_t spawn_idx) {
    Entity *entity=&state.entities[state.spawns[spawn_idx]];
    uint8_t status,steps;
#if EDW_VEXEL
    VX_BIND_combat_tick_LOCAL;
    vx_bind_combat_tick_frame.a0=entity->life;
    vx_bind_combat_tick_frame.a1=entity->invulnerable_frames;
    vx_bind_combat_tick_frame.a2=entity->push_frames;
    vx_bind_combat_tick_frame.a3=state.isr_count_delta;
    vx_bind_combat_tick_run();
    status=vx_bind_combat_tick_frame.result.v0;
    entity->invulnerable_frames=vx_bind_combat_tick_frame.result.v1;
    entity->push_frames=vx_bind_combat_tick_frame.result.v2;
    steps=vx_bind_combat_tick_frame.result.v3;
    if(vx_bind_combat_tick_frame.result.v4<2)sprites[spawn_idx].enabled=vx_bind_combat_tick_frame.result.v4;
#else
    uint8_t remaining=entity->push_frames>6?6:entity->push_frames;
    uint8_t spent=state.isr_count_delta<remaining?state.isr_count_delta:remaining;
    status=!entity->life?COMBAT_DEAD:(remaining?COMBAT_STUNNED:COMBAT_READY);
    if(entity->invulnerable_frames) {
        entity->invulnerable_frames=entity->invulnerable_frames>state.isr_count_delta?
            entity->invulnerable_frames-state.isr_count_delta:0;
        sprites[spawn_idx].enabled=!(entity->invulnerable_frames&4);
    }
    entity->push_frames=remaining-spent;
    steps=spent*3;
#endif
    if(status==COMBAT_DEAD) {
        uint8_t explosion,drop,id;
#if EDW_VEXEL
        VX_BIND_combat_death_LOCAL;
        vx_bind_combat_death_frame.a0=state.entities[ENTITY_EXPLOSION_0].spawn_idx<0;
        vx_bind_combat_death_frame.a1=state.entities[ENTITY_EXPLOSION_1].spawn_idx<0;
        vx_bind_combat_death_frame.a2=state.entities[ENTITY_DROP_ITEM_0].spawn_idx<0;
        vx_bind_combat_death_frame.a3=state.entities[ENTITY_DROP_ITEM_1].spawn_idx<0;
        vx_bind_combat_death_run();
        explosion=vx_bind_combat_death_frame.result.v0;drop=vx_bind_combat_death_frame.result.v1;
#else
        explosion=state.entities[ENTITY_EXPLOSION_0].spawn_idx<0?1:
            (state.entities[ENTITY_EXPLOSION_1].spawn_idx<0?2:0);
        drop=state.entities[ENTITY_DROP_ITEM_0].spawn_idx<0?1:
            (state.entities[ENTITY_DROP_ITEM_1].spawn_idx<0?2:0);
#endif
        /* Copy choices before spawn callbacks can enter other gameplay. */
        if(explosion) {
            id=explosion==1?ENTITY_EXPLOSION_0:ENTITY_EXPLOSION_1;
            state.entities[id].pos=entity->pos;
            spawn_entity(id);
        }
        if(drop) {
            id=drop==1?ENTITY_DROP_ITEM_0:ENTITY_DROP_ITEM_1;
            state.entities[id].pos=entity->pos;
            state.entities[id].drop_probability=E_DROP_PROBABILITY_HIGH;
            spawn_entity(id);
        }
        entity->life=entity->maximum_life;
        entity->pos.i=(uint16_t)entity->anchor8.i<<8;
        entity->pos.j=(uint16_t)entity->anchor8.j<<8;
        entity->push_frames=entity->invulnerable_frames=0;
        entity->push_vector.i=entity->push_vector.j=0;
        sprites[spawn_idx].enabled=false;
        return COMBAT_DEAD;
    }

    /* The map query restores both bank windows before returning. The
     * renderer sees the new position even on an otherwise skipped AI tick. */
    if(entity->push_vector.i || entity->push_vector.j) {
        while(steps--) {
            uint16_t i=entity->pos.i+entity->push_vector.i;
            uint16_t j=entity->pos.j+entity->push_vector.j;
            if((entity->push_vector.i<0 && i>entity->pos.i) ||
               (entity->push_vector.j<0 && j>entity->pos.j) ||
               (entity->push_vector.i>0 && i<entity->pos.i) ||
               (entity->push_vector.j>0 && j<entity->pos.j) ||
               /* The 64x128 tile map samples feet at row+14 pixels and
                * columns through col+11 pixels. Keep those reads in range. */
               i>=32768u-14u*32u || j>=65535u-11u*32u+1u ||
               (overworld_get_entity_flags(i,j)&MAP_OBSTACLE)) {
                entity->push_vector.i=entity->push_vector.j=0;
                break;
            }
            entity->pos.i=i;entity->pos.j=j;
        }
    }
    sprites[spawn_idx].pos=entity->pos;
    return status;
}
