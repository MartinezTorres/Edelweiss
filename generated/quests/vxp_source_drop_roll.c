/* Editable NEO-8 window B module. Keep the generated ABI. */
#include "vexel.h"
void vxi_vx_drop_roll(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2) VX_ABI {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a0) < (uint32_t)(1UL)) ? 1UL : ((uint32_t)(vxp_a0) > (uint32_t)(3UL))) ? vxp_a1 : (((uint32_t)(vxp_a2) > (uint32_t)(255UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) < (uint32_t)(8UL)) ? 4UL : (((uint32_t)(vxp_a2) < (uint32_t)(24UL)) ? 3UL : (((uint32_t)(vxp_a2) < (uint32_t)(56UL)) ? 2UL : (((uint32_t)(vxp_a2) < (uint32_t)(72UL)) ? 1UL : 0UL)))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a2) < (uint32_t)(32UL)) ? 4UL : (((uint32_t)(vxp_a2) < (uint32_t)(64UL)) ? 3UL : (((uint32_t)(vxp_a2) < (uint32_t)(96UL)) ? 2UL : (((uint32_t)(vxp_a2) < (uint32_t)(128UL)) ? 1UL : 0UL)))) : (((uint32_t)(vxp_a2) < (uint32_t)(64UL)) ? 4UL : (((uint32_t)(vxp_a2) < (uint32_t)(128UL)) ? 3UL : (((uint32_t)(vxp_a2) < (uint32_t)(160UL)) ? 2UL : (((uint32_t)(vxp_a2) < (uint32_t)(192UL)) ? 1UL : 0UL)))))))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a0) < (uint32_t)(1UL)) ? 1UL : ((uint32_t)(vxp_a0) > (uint32_t)(3UL))) ? 0UL : (((uint32_t)(vxp_a2) > (uint32_t)(255UL)) ? 1UL : 0UL)));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
