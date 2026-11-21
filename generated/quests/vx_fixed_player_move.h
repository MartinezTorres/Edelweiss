/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_player_move_H
#define VX_FIXED_player_move_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_player_move_RESULT
#define VX_VALUE_player_move_RESULT
typedef struct {
    uint16_t v0; /* player_move.i */
    uint16_t v1; /* player_move.j */
} vx_player_move_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint16_t a2;
    vx_player_move_result result;
} vx_player_move_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_player_move_fixed_size[sizeof(vx_player_move_fixed_frame)==9 ? 1 : -1];
#endif
static void vx_player_move_fixed(void) {
    if ((((uint8_t)(((uint8_t)(((uint8_t)(vx_player_move_fixed_frame.a0)) & ((uint8_t)(64)))))) == ((uint8_t)(0)))) {
        if ((((uint8_t)(((uint8_t)(((uint8_t)(vx_player_move_fixed_frame.a0)) & ((uint8_t)(32)))))) == ((uint8_t)(0)))) {
            vx_player_move_fixed_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_player_move_fixed_frame.a1)) + ((uint16_t)(((uint16_t)(65504)))))))) + ((uint16_t)(((uint8_t)(32))))))));
        } else {
            vx_player_move_fixed_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_player_move_fixed_frame.a1)))) + ((uint16_t)(((uint8_t)(32))))))));
        }
    } else {
        if ((((uint8_t)(((uint8_t)(((uint8_t)(vx_player_move_fixed_frame.a0)) & ((uint8_t)(32)))))) == ((uint8_t)(0)))) {
            vx_player_move_fixed_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_player_move_fixed_frame.a1)) + ((uint16_t)(((uint16_t)(65504))))))))));
        } else {
            vx_player_move_fixed_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_player_move_fixed_frame.a1))))));
        }
    }
    if ((((uint8_t)(((uint8_t)(((uint8_t)(vx_player_move_fixed_frame.a0)) & ((uint8_t)(128)))))) == ((uint8_t)(0)))) {
        if ((((uint8_t)(((uint8_t)(((uint8_t)(vx_player_move_fixed_frame.a0)) & ((uint8_t)(16)))))) == ((uint8_t)(0)))) {
            vx_player_move_fixed_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_player_move_fixed_frame.a2)) + ((uint16_t)(((uint16_t)(65504)))))))) + ((uint16_t)(((uint8_t)(32))))))));
        } else {
            vx_player_move_fixed_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_player_move_fixed_frame.a2)))) + ((uint16_t)(((uint8_t)(32))))))));
        }
    } else {
        if ((((uint8_t)(((uint8_t)(((uint8_t)(vx_player_move_fixed_frame.a0)) & ((uint8_t)(16)))))) == ((uint8_t)(0)))) {
            vx_player_move_fixed_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_player_move_fixed_frame.a2)) + ((uint16_t)(((uint16_t)(65504))))))))));
        } else {
            vx_player_move_fixed_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_player_move_fixed_frame.a2))))));
        }
    }
}
#endif
