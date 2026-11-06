#include "vexel.h"
void vx_flow_2(uint32_t *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1, VX_STABLE uint8_t vxa_2, VX_STABLE uint8_t vxa_3, VX_STABLE uint8_t vxa_4, VX_STABLE uint8_t vxa_5, VX_STABLE uint8_t vxa_6) VX_ABI VX_RESIDENT {
    vxo[0] = (((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(70UL) + (uint32_t)(vxa_0)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(73UL)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_1)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_2)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_3)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_4)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_5)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_6)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL);
}
void vx_password_encode(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI VX_RESIDENT {
    uint32_t vxt_11[1];
    (void)(vx_shift(vxp_a2, 4UL, 16, 1, 0));
    (void)(vx_shift(vxp_a3, 1UL, 8, 1, 0));
    (void)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(15UL)) & 255UL)) ^ (uint32_t)(130UL)) & 255UL), 4UL, 8, 1, 0));
    (void)(vx_shift((((uint32_t)(vxp_a1) ^ (uint32_t)(70UL)) & 255UL), 4UL, 8, 1, 0));
    (void)(vx_shift((((uint32_t)((((uint32_t)((((uint32_t)(vx_shift(vxp_a2, 4UL, 16, 1, 0)) & (uint32_t)(63UL)) & 65535UL))) & 255UL)) ^ (uint32_t)(56UL)) & 255UL), 4UL, 8, 1, 0));
    (void)(vx_shift((((uint32_t)((((uint32_t)(vx_shift(vxp_a3, 1UL, 8, 1, 0)) & (uint32_t)(31UL)) & 255UL)) ^ (uint32_t)(115UL)) & 255UL), 4UL, 8, 1, 0));
    vx_flow_2(vxt_11, (((uint32_t)(65UL) + (uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(15UL)) & 255UL)) ^ (uint32_t)(130UL)) & 255UL)) & (uint32_t)(15UL)) & 255UL))) & 255UL), (((uint32_t)(65UL) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) ^ (uint32_t)(70UL)) & 255UL)) & (uint32_t)(15UL)) & 255UL))) & 255UL), (((uint32_t)(65UL) + (uint32_t)(vx_shift((((uint32_t)(vxp_a1) ^ (uint32_t)(70UL)) & 255UL), 4UL, 8, 1, 0))) & 255UL), (((uint32_t)(65UL) + (uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vx_shift(vxp_a2, 4UL, 16, 1, 0)) & (uint32_t)(63UL)) & 65535UL))) & 255UL)) ^ (uint32_t)(56UL)) & 255UL)) & (uint32_t)(15UL)) & 255UL))) & 255UL), (((uint32_t)(65UL) + (uint32_t)(vx_shift((((uint32_t)((((uint32_t)((((uint32_t)(vx_shift(vxp_a2, 4UL, 16, 1, 0)) & (uint32_t)(63UL)) & 65535UL))) & 255UL)) ^ (uint32_t)(56UL)) & 255UL), 4UL, 8, 1, 0))) & 255UL), (((uint32_t)(65UL) + (uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vx_shift(vxp_a3, 1UL, 8, 1, 0)) & (uint32_t)(31UL)) & 255UL)) ^ (uint32_t)(115UL)) & 255UL)) & (uint32_t)(15UL)) & 255UL))) & 255UL), (((uint32_t)(65UL) + (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vx_shift(vxp_a3, 1UL, 8, 1, 0)) & (uint32_t)(31UL)) & 255UL)) ^ (uint32_t)(115UL)) & 255UL), 4UL, 8, 1, 0))) & 255UL));
    (void)(vx_shift(VX_SNAPSHOT32(vxt_11[0]), 4UL, 8, 1, 0));
    VX_STABLE uint32_t vxo_0 = (uint32_t)((((uint32_t)(65UL) + (uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(15UL)) & 255UL)) ^ (uint32_t)(130UL)) & 255UL)) & (uint32_t)(15UL)) & 255UL))) & 255UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT32(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_0))) >> 8);
    VX_STABLE uint32_t vxo_1 = (uint32_t)(73UL);
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT32(vxo_1));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_1))) >> 8);
    VX_STABLE uint32_t vxo_2 = (uint32_t)((((uint32_t)(65UL) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) ^ (uint32_t)(70UL)) & 255UL)) & (uint32_t)(15UL)) & 255UL))) & 255UL));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT32(vxo_2));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_2))) >> 8);
    VX_STABLE uint32_t vxo_3 = (uint32_t)((((uint32_t)(65UL) + (uint32_t)(vx_shift((((uint32_t)(vxp_a1) ^ (uint32_t)(70UL)) & 255UL), 4UL, 8, 1, 0))) & 255UL));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT32(vxo_3));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_3))) >> 8);
    VX_STABLE uint32_t vxo_4 = (uint32_t)((((uint32_t)(65UL) + (uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vx_shift(vxp_a2, 4UL, 16, 1, 0)) & (uint32_t)(63UL)) & 65535UL))) & 255UL)) ^ (uint32_t)(56UL)) & 255UL)) & (uint32_t)(15UL)) & 255UL))) & 255UL));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT32(vxo_4));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_4))) >> 8);
    VX_STABLE uint32_t vxo_5 = (uint32_t)((((uint32_t)(65UL) + (uint32_t)(vx_shift((((uint32_t)((((uint32_t)((((uint32_t)(vx_shift(vxp_a2, 4UL, 16, 1, 0)) & (uint32_t)(63UL)) & 65535UL))) & 255UL)) ^ (uint32_t)(56UL)) & 255UL), 4UL, 8, 1, 0))) & 255UL));
    vx_payload[10] = (uint8_t)(VX_SNAPSHOT32(vxo_5));
    vx_payload[11] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_5))) >> 8);
    VX_STABLE uint32_t vxo_6 = (uint32_t)((((uint32_t)(65UL) + (uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vx_shift(vxp_a3, 1UL, 8, 1, 0)) & (uint32_t)(31UL)) & 255UL)) ^ (uint32_t)(115UL)) & 255UL)) & (uint32_t)(15UL)) & 255UL))) & 255UL));
    vx_payload[12] = (uint8_t)(VX_SNAPSHOT32(vxo_6));
    vx_payload[13] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_6))) >> 8);
    VX_STABLE uint32_t vxo_7 = (uint32_t)((((uint32_t)(65UL) + (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vx_shift(vxp_a3, 1UL, 8, 1, 0)) & (uint32_t)(31UL)) & 255UL)) ^ (uint32_t)(115UL)) & 255UL), 4UL, 8, 1, 0))) & 255UL));
    vx_payload[14] = (uint8_t)(VX_SNAPSHOT32(vxo_7));
    vx_payload[15] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_7))) >> 8);
    VX_STABLE uint32_t vxo_8 = (uint32_t)((((uint32_t)(65UL) + (uint32_t)(vx_shift(VX_SNAPSHOT32(vxt_11[0]), 4UL, 8, 1, 0))) & 255UL));
    vx_payload[16] = (uint8_t)(VX_SNAPSHOT32(vxo_8));
    vx_payload[17] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_8))) >> 8);
    VX_STABLE uint32_t vxo_9 = (uint32_t)((((uint32_t)(65UL) + (uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_11[0])) & (uint32_t)(15UL)) & 255UL))) & 255UL));
    vx_payload[18] = (uint8_t)(VX_SNAPSHOT32(vxo_9));
    vx_payload[19] = (uint8_t)(((uint32_t)(VX_SNAPSHOT32(vxo_9))) >> 8);
}
uint32_t vx_password_encode_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    case 5: return (uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8);
    case 6: return (uint32_t)vx_payload[12] + ((uint32_t)vx_payload[13] << 8);
    case 7: return (uint32_t)vx_payload[14] + ((uint32_t)vx_payload[15] << 8);
    case 8: return (uint32_t)vx_payload[16] + ((uint32_t)vx_payload[17] << 8);
    case 9: return (uint32_t)vx_payload[18] + ((uint32_t)vx_payload[19] << 8);
    default: vx_trap(16); return 0;
    }
}
