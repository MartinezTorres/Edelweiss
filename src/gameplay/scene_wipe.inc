/* Caller owns the overworld mapping. A step ends before every engine sink. */
#include "vx_bind_scene_wipe.h"
static void scene_wipe(uint8_t mode) {
    uint8_t round=0,step=0;
    for(;;) {
        uint8_t op,arg;
        VX_BIND_scene_wipe_LOCAL;
        vx_bind_scene_wipe_frame.a0=mode;vx_bind_scene_wipe_frame.a1=round;vx_bind_scene_wipe_frame.a2=step;
        vx_bind_scene_wipe_run();
        op=vx_bind_scene_wipe_frame.result.v0;arg=vx_bind_scene_wipe_frame.result.v1;
        round=vx_bind_scene_wipe_frame.result.v2;step=vx_bind_scene_wipe_frame.result.v3;
        switch(op) {
        case 0:return;
        case 1:if(mode==1){overworld_erase_row(arg);overworld_free();}else overworld_draw_row(arg);break;
        case 2:if(mode==1){overworld_erase_col(arg);overworld_free();}else overworld_draw_col(arg);break;
        case 3:wait_frame();break;
        case 4:state.request_pattern_name_transfer=true;break;
        case 5:overworld_copyPN1();break;
        case 6:overworld_copyPN0();break;
        case 7:overworld_free();break;
        }
    }
}
