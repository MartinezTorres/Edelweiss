void vx_title_flow(void) VX_ABI VX_RESIDENT {
    uint8_t vxl_1_s3475_l0, vxln_1_s3475_l0;
    uint32_t vxt_1[1];
    uint32_t vxt_4[1];
    uint32_t vxt_6[1];
    vxln_1_s3475_l0 = (0UL);
    vxl_1_s3475_l0 = vxln_1_s3475_l0;
    for (;;) {
        if (!(((uint32_t)(VX_SNAPSHOT8(vxl_1_s3475_l0)) < (uint32_t)(12UL)))) {
            if (0UL) {
                vxln_1_s3475_l0 = (VX_SNAPSHOT8(vxl_1_s3475_l0));
                vxl_1_s3475_l0 = vxln_1_s3475_l0;
                continue;
            }
            vxln_1_s3475_l0 = (VX_SNAPSHOT8(vxl_1_s3475_l0));
            vxl_1_s3475_l0 = vxln_1_s3475_l0;
            break;
        }
        if (((uint32_t)(VX_SNAPSHOT8(vxl_1_s3475_l0)) < (uint32_t)(12UL))) {
            vx_invoke_external_flow_slot(vxt_1, VX_SNAPSHOT8(vxl_1_s3475_l0));
            if ((vx_signed(VX_SNAPSHOT32(vxt_1[0]), 8) >= vx_signed(0UL, 8))) {
                vx_invoke_external_flow_update(vxt_4, (((uint32_t)(VX_SNAPSHOT32(vxt_1[0]))) & 255UL));
                if (((uint32_t)(VX_SNAPSHOT32(vxt_4[0])) == (uint32_t)(0UL))) {
                    vx_invoke_external_flow_despawn(vxt_6, (((uint32_t)(VX_SNAPSHOT32(vxt_1[0]))) & 255UL));
                } else {
                }
            } else {
            }
        } else {
        }
        if (0UL) {
            vxln_1_s3475_l0 = ((((uint32_t)(VX_SNAPSHOT8(vxl_1_s3475_l0)) < (uint32_t)(12UL)) ? (((uint32_t)(VX_SNAPSHOT8(vxl_1_s3475_l0)) + (uint32_t)(1UL)) & 255UL) : VX_SNAPSHOT8(vxl_1_s3475_l0)));
            vxl_1_s3475_l0 = vxln_1_s3475_l0;
            break;
        }
        vxln_1_s3475_l0 = ((((uint32_t)(VX_SNAPSHOT8(vxl_1_s3475_l0)) < (uint32_t)(12UL)) ? (((uint32_t)(VX_SNAPSHOT8(vxl_1_s3475_l0)) + (uint32_t)(1UL)) & 255UL) : VX_SNAPSHOT8(vxl_1_s3475_l0)));
        vxl_1_s3475_l0 = vxln_1_s3475_l0;
    }
    VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)(0UL);
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_title_flow_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
