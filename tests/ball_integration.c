#include <common.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "vx_sprite_assets.h"
#include "entities/enemy_ball/enemy_ball_sprite.h"
#if EDW_VEXEL
#include "vx_bind_skeleti_tick.h"
#endif
struct T_State state;
TSpriteStatus sprites[12];
static uint8_t queries,blocked,mutate,gate,touch;
static void reuse(void) {
#if EDW_VEXEL
    VX_BIND_skeleti_tick_LOCAL;
    vx_bind_skeleti_tick_frame.a0=19;vx_bind_skeleti_tick_frame.a1=6;vx_bind_skeleti_tick_run();
#endif
}
uint8_t combat_update(uint8_t slot) {assert(slot==3);reuse();return gate;}
uint8_t overworld_get_entity_flags(uint16_t i,uint16_t j) {
    Entity *e=&state.entities[ENTITY_ENEMY_PROJECTILE_0];
    printf("query %u %u %u %u %u\n",i,j,e->orientation,e->animation_counter,queries);
    reuse();if(mutate) { e->pos.i+=17;e->pos.j-=9; }
    return (blocked&(1u<<queries++))?MAP_OBSTACLE:0;
}
bool collision_wolfi_d(uint8_t slot) {assert(slot==3);reuse();return touch;}
void hit_wolfi_d(uint8_t slot) {assert(slot==3);puts("hit");reuse();}
void on_hit_default(Entity *a,Entity *b) {(void)a;(void)b;}
int main(void) {
    static const uint16_t positions[]={0,16,2047,2048,2049,65535};
    static const uint8_t counters[]={0,1,2,30,255};
    unsigned d,c,k,b;
    for(d=0;d<5;++d)for(c=0;c<sizeof(counters);++c)for(k=0;k<sizeof(positions)/sizeof(*positions);++k)for(b=0;b<4;++b) {
        Entity *e=&state.entities[ENTITY_ENEMY_PROJECTILE_0];int frame=-1;
        memset(&state,0,sizeof(state));memset(sprites,0,sizeof(sprites));
        init_enemy_ball(ENTITY_ENEMY_PROJECTILE_0,k&1?0:128,0);e->spawn_idx=3;e->orientation=d;
        e->callbacks->on_spawn(e);e->pos.i=positions[k];e->pos.j=positions[k];e->animation_counter=counters[c];
        state.game_cycles=b==3?0:1;blocked=b;queries=0;mutate=k&1;touch=b&1;
        gate=b==2 && c==4?COMBAT_STUNNED:(b==1 && c==4?COMBAT_DEAD:COMBAT_READY);
        sprites[3].spriteInfo=nullptr;sprites[3].resourceRequest=0;
        printf("case %u %u %u %u\n",d,c,k,b);
        {uint8_t live=e->callbacks->on_update(e);
#if EDW_VEXEL
        if(sprites[3].resourceRequest)frame=sprites[3].resourceRequest-EDW_BALL_SPRITE_FIRST;
#else
        if(sprites[3].spriteInfo==&enemy_ball_2_0)frame=2;
        if(sprites[3].spriteInfo==&enemy_ball_3_0)frame=3;
#endif
        printf("state %u %u %u %u %u %d %u\n",live,e->pos.i,e->pos.j,e->orientation,e->animation_counter,frame,queries);}
        e->callbacks->on_despawn(e);assert(!sprites[3].enabled);
#if EDW_VEXEL
        assert(!sprites[3].resourceRequest && !sprites[3].spriteInfo);
#endif
    }
    puts("ball: patrol, same-update reversal, map effects, waits and combat gates passed");
}
