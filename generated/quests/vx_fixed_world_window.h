/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_world_window_H
#define VX_FIXED_world_window_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_world_window_RESULT
#define VX_VALUE_world_window_RESULT
typedef struct {
    uint8_t v0; /* world_window */
} vx_world_window_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    VX_STABLE uint8_t a4;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    VX_STABLE uint8_t vxv_2;
    vx_world_window_result result;
} vx_world_window_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_world_window_fixed_size[sizeof(vx_world_window_fixed_frame)==9 ? 1 : -1];
#endif
static void vx_world_window_fixed(void) {
    vx_world_window_fixed_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_world_window_fixed_frame.a1)) - ((uint8_t)(vx_world_window_fixed_frame.a3))))));
    vx_world_window_fixed_frame.vxv_1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_world_window_fixed_frame.a2)) - ((uint8_t)(vx_world_window_fixed_frame.a4))))));
    vx_world_window_fixed_frame.vxv_2 = ((uint8_t)((((((uint8_t)(((uint8_t)(((uint8_t)(vx_world_window_fixed_frame.vxv_0)) + ((uint8_t)(3)))))) < ((uint8_t)(30))) ? ((uint8_t)((((uint8_t)(((uint8_t)(((uint8_t)(vx_world_window_fixed_frame.vxv_1)) + ((uint8_t)(3)))))) < ((uint8_t)(38))))) : ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
    vx_world_window_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_world_window_fixed_frame.a0)) == ((uint8_t)(0))) ? ((uint8_t)(vx_world_window_fixed_frame.vxv_2)) : ((uint8_t)((((((uint8_t)(vx_world_window_fixed_frame.vxv_2)) != ((uint8_t)(0))) ? ((uint8_t)(((((uint8_t)(vx_world_window_fixed_frame.vxv_0)) >= ((uint8_t)(24))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_world_window_fixed_frame.vxv_1)) >= ((uint8_t)(32)))))))) : ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0))))))));
}
#endif
