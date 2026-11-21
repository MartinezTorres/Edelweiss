/* Editable NEO-8 window B module. Keep the generated ABI. */
#include "vexel.h"
#include "vx_support_value_base.h"
void vxi_vx_password_encode(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI {
    static VX_STABLE uint8_t vx_calc_uint8_t_0;
    static vx_flow_2_result vxt_25;
    vx_flow_2(&vxt_25, (((uint32_t)(65UL) + (uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(15UL)) & 255UL)) ^ (uint32_t)(130UL)) & 255UL)) & (uint32_t)(15UL)) & 255UL))) & 255UL), (((uint32_t)(65UL) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) ^ (uint32_t)(70UL)) & 255UL)) & (uint32_t)(15UL)) & 255UL))) & 255UL), (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(65)) + ((uint8_t)(((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) ^ ((uint8_t)(70)))))) >> 4) & 15U))))))))) & 255UL)))), (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(65)) + ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(vxp_a2)) >> 4))))) & ((uint8_t)(63)))))))) ^ ((uint8_t)(56)))))) & ((uint8_t)(15)))))))))) & 255UL)))), (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(65)) + ((uint8_t)(((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(vxp_a2)) >> 4))))) & ((uint8_t)(63)))))))) ^ ((uint8_t)(56)))))) >> 4) & 15U))))))))) & 255UL)))), (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(65)) + ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a3)) >> 1))))) & ((uint8_t)(31)))))) ^ ((uint8_t)(115)))))) & ((uint8_t)(15)))))))))) & 255UL)))), (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(65)) + ((uint8_t)(((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a3)) >> 1))))) & ((uint8_t)(31)))))) ^ ((uint8_t)(115)))))) >> 4) & 15U))))))))) & 255UL)))));
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(65)) + ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) & ((uint8_t)(15)))))) ^ ((uint8_t)(130)))))) & ((uint8_t)(15)))))))))) & 255UL)))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(73)) & 255UL)))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((vx_calc_uint8_t_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) ^ ((uint8_t)(70)))))), ((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(65)) + ((uint8_t)(((uint8_t)(((uint8_t)(vx_calc_uint8_t_0)) & ((uint8_t)(15)))))))))) & 255UL)))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(65)) + ((uint8_t)(((uint8_t)(((((uint8_t)(vx_calc_uint8_t_0)) >> 4) & 15U))))))))) & 255UL)))));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((vx_calc_uint8_t_0 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(vxp_a2)) >> 4))))) & ((uint8_t)(63)))))))) ^ ((uint8_t)(56)))))), ((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(65)) + ((uint8_t)(((uint8_t)(((uint8_t)(vx_calc_uint8_t_0)) & ((uint8_t)(15)))))))))) & 255UL)))));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(65)) + ((uint8_t)(((uint8_t)(((((uint8_t)(vx_calc_uint8_t_0)) >> 4) & 15U))))))))) & 255UL)))));
    vx_payload[10] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[11] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((vx_calc_uint8_t_0 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a3)) >> 1))))) & ((uint8_t)(31)))))) ^ ((uint8_t)(115)))))), ((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(65)) + ((uint8_t)(((uint8_t)(((uint8_t)(vx_calc_uint8_t_0)) & ((uint8_t)(15)))))))))) & 255UL)))));
    vx_payload[12] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[13] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(65)) + ((uint8_t)(((uint8_t)(((((uint8_t)(vx_calc_uint8_t_0)) >> 4) & 15U))))))))) & 255UL)))));
    vx_payload[14] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[15] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(65)) + ((uint8_t)(((uint8_t)(((((uint8_t)(VX_SNAPSHOT8(vxt_25.v0))) >> 4) & 15U))))))))) & 255UL)))));
    vx_payload[16] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[17] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(65)) + ((uint8_t)(((uint8_t)(((uint8_t)(VX_SNAPSHOT8(vxt_25.v0))) & ((uint8_t)(15)))))))))) & 255UL)))));
    vx_payload[18] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[19] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
