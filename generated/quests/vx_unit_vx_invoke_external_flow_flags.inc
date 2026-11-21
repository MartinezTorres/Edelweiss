void vx_invoke_external_flow_flags(uint32_t *result, uint8_t p0) VX_ABI VX_RESIDENT {
    vx_external_flow_flags(result, p0);
    if (result[0] > 255UL) vx_trap(16);
    if (vx_signed(result[1], 32) < -128L || vx_signed(result[1], 32) > 127L) vx_trap(16);
}
