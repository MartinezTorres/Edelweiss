void vx_invoke_external_flow_actor(uint32_t *result, uint8_t p0) VX_ABI VX_RESIDENT {
    vx_external_flow_actor(result, p0);
    if (result[0] > 255UL) vx_trap(16);
    if (result[1] > 255UL) vx_trap(16);
    if (result[2] > 255UL) vx_trap(16);
    if (result[3] > 255UL) vx_trap(16);
}
