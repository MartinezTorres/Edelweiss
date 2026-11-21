/* Editable NEO-8 window B module. Keep the generated ABI. */
#include "vexel.h"
void vxi_vx_world_well(VX_STABLE uint8_t vxp_a0) VX_ABI {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 42UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 43UL : (((uint32_t)(vxp_a0) < (uint32_t)(5UL)) ? 44UL : 0UL))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 45UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 46UL : (((uint32_t)(vxp_a0) < (uint32_t)(5UL)) ? 46UL : 0UL))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 2UL : (((uint32_t)(vxp_a0) < (uint32_t)(5UL)) ? (((uint32_t)(vxp_a0) + (uint32_t)(1UL)) & 255UL) : vxp_a0))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
