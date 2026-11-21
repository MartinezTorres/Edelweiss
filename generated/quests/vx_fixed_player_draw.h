/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_player_draw_H
#define VX_FIXED_player_draw_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_player_draw_RESULT
#define VX_VALUE_player_draw_RESULT
typedef struct {
    uint8_t v0; /* player_draw.facing */
    uint8_t v1; /* player_draw.frame */
} vx_player_draw_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    VX_STABLE uint8_t vxv_2;
    vx_player_draw_result result;
} vx_player_draw_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_player_draw_fixed_size[sizeof(vx_player_draw_fixed_frame)==8 ? 1 : -1];
#endif
static void vx_player_draw_fixed(void) {
    vx_player_draw_fixed_frame.vxv_0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_player_draw_fixed_frame.a0)) & ((uint8_t)(64)))))) == ((uint8_t)(0))) ? ((uint8_t)(4)) : ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_player_draw_fixed_frame.a0)) & ((uint8_t)(32)))))) == ((uint8_t)(0))) ? ((uint8_t)(3)) : ((uint8_t)(vx_player_draw_fixed_frame.a2))))))));
    vx_player_draw_fixed_frame.vxv_1 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_player_draw_fixed_frame.a0)) & ((uint8_t)(128)))))) == ((uint8_t)(0))) ? ((uint8_t)(2)) : ((uint8_t)(vx_player_draw_fixed_frame.vxv_0)))));
    vx_player_draw_fixed_frame.vxv_2 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_player_draw_fixed_frame.a0)) & ((uint8_t)(16)))))) == ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(vx_player_draw_fixed_frame.vxv_1)))));
    vx_player_draw_fixed_frame.result.v0 = ((uint8_t)(vx_player_draw_fixed_frame.vxv_2));
    vx_player_draw_fixed_frame.result.v1 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_player_draw_fixed_frame.a0)) & ((uint8_t)(240)))))) == ((uint8_t)(240))) ? ((uint8_t)(255)) : ((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vx_player_draw_fixed_frame.vxv_2)) == ((uint8_t)(1))) ? ((uint8_t)(8)) : ((uint8_t)(((((uint8_t)(vx_player_draw_fixed_frame.vxv_1)) == ((uint8_t)(2))) ? ((uint8_t)(6)) : ((uint8_t)(((((uint8_t)(vx_player_draw_fixed_frame.vxv_0)) == ((uint8_t)(3))) ? ((uint8_t)(2)) : ((uint8_t)(4))))))))))) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_player_draw_fixed_frame.a1)) & ((uint8_t)(4)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1))))))))))));
}
#endif
