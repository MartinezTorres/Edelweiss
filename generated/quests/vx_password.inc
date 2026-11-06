#include "vexel.h"
void vx_flow_0(uint32_t *vxo, VX_STABLE uint8_t vxa_0) VX_ABI VX_RESIDENT {
    vxo[0] = ((((uint32_t)(vxa_0) >= (uint32_t)(97UL)) ? ((uint32_t)(vxa_0) <= (uint32_t)(122UL)) : 0UL) ? (((uint32_t)(vxa_0) - (uint32_t)(32UL)) & 255UL) : vxa_0);
}
void vx_flow_1(uint32_t *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI VX_RESIDENT {
    (void)(vx_shift((((uint32_t)(vxa_1) - (uint32_t)(65UL)) & 255UL), 4UL, 8, 0, 0));
    vxo[0] = (((uint32_t)((((uint32_t)((((uint32_t)(vxa_0) - (uint32_t)(65UL)) & 255UL)) | (uint32_t)(vx_shift((((uint32_t)(vxa_1) - (uint32_t)(65UL)) & 255UL), 4UL, 8, 0, 0))) & 255UL)) ^ (uint32_t)(130UL)) & 255UL);
}
void vx_flow_3(uint32_t *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI VX_RESIDENT {
    (void)(vx_shift((((uint32_t)(vxa_1) - (uint32_t)(65UL)) & 255UL), 4UL, 8, 0, 0));
    vxo[0] = (((uint32_t)((((uint32_t)((((uint32_t)(vxa_0) - (uint32_t)(65UL)) & 255UL)) | (uint32_t)(vx_shift((((uint32_t)(vxa_1) - (uint32_t)(65UL)) & 255UL), 4UL, 8, 0, 0))) & 255UL)) ^ (uint32_t)(70UL)) & 255UL);
}
void vx_flow_4(uint32_t *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI VX_RESIDENT {
    (void)(vx_shift((((uint32_t)(vxa_1) - (uint32_t)(65UL)) & 255UL), 4UL, 8, 0, 0));
    vxo[0] = (((uint32_t)((((uint32_t)((((uint32_t)(vxa_0) - (uint32_t)(65UL)) & 255UL)) | (uint32_t)(vx_shift((((uint32_t)(vxa_1) - (uint32_t)(65UL)) & 255UL), 4UL, 8, 0, 0))) & 255UL)) ^ (uint32_t)(56UL)) & 255UL);
}
void vx_flow_5(uint32_t *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI VX_RESIDENT {
    (void)(vx_shift((((uint32_t)(vxa_1) - (uint32_t)(65UL)) & 255UL), 4UL, 8, 0, 0));
    vxo[0] = (((uint32_t)((((uint32_t)((((uint32_t)(vxa_0) - (uint32_t)(65UL)) & 255UL)) | (uint32_t)(vx_shift((((uint32_t)(vxa_1) - (uint32_t)(65UL)) & 255UL), 4UL, 8, 0, 0))) & 255UL)) ^ (uint32_t)(115UL)) & 255UL);
}
void vx_flow_6(uint32_t *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1, VX_STABLE uint8_t vxa_2, VX_STABLE uint8_t vxa_3, VX_STABLE uint8_t vxa_4, VX_STABLE uint8_t vxa_5, VX_STABLE uint8_t vxa_6, VX_STABLE uint8_t vxa_7, VX_STABLE uint8_t vxa_8, VX_STABLE uint8_t vxa_9, VX_STABLE uint8_t vxa_10, VX_STABLE uint8_t vxa_11, VX_STABLE uint8_t vxa_12, VX_STABLE uint8_t vxa_13, VX_STABLE uint8_t vxa_14) VX_ABI VX_RESIDENT {
    uint32_t vxt_16[1];
    vx_flow_7(vxt_16, vxa_1, vxa_2, vxa_3, vxa_4, vxa_5, vxa_6, vxa_7, vxa_8, vxa_9, vxa_10);
    if (((((((((((((((((((((((uint32_t)(vxa_0) == (uint32_t)(10UL)) ? ((uint32_t)(vxa_1) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_1) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_2) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_2) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_3) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_3) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_4) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_4) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_5) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_5) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_6) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_6) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_7) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_7) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_8) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_8) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_9) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_9) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_10) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_10) <= (uint32_t)(80UL)) : 0UL)) {
        (void)(vx_shift(VX_SNAPSHOT32(vxt_16[0]), 4UL, 8, 1, 0));
    } else {
    }
    vxo[0] = ((((((((uint32_t)(vxa_0) == (uint32_t)(5UL)) ? ((uint32_t)(vxa_1) == (uint32_t)(78UL)) : 0UL) ? ((uint32_t)(vxa_2) == (uint32_t)(73UL)) : 0UL) ? ((uint32_t)(vxa_3) == (uint32_t)(83UL)) : 0UL) ? ((uint32_t)(vxa_4) == (uint32_t)(72UL)) : 0UL) ? ((uint32_t)(vxa_5) == (uint32_t)(73UL)) : 0UL) ? 2UL : (((((((uint32_t)(vxa_0) == (uint32_t)(4UL)) ? ((uint32_t)(vxa_1) == (uint32_t)(77UL)) : 0UL) ? ((uint32_t)(vxa_2) == (uint32_t)(83UL)) : 0UL) ? ((uint32_t)(vxa_3) == (uint32_t)(88UL)) : 0UL) ? ((uint32_t)(vxa_4) == (uint32_t)(50UL)) : 0UL) ? 3UL : ((((((((((((((((((((((((((((((((uint32_t)(vxa_0) == (uint32_t)(10UL)) ? ((uint32_t)(vxa_1) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_1) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_2) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_2) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_3) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_3) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_4) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_4) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_5) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_5) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_6) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_6) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_7) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_7) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_8) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_8) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_9) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_9) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_10) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_10) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_9) == (uint32_t)((((uint32_t)(65UL) + (uint32_t)(vx_shift(VX_SNAPSHOT32(vxt_16[0]), 4UL, 8, 1, 0))) & 255UL))) : 0UL) ? ((uint32_t)(vxa_10) == (uint32_t)((((uint32_t)(65UL) + (uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_16[0])) & (uint32_t)(15UL)) & 255UL))) & 255UL))) : 0UL) ? ((uint32_t)((((uint32_t)(vxa_11) & (uint32_t)(240UL)) & 255UL)) == (uint32_t)(0UL)) : 0UL) ? ((uint32_t)((((uint32_t)(vxa_13) & (uint32_t)(192UL)) & 255UL)) == (uint32_t)(0UL)) : 0UL) ? ((uint32_t)((((uint32_t)(vxa_14) & (uint32_t)(224UL)) & 255UL)) == (uint32_t)(0UL)) : 0UL) ? ((uint32_t)(vxa_13) <= (uint32_t)(62UL)) : 0UL) ? ((uint32_t)(vxa_14) >= (uint32_t)(3UL)) : 0UL) ? ((uint32_t)(vxa_14) <= (uint32_t)(20UL)) : 0UL) ? ((uint32_t)((((uint32_t)(vxa_12) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) : 0UL) ? 1UL : 0UL)));
}
void vx_flow_7(uint32_t *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1, VX_STABLE uint8_t vxa_2, VX_STABLE uint8_t vxa_3, VX_STABLE uint8_t vxa_4, VX_STABLE uint8_t vxa_5, VX_STABLE uint8_t vxa_6, VX_STABLE uint8_t vxa_7, VX_STABLE uint8_t vxa_8, VX_STABLE uint8_t vxa_9) VX_ABI VX_RESIDENT {
    vxo[0] = (((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(70UL) + (uint32_t)(vxa_0)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_1)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_2)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_3)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_4)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_5)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_6)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_7)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL);
}
void vx_password_decode(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1_0,VX_STABLE uint8_t vxp_a1_1,VX_STABLE uint8_t vxp_a1_2,VX_STABLE uint8_t vxp_a1_3,VX_STABLE uint8_t vxp_a1_4,VX_STABLE uint8_t vxp_a1_5,VX_STABLE uint8_t vxp_a1_6,VX_STABLE uint8_t vxp_a1_7,VX_STABLE uint8_t vxp_a1_8,VX_STABLE uint8_t vxp_a1_9,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    uint32_t vxt_0[1];
    uint32_t vxt_1[1];
    uint32_t vxt_10[1];
    uint32_t vxt_12[1];
    uint32_t vxt_13[1];
    uint32_t vxt_14[1];
    uint32_t vxt_15[1];
    uint32_t vxt_2[1];
    uint32_t vxt_3[1];
    uint32_t vxt_4[1];
    uint32_t vxt_5[1];
    uint32_t vxt_6[1];
    uint32_t vxt_7[1];
    uint32_t vxt_8[1];
    uint32_t vxt_9[1];
    vx_flow_0(vxt_0, vxp_a1_0);
    vx_flow_0(vxt_1, vxp_a1_1);
    vx_flow_0(vxt_2, vxp_a1_2);
    vx_flow_0(vxt_3, vxp_a1_3);
    vx_flow_0(vxt_4, vxp_a1_4);
    vx_flow_0(vxt_5, vxp_a1_5);
    vx_flow_0(vxt_6, vxp_a1_6);
    vx_flow_0(vxt_7, vxp_a1_7);
    vx_flow_0(vxt_8, vxp_a1_8);
    vx_flow_0(vxt_9, vxp_a1_9);
    vx_flow_1(vxt_10, VX_SNAPSHOT32(vxt_0[0]), VX_SNAPSHOT32(vxt_1[0]));
    vx_flow_3(vxt_12, VX_SNAPSHOT32(vxt_2[0]), VX_SNAPSHOT32(vxt_3[0]));
    vx_flow_4(vxt_13, VX_SNAPSHOT32(vxt_4[0]), VX_SNAPSHOT32(vxt_5[0]));
    vx_flow_5(vxt_14, VX_SNAPSHOT32(vxt_6[0]), VX_SNAPSHOT32(vxt_7[0]));
    vx_flow_6(vxt_15, vxp_a0, VX_SNAPSHOT32(vxt_0[0]), VX_SNAPSHOT32(vxt_1[0]), VX_SNAPSHOT32(vxt_2[0]), VX_SNAPSHOT32(vxt_3[0]), VX_SNAPSHOT32(vxt_4[0]), VX_SNAPSHOT32(vxt_5[0]), VX_SNAPSHOT32(vxt_6[0]), VX_SNAPSHOT32(vxt_7[0]), VX_SNAPSHOT32(vxt_8[0]), VX_SNAPSHOT32(vxt_9[0]), VX_SNAPSHOT32(vxt_10[0]), VX_SNAPSHOT32(vxt_12[0]), VX_SNAPSHOT32(vxt_13[0]), VX_SNAPSHOT32(vxt_14[0]));
    if (((uint32_t)(vxp_a2) < (uint32_t)(8UL))) {
        (void)(vx_shift(1UL, (((uint32_t)(vxp_a2) & (uint32_t)(7UL)) & 255UL), 8, 0, 0));
    } else {
    }
    if (((uint32_t)(VX_SNAPSHOT32(vxt_15[0])) >= (uint32_t)(2UL))) {
    } else {
        (void)(vx_shift((((uint32_t)(VX_SNAPSHOT32(vxt_13[0]))) & 65535UL), 4UL, 16, 0, 0));
    }
    if (((uint32_t)(VX_SNAPSHOT32(vxt_15[0])) == (uint32_t)(2UL))) {
    } else {
        (void)(vx_shift(VX_SNAPSHOT32(vxt_14[0]), 1UL, 8, 0, 0));
    }
    VX_STABLE uint32_t vxo_0 = (uint32_t)(VX_SNAPSHOT32(vxt_15[0]));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT32(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_0))) >> 8);
    VX_STABLE uint32_t vxo_1 = (uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_15[0])) == (uint32_t)(2UL)) ? 15UL : (((uint32_t)(VX_SNAPSHOT32(vxt_10[0])) & (uint32_t)(15UL)) & 255UL)));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT32(vxo_1));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_1))) >> 8);
    VX_STABLE uint32_t vxo_2 = (uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_15[0])) == (uint32_t)(2UL)) ? 255UL : VX_SNAPSHOT32(vxt_12[0])));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT32(vxo_2));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_2))) >> 8);
    VX_STABLE uint32_t vxo_3 = (uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_15[0])) >= (uint32_t)(2UL)) ? 999UL : vx_shift((((uint32_t)(VX_SNAPSHOT32(vxt_13[0]))) & 65535UL), 4UL, 16, 0, 0)));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT32(vxo_3));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_3))) >> 8);
    VX_STABLE uint32_t vxo_4 = (uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_15[0])) == (uint32_t)(2UL)) ? 40UL : vx_shift(VX_SNAPSHOT32(vxt_14[0]), 1UL, 8, 0, 0)));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT32(vxo_4));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_4))) >> 8);
    VX_STABLE uint32_t vxo_5 = (uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_15[0])) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a2) < (uint32_t)(8UL)) ? vxp_a2 : 0UL) : ((((uint32_t)(vxp_a2) < (uint32_t)(8UL)) ? ((uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_12[0])) & (uint32_t)(vx_shift(1UL, (((uint32_t)(vxp_a2) & (uint32_t)(7UL)) & 255UL), 8, 0, 0))) & 255UL)) != (uint32_t)(0UL)) : 0UL) ? vxp_a2 : 0UL)));
    vx_payload[10] = (uint8_t)(VX_SNAPSHOT32(vxo_5));
    vx_payload[11] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_5))) >> 8);
    VX_STABLE uint32_t vxo_6 = (uint32_t)((((uint32_t)(37UL) + (uint32_t)(VX_SNAPSHOT32(vxt_15[0]))) & 255UL));
    vx_payload[12] = (uint8_t)(VX_SNAPSHOT32(vxo_6));
    vx_payload[13] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_6))) >> 8);
}
uint32_t vx_password_decode_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    case 5: return (uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8);
    case 6: return (uint32_t)vx_payload[12] + ((uint32_t)vx_payload[13] << 8);
    default: vx_trap(16); return 0;
    }
}
