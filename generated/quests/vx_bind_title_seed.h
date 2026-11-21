/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_title_seed_H
#define VX_BIND_title_seed_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_title_seed_frame (vx_binding_slot_0.binding_title_seed)
#define VX_BIND_title_seed_LOCAL /* fixed workspace */
static void vx_bind_title_seed_run(void) {
    vx_bind_title_seed_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_bind_title_seed_frame.a1)) == ((uint8_t)(0)))));
    vx_bind_title_seed_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_bind_title_seed_frame.a2)) <= ((uint8_t)((vx_bind_title_seed_frame.vxv_0 ? ((uint8_t)(224)) : ((uint8_t)(80)))))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
    if (vx_bind_title_seed_frame.vxv_0) {
        vx_bind_title_seed_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint32_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_title_seed_frame.a2)) + ((uint16_t)(((uint8_t)(16)))))))))) << 5))));
    } else {
        vx_bind_title_seed_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint32_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_title_seed_frame.a2)) + ((uint16_t)(((uint8_t)(40)))))))))) << 5))));
    }
    vx_bind_title_seed_frame.result.v2 = ((uint8_t)(((uint8_t)(((uint8_t)(1)) + ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_title_seed_frame.a0)) & ((uint8_t)(1))))))))));
}
#endif
