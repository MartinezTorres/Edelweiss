/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_world_seed_H
#define VX_BIND_world_seed_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_world_seed_frame (vx_binding_slot_0.binding_world_seed)
#define VX_BIND_world_seed_LOCAL /* fixed workspace */
static void vx_bind_world_seed_run(void) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        1,2,3,3,4,4,5,5,5,5,6,6,7,7,7,7,
        8
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_1[] = {
        0,0,0,1,0,1,0,1,2,3,0,1,0,1,2,3
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_2[] = {
        120,0,0,0,0,0,104,106,103,108,86,88,120,124,122,120,
        118
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_3[] = {
        126,0,0,0,0,0,24,40,56,20,22,26,8,30,46,64,
        88
    };
    vx_bind_world_seed_frame.result.v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_bind_world_seed_frame.a0)) < 17 ? vx_lut_0[((uint8_t)(vx_bind_world_seed_frame.a0))] : 0)))));
    vx_bind_world_seed_frame.result.v1 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_bind_world_seed_frame.a0)) < 16 ? vx_lut_1[((uint8_t)(vx_bind_world_seed_frame.a0))] : 0)))));
    vx_bind_world_seed_frame.result.v2 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_bind_world_seed_frame.a0)) < 17 ? vx_lut_2[((uint8_t)(vx_bind_world_seed_frame.a0))] : 0)))));
    vx_bind_world_seed_frame.result.v3 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_bind_world_seed_frame.a0)) < 17 ? vx_lut_3[((uint8_t)(vx_bind_world_seed_frame.a0))] : 0)))));
}
#endif
