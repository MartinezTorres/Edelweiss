/* The Z80 realization uses SDCC's two's-complement casts and arithmetic
 * signed shifts. Host formulas express the same values without signed overflow
 * or negative shifts. Arithmetic macro operands are evaluated once. Internal
 * copy macros require stable, non-overlapping lvalues of the same width. */
#ifndef VX_SUPPORT_VALUE_BASE_H
#define VX_SUPPORT_VALUE_BASE_H
#include <stdint.h>
#ifndef VX_VALUE_LOCATION
#define VX_VALUE_LOCATION
#endif
#if defined(__SDCC_z80)
#define VX_VALUE_I8(x) ((int8_t)(uint8_t)(x))
#define VX_VALUE_I16(x) ((int16_t)(uint16_t)(x))
#define VX_VALUE_I32(x) ((int32_t)(uint32_t)(x))
#define VX_VALUE_ASR8(x,n) ((int8_t)(x) >> (n))
#define VX_VALUE_ASR16(x,n) ((int16_t)(x) >> (n))
#define VX_VALUE_ASR32(x,n) ((int32_t)(x) >> (n))
/* Stable byte transfers avoid wide register spills. The caller owns all
 * fields for this computation; these are not atomic or external IO copies. */
#define VX_VALUE_COPY16(d,s) do { \
    ((volatile uint8_t *)&(d))[0]=((const volatile uint8_t *)&(s))[0]; \
    ((volatile uint8_t *)&(d))[1]=((const volatile uint8_t *)&(s))[1]; \
} while(0)
#define VX_VALUE_COPY32(d,s) do { \
    ((volatile uint8_t *)&(d))[0]=((const volatile uint8_t *)&(s))[0]; \
    ((volatile uint8_t *)&(d))[1]=((const volatile uint8_t *)&(s))[1]; \
    ((volatile uint8_t *)&(d))[2]=((const volatile uint8_t *)&(s))[2]; \
    ((volatile uint8_t *)&(d))[3]=((const volatile uint8_t *)&(s))[3]; \
} while(0)
/* Equality needs no word-sized intermediate. Only stable same-type lvalues
 * reach these macros; short-circuit reads cannot observe external effects. */
#define VX_VALUE_EQ16(a,b) ( \
    ((const volatile uint8_t *)&(a))[0]==((const volatile uint8_t *)&(b))[0] && \
    ((const volatile uint8_t *)&(a))[1]==((const volatile uint8_t *)&(b))[1])
#define VX_VALUE_EQ32(a,b) (VX_VALUE_EQ16(a,b) && \
    ((const volatile uint8_t *)&(a))[2]==((const volatile uint8_t *)&(b))[2] && \
    ((const volatile uint8_t *)&(a))[3]==((const volatile uint8_t *)&(b))[3])
/* The freestanding project supplies vx_mul, not SDCC's implicit lib helpers. */
#define VX_VALUE_MUL(a,b) vx_mul((uint32_t)(a),(uint32_t)(b))
#else
#define VX_VALUE_I8(x) ((int8_t)((int16_t)((uint8_t)(x) ^ 128u) - 128))
#define VX_VALUE_I16(x) ((int16_t)((int32_t)((uint16_t)(x) ^ 32768u) - 32768L))
#define VX_VALUE_I32(x) ((int32_t)((int64_t)((uint32_t)(x) ^ 2147483648UL) - 2147483648LL))
#define VX_VALUE_ASR8(x,n) ((int8_t)(((int16_t)((uint8_t)(x) ^ 128u) >> (n)) - (int16_t)(128u >> (n))))
#define VX_VALUE_ASR16(x,n) ((int16_t)(((int32_t)((uint16_t)(x) ^ 32768u) >> (n)) - (int32_t)(32768u >> (n))))
#define VX_VALUE_ASR32(x,n) ((int32_t)(((int64_t)((uint32_t)(x) ^ 2147483648UL) >> (n)) - (int64_t)(2147483648UL >> (n))))
#define VX_VALUE_MUL(a,b) ((uint32_t)(a)*(uint32_t)(b))
#define VX_VALUE_COPY16(d,s) ((d)=(s))
#define VX_VALUE_COPY32(d,s) ((d)=(s))
#define VX_VALUE_EQ16(a,b) ((a)==(b))
#define VX_VALUE_EQ32(a,b) ((a)==(b))
#endif
#endif
