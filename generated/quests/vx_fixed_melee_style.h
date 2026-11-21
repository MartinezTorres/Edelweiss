/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_melee_style_H
#define VX_FIXED_melee_style_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_melee_style_RESULT
#define VX_VALUE_melee_style_RESULT
typedef struct {
    uint8_t v0; /* melee_style.damage */
    uint8_t v1; /* melee_style.override */
    uint8_t v2; /* melee_style.color0 */
    uint8_t v3; /* melee_style.color1 */
    uint8_t v4; /* melee_style.axe */
} vx_melee_style_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    vx_melee_style_result result;
} vx_melee_style_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_melee_style_fixed_size[sizeof(vx_melee_style_fixed_frame)==6 ? 1 : -1];
#endif
static void vx_melee_style_fixed(void) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        1,4,8,2
    };
    vx_melee_style_fixed_frame.result.v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_melee_style_fixed_frame.a0)) < 4 ? vx_lut_0[((uint8_t)(vx_melee_style_fixed_frame.a0))] : 16)))));
    vx_melee_style_fixed_frame.result.v1 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_melee_style_fixed_frame.a0)) & ((uint8_t)(254)))))) == ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))));
    vx_melee_style_fixed_frame.result.v4 = ((uint8_t)(((((uint8_t)(vx_melee_style_fixed_frame.a0)) == ((uint8_t)(3))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
    if ((((uint8_t)(vx_melee_style_fixed_frame.a0)) == ((uint8_t)(2)))) {
        vx_melee_style_fixed_frame.result.v2 = ((uint8_t)(14));
        vx_melee_style_fixed_frame.result.v3 = ((uint8_t)(5));
    } else {
        if ((((uint8_t)(vx_melee_style_fixed_frame.a0)) == ((uint8_t)(3)))) {
            vx_melee_style_fixed_frame.result.v2 = ((uint8_t)(6));
            vx_melee_style_fixed_frame.result.v3 = ((uint8_t)(4));
        } else {
            vx_melee_style_fixed_frame.result.v2 = ((uint8_t)(15));
            vx_melee_style_fixed_frame.result.v3 = ((uint8_t)(11));
        }
    }
}
#endif
