/* Keep operand publication separate from arithmetic. These private leaf
 * helpers use register arguments; their immutable parameters need no spill. */
#ifndef VX_VALUE_LT8_H
#define VX_VALUE_LT8_H
#include "vx_support_value_base.h"
#ifdef __SDCC_z80
static uint8_t vx_value_lt8(uint8_t a, uint8_t b) __sdcccall(1) VX_VALUE_LOCATION {
    return (uint8_t)(a<b);
}
#define VX_VALUE_LT8(a,b) vx_value_lt8((uint8_t)(a),(uint8_t)(b))
#else
#define VX_VALUE_LT8(a,b) ((uint8_t)((uint8_t)(a)<(uint8_t)(b)))
#endif
#endif
