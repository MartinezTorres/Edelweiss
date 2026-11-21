#include "encounter.h"
void encounter_ball(void) {
    static const uint8_t counters[]={0,1,2,30};
    Entity *e=&state.entities[ENTITY_ENEMY_PROJECTILE_0];
    uint8_t d,c,p,live,frame;
    uint16_t hash=0;
    state.entities[0].pos.i=5000;state.entities[0].pos.j=5000;
    for(d=0;d<5;++d)for(c=0;c<4;++c)for(p=0;p<2;++p) {
        init_enemy_ball(ENTITY_ENEMY_PROJECTILE_0,103,20);e->spawn_idx=3;e->orientation=d;
        on_spawn(e);e->pos.i=103u*256+(p?17:-17);e->pos.j=(p?12u:28u)*256;
        e->animation_counter=counters[c];state.game_cycles=1;state.isr_count_delta=1;
        sprites[3].spriteInfo=nullptr;sprites[3].resourceRequest=0;
        live=on_update(e);frame=255;
#if EDW_VEXEL
        if(sprites[3].resourceRequest)frame=sprites[3].resourceRequest-EDW_BALL_SPRITE_FIRST;
#else
        if(sprites[3].spriteInfo==&enemy_ball_2_0)frame=2;
        if(sprites[3].spriteInfo==&enemy_ball_3_0)frame=3;
#endif
        hash=actor_hash(hash,live);hash=actor_hash(hash,e->pos.i);hash=actor_hash(hash,e->pos.j);
        hash=actor_hash(hash,e->orientation);hash=actor_hash(hash,e->animation_counter);hash=actor_hash(hash,frame);
        on_despawn(e);if(sprites[3].enabled)return;
    }
    e->spawn_idx=-1;edw_ball_hash=hash;edw_actor_checks|=4;
}
