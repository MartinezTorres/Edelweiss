#include "vx_bind_title_step.h"
#include "vx_bind_title_seed.h"
#include "vx_bind_title_frame.h"
#include "native_world.inc"
#include "vx_bind_title_flow.h"

#if !VX_BIND_title_flow_EXPANDED_flow_slot
VX_BIND_title_flow_BOUNDARY_flow_slot {EDW_NATIVE_FLOW_SLOT(VX_BIND_title_flow_DATA_flow_slot);}
#endif
VX_BIND_title_flow_BOUNDARY_flow_update {
    VX_BIND_title_flow_DATA_flow_update.r0=world_call_update(&state.entities[VX_BIND_title_flow_DATA_flow_update.a0]);
}
VX_BIND_title_flow_BOUNDARY_flow_despawn {
    despawn_entity(VX_BIND_title_flow_DATA_flow_despawn.a0);VX_BIND_title_flow_DATA_flow_despawn.r0=0;
}

static uint8_t title_wait_frame(void) {
    uint8_t candidate;
    wait_frame();state.isr_count_delta=1;
    { VX_BIND_title_flow_LOCAL;vx_bind_title_flow_run(); }
    { uint8_t old=map.pos.j;map.pos.j=0;
      CALL_PAGE(sprites,PAGE_B,updateSpriteISR());map.pos.j=old; }
    { VX_BIND_title_frame_LOCAL;
      vx_bind_title_frame_frame.a0=state.isr_count;vx_bind_title_frame_frame.a1=255;
      vx_bind_title_frame_run();state.isr_count=vx_bind_title_frame_frame.result.v0;
      candidate=vx_bind_title_frame_frame.result.v1; }
    if(candidate!=255 && state.entities[candidate].spawn_auto)spawn_entity(candidate);
    update_keyboard_and_joystick();
    { VX_BIND_title_frame_LOCAL;
      vx_bind_title_frame_frame.a0=state.isr_count;vx_bind_title_frame_frame.a1=keyboard[8];
      vx_bind_title_frame_run();return vx_bind_title_frame_frame.result.v2; }
}

void title_routine(void) {
    uint8_t slot,axis,accept,kind;
    uint8_t phase=0,round=0,step=0,cancel=0,op,a,b;
    uint16_t position;
    msxhal_install_isr(nullptr);wait_frame();
    mapper_load_module(titlemap,PAGE_B);titlemap_init();
    CALL_PAGE(sprites,PAGE_B,sprites_init());
    TMS99X8.sprites16=true;TMS99X8_syncFlags();msxhal_install_isr(title_isr);
    memset(&state,0,sizeof(state));memset(state.spawns,-1,sizeof(state.spawns));
    for(slot=0;slot<96;++slot)state.entities[slot].spawn_idx=-1;
    for(slot=0;slot<12;++slot) {
        trampoline_page_c_uint8_t(MODULE_SEGMENT(entity_spark,PAGE_C),init_spark,slot);
        state.entities[slot].spawn_auto=false;state.entities[slot].spawn_priority=0;
        for(axis=0;axis<2;++axis) {
            do {
                VX_BIND_title_seed_LOCAL;
                vx_bind_title_seed_frame.a0=slot;vx_bind_title_seed_frame.a1=axis;
                vx_bind_title_seed_frame.a2=(uint8_t)rand16();vx_bind_title_seed_run();
                accept=vx_bind_title_seed_frame.result.v0;position=vx_bind_title_seed_frame.result.v1;
                kind=vx_bind_title_seed_frame.result.v2;
            } while(!accept);
            if(axis)state.entities[slot].pos.i=position;else state.entities[slot].pos.j=position;
        }
        state.entities[slot].spark_type=kind;
    }
    for(;;) {
        { VX_BIND_title_step_LOCAL;
          vx_bind_title_step_frame.a0=phase;vx_bind_title_step_frame.a1=round;
          vx_bind_title_step_frame.a2=step;vx_bind_title_step_frame.a3=cancel;vx_bind_title_step_run();
          op=vx_bind_title_step_frame.result.v0;a=vx_bind_title_step_frame.result.v1;b=vx_bind_title_step_frame.result.v2;
          phase=vx_bind_title_step_frame.result.v3;round=vx_bind_title_step_frame.result.v4;step=vx_bind_title_step_frame.result.v5; }
        /* Copy the complete command/continuation before any engine sink. */
        switch(op) {
        case 0:return;
        case 1:cancel=title_wait_frame();break;
        case 2:titlemap_draw_row(a);break;
        case 3:titlemap_draw_col(a);break;
        case 4:titlemap_copyPN1full();break;
        case 5:titlemap_copyPN0full();break;
        case 6:titlemap_free();break;
        case 7:titlemap_free0();break;
        case 8:titlemap_free1();break;
        case 9:titlemap_free2();break;
        case 10:map.pos.i=a;map.pos.j=b;break;
        case 11:TMS99X8.blankScreen=a;TMS99X8_syncAllRegisters();break;
        case 12:TMS99X8_setBorderColor(a);break;
        case 13:for(slot=0;slot<12;++slot)state.entities[slot].spawn_auto=true;break;
        case 14:titlemap_draw_tile8(a,b);break;
        case 15:configuration.attract_mode=a;break;
        }
    }
}
