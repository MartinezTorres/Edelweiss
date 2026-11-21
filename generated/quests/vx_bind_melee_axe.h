/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_melee_axe_H
#define VX_BIND_melee_axe_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_melee_axe_frame (vx_binding_slot_0.binding_melee_axe)
#define VX_BIND_melee_axe_LOCAL /* fixed workspace */
static void vx_bind_melee_axe_run(void) {
    if ((((uint8_t)(vx_bind_melee_axe_frame.a0)) == ((uint8_t)(3)))) {
        vx_bind_melee_axe_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_melee_axe_frame.a1)) + ((uint16_t)(256)))))) + ((uint16_t)(((uint16_t)(65152))))))));
    } else {
        if ((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_melee_axe_frame.a0)) - ((uint8_t)(1)))))) < ((uint8_t)(2)))) {
            vx_bind_melee_axe_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_melee_axe_frame.a1)) + ((uint16_t)(256))))))));
        } else {
            vx_bind_melee_axe_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_melee_axe_frame.a1)) + ((uint16_t)(256)))))) + ((uint16_t)(((uint16_t)(384))))))));
        }
    }
    if ((((uint8_t)(vx_bind_melee_axe_frame.a0)) == ((uint8_t)(1)))) {
        vx_bind_melee_axe_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_melee_axe_frame.a2)) + ((uint16_t)(256)))))) + ((uint16_t)(((uint16_t)(65152))))))));
    } else {
        if ((((uint8_t)(vx_bind_melee_axe_frame.a0)) == ((uint8_t)(2)))) {
            vx_bind_melee_axe_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_melee_axe_frame.a2)) + ((uint16_t)(256)))))) + ((uint16_t)(((uint16_t)(384))))))));
        } else {
            vx_bind_melee_axe_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_melee_axe_frame.a2)) + ((uint16_t)(256))))))));
        }
    }
}
#endif
