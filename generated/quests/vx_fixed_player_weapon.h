/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_player_weapon_H
#define VX_FIXED_player_weapon_H
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
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    vx_player_weapon_result result;
} vx_player_weapon_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_player_weapon_fixed_size[sizeof(vx_player_weapon_fixed_frame)==5 ? 1 : -1];
#endif
static void vx_player_weapon_fixed(void) {
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
    vx_player_weapon_fixed_frame.vxv_0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_player_weapon_fixed_frame.a0)) & ((uint8_t)(4)))))) != ((uint8_t)(0))) ? ((uint8_t)(vx_value_ror8_4(((uint8_t)(vx_player_weapon_fixed_frame.a1))))) : ((uint8_t)(vx_player_weapon_fixed_frame.a1)))));
    vx_player_weapon_fixed_frame.vxv_1 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_player_weapon_fixed_frame.a0)) & ((uint8_t)(2)))))) != ((uint8_t)(0))) ? ((uint8_t)(vx_value_ror8_2(((uint8_t)(vx_player_weapon_fixed_frame.vxv_0))))) : ((uint8_t)(vx_player_weapon_fixed_frame.vxv_0)))));
    vx_player_weapon_fixed_frame.result.v0 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vx_player_weapon_fixed_frame.a0)) + ((uint8_t)(((uint8_t)(vx_lut_0[((uint8_t)(((uint8_t)(((((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_player_weapon_fixed_frame.a0)) & ((uint8_t)(1)))))) != ((uint8_t)(0))) ? ((uint8_t)(vx_value_ror8_1(((uint8_t)(vx_player_weapon_fixed_frame.vxv_1))))) : ((uint8_t)(vx_player_weapon_fixed_frame.vxv_1))))) >> 1) & 127U)))))])))))))) & ((uint8_t)(7))))));
}
#endif
