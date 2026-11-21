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
