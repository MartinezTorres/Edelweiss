#include <common.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#if EDW_VEXEL
#include "vexel.h"
uint8_t vx_payload[20];
void vx_trap(uint8_t reason) { (void)reason;assert(0); }
#endif
TSpriteStatus sprites[12];
const TSpriteInterlaced drop_items_0_0={0},drop_items_1_0={0},drop_items_2_0={0},drop_items_3_0={0};
static uint16_t random_value;
static unsigned draws,collisions;
static bool touching;
static void release_result(void) {
#if EDW_VEXEL
    memset(vx_payload,0xA5,sizeof(vx_payload));
#endif
}
uint16_t rand16(void) { ++draws;release_result();return random_value; }
bool collision_wolfi_d(uint8_t slot) { assert(slot==4);++collisions;release_result();return touching; }
void on_hit_null(Entity *a,Entity *b) { (void)a;(void)b; }
static Entity *reset(uint8_t probability,uint8_t item,uint16_t roll) {
    Entity *e=&state.entities[ENTITY_DROP_ITEM_0];
    memset(&state,0,sizeof(state));memset(state.spawns,-1,sizeof(state.spawns));
    memset(sprites,0,sizeof(sprites));init_drop_item(ENTITY_DROP_ITEM_0);
    e->drop_probability=probability;e->drop_item=item;
    state.entities[0].life=3;state.entities[0].maximum_life=6;
    random_value=roll;draws=collisions=0;touching=false;
    return e;
}
int main(void) {
    static const uint8_t thresholds[3][4]={{8,24,56,72},{32,64,96,128},{64,128,160,192}};
    unsigned p,k,side;
    Entity *e;
    for(p=1;p<=3;++p) for(k=0;k<4;++k) for(side=0;side<2;++side) {
        uint8_t roll=thresholds[p-1][k]-1+side;
        e=reset(p,0,0xAB00u|roll);assert(spawn_entity(ENTITY_DROP_ITEM_0));
        assert(draws==1 && e->drop_item==4-k-side);
        printf("drop p=%u low-byte=%u item=%u\n",p,roll,e->drop_item);
    }
    e=reset(0,E_DROP_20_RUPEES,0);assert(spawn_entity(ENTITY_DROP_ITEM_0));
    assert(!draws && e->drop_item==E_DROP_20_RUPEES);
    e=reset(255,E_DROP_HEART,0);assert(spawn_entity(ENTITY_DROP_ITEM_0));
    assert(!draws && e->drop_item==E_DROP_HEART);
    e=reset(3,0,65535);assert(spawn_entity(ENTITY_DROP_ITEM_0));
    assert(draws==1 && !e->drop_item && !collisions && !sprites[4].enabled);
    for(k=1;k<=4;++k) {
        static const uint8_t credit[]={0,0,1,5,20};
        e=reset(0,k,0);state.rupees=10;state.entities[0].life=5;touching=true;
        /* The actual spawn helper calls on_update and ignores its return.
         * A second update must remove the consumed item without paying twice. */
        assert(spawn_entity(ENTITY_DROP_ITEM_0));
        assert(e->drop_item==E_DROP_NOTHING && !draws);
        assert(state.rupees==10+credit[k] && state.entities[0].life==(k==1?6:5));
        assert(!e->callbacks->on_update(e));
        assert(state.rupees==10+credit[k] && collisions==1);
        despawn_entity(ENTITY_DROP_ITEM_0);assert(!sprites[4].enabled && e->spawn_idx==-1);
    }
    e=reset(0,E_DROP_20_RUPEES,0);touching=true;state.rupees=65530;
    assert(spawn_entity(ENTITY_DROP_ITEM_0));assert(state.rupees==14); /* Existing u16 arithmetic. */
    e=reset(0,E_DROP_HEART,0);assert(spawn_entity(ENTITY_DROP_ITEM_0));
    state.isr_count_delta=1;assert(e->callbacks->on_update(e) && !sprites[4].enabled);
    e->animation_counter=13;state.isr_count_delta=2;
    assert(e->callbacks->on_update(e) && sprites[4].enabled && e->animation_counter==15);
    e->animation_counter=179;assert(e->callbacks->on_update(e) && !sprites[4].enabled);
    e->animation_counter=183;assert(e->callbacks->on_update(e) && sprites[4].enabled);
    e->animation_counter=239;touching=true;collisions=0;
    assert(!e->callbacks->on_update(e) && !collisions && state.entities[0].life==3);
    puts("drops: distribution boundaries, explicit draws, rewards, single consumption and lifetime passed");
    return 0;
}
