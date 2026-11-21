/* Editable NEO-8 window B module. Keep the generated ABI. */
#include "vexel.h"
#include "vx_support_value_base.h"
#include "vx_support_value_and8.h"
void vxi_vx_password_decode(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1_0,VX_STABLE uint8_t vxp_a1_1,VX_STABLE uint8_t vxp_a1_2,VX_STABLE uint8_t vxp_a1_3,VX_STABLE uint8_t vxp_a1_4,VX_STABLE uint8_t vxp_a1_5,VX_STABLE uint8_t vxp_a1_6,VX_STABLE uint8_t vxp_a1_7,VX_STABLE uint8_t vxp_a1_8,VX_STABLE uint8_t vxp_a1_9,VX_STABLE uint8_t vxp_a2) VX_ABI {
    static vx_flow_0_result vxt_10;
    static vx_flow_0_result vxt_11;
    static vx_flow_0_result vxt_12;
    static vx_flow_0_result vxt_13;
    static vx_flow_0_result vxt_14;
    static vx_flow_0_result vxt_15;
    static vx_flow_0_result vxt_17;
    static vx_flow_0_result vxt_19;
    static vx_flow_1_result vxt_23;
    static vx_flow_3_result vxt_26;
    static vx_flow_4_result vxt_27;
    static vx_flow_5_result vxt_28;
    static vx_flow_0_result vxt_3;
    static vx_flow_6_result vxt_30;
    static vx_flow_0_result vxt_8;
    vx_flow_0(&vxt_3, vxp_a1_0);
    vx_flow_0(&vxt_8, vxp_a1_1);
    vx_flow_0(&vxt_10, vxp_a1_2);
    vx_flow_0(&vxt_11, vxp_a1_3);
    vx_flow_0(&vxt_12, vxp_a1_4);
    vx_flow_0(&vxt_13, vxp_a1_5);
    vx_flow_0(&vxt_14, vxp_a1_6);
    vx_flow_0(&vxt_15, vxp_a1_7);
    vx_flow_0(&vxt_17, vxp_a1_8);
    vx_flow_0(&vxt_19, vxp_a1_9);
    vx_flow_1(&vxt_23, VX_SNAPSHOT8(vxt_3.v0), VX_SNAPSHOT8(vxt_8.v0));
    vx_flow_3(&vxt_26, VX_SNAPSHOT8(vxt_10.v0), VX_SNAPSHOT8(vxt_11.v0));
    vx_flow_4(&vxt_27, VX_SNAPSHOT8(vxt_12.v0), VX_SNAPSHOT8(vxt_13.v0));
    vx_flow_5(&vxt_28, VX_SNAPSHOT8(vxt_14.v0), VX_SNAPSHOT8(vxt_15.v0));
    vx_flow_6(&vxt_30, vxp_a0, VX_SNAPSHOT8(vxt_3.v0), VX_SNAPSHOT8(vxt_8.v0), VX_SNAPSHOT8(vxt_10.v0), VX_SNAPSHOT8(vxt_11.v0), VX_SNAPSHOT8(vxt_12.v0), VX_SNAPSHOT8(vxt_13.v0), VX_SNAPSHOT8(vxt_14.v0), VX_SNAPSHOT8(vxt_15.v0), VX_SNAPSHOT8(vxt_17.v0), VX_SNAPSHOT8(vxt_19.v0), VX_SNAPSHOT8(vxt_23.v0), VX_SNAPSHOT8(vxt_26.v0), VX_SNAPSHOT8(vxt_27.v0), VX_SNAPSHOT8(vxt_28.v0));
    if (((uint32_t)(vxp_a2) < (uint32_t)(8UL))) {
    } else {
    }
    if (((uint32_t)(VX_SNAPSHOT8(vxt_30.v0)) >= (uint32_t)(2UL))) {
    } else {
    }
    if (((uint32_t)(VX_SNAPSHOT8(vxt_30.v0)) == (uint32_t)(2UL))) {
    } else {
    }
    static VX_STABLE uint32_t vxo_0;
    vxo_0 = (uint32_t)(VX_SNAPSHOT8(vxt_30.v0));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT32(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_0))) >> 8);
    static VX_STABLE uint32_t vxo_1;
    vxo_1 = (uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxt_30.v0)) == (uint32_t)(2UL)) ? 15UL : (((uint32_t)(VX_SNAPSHOT8(vxt_23.v0)) & (uint32_t)(15UL)) & 255UL)));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT32(vxo_1));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_1))) >> 8);
    static VX_STABLE uint32_t vxo_2;
    vxo_2 = (uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxt_30.v0)) == (uint32_t)(2UL)) ? 255UL : VX_SNAPSHOT8(vxt_26.v0)));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT32(vxo_2));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_2))) >> 8);
    static VX_STABLE uint32_t vxo_3;
    vxo_3 = (uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxt_30.v0)) >= (uint32_t)(2UL)) ? 999UL : (((uint32_t)((((uint32_t)(((uint16_t)(((uint32_t)(((uint16_t)(VX_SNAPSHOT8(vxt_27.v0))))) << 4)))) & 65535UL))))));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT32(vxo_3));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_3))) >> 8);
    static VX_STABLE uint32_t vxo_4;
    vxo_4 = (uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxt_30.v0)) == (uint32_t)(2UL)) ? 40UL : (((uint32_t)((((uint32_t)(((uint8_t)(((uint16_t)(((uint8_t)(VX_SNAPSHOT8(vxt_28.v0))))) << 1)))) & 255UL))))));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT32(vxo_4));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_4))) >> 8);
    static VX_STABLE uint32_t vxo_5;
    vxo_5 = (uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxt_30.v0)) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a2) < (uint32_t)(8UL)) ? vxp_a2 : 0UL) : ((((uint32_t)(vxp_a2) < (uint32_t)(8UL)) ? (((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(VX_VALUE_AND8(((uint8_t)(VX_SNAPSHOT8(vxt_26.v0))), ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(1)))) << ((uint8_t)(((uint8_t)(vxp_a2)) & ((uint8_t)(7))))))))))))) != ((uint8_t)(0))))) & 255UL)))) : 0UL) ? vxp_a2 : 0UL)));
    vx_payload[10] = (uint8_t)(VX_SNAPSHOT32(vxo_5));
    vx_payload[11] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_5))) >> 8);
    static VX_STABLE uint32_t vxo_6;
    vxo_6 = (uint32_t)((((uint32_t)(37UL) + (uint32_t)(VX_SNAPSHOT8(vxt_30.v0))) & 255UL));
    vx_payload[12] = (uint8_t)(VX_SNAPSHOT32(vxo_6));
    vx_payload[13] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_6))) >> 8);
}
