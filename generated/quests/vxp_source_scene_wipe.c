/* Editable NEO-8 window B module. Keep the generated ABI. */
#include "vexel.h"
void vxi_vx_scene_wipe(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a2) == (uint32_t)(255UL)) ? 0UL : (((uint32_t)(vxp_a2) < (uint32_t)(4UL)) ? 1UL : ((((uint32_t)(vxp_a2) == (uint32_t)(5UL)) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(6UL))) ? 2UL : ((((uint32_t)(vxp_a2) == (uint32_t)(7UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(0UL)) : 0UL) ? 4UL : (((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a2) >= (uint32_t)(8UL)) : 0UL) ? ((uint32_t)(vxp_a2) <= (uint32_t)(10UL)) : 0UL) ? (((uint32_t)(vxp_a2) - (uint32_t)(3UL)) & 255UL) : 3UL))))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a2) < (uint32_t)(2UL)) ? vxp_a2 : (((uint32_t)(vxp_a2) == (uint32_t)(2UL)) ? (((uint32_t)(2UL) + (uint32_t)(vxp_a1)) & 255UL) : (((uint32_t)(vxp_a2) == (uint32_t)(3UL)) ? (((uint32_t)(23UL) - (uint32_t)(vxp_a1)) & 255UL) : (((uint32_t)(vxp_a2) == (uint32_t)(5UL)) ? (((uint32_t)(31UL) - (uint32_t)(vxp_a1)) & 255UL) : vxp_a1)))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a2) == (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 11UL : 12UL))) ? 1UL : 0UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) + (uint32_t)(1UL)) & 255UL) : vxp_a1));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a2) == (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 11UL : 12UL))) ? 1UL : 0UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) == (uint32_t)(10UL)) ? 255UL : 2UL) : (((uint32_t)(vxp_a2) + (uint32_t)(1UL)) & 255UL)));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
