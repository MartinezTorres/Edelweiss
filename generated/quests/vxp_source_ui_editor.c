/* Editable NEO-8 window B module. Keep the generated ABI. */
#include "vexel.h"
void vxi_vx_ui_editor(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) + (uint32_t)((((((uint32_t)(vxp_a0) < (uint32_t)(10UL)) ? ((uint32_t)(vxp_a1) > (uint32_t)(32UL)) : 0UL) ? ((uint32_t)(vxp_a1) < (uint32_t)(127UL)) : 0UL) ? 1UL : 0UL))) & 255UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a1) >= (uint32_t)(97UL)) ? ((uint32_t)(vxp_a1) <= (uint32_t)(122UL)) : 0UL) ? (((uint32_t)(vxp_a1) - (uint32_t)(32UL)) & 255UL) : vxp_a1));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((((uint32_t)(vxp_a0) < (uint32_t)(10UL)) ? ((uint32_t)(vxp_a1) > (uint32_t)(32UL)) : 0UL) ? ((uint32_t)(vxp_a1) < (uint32_t)(127UL)) : 0UL) ? 1UL : 0UL));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((((uint32_t)(vxp_a0) >= (uint32_t)(10UL)) ? 1UL : ((uint32_t)(vxp_a1) == (uint32_t)(13UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)((((((uint32_t)(vxp_a0) < (uint32_t)(10UL)) ? ((uint32_t)(vxp_a1) > (uint32_t)(32UL)) : 0UL) ? ((uint32_t)(vxp_a1) < (uint32_t)(127UL)) : 0UL) ? 1UL : 0UL))) & 255UL)) == (uint32_t)(10UL))) ? 1UL : 0UL));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(16UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 0UL));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
