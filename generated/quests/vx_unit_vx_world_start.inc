void vx_world_start(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)(0UL);
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(0UL);
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(99UL);
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(137UL);
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a0)) + ((uint16_t)(128)))))) >> 8))))) - ((uint8_t)(11)))))))) > ((uint8_t)(106))))) & 255UL)))) ? 106UL : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a0)) + ((uint16_t)(128)))))) >> 8))))) - ((uint8_t)(11)))))))) & 255UL))))));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) + ((uint16_t)(128)))))) >> 8))))) - ((uint8_t)(16)))))))) & 255UL)))));
    vx_payload[10] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[11] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(25088UL);
    vx_payload[12] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[13] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(25600UL);
    vx_payload[14] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[15] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(34816UL);
    vx_payload[16] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[17] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(1UL);
    vx_payload[18] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[19] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_world_start_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    case 5: return (uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8);
    case 6: return (uint32_t)vx_payload[12] + ((uint32_t)vx_payload[13] << 8);
    case 7: return (uint32_t)vx_payload[14] + ((uint32_t)vx_payload[15] << 8);
    case 8: return (uint32_t)vx_payload[16] + ((uint32_t)vx_payload[17] << 8);
    case 9: return (uint32_t)vx_payload[18] + ((uint32_t)vx_payload[19] << 8);
    default: vx_trap(16); return 0;
    }
}
