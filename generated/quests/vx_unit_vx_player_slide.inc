void vx_player_slide(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint16_t vxp_a4,VX_STABLE uint16_t vxp_a5) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? vxp_a2 : vxp_a4) : vxp_a2));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? vxp_a3 : vxp_a5) : vxp_a3));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? 0UL : (((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a4) != (uint32_t)(vxp_a2)) : 0UL) ? ((uint32_t)(vxp_a5) != (uint32_t)(vxp_a3)) : 0UL) ? vxp_a2 : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? vxp_a4 : 0UL))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? 0UL : (((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a4) != (uint32_t)(vxp_a2)) : 0UL) ? ((uint32_t)(vxp_a5) != (uint32_t)(vxp_a3)) : 0UL) ? vxp_a5 : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? vxp_a3 : 0UL))));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? 0UL : (((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a4) != (uint32_t)(vxp_a2)) : 0UL) ? ((uint32_t)(vxp_a5) != (uint32_t)(vxp_a3)) : 0UL) ? 1UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 2UL : 0UL))));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_player_slide_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    default: vx_trap(16); return 0;
    }
}
