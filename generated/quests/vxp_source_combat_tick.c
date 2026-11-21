/* Editable NEO-8 window B module. Keep the generated ABI. */
#include "vexel.h"
void vxi_vx_combat_tick(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(0UL)) : 0UL) ? ((uint32_t)(vxp_a2) == (uint32_t)(0UL)) : 0UL) ? 1UL : (((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) > (uint32_t)(6UL)) ? 6UL : vxp_a2)) != (uint32_t)(0UL)) ? 2UL : 1UL))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(0UL)) : 0UL) ? ((uint32_t)(vxp_a2) == (uint32_t)(0UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a1) > (uint32_t)(vxp_a3)) ? (((uint32_t)(vxp_a1) - (uint32_t)(vxp_a3)) & 255UL) : 0UL))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(0UL)) : 0UL) ? ((uint32_t)(vxp_a2) == (uint32_t)(0UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) > (uint32_t)(6UL)) ? 6UL : vxp_a2)) - (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(vxp_a2) > (uint32_t)(6UL)) ? 6UL : vxp_a2))) ? vxp_a3 : (((uint32_t)(vxp_a2) > (uint32_t)(6UL)) ? 6UL : vxp_a2)))) & 255UL))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(0UL)) : 0UL) ? ((uint32_t)(vxp_a2) == (uint32_t)(0UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(vxp_a2) > (uint32_t)(6UL)) ? 6UL : vxp_a2))) ? vxp_a3 : (((uint32_t)(vxp_a2) > (uint32_t)(6UL)) ? 6UL : vxp_a2))) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(vxp_a2) > (uint32_t)(6UL)) ? 6UL : vxp_a2))) ? vxp_a3 : (((uint32_t)(vxp_a2) > (uint32_t)(6UL)) ? 6UL : vxp_a2)))) & 255UL)) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(vxp_a2) > (uint32_t)(6UL)) ? 6UL : vxp_a2))) ? vxp_a3 : (((uint32_t)(vxp_a2) > (uint32_t)(6UL)) ? 6UL : vxp_a2)))) & 255UL))));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(0UL)) : 0UL) ? ((uint32_t)(vxp_a2) == (uint32_t)(0UL)) : 0UL) ? 2UL : (((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? 2UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) > (uint32_t)(vxp_a3)) ? (((uint32_t)(vxp_a1) - (uint32_t)(vxp_a3)) & 255UL) : 0UL)) & (uint32_t)(4UL)) & 255UL)) == (uint32_t)(0UL)) ? 1UL : 0UL)))));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
