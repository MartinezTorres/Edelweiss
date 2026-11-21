/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_player_weapon_H
#define VX_VALUE_player_weapon_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_SUPPORT_ror8_1
#define VX_SUPPORT_ror8_1
#ifdef __SDCC_z80
static inline uint8_t vx_value_ror8_1(uint8_t x) __sdcccall(1) VX_VALUE_LOCATION
#else
static inline uint8_t vx_value_ror8_1(uint8_t x)
#endif
{
    x=(uint8_t)((x >> 1) | (x << 7));
    return x;
}
#endif
#ifndef VX_SUPPORT_ror8_2
#define VX_SUPPORT_ror8_2
#ifdef __SDCC_z80
static inline uint8_t vx_value_ror8_2(uint8_t x) __sdcccall(1) VX_VALUE_LOCATION
#else
static inline uint8_t vx_value_ror8_2(uint8_t x)
#endif
{
    x=(uint8_t)((x >> 1) | (x << 7));
    x=(uint8_t)((x >> 1) | (x << 7));
    return x;
}
#endif
#ifndef VX_SUPPORT_ror8_4
#define VX_SUPPORT_ror8_4
#ifdef __SDCC_z80
static inline uint8_t vx_value_ror8_4(uint8_t x) __sdcccall(1) VX_VALUE_LOCATION
#else
static inline uint8_t vx_value_ror8_4(uint8_t x)
#endif
{
    x=(uint8_t)((x >> 1) | (x << 7));
    x=(uint8_t)((x >> 1) | (x << 7));
    x=(uint8_t)((x >> 1) | (x << 7));
    x=(uint8_t)((x >> 1) | (x << 7));
    return x;
}
#endif
#ifndef VX_VALUE_player_weapon_RESULT
#define VX_VALUE_player_weapon_RESULT
typedef struct {
    uint8_t v0; /* player_weapon */
} vx_player_weapon_result;
#endif
static inline void vx_player_weapon_value(vx_player_weapon_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        0,1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,
        5,1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,
        6,1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,
        5,1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,
        7,1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,
        5,1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,
        6,1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,
        5,1,2,1,3,1,2,1,4,1,2,1,3,1,2,1
    };
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) & ((uint8_t)(4)))))) != ((uint8_t)(0))) ? ((uint8_t)(vx_value_ror8_4(((uint8_t)(vxp_a1))))) : ((uint8_t)(vxp_a1)))));
    VX_STABLE uint8_t vxv_1;
    vxv_1 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) & ((uint8_t)(2)))))) != ((uint8_t)(0))) ? ((uint8_t)(vx_value_ror8_2(((uint8_t)(vxv_0))))) : ((uint8_t)(vxv_0)))));
    vxo->v0 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) + ((uint8_t)(((uint8_t)(vx_lut_0[((uint8_t)(((uint8_t)(((((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) & ((uint8_t)(1)))))) != ((uint8_t)(0))) ? ((uint8_t)(vx_value_ror8_1(((uint8_t)(vxv_1))))) : ((uint8_t)(vxv_1))))) >> 1) & 127U)))))])))))))) & ((uint8_t)(7))))));
}
#endif
