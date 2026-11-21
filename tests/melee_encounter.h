/* Executed inside the real melee bank after the timed encounter. The legacy
 * tables are an independent oracle for the Vexel arithmetic and frame rules. */
#include "encounter.h"
void encounter_melee(void) {
    static const uint8_t weapons[]={E_PAW,E_CLAW,E_SWORD,E_AXE,E_BUTTER_KNIFE};
    static const uint8_t damage[]={1,4,8,2,16},elapsed[]={0,1,2,255};
    static const int16_t offset[5][5][2]={
        {{192,333},{333,192},{384,0},{333,-192},{192,-333}},
        {{333,-192},{192,-333},{0,-384},{-192,-333},{-333,-192}},
        {{-333,192},{-192,333},{0,384},{192,333},{333,192}},
        {{-192,-333},{-333,-192},{-384,0},{-333,192},{-192,333}},
        {{192,333},{333,192},{384,0},{333,-192},{192,-333}}};
    static const uint8_t frames[5][5]={{5,7,11,10,9},{10,9,8,6,4},{1,2,3,5,7},{6,4,0,1,2},{5,7,11,10,9}};
#if !EDW_VEXEL
#define SLASH_FRAMES(s) &weapon_slash_##s##_0_0,&weapon_slash_##s##_0_1,&weapon_slash_##s##_0_2,&weapon_slash_##s##_0_3, \
    &weapon_slash_##s##_1_0,&weapon_slash_##s##_1_3,&weapon_slash_##s##_2_0,&weapon_slash_##s##_2_3, \
    &weapon_slash_##s##_3_0,&weapon_slash_##s##_3_1,&weapon_slash_##s##_3_2,&weapon_slash_##s##_3_3
    static const TSpriteInterlaced *const assets[]={SLASH_FRAMES(small),SLASH_FRAMES(large)};
#endif
    Entity *e=&state.entities[ENTITY_SLASH],*p=&state.entities[0];
    uint8_t w,d,t,k,spent,next,stage,live;
    uint16_t ei,ej;
    edw_melee_checks=0;state.spawns[1]=ENTITY_SLASH;
    for(w=0;w<5;++w)for(d=0;d<5;++d) {
        init_weapon_slash(ENTITY_SLASH,weapons[w]);e->spawn_idx=1;p->orientation=d;
        p->pos.i=103u*256;p->pos.j=16u*256;
        IN_MODULE(overworld,PAGE_B,on_spawn(e));
        if(e->damage!=damage[w] || !sprites[1].enabled || e->animation_counter ||
           sprites[1].overrideColors!=(w>=2))return;
        if(w>=2 && (sprites[1].pattern0Color!=(w==2?BGray:(w==3?BDarkRed:BWhite)) ||
                    sprites[1].pattern1Color!=(w==2?BLightBlue:(w==3?BDarkBlue:BLightYellow))))return;
        ei=p->pos.i;ej=p->pos.j;spent=w==0?160:192;
        if(d==E_UP)ei-=spent;else if(d==E_DOWN)ei+=spent;else if(d==E_LEFT)ej-=spent;else ej+=spent;
        if(e->pos.i!=ei || e->pos.j!=ej)return;
        for(t=0;t<20;++t)for(k=0;k<4;++k) {
            /* Unsigned wrapping and every animation/tick boundary on Z80. */
            p->pos.i=t&1?65535:0;p->pos.j=t&2?65535:0;
            e->animation_counter=t;e->pos.i=5;e->pos.j=65530;
            sprites[1].pos.i=13;sprites[1].pos.j=17;
            sprites[1].resourceRequest=0;sprites[1].spriteInfo=nullptr;
            state.isr_count_delta=elapsed[k];live=on_update(e);
            spent=elapsed[k]<20-t?elapsed[k]:20-t;next=t+spent;
            if(live!=(next<20) || e->animation_counter!=next)return;
            ei=5;ej=65530;
            if(spent) {
                stage=(next-1)>>2;ei=p->pos.i+offset[d][stage][0];ej=p->pos.j+offset[d][stage][1];
#if EDW_VEXEL
                if(sprites[1].spriteInfo || sprites[1].resourceRequest!=(w==0?
                    edw_melee_small_sprite(frames[d][stage]):edw_melee_large_sprite(frames[d][stage])))return;
#else
                if(sprites[1].spriteInfo!=assets[(w==0?0:12)+frames[d][stage]])return;
#endif
            } else if(sprites[1].spriteInfo || sprites[1].resourceRequest)return;
            if(e->pos.i!=ei || e->pos.j!=ej || sprites[1].pos.i!=(live?ei:13) || sprites[1].pos.j!=(live?ej:17))return;
        }
        on_despawn(e);
        if(e->spawn_auto || sprites[1].enabled)return;
#if EDW_VEXEL
        if(sprites[1].spriteInfo || sprites[1].resourceRequest)return;
#endif
    }
    e->spawn_idx=-1;state.spawns[1]=-1;edw_melee_checks=15;
}
