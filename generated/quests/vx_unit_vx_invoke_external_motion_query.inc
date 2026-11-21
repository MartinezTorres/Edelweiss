void vx_invoke_external_motion_query(uint32_t *result, uint16_t p0, uint16_t p1, uint8_t p2, uint8_t p3, uint8_t p4, uint8_t p5, uint8_t p6, uint16_t p7, uint16_t p8) VX_ABI VX_RESIDENT {
    vx_external_motion_query(result, p0, p1, p2, p3, p4, p5, p6, p7, p8);
    if (result[0] > 65535UL) vx_trap(16);
    if (result[1] > 65535UL) vx_trap(16);
    if (result[2] > 255UL) vx_trap(16);
    if (result[3] > 255UL) vx_trap(16);
    if (result[4] > 255UL) vx_trap(16);
    if (result[5] > 255UL) vx_trap(16);
    if (result[6] > 255UL) vx_trap(16);
    if (result[7] > 255UL) vx_trap(16);
}
