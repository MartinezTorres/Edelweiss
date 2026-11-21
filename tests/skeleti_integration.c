/* Test actual callbacks against fixed-width expectations and compare C/Vexel
 * traces. Effects deliberately verify order, not just final coordinates. */
#include <common.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#if EDW_VEXEL
#include "vx_sprite_assets.h"
#endif
struct T_State state;
TSpriteStatus sprites[12];
#define FRAME(n) const TSpriteInterlaced skeleti_##n##_0={0},skeleti_##n##_1={0}
FRAME(0);FRAME(1);FRAME(2);FRAME(3);FRAME(4);
static const TSpriteInterlaced * const frames[]={&skeleti_0_0,&skeleti_0_1,
    &skeleti_1_0,&skeleti_1_1,&skeleti_2_0,&skeleti_2_1,
    &skeleti_3_0,&skeleti_3_1,&skeleti_4_0,&skeleti_4_1};
static uint8_t randoms[3],draws,expected_draws,stage,blocked,touching,alive,stunned;
static uint16_t proposed_i,proposed_j;
static unsigned hits;
uint8_t rand7(void) { assert(stage==1 && draws<expected_draws);return randoms[draws++]; }
uint8_t combat_update(uint8_t slot) {
    assert(slot==4 && stage==0);stage=1;return !alive?COMBAT_DEAD:(stunned?COMBAT_STUNNED:COMBAT_READY);
}
uint8_t overworld_get_entity_flags(uint16_t i,uint16_t j) {
    assert(stage==1 && draws==expected_draws && i==proposed_i && j==proposed_j);
    stage=2;return blocked?MAP_OBSTACLE:0;
}
bool collision_wolfi_d(uint8_t slot) {
    assert(slot==4 && stage==2);stage=3;return touching;
}
void hit_wolfi_d(uint8_t slot) { assert(slot==4 && stage==3);stage=4;++hits; }
void on_hit_default(Entity *a,Entity *b) { (void)a;(void)b; }

