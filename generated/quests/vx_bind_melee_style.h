/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_melee_style_H
#define VX_BIND_melee_style_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_melee_style_frame (vx_binding_slot_0.binding_melee_style)
#define VX_BIND_melee_style_LOCAL /* fixed workspace */
static void vx_bind_melee_style_run(void) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        1,4,8,2
    };
    vx_bind_melee_style_frame.result.v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_bind_melee_style_frame.a0)) < 4 ? vx_lut_0[((uint8_t)(vx_bind_melee_style_frame.a0))] : 16)))));
    vx_bind_melee_style_frame.result.v1 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_melee_style_frame.a0)) & ((uint8_t)(254)))))) == ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))));
    vx_bind_melee_style_frame.result.v4 = ((uint8_t)(((((uint8_t)(vx_bind_melee_style_frame.a0)) == ((uint8_t)(3))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
    if ((((uint8_t)(vx_bind_melee_style_frame.a0)) == ((uint8_t)(2)))) {
        vx_bind_melee_style_frame.result.v2 = ((uint8_t)(14));
        vx_bind_melee_style_frame.result.v3 = ((uint8_t)(5));
    } else {
        if ((((uint8_t)(vx_bind_melee_style_frame.a0)) == ((uint8_t)(3)))) {
            vx_bind_melee_style_frame.result.v2 = ((uint8_t)(6));
            vx_bind_melee_style_frame.result.v3 = ((uint8_t)(4));
        } else {
            vx_bind_melee_style_frame.result.v2 = ((uint8_t)(15));
            vx_bind_melee_style_frame.result.v3 = ((uint8_t)(11));
        }
    }
}
#endif
