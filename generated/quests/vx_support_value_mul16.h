/* Private register ABI; the low product bits need no 32-bit runtime call. */
#ifndef VX_VALUE_MUL16_H
#define VX_VALUE_MUL16_H
#include "vx_support_value_base.h"
#ifdef __SDCC_z80
static uint16_t vx_value_mul16(uint16_t a, uint16_t b) __sdcccall(1) VX_VALUE_LOCATION {
    uint16_t result=0;
    while(b) {
        if(b&1) result=(uint16_t)(result+a);
        b>>=1; a=(uint16_t)(a<<1);
    }
    return result;
}
#define VX_VALUE_MUL16(a,b) vx_value_mul16((uint16_t)(a),(uint16_t)(b))
#else
#define VX_VALUE_MUL16(a,b) ((uint16_t)((uint32_t)(a)*(uint32_t)(b)))
#endif
#endif
