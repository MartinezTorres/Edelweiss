void vx_invoke_external_flow_spawn(uint32_t *result, uint8_t p0) VX_ABI VX_RESIDENT {
    vx_external_flow_spawn(result, p0);
    if (result[0] > 255UL) vx_trap(16);
}
