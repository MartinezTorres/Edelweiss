/* Generated from relational source obligations and a closed activation contract. */
#include "vexel.h"
/* Local storage follows the per-function plan; ABI parameters remain automatic. */
uint8_t vx_payload[5];
void vx_lumberjack(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    vx_payload[0] = (uint8_t)(((((uint32_t)(vxp_a1) == (uint32_t)(4UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(5UL)) : 0UL) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(1UL)) : 0UL) ? 1UL : ((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 2UL : ((((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 3UL : ((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(2UL)) : 0UL) ? 4UL : ((((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 5UL : vxp_a0)))))));
    vx_payload[1] = (uint8_t)(((((uint32_t)(vxp_a1) == (uint32_t)(4UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(5UL)) : 0UL) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(1UL)) : 0UL) ? 1UL : ((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 1UL : ((((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 2UL : ((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(2UL)) : 0UL) ? 1UL : ((((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 3UL : 0UL)))))));
    vx_payload[2] = (uint8_t)(((((uint32_t)(vxp_a1) == (uint32_t)(4UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(5UL)) : 0UL) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(1UL)) : 0UL) ? 1UL : ((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 2UL : ((((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(2UL)) : 0UL) ? 3UL : 0UL))))));
}
uint32_t vx_lumberjack_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0];
    case 1: return (uint32_t)vx_payload[1];
    case 2: return (uint32_t)vx_payload[2];
    default: vx_trap(16); return 0;
    }
}
void vx_pear(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    vx_payload[0] = (uint8_t)(((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(0UL)) : 0UL) ? 2UL : (((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? 2UL : 1UL)));
    vx_payload[1] = (uint8_t)(((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(0UL)) : 0UL) ? 1UL : 0UL));
    vx_payload[2] = (uint8_t)(((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(0UL)) : 0UL) ? (((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? 0UL : 1UL) : 0UL));
    vx_payload[3] = (uint8_t)(((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(0UL)) : 0UL) ? (((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? 100UL : 0UL) : 0UL));
    vx_payload[4] = (uint8_t)(((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(0UL)) : 0UL) ? (((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? 6UL : 5UL) : 4UL));
}
uint32_t vx_pear_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0];
    case 1: return (uint32_t)vx_payload[1];
    case 2: return (uint32_t)vx_payload[2];
    case 3: return (uint32_t)vx_payload[3];
    case 4: return (uint32_t)vx_payload[4];
    default: vx_trap(16); return 0;
    }
}
