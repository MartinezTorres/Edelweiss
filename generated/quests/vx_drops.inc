#include "vexel.h"
void vx_drop_roll(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2) VX_ABI VX_RESIDENT {
    VX_STABLE uint32_t vxo_0 = (uint32_t)(((((uint32_t)(vxp_a0) < (uint32_t)(1UL)) ? 1UL : ((uint32_t)(vxp_a0) > (uint32_t)(3UL))) ? vxp_a1 : (((uint32_t)(vxp_a2) > (uint32_t)(255UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) < (uint32_t)(8UL)) ? 4UL : (((uint32_t)(vxp_a2) < (uint32_t)(24UL)) ? 3UL : (((uint32_t)(vxp_a2) < (uint32_t)(56UL)) ? 2UL : (((uint32_t)(vxp_a2) < (uint32_t)(72UL)) ? 1UL : 0UL)))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a2) < (uint32_t)(32UL)) ? 4UL : (((uint32_t)(vxp_a2) < (uint32_t)(64UL)) ? 3UL : (((uint32_t)(vxp_a2) < (uint32_t)(96UL)) ? 2UL : (((uint32_t)(vxp_a2) < (uint32_t)(128UL)) ? 1UL : 0UL)))) : (((uint32_t)(vxp_a2) < (uint32_t)(64UL)) ? 4UL : (((uint32_t)(vxp_a2) < (uint32_t)(128UL)) ? 3UL : (((uint32_t)(vxp_a2) < (uint32_t)(160UL)) ? 2UL : (((uint32_t)(vxp_a2) < (uint32_t)(192UL)) ? 1UL : 0UL)))))))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT32(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_0))) >> 8);
    VX_STABLE uint32_t vxo_1 = (uint32_t)(((((uint32_t)(vxp_a0) < (uint32_t)(1UL)) ? 1UL : ((uint32_t)(vxp_a0) > (uint32_t)(3UL))) ? 0UL : (((uint32_t)(vxp_a2) > (uint32_t)(255UL)) ? 1UL : 0UL)));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT32(vxo_1));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_1))) >> 8);
}
uint32_t vx_drop_roll_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_drop_collect(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    VX_STABLE uint32_t vxo_0 = (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)((((uint32_t)(vxp_a1) + (uint32_t)(2UL)) & 255UL)) > (uint32_t)(vxp_a2)) ? vxp_a2 : (((uint32_t)(vxp_a1) + (uint32_t)(2UL)) & 255UL)) : vxp_a1));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT32(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_0))) >> 8);
    VX_STABLE uint32_t vxo_1 = (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 1UL : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 5UL : (((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? 20UL : 0UL))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT32(vxo_1));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_1))) >> 8);
}
uint32_t vx_drop_collect_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
