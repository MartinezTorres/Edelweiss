#include <gameplay/player_sprite.h>
#include "vx_bind_player_motion.h"
/* This synchronous occurrence is exclusive through result consumption. Map,
 * sprite and trigger callbacks may invoke the other bindings, whose workspace
 * is separate from this one. Keep results in that owned frame across calls. */
static Entity *player_motion_entity;
typedef char player_motion_obstacle_bit[MAP_OBSTACLE==1 ? 1 : -1];

VX_BIND_player_motion_BOUNDARY_motion_query {
#define query VX_BIND_player_motion_DATA_motion_query
    uint8_t flags;
    player_motion_entity->pos.i=query.a0;
    player_motion_entity->pos.j=query.a1;
    keyboard[8]=query.a2;
    player_motion_entity->skip_23_frame=query.a4;
    player_motion_entity->animation_counter=query.a5;
    flags=overworld_get_entity_flags(query.a7,query.a8);
    query.r0=player_motion_entity->pos.i;
    query.r1=player_motion_entity->pos.j;
    query.r2=keyboard[8];
    query.r3=state.isr_count_delta;
    query.r4=player_motion_entity->skip_23_frame;
    query.r5=player_motion_entity->animation_counter;
    query.r6=player_motion_entity->orientation;
    query.r7=flags;
#undef query
}
/* Keep native entity-address calculations out of the continuation across
 * run(). SDCC otherwise caches four field addresses in an eight-byte stack
 * frame even when the C function has no explicitly declared local values. */
#ifdef vx_bind_player_motion_frame
#define motion_frame vx_bind_player_motion_frame
#define MOTION_FRAME_ARGUMENT /* fixed occurrence */
#else
#define motion_frame (*vxf)
#define MOTION_FRAME_ARGUMENT &vx_bind_player_motion_frame
#endif
static void player_motion_publish(VX_BIND_player_motion_TRANSFER_PARAMETERS) {
    Entity *entity=player_motion_entity;
    motion_frame.a0_0=entity->pos.i;
    motion_frame.a0_1=entity->pos.j;
    motion_frame.a0_2=keyboard[8];
    motion_frame.a0_3=state.isr_count_delta;
    motion_frame.a0_4=entity->skip_23_frame;
    motion_frame.a0_5=entity->animation_counter;
    motion_frame.a0_6=entity->orientation;
}
static uint8_t player_motion_consume(VX_BIND_player_motion_TRANSFER_PARAMETERS) {
    Entity *entity=player_motion_entity;
    entity->pos.i=motion_frame.result.v0;
    entity->pos.j=motion_frame.result.v1;
    keyboard[8]=motion_frame.result.v2;
    entity->skip_23_frame=motion_frame.result.v4;
    entity->animation_counter=motion_frame.result.v5;
    entity->orientation=motion_frame.result.v6;
    if(!motion_frame.result.v9) {sprites[0].pos=entity->pos;return false;}
    if(motion_frame.result.v8!=255)player_sprite(0,motion_frame.result.v8);
    if(motion_frame.result.v7&MAP_TRIGGER)TRAMPOLINE_PAGE_C(wolfi_triggers);
    return true;
}

#if !EDW_PLAYER_REGION_BANKED
static
#endif
uint8_t player_motion_region(Entity *entity) {
    VX_BIND_player_motion_LOCAL;
    player_motion_entity=entity;
    player_motion_publish(MOTION_FRAME_ARGUMENT);
    vx_bind_player_motion_run();
    return player_motion_consume(MOTION_FRAME_ARGUMENT);
}
#undef motion_frame
#undef MOTION_FRAME_ARGUMENT

