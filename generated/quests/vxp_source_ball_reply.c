/* Editable NEO-8 window B module. Keep the generated ABI. */
#include "vexel.h"
void vxi_vx_ball_reply(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint16_t vxp_a4,VX_STABLE uint16_t vxp_a5,VX_STABLE uint8_t vxp_a6,VX_STABLE uint8_t vxp_a7) VX_ABI {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? vxp_a4 : vxp_a2));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? vxp_a5 : vxp_a3));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 2UL : 1UL) : vxp_a6));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? 30UL : vxp_a7));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
