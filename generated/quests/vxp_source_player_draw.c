/* Editable NEO-8 window B module. Keep the generated ABI. */
#include "vexel.h"
void vxi_vx_player_draw(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(16UL)) & 255UL)) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(128UL)) & 255UL)) == (uint32_t)(0UL)) ? 2UL : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(64UL)) & 255UL)) == (uint32_t)(0UL)) ? 4UL : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(32UL)) & 255UL)) == (uint32_t)(0UL)) ? 3UL : vxp_a2)))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(240UL)) & 255UL)) == (uint32_t)(240UL)) ? 255UL : (((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(16UL)) & 255UL)) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(128UL)) & 255UL)) == (uint32_t)(0UL)) ? 2UL : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(64UL)) & 255UL)) == (uint32_t)(0UL)) ? 4UL : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(32UL)) & 255UL)) == (uint32_t)(0UL)) ? 3UL : vxp_a2))))) == (uint32_t)(1UL)) ? 8UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(128UL)) & 255UL)) == (uint32_t)(0UL)) ? 2UL : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(64UL)) & 255UL)) == (uint32_t)(0UL)) ? 4UL : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(32UL)) & 255UL)) == (uint32_t)(0UL)) ? 3UL : vxp_a2)))) == (uint32_t)(2UL)) ? 6UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(64UL)) & 255UL)) == (uint32_t)(0UL)) ? 4UL : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(32UL)) & 255UL)) == (uint32_t)(0UL)) ? 3UL : vxp_a2))) == (uint32_t)(3UL)) ? 2UL : 4UL)))) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : 1UL))) & 255UL)));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
