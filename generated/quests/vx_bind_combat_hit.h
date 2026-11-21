/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_combat_hit_H
#define VX_BIND_combat_hit_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_combat_hit_frame (vx_binding_slot_0.binding_combat_hit)
#define VX_BIND_combat_hit_LOCAL /* fixed workspace */
static void vx_bind_combat_hit_run(void) {
    if ((((((uint8_t)(vx_bind_combat_hit_frame.a0)) != ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vx_bind_combat_hit_frame.a1)) == ((uint8_t)(0))))) : ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vx_bind_combat_hit_frame.a2)) != ((uint8_t)(0))))) : ((uint8_t)(0)))) {
        vx_bind_combat_hit_frame.vxv_0 = ((uint8_t)((vx_bind_combat_hit_frame.a4 < 0)));
        if (vx_bind_combat_hit_frame.vxv_0) {
            vx_bind_combat_hit_frame.vxv_1 = ((uint16_t)(((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(0)) - ((uint16_t)(vx_bind_combat_hit_frame.a4)))))))));
        } else {
            vx_bind_combat_hit_frame.vxv_1 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_combat_hit_frame.a4))))));
        }
        vx_bind_combat_hit_frame.vxv_2 = ((uint8_t)((vx_bind_combat_hit_frame.a3 < 0)));
        if (vx_bind_combat_hit_frame.vxv_2) {
            vx_bind_combat_hit_frame.vxv_3 = ((uint16_t)(((uint16_t)(((uint16_t)(VX_VALUE_I16(((uint16_t)(0)) - ((uint16_t)(vx_bind_combat_hit_frame.a3)))))))));
        } else {
            vx_bind_combat_hit_frame.vxv_3 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_combat_hit_frame.a3))))));
        }
        vx_bind_combat_hit_frame.vxv_4 = ((uint8_t)((((uint8_t)(vx_bind_combat_hit_frame.a5)) == ((uint8_t)(1)))));
        vx_bind_combat_hit_frame.result.v0 = ((uint8_t)(1));
        vx_bind_combat_hit_frame.result.v1 = ((uint8_t)(((((uint8_t)(vx_bind_combat_hit_frame.a0)) > ((uint8_t)(vx_bind_combat_hit_frame.a2))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_combat_hit_frame.a0)) - ((uint8_t)(vx_bind_combat_hit_frame.a2)))))) : ((uint8_t)(0)))));
        vx_bind_combat_hit_frame.result.v2 = ((uint8_t)(60));
        vx_bind_combat_hit_frame.result.v3 = ((uint8_t)(6));
        if (((((uint16_t)(vx_bind_combat_hit_frame.vxv_1)) > ((uint16_t)(vx_bind_combat_hit_frame.vxv_3))) || ((VX_VALUE_EQ16(vx_bind_combat_hit_frame.vxv_1, vx_bind_combat_hit_frame.vxv_3)) && (vx_bind_combat_hit_frame.vxv_4 ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_bind_combat_hit_frame.a5)) == ((uint8_t)(2))))))))) {
            vx_bind_combat_hit_frame.result.v4 = VX_VALUE_I8(0);
            vx_bind_combat_hit_frame.result.v5 = VX_VALUE_I8(((vx_bind_combat_hit_frame.vxv_0 || ((vx_bind_combat_hit_frame.a4 == 0) && vx_bind_combat_hit_frame.vxv_4)) ? VX_VALUE_I8(-32) : VX_VALUE_I8(32)));
        } else {
            vx_bind_combat_hit_frame.result.v4 = VX_VALUE_I8(((vx_bind_combat_hit_frame.vxv_2 || ((vx_bind_combat_hit_frame.a3 == 0) && (((uint8_t)(vx_bind_combat_hit_frame.a5)) == ((uint8_t)(3))))) ? VX_VALUE_I8(-32) : VX_VALUE_I8(32)));
            vx_bind_combat_hit_frame.result.v5 = VX_VALUE_I8(0);
        }
    } else {
        vx_bind_combat_hit_frame.result.v0 = ((uint8_t)(0));
        vx_bind_combat_hit_frame.result.v1 = ((uint8_t)(vx_bind_combat_hit_frame.a0));
        vx_bind_combat_hit_frame.result.v2 = ((uint8_t)(vx_bind_combat_hit_frame.a1));
        vx_bind_combat_hit_frame.result.v3 = ((uint8_t)(0));
        vx_bind_combat_hit_frame.result.v4 = VX_VALUE_I8(0);
        vx_bind_combat_hit_frame.result.v5 = VX_VALUE_I8(0);
    }
}
#endif