static void run(uint8_t action,uint8_t delay,uint8_t reset,uint16_t i,uint16_t j,
                uint16_t pi,uint16_t pj,uint8_t ai,uint8_t aj,uint8_t clock,uint8_t cycle) {
    Entity *e=&state.entities[ENTITY_SKELETI_0];
    unsigned direction=0,frame=255,expected_action=action,expected_delay=delay;
    uint16_t old_i=i,old_j=j;
    bool active=((cycle+4)&3)==0 && alive && !stunned;
#if EDW_VEXEL
    uint8_t pending=clock&1?0:EDW_SKELETI_SPRITE_FIRST+9;
#else
    const TSpriteInterlaced *pending=clock&1?NULL:&skeleti_4_1;
#endif
    memset(&state,0,sizeof(state));memset(sprites,0,sizeof(sprites));
    init_skeleti(ENTITY_SKELETI_0,ai,aj);e->spawn_idx=4;
#if EDW_VEXEL
    sprites[4].resourceRequest=EDW_GHOST_SPRITE_FIRST;sprites[4].spriteInfo=&skeleti_4_1;
#endif
    e->callbacks->on_spawn(e);
#if EDW_VEXEL
    assert(sprites[4].enabled && !sprites[4].spriteInfo && sprites[4].resourceRequest==EDW_SKELETI_SPRITE_FIRST+2);
#else
    assert(sprites[4].enabled && sprites[4].spriteInfo==&skeleti_1_0);
#endif
    e->pos.i=i;e->pos.j=j;e->skeleti_action=action;e->skeleti_delay=delay;
#if EDW_VEXEL
    sprites[4].resourceRequest=pending;
#else
    sprites[4].spriteInfo=pending;
#endif
    state.entities[0].pos.i=pi;state.entities[0].pos.j=pj;
    state.game_cycles=cycle;state.isr_count=clock;
    stage=draws=hits=0;expected_draws=0;
    randoms[0]=reset;randoms[1]=0xAE;randoms[2]=0xF1;
    if(active) {
        expected_draws=1;
        if(!(reset&63))expected_action=0;
        if(delay) --expected_delay;
        else if(!expected_action) { expected_draws=3;expected_action=6;expected_delay=15; }
        else {
            switch(expected_action) {
            case 1: direction=pi>i?1:0;break;
            case 2: direction=pi<i?2:0;break;
            case 3: direction=pj>j?3:0;break;
            case 4: direction=pj<j?4:0;break;
            case 5: direction=(unsigned)ai*256>((unsigned)i+512)%65536?1:
                ((unsigned)ai*256<((unsigned)i+65536-512)%65536?2:0);break;
            case 6: direction=(unsigned)aj*256>((unsigned)j+512)%65536?3:
                ((unsigned)aj*256<((unsigned)j+65536-512)%65536?4:0);break;
            default: frame=(clock&8)?0:1;break;
            }
            if(!direction)expected_action=0;
            else {
                static const uint8_t variants[]={0,4,2,6,8};
                frame=variants[direction]+((clock&8)?0:1);
                if(direction<=2)i=(uint16_t)(i+(direction==1?64:-64));
                else j=(uint16_t)(j+(direction==3?64:-64));
            }
        }
    }
    proposed_i=i;proposed_j=j;
    assert(e->callbacks->on_update(e)==alive);
    if(blocked){i=old_i;j=old_j;}
    assert(e->pos.i==i && e->pos.j==j && e->skeleti_action==expected_action && e->skeleti_delay==expected_delay);
    assert(draws==expected_draws && stage==(active?(touching?4:3):1) && hits==(unsigned)(active && touching));
#if EDW_VEXEL
    assert(!sprites[4].spriteInfo && sprites[4].resourceRequest==(frame==255?pending:EDW_SKELETI_SPRITE_FIRST+frame));
#else
    assert(sprites[4].spriteInfo==(frame==255?pending:frames[frame]));
#endif
    if(active)assert(sprites[4].pos.i==i && sprites[4].pos.j==j);
    printf("%u,%u,%u: %u,%u %u,%u frame=%u draws=%u effects=%u\n",action,delay,reset,
        i,j,e->skeleti_action,e->skeleti_delay,frame,draws,stage);
    e->callbacks->on_despawn(e);assert(!sprites[4].enabled);
#if EDW_VEXEL
    assert(!sprites[4].resourceRequest && !sprites[4].spriteInfo);
#endif
}
int main(void) {
    unsigned action,k;
    static const uint16_t edge[]={0,511,512,513,65023,65024,65535};
    alive=1;stunned=1;
    run(1,0,0,1024,1024,2048,2048,8,8,0,0);
    stunned=0;
    for(action=0;action<9;++action)for(k=0;k<4;++k) {
        blocked=k&1;touching=(k>>1)&1;
        run(action,0,1,2000,4000,k<2?3000:1000,k<2?5000:3000,10,20,k?8:1,0);
        run(action,1,0,2000,4000,2000,4000,8,16,0,0);
        run(action,0,64,2000,4000,2000,4000,8,16,8,0);
    }
    blocked=touching=0;
    for(k=0;k<sizeof(edge)/sizeof(edge[0]);++k) {
        run(5,0,1,edge[k],0,0,0,k&1?0:255,0,8,0);
        run(6,0,1,0,edge[k],0,0,0,k&1?0:255,0,0);
    }
    run(0,0,1,0,0,0,0,0,0,0,255); // skipped, no draws or map effects
    // Waiting preserves either a pending frame or an already consumed request.
    run(4,5,1,2000,4000,3000,5000,10,20,0,0);
    run(4,5,1,2000,4000,3000,5000,10,20,1,0);
    alive=0;run(0,0,1,0,0,0,0,0,0,0,0); // shared death gate
    puts("skeleti: routine/delay, conditional draws, wrapping, blocked motion, sprite requests and contact passed");
}
