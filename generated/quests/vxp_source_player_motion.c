/* Editable NEO-8 window B module. Keep the generated ABI. */
#include "vexel.h"
#include "vxf_vx_player_motion.h"
void vxi_vx_player_motion(VX_STABLE uint16_t vxp_a0_0,VX_STABLE uint16_t vxp_a0_1,VX_STABLE uint8_t vxp_a0_2,VX_STABLE uint8_t vxp_a0_3,VX_STABLE uint8_t vxp_a0_4,VX_STABLE uint8_t vxp_a0_5,VX_STABLE uint8_t vxp_a0_6) VX_ABI {
    struct vxf_vx_player_motion activation;
    struct vxf_vx_player_motion *frame = &activation;
    frame->vxp_a0_0 = vxp_a0_0;
    frame->vxp_a0_1 = vxp_a0_1;
    frame->vxp_a0_2 = vxp_a0_2;
    frame->vxp_a0_3 = vxp_a0_3;
    frame->vxp_a0_4 = vxp_a0_4;
    frame->vxp_a0_5 = vxp_a0_5;
    frame->vxp_a0_6 = vxp_a0_6;
    frame->pc = 408;
    while (frame->pc) {
        switch ((frame->pc - 1u) / 128u) {
        case 0: vx_chunk_vx_player_motion_0(frame); break;
        case 1: vx_chunk_vx_player_motion_1(frame); break;
        case 2: vx_chunk_vx_player_motion_2(frame); break;
        case 3: vx_chunk_vx_player_motion_3(frame); break;
        default: vx_trap(24); return;
        }
    }
}
