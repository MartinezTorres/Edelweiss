void vx_ball_leg(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint8_t vxp_a4) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) != (uint32_t)(vxp_a0)) ? 0UL : 1UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) != (uint32_t)(vxp_a0)) ? vxp_a2 : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) - (uint32_t)(64UL)) & 65535UL) : (((uint32_t)(vxp_a2) + (uint32_t)(64UL)) & 65535UL))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) != (uint32_t)(vxp_a0)) ? vxp_a1 : ((vx_signed(vx_signed((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a3) - (uint32_t)((((uint32_t)(vxp_a2) - (uint32_t)(64UL)) & 65535UL))) & 65535UL) : (((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)(64UL)) & 65535UL)) - (uint32_t)(vxp_a3)) & 65535UL)), 16), 16) > vx_signed(2048UL, 16)) ? (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 2UL : 1UL) : vxp_a1)));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) != (uint32_t)(vxp_a0)) ? vxp_a4 : ((vx_signed(vx_signed((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a3) - (uint32_t)((((uint32_t)(vxp_a2) - (uint32_t)(64UL)) & 65535UL))) & 65535UL) : (((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)(64UL)) & 65535UL)) - (uint32_t)(vxp_a3)) & 65535UL)), 16), 16) > vx_signed(2048UL, 16)) ? 30UL : vxp_a4)));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_ball_leg_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
