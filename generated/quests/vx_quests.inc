#include "vexel.h"
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
