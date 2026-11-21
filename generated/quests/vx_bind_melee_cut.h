/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_melee_cut_H
#define VX_BIND_melee_cut_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_melee_cut_frame (vx_binding_slot_0.binding_melee_cut)
#define VX_BIND_melee_cut_LOCAL /* fixed workspace */
static void vx_bind_melee_cut_run(void) {
    vx_bind_melee_cut_frame.result.v0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_melee_cut_frame.a0)) - ((uint8_t)(1)))))) < ((uint8_t)(2))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
#endif
