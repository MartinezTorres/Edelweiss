/* Editable NEO-8 window B module. Keep the generated ABI. */
#include "vexel.h"
void vxi_vx_flow_0(vx_flow_0_result *vxo, VX_STABLE uint8_t vxa_0) VX_ABI {
    vxo->v0 = ((((uint32_t)(vxa_0) >= (uint32_t)(97UL)) ? ((uint32_t)(vxa_0) <= (uint32_t)(122UL)) : 0UL) ? (((uint32_t)(vxa_0) - (uint32_t)(32UL)) & 255UL) : vxa_0);
}
