/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_drop_spawn_H
#define VX_FIXED_drop_spawn_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_drop_spawn_RESULT
#define VX_VALUE_drop_spawn_RESULT
typedef struct {
    uint8_t v0; /* drop_spawn.enabled */
    uint8_t v1; /* drop_spawn.frame */
} vx_drop_spawn_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    vx_drop_spawn_result result;
} vx_drop_spawn_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_drop_spawn_fixed_size[sizeof(vx_drop_spawn_fixed_frame)==3 ? 1 : -1];
#endif
static void vx_drop_spawn_fixed(void) {
    vx_drop_spawn_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_drop_spawn_fixed_frame.a0)) == ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1)))));
    vx_drop_spawn_fixed_frame.result.v1 = ((uint8_t)(((((uint8_t)(vx_drop_spawn_fixed_frame.a0)) < ((uint8_t)(5))) ? ((uint8_t)(((uint8_t)(((uint8_t)(255)) + ((uint8_t)(vx_drop_spawn_fixed_frame.a0)))))) : ((uint8_t)(255)))));
}
#endif
