/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_player_attack_H
#define VX_FIXED_player_attack_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_player_attack_RESULT
#define VX_VALUE_player_attack_RESULT
typedef struct {
    uint8_t v0; /* player_attack */
} vx_player_attack_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    vx_player_attack_result result;
} vx_player_attack_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_player_attack_fixed_size[sizeof(vx_player_attack_fixed_frame)==3 ? 1 : -1];
#endif
static void vx_player_attack_fixed(void) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        0,2,3,2
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_1[] = {
        0,4,5,4
    };
    vx_player_attack_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_player_attack_fixed_frame.a0)) > ((uint8_t)(7))) ? ((uint8_t)(0)) : ((uint8_t)(((((uint8_t)(vx_player_attack_fixed_frame.a0)) == ((uint8_t)(4))) ? ((uint8_t)(((uint8_t)(vx_lut_0[((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vx_player_attack_fixed_frame.a1)) >> 1))))) & ((uint8_t)(3))))))])))) : ((uint8_t)((((((uint8_t)(vx_player_attack_fixed_frame.a0)) == ((uint8_t)(5))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_player_attack_fixed_frame.a0)) == ((uint8_t)(6)))))) ? ((uint8_t)(((uint8_t)(vx_lut_1[((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vx_player_attack_fixed_frame.a1)) >> 3))))) & ((uint8_t)(3))))))])))) : ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_player_attack_fixed_frame.a1)) & ((uint8_t)(1)))))) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0))))))))))))));
}
#endif
