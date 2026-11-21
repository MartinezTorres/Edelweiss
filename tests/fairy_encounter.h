#include "encounter.h"
void encounter_fairy(void) {
    static const int8_t wave[]={0,12,23,35,46,57,67,76,85,93,100,106,111,115,118,119,
        120,119,118,115,111,106,100,93,85,76,67,57,46,35,23,12,
        0,-12,-23,-35,-46,-57,-67,-76,-85,-93,-100,-106,-111,-115,-118,-119,
        -120,-119,-118,-115,-111,-106,-100,-93,-85,-76,-67,-57,-46,-35,-23,-12};
    Entity *e;uint8_t side,a,clock;uint16_t expected;
    init_fairy();
    for(side=0;side<2;++side)for(a=0;a<2;++a) {
        e=&state.entities[side?ENTITY_FAIRY_BOTTOM:ENTITY_FAIRY_TOP];
        e->anchor8.i=a?255:0;e->spawn_idx=2;e->pos.j=65535;
        if(side)on_spawn_bottom(e);else on_spawn_top(e);
#if EDW_VEXEL
        if(sprites[2].spriteInfo || sprites[2].resourceRequest!=edw_fairy_sprite(side))return;
#endif
        for(clock=0;clock<128;++clock) {
            state.isr_count=clock;
            expected=(uint16_t)(((uint16_t)e->anchor8.i<<8)+wave[(clock>>1)&63]);
            if(!(side?on_update_bottom(e):on_update_top(e)) || e->pos.i!=expected || e->pos.j!=65535 ||
               sprites[2].pos.i!=expected || sprites[2].pos.j!=65535)return;
        }
        on_despawn(e);if(sprites[2].enabled)return;
#if EDW_VEXEL
        if(sprites[2].resourceRequest || sprites[2].spriteInfo)return;
#endif
        e->spawn_idx=-1;
    }
    edw_actor_checks|=64;
}
