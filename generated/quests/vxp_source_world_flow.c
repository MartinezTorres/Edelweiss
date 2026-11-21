/* Editable NEO-8 window B module. Keep the generated ABI. */
#include "vexel.h"
#include "vx_support_value_base.h"
void vxi_vx_world_flow(void) VX_ABI {
    uint8_t vxl_0_s3463_l0, vxln_0_s3463_l0;
    uint8_t vxl_4_s3466_l0, vxln_4_s3466_l0;
    uint8_t vxl_4_s30083_l0, vxln_4_s30083_l0;
    uint32_t vxt_0[1];
    uint32_t vxt_16[1];
    uint32_t vxt_18[1];
    uint32_t vxt_2[1];
    uint32_t vxt_20[1];
    uint32_t vxt_21[2];
    uint32_t vxt_22[4];
    uint32_t vxt_29[1];
    uint32_t vxt_5[1];
    uint32_t vxt_7[1];
    uint32_t vxt_9[4];
    vxln_0_s3463_l0 = (0UL);
    vxl_0_s3463_l0 = vxln_0_s3463_l0;
    for (;;) {
        if (!(((uint32_t)(VX_SNAPSHOT8(vxl_0_s3463_l0)) < (uint32_t)(12UL)))) {
            if (0UL) {
                vxln_0_s3463_l0 = (VX_SNAPSHOT8(vxl_0_s3463_l0));
                vxl_0_s3463_l0 = vxln_0_s3463_l0;
                continue;
            }
            vxln_0_s3463_l0 = (VX_SNAPSHOT8(vxl_0_s3463_l0));
            vxl_0_s3463_l0 = vxln_0_s3463_l0;
            break;
        }
        if (((uint32_t)(VX_SNAPSHOT8(vxl_0_s3463_l0)) < (uint32_t)(12UL))) {
            vx_invoke_external_flow_yield(vxt_0);
            vx_invoke_external_flow_slot(vxt_2, VX_SNAPSHOT8(vxl_0_s3463_l0));
            if ((vx_signed(VX_SNAPSHOT32(vxt_2[0]), 8) >= vx_signed(0UL, 8))) {
                vx_invoke_external_flow_update(vxt_5, (((uint32_t)(VX_SNAPSHOT32(vxt_2[0]))) & 255UL));
                if (((uint32_t)(VX_SNAPSHOT32(vxt_5[0])) == (uint32_t)(0UL))) {
                    vx_invoke_external_flow_despawn(vxt_7, (((uint32_t)(VX_SNAPSHOT32(vxt_2[0]))) & 255UL));
                } else {
                }
                if (((uint32_t)(VX_SNAPSHOT8(vxl_0_s3463_l0)) != (uint32_t)(0UL))) {
                    vx_invoke_external_flow_actor(vxt_9, (((uint32_t)(VX_SNAPSHOT32(vxt_2[0]))) & 255UL));
                    if (((uint32_t)(((((uint32_t)((((uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_9[0])) - (uint32_t)(VX_SNAPSHOT32(vxt_9[2]))) & 255UL)) + (uint32_t)(3UL)) & 255UL)) < (uint32_t)(30UL)) ? ((uint32_t)((((uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_9[1])) - (uint32_t)(VX_SNAPSHOT32(vxt_9[3]))) & 255UL)) + (uint32_t)(3UL)) & 255UL)) < (uint32_t)(38UL)) : 0UL) ? 1UL : 0UL)) == (uint32_t)(0UL))) {
                        vx_invoke_external_flow_despawn(vxt_16, (((uint32_t)(VX_SNAPSHOT32(vxt_2[0]))) & 255UL));
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
        if (0UL) {
            vxln_0_s3463_l0 = ((((uint32_t)(VX_SNAPSHOT8(vxl_0_s3463_l0)) < (uint32_t)(12UL)) ? (((uint32_t)(VX_SNAPSHOT8(vxl_0_s3463_l0)) + (uint32_t)(1UL)) & 255UL) : VX_SNAPSHOT8(vxl_0_s3463_l0)));
            vxl_0_s3463_l0 = vxln_0_s3463_l0;
            break;
        }
        vxln_0_s3463_l0 = ((((uint32_t)(VX_SNAPSHOT8(vxl_0_s3463_l0)) < (uint32_t)(12UL)) ? (((uint32_t)(VX_SNAPSHOT8(vxl_0_s3463_l0)) + (uint32_t)(1UL)) & 255UL) : VX_SNAPSHOT8(vxl_0_s3463_l0)));
        vxl_0_s3463_l0 = vxln_0_s3463_l0;
    }
    vx_invoke_external_flow_cycle(vxt_18);
    if ((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(VX_SNAPSHOT32(vxt_18[0]))))) << 3)))) & ((uint8_t)(127)))))) < ((uint8_t)(96))))) & 255UL))))) {
        vxln_4_s3466_l0 = ((((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(VX_SNAPSHOT32(vxt_18[0]))))) << 3)))) & ((uint8_t)(127)))))) & 255UL)))));
        vxln_4_s30083_l0 = (0UL);
        vxl_4_s3466_l0 = vxln_4_s3466_l0;
        vxl_4_s30083_l0 = vxln_4_s30083_l0;
        for (;;) {
            if (!(((uint32_t)(VX_SNAPSHOT8(vxl_4_s30083_l0)) < (uint32_t)(8UL)))) {
                if (0UL) {
                    vxln_4_s3466_l0 = (VX_SNAPSHOT8(vxl_4_s3466_l0));
                    vxln_4_s30083_l0 = (VX_SNAPSHOT8(vxl_4_s30083_l0));
                    vxl_4_s3466_l0 = vxln_4_s3466_l0;
                    vxl_4_s30083_l0 = vxln_4_s30083_l0;
                    continue;
                }
                vxln_4_s3466_l0 = (VX_SNAPSHOT8(vxl_4_s3466_l0));
                vxln_4_s30083_l0 = (VX_SNAPSHOT8(vxl_4_s30083_l0));
                vxl_4_s3466_l0 = vxln_4_s3466_l0;
                vxl_4_s30083_l0 = vxln_4_s30083_l0;
                break;
            }
            if (((uint32_t)(VX_SNAPSHOT8(vxl_4_s30083_l0)) < (uint32_t)(8UL))) {
                vx_invoke_external_flow_yield(vxt_20);
                vx_invoke_external_flow_flags(vxt_21, (((uint32_t)(VX_SNAPSHOT8(vxl_4_s3466_l0)) + (uint32_t)(VX_SNAPSHOT8(vxl_4_s30083_l0))) & 255UL));
                if ((((uint32_t)(VX_SNAPSHOT32(vxt_21[0])) != (uint32_t)(0UL)) ? (vx_signed(VX_SNAPSHOT32(vxt_21[1]), 8) < vx_signed(0UL, 8)) : 0UL)) {
                    vx_invoke_external_flow_actor(vxt_22, (((uint32_t)(VX_SNAPSHOT8(vxl_4_s3466_l0)) + (uint32_t)(VX_SNAPSHOT8(vxl_4_s30083_l0))) & 255UL));
                    if (((uint32_t)(((((uint32_t)(((((uint32_t)((((uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_22[0])) - (uint32_t)(VX_SNAPSHOT32(vxt_22[2]))) & 255UL)) + (uint32_t)(3UL)) & 255UL)) < (uint32_t)(30UL)) ? ((uint32_t)((((uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_22[1])) - (uint32_t)(VX_SNAPSHOT32(vxt_22[3]))) & 255UL)) + (uint32_t)(3UL)) & 255UL)) < (uint32_t)(38UL)) : 0UL) ? 1UL : 0UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_22[0])) - (uint32_t)(VX_SNAPSHOT32(vxt_22[2]))) & 255UL)) >= (uint32_t)(24UL)) ? 1UL : ((uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_22[1])) - (uint32_t)(VX_SNAPSHOT32(vxt_22[3]))) & 255UL)) >= (uint32_t)(32UL))) : 0UL) ? 1UL : 0UL)) != (uint32_t)(0UL))) {
                        vx_invoke_external_flow_spawn(vxt_29, (((uint32_t)(VX_SNAPSHOT8(vxl_4_s3466_l0)) + (uint32_t)(VX_SNAPSHOT8(vxl_4_s30083_l0))) & 255UL));
                    } else {
                    }
                } else {
                }
            } else {
            }
            if (0UL) {
                vxln_4_s3466_l0 = (VX_SNAPSHOT8(vxl_4_s3466_l0));
                vxln_4_s30083_l0 = ((((uint32_t)(VX_SNAPSHOT8(vxl_4_s30083_l0)) < (uint32_t)(8UL)) ? (((uint32_t)(VX_SNAPSHOT8(vxl_4_s30083_l0)) + (uint32_t)(1UL)) & 255UL) : VX_SNAPSHOT8(vxl_4_s30083_l0)));
                vxl_4_s3466_l0 = vxln_4_s3466_l0;
                vxl_4_s30083_l0 = vxln_4_s30083_l0;
                break;
            }
            vxln_4_s3466_l0 = (VX_SNAPSHOT8(vxl_4_s3466_l0));
            vxln_4_s30083_l0 = ((((uint32_t)(VX_SNAPSHOT8(vxl_4_s30083_l0)) < (uint32_t)(8UL)) ? (((uint32_t)(VX_SNAPSHOT8(vxl_4_s30083_l0)) + (uint32_t)(1UL)) & 255UL) : VX_SNAPSHOT8(vxl_4_s30083_l0)));
            vxl_4_s3466_l0 = vxln_4_s3466_l0;
            vxl_4_s30083_l0 = vxln_4_s30083_l0;
        }
    } else {
    }
    VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)(0UL);
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
