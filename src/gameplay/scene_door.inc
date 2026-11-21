#include "vx_bind_scene_door.h"
/* The script runs synchronously. Only its small continuation survives waits. */
static void scene_door(uint8_t exit) {
    uint8_t step=0;
    Entity *wolfi=&state.entities[0];
    if(exit)state.request_pattern_name_transfer=true;
    for(;;) {
        uint8_t op,waits;
        VX_BIND_scene_door_LOCAL;
        vx_bind_scene_door_frame.a0=exit;vx_bind_scene_door_frame.a1=step;
        vx_bind_scene_door_frame.a2=wolfi->pos.i;vx_bind_scene_door_frame.a3=wolfi->pos.j;
        vx_bind_scene_door_frame.a4=wolfi->animation_counter;vx_bind_scene_door_run();
        op=vx_bind_scene_door_frame.result.v0;waits=vx_bind_scene_door_frame.result.v5;
        if(!op)break;
        if(op==1) {
            wolfi->pos.j=vx_bind_scene_door_frame.result.v2;
            if(!exit)sprites[0].pos.j=wolfi->pos.j;
            wolfi->orientation=vx_bind_scene_door_frame.result.v3;
            player_sprite(0,vx_bind_scene_door_frame.result.v4);
            if(exit)sprites[0].enabled=true;
        } else {
            wolfi->pos.i=vx_bind_scene_door_frame.result.v1;sprites[0].pos.i=wolfi->pos.i;
            while(waits--)wait_frame();
        }
        ++step;
    }
    if(!exit)sprites[0].enabled=false;
}
