/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_drop_collect_H
#define VX_BIND_drop_collect_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_support_value_lt8.h"
#include "vx_binding_storage.h"
#define vx_bind_drop_collect_frame (vx_binding_slot_0.binding_drop_collect)
#define VX_BIND_drop_collect_LOCAL /* fixed workspace */
static void vx_bind_drop_collect_run(void) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        0,0,1,5,20
    };
    vx_bind_drop_collect_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_drop_collect_frame.a1)) + ((uint8_t)(2))))));
    vx_bind_drop_collect_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_bind_drop_collect_frame.a0)) == ((uint8_t)(1))) ? ((uint8_t)((VX_VALUE_LT8(((uint8_t)(vx_bind_drop_collect_frame.a2)), ((uint8_t)(vx_bind_drop_collect_frame.vxv_0))) ? ((uint8_t)(vx_bind_drop_collect_frame.a2)) : ((uint8_t)(vx_bind_drop_collect_frame.vxv_0))))) : ((uint8_t)(vx_bind_drop_collect_frame.a1)))));
    vx_bind_drop_collect_frame.result.v1 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_bind_drop_collect_frame.a0)) < 5 ? vx_lut_0[((uint8_t)(vx_bind_drop_collect_frame.a0))] : 0)))));
}
#endif
