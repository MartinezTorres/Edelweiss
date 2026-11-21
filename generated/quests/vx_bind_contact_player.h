/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_contact_player_H
#define VX_BIND_contact_player_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_contact_player_frame (vx_binding_slot_0.binding_contact_player)
#define VX_BIND_contact_player_LOCAL /* fixed workspace */
static void vx_bind_contact_player_run(void) {
    vx_bind_contact_player_frame.result.v0 = ((uint8_t)(((((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_contact_player_frame.a0)) - ((uint16_t)(vx_bind_contact_player_frame.a2)))))) >> 5))))))) - ((uint8_t)(9)))))) < ((uint8_t)(239))) ? ((uint8_t)(0)) : ((uint8_t)(1))) && ((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vx_bind_contact_player_frame.a1)) - ((uint16_t)(vx_bind_contact_player_frame.a3)))))) >> 5))))))) - ((uint8_t)(9)))))) < ((uint8_t)(239))) ? ((uint8_t)(0)) : ((uint8_t)(1)))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
#endif
