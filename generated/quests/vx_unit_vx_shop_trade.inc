void vx_shop_trade(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint8_t vxp_a5,VX_STABLE uint8_t vxp_a6,VX_STABLE uint8_t vxp_a7) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 1UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) : 0UL) ? 1UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(75UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(200UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a1) < (uint32_t)(500UL)) ? 0UL : (((uint32_t)(vxp_a6) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)(vxp_a7) == (uint32_t)(255UL)) ? 0UL : 1UL))))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a4) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(150UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a5) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(100UL)) ? 1UL : 0UL) : 1UL)) : 0UL)))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) : 0UL) ? 20UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(75UL)) ? 75UL : 0UL) : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(200UL)) ? 200UL : 0UL) : (((uint32_t)(vxp_a1) < (uint32_t)(500UL)) ? 0UL : (((uint32_t)(vxp_a6) == (uint32_t)(0UL)) ? 500UL : (((uint32_t)(vxp_a7) == (uint32_t)(255UL)) ? 0UL : 500UL))))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a4) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(150UL)) ? 150UL : 0UL) : (((uint32_t)(vxp_a5) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(100UL)) ? 100UL : 0UL) : 0UL)) : 0UL)))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) : 0UL) ? 1UL : 0UL)));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(75UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(200UL)) ? 2UL : 0UL) : 0UL)) : 0UL))));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a1) < (uint32_t)(500UL)) ? 0UL : (((uint32_t)(vxp_a6) == (uint32_t)(0UL)) ? 5UL : 0UL)))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a4) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(150UL)) ? 2UL : 0UL) : (((uint32_t)(vxp_a5) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(100UL)) ? 6UL : 0UL) : 0UL)) : 0UL)))));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(75UL)) ? 24UL : 0UL) : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(200UL)) ? 25UL : 0UL) : (((uint32_t)(vxp_a1) < (uint32_t)(500UL)) ? 0UL : (((uint32_t)(vxp_a6) == (uint32_t)(0UL)) ? 26UL : (((uint32_t)(vxp_a7) == (uint32_t)(255UL)) ? 0UL : (((uint32_t)(vxp_a7) == (uint32_t)(0UL)) ? 30UL : (((uint32_t)(vxp_a7) == (uint32_t)(1UL)) ? 31UL : (((uint32_t)(vxp_a7) == (uint32_t)(2UL)) ? 32UL : (((uint32_t)(vxp_a7) == (uint32_t)(3UL)) ? 33UL : (((uint32_t)(vxp_a7) == (uint32_t)(4UL)) ? 34UL : (((uint32_t)(vxp_a7) == (uint32_t)(5UL)) ? 35UL : (((uint32_t)(vxp_a7) == (uint32_t)(6UL)) ? 36UL : 0UL)))))))))))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a4) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(150UL)) ? 27UL : 0UL) : (((uint32_t)(vxp_a5) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(100UL)) ? 28UL : 0UL) : 29UL)) : 0UL)))));
    vx_payload[10] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[11] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a1) < (uint32_t)(500UL)) ? 0UL : (((uint32_t)(vxp_a6) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a7) == (uint32_t)(255UL)) ? 1UL : 0UL))))) : 0UL))));
    vx_payload[12] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[13] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_shop_trade_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    case 5: return (uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8);
    case 6: return (uint32_t)vx_payload[12] + ((uint32_t)vx_payload[13] << 8);
    default: vx_trap(16); return 0;
    }
}
