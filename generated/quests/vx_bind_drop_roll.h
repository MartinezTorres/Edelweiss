/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_drop_roll_H
#define VX_BIND_drop_roll_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_drop_roll_frame (vx_binding_slot_0.binding_drop_roll)
#define VX_BIND_drop_roll_LOCAL /* fixed workspace */
static void vx_bind_drop_roll_run(void) {
    if (((((uint8_t)(vx_bind_drop_roll_frame.a0)) < ((uint8_t)(1))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_bind_drop_roll_frame.a0)) > ((uint8_t)(3))))))) {
        vx_bind_drop_roll_frame.result.v0 = ((uint8_t)(vx_bind_drop_roll_frame.a1));
        vx_bind_drop_roll_frame.result.v1 = ((uint8_t)(0));
    } else {
        if ((((uint16_t)(vx_bind_drop_roll_frame.a2)) > ((uint16_t)(255)))) {
            vx_bind_drop_roll_frame.result.v0 = ((uint8_t)(0));
            vx_bind_drop_roll_frame.result.v1 = ((uint8_t)(1));
        } else {
            vx_bind_drop_roll_frame.vxv_0 = ((uint8_t)((((uint16_t)(vx_bind_drop_roll_frame.a2)) < ((uint16_t)(64)))));
            vx_bind_drop_roll_frame.vxv_1 = ((uint8_t)((((uint16_t)(vx_bind_drop_roll_frame.a2)) < ((uint16_t)(128)))));
            vx_bind_drop_roll_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_bind_drop_roll_frame.a0)) == ((uint8_t)(1))) ? ((uint8_t)(((((uint16_t)(vx_bind_drop_roll_frame.a2)) < ((uint16_t)(8))) ? ((uint8_t)(4)) : ((uint8_t)(((((uint16_t)(vx_bind_drop_roll_frame.a2)) < ((uint16_t)(24))) ? ((uint8_t)(3)) : ((uint8_t)(((((uint16_t)(vx_bind_drop_roll_frame.a2)) < ((uint16_t)(56))) ? ((uint8_t)(2)) : ((uint8_t)(((((uint16_t)(vx_bind_drop_roll_frame.a2)) < ((uint16_t)(72))) ? ((uint8_t)(1)) : ((uint8_t)(0)))))))))))))) : ((uint8_t)(((((uint8_t)(vx_bind_drop_roll_frame.a0)) == ((uint8_t)(2))) ? ((uint8_t)(((((uint16_t)(vx_bind_drop_roll_frame.a2)) < ((uint16_t)(32))) ? ((uint8_t)(4)) : ((uint8_t)((vx_bind_drop_roll_frame.vxv_0 ? ((uint8_t)(3)) : ((uint8_t)(((((uint16_t)(vx_bind_drop_roll_frame.a2)) < ((uint16_t)(96))) ? ((uint8_t)(2)) : ((uint8_t)((vx_bind_drop_roll_frame.vxv_1 ? ((uint8_t)(1)) : ((uint8_t)(0)))))))))))))) : ((uint8_t)((vx_bind_drop_roll_frame.vxv_0 ? ((uint8_t)(4)) : ((uint8_t)((vx_bind_drop_roll_frame.vxv_1 ? ((uint8_t)(3)) : ((uint8_t)(((((uint16_t)(vx_bind_drop_roll_frame.a2)) < ((uint16_t)(160))) ? ((uint8_t)(2)) : ((uint8_t)(((((uint16_t)(vx_bind_drop_roll_frame.a2)) < ((uint16_t)(192))) ? ((uint8_t)(1)) : ((uint8_t)(0))))))))))))))))))));
            vx_bind_drop_roll_frame.result.v1 = ((uint8_t)(0));
        }
    }
}
#endif
