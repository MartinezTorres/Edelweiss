/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_combat_death_H
#define VX_BIND_combat_death_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_combat_death_frame (vx_binding_slot_0.binding_combat_death)
#define VX_BIND_combat_death_LOCAL /* fixed workspace */
static void vx_bind_combat_death_run(void) {
    vx_bind_combat_death_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_bind_combat_death_frame.a0)) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(((((uint8_t)(vx_bind_combat_death_frame.a1)) != ((uint8_t)(0))) ? ((uint8_t)(2)) : ((uint8_t)(0))))))));
    vx_bind_combat_death_frame.result.v1 = ((uint8_t)(((((uint8_t)(vx_bind_combat_death_frame.a2)) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(((((uint8_t)(vx_bind_combat_death_frame.a3)) != ((uint8_t)(0))) ? ((uint8_t)(2)) : ((uint8_t)(0))))))));
}
#endif
