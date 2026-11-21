/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_melee_hit_H
#define VX_BIND_melee_hit_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_support_value_add16.h"
#include "vx_binding_storage.h"
#define vx_bind_melee_hit_frame (vx_binding_slot_0.binding_melee_hit)
#define VX_BIND_melee_hit_LOCAL /* fixed workspace */
static void vx_bind_melee_hit_run(void) {
    vx_bind_melee_hit_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_bind_melee_hit_frame.a1)) == ((uint8_t)(3)))));
    vx_bind_melee_hit_frame.vxv_1 = ((uint8_t)((((uint8_t)(vx_bind_melee_hit_frame.a1)) == ((uint8_t)(4)))));
    vx_bind_melee_hit_frame.vxv_2 = ((uint8_t)((vx_bind_melee_hit_frame.vxv_0 ? ((uint8_t)(1)) : ((uint8_t)(vx_bind_melee_hit_frame.vxv_1)))));
    vx_bind_melee_hit_frame.vxv_3 = ((uint8_t)(((((uint8_t)(vx_bind_melee_hit_frame.a0)) == ((uint8_t)(0))) ? ((uint8_t)(160)) : ((uint8_t)(192)))));
    if (vx_bind_melee_hit_frame.vxv_0) {
        vx_bind_melee_hit_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_melee_hit_frame.a2)) - ((uint16_t)(vx_bind_melee_hit_frame.vxv_3))))))));
    } else {
        if (vx_bind_melee_hit_frame.vxv_1) {
            vx_bind_melee_hit_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(VX_VALUE_ADD16(((uint16_t)(vx_bind_melee_hit_frame.a2)), ((uint16_t)(vx_bind_melee_hit_frame.vxv_3)))))))))));
        } else {
            VX_VALUE_COPY16(vx_bind_melee_hit_frame.result.v0, vx_bind_melee_hit_frame.a2);
        }
    }
    if ((((uint8_t)(vx_bind_melee_hit_frame.a1)) == ((uint8_t)(1)))) {
        vx_bind_melee_hit_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_melee_hit_frame.a3)) - ((uint16_t)(vx_bind_melee_hit_frame.vxv_3))))))));
    } else {
        if (vx_bind_melee_hit_frame.vxv_2) {
            VX_VALUE_COPY16(vx_bind_melee_hit_frame.result.v1, vx_bind_melee_hit_frame.a3);
        } else {
            vx_bind_melee_hit_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(VX_VALUE_ADD16(((uint16_t)(vx_bind_melee_hit_frame.a3)), ((uint16_t)(vx_bind_melee_hit_frame.vxv_3)))))))))));
        }
    }
    if (vx_bind_melee_hit_frame.vxv_2) {
        if ((((uint8_t)(vx_bind_melee_hit_frame.a0)) == ((uint8_t)(0)))) {
            vx_bind_melee_hit_frame.result.v2 = ((uint8_t)(10));
            vx_bind_melee_hit_frame.result.v3 = ((uint8_t)(36));
        } else {
            vx_bind_melee_hit_frame.result.v2 = ((uint8_t)(12));
            vx_bind_melee_hit_frame.result.v3 = ((uint8_t)(40));
        }
    } else {
        if ((((uint8_t)(vx_bind_melee_hit_frame.a0)) == ((uint8_t)(0)))) {
            vx_bind_melee_hit_frame.result.v2 = ((uint8_t)(36));
            vx_bind_melee_hit_frame.result.v3 = ((uint8_t)(10));
        } else {
            vx_bind_melee_hit_frame.result.v2 = ((uint8_t)(40));
            vx_bind_melee_hit_frame.result.v3 = ((uint8_t)(12));
        }
    }
}
#endif
