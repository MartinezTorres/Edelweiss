/* Shared adapter for the two moving projectiles. Rules and storage are Vexel's. */
#include "vx_bind_projectile_spawn.h"
#include "vx_bind_projectile_move.h"
#include "vx_sprite_assets.h"

static void on_spawn(Entity *entity) {
    uint8_t slot=entity->spawn_idx;
    Entity *player=&state.entities[0];
    TSpriteStatus *sprite=&sprites[slot];
    VX_BIND_projectile_spawn_LOCAL;
    sprite->enabled=true;sprite->patternBlackRequired=true;sprite->patternColorRequired=true;
    sprite->overrideColors=false;sprite->spriteInfo=nullptr;sprite->resourceRequest=0;
#if EDW_PROJECTILE_FIRE
    /* Preserve the original fire spawn position until its first update. */
    sprite->pos=entity->pos;
    entity->animation_counter=0;
#endif
    vx_bind_projectile_spawn_frame.a0=EDW_PROJECTILE_FIRE;
    vx_bind_projectile_spawn_frame.a1=player->orientation;
    vx_bind_projectile_spawn_frame.a2=player->pos.i;vx_bind_projectile_spawn_frame.a3=player->pos.j;
    vx_bind_projectile_spawn_run();
    entity->pos.i=vx_bind_projectile_spawn_frame.result.v0;entity->pos.j=vx_bind_projectile_spawn_frame.result.v1;
    entity->vel.i=vx_bind_projectile_spawn_frame.result.v2;entity->vel.j=vx_bind_projectile_spawn_frame.result.v3;
#if !EDW_PROJECTILE_FIRE
    sprite->pos=entity->pos;
    sprite->resourceRequest=edw_arrow_sprite(vx_bind_projectile_spawn_frame.result.v4);
#endif
}
static void on_despawn(Entity *entity) {
    entity->spawn_auto=false;
    sprites[entity->spawn_idx].enabled=false;
    sprites[entity->spawn_idx].spriteInfo=nullptr;sprites[entity->spawn_idx].resourceRequest=0;
}
static uint8_t on_update(Entity *entity) {
    uint8_t slot=entity->spawn_idx;
    VX_BIND_projectile_move_LOCAL;
    vx_bind_projectile_move_frame.a0=EDW_PROJECTILE_FIRE;
    vx_bind_projectile_move_frame.a1=entity->pos.i;vx_bind_projectile_move_frame.a2=entity->pos.j;
    vx_bind_projectile_move_frame.a3=entity->vel.i;vx_bind_projectile_move_frame.a4=entity->vel.j;
    vx_bind_projectile_move_frame.a5=entity->animation_counter;vx_bind_projectile_move_frame.a6=state.isr_count_delta;
    vx_bind_projectile_move_run();
    entity->pos.i=vx_bind_projectile_move_frame.result.v0;entity->pos.j=vx_bind_projectile_move_frame.result.v1;
#if EDW_PROJECTILE_FIRE
    entity->animation_counter=vx_bind_projectile_move_frame.result.v2;
    if(vx_bind_projectile_move_frame.result.v3!=255)
        sprites[slot].resourceRequest=edw_fire_sprite(vx_bind_projectile_move_frame.result.v3);
#endif
    sprites[slot].pos=entity->pos;
    return true;
}
static const struct T_Entity_Callbacks callbacks={on_spawn,on_despawn,on_update,on_hit_null};
void EDW_PROJECTILE_INIT(uint8_t idx) {
    Entity *entity=&state.entities[idx];
    VX_BIND_projectile_spawn_LOCAL;
    entity->spawn_auto=true;entity->spawn_idx=-1;entity->spawn_priority=1;
    vx_bind_projectile_spawn_frame.a0=EDW_PROJECTILE_FIRE;vx_bind_projectile_spawn_frame.a1=0;
    vx_bind_projectile_spawn_frame.a2=0;vx_bind_projectile_spawn_frame.a3=0;vx_bind_projectile_spawn_run();
    entity->damage=vx_bind_projectile_spawn_frame.result.v5;
    entity->segment=MODULE_SEGMENT(EDW_PROJECTILE_MODULE,PAGE_C);entity->callbacks=&callbacks;
}
