void vx_player_attack(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) > (uint32_t)(7UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? 2UL : (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 3UL : 0UL)) : ((((uint32_t)(vxp_a0) == (uint32_t)(5UL)) ? 1UL : ((uint32_t)(vxp_a0) == (uint32_t)(6UL))) ? (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(8UL)) & 255UL)) != (uint32_t)(0UL)) ? 4UL : (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(16UL)) & 255UL)) != (uint32_t)(0UL)) ? 5UL : 0UL)) : (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 0UL)))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_player_attack_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
