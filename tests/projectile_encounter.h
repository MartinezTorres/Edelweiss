/* Included in each real projectile bank, outside the timed encounter. */
#include "encounter.h"
void EDW_PROJECTILE_TEST(void) {
    static const uint8_t elapsed[]={0,1,2,3,255},counters[]={0,3,254,255};
#if !EDW_VEXEL && !EDW_PROJECTILE_TEST_KIND
    static const TSpriteInterlaced *const frames[]={&weapon_arrow_0_0,&weapon_arrow_1_0,&weapon_arrow_2_0,&weapon_arrow_3_0};
#endif
#if !EDW_VEXEL && EDW_PROJECTILE_TEST_KIND
    static const TSpriteInterlaced *const frames[]={&weapon_fire_0_0,&weapon_fire_1_0,&weapon_fire_2_0,&weapon_fire_3_0};
#endif
    Entity *e=&state.entities[ENTITY_PROJECTILE_0],*p=&state.entities[0];
    uint8_t d,k,t,n,old,expected_frame;
    uint16_t i,j;
    int8_t vi,vj;
    for(d=0;d<5;++d) {
        p->pos.i=65530;p->pos.j=7;p->orientation=d;
        EDW_PROJECTILE_TEST_INIT(ENTITY_PROJECTILE_0);e->spawn_idx=1;
        e->pos.i=33;e->pos.j=44;e->animation_counter=251;on_spawn(e);
        vi=d==E_UP?-(EDW_PROJECTILE_TEST_KIND?127:96):((d==E_LEFT || d==E_RIGHT)?0:(EDW_PROJECTILE_TEST_KIND?127:96));
        vj=d==E_LEFT?-(EDW_PROJECTILE_TEST_KIND?127:96):(d==E_RIGHT?(EDW_PROJECTILE_TEST_KIND?127:96):0);
        if(e->damage!=2 || e->vel.i!=vi || e->vel.j!=vj || e->pos.i!=(uint16_t)(65530u+vi*3) ||
           e->pos.j!=(uint16_t)(7+vj*3) || !sprites[1].enabled)return;
        if(sprites[1].pos.i!=(EDW_PROJECTILE_TEST_KIND?33:e->pos.i) ||
           sprites[1].pos.j!=(EDW_PROJECTILE_TEST_KIND?44:e->pos.j))return;
        for(t=0;t<4;++t)for(k=0;k<5;++k) {
            e->pos.i=65530;e->pos.j=7;e->animation_counter=counters[t];
            sprites[1].spriteInfo=nullptr;sprites[1].resourceRequest=0;
            old=e->animation_counter;i=e->pos.i;j=e->pos.j;
            for(n=0;n<elapsed[k];++n) {i+=vi;j+=vj;}
            state.isr_count_delta=elapsed[k];
            if(!on_update(e) || e->pos.i!=i || e->pos.j!=j || sprites[1].pos.i!=i || sprites[1].pos.j!=j ||
               e->animation_counter!=(EDW_PROJECTILE_TEST_KIND?(uint8_t)(old+elapsed[k]):old))return;
            if(EDW_PROJECTILE_TEST_KIND && elapsed[k]) {
                expected_frame=((uint8_t)(old+elapsed[k]-1)>>2)&3;
#if EDW_VEXEL
                if(sprites[1].resourceRequest!=edw_fire_sprite(expected_frame) || sprites[1].spriteInfo)return;
#else
                if(sprites[1].spriteInfo!=frames[expected_frame])return;
#endif
            } else if(sprites[1].spriteInfo || sprites[1].resourceRequest)return;
        }
        on_despawn(e);
        if(e->spawn_auto || sprites[1].enabled)return;
#if EDW_VEXEL
        if(sprites[1].spriteInfo || sprites[1].resourceRequest)return;
#endif
    }
    e->spawn_idx=-1;edw_projectile_checks|=EDW_PROJECTILE_TEST_KIND?2:1;
}
