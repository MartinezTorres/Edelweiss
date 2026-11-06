/* Generated from relational source obligations and a closed activation contract. */
#include "vexel.h"
/* Local storage follows the per-function plan; ABI parameters remain automatic. */
uint8_t vx_payload[20];
void vx_lumberjack(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    VX_STABLE uint32_t vxo_0 = (uint32_t)(((((uint32_t)(vxp_a1) == (uint32_t)(4UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(5UL)) : 0UL) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(1UL)) : 0UL) ? 1UL : ((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 2UL : ((((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 3UL : ((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(2UL)) : 0UL) ? 4UL : ((((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 5UL : vxp_a0)))))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT32(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_0))) >> 8);
    VX_STABLE uint32_t vxo_1 = (uint32_t)(((((uint32_t)(vxp_a1) == (uint32_t)(4UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(5UL)) : 0UL) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(1UL)) : 0UL) ? 1UL : ((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 1UL : ((((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 2UL : ((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(2UL)) : 0UL) ? 1UL : ((((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 3UL : 0UL)))))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT32(vxo_1));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_1))) >> 8);
    VX_STABLE uint32_t vxo_2 = (uint32_t)(((((uint32_t)(vxp_a1) == (uint32_t)(4UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(5UL)) : 0UL) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(1UL)) : 0UL) ? 1UL : ((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 2UL : ((((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(2UL)) : 0UL) ? 3UL : 0UL))))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT32(vxo_2));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_2))) >> 8);
}
uint32_t vx_lumberjack_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_pear(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    VX_STABLE uint32_t vxo_0 = (uint32_t)(((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(0UL)) : 0UL) ? 2UL : (((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? 2UL : 1UL)));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT32(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_0))) >> 8);
    VX_STABLE uint32_t vxo_1 = (uint32_t)(((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(0UL)) : 0UL) ? 1UL : 0UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT32(vxo_1));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_1))) >> 8);
    VX_STABLE uint32_t vxo_2 = (uint32_t)(((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(0UL)) : 0UL) ? (((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? 0UL : 1UL) : 0UL));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT32(vxo_2));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_2))) >> 8);
    VX_STABLE uint32_t vxo_3 = (uint32_t)(((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(0UL)) : 0UL) ? (((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? 100UL : 0UL) : 0UL));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT32(vxo_3));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_3))) >> 8);
    VX_STABLE uint32_t vxo_4 = (uint32_t)(((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(0UL)) : 0UL) ? (((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? 6UL : 5UL) : 4UL));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT32(vxo_4));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_4))) >> 8);
}
uint32_t vx_pear_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    default: vx_trap(16); return 0;
    }
}
