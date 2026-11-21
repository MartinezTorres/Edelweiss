/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_combat_tick_H
#define VX_BIND_combat_tick_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_combat_tick_frame (vx_binding_slot_0.binding_combat_tick)
#define VX_BIND_combat_tick_LOCAL /* fixed workspace */
static void vx_bind_combat_tick_run(void) {
    vx_bind_combat_tick_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_bind_combat_tick_frame.a1)) == ((uint8_t)(0)))));
    if ((((((uint8_t)(vx_bind_combat_tick_frame.a0)) != ((uint8_t)(0))) ? ((uint8_t)(vx_bind_combat_tick_frame.vxv_0)) : ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vx_bind_combat_tick_frame.a2)) == ((uint8_t)(0))))) : ((uint8_t)(0)))) {
        vx_bind_combat_tick_frame.result.v0 = ((uint8_t)(1));
        vx_bind_combat_tick_frame.result.v1 = ((uint8_t)(0));
        vx_bind_combat_tick_frame.result.v2 = ((uint8_t)(0));
        vx_bind_combat_tick_frame.result.v3 = ((uint8_t)(0));
        vx_bind_combat_tick_frame.result.v4 = ((uint8_t)(2));
    } else {
        if ((((uint8_t)(vx_bind_combat_tick_frame.a0)) == ((uint8_t)(0)))) {
            vx_bind_combat_tick_frame.result.v0 = ((uint8_t)(0));
            vx_bind_combat_tick_frame.result.v1 = ((uint8_t)(0));
            vx_bind_combat_tick_frame.result.v2 = ((uint8_t)(0));
            vx_bind_combat_tick_frame.result.v3 = ((uint8_t)(0));
            vx_bind_combat_tick_frame.result.v4 = ((uint8_t)(0));
        } else {
            vx_bind_combat_tick_frame.vxv_1 = ((uint8_t)(((((uint8_t)(vx_bind_combat_tick_frame.a1)) > ((uint8_t)(vx_bind_combat_tick_frame.a3))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_combat_tick_frame.a1)) - ((uint8_t)(vx_bind_combat_tick_frame.a3)))))) : ((uint8_t)(0)))));
            vx_bind_combat_tick_frame.result.v1 = ((uint8_t)(vx_bind_combat_tick_frame.vxv_1));
            vx_bind_combat_tick_frame.result.v4 = ((uint8_t)((vx_bind_combat_tick_frame.vxv_0 ? ((uint8_t)(2)) : ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_combat_tick_frame.vxv_1)) & ((uint8_t)(4)))))) == ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0))))))));
            if ((((uint8_t)(vx_bind_combat_tick_frame.a2)) > ((uint8_t)(6)))) {
                vx_bind_combat_tick_frame.result.v0 = ((uint8_t)(2));
                if ((((uint8_t)(vx_bind_combat_tick_frame.a3)) < ((uint8_t)(6)))) {
                    vx_bind_combat_tick_frame.result.v2 = ((uint8_t)(((uint8_t)(((uint8_t)(6)) - ((uint8_t)(vx_bind_combat_tick_frame.a3))))));
                    vx_bind_combat_tick_frame.result.v3 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint16_t)(((uint8_t)(vx_bind_combat_tick_frame.a3)))) << 1))))) + ((uint8_t)(vx_bind_combat_tick_frame.a3))))));
                } else {
                    vx_bind_combat_tick_frame.result.v2 = ((uint8_t)(0));
                    vx_bind_combat_tick_frame.result.v3 = ((uint8_t)(18));
                }
            } else {
                vx_bind_combat_tick_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_bind_combat_tick_frame.a2)) != ((uint8_t)(0))) ? ((uint8_t)(2)) : ((uint8_t)(1)))));
                if ((((uint8_t)(vx_bind_combat_tick_frame.a3)) < ((uint8_t)(vx_bind_combat_tick_frame.a2)))) {
                    vx_bind_combat_tick_frame.result.v2 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_combat_tick_frame.a2)) - ((uint8_t)(vx_bind_combat_tick_frame.a3))))));
                    vx_bind_combat_tick_frame.result.v3 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint16_t)(((uint8_t)(vx_bind_combat_tick_frame.a3)))) << 1))))) + ((uint8_t)(vx_bind_combat_tick_frame.a3))))));
                } else {
                    vx_bind_combat_tick_frame.result.v2 = ((uint8_t)(((uint8_t)(0))));
                    vx_bind_combat_tick_frame.result.v3 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint16_t)(((uint8_t)(vx_bind_combat_tick_frame.a2)))) << 1))))) + ((uint8_t)(vx_bind_combat_tick_frame.a2))))));
                }
            }
        }
    }
}
#endif
