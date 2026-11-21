/* Execute the actual C and Vexel scene adapters. Every engine sink overwrites
 * the shared binding workspace, as a nested actor callback is allowed to do. */
#include <common.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "entities/wolfi/entity_wolfi.c"
#if EDW_VEXEL
#include "vx_bind_skeleti_tick.h"
#include "vx_bind_player_move.h"
#endif
struct T_State state;
T_Map map;
TSpriteStatus sprites[12];
uint8_t keyboard[16],keyboard_prev[16],keyboard_click[16];
static unsigned waits;
static void reuse(void) {
#if EDW_VEXEL
    memset(&vx_bind_player_move_frame,0xA5,sizeof(vx_bind_player_move_frame));
#endif
}
static void trace(const char *kind,unsigned a,unsigned b) {
    Entity *e=&state.entities[0];
    printf("%s %u %u: %u %u %u %u %u %u\n",kind,a,b,e->movie_state,
        e->animation_counter,e->pos.i,e->pos.j,state.next_flower.i,state.next_flower.j);
    reuse();
}
void trampoline_page_c(uint8_t bank,void (*f)(void)) {(void)bank;f();}
void trampoline_page_c_uint8_t(uint8_t bank,void (*f)(uint8_t),uint8_t p) {(void)bank;f(p);}
void wait_frame(void) {
    assert(++waits<2000);trace("wait",state.request_pattern_name_transfer,0);
    state.isr_state_machine=(state.isr_state_machine+1)%6;
    map.pos=state.target_map_pos;state.request_scroll_update=false;
}
void small_message(const char *s) {printf("small %s\n",s);trace("message",0,0);}
void large_message(const char *s) {printf("large %s\n",s);trace("message",1,0);}
void init_spark(uint8_t id) {trace("spark_init",id,0);}
void init_fairy(void) {trace("fairy_init",0,0);}
bool spawn_entity(uint8_t id) {
    trace("spawn",id,0);
    printf("entity %u %u %u %u\n",state.entities[id].pos.i,state.entities[id].pos.j,
        state.entities[id].anchor8.i,state.entities[id].anchor8.j);
    return true;
}
void despawn_entity(uint8_t id) {trace("despawn",id,0);}
void overworld_set_map_index(uint16_t i,uint16_t j,uint8_t n) {printf("map %u %u %u\n",i,j,n);trace("set",0,0);}
void overworld_draw_tile8(uint8_t i,uint8_t j) {trace("tile",i,j);}
void overworld_erase_row(uint8_t n) {trace("erase_row",n,0);}
void overworld_erase_col(uint8_t n) {trace("erase_col",n,0);}
void overworld_draw_row(uint8_t n) {trace("row",n,0);}
void overworld_draw_col(uint8_t n) {trace("col",n,0);}
void overworld_free(void) {trace("free",0,0);}
void overworld_copyPN1(void) {trace("copy",1,0);}
void overworld_copyPN0(void) {trace("copy",0,0);}
void infobar_update_map(void) {trace("minimap",0,0);}
void infobar_update_weapon(void) {assert(0);}
uint8_t combat_update(uint8_t n) {(void)n;assert(0);return 0;}
void on_hit_default(Entity *a,Entity *b) {(void)a;(void)b;assert(0);}
void on_hit_null(Entity *a,Entity *b) {(void)a;(void)b;}
void init_weapon(void) {assert(0);}
void wolfi_triggers(void) {assert(0);}
uint8_t overworld_get_entity_flags(uint16_t i,uint16_t j) {(void)i;(void)j;assert(0);return 0;}
static void reset(void) {
    memset(&state,0,sizeof(state));memset(sprites,0,sizeof(sprites));memset(&map,0,sizeof(map));
    init_wolfi(0,120,126);state.isr_count_delta=1;map.pos.i=state.target_map_pos.i=90;
    map.pos.j=state.target_map_pos.j=110;waits=0;state.next_flower.i=99;state.next_flower.j=137;
}
static void snapshot(void) {
    Entity *e=&state.entities[0];int frame=-1;
#if EDW_VEXEL
    if(sprites[0].resourceRequest)frame=sprites[0].resourceRequest-EDW_PLAYER_SPRITE_FIRST;
#else
    const TSpriteInterlaced *const f[]={&wolfi_0_0,&wolfi_0_1,&wolfi_1_0,&wolfi_1_1,&wolfi_2_0,&wolfi_2_1,&wolfi_3_0,&wolfi_3_1,&wolfi_4_0,&wolfi_4_1};
    unsigned n;for(n=0;n<10;++n)if(sprites[0].spriteInfo==f[n])frame=n;
#endif
    printf("state %u %u %u %u %u %u %d %u %u %u %u %u\n",e->movie_state,e->animation_counter,e->skip_23_frame,
        e->pos.i,e->pos.j,e->orientation,frame,state.target_map_pos.i,state.target_map_pos.j,state.request_scroll_update,
        sprites[0].pos.i,sprites[0].pos.j);
}
int main(void) {
    unsigned n,phase,dt;
    for(dt=1;dt<=3;++dt) {
        reset();state.isr_count_delta=dt;
        for(n=0;state.entities[0].callbacks!=&callbacks;++n) {
            assert(n<1200);on_update_intro(&state.entities[0]);snapshot();
            map.pos=state.target_map_pos;state.request_scroll_update=false;
        }
        assert(state.entities[0].movie_state==6 && state.next_flower.i==29 && state.next_flower.j==235);
        printf("intro finished %u %u\n",dt,n);
    }
    /* All event times, including wrap and skipped ticks; clipped statue redraw. */
    for(phase=3;phase<=5;phase+=2)for(n=0;n<256;++n) {
        reset();state.entities[0].movie_state=phase;state.entities[0].animation_counter=n;
        map.pos.i=state.target_map_pos.i=100;map.pos.j=state.target_map_pos.j=138;
        on_update_intro(&state.entities[0]);snapshot();
    }
    for(n=0;n<3;++n) {
        unsigned k;reset();state.entities[0].maximum_life=n==0?6:n==1?20:0;
        state.entities[0].pos.i=n==2?0:2000;state.rupees=123;
        state.entities[0].push_frames=state.entities[0].invulnerable_frames=9;
        for(k=1;k<12;++k)sprites[k].enabled=k&1;
        wolfi_is_killed();
        assert(!state.rupees && !state.entities[0].push_frames && !state.entities[0].invulnerable_frames);
        assert(state.entities[0].life==state.entities[0].maximum_life);
        for(k=1;k<12;++k)assert(sprites[k].enabled==(k&1));
        printf("revived %u waits %u\n",state.entities[0].life,waits);
    }
    puts("scenes: full intro, batched ticks, every montage phase and death effects agree");
}
