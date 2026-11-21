void vx_ghost_update(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint16_t vxp_a4,VX_STABLE uint16_t vxp_a5,VX_STABLE uint16_t vxp_a6,VX_STABLE int8_t vxp_a7,VX_STABLE int8_t vxp_a8,VX_STABLE uint16_t vxp_a9,VX_STABLE uint16_t vxp_a10) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vx_calc_uint16_t_0;
    static VX_STABLE uint16_t vx_calc_uint16_t_1;
    if (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(vxp_a1)) & 255UL)) & (uint32_t)(3UL)) & 255UL)) == (uint32_t)(0UL))) {
    } else {
    }
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(vxp_a1)) & 255UL)) & (uint32_t)(3UL)) & 255UL)) == (uint32_t)(0UL)) ? 1UL : 0UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(vxp_a1)) & 255UL)) & (uint32_t)(3UL)) & 255UL)) == (uint32_t)(0UL)) ? vxp_a2 : 0UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(vxp_a1)) & 255UL)) & (uint32_t)(3UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(vxp_a3) + (uint32_t)((((uint32_t)(vx_signed(((uint32_t)((vx_calc_uint16_t_0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a5)) - ((uint16_t)(vxp_a3)))))), VX_VALUE_I8(VX_VALUE_ADD8(((uint8_t)(vxp_a7)), ((uint8_t)(VX_VALUE_I8(VX_VALUE_I16(VX_VALUE_ASR16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(vx_calc_uint16_t_0))) + (VX_VALUE_I16(VX_VALUE_I16(vx_calc_uint16_t_0)) < 0 ? 511U : 0U)), 9))))))))) + (uint32_t)((((uint32_t)(vxp_a9) < (uint32_t)(vxp_a3)) ? -1UL : 1UL))), 8))) & 65535UL))) & 65535UL)) + (uint32_t)((((uint32_t)(vx_signed(((uint32_t)((vx_calc_uint16_t_1 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a5)) - ((uint16_t)(vxp_a3)))))), VX_VALUE_I8(VX_VALUE_ADD8(((uint8_t)(vxp_a7)), ((uint8_t)(VX_VALUE_I8(VX_VALUE_I16(VX_VALUE_ASR16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(vx_calc_uint16_t_1))) + (VX_VALUE_I16(VX_VALUE_I16(vx_calc_uint16_t_1)) < 0 ? 511U : 0U)), 9))))))))) + (uint32_t)((((uint32_t)(vxp_a9) < (uint32_t)(vxp_a3)) ? -1UL : 1UL))), 8))) & 65535UL))) & 65535UL) : 0UL));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(vxp_a1)) & 255UL)) & (uint32_t)(3UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(vxp_a4) + (uint32_t)((((uint32_t)(vx_signed(((uint32_t)((vx_calc_uint16_t_0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a6)) - ((uint16_t)(vxp_a4)))))), VX_VALUE_I8(VX_VALUE_ADD8(((uint8_t)(vxp_a8)), ((uint8_t)(VX_VALUE_I8(VX_VALUE_I16(VX_VALUE_ASR16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(vx_calc_uint16_t_0))) + (VX_VALUE_I16(VX_VALUE_I16(vx_calc_uint16_t_0)) < 0 ? 511U : 0U)), 9))))))))) + (uint32_t)((((uint32_t)(vxp_a10) < (uint32_t)(vxp_a4)) ? -1UL : 1UL))), 8))) & 65535UL))) & 65535UL)) + (uint32_t)((((uint32_t)(vx_signed(((uint32_t)((vx_calc_uint16_t_1 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a6)) - ((uint16_t)(vxp_a4)))))), VX_VALUE_I8(VX_VALUE_ADD8(((uint8_t)(vxp_a8)), ((uint8_t)(VX_VALUE_I8(VX_VALUE_I16(VX_VALUE_ASR16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(vx_calc_uint16_t_1))) + (VX_VALUE_I16(VX_VALUE_I16(vx_calc_uint16_t_1)) < 0 ? 511U : 0U)), 9))))))))) + (uint32_t)((((uint32_t)(vxp_a10) < (uint32_t)(vxp_a4)) ? -1UL : 1UL))), 8))) & 65535UL))) & 65535UL) : 0UL));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(vxp_a1)) & 255UL)) & (uint32_t)(3UL)) & 255UL)) == (uint32_t)(0UL)) ? vx_signed(((uint32_t)((vx_calc_uint16_t_0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a5)) - ((uint16_t)(vxp_a3)))))), VX_VALUE_I8(VX_VALUE_ADD8(((uint8_t)(vxp_a7)), ((uint8_t)(VX_VALUE_I8(VX_VALUE_I16(VX_VALUE_ASR16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(vx_calc_uint16_t_0))) + (VX_VALUE_I16(VX_VALUE_I16(vx_calc_uint16_t_0)) < 0 ? 511U : 0U)), 9))))))))) + (uint32_t)((((uint32_t)(vxp_a9) < (uint32_t)(vxp_a3)) ? -1UL : 1UL))), 8) : 0UL));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(vxp_a1)) & 255UL)) & (uint32_t)(3UL)) & 255UL)) == (uint32_t)(0UL)) ? vx_signed(((uint32_t)((vx_calc_uint16_t_0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a6)) - ((uint16_t)(vxp_a4)))))), VX_VALUE_I8(VX_VALUE_ADD8(((uint8_t)(vxp_a8)), ((uint8_t)(VX_VALUE_I8(VX_VALUE_I16(VX_VALUE_ASR16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(vx_calc_uint16_t_0))) + (VX_VALUE_I16(VX_VALUE_I16(vx_calc_uint16_t_0)) < 0 ? 511U : 0U)), 9))))))))) + (uint32_t)((((uint32_t)(vxp_a10) < (uint32_t)(vxp_a4)) ? -1UL : 1UL))), 8) : 0UL));
    vx_payload[10] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[11] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(vxp_a1)) & 255UL)) & (uint32_t)(3UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(7UL)) & 255UL)) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(7UL)) & 255UL)) == (uint32_t)(1UL)) ? 2UL : (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(7UL)) & 255UL)) == (uint32_t)(3UL)) ? 6UL : (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(7UL)) & 255UL)) < (uint32_t)(6UL)) ? 4UL : 10UL))))) + (uint32_t)(((vx_signed(vx_signed(((uint32_t)((vx_calc_uint16_t_0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a6)) - ((uint16_t)(vxp_a4)))))), VX_VALUE_I8(VX_VALUE_ADD8(((uint8_t)(vxp_a8)), ((uint8_t)(VX_VALUE_I8(VX_VALUE_I16(VX_VALUE_ASR16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(vx_calc_uint16_t_0))) + (VX_VALUE_I16(VX_VALUE_I16(vx_calc_uint16_t_0)) < 0 ? 511U : 0U)), 9))))))))) + (uint32_t)((((uint32_t)(vxp_a10) < (uint32_t)(vxp_a4)) ? -1UL : 1UL))), 8), 8) > vx_signed(0UL, 8)) ? 0UL : 1UL))) & 255UL) : 0UL));
    vx_payload[12] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[13] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_ghost_update_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_signed((uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8), 16);
    case 5: return (uint32_t)vx_signed((uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8), 16);
    case 6: return (uint32_t)vx_payload[12] + ((uint32_t)vx_payload[13] << 8);
    default: vx_trap(16); return 0;
    }
}
