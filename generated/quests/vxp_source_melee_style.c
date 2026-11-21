/* Editable NEO-8 window B module. Keep the generated ABI. */
#include "vexel.h"
void vxi_vx_melee_style(VX_STABLE uint8_t vxp_a0) VX_ABI {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 4UL : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 8UL : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 2UL : 16UL)))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a0) == (uint32_t)(1UL))) ? 0UL : 1UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 14UL : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 6UL : 15UL)));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 5UL : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 4UL : 11UL)));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 1UL : 0UL));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
