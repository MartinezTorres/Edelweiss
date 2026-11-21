void vx_flow_0(vx_flow_0_result *vxo, VX_STABLE uint8_t vxa_0) VX_ABI VX_RESIDENT {
    vxo->v0 = ((((uint32_t)(vxa_0) >= (uint32_t)(97UL)) ? ((uint32_t)(vxa_0) <= (uint32_t)(122UL)) : 0UL) ? (((uint32_t)(vxa_0) - (uint32_t)(32UL)) & 255UL) : vxa_0);
}
