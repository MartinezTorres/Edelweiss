/* Real callbacks, with observable map effects that can consume sprite requests
 * and reuse the Vexel workspace. C is the independent behavioral reference. */
#include <common.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "entities/weapons/entity_weapon_arrow_sprite.h"
#include "entities/weapons/entity_weapon_fire_sprite.h"
#include "entities/weapons/entity_weapon_bomb_sprite.h"
#include "vx_sprite_assets.h"
#if EDW_VEXEL
#include "vx_bind_skeleti_tick.h"
void vx_trap(uint8_t code) { (void)code;assert(0); }
#endif
struct T_State state;
TSpriteStatus sprites[12];
T_Map map;
static Entity *bomb;
static uint8_t tile,mutate;
static unsigned queries,writes,draws,frees;
#define FOUR(n) &weapon_##n##_0_0,&weapon_##n##_1_0,&weapon_##n##_2_0,&weapon_##n##_3_0
static const TSpriteInterlaced *const assets[]={FOUR(arrow),FOUR(fire),FOUR(bomb)};
static int frame(unsigned slot) {
#if EDW_VEXEL
    return sprites[slot].resourceRequest?sprites[slot].resourceRequest-EDW_ARROW_SPRITE_FIRST:-1;
#else
    unsigned k;
    if(!sprites[slot].spriteInfo)return -1;
    for(k=0;k<12;++k)if(sprites[slot].spriteInfo==assets[k])return k;
    assert(0);return -1;
#endif
}
static void reuse(void) {
#if EDW_VEXEL
    VX_BIND_skeleti_tick_LOCAL;
    vx_bind_skeleti_tick_frame.a0=173;vx_bind_skeleti_tick_frame.a1=5;vx_bind_skeleti_tick_run();
#endif
}
static void consume(unsigned slot) {
    int f=frame(slot);
    if(f>=0) {
        sprites[slot].pattern0Color=assets[f]->sprite0Color;
        sprites[slot].pattern1Color=assets[f]->sprite1Color;
        sprites[slot].spriteInfo=nullptr;sprites[slot].resourceRequest=0;
    }
}
uint8_t overworld_get_tile16(uint16_t i,uint16_t j) {
    ++queries;
    printf("query %u %u %u %d %u %u %u\n",bomb->animation_counter,i,j,frame(1),
        sprites[1].pattern1Color,sprites[1].pos.i,sprites[1].pos.j);
    reuse();
    if(mutate) { consume(1);bomb->pos.i+=17;bomb->pos.j-=31; }
    return tile;
}
void overworld_set_map_index(uint16_t i,uint16_t j,uint8_t value) {
    ++writes;assert(value==1 && i==(uint16_t)(bomb->pos.i+256) && j==(uint16_t)(bomb->pos.j+256));
    printf("write %u %u %u\n",bomb->animation_counter,i,j);reuse();
    tile=1; /* Subsequent detonation ticks observe the changed map. */
    if(mutate) { bomb->pos.i+=19;bomb->pos.j-=23; }
}
void overworld_draw_tile8(uint8_t i,uint8_t j) {
    assert(i<24 && j<32);++draws;printf("draw %u %u\n",i,j);reuse();
}
void overworld_free(void) { ++frees;reuse(); }
void on_hit_null(Entity *a,Entity *b) { (void)a;(void)b; }
static Entity *spawn(unsigned kind,unsigned facing) {
    Entity *e=&state.entities[ENTITY_PROJECTILE_0];
    memset(&state,0,sizeof(state));memset(sprites,0,sizeof(sprites));memset(&map,0,sizeof(map));
    state.entities[0].orientation=facing;state.entities[0].pos.i=65530;state.entities[0].pos.j=7;
    e->pos.i=33;e->pos.j=44;e->animation_counter=251;
    if(kind==0)init_weapon_bow(ENTITY_PROJECTILE_0);
    else if(kind==1)init_weapon_fire(ENTITY_PROJECTILE_0);
    else init_weapon_bomb(ENTITY_PROJECTILE_0);
    e->spawn_idx=1;e->callbacks->on_spawn(e);
    assert(e->damage==2 && sprites[1].enabled && !sprites[1].overrideColors);
    printf("spawn %u %u %u %u %d %d %u %u %u %d\n",kind,facing,e->pos.i,e->pos.j,e->vel.i,e->vel.j,
        e->animation_counter,sprites[1].pos.i,sprites[1].pos.j,frame(1));
    return e;
}
static void snapshot(Entity *e,uint8_t live) {
    printf("update %u %u %u %u %u %u %d %u\n",live,e->animation_counter,e->pos.i,e->pos.j,
        sprites[1].pos.i,sprites[1].pos.j,frame(1),sprites[1].pattern1Color);
}
int main(void) {
    static const uint8_t dt[]={0,1,2,3,8,40,255};
    static const uint8_t counters[]={0,119,120,127,128,179,180,185,186,187,189,190,193,205,206,209,210,221,222};
    static const uint8_t tiles[]={255,TILE_LARGE_ROCK_SAND,TILE_LARGE_ROCK_GRAVE,TILE_LARGE_ROCK_MIXED,TILE_DOOR_MOUNTAIN_COVERED};
    unsigned kind,d,k,t,m;
    for(kind=0;kind<2;++kind)for(d=0;d<5;++d) {
        Entity *e=spawn(kind,d);
        for(k=0;k<sizeof(dt);++k) {
            state.isr_count_delta=dt[k];snapshot(e,e->callbacks->on_update(e));
            reuse();if(k&1)consume(1);
        }
        e->callbacks->on_despawn(e);assert(!e->spawn_auto && !sprites[1].enabled);
#if EDW_VEXEL
        assert(!sprites[1].spriteInfo && !sprites[1].resourceRequest);
#endif
    }
    for(m=0;m<2;++m)for(t=0;t<sizeof(counters);++t)for(k=0;k<sizeof(dt);++k) {
        bomb=spawn(2,0);bomb->animation_counter=counters[t];mutate=m;
        tile=TILE_LARGE_ROCK_SAND;queries=writes=draws=frees=0;
        bomb->pos.i=65530;bomb->pos.j=7;map.pos.i=253;map.pos.j=0;
        sprites[1].pattern1Color=3;
        state.isr_count_delta=dt[k];snapshot(bomb,bomb->callbacks->on_update(bomb));
        printf("effects %u %u %u %u %u\n",queries,writes,draws,frees,state.request_pattern_name_transfer);
        assert(writes==frees && writes<=1 && queries<=4);
    }
    for(t=0;t<sizeof(tiles);++t) {
        bomb=spawn(2,4);bomb->animation_counter=175;mutate=1;tile=tiles[t];queries=writes=draws=frees=0;
        bomb->pos.i=2000;bomb->pos.j=2000;state.isr_count_delta=80;
        snapshot(bomb,bomb->callbacks->on_update(bomb));
        assert(queries==4 && writes==(t!=0) && frees==writes && bomb->animation_counter==222);
        bomb->callbacks->on_despawn(bomb);assert(!bomb->spawn_auto && !sprites[1].enabled);
#if EDW_VEXEL
        assert(!sprites[1].spriteInfo && !sprites[1].resourceRequest);
#endif
    }
    puts("projectiles: launch, wrapping movement, pending frames, bomb boundaries and ordered effects agree");
}
