/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_scene_wipe_H
#define VX_BIND_scene_wipe_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_scene_wipe_frame (vx_binding_slot_0.binding_scene_wipe)
#define VX_BIND_scene_wipe_LOCAL /* fixed workspace */
static void vx_bind_scene_wipe_run(void) {
    vx_bind_scene_wipe_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_bind_scene_wipe_frame.a0)) == ((uint8_t)(0)))));
    vx_bind_scene_wipe_frame.vxv_1 = ((uint8_t)((((uint8_t)(vx_bind_scene_wipe_frame.a2)) == ((uint8_t)(5)))));
    vx_bind_scene_wipe_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_bind_scene_wipe_frame.a2)) == ((uint8_t)(255))) ? ((uint8_t)(0)) : ((uint8_t)(((((uint8_t)(vx_bind_scene_wipe_frame.a2)) < ((uint8_t)(4))) ? ((uint8_t)(1)) : ((uint8_t)(((vx_bind_scene_wipe_frame.vxv_1 ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_bind_scene_wipe_frame.a2)) == ((uint8_t)(6)))))) ? ((uint8_t)(2)) : ((uint8_t)((((((uint8_t)(vx_bind_scene_wipe_frame.a2)) == ((uint8_t)(7))) ? ((uint8_t)((((uint8_t)(vx_bind_scene_wipe_frame.a0)) != ((uint8_t)(0))))) : ((uint8_t)(0))) ? ((uint8_t)(4)) : ((uint8_t)((((vx_bind_scene_wipe_frame.vxv_0 ? ((uint8_t)((((uint8_t)(vx_bind_scene_wipe_frame.a2)) >= ((uint8_t)(8))))) : ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vx_bind_scene_wipe_frame.a2)) <= ((uint8_t)(10))))) : ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_scene_wipe_frame.a2)) - ((uint8_t)(3)))))) : ((uint8_t)(3)))))))))))))))));
    vx_bind_scene_wipe_frame.result.v1 = ((uint8_t)(((((uint8_t)(vx_bind_scene_wipe_frame.a2)) < ((uint8_t)(2))) ? ((uint8_t)(vx_bind_scene_wipe_frame.a2)) : ((uint8_t)(((((uint8_t)(vx_bind_scene_wipe_frame.a2)) == ((uint8_t)(2))) ? ((uint8_t)(((uint8_t)(((uint8_t)(2)) + ((uint8_t)(vx_bind_scene_wipe_frame.a1)))))) : ((uint8_t)(((((uint8_t)(vx_bind_scene_wipe_frame.a2)) == ((uint8_t)(3))) ? ((uint8_t)(((uint8_t)(((uint8_t)(23)) - ((uint8_t)(vx_bind_scene_wipe_frame.a1)))))) : ((uint8_t)((vx_bind_scene_wipe_frame.vxv_1 ? ((uint8_t)(((uint8_t)(((uint8_t)(31)) - ((uint8_t)(vx_bind_scene_wipe_frame.a1)))))) : ((uint8_t)(vx_bind_scene_wipe_frame.a1))))))))))))));
    if ((((uint8_t)(((((uint8_t)(vx_bind_scene_wipe_frame.a2)) == ((uint8_t)((vx_bind_scene_wipe_frame.vxv_0 ? ((uint8_t)(11)) : ((uint8_t)(12)))))) ? ((uint8_t)(1)) : ((uint8_t)(0))))) != ((uint8_t)(0)))) {
        vx_bind_scene_wipe_frame.result.v2 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_scene_wipe_frame.a1)) + ((uint8_t)(1))))));
        vx_bind_scene_wipe_frame.result.v3 = ((uint8_t)(((((uint8_t)(vx_bind_scene_wipe_frame.a1)) == ((uint8_t)(10))) ? ((uint8_t)(255)) : ((uint8_t)(2)))));
    } else {
        vx_bind_scene_wipe_frame.result.v2 = ((uint8_t)(vx_bind_scene_wipe_frame.a1));
        vx_bind_scene_wipe_frame.result.v3 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_scene_wipe_frame.a2)) + ((uint8_t)(1))))));
    }
}
#endif
