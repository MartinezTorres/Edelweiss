/* Editable NEO-8 window B module. Keep the generated ABI. */
#include "vexel.h"
void vxi_vx_player_keys(VX_STABLE uint8_t vxp_a0) VX_ABI {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0) | (uint32_t)(96UL)) & 255UL) : vxp_a0)) & (uint32_t)(144UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0) | (uint32_t)(96UL)) & 255UL) : vxp_a0)) | (uint32_t)(144UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0) | (uint32_t)(96UL)) & 255UL) : vxp_a0)));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
