/* Generated from relational source obligations and a closed activation contract. */
#include "vexel.h"
/* Local storage follows the per-function plan; ABI parameters remain automatic. */
uint8_t vx_payload[14];
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
void vx_stew(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    VX_STABLE uint32_t vxo_0 = (uint32_t)((((uint32_t)(vxp_a0) > (uint32_t)(38UL)) ? 0UL : (((uint32_t)(vxp_a1) < (uint32_t)(200UL)) ? 0UL : (((uint32_t)(vxp_a2) == (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vxp_a2) == (uint32_t)(1UL)) ? 0UL : 2UL)))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT32(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_0))) >> 8);
    VX_STABLE uint32_t vxo_1 = (uint32_t)((((uint32_t)(vxp_a0) > (uint32_t)(38UL)) ? 0UL : (((uint32_t)(vxp_a1) < (uint32_t)(200UL)) ? 0UL : (((uint32_t)(vxp_a2) == (uint32_t)(2UL)) ? 200UL : 0UL))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT32(vxo_1));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_1))) >> 8);
    VX_STABLE uint32_t vxo_2 = (uint32_t)((((uint32_t)(vxp_a0) > (uint32_t)(38UL)) ? 0UL : (((uint32_t)(vxp_a1) < (uint32_t)(200UL)) ? 0UL : (((uint32_t)(vxp_a2) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a0) + (uint32_t)(2UL)) & 255UL) : 0UL))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT32(vxo_2));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_2))) >> 8);
    VX_STABLE uint32_t vxo_3 = (uint32_t)((((uint32_t)(vxp_a0) > (uint32_t)(38UL)) ? 7UL : (((uint32_t)(vxp_a1) < (uint32_t)(200UL)) ? 8UL : (((uint32_t)(vxp_a2) == (uint32_t)(2UL)) ? 10UL : (((uint32_t)(vxp_a2) == (uint32_t)(1UL)) ? 0UL : 9UL)))));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT32(vxo_3));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_3))) >> 8);
}
uint32_t vx_stew_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_university(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4) VX_ABI VX_RESIDENT {
    VX_STABLE uint32_t vxo_0 = (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? ((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a4) == (uint32_t)(1UL))) ? 2UL : ((((uint32_t)(vxp_a4) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) : 0UL) ? 2UL : 1UL)) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? ((((uint32_t)(vxp_a3) != (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a4) == (uint32_t)(1UL))) ? 255UL : ((((uint32_t)(vxp_a4) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) : 0UL) ? 255UL : 2UL)) : 255UL))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT32(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_0))) >> 8);
    VX_STABLE uint32_t vxo_1 = (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? ((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a4) == (uint32_t)(1UL))) ? 0UL : ((((uint32_t)(vxp_a4) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) ? 2UL : 1UL))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? ((((uint32_t)(vxp_a3) != (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a4) == (uint32_t)(1UL))) ? 0UL : ((((uint32_t)(vxp_a4) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) ? 2UL : 1UL))) : 0UL))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT32(vxo_1));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_1))) >> 8);
    VX_STABLE uint32_t vxo_2 = (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? ((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a4) == (uint32_t)(1UL))) ? 0UL : ((((uint32_t)(vxp_a4) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) : 0UL) ? 50UL : 0UL)) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? ((((uint32_t)(vxp_a3) != (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a4) == (uint32_t)(1UL))) ? 0UL : ((((uint32_t)(vxp_a4) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) : 0UL) ? 50UL : 0UL)) : 0UL))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT32(vxo_2));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_2))) >> 8);
    VX_STABLE uint32_t vxo_3 = (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? ((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a4) == (uint32_t)(1UL))) ? 0UL : ((((uint32_t)(vxp_a4) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) : 0UL) ? 1UL : 0UL)) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? ((((uint32_t)(vxp_a3) != (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a4) == (uint32_t)(1UL))) ? 0UL : ((((uint32_t)(vxp_a4) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) : 0UL) ? 4UL : 0UL)) : 0UL))));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT32(vxo_3));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_3))) >> 8);
    VX_STABLE uint32_t vxo_4 = (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 11UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? ((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a4) == (uint32_t)(1UL))) ? 0UL : ((((uint32_t)(vxp_a4) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) : 0UL) ? 13UL : 12UL)) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? ((((uint32_t)(vxp_a3) != (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a4) == (uint32_t)(1UL))) ? 0UL : ((((uint32_t)(vxp_a4) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) : 0UL) ? 15UL : 14UL)) : 0UL))));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT32(vxo_4));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_4))) >> 8);
}
uint32_t vx_university_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_shop_stock(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint8_t vxp_a5) VX_ABI VX_RESIDENT {
    VX_STABLE uint32_t vxo_0 = (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 16UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? 17UL : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? 18UL : 19UL)) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a4) == (uint32_t)(0UL)) ? 20UL : (((uint32_t)(vxp_a5) == (uint32_t)(0UL)) ? 21UL : 22UL)) : 23UL))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT32(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_0))) >> 8);
    VX_STABLE uint32_t vxo_1 = (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(75UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(200UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a1) >= (uint32_t)(500UL)) ? 1UL : 0UL))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a4) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(150UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a5) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(100UL)) ? 1UL : 0UL) : 0UL)) : 1UL))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT32(vxo_1));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_1))) >> 8);
}
uint32_t vx_shop_stock_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_shop_trade(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint8_t vxp_a5,VX_STABLE uint8_t vxp_a6,VX_STABLE uint8_t vxp_a7) VX_ABI VX_RESIDENT {
    VX_STABLE uint32_t vxo_0 = (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 1UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) : 0UL) ? 1UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(75UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(200UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a1) < (uint32_t)(500UL)) ? 0UL : (((uint32_t)(vxp_a6) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)(vxp_a7) == (uint32_t)(255UL)) ? 0UL : 1UL))))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a4) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(150UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a5) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(100UL)) ? 1UL : 0UL) : 1UL)) : 0UL)))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT32(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_0))) >> 8);
    VX_STABLE uint32_t vxo_1 = (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) : 0UL) ? 20UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(75UL)) ? 75UL : 0UL) : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(200UL)) ? 200UL : 0UL) : (((uint32_t)(vxp_a1) < (uint32_t)(500UL)) ? 0UL : (((uint32_t)(vxp_a6) == (uint32_t)(0UL)) ? 500UL : (((uint32_t)(vxp_a7) == (uint32_t)(255UL)) ? 0UL : 500UL))))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a4) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(150UL)) ? 150UL : 0UL) : (((uint32_t)(vxp_a5) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(100UL)) ? 100UL : 0UL) : 0UL)) : 0UL)))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT32(vxo_1));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_1))) >> 8);
    VX_STABLE uint32_t vxo_2 = (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) : 0UL) ? 1UL : 0UL)));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT32(vxo_2));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_2))) >> 8);
    VX_STABLE uint32_t vxo_3 = (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(75UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(200UL)) ? 2UL : 0UL) : 0UL)) : 0UL))));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT32(vxo_3));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_3))) >> 8);
    VX_STABLE uint32_t vxo_4 = (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a1) < (uint32_t)(500UL)) ? 0UL : (((uint32_t)(vxp_a6) == (uint32_t)(0UL)) ? 5UL : 0UL)))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a4) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(150UL)) ? 2UL : 0UL) : (((uint32_t)(vxp_a5) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(100UL)) ? 6UL : 0UL) : 0UL)) : 0UL)))));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT32(vxo_4));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_4))) >> 8);
    VX_STABLE uint32_t vxo_5 = (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(75UL)) ? 24UL : 0UL) : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(200UL)) ? 25UL : 0UL) : (((uint32_t)(vxp_a1) < (uint32_t)(500UL)) ? 0UL : (((uint32_t)(vxp_a6) == (uint32_t)(0UL)) ? 26UL : (((uint32_t)(vxp_a7) == (uint32_t)(255UL)) ? 0UL : (((uint32_t)(vxp_a7) == (uint32_t)(0UL)) ? 30UL : (((uint32_t)(vxp_a7) == (uint32_t)(1UL)) ? 31UL : (((uint32_t)(vxp_a7) == (uint32_t)(2UL)) ? 32UL : (((uint32_t)(vxp_a7) == (uint32_t)(3UL)) ? 33UL : (((uint32_t)(vxp_a7) == (uint32_t)(4UL)) ? 34UL : (((uint32_t)(vxp_a7) == (uint32_t)(5UL)) ? 35UL : (((uint32_t)(vxp_a7) == (uint32_t)(6UL)) ? 36UL : 0UL)))))))))))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a4) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(150UL)) ? 27UL : 0UL) : (((uint32_t)(vxp_a5) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(100UL)) ? 28UL : 0UL) : 29UL)) : 0UL)))));
    vx_payload[10] = (uint8_t)(VX_SNAPSHOT32(vxo_5));
    vx_payload[11] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_5))) >> 8);
    VX_STABLE uint32_t vxo_6 = (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a1) < (uint32_t)(500UL)) ? 0UL : (((uint32_t)(vxp_a6) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a7) == (uint32_t)(255UL)) ? 1UL : 0UL))))) : 0UL))));
    vx_payload[12] = (uint8_t)(VX_SNAPSHOT32(vxo_6));
    vx_payload[13] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_6))) >> 8);
}
uint32_t vx_shop_trade_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    case 5: return (uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8);
    case 6: return (uint32_t)vx_payload[12] + ((uint32_t)vx_payload[13] << 8);
    default: vx_trap(16); return 0;
    }
}
