#include "encounter.h"
void EDW_EFFECT_TEST(void) {
    static const uint8_t counters[]={0,5,6,17,23,24,250,255},elapsed[]={0,1,2,3,255};
    Entity *e=&state.entities[ENTITY_ENEMY_PROJECTILE_0];
    uint8_t kind,c,t,n,count,frame,live,actual;
#if !EDW_VEXEL
    static const TSpriteInterlaced *const frames[]={
#if EDW_EFFECT_SPARK
#define S(n) &spark_##n##_0,&spark_##n##_1,&spark_##n##_2
        S(0),S(1),S(2),S(3)
#undef S
#else
        &explosion_0_0,&explosion_1_0,&explosion_2_0,&explosion_3_0
#endif
    };
#endif
    for(kind=0;kind<(EDW_EFFECT_SPARK?3:1);++kind)for(c=0;c<8;++c)for(t=0;t<5;++t) {
        EDW_EFFECT_INIT(ENTITY_ENEMY_PROJECTILE_0);e->spawn_idx=1;e->spark_type=kind;on_spawn(e);
        count=counters[c];e->animation_counter=count;frame=255;live=1;
        sprites[1].spriteInfo=nullptr;sprites[1].resourceRequest=0;
        for(n=0;n<elapsed[t];++n) {
            if(count==6)frame=1;if(count==12)frame=2;if(count==18)frame=3;
            if(count==24){live=0;break;}++count;
        }
        state.isr_count_delta=elapsed[t];actual=on_update(e);
        if(actual!=live || e->animation_counter!=count)return;
        if(frame!=255)frame=EDW_EFFECT_SPARK?(uint8_t)(frame*3+kind):frame;
#if EDW_VEXEL
        if(sprites[1].spriteInfo || sprites[1].resourceRequest!=(frame==255?0:EDW_EFFECT_FIRST+frame))return;
#else
        if(sprites[1].spriteInfo!=(frame==255?NULL:frames[frame]))return;
#endif
        on_despawn(e);if(sprites[1].enabled)return;
    }
    e->spawn_idx=-1;edw_actor_checks|=EDW_EFFECT_SPARK?1:2;
}
