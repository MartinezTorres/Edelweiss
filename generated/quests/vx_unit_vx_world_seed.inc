void vx_world_seed(VX_STABLE uint8_t vxp_a0) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 2UL : (((uint32_t)(vxp_a0) < (uint32_t)(4UL)) ? 3UL : (((uint32_t)(vxp_a0) < (uint32_t)(6UL)) ? 4UL : (((uint32_t)(vxp_a0) < (uint32_t)(10UL)) ? 5UL : (((uint32_t)(vxp_a0) < (uint32_t)(12UL)) ? 6UL : (((uint32_t)(vxp_a0) < (uint32_t)(16UL)) ? 7UL : (((uint32_t)(vxp_a0) == (uint32_t)(16UL)) ? 8UL : 0UL)))))))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a0) < (uint32_t)(2UL)) ? 1UL : ((uint32_t)(vxp_a0) >= (uint32_t)(16UL))) ? 0UL : (((uint32_t)(vxp_a0) < (uint32_t)(4UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(2UL)) & 255UL) : (((uint32_t)(vxp_a0) < (uint32_t)(6UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(4UL)) & 255UL) : (((uint32_t)(vxp_a0) < (uint32_t)(10UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(6UL)) & 255UL) : (((uint32_t)(vxp_a0) < (uint32_t)(12UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(10UL)) & 255UL) : (((uint32_t)(vxp_a0) - (uint32_t)(12UL)) & 255UL)))))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a0) == (uint32_t)(12UL))) ? 1UL : ((uint32_t)(vxp_a0) == (uint32_t)(15UL))) ? 120UL : (((uint32_t)(vxp_a0) == (uint32_t)(6UL)) ? 104UL : (((uint32_t)(vxp_a0) == (uint32_t)(7UL)) ? 106UL : (((uint32_t)(vxp_a0) == (uint32_t)(8UL)) ? 103UL : (((uint32_t)(vxp_a0) == (uint32_t)(9UL)) ? 108UL : (((uint32_t)(vxp_a0) == (uint32_t)(10UL)) ? 86UL : (((uint32_t)(vxp_a0) == (uint32_t)(11UL)) ? 88UL : (((uint32_t)(vxp_a0) == (uint32_t)(13UL)) ? 124UL : (((uint32_t)(vxp_a0) == (uint32_t)(14UL)) ? 122UL : (((uint32_t)(vxp_a0) == (uint32_t)(16UL)) ? 118UL : 0UL)))))))))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 126UL : (((uint32_t)(vxp_a0) == (uint32_t)(6UL)) ? 24UL : (((uint32_t)(vxp_a0) == (uint32_t)(7UL)) ? 40UL : (((uint32_t)(vxp_a0) == (uint32_t)(8UL)) ? 56UL : (((uint32_t)(vxp_a0) == (uint32_t)(9UL)) ? 20UL : (((uint32_t)(vxp_a0) == (uint32_t)(10UL)) ? 22UL : (((uint32_t)(vxp_a0) == (uint32_t)(11UL)) ? 26UL : (((uint32_t)(vxp_a0) == (uint32_t)(12UL)) ? 8UL : (((uint32_t)(vxp_a0) == (uint32_t)(13UL)) ? 30UL : (((uint32_t)(vxp_a0) == (uint32_t)(14UL)) ? 46UL : (((uint32_t)(vxp_a0) == (uint32_t)(15UL)) ? 64UL : (((uint32_t)(vxp_a0) == (uint32_t)(16UL)) ? 88UL : 0UL)))))))))))));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_world_seed_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
