#include "vexel.h"
void vx_town_door(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a0) == (uint32_t)(45UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(52UL)) : 0UL) ? 1UL : ((((uint32_t)(vxp_a0) == (uint32_t)(57UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(53UL)) : 0UL) ? 2UL : ((((uint32_t)(vxp_a0) == (uint32_t)(48UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(57UL)) : 0UL) ? 3UL : ((((uint32_t)(vxp_a0) == (uint32_t)(53UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(73UL)) : 0UL) ? 4UL : ((((uint32_t)(vxp_a0) == (uint32_t)(59UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(76UL)) : 0UL) ? 5UL : ((((uint32_t)(vxp_a0) == (uint32_t)(57UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(67UL)) : 0UL) ? 6UL : ((((uint32_t)(vxp_a0) == (uint32_t)(59UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(60UL)) : 0UL) ? 7UL : ((((uint32_t)(vxp_a0) == (uint32_t)(47UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(65UL)) : 0UL) ? 8UL : ((((uint32_t)(vxp_a0) == (uint32_t)(46UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(71UL)) : 0UL) ? 9UL : ((((uint32_t)(vxp_a0) == (uint32_t)(59UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(71UL)) : 0UL) ? 10UL : 0UL)))))))))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_town_door_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_town_house(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) > (uint32_t)(3UL)) ? 0UL : (((uint32_t)(vxp_a1) == (uint32_t)(255UL)) ? 0UL : ((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(255UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a3) != (uint32_t)(0UL)) ? 49UL : 48UL)))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) > (uint32_t)(3UL)) ? 0UL : (((uint32_t)(vxp_a1) == (uint32_t)(255UL)) ? 0UL : ((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(255UL)) : 0UL) ? 0UL : ((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL))) >= (uint32_t)(vxp_a0)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL))) + (uint32_t)(1UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL)))) == (uint32_t)(0UL)) ? 1UL : ((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL))) >= (uint32_t)(vxp_a0)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL))) + (uint32_t)(1UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL)))) == (uint32_t)(3UL))) ? 59UL : (((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL))) >= (uint32_t)(vxp_a0)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL))) + (uint32_t)(1UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL)))) == (uint32_t)(1UL)) ? 47UL : 46UL))))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) > (uint32_t)(3UL)) ? 0UL : (((uint32_t)(vxp_a1) == (uint32_t)(255UL)) ? 0UL : ((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(255UL)) : 0UL) ? 0UL : (((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL))) >= (uint32_t)(vxp_a0)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL))) + (uint32_t)(1UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL)))) == (uint32_t)(0UL)) ? 60UL : (((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL))) >= (uint32_t)(vxp_a0)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL))) + (uint32_t)(1UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL)))) == (uint32_t)(1UL)) ? 65UL : 71UL))))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) > (uint32_t)(3UL)) ? 0UL : (((uint32_t)(vxp_a1) == (uint32_t)(255UL)) ? 1UL : ((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(255UL)) : 0UL) ? 2UL : 0UL))));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_town_house_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_town_board(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(vxp_a1)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(39UL)) ? 50UL : (((uint32_t)(vxp_a0) == (uint32_t)(44UL)) ? 51UL : (((uint32_t)(vxp_a0) == (uint32_t)(57UL)) ? 52UL : (((uint32_t)(vxp_a0) == (uint32_t)(59UL)) ? 53UL : (((uint32_t)(vxp_a0) == (uint32_t)(64UL)) ? 54UL : (((uint32_t)(vxp_a0) == (uint32_t)(66UL)) ? 55UL : (((uint32_t)(vxp_a0) == (uint32_t)(72UL)) ? 56UL : (((uint32_t)(vxp_a0) == (uint32_t)(74UL)) ? 57UL : (((uint32_t)(vxp_a0) == (uint32_t)(92UL)) ? 58UL : 0UL)))))))))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(vxp_a0);
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_town_board_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_town_monster(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) < (uint32_t)(3UL)) ? (((uint32_t)(vxp_a0) + (uint32_t)(1UL)) & 255UL) : 4UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) < (uint32_t)(3UL)) ? (((uint32_t)(59UL) + (uint32_t)(vxp_a0)) & 255UL) : 0UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) < (uint32_t)(3UL)) ? (((uint32_t)(vxp_a1) > (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(1UL)) & 255UL) : 0UL) : vxp_a1));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) < (uint32_t)(3UL)) ? 30UL : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 60UL : 0UL)));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_town_monster_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
