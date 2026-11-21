/* Editable NEO-8 window B module. Keep the generated ABI. */
#include "vexel.h"
void vxi_vx_world_window(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4) VX_ABI {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) - (uint32_t)(vxp_a3)) & 255UL)) + (uint32_t)(3UL)) & 255UL)) < (uint32_t)(30UL)) ? ((uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) - (uint32_t)(vxp_a4)) & 255UL)) + (uint32_t)(3UL)) & 255UL)) < (uint32_t)(38UL)) : 0UL) ? 1UL : 0UL) : ((((uint32_t)(((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) - (uint32_t)(vxp_a3)) & 255UL)) + (uint32_t)(3UL)) & 255UL)) < (uint32_t)(30UL)) ? ((uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) - (uint32_t)(vxp_a4)) & 255UL)) + (uint32_t)(3UL)) & 255UL)) < (uint32_t)(38UL)) : 0UL) ? 1UL : 0UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(vxp_a1) - (uint32_t)(vxp_a3)) & 255UL)) >= (uint32_t)(24UL)) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a2) - (uint32_t)(vxp_a4)) & 255UL)) >= (uint32_t)(32UL))) : 0UL) ? 1UL : 0UL)));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
