/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_player_view_H
#define VX_FIXED_player_view_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_player_view_RESULT
#define VX_VALUE_player_view_RESULT
typedef struct {
    uint8_t v0; /* player_view.i */
    uint8_t v1; /* player_view.j */
    uint8_t v2; /* player_view.request */
} vx_player_view_result;
#endif
static struct {
    VX_STABLE uint16_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    VX_STABLE uint8_t a4;
    VX_STABLE uint8_t a5;
    VX_STABLE uint8_t a6;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    VX_STABLE uint8_t vxv_2;
    vx_player_view_result result;
} vx_player_view_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_player_view_fixed_size[sizeof(vx_player_view_fixed_frame)==15 ? 1 : -1];
#endif
static void vx_player_view_fixed(void) {
    vx_player_view_fixed_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(vx_player_view_fixed_frame.a0)) >> 8))))))) - ((uint8_t)(vx_player_view_fixed_frame.a2))))));
    vx_player_view_fixed_frame.vxv_1 = ((uint8_t)((((((uint8_t)(vx_player_view_fixed_frame.vxv_0)) > ((uint8_t)(13))) && (((uint8_t)(vx_player_view_fixed_frame.a4)) < ((uint8_t)(106)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_player_view_fixed_frame.a2)) + ((uint8_t)(1)))))) : ((uint8_t)((((((uint8_t)(vx_player_view_fixed_frame.vxv_0)) < ((uint8_t)(8))) && (((uint8_t)(vx_player_view_fixed_frame.a4)) > ((uint8_t)(0)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_player_view_fixed_frame.a2)) - ((uint8_t)(1)))))) : ((uint8_t)(vx_player_view_fixed_frame.a4))))))));
    vx_player_view_fixed_frame.result.v0 = ((uint8_t)(vx_player_view_fixed_frame.vxv_1));
    vx_player_view_fixed_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(vx_player_view_fixed_frame.a1)) >> 8))))))) - ((uint8_t)(vx_player_view_fixed_frame.a3))))));
    vx_player_view_fixed_frame.vxv_2 = ((uint8_t)((((((uint8_t)(vx_player_view_fixed_frame.vxv_0)) > ((uint8_t)(20))) && (((uint8_t)(vx_player_view_fixed_frame.a5)) < ((uint8_t)(224)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_player_view_fixed_frame.a3)) + ((uint8_t)(1)))))) : ((uint8_t)((((((uint8_t)(vx_player_view_fixed_frame.vxv_0)) < ((uint8_t)(10))) && (((uint8_t)(vx_player_view_fixed_frame.a5)) > ((uint8_t)(0)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_player_view_fixed_frame.a3)) - ((uint8_t)(1)))))) : ((uint8_t)(vx_player_view_fixed_frame.a5))))))));
    vx_player_view_fixed_frame.result.v1 = ((uint8_t)(vx_player_view_fixed_frame.vxv_2));
    vx_player_view_fixed_frame.result.v2 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vx_player_view_fixed_frame.a6)) | ((uint8_t)(((((uint8_t)(vx_player_view_fixed_frame.a2)) != ((uint8_t)(vx_player_view_fixed_frame.vxv_1))) ? ((uint8_t)(1)) : ((uint8_t)(0))))))))) | ((uint8_t)(((((uint8_t)(vx_player_view_fixed_frame.a3)) != ((uint8_t)(vx_player_view_fixed_frame.vxv_2))) ? ((uint8_t)(1)) : ((uint8_t)(0)))))))));
}
#endif
