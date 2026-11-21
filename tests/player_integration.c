#include <common.h>
#include <gameplay/player_sprite.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "entities/wolfi/player_controls.inc"
#if EDW_VEXEL
#include "vx_bind_skeleti_tick.h"
#endif
struct T_State state;
TSpriteStatus sprites[12];
T_Map map;
uint8_t keyboard[16],keyboard_prev[16],keyboard_click[16];
static unsigned queries,blocks,mutate,triggers;
static int spawned;
static void reuse(void) {
#if EDW_VEXEL
    VX_BIND_skeleti_tick_LOCAL;
    vx_bind_skeleti_tick_frame.a0=99;vx_bind_skeleti_tick_frame.a1=1;vx_bind_skeleti_tick_run();
#endif
}
void trampoline_page_c(uint8_t bank,void (*f)(void)) {(void)bank;f();}
void wolfi_triggers(void) {++triggers;puts("trigger");reuse();state.entities[0].pos.i+=128;}
void init_weapon(void) {printf("weapon %u\n",state.weapon);reuse();}
void infobar_update_weapon(void) {puts("icon");reuse();}
bool spawn_entity(uint8_t slot) {
    printf("spawn %u at %u %u facing %u\n",slot,state.entities[0].pos.i,state.entities[0].pos.j,state.entities[0].orientation);
    spawned=slot;reuse();state.entities[slot].spawn_idx=5;return true;
}
uint8_t overworld_get_entity_flags(uint16_t i,uint16_t j) {
    uint8_t flags=((blocks&(1u<<(queries%3)))?MAP_OBSTACLE:0)|MAP_TRIGGER;
    printf("query %u %u %u state %u %u %u %u %u\n",i,j,flags,
        state.entities[0].pos.i,state.entities[0].pos.j,state.entities[0].skip_23_frame,
        state.entities[0].animation_counter,keyboard[8]);++queries;reuse();
    if(mutate&1){state.entities[0].pos.i+=7;state.entities[0].pos.j-=11;}
    if((mutate&2) && queries==1) {
        /* A boundary supplies fresh state; no field may be restored from the
         * entry snapshot after an engine callback has changed it. */
        keyboard[8]=0x5f;state.isr_count_delta=2;
        state.entities[0].skip_23_frame=2;
        state.entities[0].animation_counter=3;
        state.entities[0].orientation=E_DOWN;
    }
    return flags;
}
static void run(unsigned keys,unsigned dt,unsigned skip,unsigned obstacles,unsigned change) {
    Entity *e=&state.entities[0];unsigned n;int frame=-1;uint8_t view;
    static const uint8_t slots[]={ENTITY_SLASH,ENTITY_BOMB_0,ENTITY_BOMB_1,ENTITY_PROJECTILE_0,ENTITY_PROJECTILE_1};
    memset(&state,0,sizeof(state));memset(sprites,0,sizeof(sprites));memset(&map,0,sizeof(map));
    memset(keyboard,255,sizeof(keyboard));memset(keyboard_click,0,sizeof(keyboard_click));
    e->pos.i=change?65530:8000;e->pos.j=change?9:9000;e->orientation=E_UP;e->animation_counter=255;e->skip_23_frame=skip;
    keyboard[8]=keys;state.isr_count_delta=dt;blocks=obstacles;mutate=change;queries=triggers=0;
    state.weapon=(keys>>4)&7;
    for(n=0;n<8;++n)state.has_weapon[n]=(0xA5>>n)&1;
    for(n=0;n<5;++n)state.entities[slots[n]].spawn_idx=(obstacles&(1u<<n))?4:-1;
    keyboard_click[4]=change?K_M:0;keyboard_click[8]=change?K_SPACE:0;
    map.pos.i=state.target_map_pos.i=31;map.pos.j=state.target_map_pos.j=35;
    printf("case %u %u %u %u %u\n",keys,dt,skip,obstacles,change);
    view=player_control(e);if(view)player_view(e);
#if EDW_VEXEL
    if(sprites[0].resourceRequest)frame=sprites[0].resourceRequest-EDW_PLAYER_SPRITE_FIRST;
#else
    {const TSpriteInterlaced *const frames[]={&wolfi_0_0,&wolfi_0_1,&wolfi_1_0,&wolfi_1_1,&wolfi_2_0,&wolfi_2_1,&wolfi_3_0,&wolfi_3_1,&wolfi_4_0,&wolfi_4_1};
     for(n=0;n<10;++n)if(sprites[0].spriteInfo==frames[n])frame=n;}
#endif
    assert(queries || !triggers); /* skipped/zero ticks never reuse old trigger flags */
    printf("state %u %u %u %u %u %u %d %u %u %u %u %u\n",view,e->pos.i,e->pos.j,e->orientation,e->animation_counter,e->skip_23_frame,frame,
        keyboard[8],state.target_map_pos.i,state.target_map_pos.j,state.request_scroll_update,queries);
}
int main(void) {
    unsigned keys,dt,skip,b;
    for(keys=0;keys<16;++keys)for(dt=0;dt<4;++dt)for(skip=0;skip<3;++skip)for(b=0;b<4;++b)
        run((keys<<4)|15,dt,skip,b,keys&1);
    run(254,1,255,7,0);run(207,0,2,0,0);
    run(159,3,0,0,2);run(159,1,0,7,3);
    /* Every weapon/inventory and free-slot combination, independently modeled. */
    for(keys=0;keys<8;++keys)for(b=0;b<256;++b) {
        unsigned expected=keys,n;
        memset(&state,0,sizeof(state));memset(keyboard,255,sizeof(keyboard));memset(keyboard_click,0,sizeof(keyboard_click));
        state.weapon=keys;for(n=0;n<8;++n)state.has_weapon[n]=(b>>n)&1;
        for(n=1;n<=8;++n)if(b&(1u<<((keys+n)&7))){expected=(keys+n)&7;break;}
        keyboard_click[4]=K_M;player_control(&state.entities[0]);assert(state.weapon==expected);
    }
    for(keys=0;keys<9;++keys)for(b=0;b<32;++b) {
        static const uint8_t slots[]={ENTITY_SLASH,ENTITY_BOMB_0,ENTITY_BOMB_1,ENTITY_PROJECTILE_0,ENTITY_PROJECTILE_1};
        static const uint8_t allowed[]={1,1,1,1,6,24,24,1,0};
        unsigned n;int expected=-1;
        memset(&state,0,sizeof(state));memset(keyboard,255,sizeof(keyboard));memset(keyboard_click,0,sizeof(keyboard_click));
        state.weapon=keys==8?255:keys;spawned=-1;keyboard_click[8]=K_SPACE;
        for(n=0;n<5;++n) {
            state.entities[slots[n]].spawn_idx=(b&(1u<<n))?-1:4;
            if(expected<0 && (b&allowed[keys]&(1u<<n)))expected=slots[n];
        }
        player_control(&state.entities[0]);assert(spawned==expected);
    }
    puts("player: keys, cadence, corner slide, ordered queries, attacks, inventory and view passed");
}
