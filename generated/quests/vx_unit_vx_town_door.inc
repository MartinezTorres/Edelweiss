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
