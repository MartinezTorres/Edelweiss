void vx_spark_frame(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(vxp_a0)) + ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a0)))) << 1)))))))) & 255UL))))) + (uint32_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a1) == (uint32_t)(1UL)) ? 1UL : 2UL)))) & 255UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_spark_frame_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
