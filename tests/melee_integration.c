/* Compare real adapters, including callbacks that reuse the Vexel workspace. */
#include <common.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "entities/weapons/entity_weapon_slash_small_sprite.h"
#include "entities/weapons/entity_weapon_slash_large_sprite.h"
#include "vx_sprite_assets.h"
#if EDW_VEXEL
#include "vx_bind_skeleti_tick.h"
void vx_trap(uint8_t code) { (void)code;assert(0); }
#endif
struct T_State state;
TSpriteStatus sprites[12];
T_Map map;
static uint8_t tile;
static unsigned queries,writes,draws,frees,hits;
static uint16_t query_i,query_j;
static uint32_t effects;
static void effect(unsigned value) {
    effects=effects*16777619u+value;
#if EDW_VEXEL
    VX_BIND_skeleti_tick_LOCAL;
    vx_bind_skeleti_tick_frame.a0=244;vx_bind_skeleti_tick_frame.a1=7;vx_bind_skeleti_tick_run();
#endif
}
uint8_t overworld_get_tile16(uint16_t i,uint16_t j) {
    assert(!queries++);query_i=i;query_j=j;effect(i);effect(j);
    /* Hit calculation must refresh player facts after this callback. */
    state.entities[0].pos.i+=17;state.entities[0].pos.j-=31;return tile;
}
void overworld_set_map_index(uint16_t i,uint16_t j,uint8_t value) {
    assert(queries==1 && !writes++ && i==query_i && j==query_j && value==1);
    effect(i);effect(j);effect(value);
}
void overworld_draw_tile8(uint8_t row,uint8_t col) {
    assert(writes==1 && row<24 && col<32);++draws;effect(row);effect(col);
}
void overworld_free(void) { assert(writes==1 && !frees++);effect(777); }
void weapon_collision_detection_d(uint8_t slot,uint8_t h,uint8_t w) {
    Entity *e=&state.entities[ENTITY_SLASH];assert(slot==1 && !hits++);
    effect(e->pos.i);effect(e->pos.j);effect(h);effect(w);
}
void on_hit_null(Entity *a,Entity *b) { (void)a;(void)b; }
#define FRAMES(s) &weapon_slash_##s##_0_0,&weapon_slash_##s##_0_1,&weapon_slash_##s##_0_2,&weapon_slash_##s##_0_3, \
    &weapon_slash_##s##_1_0,&weapon_slash_##s##_1_3,&weapon_slash_##s##_2_0,&weapon_slash_##s##_2_3, \
    &weapon_slash_##s##_3_0,&weapon_slash_##s##_3_1,&weapon_slash_##s##_3_2,&weapon_slash_##s##_3_3
static int frame(void) {
#if EDW_VEXEL
    return sprites[1].resourceRequest ? sprites[1].resourceRequest-EDW_MELEE_SMALL_SPRITE_FIRST : -1;
#else
    static const TSpriteInterlaced *all[]={FRAMES(small),FRAMES(large)};unsigned k;
    if(!sprites[1].spriteInfo)return -1;
    for(k=0;k<24;++k)if(sprites[1].spriteInfo==all[k])return k;
    assert(0);return -1;
#endif
}
static Entity *reset(uint8_t weapon,uint8_t facing,uint16_t i,uint16_t j) {
    Entity *e;
    memset(&state,0,sizeof(state));memset(sprites,0,sizeof(sprites));memset(&map,0,sizeof(map));
    queries=writes=draws=frees=hits=0;effects=0;map.pos.i=facing&1?253:0;map.pos.j=facing&2?253:0;
    tile=facing%3==0?TILE_WOOD_FENCE:(facing%3==1?TILE_BUSH:0);
    state.entities[0].pos.i=i;state.entities[0].pos.j=j;state.entities[0].orientation=facing;
    init_weapon_slash(ENTITY_SLASH,weapon);e=&state.entities[ENTITY_SLASH];e->spawn_idx=1;
    sprites[1].pattern0Color=2;sprites[1].pattern1Color=3;
#if EDW_VEXEL
    sprites[1].resourceRequest=edw_melee_small_sprite(0);sprites[1].spriteInfo=&weapon_slash_small_0_0;
#endif
    e->callbacks->on_spawn(e);assert(hits==1 && queries==(weapon==E_AXE));
    assert(writes==(weapon==E_AXE && tile!=0) && frees==writes);
    assert(state.request_pattern_name_transfer==(writes!=0));
#if EDW_VEXEL
    assert(!sprites[1].resourceRequest && !sprites[1].spriteInfo);
#endif
    printf("spawn %u %u %u %u %u %u %u %u %u %u %u %lu\n",weapon,facing,e->damage,
        e->pos.i,e->pos.j,sprites[1].overrideColors,sprites[1].pattern0Color,sprites[1].pattern1Color,
        queries,writes,draws,(unsigned long)effects);
    return e;
}
static void snapshot(Entity *e,uint8_t live) {
    printf("tick %u %u %u %u %u %u %d\n",live,e->animation_counter,e->pos.i,e->pos.j,
        sprites[1].pos.i,sprites[1].pos.j,frame());
}
int main(void) {
    static const uint8_t weapons[]={E_PAW,E_CLAW,E_SWORD,E_AXE,E_BUTTER_KNIFE,255};
    static const uint8_t elapsed[]={0,1,3,4,7,255},starts[]={0,3,4,18,19};unsigned w,d,k,s;
    for(w=0;w<sizeof(weapons);++w)for(d=0;d<=E_DOWN;++d) {
        Entity *e=reset(weapons[w],d,d&1?65535:0,d&2?65535:0);
        for(k=0;k<sizeof(elapsed);++k) {
            uint8_t live;state.entities[0].pos.i+=29;state.entities[0].pos.j-=13;
            state.isr_count_delta=elapsed[k];live=e->callbacks->on_update(e);snapshot(e,live);
            assert(hits==1);
            if(!live) {assert(e->animation_counter==20);break;}
            if(k&1) {sprites[1].spriteInfo=nullptr;sprites[1].resourceRequest=0;}
        }
        assert(k<sizeof(elapsed));e->callbacks->on_despawn(e);
        assert(!e->spawn_auto && !sprites[1].enabled);
#if EDW_VEXEL
        assert(!sprites[1].resourceRequest && !sprites[1].spriteInfo);
#endif
        for(s=0;s<sizeof(starts);++s)for(k=0;k<sizeof(elapsed);++k) {
            uint8_t live;e->animation_counter=starts[s];e->pos.i=5;e->pos.j=65530;
            sprites[1].pos.i=13;sprites[1].pos.j=17;sprites[1].spriteInfo=nullptr;sprites[1].resourceRequest=0;
            state.isr_count_delta=elapsed[k];live=e->callbacks->on_update(e);snapshot(e,live);
        }
    }
    puts("melee: damage, palettes, hit rectangles, axe effects, callbacks, batched ticks, frames and cleanup passed");
}
