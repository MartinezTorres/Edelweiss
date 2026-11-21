/* Editable NEO-8 window B module. Keep the generated ABI. */
#include "vexel.h"
void vxi_vx_town_board(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(vxp_a1)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(39UL)) ? 50UL : (((uint32_t)(vxp_a0) == (uint32_t)(44UL)) ? 51UL : (((uint32_t)(vxp_a0) == (uint32_t)(57UL)) ? 52UL : (((uint32_t)(vxp_a0) == (uint32_t)(59UL)) ? 53UL : (((uint32_t)(vxp_a0) == (uint32_t)(64UL)) ? 54UL : (((uint32_t)(vxp_a0) == (uint32_t)(66UL)) ? 55UL : (((uint32_t)(vxp_a0) == (uint32_t)(72UL)) ? 56UL : (((uint32_t)(vxp_a0) == (uint32_t)(74UL)) ? 57UL : (((uint32_t)(vxp_a0) == (uint32_t)(92UL)) ? 58UL : 0UL)))))))))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(vxp_a0);
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
