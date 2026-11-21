/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_player_view_H
#define VX_BIND_player_view_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_player_view_frame (vx_binding_slot_0.binding_player_view)
#define VX_BIND_player_view_LOCAL /* fixed workspace */
static void vx_bind_player_view_run(void) {
    vx_bind_player_view_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(vx_bind_player_view_frame.a0)) >> 8))))))) - ((uint8_t)(vx_bind_player_view_frame.a2))))));
    vx_bind_player_view_frame.vxv_1 = ((uint8_t)((((((uint8_t)(vx_bind_player_view_frame.vxv_0)) > ((uint8_t)(13))) && (((uint8_t)(vx_bind_player_view_frame.a4)) < ((uint8_t)(106)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_player_view_frame.a2)) + ((uint8_t)(1)))))) : ((uint8_t)((((((uint8_t)(vx_bind_player_view_frame.vxv_0)) < ((uint8_t)(8))) && (((uint8_t)(vx_bind_player_view_frame.a4)) > ((uint8_t)(0)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_player_view_frame.a2)) - ((uint8_t)(1)))))) : ((uint8_t)(vx_bind_player_view_frame.a4))))))));
    vx_bind_player_view_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(vx_bind_player_view_frame.a1)) >> 8))))))) - ((uint8_t)(vx_bind_player_view_frame.a3))))));
    vx_bind_player_view_frame.vxv_2 = ((uint8_t)((((((uint8_t)(vx_bind_player_view_frame.vxv_0)) > ((uint8_t)(20))) && (((uint8_t)(vx_bind_player_view_frame.a5)) < ((uint8_t)(224)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_player_view_frame.a3)) + ((uint8_t)(1)))))) : ((uint8_t)((((((uint8_t)(vx_bind_player_view_frame.vxv_0)) < ((uint8_t)(10))) && (((uint8_t)(vx_bind_player_view_frame.a5)) > ((uint8_t)(0)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_player_view_frame.a3)) - ((uint8_t)(1)))))) : ((uint8_t)(vx_bind_player_view_frame.a5))))))));
    vx_bind_player_view_frame.result.v0 = ((uint8_t)(vx_bind_player_view_frame.vxv_1));
    vx_bind_player_view_frame.result.v1 = ((uint8_t)(vx_bind_player_view_frame.vxv_2));
    vx_bind_player_view_frame.result.v2 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_player_view_frame.a6)) | ((uint8_t)(((((uint8_t)(vx_bind_player_view_frame.a2)) != ((uint8_t)(vx_bind_player_view_frame.vxv_1))) ? ((uint8_t)(1)) : ((uint8_t)(0))))))))) | ((uint8_t)(((((uint8_t)(vx_bind_player_view_frame.a3)) != ((uint8_t)(vx_bind_player_view_frame.vxv_2))) ? ((uint8_t)(1)) : ((uint8_t)(0)))))))));
}
#endif
