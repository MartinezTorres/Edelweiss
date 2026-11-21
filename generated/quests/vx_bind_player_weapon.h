/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_player_weapon_H
#define VX_BIND_player_weapon_H
#include "vx_binding_types.h"
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
#include "vx_binding_storage.h"
#define vx_bind_player_weapon_frame (vx_binding_slot_0.binding_player_weapon)
#define VX_BIND_player_weapon_LOCAL /* fixed workspace */
static void vx_bind_player_weapon_run(void) {
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
    vx_bind_player_weapon_frame.vxv_0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_player_weapon_frame.a0)) & ((uint8_t)(4)))))) != ((uint8_t)(0))) ? ((uint8_t)(vx_value_ror8_4(((uint8_t)(vx_bind_player_weapon_frame.a1))))) : ((uint8_t)(vx_bind_player_weapon_frame.a1)))));
    vx_bind_player_weapon_frame.vxv_1 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_player_weapon_frame.a0)) & ((uint8_t)(2)))))) != ((uint8_t)(0))) ? ((uint8_t)(vx_value_ror8_2(((uint8_t)(vx_bind_player_weapon_frame.vxv_0))))) : ((uint8_t)(vx_bind_player_weapon_frame.vxv_0)))));
    vx_bind_player_weapon_frame.result.v0 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_player_weapon_frame.a0)) + ((uint8_t)(((uint8_t)(vx_lut_0[((uint8_t)(((uint8_t)(((((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_player_weapon_frame.a0)) & ((uint8_t)(1)))))) != ((uint8_t)(0))) ? ((uint8_t)(vx_value_ror8_1(((uint8_t)(vx_bind_player_weapon_frame.vxv_1))))) : ((uint8_t)(vx_bind_player_weapon_frame.vxv_1))))) >> 1) & 127U)))))])))))))) & ((uint8_t)(7))))));
}
#endif
