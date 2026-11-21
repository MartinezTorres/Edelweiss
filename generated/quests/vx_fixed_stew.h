/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_stew_H
#define VX_FIXED_stew_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_stew_RESULT
#define VX_VALUE_stew_RESULT
typedef struct {
    uint8_t v0; /* stew.choices */
    uint16_t v1; /* stew.debit */
    uint8_t v2; /* stew.maximum_life */
    uint8_t v3; /* stew.text */
} vx_stew_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint8_t a2;
    vx_stew_result result;
} vx_stew_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_stew_fixed_size[sizeof(vx_stew_fixed_frame)==9 ? 1 : -1];
#endif
static void vx_stew_fixed(void) {
    if ((((uint8_t)(vx_stew_fixed_frame.a0)) > ((uint8_t)(38)))) {
        vx_stew_fixed_frame.result.v0 = ((uint8_t)(0));
        vx_stew_fixed_frame.result.v1 = ((uint16_t)((((uint16_t)(0)) & 255UL)));
        vx_stew_fixed_frame.result.v2 = ((uint8_t)(0));
        vx_stew_fixed_frame.result.v3 = ((uint8_t)(7));
    } else {
        if ((((uint16_t)(vx_stew_fixed_frame.a1)) < ((uint16_t)(200)))) {
            vx_stew_fixed_frame.result.v0 = ((uint8_t)(0));
            vx_stew_fixed_frame.result.v1 = ((uint16_t)((((uint16_t)(0)) & 255UL)));
            vx_stew_fixed_frame.result.v2 = ((uint8_t)(0));
            vx_stew_fixed_frame.result.v3 = ((uint8_t)(8));
        } else {
            vx_stew_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_stew_fixed_frame.a2)) - ((uint8_t)(1)))))) < ((uint8_t)(2))) ? ((uint8_t)(0)) : ((uint8_t)(2)))));
            if ((((uint8_t)(vx_stew_fixed_frame.a2)) == ((uint8_t)(2)))) {
                vx_stew_fixed_frame.result.v1 = ((uint16_t)((((uint16_t)(200)) & 255UL)));
                vx_stew_fixed_frame.result.v2 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_stew_fixed_frame.a0)) + ((uint8_t)(2))))));
                vx_stew_fixed_frame.result.v3 = ((uint8_t)(10));
            } else {
                vx_stew_fixed_frame.result.v1 = ((uint16_t)((((uint16_t)(0)) & 255UL)));
                vx_stew_fixed_frame.result.v2 = ((uint8_t)(0));
                vx_stew_fixed_frame.result.v3 = ((uint8_t)(((((uint8_t)(vx_stew_fixed_frame.a2)) == ((uint8_t)(1))) ? ((uint8_t)(0)) : ((uint8_t)(9)))));
            }
        }
    }
}
#endif
