/* Editable NEO-8 window B module. Keep the generated ABI. */
#include "vexel.h"
void vxi_vx_melee_axe(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint16_t vxp_a2) VX_ABI {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a1) + (uint32_t)(256UL)) & 65535UL)) + (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 65152UL : ((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 1UL : ((uint32_t)(vxp_a0) == (uint32_t)(2UL))) ? 0UL : 384UL)))) & 65535UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)(256UL)) & 65535UL)) + (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 65152UL : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 384UL : 0UL)))) & 65535UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
