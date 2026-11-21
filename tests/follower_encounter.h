#include "encounter.h"
void encounter_follower(void) {
    static const uint8_t directions[]={0,E_LEFT,E_RIGHT,E_UP,E_DOWN,255},previous[]={0,E_LEFT,E_RIGHT,255};
#if !EDW_VEXEL
    static const TSpriteInterlaced *const frames[]={&npcs_0_0,&npcs_0_1,&npcs_0_2,&npcs_0_3};
#endif
    Entity *e=&state.entities[ENTITY_LUMBERJACK];
    uint8_t d,p,c,facing,frame;
    for(d=0;d<6;++d)for(p=0;p<4;++p)for(c=0;c<2;++c) {
        init_lumberjack(ENTITY_LUMBERJACK,0,0);e->spawn_idx=4;on_spawn(e);
        e->is_following=true;e->orientation=directions[d];e->selected_orientation=previous[p];
        state.entities[0].animation_counter=c?4:0;state.follower_entity_spawn_idx=4;
        sprites[4].spriteInfo=nullptr;sprites[4].resourceRequest=0;
        facing=previous[p];frame=255;
        if(directions[d]==E_LEFT || directions[d]==E_RIGHT)facing=directions[d];
        if(facing==E_LEFT || facing==E_RIGHT)frame=(facing==E_LEFT?0:2)+(c?0:1);
        if(!on_update(e) || e->selected_orientation!=facing)return;
#if EDW_VEXEL
        if(sprites[4].spriteInfo || sprites[4].resourceRequest!=edw_lumberjack_sprite(frame))return;
#else
        if(sprites[4].spriteInfo!=(frame==255?NULL:frames[frame]))return;
#endif
        on_despawn(e);
        if(sprites[4].enabled || e->is_following || e->spawn_auto || state.follower_entity_spawn_idx)return;
#if EDW_VEXEL
        if(sprites[4].resourceRequest || sprites[4].spriteInfo)return;
#endif
    }
    e->spawn_idx=-1;edw_actor_checks|=128;
}
