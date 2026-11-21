/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_world_rocks_H
#define VX_FIXED_world_rocks_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_world_rocks_RESULT
#define VX_VALUE_world_rocks_RESULT
typedef struct {
    uint8_t v0; /* world_rocks */
} vx_world_rocks_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    vx_world_rocks_result result;
} vx_world_rocks_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_world_rocks_fixed_size[sizeof(vx_world_rocks_fixed_frame)==4 ? 1 : -1];
#endif
static void vx_world_rocks_fixed(void) {
    vx_world_rocks_fixed_frame.result.v0 = ((uint8_t)((((((uint8_t)(vx_world_rocks_fixed_frame.a2)) == ((uint8_t)(0))) ? ((uint8_t)(((((uint8_t)(vx_world_rocks_fixed_frame.a0)) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_world_rocks_fixed_frame.a1)) != ((uint8_t)(0)))))))) : ((uint8_t)(0))) ? ((uint8_t)(47)) : ((uint8_t)(0)))));
}
#endif
