/* Editable NEO-8 window B module. Keep the generated ABI. */
#include "vexel.h"
void vxi_vx_scene_revive(VX_STABLE uint8_t vxp_a0) VX_ABI {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a0) - (uint32_t)(2UL)) & 255UL)) < (uint32_t)(6UL)) ? 6UL : (((uint32_t)(vxp_a0) - (uint32_t)(2UL)) & 255UL)));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
