/* Read two stable byte lvalues before widening their sum. */
#ifndef VX_VALUE_ADD8WIDE_H
#define VX_VALUE_ADD8WIDE_H
#include "vx_support_value_base.h"
#ifdef __SDCC_z80
static uint16_t vx_value_add8wide(const volatile uint8_t *a, const volatile uint8_t *b) VX_VALUE_LOCATION {
    return (uint16_t)*a+(uint16_t)*b;
}
#define VX_VALUE_ADD8WIDE(a,b) vx_value_add8wide(&(a),&(b))
#else
#define VX_VALUE_ADD8WIDE(a,b) ((uint16_t)((uint16_t)(uint8_t)(a)+(uint16_t)(uint8_t)(b)))
#endif
#endif
