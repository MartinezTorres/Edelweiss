/* Keep operand publication separate from arithmetic. These private leaf
 * helpers use register arguments; their immutable parameters need no spill. */
#ifndef VX_VALUE_ADD16_H
#define VX_VALUE_ADD16_H
#include "vx_support_value_base.h"
#ifdef __SDCC_z80
static uint16_t vx_value_add16(uint16_t a, uint16_t b) __sdcccall(1) VX_VALUE_LOCATION {
    return (uint16_t)(a+b);
}
#define VX_VALUE_ADD16(a,b) vx_value_add16((uint16_t)(a),(uint16_t)(b))
#else
#define VX_VALUE_ADD16(a,b) ((uint16_t)((uint16_t)(a)+(uint16_t)(b)))
#endif
#endif
