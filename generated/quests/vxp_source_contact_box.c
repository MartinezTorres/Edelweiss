/* Editable NEO-8 window B module. Keep the generated ABI. */
#include "vexel.h"
#include "vx_support_value_base.h"
#include "vx_support_value_add8.h"
#include "vx_support_value_lt8.h"
void vxi_vx_contact_box(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint8_t vxp_a5) VX_ABI {
    static VX_STABLE uint8_t vx_calc_uint8_t_0;
    static VX_STABLE uint8_t vx_calc_uint8_t_1;
    if (((uint32_t)(((vx_calc_uint8_t_0 = ((uint16_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a4)) + ((uint16_t)(16)))))) >> 1))))), ((uint32_t)((((uint32_t)((!VX_VALUE_LT8(((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(((uint8_t)(vx_calc_uint8_t_0)))))) << 1)))), ((uint8_t)(((uint8_t)(VX_VALUE_ADD8(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a0)) - ((uint16_t)(vxp_a2)))))) >> 5))))))), ((uint8_t)(((uint8_t)(vx_calc_uint8_t_0))))))))))))) & 255UL)))) ? 1UL : 0UL)) != (uint32_t)(0UL))) {
    } else {
    }
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)(((((uint32_t)(((vx_calc_uint8_t_1 = ((uint16_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a4)) + ((uint16_t)(16)))))) >> 1))))), ((uint32_t)((((uint32_t)((!VX_VALUE_LT8(((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(((uint8_t)(vx_calc_uint8_t_1)))))) << 1)))), ((uint8_t)(((uint8_t)(VX_VALUE_ADD8(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a0)) - ((uint16_t)(vxp_a2)))))) >> 5))))))), ((uint8_t)(((uint8_t)(vx_calc_uint8_t_1))))))))))))) & 255UL)))) ? 1UL : 0UL)) != (uint32_t)(0UL)) ? ((uint32_t)(((vx_calc_uint8_t_0 = ((uint16_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a5)) + ((uint16_t)(16)))))) >> 1))))), ((uint32_t)((((uint32_t)((!VX_VALUE_LT8(((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(((uint8_t)(vx_calc_uint8_t_0)))))) << 1)))), ((uint8_t)(((uint8_t)(VX_VALUE_ADD8(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) - ((uint16_t)(vxp_a3)))))) >> 5))))))), ((uint8_t)(((uint8_t)(vx_calc_uint8_t_0))))))))))))) & 255UL)))) ? 1UL : 0UL)) != (uint32_t)(0UL)) : 0UL) ? 1UL : 0UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
