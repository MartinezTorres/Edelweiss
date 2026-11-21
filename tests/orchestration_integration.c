/* Actual frame orchestration with deterministic engine effects. */
#include <common.h>
#include <gameplay/world_orchestration.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#if EDW_VEXEL
#include "vx_binding_storage.h"
#include "vx_bind_player_move.h"
#endif
TSpriteStatus sprites[12];
static unsigned yields,waits,changes;
static void reuse(void) {
#if EDW_VEXEL
    memset(&vx_bind_player_move_frame,0xA5,sizeof(vx_bind_player_move_frame));
#endif
}
void yield(void) {
    ++yields;reuse();
    if(changes && yields==3) {++map.pos.i;--map.pos.j;}
}
void wait_frame(void) {
    assert(++waits<600);map.pos=state.target_map_pos;state.request_scroll_update=false;reuse();
    printf("wait %u %u\n",map.pos.i,map.pos.j);
}
void overworld_draw_row(uint8_t n) {printf("row %u at %u %u\n",n,map.pos.i,map.pos.j);reuse();}
void overworld_draw_col(uint8_t n) {printf("col %u at %u %u\n",n,map.pos.i,map.pos.j);reuse();}
void overworld_erase_row(uint8_t n) {(void)n;assert(0);}
void overworld_erase_col(uint8_t n) {(void)n;assert(0);}
void overworld_free(void) {puts("free");reuse();}
void overworld_copyPN1(void) {puts("copy1");reuse();}
void overworld_copyPN0(void) {puts("copy0");reuse();}
static void on_spawn(Entity *e) {printf("spawn %u slot %u\n",(unsigned)(e-state.entities),e->spawn_idx);reuse();}
static void on_despawn(Entity *e) {printf("despawn %u slot %u\n",(unsigned)(e-state.entities),e->spawn_idx);reuse();}
static uint8_t on_update(Entity *e) {
    unsigned id=e-state.entities;
    printf("update %u slot %u\n",id,e->spawn_idx);reuse();
    if(changes) {
        if(id==1)e->pos.i+=4096;
        if(id==2)despawn_entity(id);
    }
    return id!=3;
}
static const struct T_Entity_Callbacks callbacks={on_spawn,on_despawn,on_update,0};
static void init_point(const char *kind,uint8_t id,uint8_t i,uint8_t j) {
    printf("init %s %u %u %u\n",kind,id,i,j);reuse();
}
void init_wolfi(uint8_t id,uint8_t i,uint8_t j) {init_point("wolfi",id,i,j);}
void init_ghosti(uint8_t id,uint8_t i,uint8_t j) {init_point("ghost",id,i,j);}
void init_skeleti(uint8_t id,uint8_t i,uint8_t j) {init_point("skeleti",id,i,j);}
void init_enemy_ball(uint8_t id,uint8_t i,uint8_t j) {init_point("ball",id,i,j);}
void init_lumberjack(uint8_t id,uint8_t i,uint8_t j) {init_point("lumberjack",id,i,j);}
void init_explosion(uint8_t id) {init_point("explosion",id,0,0);}
void init_drop_item(uint8_t id) {init_point("drop",id,0,0);}
void init_weapon_slash(uint8_t id,uint8_t kind) {init_point("weapon",id,kind,0);}
void init_weapon_bomb(uint8_t id) {init_point("bomb",id,0,0);}
void init_weapon_fire(uint8_t id) {init_point("fire",id,0,0);}
void init_weapon_bow(uint8_t id) {init_point("bow",id,0,0);}
static void reset(void) {
    unsigned n;memset(&state,0,sizeof(state));memset(sprites,0,sizeof(sprites));
    memset(state.spawns,-1,sizeof(state.spawns));memset(&map,0,sizeof(map));
    for(n=0;n<96;++n) {state.entities[n].spawn_idx=-1;state.entities[n].callbacks=&callbacks;state.entities[n].spawn_priority=1;}
    yields=waits=0;
}
int main(void) {
    static const uint8_t samples[]={0,1,2,3,4,127,252,253,254,255};
    static const int offsets[]={-4,-3,-1,0,23,24,26,27,31,32,34,35};
    unsigned a,b,n,cycle,di,dj;
    reset();world_init_entities();
    /* Live projectiles must be removed before either replacement is initialized. */
    for(a=0;a<9;++a) {
        reset();state.weapon=a;
        for(n=0;n<2;++n) {
            state.spawns[n+1]=ENTITY_PROJECTILE_0+n;
            state.entities[ENTITY_PROJECTILE_0+n].spawn_idx=n+1;
        }
        state.num_spawns=2;printf("equipment %u\n",a);init_weapon();
        printf("remaining %u\n",state.num_spawns);
    }
    for(a=0;a<sizeof(samples);++a)for(b=0;b<sizeof(samples);++b) {
        uint8_t delta=(uint8_t)(samples[a]-samples[b]);
        reset();state.isr_count=samples[a];state.game_cycles=samples[b];world_begin_frame(samples[b]);
        assert(state.isr_count_delta==(delta>3?1:delta));assert(state.game_cycles==(uint8_t)(samples[b]+1));
    }
    for(changes=0;changes<2;++changes)for(cycle=0;cycle<16;++cycle) {
        reset();state.game_cycles=cycle;map.pos.i=255;map.pos.j=2;
        for(n=0;n<96;++n) {
            state.entities[n].pos.i=(uint16_t)(uint8_t)(map.pos.i+offsets[n%12])<<8;
            state.entities[n].pos.j=(uint16_t)(uint8_t)(map.pos.j+offsets[(n/12)%12])<<8;
            state.entities[n].spawn_auto=n%3!=0;
        }
        for(n=0;n<4;++n) {state.spawns[n]=n;state.entities[n].spawn_idx=n;}
        state.num_spawns=4;printf("cycle %u changes %u\n",cycle,changes);world_update_entities();
        printf("spawns %u yields %u map %u %u:",state.num_spawns,yields,map.pos.i,map.pos.j);
        for(n=0;n<12;++n)printf(" %d",state.spawns[n]);puts("");
    }
    for(a=0;a<3;++a)for(di=0;di<3;++di)for(dj=0;dj<3;++dj) {
        uint16_t result;reset();map.pos.i=a==0?1:a==1?106:254;map.pos.j=a==0?1:a==1?224:254;
        state.target_map_pos.i=map.pos.i+di-1;state.target_map_pos.j=map.pos.j+dj-1;
        result=world_scroll(a&1);printf("scroll %u %u %u\n",result,map.pos.i,map.pos.j);
    }
    for(a=0;a<2;++a)for(b=0;b<2;++b)for(n=0;n<4;++n) {
        unsigned k;reset();state.follower_entity_spawn_idx=4;state.spawns[4]=1;
        state.history_wolfi_pos_count=254;state.entities[0].pos.i=123;state.entities[0].pos.j=456;
        state.entities[0].orientation=E_LEFT;sprites[0].enabled=a;
        for(k=0;k<8;++k) {
            state.history_wolfi_pos[k].i=k==6?123:k;state.history_wolfi_pos[k].j=k==6?456:k+100;
            state.history_wolfi_visibility[k]=b;state.history_wolfi_orientation[k]=E_UP;
        }
        state.isr_state_machine=n;world_follow();world_follow();
        printf("trail %u %u %u %u %u %u\n",state.history_wolfi_pos_count,state.entities[1].pos.i,
            state.entities[1].pos.j,state.entities[1].orientation,sprites[4].enabled,state.history_wolfi_pos[0].i);
    }
    reset();world_reveal();assert(waits==33);
    /* Signed camera deltas during a warp, including coordinates before origin. */
    for(a=0;a<3;++a) {
        reset();map.pos.i=state.target_map_pos.i=90;map.pos.j=state.target_map_pos.j=110;
        state.entities[0].pos.i=(uint16_t)(a==0?20:a==1?100:255)<<8;
        state.entities[0].pos.j=(uint16_t)(a==0?10:a==1?120:255)<<8;
        wolfi_door_warp_migrate();printf("migrated %u %u waits %u\n",map.pos.i,map.pos.j,waits);
    }
    puts("orchestration: cadence, callback order, spawn bands, scrolling, trail and reveal agree");
}
