/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_combat_idle_H
#define VX_BIND_combat_idle_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_combat_idle_frame (vx_binding_slot_0.binding_combat_idle)
#define VX_BIND_combat_idle_LOCAL /* fixed workspace */
static void vx_bind_combat_idle_run(void) {
    vx_bind_combat_idle_frame.result.v0 = ((uint8_t)(1));
    vx_bind_combat_idle_frame.result.v1 = ((uint8_t)(0));
    vx_bind_combat_idle_frame.result.v2 = ((uint8_t)(0));
    vx_bind_combat_idle_frame.result.v3 = ((uint8_t)(0));
    vx_bind_combat_idle_frame.result.v4 = ((uint8_t)(2));
}
#endif
