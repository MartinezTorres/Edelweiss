/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_player_move_H
#define VX_BIND_player_move_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_player_move_frame (vx_binding_slot_0.binding_player_move)
#define VX_BIND_player_move_LOCAL /* fixed workspace */
static void vx_bind_player_move_run(void) {
    if ((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_player_move_frame.a0)) & ((uint8_t)(64)))))) == ((uint8_t)(0)))) {
        if ((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_player_move_frame.a0)) & ((uint8_t)(32)))))) == ((uint8_t)(0)))) {
            vx_bind_player_move_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_player_move_frame.a1)) + ((uint16_t)(((uint16_t)(65504)))))))) + ((uint16_t)(((uint8_t)(32))))))));
        } else {
            vx_bind_player_move_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_player_move_frame.a1)))) + ((uint16_t)(((uint8_t)(32))))))));
        }
    } else {
        if ((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_player_move_frame.a0)) & ((uint8_t)(32)))))) == ((uint8_t)(0)))) {
            vx_bind_player_move_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_player_move_frame.a1)) + ((uint16_t)(((uint16_t)(65504))))))))));
        } else {
            vx_bind_player_move_frame.result.v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_player_move_frame.a1))))));
        }
    }
    if ((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_player_move_frame.a0)) & ((uint8_t)(128)))))) == ((uint8_t)(0)))) {
        if ((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_player_move_frame.a0)) & ((uint8_t)(16)))))) == ((uint8_t)(0)))) {
            vx_bind_player_move_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_player_move_frame.a2)) + ((uint16_t)(((uint16_t)(65504)))))))) + ((uint16_t)(((uint8_t)(32))))))));
        } else {
            vx_bind_player_move_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_player_move_frame.a2)))) + ((uint16_t)(((uint8_t)(32))))))));
        }
    } else {
        if ((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_player_move_frame.a0)) & ((uint8_t)(16)))))) == ((uint8_t)(0)))) {
            vx_bind_player_move_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_player_move_frame.a2)) + ((uint16_t)(((uint16_t)(65504))))))))));
        } else {
            vx_bind_player_move_frame.result.v1 = ((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_player_move_frame.a2))))));
        }
    }
}
#endif
