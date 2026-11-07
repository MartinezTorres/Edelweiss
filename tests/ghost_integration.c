#include <common.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#if EDW_VEXEL
#include "vexel.h"
uint8_t vx_payload[20];
void vx_trap(uint8_t reason) { (void)reason;assert(0); }
#endif
struct T_State state;
TSpriteStatus sprites[12];
#define FRAME(n) const TSpriteInterlaced ghosti_##n##_0={0},ghosti_##n##_1={0}
FRAME(0);FRAME(1);FRAME(2);FRAME(3);FRAME(4);FRAME(5);FRAME(6);
static unsigned draws,gates,collisions,hits;
static uint8_t bits;
static bool alive=true,touching;
static void release_result(void) {
#if EDW_VEXEL
    memset(vx_payload,0xA5,sizeof(vx_payload));
#endif
}
uint16_t rand16(void) { assert(draws<6);release_result();return 0xAA00|((bits>>draws++)&1); }
bool generic_entity_invulnerable_frames_and_pushing(uint8_t slot) {
    assert(slot<12);++gates;release_result();return alive;
}
bool collision_wolfi_d(uint8_t slot) { assert(slot<12);++collisions;release_result();return touching; }
void hit_wolfi_d(uint8_t slot) { (void)slot;++hits;release_result(); }
void on_hit_default(Entity *a,Entity *b) { (void)a;(void)b; }
static Entity *reset(uint8_t slot,uint8_t ai,uint8_t aj) {
    Entity *e=&state.entities[ENTITY_GHOSTI_0];
    memset(&state,0,sizeof(state));memset(sprites,0,sizeof(sprites));
    init_ghosti(ENTITY_GHOSTI_0,ai,aj);e->spawn_idx=slot;
    draws=gates=collisions=hits=0;alive=true;touching=false;
    return e;
}
/* Fixed-width oracle: define wrapping and signed division independently of
 * both the generated C and the implementation-defined legacy narrowing. */
static int signed8(unsigned x) { x&=255;return x<128?(int)x:(int)x-256; }
static int signed16(unsigned x) { x&=65535;return x<32768?(int)x:(int)x-65536; }
static void axis(uint16_t *pos,int8_t *vel,uint8_t anchor,uint16_t player) {
    int v=signed8((unsigned)*vel+signed16((unsigned)anchor*256-*pos)/512);
    v=signed8(v+(player<*pos?-1:1));*vel=v;*pos=(uint16_t)(*pos+2*v);
}
int main(void) {
    static const TSpriteInterlaced *frames[]={&ghosti_0_0,&ghosti_0_1,&ghosti_1_0,&ghosti_1_1,
        &ghosti_2_0,&ghosti_2_1,&ghosti_3_0,&ghosti_3_1,&ghosti_4_0,&ghosti_4_1,&ghosti_5_0,&ghosti_5_1};
    static const uint8_t variants[]={0,2,4,6,4,4,10,10};
    Entity *e;unsigned k,t;
    for(k=0;k<4;++k) {
        bits=k*5|48;e=reset(6,0,255);e->callbacks->on_spawn(e);
        assert(draws==6 && e->pos.i==65280 && e->pos.j==64768);
        assert(e->vel.i==((bits&1)?-1:1)*((bits&4)?2:1));
        assert(e->vel.j==((bits&2)?-2:2)*((bits&8)?2:1));
        assert(!e->invulnerable_frames && sprites[6].enabled);
    }
    for(k=0;k<8;++k) {
        static const uint16_t positions[]={0,65535,511,512,513,32767,32768,60000};
        static const int8_t velocities[]={0,-1,127,-128,4,-4,60,-60};
        uint16_t pi,pj;int8_t vi,vj;
        e=reset(k,128,1);e->pos.i=positions[k];e->pos.j=positions[7-k];
        e->vel.i=velocities[k];e->vel.j=velocities[7-k];
        for(t=0;t<32;++t) {
            bool active=((t+k)&3)==0;
            state.game_cycles=t;state.entities[0].pos.i=t&1?0:65535;state.entities[0].pos.j=t&2?e->pos.j:17;
            e->life=3;pi=e->pos.i;pj=e->pos.j;vi=e->vel.i;vj=e->vel.j;touching=(t&4)!=0;
            if(active) { axis(&pi,&vi,e->anchor8.i,state.entities[0].pos.i);axis(&pj,&vj,e->anchor8.j,state.entities[0].pos.j); }
            unsigned old_collisions=collisions,old_hits=hits;
            assert(e->callbacks->on_update(e));
            assert(e->pos.i==pi && e->pos.j==pj && e->vel.i==vi && e->vel.j==vj);
            assert(e->life==(active?16:3) && collisions==old_collisions+active && hits==old_hits+(active&&touching));
            if(active)assert(sprites[k].spriteInfo==frames[variants[k]+(vj>0?0:1)]);
        }
        printf("ghost slot=%u pos=%u,%u vel=%d,%d contacts=%u\n",k,e->pos.i,e->pos.j,e->vel.i,e->vel.j,hits);
        alive=false;state.game_cycles=(uint8_t)-k;
        uint16_tp old=e->pos;unsigned old_collisions=collisions;
        assert(!e->callbacks->on_update(e) && e->pos.i==old.i && e->pos.j==old.j && collisions==old_collisions);
        e->callbacks->on_despawn(e);assert(!sprites[k].enabled);
    }
    puts("ghost: six draws, signed motion, scheduling, frames, collision and death gate passed");
}
