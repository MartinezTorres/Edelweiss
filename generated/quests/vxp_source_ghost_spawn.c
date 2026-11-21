/* Editable NEO-8 window B module. Keep the generated ABI. */
#include "vexel.h"
void vxi_vx_ghost_spawn(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) - (uint32_t)(256UL)) & 65535UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) - (uint32_t)(512UL)) & 65535UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? vx_signed(((uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) ? -1UL : 1UL)) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) ? -1UL : 1UL))), 8) : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) ? -1UL : 1UL)));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(8UL)) & 255UL)) != (uint32_t)(0UL)) ? vx_signed(((uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? -2UL : 2UL)) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? -2UL : 2UL))), 8) : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? -2UL : 2UL)));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
