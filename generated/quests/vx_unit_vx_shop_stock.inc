void vx_shop_stock(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint8_t vxp_a5) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 16UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? 17UL : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? 18UL : 19UL)) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a4) == (uint32_t)(0UL)) ? 20UL : (((uint32_t)(vxp_a5) == (uint32_t)(0UL)) ? 21UL : 22UL)) : 23UL))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(75UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(200UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a1) >= (uint32_t)(500UL)) ? 1UL : 0UL))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a4) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(150UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a5) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(100UL)) ? 1UL : 0UL) : 0UL)) : 1UL))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_shop_stock_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
