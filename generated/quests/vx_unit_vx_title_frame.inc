void vx_title_frame(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    if (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(192UL)) ? 0UL : vxp_a0)) & (uint32_t)(15UL)) & 255UL)) == (uint32_t)(0UL))) {
    } else {
    }
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(192UL)) ? 0UL : vxp_a0));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(192UL)) ? 0UL : vxp_a0)) & (uint32_t)(15UL)) & 255UL)) == (uint32_t)(0UL)) ? vx_shift((((uint32_t)(vxp_a0) == (uint32_t)(192UL)) ? 0UL : vxp_a0), 4UL, 8, 1, 0) : 255UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) != (uint32_t)(255UL)) ? 1UL : 0UL));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_title_frame_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    default: vx_trap(16); return 0;
    }
}
