/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_contact_player_H
#define VX_FIXED_contact_player_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_contact_player_RESULT
#define VX_VALUE_contact_player_RESULT
typedef struct {
    uint8_t v0; /* contact_player */
} vx_contact_player_result;
#endif
static struct {
    VX_STABLE uint16_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint16_t a2;
    VX_STABLE uint16_t a3;
    vx_contact_player_result result;
} vx_contact_player_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_contact_player_fixed_size[sizeof(vx_contact_player_fixed_frame)==9 ? 1 : -1];
#endif
static void vx_contact_player_fixed(void) {
    vx_contact_player_fixed_frame.result.v0 = ((uint8_t)(((((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vx_contact_player_fixed_frame.a0)) - ((uint16_t)(vx_contact_player_fixed_frame.a2)))))) >> 5))))))) - ((uint8_t)(9)))))) < ((uint8_t)(239))) ? ((uint8_t)(0)) : ((uint8_t)(1))) && ((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vx_contact_player_fixed_frame.a1)) - ((uint16_t)(vx_contact_player_fixed_frame.a3)))))) >> 5))))))) - ((uint8_t)(9)))))) < ((uint8_t)(239))) ? ((uint8_t)(0)) : ((uint8_t)(1)))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
#endif
