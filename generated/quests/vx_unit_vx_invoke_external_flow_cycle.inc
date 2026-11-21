void vx_invoke_external_flow_cycle(uint32_t *result) VX_ABI VX_RESIDENT {
    vx_external_flow_cycle(result);
    if (result[0] > 255UL) vx_trap(16);
}
