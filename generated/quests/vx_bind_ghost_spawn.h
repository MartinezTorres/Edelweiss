/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_ghost_spawn_H
#define VX_BIND_ghost_spawn_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_ghost_spawn_frame (vx_binding_slot_0.binding_ghost_spawn)
#define VX_BIND_ghost_spawn_LOCAL /* fixed workspace */
static void vx_bind_ghost_spawn_run(void) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        1,255,1,255,2,254,2,254
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_1[] = {
        2,254,2,254,4,252,4,252
    };
    vx_bind_ghost_spawn_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_ghost_spawn_frame.a0)) - ((uint16_t)(256))))));
    vx_bind_ghost_spawn_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_ghost_spawn_frame.a1)) - ((uint16_t)(512))))));
    vx_bind_ghost_spawn_frame.result.v2 = VX_VALUE_I8(VX_VALUE_I8(vx_lut_0[((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_ghost_spawn_frame.a2)) & ((uint8_t)(7))))))]));
    vx_bind_ghost_spawn_frame.result.v3 = VX_VALUE_I8(VX_VALUE_I8(vx_lut_1[((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vx_bind_ghost_spawn_frame.a2)) >> 1))))) & ((uint8_t)(7))))))]));
}
#endif
