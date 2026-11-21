/* Editable NEO-8 window B module. Keep the generated ABI. */
#include "vexel.h"
#include "vx_support_value_base.h"
void vxi_vx_spark_frame(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(vxp_a0)) + ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a0)))) << 1)))))))) & 255UL))))) + (uint32_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a1) == (uint32_t)(1UL)) ? 1UL : 2UL)))) & 255UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
