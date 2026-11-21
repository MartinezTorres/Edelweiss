/* Editable NEO-8 window B module. Keep the generated ABI. */
#include "vexel.h"
void vxi_vx_effect_step(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) <= (uint32_t)((((uint32_t)(24UL) - (uint32_t)(vxp_a0)) & 255UL))) ? 1UL : 0UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(24UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(24UL) - (uint32_t)(vxp_a0)) & 255UL)))) & 255UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(24UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(24UL) - (uint32_t)(vxp_a0)) & 255UL))) > (uint32_t)((((uint32_t)(18UL) - (uint32_t)(vxp_a0)) & 255UL))) ? 3UL : (((uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(24UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(24UL) - (uint32_t)(vxp_a0)) & 255UL))) > (uint32_t)((((uint32_t)(12UL) - (uint32_t)(vxp_a0)) & 255UL))) ? 2UL : (((uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(24UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(24UL) - (uint32_t)(vxp_a0)) & 255UL))) > (uint32_t)((((uint32_t)(6UL) - (uint32_t)(vxp_a0)) & 255UL))) ? 1UL : 255UL))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
