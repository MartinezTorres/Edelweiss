#include <common.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "vx_sprite_assets.h"
#include "entities/spark/entity_spark_sprite.h"
#include "entities/explosion/entity_explosion_sprite.h"
struct T_State state;
TSpriteStatus sprites[12];
void on_hit_null(Entity *a,Entity *b) {(void)a;(void)b;}
static const TSpriteInterlaced *const frames[]={
#define S(n) &spark_##n##_0,&spark_##n##_1,&spark_##n##_2
    S(0),S(1),S(2),S(3),&explosion_0_0,&explosion_1_0,&explosion_2_0,&explosion_3_0};
int main(void) {
    static const uint8_t counters[]={0,5,6,11,12,17,18,23,24,25,250,255},elapsed[]={0,1,2,3,6,24,255};
    unsigned kind,c,t;
    for(kind=0;kind<4;++kind)for(c=0;c<sizeof(counters);++c)for(t=0;t<sizeof(elapsed);++t) {
        Entity *e=&state.entities[ENTITY_ENEMY_PROJECTILE_0];
        uint8_t counter=counters[c],frame=255,live=1,n;
        int expected;
        memset(&state,0,sizeof(state));memset(sprites,0,sizeof(sprites));
        if(kind<3)init_spark(ENTITY_ENEMY_PROJECTILE_0);else init_explosion(ENTITY_ENEMY_PROJECTILE_0);
        e->spark_type=kind;e->spawn_idx=1;e->pos.i=234;e->pos.j=567;e->callbacks->on_spawn(e);
        assert(sprites[1].enabled && e->animation_counter==0);
        e->animation_counter=counter;state.isr_count_delta=elapsed[t];
        sprites[1].spriteInfo=nullptr;sprites[1].resourceRequest=0;
        for(n=0;n<elapsed[t];++n) {
            if(counter==6)frame=1;if(counter==12)frame=2;if(counter==18)frame=3;
            if(counter==24){live=0;break;}++counter;
        }
        assert(e->callbacks->on_update(e)==live && e->animation_counter==counter);
        expected=frame==255?-1:(kind<3?frame*3+kind:12+frame);
#if EDW_VEXEL
        assert(!sprites[1].spriteInfo && sprites[1].resourceRequest==(expected<0?0:EDW_SPARK_SPRITE_FIRST+expected));
#else
        assert(sprites[1].spriteInfo==(expected<0?NULL:frames[expected]));
#endif
        printf("%u %u %u -> %u %u %d\n",kind,counters[c],elapsed[t],live,counter,expected);
        e->callbacks->on_despawn(e);assert(!sprites[1].enabled);
#if EDW_VEXEL
        assert(!sprites[1].resourceRequest && !sprites[1].spriteInfo);
#endif
    }
    puts("effects: shared timeline, pending frames, wrap and expiration passed");
}
