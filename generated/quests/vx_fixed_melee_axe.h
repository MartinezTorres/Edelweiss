/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_melee_axe_H
#define VX_FIXED_melee_axe_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_melee_axe_RESULT
#define VX_VALUE_melee_axe_RESULT
typedef struct {
    uint16_t v0; /* melee_axe.i */
    uint16_t v1; /* melee_axe.j */
} vx_melee_axe_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint16_t a2;
    vx_melee_axe_result result;
} vx_melee_axe_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_melee_axe_fixed_size[sizeof(vx_melee_axe_fixed_frame)==9 ? 1 : -1];
#endif
static void vx_melee_axe_fixed(void) {
    if ((((uint8_t)(vx_melee_axe_fixed_frame.a0)) == ((uint8_t)(3)))) {
        vx_melee_axe_fixed_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_melee_axe_fixed_frame.a1)) + ((uint16_t)(256)))))) + ((uint16_t)(((uint16_t)(65152))))))));
    } else {
        if ((((uint8_t)(((uint8_t)(((uint8_t)(vx_melee_axe_fixed_frame.a0)) - ((uint8_t)(1)))))) < ((uint8_t)(2)))) {
            vx_melee_axe_fixed_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_melee_axe_fixed_frame.a1)) + ((uint16_t)(256))))))));
        } else {
            vx_melee_axe_fixed_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_melee_axe_fixed_frame.a1)) + ((uint16_t)(256)))))) + ((uint16_t)(((uint16_t)(384))))))));
        }
    }
    if ((((uint8_t)(vx_melee_axe_fixed_frame.a0)) == ((uint8_t)(1)))) {
        vx_melee_axe_fixed_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_melee_axe_fixed_frame.a2)) + ((uint16_t)(256)))))) + ((uint16_t)(((uint16_t)(65152))))))));
    } else {
        if ((((uint8_t)(vx_melee_axe_fixed_frame.a0)) == ((uint8_t)(2)))) {
            vx_melee_axe_fixed_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_melee_axe_fixed_frame.a2)) + ((uint16_t)(256)))))) + ((uint16_t)(((uint16_t)(384))))))));
        } else {
            vx_melee_axe_fixed_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_melee_axe_fixed_frame.a2)) + ((uint16_t)(256))))))));
        }
    }
}
#endif
