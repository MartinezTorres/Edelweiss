/* Generated from relational source obligations and a closed activation contract. */
#include "vexel.h"
#undef VX_VALUE_LOCATION
#define VX_VALUE_LOCATION VX_RESIDENT
#include "vx_support_value_base.h"
#include "vx_support_value_add8.h"
#include "vx_support_value_and8.h"
#include "vx_support_value_lt8.h"
#include "vx_support_value_mul16.h"
#ifndef VX_SUPPORT_scale8_24
#define VX_SUPPORT_scale8_24
#ifdef __SDCC
static uint8_t vx_value_scale8_24(uint8_t x) __sdcccall(1) VX_VALUE_LOCATION {
    return (uint8_t)(((uint32_t)x << 3) + ((uint32_t)x << 4));
}
#else
static inline uint8_t vx_value_scale8_24(uint8_t x) {
    return (uint8_t)((uint32_t)x * 24U);
}
#endif
#endif
#ifndef VX_SUPPORT_scale8_3
#define VX_SUPPORT_scale8_3
#ifdef __SDCC
static uint8_t vx_value_scale8_3(uint8_t x) __sdcccall(1) VX_VALUE_LOCATION {
    return (uint8_t)((uint32_t)x + ((uint32_t)x << 1));
}
#else
static inline uint8_t vx_value_scale8_3(uint8_t x) {
    return (uint8_t)((uint32_t)x * 3U);
}
#endif
#endif
#include "vx_support_value_sub8.h"
#undef VX_VALUE_LOCATION
#define VX_VALUE_LOCATION
/* Local storage follows the per-function plan; ABI parameters remain automatic. */
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
void vx_invoke_external_flow_yield(uint32_t *result) VX_ABI VX_RESIDENT {
    vx_external_flow_yield(result);
    if (result[0] > 255UL) vx_trap(16);
}
void vx_invoke_external_flow_slot(uint32_t *result, uint8_t p0) VX_ABI VX_RESIDENT {
    vx_external_flow_slot(result, p0);
    if (vx_signed(result[0], 32) < -128L || vx_signed(result[0], 32) > 127L) vx_trap(16);
}
void vx_invoke_external_flow_actor(uint32_t *result, uint8_t p0) VX_ABI VX_RESIDENT {
    vx_external_flow_actor(result, p0);
    if (result[0] > 255UL) vx_trap(16);
    if (result[1] > 255UL) vx_trap(16);
    if (result[2] > 255UL) vx_trap(16);
    if (result[3] > 255UL) vx_trap(16);
}
void vx_invoke_external_flow_flags(uint32_t *result, uint8_t p0) VX_ABI VX_RESIDENT {
    vx_external_flow_flags(result, p0);
    if (result[0] > 255UL) vx_trap(16);
    if (vx_signed(result[1], 32) < -128L || vx_signed(result[1], 32) > 127L) vx_trap(16);
}
void vx_invoke_external_flow_update(uint32_t *result, uint8_t p0) VX_ABI VX_RESIDENT {
    vx_external_flow_update(result, p0);
    if (result[0] > 255UL) vx_trap(16);
}
void vx_invoke_external_flow_despawn(uint32_t *result, uint8_t p0) VX_ABI VX_RESIDENT {
    vx_external_flow_despawn(result, p0);
    if (result[0] > 255UL) vx_trap(16);
}
void vx_invoke_external_flow_spawn(uint32_t *result, uint8_t p0) VX_ABI VX_RESIDENT {
    vx_external_flow_spawn(result, p0);
    if (result[0] > 255UL) vx_trap(16);
}
void vx_invoke_external_flow_cycle(uint32_t *result) VX_ABI VX_RESIDENT {
    vx_external_flow_cycle(result);
    if (result[0] > 255UL) vx_trap(16);
}
void vx_flow_0(vx_flow_0_result *vxo, VX_STABLE uint8_t vxa_0) VX_ABI VX_RESIDENT {
    vxo->v0 = ((((uint32_t)(vxa_0) >= (uint32_t)(97UL)) ? ((uint32_t)(vxa_0) <= (uint32_t)(122UL)) : 0UL) ? (((uint32_t)(vxa_0) - (uint32_t)(32UL)) & 255UL) : vxa_0);
}
void vx_flow_1(vx_flow_1_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI VX_RESIDENT {
    vxo->v0 = (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vxa_0)) - ((uint8_t)(65)))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(((uint8_t)(((uint8_t)(vxa_1)) - ((uint8_t)(65)))))))) << 4)))))))) ^ ((uint8_t)(130)))))) & 255UL))));
}
void vx_flow_2(vx_flow_2_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1, VX_STABLE uint8_t vxa_2, VX_STABLE uint8_t vxa_3, VX_STABLE uint8_t vxa_4, VX_STABLE uint8_t vxa_5, VX_STABLE uint8_t vxa_6) VX_ABI VX_RESIDENT {
    vxo->v0 = (((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(70UL) + (uint32_t)(vxa_0)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(73UL)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_1)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_2)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_3)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_4)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_5)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_6)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL);
}
void vx_flow_3(vx_flow_3_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI VX_RESIDENT {
    vxo->v0 = (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vxa_0)) - ((uint8_t)(65)))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(((uint8_t)(((uint8_t)(vxa_1)) - ((uint8_t)(65)))))))) << 4)))))))) ^ ((uint8_t)(70)))))) & 255UL))));
}
void vx_flow_4(vx_flow_4_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI VX_RESIDENT {
    vxo->v0 = (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vxa_0)) - ((uint8_t)(65)))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(((uint8_t)(((uint8_t)(vxa_1)) - ((uint8_t)(65)))))))) << 4)))))))) ^ ((uint8_t)(56)))))) & 255UL))));
}
void vx_flow_5(vx_flow_5_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI VX_RESIDENT {
    vxo->v0 = (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vxa_0)) - ((uint8_t)(65)))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(((uint8_t)(((uint8_t)(vxa_1)) - ((uint8_t)(65)))))))) << 4)))))))) ^ ((uint8_t)(115)))))) & 255UL))));
}
void vx_flow_6(vx_flow_6_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1, VX_STABLE uint8_t vxa_2, VX_STABLE uint8_t vxa_3, VX_STABLE uint8_t vxa_4, VX_STABLE uint8_t vxa_5, VX_STABLE uint8_t vxa_6, VX_STABLE uint8_t vxa_7, VX_STABLE uint8_t vxa_8, VX_STABLE uint8_t vxa_9, VX_STABLE uint8_t vxa_10, VX_STABLE uint8_t vxa_11, VX_STABLE uint8_t vxa_12, VX_STABLE uint8_t vxa_13, VX_STABLE uint8_t vxa_14) VX_ABI VX_RESIDENT {
    static vx_flow_7_result vxt_31;
    vx_flow_7(&vxt_31, vxa_1, vxa_2, vxa_3, vxa_4, vxa_5, vxa_6, vxa_7, vxa_8);
    if (((((((((((((((((((((((uint32_t)(vxa_0) == (uint32_t)(10UL)) ? ((uint32_t)(vxa_1) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_1) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_2) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_2) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_3) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_3) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_4) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_4) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_5) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_5) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_6) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_6) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_7) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_7) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_8) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_8) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_9) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_9) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_10) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_10) <= (uint32_t)(80UL)) : 0UL)) {
    } else {
    }
    vxo->v0 = ((((((((uint32_t)(vxa_0) == (uint32_t)(5UL)) ? ((uint32_t)(vxa_1) == (uint32_t)(78UL)) : 0UL) ? ((uint32_t)(vxa_2) == (uint32_t)(73UL)) : 0UL) ? ((uint32_t)(vxa_3) == (uint32_t)(83UL)) : 0UL) ? ((uint32_t)(vxa_4) == (uint32_t)(72UL)) : 0UL) ? ((uint32_t)(vxa_5) == (uint32_t)(73UL)) : 0UL) ? 2UL : (((((((uint32_t)(vxa_0) == (uint32_t)(4UL)) ? ((uint32_t)(vxa_1) == (uint32_t)(77UL)) : 0UL) ? ((uint32_t)(vxa_2) == (uint32_t)(83UL)) : 0UL) ? ((uint32_t)(vxa_3) == (uint32_t)(88UL)) : 0UL) ? ((uint32_t)(vxa_4) == (uint32_t)(50UL)) : 0UL) ? 3UL : ((((((((((((((((((((((((((((((((uint32_t)(vxa_0) == (uint32_t)(10UL)) ? ((uint32_t)(vxa_1) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_1) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_2) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_2) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_3) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_3) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_4) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_4) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_5) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_5) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_6) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_6) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_7) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_7) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_8) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_8) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_9) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_9) <= (uint32_t)(80UL)) : 0UL) ? ((uint32_t)(vxa_10) >= (uint32_t)(65UL)) : 0UL) ? ((uint32_t)(vxa_10) <= (uint32_t)(80UL)) : 0UL) ? (((uint32_t)((((uint32_t)((((uint8_t)(vxa_9)) == ((uint8_t)(((uint8_t)(((uint8_t)(65)) + ((uint8_t)(((uint8_t)(((((uint8_t)(VX_SNAPSHOT8(vxt_31.v0))) >> 4) & 15U)))))))))))) & 255UL)))) : 0UL) ? ((uint32_t)(vxa_10) == (uint32_t)((((uint32_t)(65UL) + (uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxt_31.v0)) & (uint32_t)(15UL)) & 255UL))) & 255UL))) : 0UL) ? ((uint32_t)((((uint32_t)(vxa_11) & (uint32_t)(240UL)) & 255UL)) == (uint32_t)(0UL)) : 0UL) ? ((uint32_t)((((uint32_t)(vxa_13) & (uint32_t)(192UL)) & 255UL)) == (uint32_t)(0UL)) : 0UL) ? ((uint32_t)((((uint32_t)(vxa_14) & (uint32_t)(224UL)) & 255UL)) == (uint32_t)(0UL)) : 0UL) ? ((uint32_t)(vxa_13) <= (uint32_t)(62UL)) : 0UL) ? ((uint32_t)(vxa_14) >= (uint32_t)(3UL)) : 0UL) ? ((uint32_t)(vxa_14) <= (uint32_t)(20UL)) : 0UL) ? ((uint32_t)((((uint32_t)(vxa_12) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) : 0UL) ? 1UL : 0UL)));
}
void vx_flow_7(vx_flow_7_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1, VX_STABLE uint8_t vxa_2, VX_STABLE uint8_t vxa_3, VX_STABLE uint8_t vxa_4, VX_STABLE uint8_t vxa_5, VX_STABLE uint8_t vxa_6, VX_STABLE uint8_t vxa_7) VX_ABI VX_RESIDENT {
    vxo->v0 = (((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(70UL) + (uint32_t)(vxa_0)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_1)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_2)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_3)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_4)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_5)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_6)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL)) + (uint32_t)(vxa_7)) & 255UL)) ^ (uint32_t)(55UL)) & 255UL);
}
uint8_t vx_payload[20];
void vx_lumberjack(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a1) == (uint32_t)(4UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(5UL)) : 0UL) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(1UL)) : 0UL) ? 1UL : ((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 2UL : ((((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 3UL : ((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(2UL)) : 0UL) ? 4UL : ((((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 5UL : vxp_a0)))))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a1) == (uint32_t)(4UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(5UL)) : 0UL) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(1UL)) : 0UL) ? 1UL : ((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 1UL : ((((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 2UL : ((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(2UL)) : 0UL) ? 1UL : ((((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 3UL : 0UL)))))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a1) == (uint32_t)(4UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(5UL)) : 0UL) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(1UL)) : 0UL) ? 1UL : ((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 2UL : ((((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(3UL)) : 0UL) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(2UL)) : 0UL) ? 3UL : 0UL))))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_lumberjack_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_pear(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(0UL)) : 0UL) ? 2UL : (((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? 2UL : 1UL)));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(0UL)) : 0UL) ? 1UL : 0UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(0UL)) : 0UL) ? (((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? 0UL : 1UL) : 0UL));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(0UL)) : 0UL) ? (((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? 100UL : 0UL) : 0UL));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(0UL)) : 0UL) ? (((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? 6UL : 5UL) : 4UL));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_pear_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_stew(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) > (uint32_t)(38UL)) ? 0UL : (((uint32_t)(vxp_a1) < (uint32_t)(200UL)) ? 0UL : (((uint32_t)(vxp_a2) == (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vxp_a2) == (uint32_t)(1UL)) ? 0UL : 2UL)))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) > (uint32_t)(38UL)) ? 0UL : (((uint32_t)(vxp_a1) < (uint32_t)(200UL)) ? 0UL : (((uint32_t)(vxp_a2) == (uint32_t)(2UL)) ? 200UL : 0UL))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) > (uint32_t)(38UL)) ? 0UL : (((uint32_t)(vxp_a1) < (uint32_t)(200UL)) ? 0UL : (((uint32_t)(vxp_a2) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a0) + (uint32_t)(2UL)) & 255UL) : 0UL))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) > (uint32_t)(38UL)) ? 7UL : (((uint32_t)(vxp_a1) < (uint32_t)(200UL)) ? 8UL : (((uint32_t)(vxp_a2) == (uint32_t)(2UL)) ? 10UL : (((uint32_t)(vxp_a2) == (uint32_t)(1UL)) ? 0UL : 9UL)))));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_stew_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_university(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? ((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a4) == (uint32_t)(1UL))) ? 2UL : ((((uint32_t)(vxp_a4) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) : 0UL) ? 2UL : 1UL)) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? ((((uint32_t)(vxp_a3) != (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a4) == (uint32_t)(1UL))) ? 255UL : ((((uint32_t)(vxp_a4) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) : 0UL) ? 255UL : 2UL)) : 255UL))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? ((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a4) == (uint32_t)(1UL))) ? 0UL : ((((uint32_t)(vxp_a4) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) ? 2UL : 1UL))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? ((((uint32_t)(vxp_a3) != (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a4) == (uint32_t)(1UL))) ? 0UL : ((((uint32_t)(vxp_a4) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) ? 2UL : 1UL))) : 0UL))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? ((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a4) == (uint32_t)(1UL))) ? 0UL : ((((uint32_t)(vxp_a4) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) : 0UL) ? 50UL : 0UL)) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? ((((uint32_t)(vxp_a3) != (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a4) == (uint32_t)(1UL))) ? 0UL : ((((uint32_t)(vxp_a4) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) : 0UL) ? 50UL : 0UL)) : 0UL))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? ((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a4) == (uint32_t)(1UL))) ? 0UL : ((((uint32_t)(vxp_a4) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) : 0UL) ? 1UL : 0UL)) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? ((((uint32_t)(vxp_a3) != (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a4) == (uint32_t)(1UL))) ? 0UL : ((((uint32_t)(vxp_a4) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) : 0UL) ? 4UL : 0UL)) : 0UL))));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 11UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? ((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a4) == (uint32_t)(1UL))) ? 0UL : ((((uint32_t)(vxp_a4) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) : 0UL) ? 13UL : 12UL)) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? ((((uint32_t)(vxp_a3) != (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a4) == (uint32_t)(1UL))) ? 0UL : ((((uint32_t)(vxp_a4) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(50UL)) : 0UL) ? 15UL : 14UL)) : 0UL))));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_university_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_shop_stock(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint8_t vxp_a5) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 16UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? 17UL : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? 18UL : 19UL)) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a4) == (uint32_t)(0UL)) ? 20UL : (((uint32_t)(vxp_a5) == (uint32_t)(0UL)) ? 21UL : 22UL)) : 23UL))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(75UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(200UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a1) >= (uint32_t)(500UL)) ? 1UL : 0UL))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a4) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(150UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a5) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(100UL)) ? 1UL : 0UL) : 0UL)) : 1UL))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_shop_stock_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_shop_trade(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint8_t vxp_a5,VX_STABLE uint8_t vxp_a6,VX_STABLE uint8_t vxp_a7) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 1UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) : 0UL) ? 1UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(75UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(200UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a1) < (uint32_t)(500UL)) ? 0UL : (((uint32_t)(vxp_a6) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)(vxp_a7) == (uint32_t)(255UL)) ? 0UL : 1UL))))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a4) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(150UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a5) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(100UL)) ? 1UL : 0UL) : 1UL)) : 0UL)))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) : 0UL) ? 20UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(75UL)) ? 75UL : 0UL) : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(200UL)) ? 200UL : 0UL) : (((uint32_t)(vxp_a1) < (uint32_t)(500UL)) ? 0UL : (((uint32_t)(vxp_a6) == (uint32_t)(0UL)) ? 500UL : (((uint32_t)(vxp_a7) == (uint32_t)(255UL)) ? 0UL : 500UL))))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a4) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(150UL)) ? 150UL : 0UL) : (((uint32_t)(vxp_a5) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(100UL)) ? 100UL : 0UL) : 0UL)) : 0UL)))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) : 0UL) ? 1UL : 0UL)));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(75UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(200UL)) ? 2UL : 0UL) : 0UL)) : 0UL))));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a1) < (uint32_t)(500UL)) ? 0UL : (((uint32_t)(vxp_a6) == (uint32_t)(0UL)) ? 5UL : 0UL)))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a4) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(150UL)) ? 2UL : 0UL) : (((uint32_t)(vxp_a5) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(100UL)) ? 6UL : 0UL) : 0UL)) : 0UL)))));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(75UL)) ? 24UL : 0UL) : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(200UL)) ? 25UL : 0UL) : (((uint32_t)(vxp_a1) < (uint32_t)(500UL)) ? 0UL : (((uint32_t)(vxp_a6) == (uint32_t)(0UL)) ? 26UL : (((uint32_t)(vxp_a7) == (uint32_t)(255UL)) ? 0UL : (((uint32_t)(vxp_a7) == (uint32_t)(0UL)) ? 30UL : (((uint32_t)(vxp_a7) == (uint32_t)(1UL)) ? 31UL : (((uint32_t)(vxp_a7) == (uint32_t)(2UL)) ? 32UL : (((uint32_t)(vxp_a7) == (uint32_t)(3UL)) ? 33UL : (((uint32_t)(vxp_a7) == (uint32_t)(4UL)) ? 34UL : (((uint32_t)(vxp_a7) == (uint32_t)(5UL)) ? 35UL : (((uint32_t)(vxp_a7) == (uint32_t)(6UL)) ? 36UL : 0UL)))))))))))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a4) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(150UL)) ? 27UL : 0UL) : (((uint32_t)(vxp_a5) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) >= (uint32_t)(100UL)) ? 28UL : 0UL) : 29UL)) : 0UL)))));
    vx_payload[10] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[11] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 0UL : ((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) >= (uint32_t)(20UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a1) < (uint32_t)(500UL)) ? 0UL : (((uint32_t)(vxp_a6) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a7) == (uint32_t)(255UL)) ? 1UL : 0UL))))) : 0UL))));
    vx_payload[12] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[13] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_shop_trade_read(uint16_t index) VX_ABI VX_RESIDENT {
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
void vx_password_encode(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI VX_RESIDENT {
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
void vx_password_decode(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1_0,VX_STABLE uint8_t vxp_a1_1,VX_STABLE uint8_t vxp_a1_2,VX_STABLE uint8_t vxp_a1_3,VX_STABLE uint8_t vxp_a1_4,VX_STABLE uint8_t vxp_a1_5,VX_STABLE uint8_t vxp_a1_6,VX_STABLE uint8_t vxp_a1_7,VX_STABLE uint8_t vxp_a1_8,VX_STABLE uint8_t vxp_a1_9,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
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
void vx_world_route(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a4) == (uint32_t)(0UL)) ? 1UL : ((((uint32_t)(vxp_a1) == (uint32_t)(17UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(89UL)) : 0UL) ? 2UL : ((((uint32_t)(vxp_a1) == (uint32_t)(11UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(89UL)) : 0UL) ? 2UL : ((((uint32_t)(vxp_a1) == (uint32_t)(6UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(63UL)) : 0UL) ? 2UL : ((((uint32_t)(vxp_a1) == (uint32_t)(6UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(56UL)) : 0UL) ? 2UL : ((((uint32_t)(vxp_a1) == (uint32_t)(11UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(53UL)) : 0UL) ? 2UL : ((((uint32_t)(vxp_a1) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(53UL)) : 0UL) ? 2UL : ((((uint32_t)(vxp_a1) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(88UL)) : 0UL) ? 2UL : ((((uint32_t)(vxp_a1) == (uint32_t)(6UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(88UL)) : 0UL) ? 2UL : 0UL))))))))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? ((((uint32_t)(vxp_a1) == (uint32_t)(56UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(4UL)) : 0UL) ? 3UL : ((((uint32_t)(vxp_a1) == (uint32_t)(55UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(8UL)) : 0UL) ? 3UL : 0UL)) : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? ((((uint32_t)(vxp_a1) == (uint32_t)(32UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(78UL)) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(79UL))) : 0UL) ? 4UL : 0UL) : (((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? ((((uint32_t)(vxp_a1) == (uint32_t)(39UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(114UL)) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(115UL))) : 0UL) ? 4UL : ((((uint32_t)(vxp_a1) == (uint32_t)(28UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(2UL)) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(3UL))) : 0UL) ? 4UL : ((((uint32_t)(vxp_a1) == (uint32_t)(15UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(2UL)) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(3UL))) : 0UL) ? 4UL : ((((uint32_t)(vxp_a1) == (uint32_t)(23UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(12UL)) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(13UL))) : 0UL) ? 4UL : ((((uint32_t)(vxp_a1) == (uint32_t)(16UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(28UL)) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(29UL))) : 0UL) ? 4UL : 0UL))))) : (((uint32_t)(vxp_a0) == (uint32_t)(5UL)) ? 5UL : (((uint32_t)(vxp_a0) == (uint32_t)(6UL)) ? 6UL : 0UL))))))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a4) == (uint32_t)(0UL)) ? 0UL : ((((uint32_t)(vxp_a1) == (uint32_t)(17UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(89UL)) : 0UL) ? 11UL : ((((uint32_t)(vxp_a1) == (uint32_t)(11UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(89UL)) : 0UL) ? 17UL : ((((uint32_t)(vxp_a1) == (uint32_t)(6UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(63UL)) : 0UL) ? 6UL : ((((uint32_t)(vxp_a1) == (uint32_t)(6UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(56UL)) : 0UL) ? 6UL : ((((uint32_t)(vxp_a1) == (uint32_t)(11UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(53UL)) : 0UL) ? 2UL : ((((uint32_t)(vxp_a1) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(53UL)) : 0UL) ? 11UL : ((((uint32_t)(vxp_a1) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(88UL)) : 0UL) ? 6UL : ((((uint32_t)(vxp_a1) == (uint32_t)(6UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(88UL)) : 0UL) ? 2UL : 0UL))))))))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? ((((uint32_t)(vxp_a1) == (uint32_t)(56UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(4UL)) : 0UL) ? 55UL : ((((uint32_t)(vxp_a1) == (uint32_t)(55UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(8UL)) : 0UL) ? 56UL : 0UL)) : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? ((((uint32_t)(vxp_a1) == (uint32_t)(32UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(78UL)) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(79UL))) : 0UL) ? 39UL : 0UL) : (((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? ((((uint32_t)(vxp_a1) == (uint32_t)(39UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(114UL)) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(115UL))) : 0UL) ? 32UL : ((((uint32_t)(vxp_a1) == (uint32_t)(28UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(2UL)) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(3UL))) : 0UL) ? 15UL : ((((uint32_t)(vxp_a1) == (uint32_t)(15UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(2UL)) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(3UL))) : 0UL) ? 28UL : ((((uint32_t)(vxp_a1) == (uint32_t)(23UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(12UL)) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(13UL))) : 0UL) ? 16UL : ((((uint32_t)(vxp_a1) == (uint32_t)(16UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(28UL)) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(29UL))) : 0UL) ? 23UL : 0UL))))) : 0UL))))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a4) == (uint32_t)(0UL)) ? 0UL : ((((uint32_t)(vxp_a1) == (uint32_t)(17UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(89UL)) : 0UL) ? 89UL : ((((uint32_t)(vxp_a1) == (uint32_t)(11UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(89UL)) : 0UL) ? 89UL : ((((uint32_t)(vxp_a1) == (uint32_t)(6UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(63UL)) : 0UL) ? 56UL : ((((uint32_t)(vxp_a1) == (uint32_t)(6UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(56UL)) : 0UL) ? 63UL : ((((uint32_t)(vxp_a1) == (uint32_t)(11UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(53UL)) : 0UL) ? 53UL : ((((uint32_t)(vxp_a1) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(53UL)) : 0UL) ? 53UL : ((((uint32_t)(vxp_a1) == (uint32_t)(2UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(88UL)) : 0UL) ? 88UL : ((((uint32_t)(vxp_a1) == (uint32_t)(6UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(88UL)) : 0UL) ? 88UL : 0UL))))))))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? ((((uint32_t)(vxp_a1) == (uint32_t)(56UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(4UL)) : 0UL) ? 8UL : ((((uint32_t)(vxp_a1) == (uint32_t)(55UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(8UL)) : 0UL) ? 4UL : 0UL)) : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? ((((uint32_t)(vxp_a1) == (uint32_t)(32UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(78UL)) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(79UL))) : 0UL) ? 114UL : 0UL) : (((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? ((((uint32_t)(vxp_a1) == (uint32_t)(39UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(114UL)) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(115UL))) : 0UL) ? 78UL : ((((uint32_t)(vxp_a1) == (uint32_t)(28UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(2UL)) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(3UL))) : 0UL) ? 2UL : ((((uint32_t)(vxp_a1) == (uint32_t)(15UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(2UL)) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(3UL))) : 0UL) ? 2UL : ((((uint32_t)(vxp_a1) == (uint32_t)(23UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(12UL)) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(13UL))) : 0UL) ? 28UL : ((((uint32_t)(vxp_a1) == (uint32_t)(16UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(28UL)) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(29UL))) : 0UL) ? 12UL : 0UL))))) : 0UL))))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_world_route_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_world_rocks(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a1) != (uint32_t)(0UL))) : 0UL) ? 47UL : 0UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_world_rocks_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_world_well(VX_STABLE uint8_t vxp_a0) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 42UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 43UL : (((uint32_t)(vxp_a0) < (uint32_t)(5UL)) ? 44UL : 0UL))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 45UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 46UL : (((uint32_t)(vxp_a0) < (uint32_t)(5UL)) ? 46UL : 0UL))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 2UL : (((uint32_t)(vxp_a0) < (uint32_t)(5UL)) ? (((uint32_t)(vxp_a0) + (uint32_t)(1UL)) & 255UL) : vxp_a0))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_world_well_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_drop_roll(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a0) < (uint32_t)(1UL)) ? 1UL : ((uint32_t)(vxp_a0) > (uint32_t)(3UL))) ? vxp_a1 : (((uint32_t)(vxp_a2) > (uint32_t)(255UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) < (uint32_t)(8UL)) ? 4UL : (((uint32_t)(vxp_a2) < (uint32_t)(24UL)) ? 3UL : (((uint32_t)(vxp_a2) < (uint32_t)(56UL)) ? 2UL : (((uint32_t)(vxp_a2) < (uint32_t)(72UL)) ? 1UL : 0UL)))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a2) < (uint32_t)(32UL)) ? 4UL : (((uint32_t)(vxp_a2) < (uint32_t)(64UL)) ? 3UL : (((uint32_t)(vxp_a2) < (uint32_t)(96UL)) ? 2UL : (((uint32_t)(vxp_a2) < (uint32_t)(128UL)) ? 1UL : 0UL)))) : (((uint32_t)(vxp_a2) < (uint32_t)(64UL)) ? 4UL : (((uint32_t)(vxp_a2) < (uint32_t)(128UL)) ? 3UL : (((uint32_t)(vxp_a2) < (uint32_t)(160UL)) ? 2UL : (((uint32_t)(vxp_a2) < (uint32_t)(192UL)) ? 1UL : 0UL)))))))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a0) < (uint32_t)(1UL)) ? 1UL : ((uint32_t)(vxp_a0) > (uint32_t)(3UL))) ? 0UL : (((uint32_t)(vxp_a2) > (uint32_t)(255UL)) ? 1UL : 0UL)));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_drop_roll_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_drop_collect(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)((((uint32_t)(vxp_a1) + (uint32_t)(2UL)) & 255UL)) > (uint32_t)(vxp_a2)) ? vxp_a2 : (((uint32_t)(vxp_a1) + (uint32_t)(2UL)) & 255UL)) : vxp_a1));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 1UL : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 5UL : (((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? 20UL : 0UL))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_drop_collect_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_drop_spawn(VX_STABLE uint8_t vxp_a0) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 0UL : 1UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a0) >= (uint32_t)(1UL)) ? ((uint32_t)(vxp_a0) <= (uint32_t)(4UL)) : 0UL) ? (((uint32_t)(vxp_a0) - (uint32_t)(1UL)) & 255UL) : 255UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_drop_spawn_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_drop_step(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a2) <= (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)(240UL)) ? (((uint32_t)(240UL) - (uint32_t)(vxp_a1)) & 255UL) : 0UL))) ? 1UL : 0UL)));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? vxp_a1 : (((uint32_t)(vxp_a1) + (uint32_t)((((uint32_t)(vxp_a2) < (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)(240UL)) ? (((uint32_t)(240UL) - (uint32_t)(vxp_a1)) & 255UL) : 0UL))) ? vxp_a2 : (((uint32_t)(vxp_a1) < (uint32_t)(240UL)) ? (((uint32_t)(240UL) - (uint32_t)(vxp_a1)) & 255UL) : 0UL)))) & 255UL)));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 255UL : (((uint32_t)((((uint32_t)(vxp_a2) < (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)(240UL)) ? (((uint32_t)(240UL) - (uint32_t)(vxp_a1)) & 255UL) : 0UL))) ? vxp_a2 : (((uint32_t)(vxp_a1) < (uint32_t)(240UL)) ? (((uint32_t)(240UL) - (uint32_t)(vxp_a1)) & 255UL) : 0UL))) == (uint32_t)(0UL)) ? 255UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) + (uint32_t)((((uint32_t)(vxp_a2) < (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)(240UL)) ? (((uint32_t)(240UL) - (uint32_t)(vxp_a1)) & 255UL) : 0UL))) ? vxp_a2 : (((uint32_t)(vxp_a1) < (uint32_t)(240UL)) ? (((uint32_t)(240UL) - (uint32_t)(vxp_a1)) & 255UL) : 0UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL)) < (uint32_t)(14UL)) ? 0UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) + (uint32_t)((((uint32_t)(vxp_a2) < (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)(240UL)) ? (((uint32_t)(240UL) - (uint32_t)(vxp_a1)) & 255UL) : 0UL))) ? vxp_a2 : (((uint32_t)(vxp_a1) < (uint32_t)(240UL)) ? (((uint32_t)(240UL) - (uint32_t)(vxp_a1)) & 255UL) : 0UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL)) < (uint32_t)(180UL)) ? 1UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) + (uint32_t)((((uint32_t)(vxp_a2) < (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)(240UL)) ? (((uint32_t)(240UL) - (uint32_t)(vxp_a1)) & 255UL) : 0UL))) ? vxp_a2 : (((uint32_t)(vxp_a1) < (uint32_t)(240UL)) ? (((uint32_t)(240UL) - (uint32_t)(vxp_a1)) & 255UL) : 0UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL)) & (uint32_t)(8UL)) & 255UL))))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_drop_step_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_town_door(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a0) == (uint32_t)(45UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(52UL)) : 0UL) ? 1UL : ((((uint32_t)(vxp_a0) == (uint32_t)(57UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(53UL)) : 0UL) ? 2UL : ((((uint32_t)(vxp_a0) == (uint32_t)(48UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(57UL)) : 0UL) ? 3UL : ((((uint32_t)(vxp_a0) == (uint32_t)(53UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(73UL)) : 0UL) ? 4UL : ((((uint32_t)(vxp_a0) == (uint32_t)(59UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(76UL)) : 0UL) ? 5UL : ((((uint32_t)(vxp_a0) == (uint32_t)(57UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(67UL)) : 0UL) ? 6UL : ((((uint32_t)(vxp_a0) == (uint32_t)(59UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(60UL)) : 0UL) ? 7UL : ((((uint32_t)(vxp_a0) == (uint32_t)(47UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(65UL)) : 0UL) ? 8UL : ((((uint32_t)(vxp_a0) == (uint32_t)(46UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(71UL)) : 0UL) ? 9UL : ((((uint32_t)(vxp_a0) == (uint32_t)(59UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(71UL)) : 0UL) ? 10UL : 0UL)))))))))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_town_door_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_town_house(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) > (uint32_t)(3UL)) ? 0UL : (((uint32_t)(vxp_a1) == (uint32_t)(255UL)) ? 0UL : ((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(255UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a3) != (uint32_t)(0UL)) ? 49UL : 48UL)))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) > (uint32_t)(3UL)) ? 0UL : (((uint32_t)(vxp_a1) == (uint32_t)(255UL)) ? 0UL : ((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(255UL)) : 0UL) ? 0UL : ((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL))) >= (uint32_t)(vxp_a0)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL))) + (uint32_t)(1UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL)))) == (uint32_t)(0UL)) ? 1UL : ((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL))) >= (uint32_t)(vxp_a0)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL))) + (uint32_t)(1UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL)))) == (uint32_t)(3UL))) ? 59UL : (((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL))) >= (uint32_t)(vxp_a0)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL))) + (uint32_t)(1UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL)))) == (uint32_t)(1UL)) ? 47UL : 46UL))))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) > (uint32_t)(3UL)) ? 0UL : (((uint32_t)(vxp_a1) == (uint32_t)(255UL)) ? 0UL : ((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(255UL)) : 0UL) ? 0UL : (((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL))) >= (uint32_t)(vxp_a0)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL))) + (uint32_t)(1UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL)))) == (uint32_t)(0UL)) ? 60UL : (((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL))) >= (uint32_t)(vxp_a0)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL))) + (uint32_t)(1UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 2UL)))) == (uint32_t)(1UL)) ? 65UL : 71UL))))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) > (uint32_t)(3UL)) ? 0UL : (((uint32_t)(vxp_a1) == (uint32_t)(255UL)) ? 1UL : ((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a2) == (uint32_t)(255UL)) : 0UL) ? 2UL : 0UL))));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_town_house_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_town_board(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(vxp_a1)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(39UL)) ? 50UL : (((uint32_t)(vxp_a0) == (uint32_t)(44UL)) ? 51UL : (((uint32_t)(vxp_a0) == (uint32_t)(57UL)) ? 52UL : (((uint32_t)(vxp_a0) == (uint32_t)(59UL)) ? 53UL : (((uint32_t)(vxp_a0) == (uint32_t)(64UL)) ? 54UL : (((uint32_t)(vxp_a0) == (uint32_t)(66UL)) ? 55UL : (((uint32_t)(vxp_a0) == (uint32_t)(72UL)) ? 56UL : (((uint32_t)(vxp_a0) == (uint32_t)(74UL)) ? 57UL : (((uint32_t)(vxp_a0) == (uint32_t)(92UL)) ? 58UL : 0UL)))))))))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(vxp_a0);
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_town_board_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_town_monster(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) < (uint32_t)(3UL)) ? (((uint32_t)(vxp_a0) + (uint32_t)(1UL)) & 255UL) : 4UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) < (uint32_t)(3UL)) ? (((uint32_t)(59UL) + (uint32_t)(vxp_a0)) & 255UL) : 0UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) < (uint32_t)(3UL)) ? (((uint32_t)(vxp_a1) > (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(1UL)) & 255UL) : 0UL) : vxp_a1));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) < (uint32_t)(3UL)) ? 30UL : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 60UL : 0UL)));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_town_monster_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_ghost_spawn(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) - (uint32_t)(256UL)) & 65535UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) - (uint32_t)(512UL)) & 65535UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? vx_signed(((uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) ? -1UL : 1UL)) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) ? -1UL : 1UL))), 8) : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) ? -1UL : 1UL)));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(8UL)) & 255UL)) != (uint32_t)(0UL)) ? vx_signed(((uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? -2UL : 2UL)) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? -2UL : 2UL))), 8) : (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? -2UL : 2UL)));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_ghost_spawn_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_signed((uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8), 16);
    case 3: return (uint32_t)vx_signed((uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8), 16);
    default: vx_trap(16); return 0;
    }
}
void vx_ghost_update(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint16_t vxp_a4,VX_STABLE uint16_t vxp_a5,VX_STABLE uint16_t vxp_a6,VX_STABLE int8_t vxp_a7,VX_STABLE int8_t vxp_a8,VX_STABLE uint16_t vxp_a9,VX_STABLE uint16_t vxp_a10) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vx_calc_uint16_t_0;
    static VX_STABLE uint16_t vx_calc_uint16_t_1;
    if (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(vxp_a1)) & 255UL)) & (uint32_t)(3UL)) & 255UL)) == (uint32_t)(0UL))) {
    } else {
    }
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(vxp_a1)) & 255UL)) & (uint32_t)(3UL)) & 255UL)) == (uint32_t)(0UL)) ? 1UL : 0UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(vxp_a1)) & 255UL)) & (uint32_t)(3UL)) & 255UL)) == (uint32_t)(0UL)) ? vxp_a2 : 0UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(vxp_a1)) & 255UL)) & (uint32_t)(3UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(vxp_a3) + (uint32_t)((((uint32_t)(vx_signed(((uint32_t)((vx_calc_uint16_t_0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a5)) - ((uint16_t)(vxp_a3)))))), VX_VALUE_I8(VX_VALUE_ADD8(((uint8_t)(vxp_a7)), ((uint8_t)(VX_VALUE_I8(VX_VALUE_I16(VX_VALUE_ASR16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(vx_calc_uint16_t_0))) + (VX_VALUE_I16(VX_VALUE_I16(vx_calc_uint16_t_0)) < 0 ? 511U : 0U)), 9))))))))) + (uint32_t)((((uint32_t)(vxp_a9) < (uint32_t)(vxp_a3)) ? -1UL : 1UL))), 8))) & 65535UL))) & 65535UL)) + (uint32_t)((((uint32_t)(vx_signed(((uint32_t)((vx_calc_uint16_t_1 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a5)) - ((uint16_t)(vxp_a3)))))), VX_VALUE_I8(VX_VALUE_ADD8(((uint8_t)(vxp_a7)), ((uint8_t)(VX_VALUE_I8(VX_VALUE_I16(VX_VALUE_ASR16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(vx_calc_uint16_t_1))) + (VX_VALUE_I16(VX_VALUE_I16(vx_calc_uint16_t_1)) < 0 ? 511U : 0U)), 9))))))))) + (uint32_t)((((uint32_t)(vxp_a9) < (uint32_t)(vxp_a3)) ? -1UL : 1UL))), 8))) & 65535UL))) & 65535UL) : 0UL));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(vxp_a1)) & 255UL)) & (uint32_t)(3UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(vxp_a4) + (uint32_t)((((uint32_t)(vx_signed(((uint32_t)((vx_calc_uint16_t_0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a6)) - ((uint16_t)(vxp_a4)))))), VX_VALUE_I8(VX_VALUE_ADD8(((uint8_t)(vxp_a8)), ((uint8_t)(VX_VALUE_I8(VX_VALUE_I16(VX_VALUE_ASR16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(vx_calc_uint16_t_0))) + (VX_VALUE_I16(VX_VALUE_I16(vx_calc_uint16_t_0)) < 0 ? 511U : 0U)), 9))))))))) + (uint32_t)((((uint32_t)(vxp_a10) < (uint32_t)(vxp_a4)) ? -1UL : 1UL))), 8))) & 65535UL))) & 65535UL)) + (uint32_t)((((uint32_t)(vx_signed(((uint32_t)((vx_calc_uint16_t_1 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a6)) - ((uint16_t)(vxp_a4)))))), VX_VALUE_I8(VX_VALUE_ADD8(((uint8_t)(vxp_a8)), ((uint8_t)(VX_VALUE_I8(VX_VALUE_I16(VX_VALUE_ASR16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(vx_calc_uint16_t_1))) + (VX_VALUE_I16(VX_VALUE_I16(vx_calc_uint16_t_1)) < 0 ? 511U : 0U)), 9))))))))) + (uint32_t)((((uint32_t)(vxp_a10) < (uint32_t)(vxp_a4)) ? -1UL : 1UL))), 8))) & 65535UL))) & 65535UL) : 0UL));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(vxp_a1)) & 255UL)) & (uint32_t)(3UL)) & 255UL)) == (uint32_t)(0UL)) ? vx_signed(((uint32_t)((vx_calc_uint16_t_0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a5)) - ((uint16_t)(vxp_a3)))))), VX_VALUE_I8(VX_VALUE_ADD8(((uint8_t)(vxp_a7)), ((uint8_t)(VX_VALUE_I8(VX_VALUE_I16(VX_VALUE_ASR16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(vx_calc_uint16_t_0))) + (VX_VALUE_I16(VX_VALUE_I16(vx_calc_uint16_t_0)) < 0 ? 511U : 0U)), 9))))))))) + (uint32_t)((((uint32_t)(vxp_a9) < (uint32_t)(vxp_a3)) ? -1UL : 1UL))), 8) : 0UL));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(vxp_a1)) & 255UL)) & (uint32_t)(3UL)) & 255UL)) == (uint32_t)(0UL)) ? vx_signed(((uint32_t)((vx_calc_uint16_t_0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a6)) - ((uint16_t)(vxp_a4)))))), VX_VALUE_I8(VX_VALUE_ADD8(((uint8_t)(vxp_a8)), ((uint8_t)(VX_VALUE_I8(VX_VALUE_I16(VX_VALUE_ASR16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(vx_calc_uint16_t_0))) + (VX_VALUE_I16(VX_VALUE_I16(vx_calc_uint16_t_0)) < 0 ? 511U : 0U)), 9))))))))) + (uint32_t)((((uint32_t)(vxp_a10) < (uint32_t)(vxp_a4)) ? -1UL : 1UL))), 8) : 0UL));
    vx_payload[10] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[11] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(vxp_a1)) & 255UL)) & (uint32_t)(3UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(7UL)) & 255UL)) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(7UL)) & 255UL)) == (uint32_t)(1UL)) ? 2UL : (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(7UL)) & 255UL)) == (uint32_t)(3UL)) ? 6UL : (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(7UL)) & 255UL)) < (uint32_t)(6UL)) ? 4UL : 10UL))))) + (uint32_t)(((vx_signed(vx_signed(((uint32_t)((vx_calc_uint16_t_0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a6)) - ((uint16_t)(vxp_a4)))))), VX_VALUE_I8(VX_VALUE_ADD8(((uint8_t)(vxp_a8)), ((uint8_t)(VX_VALUE_I8(VX_VALUE_I16(VX_VALUE_ASR16(VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(vx_calc_uint16_t_0))) + (VX_VALUE_I16(VX_VALUE_I16(vx_calc_uint16_t_0)) < 0 ? 511U : 0U)), 9))))))))) + (uint32_t)((((uint32_t)(vxp_a10) < (uint32_t)(vxp_a4)) ? -1UL : 1UL))), 8), 8) > vx_signed(0UL, 8)) ? 0UL : 1UL))) & 255UL) : 0UL));
    vx_payload[12] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[13] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_ghost_update_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_signed((uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8), 16);
    case 5: return (uint32_t)vx_signed((uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8), 16);
    case 6: return (uint32_t)vx_payload[12] + ((uint32_t)vx_payload[13] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_skeleti_tick(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(vxp_a1)) & 255UL)) & (uint32_t)(3UL)) & 255UL)) == (uint32_t)(0UL)) ? 1UL : 0UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_skeleti_tick_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_skeleti_draws(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(63UL)) & 255UL)) == (uint32_t)(0UL)) ? 0UL : vxp_a0)) == (uint32_t)(0UL)) ? 1UL : 0UL) : 0UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_skeleti_draws_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_skeleti_update(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint16_t vxp_a5,VX_STABLE uint16_t vxp_a6,VX_STABLE uint16_t vxp_a7,VX_STABLE uint16_t vxp_a8,VX_STABLE uint16_t vxp_a9,VX_STABLE uint16_t vxp_a10,VX_STABLE uint8_t vxp_a11) VX_ABI VX_RESIDENT {
    if (((uint32_t)(vxp_a1) != (uint32_t)(0UL))) {
    } else {
        if (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(63UL)) & 255UL)) == (uint32_t)(0UL)) ? 0UL : vxp_a0)) == (uint32_t)(0UL))) {
        } else {
        }
    }
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(63UL)) & 255UL)) == (uint32_t)(0UL)) ? 0UL : vxp_a0) : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(63UL)) & 255UL)) == (uint32_t)(0UL)) ? 0UL : vxp_a0)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a3) & (uint32_t)(7UL)) & 255UL) : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a9) > (uint32_t)(vxp_a5)) ? vxp_a0 : 0UL) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a9) < (uint32_t)(vxp_a5)) ? vxp_a0 : 0UL) : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? (((uint32_t)(vxp_a10) > (uint32_t)(vxp_a6)) ? vxp_a0 : 0UL) : (((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? (((uint32_t)(vxp_a10) < (uint32_t)(vxp_a6)) ? vxp_a0 : 0UL) : (((uint32_t)(vxp_a0) == (uint32_t)(5UL)) ? (((uint32_t)(vxp_a7) > (uint32_t)((((uint32_t)(vxp_a5) + (uint32_t)(512UL)) & 65535UL))) ? vxp_a0 : (((uint32_t)(vxp_a7) < (uint32_t)((((uint32_t)(vxp_a5) - (uint32_t)(512UL)) & 65535UL))) ? vxp_a0 : 0UL)) : (((uint32_t)(vxp_a0) == (uint32_t)(6UL)) ? (((uint32_t)(vxp_a8) > (uint32_t)((((uint32_t)(vxp_a6) + (uint32_t)(512UL)) & 65535UL))) ? vxp_a0 : (((uint32_t)(vxp_a8) < (uint32_t)((((uint32_t)(vxp_a6) - (uint32_t)(512UL)) & 65535UL))) ? vxp_a0 : 0UL)) : 0UL)))))))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(1UL)) & 255UL) : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(63UL)) & 255UL)) == (uint32_t)(0UL)) ? 0UL : vxp_a0)) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((((uint8_t)(vxp_a4)) >> 4) & 15U))))) & 255UL)))) : 0UL)));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? vxp_a5 : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(63UL)) & 255UL)) == (uint32_t)(0UL)) ? 0UL : vxp_a0)) == (uint32_t)(0UL)) ? vxp_a5 : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a9) > (uint32_t)(vxp_a5)) ? (((uint32_t)(vxp_a5) + (uint32_t)(64UL)) & 65535UL) : vxp_a5) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a9) < (uint32_t)(vxp_a5)) ? (((uint32_t)(vxp_a5) - (uint32_t)(64UL)) & 65535UL) : vxp_a5) : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? vxp_a5 : (((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? vxp_a5 : (((uint32_t)(vxp_a0) == (uint32_t)(5UL)) ? (((uint32_t)(vxp_a7) > (uint32_t)((((uint32_t)(vxp_a5) + (uint32_t)(512UL)) & 65535UL))) ? (((uint32_t)(vxp_a5) + (uint32_t)(64UL)) & 65535UL) : (((uint32_t)(vxp_a7) < (uint32_t)((((uint32_t)(vxp_a5) - (uint32_t)(512UL)) & 65535UL))) ? (((uint32_t)(vxp_a5) - (uint32_t)(64UL)) & 65535UL) : vxp_a5)) : vxp_a5))))))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? vxp_a6 : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(63UL)) & 255UL)) == (uint32_t)(0UL)) ? 0UL : vxp_a0)) == (uint32_t)(0UL)) ? vxp_a6 : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? vxp_a6 : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? vxp_a6 : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? (((uint32_t)(vxp_a10) > (uint32_t)(vxp_a6)) ? (((uint32_t)(vxp_a6) + (uint32_t)(64UL)) & 65535UL) : vxp_a6) : (((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? (((uint32_t)(vxp_a10) < (uint32_t)(vxp_a6)) ? (((uint32_t)(vxp_a6) - (uint32_t)(64UL)) & 65535UL) : vxp_a6) : (((uint32_t)(vxp_a0) == (uint32_t)(5UL)) ? vxp_a6 : (((uint32_t)(vxp_a0) == (uint32_t)(6UL)) ? (((uint32_t)(vxp_a8) > (uint32_t)((((uint32_t)(vxp_a6) + (uint32_t)(512UL)) & 65535UL))) ? (((uint32_t)(vxp_a6) + (uint32_t)(64UL)) & 65535UL) : (((uint32_t)(vxp_a8) < (uint32_t)((((uint32_t)(vxp_a6) - (uint32_t)(512UL)) & 65535UL))) ? (((uint32_t)(vxp_a6) - (uint32_t)(64UL)) & 65535UL) : vxp_a6)) : vxp_a6)))))))));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? 255UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(63UL)) & 255UL)) == (uint32_t)(0UL)) ? 0UL : vxp_a0)) == (uint32_t)(0UL)) ? 255UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a9) > (uint32_t)(vxp_a5)) ? (((uint32_t)(4UL) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a11) & (uint32_t)(8UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : 1UL))) & 255UL) : 255UL) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a9) < (uint32_t)(vxp_a5)) ? (((uint32_t)(2UL) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a11) & (uint32_t)(8UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : 1UL))) & 255UL) : 255UL) : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? (((uint32_t)(vxp_a10) > (uint32_t)(vxp_a6)) ? (((uint32_t)(6UL) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a11) & (uint32_t)(8UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : 1UL))) & 255UL) : 255UL) : (((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? (((uint32_t)(vxp_a10) < (uint32_t)(vxp_a6)) ? (((uint32_t)(8UL) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a11) & (uint32_t)(8UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : 1UL))) & 255UL) : 255UL) : (((uint32_t)(vxp_a0) == (uint32_t)(5UL)) ? (((uint32_t)(vxp_a7) > (uint32_t)((((uint32_t)(vxp_a5) + (uint32_t)(512UL)) & 65535UL))) ? (((uint32_t)(4UL) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a11) & (uint32_t)(8UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : 1UL))) & 255UL) : (((uint32_t)(vxp_a7) < (uint32_t)((((uint32_t)(vxp_a5) - (uint32_t)(512UL)) & 65535UL))) ? (((uint32_t)(2UL) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a11) & (uint32_t)(8UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : 1UL))) & 255UL) : 255UL)) : (((uint32_t)(vxp_a0) == (uint32_t)(6UL)) ? (((uint32_t)(vxp_a8) > (uint32_t)((((uint32_t)(vxp_a6) + (uint32_t)(512UL)) & 65535UL))) ? (((uint32_t)(6UL) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a11) & (uint32_t)(8UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : 1UL))) & 255UL) : (((uint32_t)(vxp_a8) < (uint32_t)((((uint32_t)(vxp_a6) - (uint32_t)(512UL)) & 65535UL))) ? (((uint32_t)(8UL) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a11) & (uint32_t)(8UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : 1UL))) & 255UL) : 255UL)) : (((uint32_t)((((uint32_t)(vxp_a11) & (uint32_t)(8UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : 1UL))))))))));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_skeleti_update_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_combat_hit(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE int16_t vxp_a3,VX_STABLE int16_t vxp_a4,VX_STABLE uint8_t vxp_a5) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(0UL)) : 0UL) ? ((uint32_t)(vxp_a2) != (uint32_t)(0UL)) : 0UL) ? 1UL : 0UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(0UL)) : 0UL) ? ((uint32_t)(vxp_a2) != (uint32_t)(0UL)) : 0UL) ? (((uint32_t)(vxp_a0) > (uint32_t)(vxp_a2)) ? (((uint32_t)(vxp_a0) - (uint32_t)(vxp_a2)) & 255UL) : 0UL) : vxp_a0));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(0UL)) : 0UL) ? ((uint32_t)(vxp_a2) != (uint32_t)(0UL)) : 0UL) ? 60UL : vxp_a1));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(0UL)) : 0UL) ? ((uint32_t)(vxp_a2) != (uint32_t)(0UL)) : 0UL) ? 6UL : 0UL));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(0UL)) : 0UL) ? ((uint32_t)(vxp_a2) != (uint32_t)(0UL)) : 0UL) ? ((((uint32_t)(((vx_signed(vxp_a4, 16) < vx_signed(0UL, 16)) ? (((uint32_t)(vx_signed(((uint32_t)(0UL) - (uint32_t)(vxp_a4)), 16))) & 65535UL) : (((uint32_t)(vxp_a4)) & 65535UL))) > (uint32_t)(((vx_signed(vxp_a3, 16) < vx_signed(0UL, 16)) ? (((uint32_t)(vx_signed(((uint32_t)(0UL) - (uint32_t)(vxp_a3)), 16))) & 65535UL) : (((uint32_t)(vxp_a3)) & 65535UL)))) ? 1UL : (((uint32_t)(((vx_signed(vxp_a4, 16) < vx_signed(0UL, 16)) ? (((uint32_t)(vx_signed(((uint32_t)(0UL) - (uint32_t)(vxp_a4)), 16))) & 65535UL) : (((uint32_t)(vxp_a4)) & 65535UL))) == (uint32_t)(((vx_signed(vxp_a3, 16) < vx_signed(0UL, 16)) ? (((uint32_t)(vx_signed(((uint32_t)(0UL) - (uint32_t)(vxp_a3)), 16))) & 65535UL) : (((uint32_t)(vxp_a3)) & 65535UL)))) ? (((uint32_t)(vxp_a5) == (uint32_t)(1UL)) ? 1UL : ((uint32_t)(vxp_a5) == (uint32_t)(2UL))) : 0UL)) ? 0UL : (((vx_signed(vxp_a3, 16) < vx_signed(0UL, 16)) ? 1UL : ((vx_signed(vxp_a3, 16) == vx_signed(0UL, 16)) ? ((uint32_t)(vxp_a5) == (uint32_t)(3UL)) : 0UL)) ? -32UL : 32UL)) : 0UL));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(0UL)) : 0UL) ? ((uint32_t)(vxp_a2) != (uint32_t)(0UL)) : 0UL) ? ((((uint32_t)(((vx_signed(vxp_a4, 16) < vx_signed(0UL, 16)) ? (((uint32_t)(vx_signed(((uint32_t)(0UL) - (uint32_t)(vxp_a4)), 16))) & 65535UL) : (((uint32_t)(vxp_a4)) & 65535UL))) > (uint32_t)(((vx_signed(vxp_a3, 16) < vx_signed(0UL, 16)) ? (((uint32_t)(vx_signed(((uint32_t)(0UL) - (uint32_t)(vxp_a3)), 16))) & 65535UL) : (((uint32_t)(vxp_a3)) & 65535UL)))) ? 1UL : (((uint32_t)(((vx_signed(vxp_a4, 16) < vx_signed(0UL, 16)) ? (((uint32_t)(vx_signed(((uint32_t)(0UL) - (uint32_t)(vxp_a4)), 16))) & 65535UL) : (((uint32_t)(vxp_a4)) & 65535UL))) == (uint32_t)(((vx_signed(vxp_a3, 16) < vx_signed(0UL, 16)) ? (((uint32_t)(vx_signed(((uint32_t)(0UL) - (uint32_t)(vxp_a3)), 16))) & 65535UL) : (((uint32_t)(vxp_a3)) & 65535UL)))) ? (((uint32_t)(vxp_a5) == (uint32_t)(1UL)) ? 1UL : ((uint32_t)(vxp_a5) == (uint32_t)(2UL))) : 0UL)) ? (((vx_signed(vxp_a4, 16) < vx_signed(0UL, 16)) ? 1UL : ((vx_signed(vxp_a4, 16) == vx_signed(0UL, 16)) ? ((uint32_t)(vxp_a5) == (uint32_t)(1UL)) : 0UL)) ? -32UL : 32UL) : 0UL) : 0UL));
    vx_payload[10] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[11] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_combat_hit_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_signed((uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8), 16);
    case 5: return (uint32_t)vx_signed((uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8), 16);
    default: vx_trap(16); return 0;
    }
}
void vx_combat_tick(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(0UL)) : 0UL) ? ((uint32_t)(vxp_a2) == (uint32_t)(0UL)) : 0UL) ? 1UL : (((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) > (uint32_t)(6UL)) ? 6UL : vxp_a2)) != (uint32_t)(0UL)) ? 2UL : 1UL))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(0UL)) : 0UL) ? ((uint32_t)(vxp_a2) == (uint32_t)(0UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a1) > (uint32_t)(vxp_a3)) ? (((uint32_t)(vxp_a1) - (uint32_t)(vxp_a3)) & 255UL) : 0UL))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(0UL)) : 0UL) ? ((uint32_t)(vxp_a2) == (uint32_t)(0UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)(vxp_a2) > (uint32_t)(6UL)) ? 6UL : vxp_a2)) - (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(vxp_a2) > (uint32_t)(6UL)) ? 6UL : vxp_a2))) ? vxp_a3 : (((uint32_t)(vxp_a2) > (uint32_t)(6UL)) ? 6UL : vxp_a2)))) & 255UL))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(0UL)) : 0UL) ? ((uint32_t)(vxp_a2) == (uint32_t)(0UL)) : 0UL) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(vxp_a2) > (uint32_t)(6UL)) ? 6UL : vxp_a2))) ? vxp_a3 : (((uint32_t)(vxp_a2) > (uint32_t)(6UL)) ? 6UL : vxp_a2))) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(vxp_a2) > (uint32_t)(6UL)) ? 6UL : vxp_a2))) ? vxp_a3 : (((uint32_t)(vxp_a2) > (uint32_t)(6UL)) ? 6UL : vxp_a2)))) & 255UL)) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(vxp_a2) > (uint32_t)(6UL)) ? 6UL : vxp_a2))) ? vxp_a3 : (((uint32_t)(vxp_a2) > (uint32_t)(6UL)) ? 6UL : vxp_a2)))) & 255UL))));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(0UL)) : 0UL) ? ((uint32_t)(vxp_a2) == (uint32_t)(0UL)) : 0UL) ? 2UL : (((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? 2UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) > (uint32_t)(vxp_a3)) ? (((uint32_t)(vxp_a1) - (uint32_t)(vxp_a3)) & 255UL) : 0UL)) & (uint32_t)(4UL)) & 255UL)) == (uint32_t)(0UL)) ? 1UL : 0UL)))));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_combat_tick_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_combat_death(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? 1UL : (((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? 2UL : 0UL)));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? 1UL : (((uint32_t)(vxp_a3) != (uint32_t)(0UL)) ? 2UL : 0UL)));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_combat_death_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_melee_style(VX_STABLE uint8_t vxp_a0) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 4UL : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 8UL : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 2UL : 16UL)))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a0) == (uint32_t)(1UL))) ? 0UL : 1UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 14UL : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 6UL : 15UL)));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 5UL : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 4UL : 11UL)));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 1UL : 0UL));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_melee_style_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_melee_hit(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(3UL)) ? (((uint32_t)(vxp_a2) - (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 160UL : 192UL))) & 65535UL) : (((uint32_t)(vxp_a1) == (uint32_t)(4UL)) ? (((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 160UL : 192UL))) & 65535UL) : vxp_a2)));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a3) - (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 160UL : 192UL))) & 65535UL) : ((((uint32_t)(vxp_a1) == (uint32_t)(3UL)) ? 1UL : ((uint32_t)(vxp_a1) == (uint32_t)(4UL))) ? vxp_a3 : (((uint32_t)(vxp_a3) + (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 160UL : 192UL))) & 65535UL))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a1) == (uint32_t)(3UL)) ? 1UL : ((uint32_t)(vxp_a1) == (uint32_t)(4UL))) ? (((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 10UL : 12UL) : (((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 36UL : 40UL)));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a1) == (uint32_t)(3UL)) ? 1UL : ((uint32_t)(vxp_a1) == (uint32_t)(4UL))) ? (((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 36UL : 40UL) : (((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 10UL : 12UL)));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_melee_hit_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_melee_axe(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint16_t vxp_a2) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a1) + (uint32_t)(256UL)) & 65535UL)) + (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 65152UL : ((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 1UL : ((uint32_t)(vxp_a0) == (uint32_t)(2UL))) ? 0UL : 384UL)))) & 65535UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)(256UL)) & 65535UL)) + (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 65152UL : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 384UL : 0UL)))) & 65535UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_melee_axe_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_melee_cut(VX_STABLE uint8_t vxp_a0) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 1UL : ((uint32_t)(vxp_a0) == (uint32_t)(2UL))) ? 1UL : 0UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_melee_cut_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_melee_update(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint16_t vxp_a4,VX_STABLE uint16_t vxp_a5) VX_ABI VX_RESIDENT {
    if (((uint32_t)(vxp_a2) >= (uint32_t)(20UL))) {
    } else {
        if (((uint32_t)(vxp_a3) == (uint32_t)(0UL))) {
        } else {
        }
    }
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a2) >= (uint32_t)(20UL)) ? 0UL : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) < (uint32_t)(20UL)) ? 1UL : 0UL))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a2) >= (uint32_t)(20UL)) ? 0UL : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? 0UL : 1UL)));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a2) >= (uint32_t)(20UL)) ? vxp_a2 : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? vxp_a2 : (((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a2) >= (uint32_t)(20UL)) ? 0UL : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a4) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) == (uint32_t)(1UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(0UL)) ? 333UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(1UL)) ? 192UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(3UL)) ? -192UL : -333UL)))) : (((uint32_t)(vxp_a1) == (uint32_t)(2UL)) ? vx_signed(((uint32_t)(0UL) - (uint32_t)((((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(0UL)) ? 333UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(1UL)) ? 192UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(3UL)) ? -192UL : -333UL)))))), 16) : (((uint32_t)(vxp_a1) == (uint32_t)(3UL)) ? vx_signed(((uint32_t)(0UL) - (uint32_t)(((((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(4UL))) ? 192UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(2UL)) ? 384UL : 333UL)))), 16) : ((((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(4UL))) ? 192UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(2UL)) ? 384UL : 333UL))))))) & 65535UL))) & 65535UL))));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a2) >= (uint32_t)(20UL)) ? 0UL : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a5) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) == (uint32_t)(1UL)) ? vx_signed(((uint32_t)(0UL) - (uint32_t)(((((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(4UL))) ? 192UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(2UL)) ? 384UL : 333UL)))), 16) : (((uint32_t)(vxp_a1) == (uint32_t)(2UL)) ? ((((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(4UL))) ? 192UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(2UL)) ? 384UL : 333UL)) : (((uint32_t)(vxp_a1) == (uint32_t)(3UL)) ? vx_signed(((uint32_t)(0UL) - (uint32_t)((((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(0UL)) ? 333UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(1UL)) ? 192UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(3UL)) ? -192UL : -333UL)))))), 16) : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(0UL)) ? 333UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(1UL)) ? 192UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(3UL)) ? -192UL : -333UL))))))))) & 65535UL))) & 65535UL))));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a2) >= (uint32_t)(20UL)) ? 0UL : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a1) == (uint32_t)(1UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(0UL)) ? 10UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(1UL)) ? 9UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(2UL)) ? 8UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(3UL)) ? 6UL : 4UL)))) : (((uint32_t)(vxp_a1) == (uint32_t)(2UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(1UL)) ? 2UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(2UL)) ? 3UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(3UL)) ? 5UL : 7UL)))) : (((uint32_t)(vxp_a1) == (uint32_t)(3UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(0UL)) ? 6UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(1UL)) ? 4UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(3UL)) ? 1UL : 2UL)))) : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(0UL)) ? 5UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(1UL)) ? 7UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(2UL)) ? 11UL : (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a3) < (uint32_t)((((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL))) ? vxp_a3 : (((uint32_t)(20UL) - (uint32_t)(vxp_a2)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL), 2UL, 8, 1, 0)) == (uint32_t)(3UL)) ? 10UL : 9UL))))))))));
    vx_payload[10] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[11] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a2) >= (uint32_t)(20UL)) ? 0UL : (((uint32_t)(vxp_a3) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 1UL : 0UL))));
    vx_payload[12] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[13] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_melee_update_read(uint16_t index) VX_ABI VX_RESIDENT {
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
void vx_projectile_spawn(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vx_signed(((uint32_t)(vx_signed((((uint32_t)(vxp_a1) == (uint32_t)(3UL)) ? vx_signed(((uint32_t)(0UL) - (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 127UL : 96UL)))), 16) : ((((uint32_t)(vxp_a1) == (uint32_t)(1UL)) ? 1UL : ((uint32_t)(vxp_a1) == (uint32_t)(2UL))) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 127UL : 96UL)))), 8)) + (uint32_t)(vx_signed(vx_shift(vx_signed((((uint32_t)(vxp_a1) == (uint32_t)(3UL)) ? vx_signed(((uint32_t)(0UL) - (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 127UL : 96UL)))), 16) : ((((uint32_t)(vxp_a1) == (uint32_t)(1UL)) ? 1UL : ((uint32_t)(vxp_a1) == (uint32_t)(2UL))) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 127UL : 96UL)))), 8), 1UL, 16, 0, 1), 16))), 16))) & 65535UL))) & 65535UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a3) + (uint32_t)((((uint32_t)(vx_signed(((uint32_t)(vx_signed((((uint32_t)(vxp_a1) == (uint32_t)(1UL)) ? vx_signed(((uint32_t)(0UL) - (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 127UL : 96UL)))), 16) : (((uint32_t)(vxp_a1) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 127UL : 96UL)) : 0UL)), 8)) + (uint32_t)(vx_signed(vx_shift(vx_signed((((uint32_t)(vxp_a1) == (uint32_t)(1UL)) ? vx_signed(((uint32_t)(0UL) - (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 127UL : 96UL)))), 16) : (((uint32_t)(vxp_a1) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 127UL : 96UL)) : 0UL)), 8), 1UL, 16, 0, 1), 16))), 16))) & 65535UL))) & 65535UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(vx_signed((((uint32_t)(vxp_a1) == (uint32_t)(3UL)) ? vx_signed(((uint32_t)(0UL) - (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 127UL : 96UL)))), 16) : ((((uint32_t)(vxp_a1) == (uint32_t)(1UL)) ? 1UL : ((uint32_t)(vxp_a1) == (uint32_t)(2UL))) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 127UL : 96UL)))), 8));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(vx_signed((((uint32_t)(vxp_a1) == (uint32_t)(1UL)) ? vx_signed(((uint32_t)(0UL) - (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 127UL : 96UL)))), 16) : (((uint32_t)(vxp_a1) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 127UL : 96UL)) : 0UL)), 8));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? 255UL : (((uint32_t)(vxp_a1) == (uint32_t)(3UL)) ? 0UL : (((uint32_t)(vxp_a1) == (uint32_t)(2UL)) ? 1UL : (((uint32_t)(vxp_a1) == (uint32_t)(1UL)) ? 3UL : 2UL)))));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(2UL);
    vx_payload[10] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[11] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_projectile_spawn_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_signed((uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8), 16);
    case 3: return (uint32_t)vx_signed((uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8), 16);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    case 5: return (uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_projectile_move(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE int8_t vxp_a3,VX_STABLE int8_t vxp_a4,VX_STABLE uint8_t vxp_a5,VX_STABLE uint8_t vxp_a6) VX_ABI VX_RESIDENT {
    if (((uint32_t)(vxp_a6) == (uint32_t)(0UL))) {
    } else {
        if (((uint32_t)(vxp_a6) == (uint32_t)(1UL))) {
        } else {
            if (((uint32_t)(vxp_a6) == (uint32_t)(2UL))) {
            } else {
                if (((uint32_t)(vxp_a6) == (uint32_t)(3UL))) {
                } else {
                }
            }
        }
    }
    if (((uint32_t)(vxp_a6) == (uint32_t)(0UL))) {
    } else {
        if (((uint32_t)(vxp_a6) == (uint32_t)(1UL))) {
        } else {
            if (((uint32_t)(vxp_a6) == (uint32_t)(2UL))) {
            } else {
                if (((uint32_t)(vxp_a6) == (uint32_t)(3UL))) {
                } else {
                }
            }
        }
    }
    if ((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? ((uint32_t)(vxp_a6) != (uint32_t)(0UL)) : 0UL)) {
    } else {
    }
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a6) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a6) == (uint32_t)(1UL)) ? vxp_a3 : (((uint32_t)(vxp_a6) == (uint32_t)(2UL)) ? (VX_VALUE_I16(((uint32_t)(((uint16_t)(vxp_a3)))) << 1)) : (((uint32_t)(vxp_a6) == (uint32_t)(3UL)) ? (VX_VALUE_I16(((uint16_t)(vxp_a3)) + ((uint16_t)(VX_VALUE_I16(((uint32_t)(((uint16_t)(vxp_a3)))) << 1))))) : vx_signed(vx_mul(vxp_a3, vxp_a6), 16))))))) & 65535UL))) & 65535UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a6) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a6) == (uint32_t)(1UL)) ? vxp_a4 : (((uint32_t)(vxp_a6) == (uint32_t)(2UL)) ? (VX_VALUE_I16(((uint32_t)(((uint16_t)(vxp_a4)))) << 1)) : (((uint32_t)(vxp_a6) == (uint32_t)(3UL)) ? (VX_VALUE_I16(((uint16_t)(vxp_a4)) + ((uint16_t)(VX_VALUE_I16(((uint32_t)(((uint16_t)(vxp_a4)))) << 1))))) : vx_signed(vx_mul(vxp_a4, vxp_a6), 16))))))) & 65535UL))) & 65535UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a5) + (uint32_t)(vxp_a6)) & 255UL) : vxp_a5));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? ((uint32_t)(vxp_a6) != (uint32_t)(0UL)) : 0UL) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vxp_a5)) + ((uint8_t)(vxp_a6)))))) - ((uint8_t)(1)))))) >> 2))))) & ((uint8_t)(3)))))) & 255UL)))) : 255UL));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_projectile_move_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_bomb_step(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a0) < (uint32_t)(186UL)) ? (((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(186UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(186UL) - (uint32_t)(vxp_a0)) & 255UL)) : (((uint32_t)(vxp_a0) < (uint32_t)(190UL)) ? 1UL : (((uint32_t)(vxp_a0) < (uint32_t)(222UL)) ? (((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL)) : 0UL)))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? vxp_a0 : (((uint32_t)(vxp_a0) < (uint32_t)(186UL)) ? (((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(186UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(186UL) - (uint32_t)(vxp_a0)) & 255UL)))) & 255UL) : (((uint32_t)(vxp_a0) < (uint32_t)(190UL)) ? (((uint32_t)(vxp_a0) + (uint32_t)(1UL)) & 255UL) : (((uint32_t)(vxp_a0) < (uint32_t)(222UL)) ? (((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL)))) & 255UL) : vxp_a0)))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)(vxp_a0) < (uint32_t)(186UL)) ? 1UL : (((uint32_t)(vxp_a0) < (uint32_t)(190UL)) ? 1UL : (((uint32_t)(vxp_a0) < (uint32_t)(222UL)) ? 1UL : 0UL)))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? 255UL : (((uint32_t)(vxp_a0) < (uint32_t)(186UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(186UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(186UL) - (uint32_t)(vxp_a0)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL)) >= (uint32_t)(180UL)) ? 1UL : (((uint32_t)(vxp_a0) < (uint32_t)(120UL)) ? 0UL : 255UL)) : (((uint32_t)(vxp_a0) < (uint32_t)(190UL)) ? 2UL : (((uint32_t)(vxp_a0) < (uint32_t)(222UL)) ? ((((uint32_t)(vxp_a0) < (uint32_t)(210UL)) ? ((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL)))) & 255UL)) > (uint32_t)(206UL)) : 0UL) ? 3UL : 255UL) : 255UL)))));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a0) < (uint32_t)(186UL)) ? ((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(186UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(186UL) - (uint32_t)(vxp_a0)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL)) >= (uint32_t)(120UL)) ? ((uint32_t)(vxp_a0) < (uint32_t)(180UL)) : 0UL) ? (((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(186UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(186UL) - (uint32_t)(vxp_a0)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL)) < (uint32_t)(180UL)) ? (((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(186UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(186UL) - (uint32_t)(vxp_a0)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL) : 179UL)) & (uint32_t)(8UL)) & 255UL)) != (uint32_t)(0UL)) ? 14UL : 9UL) : 0UL) : 0UL)));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a0) < (uint32_t)(186UL)) ? 0UL : (((uint32_t)(vxp_a0) < (uint32_t)(190UL)) ? 0UL : (((uint32_t)(vxp_a0) < (uint32_t)(222UL)) ? 1UL : 0UL)))));
    vx_payload[10] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[11] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a0) < (uint32_t)(186UL)) ? 0UL : (((uint32_t)(vxp_a0) < (uint32_t)(190UL)) ? 0UL : (((uint32_t)(vxp_a0) < (uint32_t)(222UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL)) < (uint32_t)(194UL)) ? -150UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL)) < (uint32_t)(198UL)) ? 70UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL)) < (uint32_t)(202UL)) ? -102UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL)) < (uint32_t)(206UL)) ? 134UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL)) < (uint32_t)(210UL)) ? -86UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL)) < (uint32_t)(214UL)) ? 118UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL)) < (uint32_t)(218UL)) ? -150UL : 102UL))))))) : 0UL)))));
    vx_payload[12] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[13] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a0) < (uint32_t)(186UL)) ? 0UL : (((uint32_t)(vxp_a0) < (uint32_t)(190UL)) ? 0UL : (((uint32_t)(vxp_a0) < (uint32_t)(222UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL)) < (uint32_t)(194UL)) ? -104UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL)) < (uint32_t)(198UL)) ? -120UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL)) < (uint32_t)(202UL)) ? 72UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL)) < (uint32_t)(206UL)) ? 152UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL)) < (uint32_t)(210UL)) ? -104UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL)) < (uint32_t)(214UL)) ? -88UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(222UL) - (uint32_t)(vxp_a0)) & 255UL)))) & 255UL)) - (uint32_t)(1UL)) & 255UL)) < (uint32_t)(218UL)) ? 72UL : 136UL))))))) : 0UL)))));
    vx_payload[14] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[15] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a0) < (uint32_t)(186UL)) ? 0UL : (((uint32_t)(vxp_a0) < (uint32_t)(190UL)) ? 1UL : 0UL))));
    vx_payload[16] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[17] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_bomb_step_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    case 5: return (uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8);
    case 6: return (uint32_t)vx_signed((uint32_t)vx_payload[12] + ((uint32_t)vx_payload[13] << 8), 16);
    case 7: return (uint32_t)vx_signed((uint32_t)vx_payload[14] + ((uint32_t)vx_payload[15] << 8), 16);
    case 8: return (uint32_t)vx_payload[16] + ((uint32_t)vx_payload[17] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_bomb_cut(VX_STABLE uint8_t vxp_a0) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a0) >= (uint32_t)(1UL)) ? ((uint32_t)(vxp_a0) <= (uint32_t)(4UL)) : 0UL) ? 1UL : 0UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_bomb_cut_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_effect_step(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) <= (uint32_t)((((uint32_t)(24UL) - (uint32_t)(vxp_a0)) & 255UL))) ? 1UL : 0UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(24UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(24UL) - (uint32_t)(vxp_a0)) & 255UL)))) & 255UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(24UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(24UL) - (uint32_t)(vxp_a0)) & 255UL))) > (uint32_t)((((uint32_t)(18UL) - (uint32_t)(vxp_a0)) & 255UL))) ? 3UL : (((uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(24UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(24UL) - (uint32_t)(vxp_a0)) & 255UL))) > (uint32_t)((((uint32_t)(12UL) - (uint32_t)(vxp_a0)) & 255UL))) ? 2UL : (((uint32_t)((((uint32_t)(vxp_a1) < (uint32_t)((((uint32_t)(24UL) - (uint32_t)(vxp_a0)) & 255UL))) ? vxp_a1 : (((uint32_t)(24UL) - (uint32_t)(vxp_a0)) & 255UL))) > (uint32_t)((((uint32_t)(6UL) - (uint32_t)(vxp_a0)) & 255UL))) ? 1UL : 255UL))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_effect_step_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_spark_frame(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(vxp_a0)) + ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a0)))) << 1)))))))) & 255UL))))) + (uint32_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a1) == (uint32_t)(1UL)) ? 1UL : 2UL)))) & 255UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_spark_frame_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_fairy_move(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(((uint16_t)(((uint32_t)(((uint16_t)(vxp_a0)))) << 8)))) & 65535UL))))) + (uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(32)))))) == ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) == (uint32_t)(16UL)) ? 120UL : (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) < (uint32_t)(8UL)) ? (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) < (uint32_t)(4UL)) ? (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) < (uint32_t)(2UL)) ? (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) == (uint32_t)(0UL)) ? 0UL : 12UL) : (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) == (uint32_t)(2UL)) ? 23UL : 35UL)) : (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) < (uint32_t)(6UL)) ? (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) == (uint32_t)(4UL)) ? 46UL : 57UL) : (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) == (uint32_t)(6UL)) ? 67UL : 76UL))) : (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) < (uint32_t)(12UL)) ? (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) < (uint32_t)(10UL)) ? (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) == (uint32_t)(8UL)) ? 85UL : 93UL) : (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) == (uint32_t)(10UL)) ? 100UL : 106UL)) : (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) < (uint32_t)(14UL)) ? (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) == (uint32_t)(12UL)) ? 111UL : 115UL) : (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) == (uint32_t)(14UL)) ? 118UL : 119UL))))) : (((uint32_t)(0UL) - (uint32_t)((((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) == (uint32_t)(16UL)) ? 120UL : (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) < (uint32_t)(8UL)) ? (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) < (uint32_t)(4UL)) ? (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) < (uint32_t)(2UL)) ? (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) == (uint32_t)(0UL)) ? 0UL : 12UL) : (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) == (uint32_t)(2UL)) ? 23UL : 35UL)) : (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) < (uint32_t)(6UL)) ? (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) == (uint32_t)(4UL)) ? 46UL : 57UL) : (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) == (uint32_t)(6UL)) ? 67UL : 76UL))) : (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) < (uint32_t)(12UL)) ? (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) < (uint32_t)(10UL)) ? (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) == (uint32_t)(8UL)) ? 85UL : 93UL) : (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) == (uint32_t)(10UL)) ? 100UL : 106UL)) : (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) < (uint32_t)(14UL)) ? (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) == (uint32_t)(12UL)) ? 111UL : 115UL) : (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(16)))))) != ((uint8_t)(0))))) & 255UL)))) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(16)) - ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))))))) & 255UL)))) : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a1)) >> 1))))) & ((uint8_t)(63)))))) & ((uint8_t)(15)))))) & 255UL)))))) == (uint32_t)(14UL)) ? 118UL : 119UL))))))) & 65535UL)))) & 65535UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_fairy_move_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_lumber_draw(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 1UL : ((uint32_t)(vxp_a0) == (uint32_t)(2UL))) ? vxp_a0 : vxp_a1));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)(((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 1UL : ((uint32_t)(vxp_a0) == (uint32_t)(2UL))) ? vxp_a0 : vxp_a1)) == (uint32_t)(1UL)) ? 1UL : ((uint32_t)(((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 1UL : ((uint32_t)(vxp_a0) == (uint32_t)(2UL))) ? vxp_a0 : vxp_a1)) == (uint32_t)(2UL))) ? (((uint32_t)((((uint32_t)(((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 1UL : ((uint32_t)(vxp_a0) == (uint32_t)(2UL))) ? vxp_a0 : vxp_a1)) == (uint32_t)(1UL)) ? 0UL : 2UL)) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : 1UL))) & 255UL) : 255UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_lumber_draw_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_ball_tick(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(vxp_a1)) & 255UL)) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : 1UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(vxp_a1)) & 255UL)) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? 1UL : 0UL)));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(vxp_a1)) & 255UL)) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) ? vxp_a2 : (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? vxp_a2 : (((uint32_t)(vxp_a2) - (uint32_t)(1UL)) & 255UL))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(vxp_a1)) & 255UL)) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) ? 255UL : (((uint32_t)(vxp_a2) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a3) == (uint32_t)(1UL)) ? 2UL : 3UL) : 255UL)));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_ball_tick_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_ball_leg(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint8_t vxp_a4) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) != (uint32_t)(vxp_a0)) ? 0UL : 1UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) != (uint32_t)(vxp_a0)) ? vxp_a2 : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) - (uint32_t)(64UL)) & 65535UL) : (((uint32_t)(vxp_a2) + (uint32_t)(64UL)) & 65535UL))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) != (uint32_t)(vxp_a0)) ? vxp_a1 : ((vx_signed(vx_signed((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a3) - (uint32_t)((((uint32_t)(vxp_a2) - (uint32_t)(64UL)) & 65535UL))) & 65535UL) : (((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)(64UL)) & 65535UL)) - (uint32_t)(vxp_a3)) & 65535UL)), 16), 16) > vx_signed(2048UL, 16)) ? (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 2UL : 1UL) : vxp_a1)));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) != (uint32_t)(vxp_a0)) ? vxp_a4 : ((vx_signed(vx_signed((((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a3) - (uint32_t)((((uint32_t)(vxp_a2) - (uint32_t)(64UL)) & 65535UL))) & 65535UL) : (((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)(64UL)) & 65535UL)) - (uint32_t)(vxp_a3)) & 65535UL)), 16), 16) > vx_signed(2048UL, 16)) ? 30UL : vxp_a4)));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_ball_leg_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_ball_reply(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint16_t vxp_a4,VX_STABLE uint16_t vxp_a5,VX_STABLE uint8_t vxp_a6,VX_STABLE uint8_t vxp_a7) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? vxp_a4 : vxp_a2));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? vxp_a5 : vxp_a3));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 2UL : 1UL) : vxp_a6));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? 30UL : vxp_a7));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_ball_reply_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_ball_home(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a0) > (uint32_t)((((uint32_t)(vxp_a1) + (uint32_t)(16UL)) & 65535UL))) ? (((uint32_t)(vxp_a0) - (uint32_t)(16UL)) & 65535UL) : vxp_a0)) < (uint32_t)((((uint32_t)(vxp_a1) - (uint32_t)(16UL)) & 65535UL))) ? (((uint32_t)((((uint32_t)(vxp_a0) > (uint32_t)((((uint32_t)(vxp_a1) + (uint32_t)(16UL)) & 65535UL))) ? (((uint32_t)(vxp_a0) - (uint32_t)(16UL)) & 65535UL) : vxp_a0)) + (uint32_t)(16UL)) & 65535UL) : (((uint32_t)(vxp_a0) > (uint32_t)((((uint32_t)(vxp_a1) + (uint32_t)(16UL)) & 65535UL))) ? (((uint32_t)(vxp_a0) - (uint32_t)(16UL)) & 65535UL) : vxp_a0)));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_ball_home_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_player_keys(VX_STABLE uint8_t vxp_a0) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0) | (uint32_t)(96UL)) & 255UL) : vxp_a0)) & (uint32_t)(144UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0) | (uint32_t)(96UL)) & 255UL) : vxp_a0)) | (uint32_t)(144UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0) | (uint32_t)(96UL)) & 255UL) : vxp_a0)));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_player_keys_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_player_weapon(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    if (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL))) {
    } else {
    }
    if (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL))) {
    } else {
    }
    if (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL))) {
    } else {
    }
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 2UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 6UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1)), 1UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 2UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 6UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1)), 7UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 2UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 6UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1)))) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : (((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 2UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 6UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1)), 1UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 2UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 6UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1)), 7UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 2UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 6UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1)))) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 2UL : (((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 2UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 6UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1)), 1UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 2UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 6UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1)), 7UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 2UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 6UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1)))) & (uint32_t)(8UL)) & 255UL)) != (uint32_t)(0UL)) ? 3UL : (((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 2UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 6UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1)), 1UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 2UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 6UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1)), 7UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 2UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 6UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1)))) & (uint32_t)(16UL)) & 255UL)) != (uint32_t)(0UL)) ? 4UL : (((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 2UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 6UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1)), 1UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 2UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 6UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1)), 7UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 2UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 6UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1)))) & (uint32_t)(32UL)) & 255UL)) != (uint32_t)(0UL)) ? 5UL : (((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 2UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 6UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1)), 1UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 2UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 6UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1)), 7UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 2UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 6UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1)))) & (uint32_t)(64UL)) & 255UL)) != (uint32_t)(0UL)) ? 6UL : (((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 2UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 6UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1)), 1UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 2UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 6UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1)), 7UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 2UL, 8, 1, 0)) | (uint32_t)(vx_shift((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1), 6UL, 8, 0, 0))) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 4) & 15U))))) | ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a1)))) << 4)))))))) & 255UL)))) : vxp_a1)))) & (uint32_t)(128UL)) & 255UL)) != (uint32_t)(0UL)) ? 7UL : 0UL))))))))) & 255UL)) & (uint32_t)(7UL)) & 255UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_player_weapon_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_player_attack(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) > (uint32_t)(7UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(2UL)) & 255UL)) != (uint32_t)(0UL)) ? 2UL : (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 3UL : 0UL)) : ((((uint32_t)(vxp_a0) == (uint32_t)(5UL)) ? 1UL : ((uint32_t)(vxp_a0) == (uint32_t)(6UL))) ? (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(8UL)) & 255UL)) != (uint32_t)(0UL)) ? 4UL : (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(16UL)) & 255UL)) != (uint32_t)(0UL)) ? 5UL : 0UL)) : (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 0UL)))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_player_attack_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_player_tick(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vxp_a0) + (uint32_t)(1UL)) & 255UL)));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL)) ? vxp_a1 : (((uint32_t)(vxp_a1) + (uint32_t)(1UL)) & 255UL)));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL)) ? 0UL : 1UL));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_player_tick_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_player_move(VX_STABLE uint8_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint16_t vxp_a2) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a1) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(32UL)) & 255UL)) == (uint32_t)(0UL)) ? 65504UL : 0UL))) & 65535UL)) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(64UL)) & 255UL)) == (uint32_t)(0UL)) ? 32UL : 0UL))) & 65535UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(16UL)) & 255UL)) == (uint32_t)(0UL)) ? 65504UL : 0UL))) & 65535UL)) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(128UL)) & 255UL)) == (uint32_t)(0UL)) ? 32UL : 0UL))) & 65535UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_player_move_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_player_slide(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint16_t vxp_a4,VX_STABLE uint16_t vxp_a5) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? vxp_a2 : vxp_a4) : vxp_a2));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? vxp_a3 : vxp_a5) : vxp_a3));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? 0UL : (((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a4) != (uint32_t)(vxp_a2)) : 0UL) ? ((uint32_t)(vxp_a5) != (uint32_t)(vxp_a3)) : 0UL) ? vxp_a2 : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? vxp_a4 : 0UL))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? 0UL : (((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a4) != (uint32_t)(vxp_a2)) : 0UL) ? ((uint32_t)(vxp_a5) != (uint32_t)(vxp_a3)) : 0UL) ? vxp_a5 : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? vxp_a3 : 0UL))));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? 0UL : (((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a4) != (uint32_t)(vxp_a2)) : 0UL) ? ((uint32_t)(vxp_a5) != (uint32_t)(vxp_a3)) : 0UL) ? 1UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 2UL : 0UL))));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_player_slide_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_player_draw(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(16UL)) & 255UL)) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(128UL)) & 255UL)) == (uint32_t)(0UL)) ? 2UL : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(64UL)) & 255UL)) == (uint32_t)(0UL)) ? 4UL : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(32UL)) & 255UL)) == (uint32_t)(0UL)) ? 3UL : vxp_a2)))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(240UL)) & 255UL)) == (uint32_t)(240UL)) ? 255UL : (((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(16UL)) & 255UL)) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(128UL)) & 255UL)) == (uint32_t)(0UL)) ? 2UL : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(64UL)) & 255UL)) == (uint32_t)(0UL)) ? 4UL : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(32UL)) & 255UL)) == (uint32_t)(0UL)) ? 3UL : vxp_a2))))) == (uint32_t)(1UL)) ? 8UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(128UL)) & 255UL)) == (uint32_t)(0UL)) ? 2UL : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(64UL)) & 255UL)) == (uint32_t)(0UL)) ? 4UL : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(32UL)) & 255UL)) == (uint32_t)(0UL)) ? 3UL : vxp_a2)))) == (uint32_t)(2UL)) ? 6UL : (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(64UL)) & 255UL)) == (uint32_t)(0UL)) ? 4UL : (((uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(32UL)) & 255UL)) == (uint32_t)(0UL)) ? 3UL : vxp_a2))) == (uint32_t)(3UL)) ? 2UL : 4UL)))) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : 1UL))) & 255UL)));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_player_draw_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_player_view(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint8_t vxp_a5,VX_STABLE uint8_t vxp_a6) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(vxp_a0)) >> 8))))))) - ((uint8_t)(vxp_a2)))))) > ((uint8_t)(13))))) & 255UL)))) ? ((uint32_t)(vxp_a4) < (uint32_t)(106UL)) : 0UL) ? (((uint32_t)(vxp_a2) + (uint32_t)(1UL)) & 255UL) : (((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(vxp_a0)) >> 8))))))) - ((uint8_t)(vxp_a2)))))) < ((uint8_t)(8))))) & 255UL)))) ? ((uint32_t)(vxp_a4) > (uint32_t)(0UL)) : 0UL) ? (((uint32_t)(vxp_a2) - (uint32_t)(1UL)) & 255UL) : vxp_a4)));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(vxp_a1)) >> 8))))))) - ((uint8_t)(vxp_a3)))))) > ((uint8_t)(20))))) & 255UL)))) ? ((uint32_t)(vxp_a5) < (uint32_t)(224UL)) : 0UL) ? (((uint32_t)(vxp_a3) + (uint32_t)(1UL)) & 255UL) : (((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(vxp_a1)) >> 8))))))) - ((uint8_t)(vxp_a3)))))) < ((uint8_t)(10))))) & 255UL)))) ? ((uint32_t)(vxp_a5) > (uint32_t)(0UL)) : 0UL) ? (((uint32_t)(vxp_a3) - (uint32_t)(1UL)) & 255UL) : vxp_a5)));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a6) | (uint32_t)((((uint32_t)(vxp_a2) != (uint32_t)((((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(vxp_a0)) >> 8))))))) - ((uint8_t)(vxp_a2)))))) > ((uint8_t)(13))))) & 255UL)))) ? ((uint32_t)(vxp_a4) < (uint32_t)(106UL)) : 0UL) ? (((uint32_t)(vxp_a2) + (uint32_t)(1UL)) & 255UL) : (((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(vxp_a0)) >> 8))))))) - ((uint8_t)(vxp_a2)))))) < ((uint8_t)(8))))) & 255UL)))) ? ((uint32_t)(vxp_a4) > (uint32_t)(0UL)) : 0UL) ? (((uint32_t)(vxp_a2) - (uint32_t)(1UL)) & 255UL) : vxp_a4)))) ? 1UL : 0UL))) & 255UL)) | (uint32_t)((((uint32_t)(vxp_a3) != (uint32_t)((((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(vxp_a1)) >> 8))))))) - ((uint8_t)(vxp_a3)))))) > ((uint8_t)(20))))) & 255UL)))) ? ((uint32_t)(vxp_a5) < (uint32_t)(224UL)) : 0UL) ? (((uint32_t)(vxp_a3) + (uint32_t)(1UL)) & 255UL) : (((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(vxp_a1)) >> 8))))))) - ((uint8_t)(vxp_a3)))))) < ((uint8_t)(10))))) & 255UL)))) ? ((uint32_t)(vxp_a5) > (uint32_t)(0UL)) : 0UL) ? (((uint32_t)(vxp_a3) - (uint32_t)(1UL)) & 255UL) : vxp_a5)))) ? 1UL : 0UL))) & 255UL));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_player_view_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_player_motion(VX_STABLE uint16_t vxp_a0_0,VX_STABLE uint16_t vxp_a0_1,VX_STABLE uint8_t vxp_a0_2,VX_STABLE uint8_t vxp_a0_3,VX_STABLE uint8_t vxp_a0_4,VX_STABLE uint8_t vxp_a0_5,VX_STABLE uint8_t vxp_a0_6) VX_ABI VX_RESIDENT {
    uint16_t vxl_2_s2456_l0, vxln_2_s2456_l0;
    uint16_t vxl_2_s2456_l1, vxln_2_s2456_l1;
    uint8_t vxl_2_s2456_l2, vxln_2_s2456_l2;
    uint8_t vxl_2_s2456_l3, vxln_2_s2456_l3;
    uint8_t vxl_2_s2456_l4, vxln_2_s2456_l4;
    uint8_t vxl_2_s2456_l5, vxln_2_s2456_l5;
    uint8_t vxl_2_s2456_l6, vxln_2_s2456_l6;
    uint8_t vxlq_2_s2456, vxlqn_2_s2456;
    uint8_t vxl_2_s2460_l0, vxln_2_s2460_l0;
    uint8_t vxlq_2_s2460, vxlqn_2_s2460;
    uint8_t vxl_2_s14616_l0, vxln_2_s14616_l0;
    uint16_t vxl_3_s2456_l0, vxln_3_s2456_l0;
    uint16_t vxl_3_s2456_l1, vxln_3_s2456_l1;
    uint8_t vxl_3_s2456_l2, vxln_3_s2456_l2;
    uint8_t vxl_3_s2456_l3, vxln_3_s2456_l3;
    uint8_t vxl_3_s2456_l4, vxln_3_s2456_l4;
    uint8_t vxl_3_s2456_l5, vxln_3_s2456_l5;
    uint8_t vxl_3_s2456_l6, vxln_3_s2456_l6;
    uint8_t vxlq_3_s2456, vxlqn_3_s2456;
    uint8_t vxl_3_s2460_l0, vxln_3_s2460_l0;
    uint8_t vxlq_3_s2460, vxlqn_3_s2460;
    uint8_t vxl_3_s20180_l0, vxln_3_s20180_l0;
    uint16_t vxl_5_s2456_l0, vxln_5_s2456_l0;
    uint16_t vxl_5_s2456_l1, vxln_5_s2456_l1;
    uint8_t vxl_5_s2456_l2, vxln_5_s2456_l2;
    uint8_t vxl_5_s2456_l3, vxln_5_s2456_l3;
    uint8_t vxl_5_s2456_l4, vxln_5_s2456_l4;
    uint8_t vxl_5_s2456_l5, vxln_5_s2456_l5;
    uint8_t vxl_5_s2456_l6, vxln_5_s2456_l6;
    uint8_t vxlq_5_s2456, vxlqn_5_s2456;
    uint8_t vxl_5_s2460_l0, vxln_5_s2460_l0;
    uint8_t vxlq_5_s2460, vxlqn_5_s2460;
    uint16_t vxl_5_s22657_l0, vxln_5_s22657_l0;
    uint16_t vxl_5_s22659_l0, vxln_5_s22659_l0;
    uint8_t vxl_5_s22661_l0, vxln_5_s22661_l0;
    uint8_t vxl_5_s22663_l0, vxln_5_s22663_l0;
    uint32_t vxt_24[8];
    if (((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) & (uint32_t)(144UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) | (uint32_t)(144UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2))) == (uint32_t)(255UL))) {
    } else {
        vxlqn_2_s2456 = 1UL;
        vxln_2_s2456_l0 = vxlqn_2_s2456 ? (vxp_a0_0) : 0;
        vxln_2_s2456_l1 = vxlqn_2_s2456 ? (vxp_a0_1) : 0;
        vxln_2_s2456_l2 = vxlqn_2_s2456 ? ((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) & (uint32_t)(144UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) | (uint32_t)(144UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2))) : 0;
        vxln_2_s2456_l3 = vxlqn_2_s2456 ? (vxp_a0_3) : 0;
        vxln_2_s2456_l4 = vxlqn_2_s2456 ? (vxp_a0_4) : 0;
        vxln_2_s2456_l5 = vxlqn_2_s2456 ? (vxp_a0_5) : 0;
        vxln_2_s2456_l6 = vxlqn_2_s2456 ? (vxp_a0_6) : 0;
        vxlqn_2_s2460 = 1UL;
        vxln_2_s2460_l0 = vxlqn_2_s2460 ? (0UL) : 0;
        vxln_2_s14616_l0 = (0UL);
        vxl_2_s2456_l0 = vxln_2_s2456_l0;
        vxl_2_s2456_l1 = vxln_2_s2456_l1;
        vxl_2_s2456_l2 = vxln_2_s2456_l2;
        vxl_2_s2456_l3 = vxln_2_s2456_l3;
        vxl_2_s2456_l4 = vxln_2_s2456_l4;
        vxl_2_s2456_l5 = vxln_2_s2456_l5;
        vxl_2_s2456_l6 = vxln_2_s2456_l6;
        vxlq_2_s2456 = vxlqn_2_s2456;
        vxl_2_s2460_l0 = vxln_2_s2460_l0;
        vxlq_2_s2460 = vxlqn_2_s2460;
        vxl_2_s14616_l0 = vxln_2_s14616_l0;
        for (;;) {
            if (!(((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3))))) {
                if (0UL) {
                    vxlqn_2_s2456 = VX_SNAPSHOT8(vxlq_2_s2456);
                    vxln_2_s2456_l0 = vxlqn_2_s2456 ? (VX_SNAPSHOT16(vxl_2_s2456_l0)) : 0;
                    vxln_2_s2456_l1 = vxlqn_2_s2456 ? (VX_SNAPSHOT16(vxl_2_s2456_l1)) : 0;
                    vxln_2_s2456_l2 = vxlqn_2_s2456 ? (VX_SNAPSHOT8(vxl_2_s2456_l2)) : 0;
                    vxln_2_s2456_l3 = vxlqn_2_s2456 ? (VX_SNAPSHOT8(vxl_2_s2456_l3)) : 0;
                    vxln_2_s2456_l4 = vxlqn_2_s2456 ? (VX_SNAPSHOT8(vxl_2_s2456_l4)) : 0;
                    vxln_2_s2456_l5 = vxlqn_2_s2456 ? (VX_SNAPSHOT8(vxl_2_s2456_l5)) : 0;
                    vxln_2_s2456_l6 = vxlqn_2_s2456 ? (VX_SNAPSHOT8(vxl_2_s2456_l6)) : 0;
                    vxlqn_2_s2460 = VX_SNAPSHOT8(vxlq_2_s2460);
                    vxln_2_s2460_l0 = vxlqn_2_s2460 ? (VX_SNAPSHOT8(vxl_2_s2460_l0)) : 0;
                    vxln_2_s14616_l0 = (VX_SNAPSHOT8(vxl_2_s14616_l0));
                    vxl_2_s2456_l0 = vxln_2_s2456_l0;
                    vxl_2_s2456_l1 = vxln_2_s2456_l1;
                    vxl_2_s2456_l2 = vxln_2_s2456_l2;
                    vxl_2_s2456_l3 = vxln_2_s2456_l3;
                    vxl_2_s2456_l4 = vxln_2_s2456_l4;
                    vxl_2_s2456_l5 = vxln_2_s2456_l5;
                    vxl_2_s2456_l6 = vxln_2_s2456_l6;
                    vxlq_2_s2456 = vxlqn_2_s2456;
                    vxl_2_s2460_l0 = vxln_2_s2460_l0;
                    vxlq_2_s2460 = vxlqn_2_s2460;
                    vxl_2_s14616_l0 = vxln_2_s14616_l0;
                    continue;
                }
                vxlqn_2_s2456 = VX_SNAPSHOT8(vxlq_2_s2456);
                vxln_2_s2456_l0 = vxlqn_2_s2456 ? (VX_SNAPSHOT16(vxl_2_s2456_l0)) : 0;
                vxln_2_s2456_l1 = vxlqn_2_s2456 ? (VX_SNAPSHOT16(vxl_2_s2456_l1)) : 0;
                vxln_2_s2456_l2 = vxlqn_2_s2456 ? (VX_SNAPSHOT8(vxl_2_s2456_l2)) : 0;
                vxln_2_s2456_l3 = vxlqn_2_s2456 ? (VX_SNAPSHOT8(vxl_2_s2456_l3)) : 0;
                vxln_2_s2456_l4 = vxlqn_2_s2456 ? (VX_SNAPSHOT8(vxl_2_s2456_l4)) : 0;
                vxln_2_s2456_l5 = vxlqn_2_s2456 ? (VX_SNAPSHOT8(vxl_2_s2456_l5)) : 0;
                vxln_2_s2456_l6 = vxlqn_2_s2456 ? (VX_SNAPSHOT8(vxl_2_s2456_l6)) : 0;
                vxlqn_2_s2460 = VX_SNAPSHOT8(vxlq_2_s2460);
                vxln_2_s2460_l0 = vxlqn_2_s2460 ? (VX_SNAPSHOT8(vxl_2_s2460_l0)) : 0;
                vxln_2_s14616_l0 = (VX_SNAPSHOT8(vxl_2_s14616_l0));
                vxl_2_s2456_l0 = vxln_2_s2456_l0;
                vxl_2_s2456_l1 = vxln_2_s2456_l1;
                vxl_2_s2456_l2 = vxln_2_s2456_l2;
                vxl_2_s2456_l3 = vxln_2_s2456_l3;
                vxl_2_s2456_l4 = vxln_2_s2456_l4;
                vxl_2_s2456_l5 = vxln_2_s2456_l5;
                vxl_2_s2456_l6 = vxln_2_s2456_l6;
                vxlq_2_s2456 = vxlqn_2_s2456;
                vxl_2_s2460_l0 = vxln_2_s2460_l0;
                vxlq_2_s2460 = vxlqn_2_s2460;
                vxl_2_s14616_l0 = vxln_2_s14616_l0;
                break;
            }
            if (((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3)))) {
                if (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l4)) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL))) {
                } else {
                    vxlqn_3_s2456 = 1UL;
                    vxln_3_s2456_l0 = vxlqn_3_s2456 ? (VX_SNAPSHOT16(vxl_2_s2456_l0)) : 0;
                    vxln_3_s2456_l1 = vxlqn_3_s2456 ? (VX_SNAPSHOT16(vxl_2_s2456_l1)) : 0;
                    vxln_3_s2456_l2 = vxlqn_3_s2456 ? (VX_SNAPSHOT8(vxl_2_s2456_l2)) : 0;
                    vxln_3_s2456_l3 = vxlqn_3_s2456 ? (VX_SNAPSHOT8(vxl_2_s2456_l3)) : 0;
                    vxln_3_s2456_l4 = vxlqn_3_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l4)) + (uint32_t)(1UL)) & 255UL)) : 0;
                    vxln_3_s2456_l5 = vxlqn_3_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l5)) + (uint32_t)(1UL)) & 255UL)) : 0;
                    vxln_3_s2456_l6 = vxlqn_3_s2456 ? (VX_SNAPSHOT8(vxl_2_s2456_l6)) : 0;
                    vxlqn_3_s2460 = VX_SNAPSHOT8(vxlq_2_s2460);
                    vxln_3_s2460_l0 = vxlqn_3_s2460 ? (VX_SNAPSHOT8(vxl_2_s2460_l0)) : 0;
                    vxln_3_s20180_l0 = (0UL);
                    vxl_3_s2456_l0 = vxln_3_s2456_l0;
                    vxl_3_s2456_l1 = vxln_3_s2456_l1;
                    vxl_3_s2456_l2 = vxln_3_s2456_l2;
                    vxl_3_s2456_l3 = vxln_3_s2456_l3;
                    vxl_3_s2456_l4 = vxln_3_s2456_l4;
                    vxl_3_s2456_l5 = vxln_3_s2456_l5;
                    vxl_3_s2456_l6 = vxln_3_s2456_l6;
                    vxlq_3_s2456 = vxlqn_3_s2456;
                    vxl_3_s2460_l0 = vxln_3_s2460_l0;
                    vxlq_3_s2460 = vxlqn_3_s2460;
                    vxl_3_s20180_l0 = vxln_3_s20180_l0;
                    for (;;) {
                        if (!(((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL)))) {
                            if (0UL) {
                                vxlqn_3_s2456 = VX_SNAPSHOT8(vxlq_3_s2456);
                                vxln_3_s2456_l0 = vxlqn_3_s2456 ? (VX_SNAPSHOT16(vxl_3_s2456_l0)) : 0;
                                vxln_3_s2456_l1 = vxlqn_3_s2456 ? (VX_SNAPSHOT16(vxl_3_s2456_l1)) : 0;
                                vxln_3_s2456_l2 = vxlqn_3_s2456 ? (VX_SNAPSHOT8(vxl_3_s2456_l2)) : 0;
                                vxln_3_s2456_l3 = vxlqn_3_s2456 ? (VX_SNAPSHOT8(vxl_3_s2456_l3)) : 0;
                                vxln_3_s2456_l4 = vxlqn_3_s2456 ? (VX_SNAPSHOT8(vxl_3_s2456_l4)) : 0;
                                vxln_3_s2456_l5 = vxlqn_3_s2456 ? (VX_SNAPSHOT8(vxl_3_s2456_l5)) : 0;
                                vxln_3_s2456_l6 = vxlqn_3_s2456 ? (VX_SNAPSHOT8(vxl_3_s2456_l6)) : 0;
                                vxlqn_3_s2460 = VX_SNAPSHOT8(vxlq_3_s2460);
                                vxln_3_s2460_l0 = vxlqn_3_s2460 ? (VX_SNAPSHOT8(vxl_3_s2460_l0)) : 0;
                                vxln_3_s20180_l0 = (VX_SNAPSHOT8(vxl_3_s20180_l0));
                                vxl_3_s2456_l0 = vxln_3_s2456_l0;
                                vxl_3_s2456_l1 = vxln_3_s2456_l1;
                                vxl_3_s2456_l2 = vxln_3_s2456_l2;
                                vxl_3_s2456_l3 = vxln_3_s2456_l3;
                                vxl_3_s2456_l4 = vxln_3_s2456_l4;
                                vxl_3_s2456_l5 = vxln_3_s2456_l5;
                                vxl_3_s2456_l6 = vxln_3_s2456_l6;
                                vxlq_3_s2456 = vxlqn_3_s2456;
                                vxl_3_s2460_l0 = vxln_3_s2460_l0;
                                vxlq_3_s2460 = vxlqn_3_s2460;
                                vxl_3_s20180_l0 = vxln_3_s20180_l0;
                                continue;
                            }
                            vxlqn_3_s2456 = VX_SNAPSHOT8(vxlq_3_s2456);
                            vxln_3_s2456_l0 = vxlqn_3_s2456 ? (VX_SNAPSHOT16(vxl_3_s2456_l0)) : 0;
                            vxln_3_s2456_l1 = vxlqn_3_s2456 ? (VX_SNAPSHOT16(vxl_3_s2456_l1)) : 0;
                            vxln_3_s2456_l2 = vxlqn_3_s2456 ? (VX_SNAPSHOT8(vxl_3_s2456_l2)) : 0;
                            vxln_3_s2456_l3 = vxlqn_3_s2456 ? (VX_SNAPSHOT8(vxl_3_s2456_l3)) : 0;
                            vxln_3_s2456_l4 = vxlqn_3_s2456 ? (VX_SNAPSHOT8(vxl_3_s2456_l4)) : 0;
                            vxln_3_s2456_l5 = vxlqn_3_s2456 ? (VX_SNAPSHOT8(vxl_3_s2456_l5)) : 0;
                            vxln_3_s2456_l6 = vxlqn_3_s2456 ? (VX_SNAPSHOT8(vxl_3_s2456_l6)) : 0;
                            vxlqn_3_s2460 = VX_SNAPSHOT8(vxlq_3_s2460);
                            vxln_3_s2460_l0 = vxlqn_3_s2460 ? (VX_SNAPSHOT8(vxl_3_s2460_l0)) : 0;
                            vxln_3_s20180_l0 = (VX_SNAPSHOT8(vxl_3_s20180_l0));
                            vxl_3_s2456_l0 = vxln_3_s2456_l0;
                            vxl_3_s2456_l1 = vxln_3_s2456_l1;
                            vxl_3_s2456_l2 = vxln_3_s2456_l2;
                            vxl_3_s2456_l3 = vxln_3_s2456_l3;
                            vxl_3_s2456_l4 = vxln_3_s2456_l4;
                            vxl_3_s2456_l5 = vxln_3_s2456_l5;
                            vxl_3_s2456_l6 = vxln_3_s2456_l6;
                            vxlq_3_s2456 = vxlqn_3_s2456;
                            vxl_3_s2460_l0 = vxln_3_s2460_l0;
                            vxlq_3_s2460 = vxlqn_3_s2460;
                            vxl_3_s20180_l0 = vxln_3_s20180_l0;
                            break;
                        }
                        if (((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL))) {
                            vxlqn_5_s2456 = VX_SNAPSHOT8(vxlq_3_s2456);
                            vxln_5_s2456_l0 = vxlqn_5_s2456 ? (VX_SNAPSHOT16(vxl_3_s2456_l0)) : 0;
                            vxln_5_s2456_l1 = vxlqn_5_s2456 ? (VX_SNAPSHOT16(vxl_3_s2456_l1)) : 0;
                            vxln_5_s2456_l2 = vxlqn_5_s2456 ? (VX_SNAPSHOT8(vxl_3_s2456_l2)) : 0;
                            vxln_5_s2456_l3 = vxlqn_5_s2456 ? (VX_SNAPSHOT8(vxl_3_s2456_l3)) : 0;
                            vxln_5_s2456_l4 = vxlqn_5_s2456 ? (VX_SNAPSHOT8(vxl_3_s2456_l4)) : 0;
                            vxln_5_s2456_l5 = vxlqn_5_s2456 ? (VX_SNAPSHOT8(vxl_3_s2456_l5)) : 0;
                            vxln_5_s2456_l6 = vxlqn_5_s2456 ? (VX_SNAPSHOT8(vxl_3_s2456_l6)) : 0;
                            vxlqn_5_s2460 = VX_SNAPSHOT8(vxlq_3_s2460);
                            vxln_5_s2460_l0 = vxlqn_5_s2460 ? (VX_SNAPSHOT8(vxl_3_s2460_l0)) : 0;
                            vxln_5_s22657_l0 = ((((uint32_t)((((uint32_t)(VX_SNAPSHOT16(vxl_3_s2456_l0)) + (uint32_t)((((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_3_s2456_l2)) & (uint32_t)(32UL)) & 255UL)) == (uint32_t)(0UL)) ? 65504UL : 0UL))) & 65535UL)) + (uint32_t)((((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_3_s2456_l2)) & (uint32_t)(64UL)) & 255UL)) == (uint32_t)(0UL)) ? 32UL : 0UL))) & 65535UL));
                            vxln_5_s22659_l0 = ((((uint32_t)((((uint32_t)(VX_SNAPSHOT16(vxl_3_s2456_l1)) + (uint32_t)((((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_3_s2456_l2)) & (uint32_t)(16UL)) & 255UL)) == (uint32_t)(0UL)) ? 65504UL : 0UL))) & 65535UL)) + (uint32_t)((((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_3_s2456_l2)) & (uint32_t)(128UL)) & 255UL)) == (uint32_t)(0UL)) ? 32UL : 0UL))) & 65535UL));
                            vxln_5_s22661_l0 = (0UL);
                            vxln_5_s22663_l0 = (1UL);
                            vxl_5_s2456_l0 = vxln_5_s2456_l0;
                            vxl_5_s2456_l1 = vxln_5_s2456_l1;
                            vxl_5_s2456_l2 = vxln_5_s2456_l2;
                            vxl_5_s2456_l3 = vxln_5_s2456_l3;
                            vxl_5_s2456_l4 = vxln_5_s2456_l4;
                            vxl_5_s2456_l5 = vxln_5_s2456_l5;
                            vxl_5_s2456_l6 = vxln_5_s2456_l6;
                            vxlq_5_s2456 = vxlqn_5_s2456;
                            vxl_5_s2460_l0 = vxln_5_s2460_l0;
                            vxlq_5_s2460 = vxlqn_5_s2460;
                            vxl_5_s22657_l0 = vxln_5_s22657_l0;
                            vxl_5_s22659_l0 = vxln_5_s22659_l0;
                            vxl_5_s22661_l0 = vxln_5_s22661_l0;
                            vxl_5_s22663_l0 = vxln_5_s22663_l0;
                            for (;;) {
                                if (!(((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)))) {
                                    if (0UL) {
                                        vxlqn_5_s2456 = VX_SNAPSHOT8(vxlq_5_s2456);
                                        vxln_5_s2456_l0 = vxlqn_5_s2456 ? (VX_SNAPSHOT16(vxl_5_s2456_l0)) : 0;
                                        vxln_5_s2456_l1 = vxlqn_5_s2456 ? (VX_SNAPSHOT16(vxl_5_s2456_l1)) : 0;
                                        vxln_5_s2456_l2 = vxlqn_5_s2456 ? (VX_SNAPSHOT8(vxl_5_s2456_l2)) : 0;
                                        vxln_5_s2456_l3 = vxlqn_5_s2456 ? (VX_SNAPSHOT8(vxl_5_s2456_l3)) : 0;
                                        vxln_5_s2456_l4 = vxlqn_5_s2456 ? (VX_SNAPSHOT8(vxl_5_s2456_l4)) : 0;
                                        vxln_5_s2456_l5 = vxlqn_5_s2456 ? (VX_SNAPSHOT8(vxl_5_s2456_l5)) : 0;
                                        vxln_5_s2456_l6 = vxlqn_5_s2456 ? (VX_SNAPSHOT8(vxl_5_s2456_l6)) : 0;
                                        vxlqn_5_s2460 = VX_SNAPSHOT8(vxlq_5_s2460);
                                        vxln_5_s2460_l0 = vxlqn_5_s2460 ? (VX_SNAPSHOT8(vxl_5_s2460_l0)) : 0;
                                        vxln_5_s22657_l0 = (VX_SNAPSHOT16(vxl_5_s22657_l0));
                                        vxln_5_s22659_l0 = (VX_SNAPSHOT16(vxl_5_s22659_l0));
                                        vxln_5_s22661_l0 = (VX_SNAPSHOT8(vxl_5_s22661_l0));
                                        vxln_5_s22663_l0 = (VX_SNAPSHOT8(vxl_5_s22663_l0));
                                        vxl_5_s2456_l0 = vxln_5_s2456_l0;
                                        vxl_5_s2456_l1 = vxln_5_s2456_l1;
                                        vxl_5_s2456_l2 = vxln_5_s2456_l2;
                                        vxl_5_s2456_l3 = vxln_5_s2456_l3;
                                        vxl_5_s2456_l4 = vxln_5_s2456_l4;
                                        vxl_5_s2456_l5 = vxln_5_s2456_l5;
                                        vxl_5_s2456_l6 = vxln_5_s2456_l6;
                                        vxlq_5_s2456 = vxlqn_5_s2456;
                                        vxl_5_s2460_l0 = vxln_5_s2460_l0;
                                        vxlq_5_s2460 = vxlqn_5_s2460;
                                        vxl_5_s22657_l0 = vxln_5_s22657_l0;
                                        vxl_5_s22659_l0 = vxln_5_s22659_l0;
                                        vxl_5_s22661_l0 = vxln_5_s22661_l0;
                                        vxl_5_s22663_l0 = vxln_5_s22663_l0;
                                        continue;
                                    }
                                    vxlqn_5_s2456 = VX_SNAPSHOT8(vxlq_5_s2456);
                                    vxln_5_s2456_l0 = vxlqn_5_s2456 ? (VX_SNAPSHOT16(vxl_5_s2456_l0)) : 0;
                                    vxln_5_s2456_l1 = vxlqn_5_s2456 ? (VX_SNAPSHOT16(vxl_5_s2456_l1)) : 0;
                                    vxln_5_s2456_l2 = vxlqn_5_s2456 ? (VX_SNAPSHOT8(vxl_5_s2456_l2)) : 0;
                                    vxln_5_s2456_l3 = vxlqn_5_s2456 ? (VX_SNAPSHOT8(vxl_5_s2456_l3)) : 0;
                                    vxln_5_s2456_l4 = vxlqn_5_s2456 ? (VX_SNAPSHOT8(vxl_5_s2456_l4)) : 0;
                                    vxln_5_s2456_l5 = vxlqn_5_s2456 ? (VX_SNAPSHOT8(vxl_5_s2456_l5)) : 0;
                                    vxln_5_s2456_l6 = vxlqn_5_s2456 ? (VX_SNAPSHOT8(vxl_5_s2456_l6)) : 0;
                                    vxlqn_5_s2460 = VX_SNAPSHOT8(vxlq_5_s2460);
                                    vxln_5_s2460_l0 = vxlqn_5_s2460 ? (VX_SNAPSHOT8(vxl_5_s2460_l0)) : 0;
                                    vxln_5_s22657_l0 = (VX_SNAPSHOT16(vxl_5_s22657_l0));
                                    vxln_5_s22659_l0 = (VX_SNAPSHOT16(vxl_5_s22659_l0));
                                    vxln_5_s22661_l0 = (VX_SNAPSHOT8(vxl_5_s22661_l0));
                                    vxln_5_s22663_l0 = (VX_SNAPSHOT8(vxl_5_s22663_l0));
                                    vxl_5_s2456_l0 = vxln_5_s2456_l0;
                                    vxl_5_s2456_l1 = vxln_5_s2456_l1;
                                    vxl_5_s2456_l2 = vxln_5_s2456_l2;
                                    vxl_5_s2456_l3 = vxln_5_s2456_l3;
                                    vxl_5_s2456_l4 = vxln_5_s2456_l4;
                                    vxl_5_s2456_l5 = vxln_5_s2456_l5;
                                    vxl_5_s2456_l6 = vxln_5_s2456_l6;
                                    vxlq_5_s2456 = vxlqn_5_s2456;
                                    vxl_5_s2460_l0 = vxln_5_s2460_l0;
                                    vxlq_5_s2460 = vxlqn_5_s2460;
                                    vxl_5_s22657_l0 = vxln_5_s22657_l0;
                                    vxl_5_s22659_l0 = vxln_5_s22659_l0;
                                    vxl_5_s22661_l0 = vxln_5_s22661_l0;
                                    vxl_5_s22663_l0 = vxln_5_s22663_l0;
                                    break;
                                }
                                if (((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL))) {
                                    vx_invoke_external_motion_query(vxt_24, VX_SNAPSHOT16(vxl_5_s2456_l0), VX_SNAPSHOT16(vxl_5_s2456_l1), VX_SNAPSHOT8(vxl_5_s2456_l2), VX_SNAPSHOT8(vxl_5_s2456_l3), VX_SNAPSHOT8(vxl_5_s2456_l4), VX_SNAPSHOT8(vxl_5_s2456_l5), VX_SNAPSHOT8(vxl_5_s2456_l6), (((uint32_t)(VX_SNAPSHOT8(vxl_5_s22661_l0)) == (uint32_t)(1UL)) ? VX_SNAPSHOT16(vxl_5_s2456_l0) : VX_SNAPSHOT16(vxl_5_s22657_l0)), (((uint32_t)(VX_SNAPSHOT8(vxl_5_s22661_l0)) == (uint32_t)(2UL)) ? VX_SNAPSHOT16(vxl_5_s2456_l1) : VX_SNAPSHOT16(vxl_5_s22659_l0)));
                                } else {
                                }
                                if (0UL) {
                                    vxlqn_5_s2456 = (((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? 1UL : VX_SNAPSHOT8(vxlq_5_s2456));
                                    vxln_5_s2456_l0 = vxlqn_5_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_24[7])) & (uint32_t)(1UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(VX_SNAPSHOT8(vxl_5_s22661_l0)) != (uint32_t)(1UL)) ? VX_SNAPSHOT16(vxl_5_s22657_l0) : VX_SNAPSHOT32(vxt_24[0])) : VX_SNAPSHOT32(vxt_24[0])) : VX_SNAPSHOT16(vxl_5_s2456_l0))) : 0;
                                    vxln_5_s2456_l1 = vxlqn_5_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_24[7])) & (uint32_t)(1UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(VX_SNAPSHOT8(vxl_5_s22661_l0)) != (uint32_t)(2UL)) ? VX_SNAPSHOT16(vxl_5_s22659_l0) : VX_SNAPSHOT32(vxt_24[1])) : VX_SNAPSHOT32(vxt_24[1])) : VX_SNAPSHOT16(vxl_5_s2456_l1))) : 0;
                                    vxln_5_s2456_l2 = vxlqn_5_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? VX_SNAPSHOT32(vxt_24[2]) : VX_SNAPSHOT8(vxl_5_s2456_l2))) : 0;
                                    vxln_5_s2456_l3 = vxlqn_5_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? VX_SNAPSHOT32(vxt_24[3]) : VX_SNAPSHOT8(vxl_5_s2456_l3))) : 0;
                                    vxln_5_s2456_l4 = vxlqn_5_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? VX_SNAPSHOT32(vxt_24[4]) : VX_SNAPSHOT8(vxl_5_s2456_l4))) : 0;
                                    vxln_5_s2456_l5 = vxlqn_5_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? VX_SNAPSHOT32(vxt_24[5]) : VX_SNAPSHOT8(vxl_5_s2456_l5))) : 0;
                                    vxln_5_s2456_l6 = vxlqn_5_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? VX_SNAPSHOT32(vxt_24[6]) : VX_SNAPSHOT8(vxl_5_s2456_l6))) : 0;
                                    vxlqn_5_s2460 = (((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? 1UL : VX_SNAPSHOT8(vxlq_5_s2460));
                                    vxln_5_s2460_l0 = vxlqn_5_s2460 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? VX_SNAPSHOT32(vxt_24[7]) : VX_SNAPSHOT8(vxl_5_s2460_l0))) : 0;
                                    vxln_5_s22657_l0 = (VX_SNAPSHOT16(vxl_5_s22657_l0));
                                    vxln_5_s22659_l0 = (VX_SNAPSHOT16(vxl_5_s22659_l0));
                                    vxln_5_s22661_l0 = ((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_24[7])) & (uint32_t)(1UL)) & 255UL)) == (uint32_t)(0UL)) ? VX_SNAPSHOT8(vxl_5_s22661_l0) : (((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22661_l0)) == (uint32_t)(0UL)) ? ((uint32_t)(VX_SNAPSHOT16(vxl_5_s22657_l0)) != (uint32_t)(VX_SNAPSHOT32(vxt_24[0]))) : 0UL) ? ((uint32_t)(VX_SNAPSHOT16(vxl_5_s22659_l0)) != (uint32_t)(VX_SNAPSHOT32(vxt_24[1]))) : 0UL) ? 1UL : (((uint32_t)(VX_SNAPSHOT8(vxl_5_s22661_l0)) == (uint32_t)(1UL)) ? 2UL : VX_SNAPSHOT8(vxl_5_s22661_l0)))) : VX_SNAPSHOT8(vxl_5_s22661_l0)));
                                    vxln_5_s22663_l0 = ((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_24[7])) & (uint32_t)(1UL)) & 255UL)) == (uint32_t)(0UL)) ? 0UL : (((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22661_l0)) == (uint32_t)(0UL)) ? ((uint32_t)(VX_SNAPSHOT16(vxl_5_s22657_l0)) != (uint32_t)(VX_SNAPSHOT32(vxt_24[0]))) : 0UL) ? ((uint32_t)(VX_SNAPSHOT16(vxl_5_s22659_l0)) != (uint32_t)(VX_SNAPSHOT32(vxt_24[1]))) : 0UL) ? VX_SNAPSHOT8(vxl_5_s22663_l0) : (((uint32_t)(VX_SNAPSHOT8(vxl_5_s22661_l0)) == (uint32_t)(1UL)) ? VX_SNAPSHOT8(vxl_5_s22663_l0) : 0UL))) : VX_SNAPSHOT8(vxl_5_s22663_l0)));
                                    vxl_5_s2456_l0 = vxln_5_s2456_l0;
                                    vxl_5_s2456_l1 = vxln_5_s2456_l1;
                                    vxl_5_s2456_l2 = vxln_5_s2456_l2;
                                    vxl_5_s2456_l3 = vxln_5_s2456_l3;
                                    vxl_5_s2456_l4 = vxln_5_s2456_l4;
                                    vxl_5_s2456_l5 = vxln_5_s2456_l5;
                                    vxl_5_s2456_l6 = vxln_5_s2456_l6;
                                    vxlq_5_s2456 = vxlqn_5_s2456;
                                    vxl_5_s2460_l0 = vxln_5_s2460_l0;
                                    vxlq_5_s2460 = vxlqn_5_s2460;
                                    vxl_5_s22657_l0 = vxln_5_s22657_l0;
                                    vxl_5_s22659_l0 = vxln_5_s22659_l0;
                                    vxl_5_s22661_l0 = vxln_5_s22661_l0;
                                    vxl_5_s22663_l0 = vxln_5_s22663_l0;
                                    break;
                                }
                                vxlqn_5_s2456 = (((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? 1UL : VX_SNAPSHOT8(vxlq_5_s2456));
                                vxln_5_s2456_l0 = vxlqn_5_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_24[7])) & (uint32_t)(1UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(VX_SNAPSHOT8(vxl_5_s22661_l0)) != (uint32_t)(1UL)) ? VX_SNAPSHOT16(vxl_5_s22657_l0) : VX_SNAPSHOT32(vxt_24[0])) : VX_SNAPSHOT32(vxt_24[0])) : VX_SNAPSHOT16(vxl_5_s2456_l0))) : 0;
                                vxln_5_s2456_l1 = vxlqn_5_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_24[7])) & (uint32_t)(1UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(VX_SNAPSHOT8(vxl_5_s22661_l0)) != (uint32_t)(2UL)) ? VX_SNAPSHOT16(vxl_5_s22659_l0) : VX_SNAPSHOT32(vxt_24[1])) : VX_SNAPSHOT32(vxt_24[1])) : VX_SNAPSHOT16(vxl_5_s2456_l1))) : 0;
                                vxln_5_s2456_l2 = vxlqn_5_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? VX_SNAPSHOT32(vxt_24[2]) : VX_SNAPSHOT8(vxl_5_s2456_l2))) : 0;
                                vxln_5_s2456_l3 = vxlqn_5_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? VX_SNAPSHOT32(vxt_24[3]) : VX_SNAPSHOT8(vxl_5_s2456_l3))) : 0;
                                vxln_5_s2456_l4 = vxlqn_5_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? VX_SNAPSHOT32(vxt_24[4]) : VX_SNAPSHOT8(vxl_5_s2456_l4))) : 0;
                                vxln_5_s2456_l5 = vxlqn_5_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? VX_SNAPSHOT32(vxt_24[5]) : VX_SNAPSHOT8(vxl_5_s2456_l5))) : 0;
                                vxln_5_s2456_l6 = vxlqn_5_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? VX_SNAPSHOT32(vxt_24[6]) : VX_SNAPSHOT8(vxl_5_s2456_l6))) : 0;
                                vxlqn_5_s2460 = (((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? 1UL : VX_SNAPSHOT8(vxlq_5_s2460));
                                vxln_5_s2460_l0 = vxlqn_5_s2460 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? VX_SNAPSHOT32(vxt_24[7]) : VX_SNAPSHOT8(vxl_5_s2460_l0))) : 0;
                                vxln_5_s22657_l0 = (VX_SNAPSHOT16(vxl_5_s22657_l0));
                                vxln_5_s22659_l0 = (VX_SNAPSHOT16(vxl_5_s22659_l0));
                                vxln_5_s22661_l0 = ((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_24[7])) & (uint32_t)(1UL)) & 255UL)) == (uint32_t)(0UL)) ? VX_SNAPSHOT8(vxl_5_s22661_l0) : (((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22661_l0)) == (uint32_t)(0UL)) ? ((uint32_t)(VX_SNAPSHOT16(vxl_5_s22657_l0)) != (uint32_t)(VX_SNAPSHOT32(vxt_24[0]))) : 0UL) ? ((uint32_t)(VX_SNAPSHOT16(vxl_5_s22659_l0)) != (uint32_t)(VX_SNAPSHOT32(vxt_24[1]))) : 0UL) ? 1UL : (((uint32_t)(VX_SNAPSHOT8(vxl_5_s22661_l0)) == (uint32_t)(1UL)) ? 2UL : VX_SNAPSHOT8(vxl_5_s22661_l0)))) : VX_SNAPSHOT8(vxl_5_s22661_l0)));
                                vxln_5_s22663_l0 = ((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22663_l0)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT32(vxt_24[7])) & (uint32_t)(1UL)) & 255UL)) == (uint32_t)(0UL)) ? 0UL : (((((uint32_t)(VX_SNAPSHOT8(vxl_5_s22661_l0)) == (uint32_t)(0UL)) ? ((uint32_t)(VX_SNAPSHOT16(vxl_5_s22657_l0)) != (uint32_t)(VX_SNAPSHOT32(vxt_24[0]))) : 0UL) ? ((uint32_t)(VX_SNAPSHOT16(vxl_5_s22659_l0)) != (uint32_t)(VX_SNAPSHOT32(vxt_24[1]))) : 0UL) ? VX_SNAPSHOT8(vxl_5_s22663_l0) : (((uint32_t)(VX_SNAPSHOT8(vxl_5_s22661_l0)) == (uint32_t)(1UL)) ? VX_SNAPSHOT8(vxl_5_s22663_l0) : 0UL))) : VX_SNAPSHOT8(vxl_5_s22663_l0)));
                                vxl_5_s2456_l0 = vxln_5_s2456_l0;
                                vxl_5_s2456_l1 = vxln_5_s2456_l1;
                                vxl_5_s2456_l2 = vxln_5_s2456_l2;
                                vxl_5_s2456_l3 = vxln_5_s2456_l3;
                                vxl_5_s2456_l4 = vxln_5_s2456_l4;
                                vxl_5_s2456_l5 = vxln_5_s2456_l5;
                                vxl_5_s2456_l6 = vxln_5_s2456_l6;
                                vxlq_5_s2456 = vxlqn_5_s2456;
                                vxl_5_s2460_l0 = vxln_5_s2460_l0;
                                vxlq_5_s2460 = vxlqn_5_s2460;
                                vxl_5_s22657_l0 = vxln_5_s22657_l0;
                                vxl_5_s22659_l0 = vxln_5_s22659_l0;
                                vxl_5_s22661_l0 = vxln_5_s22661_l0;
                                vxl_5_s22663_l0 = vxln_5_s22663_l0;
                            }
                        } else {
                        }
                        if (0UL) {
                            vxlqn_3_s2456 = (((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxlq_5_s2456) : VX_SNAPSHOT8(vxlq_3_s2456));
                            vxln_3_s2456_l0 = vxlqn_3_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL)) ? VX_SNAPSHOT16(vxl_5_s2456_l0) : VX_SNAPSHOT16(vxl_3_s2456_l0))) : 0;
                            vxln_3_s2456_l1 = vxlqn_3_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL)) ? VX_SNAPSHOT16(vxl_5_s2456_l1) : VX_SNAPSHOT16(vxl_3_s2456_l1))) : 0;
                            vxln_3_s2456_l2 = vxlqn_3_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxl_5_s2456_l2) : VX_SNAPSHOT8(vxl_3_s2456_l2))) : 0;
                            vxln_3_s2456_l3 = vxlqn_3_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxl_5_s2456_l3) : VX_SNAPSHOT8(vxl_3_s2456_l3))) : 0;
                            vxln_3_s2456_l4 = vxlqn_3_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxl_5_s2456_l4) : VX_SNAPSHOT8(vxl_3_s2456_l4))) : 0;
                            vxln_3_s2456_l5 = vxlqn_3_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxl_5_s2456_l5) : VX_SNAPSHOT8(vxl_3_s2456_l5))) : 0;
                            vxln_3_s2456_l6 = vxlqn_3_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxl_5_s2456_l6) : VX_SNAPSHOT8(vxl_3_s2456_l6))) : 0;
                            vxlqn_3_s2460 = (((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxlq_5_s2460) : VX_SNAPSHOT8(vxlq_3_s2460));
                            vxln_3_s2460_l0 = vxlqn_3_s2460 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxl_5_s2460_l0) : VX_SNAPSHOT8(vxl_3_s2460_l0))) : 0;
                            vxln_3_s20180_l0 = ((((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL)) ? (((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) + (uint32_t)(1UL)) & 255UL) : VX_SNAPSHOT8(vxl_3_s20180_l0)));
                            vxl_3_s2456_l0 = vxln_3_s2456_l0;
                            vxl_3_s2456_l1 = vxln_3_s2456_l1;
                            vxl_3_s2456_l2 = vxln_3_s2456_l2;
                            vxl_3_s2456_l3 = vxln_3_s2456_l3;
                            vxl_3_s2456_l4 = vxln_3_s2456_l4;
                            vxl_3_s2456_l5 = vxln_3_s2456_l5;
                            vxl_3_s2456_l6 = vxln_3_s2456_l6;
                            vxlq_3_s2456 = vxlqn_3_s2456;
                            vxl_3_s2460_l0 = vxln_3_s2460_l0;
                            vxlq_3_s2460 = vxlqn_3_s2460;
                            vxl_3_s20180_l0 = vxln_3_s20180_l0;
                            break;
                        }
                        vxlqn_3_s2456 = (((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxlq_5_s2456) : VX_SNAPSHOT8(vxlq_3_s2456));
                        vxln_3_s2456_l0 = vxlqn_3_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL)) ? VX_SNAPSHOT16(vxl_5_s2456_l0) : VX_SNAPSHOT16(vxl_3_s2456_l0))) : 0;
                        vxln_3_s2456_l1 = vxlqn_3_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL)) ? VX_SNAPSHOT16(vxl_5_s2456_l1) : VX_SNAPSHOT16(vxl_3_s2456_l1))) : 0;
                        vxln_3_s2456_l2 = vxlqn_3_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxl_5_s2456_l2) : VX_SNAPSHOT8(vxl_3_s2456_l2))) : 0;
                        vxln_3_s2456_l3 = vxlqn_3_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxl_5_s2456_l3) : VX_SNAPSHOT8(vxl_3_s2456_l3))) : 0;
                        vxln_3_s2456_l4 = vxlqn_3_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxl_5_s2456_l4) : VX_SNAPSHOT8(vxl_3_s2456_l4))) : 0;
                        vxln_3_s2456_l5 = vxlqn_3_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxl_5_s2456_l5) : VX_SNAPSHOT8(vxl_3_s2456_l5))) : 0;
                        vxln_3_s2456_l6 = vxlqn_3_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxl_5_s2456_l6) : VX_SNAPSHOT8(vxl_3_s2456_l6))) : 0;
                        vxlqn_3_s2460 = (((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxlq_5_s2460) : VX_SNAPSHOT8(vxlq_3_s2460));
                        vxln_3_s2460_l0 = vxlqn_3_s2460 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxl_5_s2460_l0) : VX_SNAPSHOT8(vxl_3_s2460_l0))) : 0;
                        vxln_3_s20180_l0 = ((((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) < (uint32_t)(2UL)) ? (((uint32_t)(VX_SNAPSHOT8(vxl_3_s20180_l0)) + (uint32_t)(1UL)) & 255UL) : VX_SNAPSHOT8(vxl_3_s20180_l0)));
                        vxl_3_s2456_l0 = vxln_3_s2456_l0;
                        vxl_3_s2456_l1 = vxln_3_s2456_l1;
                        vxl_3_s2456_l2 = vxln_3_s2456_l2;
                        vxl_3_s2456_l3 = vxln_3_s2456_l3;
                        vxl_3_s2456_l4 = vxln_3_s2456_l4;
                        vxl_3_s2456_l5 = vxln_3_s2456_l5;
                        vxl_3_s2456_l6 = vxln_3_s2456_l6;
                        vxlq_3_s2456 = vxlqn_3_s2456;
                        vxl_3_s2460_l0 = vxln_3_s2460_l0;
                        vxlq_3_s2460 = vxlqn_3_s2460;
                        vxl_3_s20180_l0 = vxln_3_s20180_l0;
                    }
                }
            } else {
            }
            if (0UL) {
                vxlqn_2_s2456 = (((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3))) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l4)) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL)) ? 1UL : VX_SNAPSHOT8(vxlq_3_s2456)) : VX_SNAPSHOT8(vxlq_2_s2456));
                vxln_2_s2456_l0 = vxlqn_2_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3))) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l4)) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL)) ? VX_SNAPSHOT16(vxl_2_s2456_l0) : VX_SNAPSHOT16(vxl_3_s2456_l0)) : VX_SNAPSHOT16(vxl_2_s2456_l0))) : 0;
                vxln_2_s2456_l1 = vxlqn_2_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3))) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l4)) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL)) ? VX_SNAPSHOT16(vxl_2_s2456_l1) : VX_SNAPSHOT16(vxl_3_s2456_l1)) : VX_SNAPSHOT16(vxl_2_s2456_l1))) : 0;
                vxln_2_s2456_l2 = vxlqn_2_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3))) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l4)) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxl_2_s2456_l2) : VX_SNAPSHOT8(vxl_3_s2456_l2)) : VX_SNAPSHOT8(vxl_2_s2456_l2))) : 0;
                vxln_2_s2456_l3 = vxlqn_2_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3))) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l4)) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxl_2_s2456_l3) : VX_SNAPSHOT8(vxl_3_s2456_l3)) : VX_SNAPSHOT8(vxl_2_s2456_l3))) : 0;
                vxln_2_s2456_l4 = vxlqn_2_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3))) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l4)) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL)) ? 0UL : VX_SNAPSHOT8(vxl_3_s2456_l4)) : VX_SNAPSHOT8(vxl_2_s2456_l4))) : 0;
                vxln_2_s2456_l5 = vxlqn_2_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3))) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l4)) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxl_2_s2456_l5) : VX_SNAPSHOT8(vxl_3_s2456_l5)) : VX_SNAPSHOT8(vxl_2_s2456_l5))) : 0;
                vxln_2_s2456_l6 = vxlqn_2_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3))) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l4)) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxl_2_s2456_l6) : VX_SNAPSHOT8(vxl_3_s2456_l6)) : VX_SNAPSHOT8(vxl_2_s2456_l6))) : 0;
                vxlqn_2_s2460 = (((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3))) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l4)) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxlq_2_s2460) : VX_SNAPSHOT8(vxlq_3_s2460)) : VX_SNAPSHOT8(vxlq_2_s2460));
                vxln_2_s2460_l0 = vxlqn_2_s2460 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3))) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l4)) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxl_2_s2460_l0) : VX_SNAPSHOT8(vxl_3_s2460_l0)) : VX_SNAPSHOT8(vxl_2_s2460_l0))) : 0;
                vxln_2_s14616_l0 = ((((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3))) ? (((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) + (uint32_t)(1UL)) & 255UL) : VX_SNAPSHOT8(vxl_2_s14616_l0)));
                vxl_2_s2456_l0 = vxln_2_s2456_l0;
                vxl_2_s2456_l1 = vxln_2_s2456_l1;
                vxl_2_s2456_l2 = vxln_2_s2456_l2;
                vxl_2_s2456_l3 = vxln_2_s2456_l3;
                vxl_2_s2456_l4 = vxln_2_s2456_l4;
                vxl_2_s2456_l5 = vxln_2_s2456_l5;
                vxl_2_s2456_l6 = vxln_2_s2456_l6;
                vxlq_2_s2456 = vxlqn_2_s2456;
                vxl_2_s2460_l0 = vxln_2_s2460_l0;
                vxlq_2_s2460 = vxlqn_2_s2460;
                vxl_2_s14616_l0 = vxln_2_s14616_l0;
                break;
            }
            vxlqn_2_s2456 = (((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3))) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l4)) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL)) ? 1UL : VX_SNAPSHOT8(vxlq_3_s2456)) : VX_SNAPSHOT8(vxlq_2_s2456));
            vxln_2_s2456_l0 = vxlqn_2_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3))) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l4)) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL)) ? VX_SNAPSHOT16(vxl_2_s2456_l0) : VX_SNAPSHOT16(vxl_3_s2456_l0)) : VX_SNAPSHOT16(vxl_2_s2456_l0))) : 0;
            vxln_2_s2456_l1 = vxlqn_2_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3))) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l4)) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL)) ? VX_SNAPSHOT16(vxl_2_s2456_l1) : VX_SNAPSHOT16(vxl_3_s2456_l1)) : VX_SNAPSHOT16(vxl_2_s2456_l1))) : 0;
            vxln_2_s2456_l2 = vxlqn_2_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3))) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l4)) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxl_2_s2456_l2) : VX_SNAPSHOT8(vxl_3_s2456_l2)) : VX_SNAPSHOT8(vxl_2_s2456_l2))) : 0;
            vxln_2_s2456_l3 = vxlqn_2_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3))) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l4)) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxl_2_s2456_l3) : VX_SNAPSHOT8(vxl_3_s2456_l3)) : VX_SNAPSHOT8(vxl_2_s2456_l3))) : 0;
            vxln_2_s2456_l4 = vxlqn_2_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3))) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l4)) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL)) ? 0UL : VX_SNAPSHOT8(vxl_3_s2456_l4)) : VX_SNAPSHOT8(vxl_2_s2456_l4))) : 0;
            vxln_2_s2456_l5 = vxlqn_2_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3))) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l4)) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxl_2_s2456_l5) : VX_SNAPSHOT8(vxl_3_s2456_l5)) : VX_SNAPSHOT8(vxl_2_s2456_l5))) : 0;
            vxln_2_s2456_l6 = vxlqn_2_s2456 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3))) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l4)) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxl_2_s2456_l6) : VX_SNAPSHOT8(vxl_3_s2456_l6)) : VX_SNAPSHOT8(vxl_2_s2456_l6))) : 0;
            vxlqn_2_s2460 = (((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3))) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l4)) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxlq_2_s2460) : VX_SNAPSHOT8(vxlq_3_s2460)) : VX_SNAPSHOT8(vxlq_2_s2460));
            vxln_2_s2460_l0 = vxlqn_2_s2460 ? ((((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3))) ? (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l4)) + (uint32_t)(1UL)) & 255UL)) > (uint32_t)(2UL)) ? VX_SNAPSHOT8(vxl_2_s2460_l0) : VX_SNAPSHOT8(vxl_3_s2460_l0)) : VX_SNAPSHOT8(vxl_2_s2460_l0))) : 0;
            vxln_2_s14616_l0 = ((((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) < (uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l3))) ? (((uint32_t)(VX_SNAPSHOT8(vxl_2_s14616_l0)) + (uint32_t)(1UL)) & 255UL) : VX_SNAPSHOT8(vxl_2_s14616_l0)));
            vxl_2_s2456_l0 = vxln_2_s2456_l0;
            vxl_2_s2456_l1 = vxln_2_s2456_l1;
            vxl_2_s2456_l2 = vxln_2_s2456_l2;
            vxl_2_s2456_l3 = vxln_2_s2456_l3;
            vxl_2_s2456_l4 = vxln_2_s2456_l4;
            vxl_2_s2456_l5 = vxln_2_s2456_l5;
            vxl_2_s2456_l6 = vxln_2_s2456_l6;
            vxlq_2_s2456 = vxlqn_2_s2456;
            vxl_2_s2460_l0 = vxln_2_s2460_l0;
            vxlq_2_s2460 = vxlqn_2_s2460;
            vxl_2_s14616_l0 = vxln_2_s14616_l0;
        }
    }
    VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) & (uint32_t)(144UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) | (uint32_t)(144UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2))) == (uint32_t)(255UL)) ? vxp_a0_0 : VX_SNAPSHOT16(vxl_2_s2456_l0)));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) & (uint32_t)(144UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) | (uint32_t)(144UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2))) == (uint32_t)(255UL)) ? vxp_a0_1 : VX_SNAPSHOT16(vxl_2_s2456_l1)));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) & (uint32_t)(144UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) | (uint32_t)(144UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2))) == (uint32_t)(255UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) & (uint32_t)(144UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) | (uint32_t)(144UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) : VX_SNAPSHOT8(vxl_2_s2456_l2)));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) & (uint32_t)(144UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) | (uint32_t)(144UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2))) == (uint32_t)(255UL)) ? vxp_a0_3 : VX_SNAPSHOT8(vxl_2_s2456_l3)));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) & (uint32_t)(144UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) | (uint32_t)(144UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2))) == (uint32_t)(255UL)) ? vxp_a0_4 : VX_SNAPSHOT8(vxl_2_s2456_l4)));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) & (uint32_t)(144UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) | (uint32_t)(144UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2))) == (uint32_t)(255UL)) ? 0UL : VX_SNAPSHOT8(vxl_2_s2456_l5)));
    vx_payload[10] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[11] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) & (uint32_t)(144UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) | (uint32_t)(144UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2))) == (uint32_t)(255UL)) ? vxp_a0_6 : (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l2)) & (uint32_t)(16UL)) & 255UL)) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l2)) & (uint32_t)(128UL)) & 255UL)) == (uint32_t)(0UL)) ? 2UL : (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l2)) & (uint32_t)(64UL)) & 255UL)) == (uint32_t)(0UL)) ? 4UL : (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l2)) & (uint32_t)(32UL)) & 255UL)) == (uint32_t)(0UL)) ? 3UL : VX_SNAPSHOT8(vxl_2_s2456_l6)))))));
    vx_payload[12] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[13] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) & (uint32_t)(144UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) | (uint32_t)(144UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2))) == (uint32_t)(255UL)) ? 0UL : VX_SNAPSHOT8(vxl_2_s2460_l0)));
    vx_payload[14] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[15] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) & (uint32_t)(144UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) | (uint32_t)(144UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2))) == (uint32_t)(255UL)) ? 255UL : (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l2)) & (uint32_t)(240UL)) & 255UL)) == (uint32_t)(240UL)) ? 255UL : (((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l2)) & (uint32_t)(16UL)) & 255UL)) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l2)) & (uint32_t)(128UL)) & 255UL)) == (uint32_t)(0UL)) ? 2UL : (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l2)) & (uint32_t)(64UL)) & 255UL)) == (uint32_t)(0UL)) ? 4UL : (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l2)) & (uint32_t)(32UL)) & 255UL)) == (uint32_t)(0UL)) ? 3UL : VX_SNAPSHOT8(vxl_2_s2456_l6)))))) == (uint32_t)(1UL)) ? 8UL : (((uint32_t)((((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l2)) & (uint32_t)(128UL)) & 255UL)) == (uint32_t)(0UL)) ? 2UL : (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l2)) & (uint32_t)(64UL)) & 255UL)) == (uint32_t)(0UL)) ? 4UL : (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l2)) & (uint32_t)(32UL)) & 255UL)) == (uint32_t)(0UL)) ? 3UL : VX_SNAPSHOT8(vxl_2_s2456_l6))))) == (uint32_t)(2UL)) ? 6UL : (((uint32_t)((((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l2)) & (uint32_t)(64UL)) & 255UL)) == (uint32_t)(0UL)) ? 4UL : (((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l2)) & (uint32_t)(32UL)) & 255UL)) == (uint32_t)(0UL)) ? 3UL : VX_SNAPSHOT8(vxl_2_s2456_l6)))) == (uint32_t)(3UL)) ? 2UL : 4UL)))) + (uint32_t)((((uint32_t)((((uint32_t)(VX_SNAPSHOT8(vxl_2_s2456_l5)) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : 1UL))) & 255UL))));
    vx_payload[16] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[17] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) & (uint32_t)(144UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2)) | (uint32_t)(144UL)) & 255UL) : (((uint32_t)((((uint32_t)(vxp_a0_2) & (uint32_t)(96UL)) & 255UL)) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a0_2) | (uint32_t)(96UL)) & 255UL) : vxp_a0_2))) == (uint32_t)(255UL)) ? 0UL : 1UL));
    vx_payload[18] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[19] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_player_motion_read(uint16_t index) VX_ABI VX_RESIDENT {
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
void vx_scene_intro(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) > (uint32_t)(26112UL)) ? 8UL : 2UL) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a3) < (uint32_t)(34816UL)) ? 8UL : 3UL) : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? (((uint32_t)(((((uint32_t)(vxp_a1) <= (uint32_t)(138UL)) ? (((((((((((((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(0UL)) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(6UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(12UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(18UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(24UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(30UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(36UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(42UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(48UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(54UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(60UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(66UL))) : 0UL) ? 1UL : 0UL)) != (uint32_t)(0UL)) ? 4UL : 0UL) : (((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? 5UL : (((uint32_t)(vxp_a0) == (uint32_t)(5UL)) ? (((uint32_t)(((((uint32_t)(vxp_a1) <= (uint32_t)(138UL)) ? (((((((((((((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(0UL)) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(6UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(12UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(18UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(24UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(30UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(36UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(42UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(48UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(54UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(60UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a1) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a1) - (uint32_t)(72UL)) & 255UL) : vxp_a1)) == (uint32_t)(66UL))) : 0UL) ? 1UL : 0UL)) != (uint32_t)(0UL)) ? 6UL : 0UL) : (((uint32_t)(vxp_a0) == (uint32_t)(6UL)) ? 7UL : 0UL))))))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) > (uint32_t)(26112UL)) ? 1UL : 2UL) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a3) < (uint32_t)(34816UL)) ? 2UL : 3UL) : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? (((uint32_t)(vxp_a1) == (uint32_t)(210UL)) ? 4UL : 3UL) : (((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? 5UL : (((uint32_t)(vxp_a0) == (uint32_t)(5UL)) ? (((uint32_t)(vxp_a1) == (uint32_t)(210UL)) ? 6UL : 5UL) : vxp_a0)))))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? vxp_a1 : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) > (uint32_t)(26112UL)) ? (((uint32_t)(vxp_a1) + (uint32_t)(1UL)) & 255UL) : vxp_a1) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a3) < (uint32_t)(34816UL)) ? (((uint32_t)(vxp_a1) + (uint32_t)(1UL)) & 255UL) : 0UL) : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? (((uint32_t)(vxp_a1) + (uint32_t)(1UL)) & 255UL) : (((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(5UL)) ? (((uint32_t)(vxp_a1) + (uint32_t)(1UL)) & 255UL) : vxp_a1)))))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? vxp_a2 : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) > (uint32_t)(26112UL)) ? (((uint32_t)(vxp_a2) - (uint32_t)(64UL)) & 65535UL) : vxp_a2) : vxp_a2)));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? vxp_a3 : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? vxp_a3 : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a3) < (uint32_t)(34816UL)) ? (((uint32_t)(vxp_a3) + (uint32_t)(64UL)) & 65535UL) : vxp_a3) : vxp_a3))));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) > (uint32_t)(26112UL)) ? 3UL : 0UL) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a3) < (uint32_t)(34816UL)) ? 2UL : 3UL) : 0UL))));
    vx_payload[10] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[11] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 255UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) > (uint32_t)(26112UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) + (uint32_t)(1UL)) & 255UL)) & (uint32_t)(8UL)) & 255UL)) != (uint32_t)(0UL)) ? 2UL : 3UL) : 255UL) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a3) < (uint32_t)(34816UL)) ? (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) + (uint32_t)(1UL)) & 255UL)) & (uint32_t)(8UL)) & 255UL)) != (uint32_t)(0UL)) ? 6UL : 7UL) : 2UL) : 255UL))));
    vx_payload[12] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[13] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) > (uint32_t)(26112UL)) ? 0UL : 1UL) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? (((uint32_t)(vxp_a3) < (uint32_t)(34816UL)) ? 0UL : 1UL) : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? (((uint32_t)(vxp_a1) == (uint32_t)(210UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? 1UL : (((uint32_t)(vxp_a0) == (uint32_t)(5UL)) ? (((uint32_t)(vxp_a1) == (uint32_t)(210UL)) ? 1UL : 0UL) : 0UL)))))));
    vx_payload[14] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[15] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_scene_intro_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    case 5: return (uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8);
    case 6: return (uint32_t)vx_payload[12] + ((uint32_t)vx_payload[13] << 8);
    case 7: return (uint32_t)vx_payload[14] + ((uint32_t)vx_payload[15] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_scene_spark(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) > (uint32_t)(138UL)) ? 0UL : ((((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(0UL)) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(42UL))) ? 1UL : ((((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(6UL)) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(36UL))) ? 2UL : ((((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(12UL)) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(48UL))) ? 3UL : ((((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(18UL)) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(54UL))) ? 4UL : ((((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(24UL)) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(60UL))) ? 5UL : ((((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(30UL)) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(66UL))) ? 6UL : 0UL))))))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(0UL)) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(24UL))) ? 97UL : ((((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(6UL)) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(42UL))) ? 101UL : ((((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(12UL)) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(36UL))) ? 98UL : (((((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(18UL)) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(48UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(60UL))) ? 99UL : 100UL)))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(0UL)) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(18UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(54UL))) ? 135UL : ((((((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(6UL)) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(24UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(36UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a0) >= (uint32_t)(72UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(72UL)) & 255UL) : vxp_a0)) == (uint32_t)(48UL))) ? 137UL : 136UL)));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a0) == (uint32_t)(0UL)) : 0UL) ? 1UL : 0UL));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(132UL)) ? (((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? 1UL : 2UL) : 0UL));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_scene_spark_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_scene_wipe(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a2) == (uint32_t)(255UL)) ? 0UL : (((uint32_t)(vxp_a2) < (uint32_t)(4UL)) ? 1UL : ((((uint32_t)(vxp_a2) == (uint32_t)(5UL)) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(6UL))) ? 2UL : ((((uint32_t)(vxp_a2) == (uint32_t)(7UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(0UL)) : 0UL) ? 4UL : (((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((uint32_t)(vxp_a2) >= (uint32_t)(8UL)) : 0UL) ? ((uint32_t)(vxp_a2) <= (uint32_t)(10UL)) : 0UL) ? (((uint32_t)(vxp_a2) - (uint32_t)(3UL)) & 255UL) : 3UL))))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a2) < (uint32_t)(2UL)) ? vxp_a2 : (((uint32_t)(vxp_a2) == (uint32_t)(2UL)) ? (((uint32_t)(2UL) + (uint32_t)(vxp_a1)) & 255UL) : (((uint32_t)(vxp_a2) == (uint32_t)(3UL)) ? (((uint32_t)(23UL) - (uint32_t)(vxp_a1)) & 255UL) : (((uint32_t)(vxp_a2) == (uint32_t)(5UL)) ? (((uint32_t)(31UL) - (uint32_t)(vxp_a1)) & 255UL) : vxp_a1)))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a2) == (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 11UL : 12UL))) ? 1UL : 0UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) + (uint32_t)(1UL)) & 255UL) : vxp_a1));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a2) == (uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 11UL : 12UL))) ? 1UL : 0UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) == (uint32_t)(10UL)) ? 255UL : 2UL) : (((uint32_t)(vxp_a2) + (uint32_t)(1UL)) & 255UL)));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_scene_wipe_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_scene_revive(VX_STABLE uint8_t vxp_a0) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a0) - (uint32_t)(2UL)) & 255UL)) < (uint32_t)(6UL)) ? 6UL : (((uint32_t)(vxp_a0) - (uint32_t)(2UL)) & 255UL)));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_scene_revive_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_scene_door(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint8_t vxp_a4) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)(vxp_a1) <= (uint32_t)((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? 16UL : 6UL))) ? 2UL : 0UL)));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? vxp_a2 : (((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? (((uint32_t)(vxp_a2) + (uint32_t)(16UL)) & 65535UL) : (((uint32_t)(vxp_a2) - (uint32_t)(16UL)) & 65535UL))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? vxp_a3 : (((uint32_t)((((uint32_t)(vxp_a3) + (uint32_t)(256UL)) & 65535UL)) & (uint32_t)(65024UL)) & 65535UL)));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? 4UL : 3UL));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? 4UL : 2UL)) + (uint32_t)((((uint32_t)((((uint32_t)(vxp_a4) & (uint32_t)(4UL)) & 255UL)) != (uint32_t)(0UL)) ? 0UL : 1UL))) & 255UL));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? 2UL : 4UL));
    vx_payload[10] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[11] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_scene_door_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    case 5: return (uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_scene_camera(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint8_t vxp_a5,VX_STABLE uint8_t vxp_a6) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((((uint32_t)((((uint32_t)((VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(((uint16_t)((((uint16_t)(vxp_a0)) >> 8)))))) - ((uint16_t)(vxp_a2))) < 8))) & 255UL)))) ? ((uint32_t)(vxp_a4) > (uint32_t)(0UL)) : 0UL) ? (((uint32_t)(vxp_a2) - (uint32_t)(1UL)) & 255UL) : (((((uint32_t)((((uint32_t)((VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(((uint16_t)((((uint16_t)(vxp_a0)) >> 8)))))) - ((uint16_t)(vxp_a2))) > 13))) & 255UL)))) ? ((uint32_t)(vxp_a4) < (uint32_t)(106UL)) : 0UL) ? (((uint32_t)(vxp_a2) + (uint32_t)(1UL)) & 255UL) : vxp_a4)));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((((uint32_t)((((uint32_t)((VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(((uint16_t)((((uint16_t)(vxp_a1)) >> 8)))))) - ((uint16_t)(vxp_a3))) < 10))) & 255UL)))) ? ((uint32_t)(vxp_a5) > (uint32_t)(0UL)) : 0UL) ? (((uint32_t)(vxp_a3) - (uint32_t)(1UL)) & 255UL) : (((((uint32_t)((((uint32_t)((VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(((uint16_t)((((uint16_t)(vxp_a1)) >> 8)))))) - ((uint16_t)(vxp_a3))) > 20))) & 255UL)))) ? ((uint32_t)(vxp_a5) < (uint32_t)(224UL)) : 0UL) ? (((uint32_t)(vxp_a3) + (uint32_t)(1UL)) & 255UL) : vxp_a5)));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a6) | (uint32_t)((((uint32_t)(vxp_a2) != (uint32_t)((((((uint32_t)((((uint32_t)((VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(((uint16_t)((((uint16_t)(vxp_a0)) >> 8)))))) - ((uint16_t)(vxp_a2))) < 8))) & 255UL)))) ? ((uint32_t)(vxp_a4) > (uint32_t)(0UL)) : 0UL) ? (((uint32_t)(vxp_a2) - (uint32_t)(1UL)) & 255UL) : (((((uint32_t)((((uint32_t)((VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(((uint16_t)((((uint16_t)(vxp_a0)) >> 8)))))) - ((uint16_t)(vxp_a2))) > 13))) & 255UL)))) ? ((uint32_t)(vxp_a4) < (uint32_t)(106UL)) : 0UL) ? (((uint32_t)(vxp_a2) + (uint32_t)(1UL)) & 255UL) : vxp_a4)))) ? 1UL : 0UL))) & 255UL)) | (uint32_t)((((uint32_t)(vxp_a3) != (uint32_t)((((((uint32_t)((((uint32_t)((VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(((uint16_t)((((uint16_t)(vxp_a1)) >> 8)))))) - ((uint16_t)(vxp_a3))) < 10))) & 255UL)))) ? ((uint32_t)(vxp_a5) > (uint32_t)(0UL)) : 0UL) ? (((uint32_t)(vxp_a3) - (uint32_t)(1UL)) & 255UL) : (((((uint32_t)((((uint32_t)((VX_VALUE_I16(((uint16_t)(VX_VALUE_I16(((uint16_t)((((uint16_t)(vxp_a1)) >> 8)))))) - ((uint16_t)(vxp_a3))) > 20))) & 255UL)))) ? ((uint32_t)(vxp_a5) < (uint32_t)(224UL)) : 0UL) ? (((uint32_t)(vxp_a3) + (uint32_t)(1UL)) & 255UL) : vxp_a5)))) ? 1UL : 0UL))) & 255UL));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_scene_camera_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_scene_brief(VX_STABLE uint8_t vxp_a0) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) < (uint32_t)(5UL)) ? (((uint32_t)(vxp_a0) + (uint32_t)(1UL)) & 255UL) : 0UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) + (uint32_t)(1UL)) & 255UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? 1UL : 0UL));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_scene_brief_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return 29UL;
    case 4: return 235UL;
    default: vx_trap(16); return 0;
    }
}
void vx_world_frame(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a0) - (uint32_t)(vxp_a1)) & 255UL)) > (uint32_t)(3UL)) ? 1UL : (((uint32_t)(vxp_a0) - (uint32_t)(vxp_a1)) & 255UL)));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a2) + (uint32_t)(1UL)) & 255UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_world_frame_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_world_window(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? ((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) - (uint32_t)(vxp_a3)) & 255UL)) + (uint32_t)(3UL)) & 255UL)) < (uint32_t)(30UL)) ? ((uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) - (uint32_t)(vxp_a4)) & 255UL)) + (uint32_t)(3UL)) & 255UL)) < (uint32_t)(38UL)) : 0UL) ? 1UL : 0UL) : ((((uint32_t)(((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a1) - (uint32_t)(vxp_a3)) & 255UL)) + (uint32_t)(3UL)) & 255UL)) < (uint32_t)(30UL)) ? ((uint32_t)((((uint32_t)((((uint32_t)(vxp_a2) - (uint32_t)(vxp_a4)) & 255UL)) + (uint32_t)(3UL)) & 255UL)) < (uint32_t)(38UL)) : 0UL) ? 1UL : 0UL)) != (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(vxp_a1) - (uint32_t)(vxp_a3)) & 255UL)) >= (uint32_t)(24UL)) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a2) - (uint32_t)(vxp_a4)) & 255UL)) >= (uint32_t)(32UL))) : 0UL) ? 1UL : 0UL)));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_world_window_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_world_follow(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint8_t vxp_a5) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)(((((((uint32_t)(vxp_a0) != (uint32_t)(vxp_a2)) ? 1UL : ((uint32_t)(vxp_a1) != (uint32_t)(vxp_a3))) ? 1UL : ((uint32_t)(vxp_a4) != (uint32_t)(vxp_a5))) ? 1UL : ((uint32_t)(vxp_a4) == (uint32_t)(0UL))) ? 1UL : 0UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_world_follow_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_world_scroll(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3,VX_STABLE uint8_t vxp_a4) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a2) < (uint32_t)(vxp_a0)) ? (((uint32_t)(vxp_a0) - (uint32_t)(1UL)) & 255UL) : (((uint32_t)(vxp_a2) > (uint32_t)(vxp_a0)) ? (((uint32_t)(vxp_a0) + (uint32_t)(1UL)) & 255UL) : vxp_a0)));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a3) < (uint32_t)(vxp_a1)) ? (((uint32_t)(vxp_a1) - (uint32_t)(1UL)) & 255UL) : (((uint32_t)(vxp_a3) > (uint32_t)(vxp_a1)) ? (((uint32_t)(vxp_a1) + (uint32_t)(1UL)) & 255UL) : vxp_a1)));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a2) < (uint32_t)(vxp_a0)) ? 0UL : (((uint32_t)(vxp_a2) > (uint32_t)(vxp_a0)) ? 7UL : 255UL)));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a3) < (uint32_t)(vxp_a1)) ? 0UL : (((uint32_t)(vxp_a3) > (uint32_t)(vxp_a1)) ? 31UL : 255UL)));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a2) < (uint32_t)(vxp_a0)) ? 255UL : (((uint32_t)(vxp_a2) > (uint32_t)(vxp_a0)) ? 1UL : 0UL)));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a2) != (uint32_t)(vxp_a0)) ? 1UL : ((uint32_t)(vxp_a3) != (uint32_t)(vxp_a1))) ? 1UL : vxp_a4));
    vx_payload[10] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[11] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_world_scroll_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    case 5: return (uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_world_seed(VX_STABLE uint8_t vxp_a0) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 2UL : (((uint32_t)(vxp_a0) < (uint32_t)(4UL)) ? 3UL : (((uint32_t)(vxp_a0) < (uint32_t)(6UL)) ? 4UL : (((uint32_t)(vxp_a0) < (uint32_t)(10UL)) ? 5UL : (((uint32_t)(vxp_a0) < (uint32_t)(12UL)) ? 6UL : (((uint32_t)(vxp_a0) < (uint32_t)(16UL)) ? 7UL : (((uint32_t)(vxp_a0) == (uint32_t)(16UL)) ? 8UL : 0UL)))))))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a0) < (uint32_t)(2UL)) ? 1UL : ((uint32_t)(vxp_a0) >= (uint32_t)(16UL))) ? 0UL : (((uint32_t)(vxp_a0) < (uint32_t)(4UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(2UL)) & 255UL) : (((uint32_t)(vxp_a0) < (uint32_t)(6UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(4UL)) & 255UL) : (((uint32_t)(vxp_a0) < (uint32_t)(10UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(6UL)) & 255UL) : (((uint32_t)(vxp_a0) < (uint32_t)(12UL)) ? (((uint32_t)(vxp_a0) - (uint32_t)(10UL)) & 255UL) : (((uint32_t)(vxp_a0) - (uint32_t)(12UL)) & 255UL)))))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a0) == (uint32_t)(12UL))) ? 1UL : ((uint32_t)(vxp_a0) == (uint32_t)(15UL))) ? 120UL : (((uint32_t)(vxp_a0) == (uint32_t)(6UL)) ? 104UL : (((uint32_t)(vxp_a0) == (uint32_t)(7UL)) ? 106UL : (((uint32_t)(vxp_a0) == (uint32_t)(8UL)) ? 103UL : (((uint32_t)(vxp_a0) == (uint32_t)(9UL)) ? 108UL : (((uint32_t)(vxp_a0) == (uint32_t)(10UL)) ? 86UL : (((uint32_t)(vxp_a0) == (uint32_t)(11UL)) ? 88UL : (((uint32_t)(vxp_a0) == (uint32_t)(13UL)) ? 124UL : (((uint32_t)(vxp_a0) == (uint32_t)(14UL)) ? 122UL : (((uint32_t)(vxp_a0) == (uint32_t)(16UL)) ? 118UL : 0UL)))))))))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 126UL : (((uint32_t)(vxp_a0) == (uint32_t)(6UL)) ? 24UL : (((uint32_t)(vxp_a0) == (uint32_t)(7UL)) ? 40UL : (((uint32_t)(vxp_a0) == (uint32_t)(8UL)) ? 56UL : (((uint32_t)(vxp_a0) == (uint32_t)(9UL)) ? 20UL : (((uint32_t)(vxp_a0) == (uint32_t)(10UL)) ? 22UL : (((uint32_t)(vxp_a0) == (uint32_t)(11UL)) ? 26UL : (((uint32_t)(vxp_a0) == (uint32_t)(12UL)) ? 8UL : (((uint32_t)(vxp_a0) == (uint32_t)(13UL)) ? 30UL : (((uint32_t)(vxp_a0) == (uint32_t)(14UL)) ? 46UL : (((uint32_t)(vxp_a0) == (uint32_t)(15UL)) ? 64UL : (((uint32_t)(vxp_a0) == (uint32_t)(16UL)) ? 88UL : 0UL)))))))))))));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_world_seed_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_world_start(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)(0UL);
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(0UL);
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(99UL);
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(137UL);
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a0)) + ((uint16_t)(128)))))) >> 8))))) - ((uint8_t)(11)))))))) > ((uint8_t)(106))))) & 255UL)))) ? 106UL : (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a0)) + ((uint16_t)(128)))))) >> 8))))) - ((uint8_t)(11)))))))) & 255UL))))));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) + ((uint16_t)(128)))))) >> 8))))) - ((uint8_t)(16)))))))) & 255UL)))));
    vx_payload[10] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[11] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(25088UL);
    vx_payload[12] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[13] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(25600UL);
    vx_payload[14] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[15] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(34816UL);
    vx_payload[16] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[17] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(1UL);
    vx_payload[18] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[19] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_world_start_read(uint16_t index) VX_ABI VX_RESIDENT {
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
void vx_weapon_setup(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? (((uint32_t)(vxp_a1) < (uint32_t)(2UL)) ? 2UL : 0UL) : (((uint32_t)(((((uint32_t)(vxp_a0) == (uint32_t)(5UL)) ? 1UL : ((uint32_t)(vxp_a0) == (uint32_t)(6UL))) ? 1UL : 0UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vxp_a1) < (uint32_t)(2UL)) ? 3UL : (((uint32_t)(vxp_a1) < (uint32_t)(4UL)) ? (((uint32_t)(vxp_a0) == (uint32_t)(5UL)) ? 4UL : 5UL) : 0UL)) : (((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? 1UL : 0UL))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) & (uint32_t)(1UL)) & 255UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_weapon_setup_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_contact_box(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3,VX_STABLE uint8_t vxp_a4,VX_STABLE uint8_t vxp_a5) VX_ABI VX_RESIDENT {
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
uint32_t vx_contact_box_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_contact_player(VX_STABLE uint16_t vxp_a0,VX_STABLE uint16_t vxp_a1,VX_STABLE uint16_t vxp_a2,VX_STABLE uint16_t vxp_a3) VX_ABI VX_RESIDENT {
    if (((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a0)) - ((uint16_t)(vxp_a2)))))) >> 5))))))) + ((uint8_t)(8)))))) <= ((uint8_t)(16))))) & 255UL)))) ? 1UL : 0UL)) != (uint32_t)(0UL))) {
    } else {
    }
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)(((((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a0)) - ((uint16_t)(vxp_a2)))))) >> 5))))))) + ((uint8_t)(8)))))) <= ((uint8_t)(16))))) & 255UL)))) ? 1UL : 0UL)) != (uint32_t)(0UL)) ? ((uint32_t)(((((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) - ((uint16_t)(vxp_a3)))))) >> 5))))))) + ((uint8_t)(8)))))) <= ((uint8_t)(16))))) & 255UL)))) ? 1UL : 0UL)) != (uint32_t)(0UL)) : 0UL) ? 1UL : 0UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_contact_player_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_ui_menu(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)(((((uint32_t)((((uint32_t)(vxp_a3) & (uint32_t)((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? 64UL : 128UL))) & 255UL)) != (uint32_t)(0UL)) ? ((uint32_t)((((uint32_t)(((((uint32_t)((((uint32_t)(vxp_a3) & (uint32_t)((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? 32UL : 16UL))) & 255UL)) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(0UL)) : 0UL) ? (((uint32_t)(vxp_a0) - (uint32_t)(1UL)) & 255UL) : vxp_a0)) + (uint32_t)(1UL)) & 65535UL)) < (uint32_t)(vxp_a1)) : 0UL) ? (((uint32_t)(((((uint32_t)((((uint32_t)(vxp_a3) & (uint32_t)((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? 32UL : 16UL))) & 255UL)) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(0UL)) : 0UL) ? (((uint32_t)(vxp_a0) - (uint32_t)(1UL)) & 255UL) : vxp_a0)) + (uint32_t)(1UL)) & 255UL) : ((((uint32_t)((((uint32_t)(vxp_a3) & (uint32_t)((((uint32_t)(vxp_a2) != (uint32_t)(0UL)) ? 32UL : 16UL))) & 255UL)) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a0) != (uint32_t)(0UL)) : 0UL) ? (((uint32_t)(vxp_a0) - (uint32_t)(1UL)) & 255UL) : vxp_a0)));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a3) & (uint32_t)(1UL)) & 255UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_ui_menu_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_ui_cursor(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a0) == (uint32_t)(0UL))) ? 5UL : 35UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(2UL) + (uint32_t)((vx_mul((((uint32_t)(vxp_a1) != (uint32_t)(0UL)) ? vxp_a0 : 3UL), 7UL) & 255UL))) & 255UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_ui_cursor_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_ui_editor(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) + (uint32_t)((((((uint32_t)(vxp_a0) < (uint32_t)(10UL)) ? ((uint32_t)(vxp_a1) > (uint32_t)(32UL)) : 0UL) ? ((uint32_t)(vxp_a1) < (uint32_t)(127UL)) : 0UL) ? 1UL : 0UL))) & 255UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a1) >= (uint32_t)(97UL)) ? ((uint32_t)(vxp_a1) <= (uint32_t)(122UL)) : 0UL) ? (((uint32_t)(vxp_a1) - (uint32_t)(32UL)) & 255UL) : vxp_a1));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((((uint32_t)(vxp_a0) < (uint32_t)(10UL)) ? ((uint32_t)(vxp_a1) > (uint32_t)(32UL)) : 0UL) ? ((uint32_t)(vxp_a1) < (uint32_t)(127UL)) : 0UL) ? 1UL : 0UL));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((((uint32_t)(vxp_a0) >= (uint32_t)(10UL)) ? 1UL : ((uint32_t)(vxp_a1) == (uint32_t)(13UL))) ? 1UL : ((uint32_t)((((uint32_t)(vxp_a0) + (uint32_t)((((((uint32_t)(vxp_a0) < (uint32_t)(10UL)) ? ((uint32_t)(vxp_a1) > (uint32_t)(32UL)) : 0UL) ? ((uint32_t)(vxp_a1) < (uint32_t)(127UL)) : 0UL) ? 1UL : 0UL))) & 255UL)) == (uint32_t)(10UL))) ? 1UL : 0UL));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)(vxp_a2) & (uint32_t)(16UL)) & 255UL)) != (uint32_t)(0UL)) ? 1UL : 0UL));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_ui_editor_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_title_step(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2,VX_STABLE uint8_t vxp_a3) VX_ABI VX_RESIDENT {
    static VX_STABLE uint8_t vx_calc_uint8_t_0;
    if (((uint32_t)(vxp_a3) != (uint32_t)(0UL))) {
    } else {
        if (((uint32_t)(vxp_a0) == (uint32_t)(0UL))) {
        } else {
            if (((uint32_t)(vxp_a0) == (uint32_t)(1UL))) {
            } else {
                if (((uint32_t)(vxp_a0) == (uint32_t)(2UL))) {
                } else {
                    if (((uint32_t)(vxp_a0) == (uint32_t)(3UL))) {
                        if (((uint32_t)(vxp_a2) == (uint32_t)(0UL))) {
                        } else {
                        }
                        if (((uint32_t)(vxp_a2) == (uint32_t)(0UL))) {
                        } else {
                        }
                    } else {
                        if (((uint32_t)(vxp_a0) == (uint32_t)(4UL))) {
                        } else {
                            if (((uint32_t)(vxp_a0) == (uint32_t)(5UL))) {
                            } else {
                            }
                        }
                    }
                }
            }
        }
    }
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a3) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? 10UL : (((uint32_t)(vxp_a2) == (uint32_t)(1UL)) ? 11UL : 1UL)) : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) < (uint32_t)(2UL)) ? 2UL : ((((uint32_t)(vxp_a2) == (uint32_t)(3UL)) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(4UL))) ? 3UL : (((uint32_t)(vxp_a2) == (uint32_t)(6UL)) ? 4UL : (((uint32_t)(vxp_a2) == (uint32_t)(7UL)) ? 5UL : (((uint32_t)(vxp_a2) == (uint32_t)(8UL)) ? 6UL : 1UL))))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 11UL : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? 10UL : (((uint32_t)(vxp_a2) == (uint32_t)(2UL)) ? 9UL : (((uint32_t)(((((((((uint32_t)(vxp_a2) == (uint32_t)(3UL)) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(4UL))) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(6UL))) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(7UL))) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(9UL))) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(10UL))) ? 1UL : 0UL)) != (uint32_t)(0UL)) ? 3UL : (((uint32_t)(vxp_a2) == (uint32_t)(11UL)) ? 7UL : (((uint32_t)(vxp_a2) == (uint32_t)(13UL)) ? 4UL : (((uint32_t)(vxp_a2) == (uint32_t)(14UL)) ? 5UL : (((uint32_t)(vxp_a2) == (uint32_t)(15UL)) ? 8UL : (((uint32_t)(vxp_a2) == (uint32_t)(16UL)) ? (((uint32_t)(vxp_a1) == (uint32_t)(30UL)) ? 12UL : 16UL) : 1UL)))))))) : (((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? 1UL : (((uint32_t)(vxp_a2) == (uint32_t)(1UL)) ? 6UL : (((uint32_t)(vxp_a2) == (uint32_t)(2UL)) ? 12UL : (((uint32_t)(vxp_a2) == (uint32_t)(3UL)) ? 13UL : 10UL)))) : (((uint32_t)(vxp_a0) == (uint32_t)(5UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? 10UL : (((uint32_t)(vxp_a2) < (uint32_t)(46UL)) ? ((vx_calc_uint8_t_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) - ((uint8_t)(1)))))), ((uint32_t)((((uint32_t)((((uint8_t)(((uint8_t)(VX_VALUE_SUB8(((uint8_t)(vx_calc_uint8_t_0)), ((uint8_t)(((uint8_t)(vx_value_scale8_3(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(VX_VALUE_MUL16(((uint16_t)(vx_calc_uint8_t_0)), ((uint16_t)(171))))))) >> 9))))))))))))))))) == ((uint8_t)(0))))) & 255UL)))) ? 1UL : 3UL) : ((((uint32_t)(vxp_a2) >= (uint32_t)(47UL)) ? ((uint32_t)(vxp_a2) <= (uint32_t)(49UL)) : 0UL) ? 14UL : (((uint32_t)(vxp_a2) == (uint32_t)(51UL)) ? 4UL : (((uint32_t)(vxp_a2) == (uint32_t)(52UL)) ? 5UL : (((uint32_t)(vxp_a2) == (uint32_t)(53UL)) ? 12UL : (((uint32_t)(vxp_a2) == (uint32_t)(55UL)) ? 7UL : (((uint32_t)(vxp_a2) == (uint32_t)(57UL)) ? 8UL : (((uint32_t)(vxp_a2) == (uint32_t)(59UL)) ? 9UL : 1UL))))))))) : (((uint32_t)(vxp_a0) == (uint32_t)(6UL)) ? 15UL : 0UL)))))))));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a3) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? 24UL : 0UL) : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? ((((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? 1UL : ((uint32_t)(vxp_a2) == (uint32_t)(4UL))) ? vxp_a1 : (((uint32_t)(vxp_a2) == (uint32_t)(1UL)) ? (((uint32_t)(23UL) - (uint32_t)(vxp_a1)) & 255UL) : (((uint32_t)(31UL) - (uint32_t)(vxp_a1)) & 255UL))) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 1UL : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(24)) + ((uint8_t)(((uint8_t)(vx_value_scale8_24(((uint8_t)(((uint8_t)(((((uint8_t)(vxp_a1)) >> 3) & 31U)))))))))))))) & 255UL)))) : (((uint32_t)(vxp_a2) == (uint32_t)(16UL)) ? 14UL : (((uint32_t)(vxp_a2) < (uint32_t)(5UL)) ? (((uint32_t)(vxp_a2) - (uint32_t)(2UL)) & 255UL) : (((uint32_t)(vxp_a2) < (uint32_t)(8UL)) ? (((uint32_t)(vxp_a2) - (uint32_t)(3UL)) & 255UL) : (((uint32_t)(vxp_a2) - (uint32_t)(4UL)) & 255UL))))) : (((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(2UL)) ? 15UL : 0UL) : (((uint32_t)(vxp_a0) == (uint32_t)(5UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a2) == (uint32_t)(53UL)) ? 1UL : (((uint32_t)(vxp_a2) < (uint32_t)(46UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((0U - ((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(VX_VALUE_MUL16(((uint16_t)(((uint8_t)(((uint8_t)(vxp_a2)) - ((uint8_t)(1)))))), ((uint16_t)(171))))))) >> 9)))))))))))) + ((uint8_t)(vxp_a2)))))) + ((uint8_t)(255)))))) & 255UL)))) : (((uint32_t)(vxp_a2) == (uint32_t)(47UL)) ? 22UL : (((uint32_t)(vxp_a2) == (uint32_t)(48UL)) ? 16UL : 23UL))))) : 9UL))))))));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a3) != (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(((uint8_t)(((uint16_t)(((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) & ((uint8_t)(7)))))))) << 5)))) & 255UL)))) : 0UL) : (((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(4UL)) ? 32UL : 0UL) : (((uint32_t)(vxp_a0) == (uint32_t)(5UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(0UL)) ? (((uint32_t)((((uint32_t)(vxp_a1) & (uint32_t)(1UL)) & 255UL)) != (uint32_t)(0UL)) ? 32UL : 0UL) : 31UL) : 0UL))))))));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a3) != (uint32_t)(0UL)) ? vxp_a0 : (((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(2UL)) ? 1UL : 0UL) : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? ((((uint32_t)(vxp_a2) == (uint32_t)(9UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(11UL)) : 0UL) ? 2UL : 1UL) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 3UL : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? ((((uint32_t)(vxp_a2) == (uint32_t)(16UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(31UL)) : 0UL) ? 4UL : 3UL) : (((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(4UL)) ? 5UL : 4UL) : (((uint32_t)(vxp_a0) == (uint32_t)(5UL)) ? ((((uint32_t)(vxp_a2) == (uint32_t)(75UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(47UL)) : 0UL) ? 6UL : 5UL) : 7UL))))))));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a3) != (uint32_t)(0UL)) ? vxp_a1 : (((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(9UL)) ? (((uint32_t)(vxp_a1) + (uint32_t)(1UL)) & 255UL) : vxp_a1) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(16UL)) ? (((uint32_t)(vxp_a1) == (uint32_t)(31UL)) ? 0UL : (((uint32_t)(vxp_a1) + (uint32_t)(1UL)) & 255UL)) : vxp_a1) : (((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(5UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(75UL)) ? (((uint32_t)(vxp_a1) + (uint32_t)(1UL)) & 255UL) : vxp_a1) : vxp_a1))))))));
    vx_payload[8] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[9] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a3) != (uint32_t)(0UL)) ? vxp_a2 : (((uint32_t)(vxp_a0) == (uint32_t)(0UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vxp_a2) + (uint32_t)(1UL)) & 255UL)) : (((uint32_t)(vxp_a0) == (uint32_t)(1UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(9UL)) ? 0UL : (((uint32_t)(vxp_a2) + (uint32_t)(1UL)) & 255UL)) : (((uint32_t)(vxp_a0) == (uint32_t)(2UL)) ? 0UL : (((uint32_t)(vxp_a0) == (uint32_t)(3UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(16UL)) ? 0UL : (((uint32_t)(vxp_a2) + (uint32_t)(1UL)) & 255UL)) : (((uint32_t)(vxp_a0) == (uint32_t)(4UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(4UL)) ? 0UL : (((uint32_t)(vxp_a2) + (uint32_t)(1UL)) & 255UL)) : (((uint32_t)(vxp_a0) == (uint32_t)(5UL)) ? (((uint32_t)(vxp_a2) == (uint32_t)(75UL)) ? 0UL : (((uint32_t)(vxp_a2) + (uint32_t)(1UL)) & 255UL)) : vxp_a2))))))));
    vx_payload[10] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[11] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_title_step_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    case 4: return (uint32_t)vx_payload[8] + ((uint32_t)vx_payload[9] << 8);
    case 5: return (uint32_t)vx_payload[10] + ((uint32_t)vx_payload[11] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_title_seed(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a2) <= (uint32_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? 224UL : 80UL))) ? 1UL : 0UL));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(vx_shift((((uint32_t)(vxp_a2) + (uint32_t)((((uint32_t)(vxp_a1) == (uint32_t)(0UL)) ? 16UL : 40UL))) & 65535UL), 5UL, 16, 0, 0));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(1UL) + (uint32_t)((((uint32_t)(vxp_a0) & (uint32_t)(1UL)) & 255UL))) & 255UL));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_title_seed_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_title_frame(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1) VX_ABI VX_RESIDENT {
    if (((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(192UL)) ? 0UL : vxp_a0)) & (uint32_t)(15UL)) & 255UL)) == (uint32_t)(0UL))) {
    } else {
    }
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a0) == (uint32_t)(192UL)) ? 0UL : vxp_a0));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)((((uint32_t)((((uint32_t)(vxp_a0) == (uint32_t)(192UL)) ? 0UL : vxp_a0)) & (uint32_t)(15UL)) & 255UL)) == (uint32_t)(0UL)) ? vx_shift((((uint32_t)(vxp_a0) == (uint32_t)(192UL)) ? 0UL : vxp_a0), 4UL, 8, 1, 0) : 255UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(vxp_a1) != (uint32_t)(255UL)) ? 1UL : 0UL));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_title_frame_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_title_attract(VX_STABLE uint8_t vxp_a0,VX_STABLE uint8_t vxp_a1,VX_STABLE uint8_t vxp_a2) VX_ABI VX_RESIDENT {
    static VX_STABLE uint16_t vxo_0;
    vxo_0 = (uint16_t)((((uint32_t)(((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(0UL)) : 0UL) ? 1UL : 0UL)) != (uint32_t)(0UL)) ? (((uint32_t)(vxp_a2) != (uint32_t)(255UL)) ? 0UL : (((uint32_t)(vxp_a0) - (uint32_t)(1UL)) & 255UL)) : vxp_a0));
    vx_payload[0] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[1] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(0UL)) : 0UL) ? 1UL : 0UL));
    vx_payload[2] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[3] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)((((uint32_t)(((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(0UL)) : 0UL) ? 1UL : 0UL)) != (uint32_t)(0UL)) ? 254UL : vxp_a2));
    vx_payload[4] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[5] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
    vxo_0 = (uint16_t)(((((uint32_t)(((((uint32_t)(vxp_a0) != (uint32_t)(0UL)) ? ((uint32_t)(vxp_a1) == (uint32_t)(0UL)) : 0UL) ? 1UL : 0UL)) != (uint32_t)(0UL)) ? ((uint32_t)((((uint32_t)(vxp_a2) != (uint32_t)(255UL)) ? 0UL : (((uint32_t)(vxp_a0) - (uint32_t)(1UL)) & 255UL))) == (uint32_t)(0UL)) : 0UL) ? 1UL : 0UL));
    vx_payload[6] = (uint8_t)(VX_SNAPSHOT16(vxo_0));
    vx_payload[7] = (uint8_t)(((uint32_t)(VX_SNAPSHOT16(vxo_0))) >> 8);
}
uint32_t vx_title_attract_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    case 1: return (uint32_t)vx_payload[2] + ((uint32_t)vx_payload[3] << 8);
    case 2: return (uint32_t)vx_payload[4] + ((uint32_t)vx_payload[5] << 8);
    case 3: return (uint32_t)vx_payload[6] + ((uint32_t)vx_payload[7] << 8);
    default: vx_trap(16); return 0;
    }
}
void vx_world_flow(void) VX_ABI VX_RESIDENT {
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
uint32_t vx_world_flow_read(uint16_t index) VX_ABI VX_RESIDENT {
    switch(index) {
    case 0: return (uint32_t)vx_payload[0] + ((uint32_t)vx_payload[1] << 8);
    default: vx_trap(16); return 0;
    }
}
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
