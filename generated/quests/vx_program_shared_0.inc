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
