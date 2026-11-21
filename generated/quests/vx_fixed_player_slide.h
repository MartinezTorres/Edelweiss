/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_player_slide_H
#define VX_FIXED_player_slide_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_player_slide_RESULT
#define VX_VALUE_player_slide_RESULT
typedef struct {
    uint16_t v0; /* player_slide.i */
    uint16_t v1; /* player_slide.j */
    uint16_t v2; /* player_slide.qi */
    uint16_t v3; /* player_slide.qj */
    uint8_t v4; /* player_slide.query */
} vx_player_slide_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint16_t a2;
    VX_STABLE uint16_t a3;
    VX_STABLE uint16_t a4;
    VX_STABLE uint16_t a5;
    vx_player_slide_result result;
} vx_player_slide_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_player_slide_fixed_size[sizeof(vx_player_slide_fixed_frame)==19 ? 1 : -1];
#endif
static void vx_player_slide_fixed(void) {
    if ((((uint8_t)(vx_player_slide_fixed_frame.a1)) == ((uint8_t)(0)))) {
        if ((((uint8_t)(vx_player_slide_fixed_frame.a0)) == ((uint8_t)(1)))) {
            VX_VALUE_COPY16(vx_player_slide_fixed_frame.result.v0, vx_player_slide_fixed_frame.a2);
        } else {
            VX_VALUE_COPY16(vx_player_slide_fixed_frame.result.v0, vx_player_slide_fixed_frame.a4);
        }
        if ((((uint8_t)(vx_player_slide_fixed_frame.a0)) == ((uint8_t)(2)))) {
            VX_VALUE_COPY16(vx_player_slide_fixed_frame.result.v1, vx_player_slide_fixed_frame.a3);
        } else {
            VX_VALUE_COPY16(vx_player_slide_fixed_frame.result.v1, vx_player_slide_fixed_frame.a5);
        }
        vx_player_slide_fixed_frame.result.v2 = ((uint16_t)(0));
        vx_player_slide_fixed_frame.result.v3 = ((uint16_t)(0));
        vx_player_slide_fixed_frame.result.v4 = ((uint8_t)(0));
    } else {
        VX_VALUE_COPY16(vx_player_slide_fixed_frame.result.v0, vx_player_slide_fixed_frame.a2);
        VX_VALUE_COPY16(vx_player_slide_fixed_frame.result.v1, vx_player_slide_fixed_frame.a3);
        if ((((((uint8_t)(vx_player_slide_fixed_frame.a0)) == ((uint8_t)(0))) && (!VX_VALUE_EQ16(vx_player_slide_fixed_frame.a4, vx_player_slide_fixed_frame.a2))) && (!VX_VALUE_EQ16(vx_player_slide_fixed_frame.a5, vx_player_slide_fixed_frame.a3)))) {
            VX_VALUE_COPY16(vx_player_slide_fixed_frame.result.v2, vx_player_slide_fixed_frame.a2);
            VX_VALUE_COPY16(vx_player_slide_fixed_frame.result.v3, vx_player_slide_fixed_frame.a5);
            vx_player_slide_fixed_frame.result.v4 = ((uint8_t)(1));
        } else {
            if ((((uint8_t)(vx_player_slide_fixed_frame.a0)) == ((uint8_t)(1)))) {
                VX_VALUE_COPY16(vx_player_slide_fixed_frame.result.v2, vx_player_slide_fixed_frame.a4);
                VX_VALUE_COPY16(vx_player_slide_fixed_frame.result.v3, vx_player_slide_fixed_frame.a3);
                vx_player_slide_fixed_frame.result.v4 = ((uint8_t)(2));
            } else {
                vx_player_slide_fixed_frame.result.v2 = ((uint16_t)(0));
                vx_player_slide_fixed_frame.result.v3 = ((uint16_t)(0));
                vx_player_slide_fixed_frame.result.v4 = ((uint8_t)(0));
            }
        }
    }
}
#endif
