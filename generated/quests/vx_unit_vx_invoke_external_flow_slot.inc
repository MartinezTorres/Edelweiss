void vx_invoke_external_flow_slot(uint32_t *result, uint8_t p0) VX_ABI VX_RESIDENT {
    vx_external_flow_slot(result, p0);
    if (vx_signed(result[0], 32) < -128L || vx_signed(result[0], 32) > 127L) vx_trap(16);
}
