void vx_contact_player(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3) VX_ABI VX_RESIDENT {
    if (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a0)) - ((uint16_t)(vxp_a2)))))) >> 5))))))) + ((uint8_t)(8)))))) <= ((uint8_t)(16))))) & 255UL)))) ? 1UL : 0UL)) != (uint32_t)(0UL))) {
    } else {
    }
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)(((((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a0)) - ((uint16_t)(vxp_a2)))))) >> 5))))))) + ((uint8_t)(8)))))) <= ((uint8_t)(16))))) & 255UL)))) ? 1UL : 0UL)) != (uint32_t)(0UL)) ? ((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) - ((uint16_t)(vxp_a3)))))) >> 5))))))) + ((uint8_t)(8)))))) <= ((uint8_t)(16))))) & 255UL)))) ? 1UL : 0UL)) != (uint32_t)(0UL)) : 0UL) ? 1UL : 0UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_contact_player_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
