/* Deliberate new gameplay expectations, shared by the C reference and Vexel.
 * Test real hit/update adapters with deterministic map and allocation effects. */
#include <common.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

struct T_State state;
TSpriteStatus sprites[12];
static unsigned queries,wall_at,spawn_count;
static uint8_t spawned[2];
static uint16_tp death_position;
static bool pool_full,reenter;

uint8_t overworld_get_entity_flags(uint16_t i,uint16_t j) {
    Entity *e=&state.entities[ENTITY_SKELETI_0];
    assert(i==(uint16_t)(e->pos.i+e->push_vector.i));
    assert(j==(uint16_t)(e->pos.j+e->push_vector.j));
    ++queries;
    return wall_at && queries==wall_at?MAP_OBSTACLE:0;
}
bool spawn_entity(uint8_t id) {
    assert(spawn_count<2);
    spawned[spawn_count++]=id;
    assert(state.entities[id].pos.i==death_position.i && state.entities[id].pos.j==death_position.j);
    if(id==ENTITY_DROP_ITEM_0 || id==ENTITY_DROP_ITEM_1)
        assert(state.entities[id].drop_probability==E_DROP_PROBABILITY_HIGH);
    if(pool_full)return false;
    state.entities[id].spawn_idx=spawn_count+6;
    if(reenter) {
        /* An engine callback can enter another combat adapter after the
         * outer pure projections have returned. Reuse both fixed math
         * frames, while the outer entity pointer and drop choice stay live. */
        Entity *other=&state.entities[ENTITY_SKELETI_1];
        const uint8_t ids[]={ENTITY_EXPLOSION_0,ENTITY_EXPLOSION_1,ENTITY_DROP_ITEM_0,ENTITY_DROP_ITEM_1};
        int8_t saved[4];
        reenter=false;
        for(unsigned k=0;k<4;++k){saved[k]=state.entities[ids[k]].spawn_idx;state.entities[ids[k]].spawn_idx=8;}
        other->life=0;other->maximum_life=3;other->anchor8.i=1;other->anchor8.j=2;
        other->spawn_idx=5;state.spawns[5]=ENTITY_SKELETI_1;
        assert(combat_update(5)==COMBAT_DEAD);
        assert(other->life==3 && other->pos.i==256 && other->pos.j==512);
        for(unsigned k=0;k<4;++k)state.entities[ids[k]].spawn_idx=saved[k];
    }
    return true;
}
static Entity *reset(void) {
    Entity *e;
    memset(&state,0,sizeof(state));memset(sprites,0,sizeof(sprites));
    memset(state.spawns,-1,sizeof(state.spawns));
    for(unsigned k=0;k<96;++k)state.entities[k].spawn_idx=-1;
    e=&state.entities[ENTITY_SKELETI_0];e->spawn_idx=4;state.spawns[4]=ENTITY_SKELETI_0;
    e->life=e->maximum_life=8;e->pos.i=10000;e->pos.j=12000;
    state.entities[0].pos=e->pos;state.entities[0].damage=2;state.entities[0].orientation=E_DOWN;
    queries=wall_at=spawn_count=0;pool_full=reenter=false;
    return e;
}
static void directions(void) {
    static const struct { int di,dj,facing,vi,vj; } cases[]={
        {96,32,E_UP,32,0},{-96,32,E_DOWN,-32,0},
        {32,96,E_LEFT,0,32},{32,-96,E_RIGHT,0,-32},
        {64,64,E_RIGHT,0,32},{64,64,E_UP,32,0},
        {0,0,E_LEFT,0,-32},{0,0,E_RIGHT,0,32},
        {0,0,E_UP,-32,0},{0,0,E_DOWN,32,0},{0,0,E_REST,32,0},
        {-32768,0,E_DOWN,-32,0},{0,-32768,E_DOWN,0,-32}
    };
    for(unsigned k=0;k<sizeof(cases)/sizeof(cases[0]);++k) {
        Entity *e=reset(),*a=&state.entities[0];
        a->pos.i=(uint16_t)(e->pos.i-cases[k].di);a->pos.j=(uint16_t)(e->pos.j-cases[k].dj);
        a->orientation=cases[k].facing;
        /* No preceding collision query: direction cannot depend on one. */
        on_hit_default(e,a);
        assert(e->life==6 && e->invulnerable_frames==60 && e->push_frames==6);
        assert(e->push_vector.i==cases[k].vi && e->push_vector.j==cases[k].vj);
    }
    Entity *e=reset(),*a=&state.entities[0];
    a->damage=0;on_hit_default(e,a);assert(e->life==8 && !e->push_frames);
    a->damage=255;on_hit_default(e,a);assert(!e->life && e->push_frames==6);
    e->invulnerable_frames=0;e->push_frames=2;
    on_hit_default(e,a);assert(!e->life && e->push_frames==2);
}
static void slide(unsigned batch,unsigned wall) {
    Entity *e=reset(),*a=&state.entities[0];
    a->pos.j-=64;on_hit_default(e,a);wall_at=wall;
    for(unsigned tick=0;tick<6;tick+=batch) {
        state.isr_count_delta=batch;
        assert(combat_update(4)==COMBAT_STUNNED);
        assert(e->push_frames==6-tick-batch);
        assert(e->invulnerable_frames==60-tick-batch);
        assert(sprites[4].enabled==!(e->invulnerable_frames&4));
        assert(sprites[4].pos.i==e->pos.i && sprites[4].pos.j==e->pos.j);
        /* Persistent contact neither refreshes stun nor changes direction. */
        a->pos.j=e->pos.j+64;on_hit_default(e,a);
        assert(e->life==6 && e->push_frames==6-tick-batch);
    }
    assert(e->pos.i==10000 && e->pos.j==12000+(wall?wall-1:18)*32);
    assert(queries==(wall?wall:18));
    state.isr_count_delta=3;assert(combat_update(4)==COMBAT_READY);
    assert(!e->push_frames && queries==(wall?wall:18));
    printf("slide batch=%u wall=%u position=%u,%u immunity=%u queries=%u\n",
        batch,wall,e->pos.i,e->pos.j,e->invulnerable_frames,queries);
}
static void timing_and_edges(void) {
    Entity *e=reset();state.isr_count_delta=3;
    assert(combat_update(4)==COMBAT_READY && !sprites[4].enabled && !queries);
    on_hit_default(e,&state.entities[0]);
    state.isr_count_delta=0;
    assert(combat_update(4)==COMBAT_STUNNED && e->push_frames==6 && !queries);
    e->push_frames=1;e->invulnerable_frames=1;state.isr_count_delta=3;
    assert(combat_update(4)==COMBAT_STUNNED && !e->push_frames && !e->invulnerable_frames);
    assert(e->pos.i==10096 && queries==3 && sprites[4].enabled);
    assert(combat_update(4)==COMBAT_READY && queries==3);
    e=reset();on_hit_default(e,&state.entities[0]);state.isr_count_delta=255;
    assert(combat_update(4)==COMBAT_STUNNED && !e->push_frames && !e->invulnerable_frames);
    assert(queries==18 && e->pos.i==10576);
    e=reset();e->pos.j=65520;e->push_vector.j=32;e->push_frames=6;state.isr_count_delta=1;
    assert(combat_update(4)==COMBAT_STUNNED && !queries && e->pos.j==65520 && !e->push_vector.j);
    e=reset();e->pos.i=0;e->push_vector.i=-32;e->push_frames=6;state.isr_count_delta=1;
    assert(combat_update(4)==COMBAT_STUNNED && !queries && !e->pos.i && !e->push_vector.i);
    e=reset();e->pos.i=32304;e->push_vector.i=32;e->push_frames=6;state.isr_count_delta=1;
    assert(combat_update(4)==COMBAT_STUNNED && !queries && e->pos.i==32304 && !e->push_vector.i);
    e=reset();e->pos.j=65168;e->push_vector.j=32;e->push_frames=6;state.isr_count_delta=1;
    assert(combat_update(4)==COMBAT_STUNNED && !queries && e->pos.j==65168 && !e->push_vector.j);
}
static void death(unsigned busy,bool full,bool nested) {
    Entity *e=reset();e->life=0;e->push_frames=6;e->push_vector.i=32;
    e->anchor8.i=20;e->anchor8.j=30;death_position=e->pos;
    state.isr_count_delta=3;pool_full=full;reenter=nested;
    if(busy&1)state.entities[ENTITY_EXPLOSION_0].spawn_idx=6;
    if(busy&2)state.entities[ENTITY_EXPLOSION_1].spawn_idx=7;
    if(busy&4)state.entities[ENTITY_DROP_ITEM_0].spawn_idx=8;
    if(busy&8)state.entities[ENTITY_DROP_ITEM_1].spawn_idx=9;
    /* A bomb slot has no bearing on the second explosion slot. */
    state.entities[ENTITY_BOMB_1].spawn_idx=5;
    assert(combat_update(4)==COMBAT_DEAD && !queries);
    unsigned n=0;
    if((busy&3)!=3)assert(spawned[n++]==(busy&1?ENTITY_EXPLOSION_1:ENTITY_EXPLOSION_0));
    if((busy&12)!=12)assert(spawned[n++]==(busy&4?ENTITY_DROP_ITEM_1:ENTITY_DROP_ITEM_0));
    assert(spawn_count==n && e->life==8 && e->pos.i==5120 && e->pos.j==7680);
    assert(!e->push_frames && !e->invulnerable_frames && !e->push_vector.i && !e->push_vector.j);
    assert(!sprites[4].enabled);
    /* The scheduler consumes COMBAT_DEAD by despawning before another call. */
}
int main(void) {
    directions();
    for(unsigned batch=1;batch<=3;++batch) { slide(batch,0);slide(batch,4); }
    timing_and_edges();
    for(unsigned busy=0;busy<16;++busy)death(busy,false,false);
    death(0,true,false);
    death(0,false,true);
    puts("combat: cardinal hits, rejected repeats, 18-pixel slide, walls, saturated timers and death effects passed");
}
