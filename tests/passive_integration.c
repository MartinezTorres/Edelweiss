/* Actual fairy/lumberjack callbacks, with only engine interaction sinks stubbed. */
#include <common.h>
#include <gameplay/quest.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "vx_sprite_assets.h"
#include "entities/fairy/entity_fairy_sprite.h"
#include "entities/npcs/entity_npcs_sprites.h"
TSpriteStatus sprites[12];
static unsigned collisions;
bool collision_wolfi_d(uint8_t slot) {(void)slot;++collisions;return false;}
void on_hit_null(Entity *a,Entity *b) {(void)a;(void)b;}
void on_hit_default(Entity *a,Entity *b) {(void)a;(void)b;}
void large_message(const char *s) {(void)s;assert(0);}
void quest_interact(uint8_t event) {(void)event;assert(0);}
static const int8_t wave[]={0,12,23,35,46,57,67,76,85,93,100,106,111,115,118,119,
    120,119,118,115,111,106,100,93,85,76,67,57,46,35,23,12,
    0,-12,-23,-35,-46,-57,-67,-76,-85,-93,-100,-106,-111,-115,-118,-119,
    -120,-119,-118,-115,-111,-106,-100,-93,-85,-76,-67,-57,-46,-35,-23,-12};
static void clear(void) {
    memset(&state,0,sizeof(state));memset(state.spawns,-1,sizeof(state.spawns));
    memset(sprites,0,sizeof(sprites));collisions=0;
}
int main(void) {
    static const uint8_t anchors[]={0,1,127,255},directions[]={E_REST,E_LEFT,E_RIGHT,E_UP,E_DOWN,255};
    static const uint8_t previous[]={0,E_LEFT,E_RIGHT,255},counters[]={0,3,4,7,8,255};
    static const TSpriteInterlaced *const frames[]={&npcs_0_0,&npcs_0_1,&npcs_0_2,&npcs_0_3};
    unsigned side,a,clock,d,p,c,follow;
    for(side=0;side<2;++side)for(a=0;a<sizeof(anchors);++a) {
        Entity *e;
        uint8_t id=side?ENTITY_FAIRY_BOTTOM:ENTITY_FAIRY_TOP;
        clear();init_fairy();e=&state.entities[id];e->anchor8.i=anchors[a];e->pos.j=65535;
        assert(spawn_entity(id));
#if EDW_VEXEL
        assert(!sprites[2].spriteInfo && sprites[2].resourceRequest==edw_fairy_sprite(side));
#else
        assert(sprites[2].spriteInfo==(side?&fairy_1_0:&fairy_0_0));
#endif
        for(clock=0;clock<256;++clock) {
            uint16_t expected=(uint16_t)(((uint16_t)anchors[a]<<8)+wave[(clock>>1)&63]);
            state.isr_count=clock;assert(e->callbacks->on_update(e));
            assert(e->pos.i==expected && e->pos.j==65535);
            assert(sprites[2].pos.i==expected && sprites[2].pos.j==65535);
        }
        despawn_entity(id);assert(!sprites[2].enabled && e->spawn_idx==-1);
#if EDW_VEXEL
        assert(!sprites[2].resourceRequest && !sprites[2].spriteInfo);
#endif
    }
    for(follow=0;follow<2;++follow)for(d=0;d<sizeof(directions);++d)
    for(p=0;p<sizeof(previous);++p)for(c=0;c<sizeof(counters);++c) {
        Entity *e;uint8_t facing=previous[p],frame=255;
        clear();init_lumberjack(1,2,3);e=&state.entities[1];assert(spawn_entity(1));
#if EDW_VEXEL
        assert(!sprites[4].spriteInfo && sprites[4].resourceRequest==edw_lumberjack_sprite(0));
#else
        assert(sprites[4].spriteInfo==frames[0]);
#endif
        e->is_following=follow;e->orientation=directions[d];e->selected_orientation=facing;
        state.entities[0].animation_counter=counters[c];state.follower_entity_spawn_idx=4;
        /* Keep the spawn's frame pending: invalid facing must preserve it. */
        collisions=0;
        if(follow) {
            if(directions[d]==E_LEFT || directions[d]==E_RIGHT)facing=directions[d];
            if(facing==E_LEFT || facing==E_RIGHT)frame=(facing==E_LEFT?0:2)+(counters[c]&4?0:1);
        }
        assert(e->callbacks->on_update(e));
        assert(e->selected_orientation==facing && collisions==!follow);
#if EDW_VEXEL
        assert(!sprites[4].spriteInfo && sprites[4].resourceRequest==edw_lumberjack_sprite(frame==255?0:frame));
#else
        assert(sprites[4].spriteInfo==frames[frame==255?0:frame]);
#endif
        despawn_entity(1);assert(!sprites[4].enabled && !e->is_following);
        if(follow)assert(!e->spawn_auto && !state.follower_entity_spawn_idx);
#if EDW_VEXEL
        assert(!sprites[4].resourceRequest && !sprites[4].spriteInfo);
#endif
    }
    puts("passive actors: all fairy clock phases, position wrap, follower facing, frame retention and lifecycle agree");
}
