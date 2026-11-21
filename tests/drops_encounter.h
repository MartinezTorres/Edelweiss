#include "encounter.h"
void encounter_drops(void) {
    static const uint8_t counters[]={0,13,14,179,180,183,184,239,240,255},elapsed[]={0,1,2,3,255};
    Entity *e=&state.entities[ENTITY_DROP_ITEM_0];
    uint8_t c,t,n,count,visible,live;
    init_drop_item(ENTITY_DROP_ITEM_0);e->spawn_idx=4;e->drop_probability=E_DROP_PROBABILITY_SKIP;
    e->pos=state.entities[0].pos;e->pos.i+=1024;
    for(c=0;c<10;++c)for(t=0;t<5;++t) {
        e->drop_item=E_DROP_HEART;on_spawn(e);
        count=counters[c];e->animation_counter=count;state.isr_count_delta=elapsed[t];
        visible=8;live=1;sprites[4].enabled=(bool)visible;
        for(n=0;n<elapsed[t];++n) {
            if(count>=240){live=0;break;}
            visible=count<14?0:(count<180?1:count&8);++count;
        }
        if(on_update(e)!=live || e->animation_counter!=count || sprites[4].enabled!=visible)return;
#if EDW_VEXEL
        if(sprites[4].spriteInfo || sprites[4].resourceRequest!=edw_drop_sprite(0))return;
#endif
        on_despawn(e);if(sprites[4].enabled)return;
#if EDW_VEXEL
        if(sprites[4].resourceRequest || sprites[4].spriteInfo)return;
#endif
    }
    e->spawn_idx=-1;edw_actor_checks|=32;
}
