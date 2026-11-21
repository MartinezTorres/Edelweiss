/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_skeleti_tick_H
#define VX_FIXED_skeleti_tick_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_skeleti_tick_RESULT
#define VX_VALUE_skeleti_tick_RESULT
typedef struct {
    uint8_t v0; /* skeleti_tick */
} vx_skeleti_tick_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    vx_skeleti_tick_result result;
} vx_skeleti_tick_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_skeleti_tick_fixed_size[sizeof(vx_skeleti_tick_fixed_frame)==3 ? 1 : -1];
#endif
static void vx_skeleti_tick_fixed(void) {
    vx_skeleti_tick_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vx_skeleti_tick_fixed_frame.a0)) + ((uint8_t)(vx_skeleti_tick_fixed_frame.a1)))))) & ((uint8_t)(3)))))) == ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
#endif
