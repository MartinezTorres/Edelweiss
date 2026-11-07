#include "vexel.h"
void vx_flow_0(uint32_t *vxo, VX_STABLE uint16_t vxa_0, VX_STABLE uint16_t vxa_1, VX_STABLE int8_t vxa_2, VX_STABLE uint16_t vxa_3) VX_ABI VX_RESIDENT {
    (void)(vx_signed(vx_shift(vx_signed(((uint32_t)(vx_signed((((uint32_t)(vxa_1) - (uint32_t)(vxa_0)) & 65535UL), 16)) + (uint32_t)(((vx_signed(vx_signed((((uint32_t)(vxa_1) - (uint32_t)(vxa_0)) & 65535UL), 16), 16) < vx_signed(0UL, 16)) ? 511UL : 0UL))), 16), 9UL, 16, 1, 1), 16));
    vxo[0] = vx_signed(((uint32_t)(vx_signed(((uint32_t)(vxa_2) + (uint32_t)(vx_signed(vx_signed(vx_shift(vx_signed(((uint32_t)(vx_signed((((uint32_t)(vxa_1) - (uint32_t)(vxa_0)) & 65535UL), 16)) + (uint32_t)(((vx_signed(vx_signed((((uint32_t)(vxa_1) - (uint32_t)(vxa_0)) & 65535UL), 16), 16) < vx_signed(0UL, 16)) ? 511UL : 0UL))), 16), 9UL, 16, 1, 1), 16), 8))), 8)) + (uint32_t)((((uint32_t)(vxa_3) < (uint32_t)(vxa_0)) ? -1UL : 1UL))), 8);
}
void vx_ghost_spawn(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    VX_STABLE uint32_t vxo_0 = (uint32_t)((((uint32_t)(vxp_a0) - (uint32_t)(256UL)) & 65535UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT32(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_0))) >> 8);
    VX_STABLE uint32_t vxo_1 = (uint32_t)((((uint32_t)(vxp_a1) - (uint32_t)(512UL)) & 65535UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT32(vxo_1));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_1))) >> 8);
    VX_STABLE uint32_t vxo_2 = (uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? vx_signed(((uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) ? -1UL : 1UL)) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) ? -1UL : 1UL))), 8) : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) ? -1UL : 1UL)));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT32(vxo_2));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_2))) >> 8);
    VX_STABLE uint32_t vxo_3 = (uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(8UL)) & 255UL)) != (uint32_t)(0UL)) ? vx_signed(((uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? -2UL : 2UL)) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? -2UL : 2UL))), 8) : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? -2UL : 2UL)));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT32(vxo_3));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_3))) >> 8);
}
uint32_t vx_ghost_spawn_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_signed((uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8), 16);
    case 3: return (uint32_t)vx_signed((uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8), 16);
    default: vx_trap(16); return 0;
    }
}
void vx_ghost_tick(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI VX_RESIDENT {
    VX_STABLE uint32_t vxo_0 = (uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(vxp_a1)) & 255UL)) & (uint32_t)(3UL)) & 255UL)) == (uint32_t)(0UL)) ? 1UL : 0UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT32(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_0))) >> 8);
    VX_STABLE uint32_t vxo_1 = (uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(vxp_a1)) & 255UL)) & (uint32_t)(3UL)) & 255UL)) == (uint32_t)(0UL)) ? vxp_a3 : vxp_a2));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT32(vxo_1));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_1))) >> 8);
}
uint32_t vx_ghost_tick_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_ghost_axis(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE int8_t vxp_a2,VX_STABLE uint16_t vxp_a3) VX_ABI VX_RESIDENT {
    uint32_t vxt_0[1];
    vx_flow_0(vxt_0, vxp_a0, vxp_a1, vxp_a2, vxp_a3);
    VX_STABLE uint32_t vxo_0 = (uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_0[0]))) & 65535UL))) & 65535UL)) + (uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_0[0]))) & 65535UL))) & 65535UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT32(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_0))) >> 8);
    VX_STABLE uint32_t vxo_1 = (uint32_t)(VX_SNAPSHOT32(vxt_0[0]));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT32(vxo_1));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_1))) >> 8);
}
uint32_t vx_ghost_axis_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_signed((uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8), 16);
    default: vx_trap(16); return 0;
    }
}
void vx_ghost_frame(VX_STABLE uint8_t vxp_a0,VX_STABLE int8_t vxp_a1) VX_ABI VX_RESIDENT {
    VX_STABLE uint32_t vxo_0 = (uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(7UL)) & 255UL)) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(7UL)) & 255UL)) == (uint32_t)(1UL)) ? 2UL : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(7UL)) & 255UL)) == (uint32_t)(3UL)) ? 6UL : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(7UL)) & 255UL)) < (uint32_t)(6UL)) ? 4UL : 10UL))))) + (uint32_t)(((vx_signed(vxp_a1, 8) > vx_signed(0UL, 8)) ? 0UL : 1UL))) & 255UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT32(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_0))) >> 8);
}
uint32_t vx_ghost_frame_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
