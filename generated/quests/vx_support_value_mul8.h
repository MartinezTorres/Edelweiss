/* Private register ABI; the low product bits need no 32-bit runtime call. */
#ifndef VX_VALUE_MUL8_H
#define VX_VALUE_MUL8_H
#include "vx_support_value_base.h"
#ifdef __SDCC_z80
static uint8_t vx_value_mul8(uint8_t a, uint8_t b) __sdcccall(1) VX_VALUE_LOCATION {
    uint8_t result=0;
    while(b) {
        if(b&1) result=(uint8_t)(result+a);
        b>>=1; a=(uint8_t)(a<<1);
    }
    return result;
}
#define VX_VALUE_MUL8(a,b) vx_value_mul8((uint8_t)(a),(uint8_t)(b))
#else
#define VX_VALUE_MUL8(a,b) ((uint8_t)((uint32_t)(a)*(uint32_t)(b)))
#endif
#endif
