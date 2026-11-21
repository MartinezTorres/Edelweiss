/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_projectile_spawn_H
#define VX_BIND_projectile_spawn_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_support_value_add16.h"
#include "vx_binding_storage.h"
#define vx_bind_projectile_spawn_frame (vx_binding_slot_0.binding_projectile_spawn)
#define VX_BIND_projectile_spawn_LOCAL /* fixed workspace */
static void vx_bind_projectile_spawn_run(void) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        2,3,1,0
    };
    vx_bind_projectile_spawn_frame.vxv_0 = ((uint8_t)(((((uint8_t)(vx_bind_projectile_spawn_frame.a0)) == ((uint8_t)(2))) ? ((uint8_t)(0)) : ((uint8_t)(((((uint8_t)(vx_bind_projectile_spawn_frame.a0)) == ((uint8_t)(1))) ? ((uint8_t)(127)) : ((uint8_t)(96))))))));
    vx_bind_projectile_spawn_frame.vxv_1 = VX_VALUE_I8(VX_VALUE_I8(((uint8_t)(0)) - ((uint8_t)(vx_bind_projectile_spawn_frame.vxv_0))));
    vx_bind_projectile_spawn_frame.vxv_2 = ((uint8_t)((((uint8_t)(vx_bind_projectile_spawn_frame.a1)) == ((uint8_t)(1)))));
    vx_bind_projectile_spawn_frame.vxv_3 = ((uint8_t)((((uint8_t)(vx_bind_projectile_spawn_frame.a1)) == ((uint8_t)(2)))));
    vx_bind_projectile_spawn_frame.vxv_4 = VX_VALUE_I8(((((uint8_t)(vx_bind_projectile_spawn_frame.a1)) == ((uint8_t)(3))) ? VX_VALUE_I8(vx_bind_projectile_spawn_frame.vxv_1) : VX_VALUE_I8(((vx_bind_projectile_spawn_frame.vxv_2 ? ((uint8_t)(1)) : ((uint8_t)(vx_bind_projectile_spawn_frame.vxv_3))) ? ((uint8_t)(0)) : ((uint8_t)(vx_bind_projectile_spawn_frame.vxv_0))))));
    vx_bind_projectile_spawn_frame.vxv_5 = VX_VALUE_I8((vx_bind_projectile_spawn_frame.vxv_2 ? VX_VALUE_I8(vx_bind_projectile_spawn_frame.vxv_1) : VX_VALUE_I8((vx_bind_projectile_spawn_frame.vxv_3 ? ((uint8_t)(vx_bind_projectile_spawn_frame.vxv_0)) : ((uint8_t)(0))))));
    vx_bind_projectile_spawn_frame.result.v0 = ((uint16_t)(((uint16_t)(VX_VALUE_ADD16(((uint16_t)(vx_bind_projectile_spawn_frame.a2)), ((uint16_t)(((uint16_t)(VX_VALUE_I16(VX_VALUE_ADD16(((uint16_t)(vx_bind_projectile_spawn_frame.vxv_4)), ((uint16_t)(VX_VALUE_I16(((uint32_t)(((uint16_t)(vx_bind_projectile_spawn_frame.vxv_4)))) << 1))))))))))))));
    vx_bind_projectile_spawn_frame.result.v1 = ((uint16_t)(((uint16_t)(VX_VALUE_ADD16(((uint16_t)(vx_bind_projectile_spawn_frame.a3)), ((uint16_t)(((uint16_t)(VX_VALUE_I16(VX_VALUE_ADD16(((uint16_t)(vx_bind_projectile_spawn_frame.vxv_5)), ((uint16_t)(VX_VALUE_I16(((uint32_t)(((uint16_t)(vx_bind_projectile_spawn_frame.vxv_5)))) << 1))))))))))))));
    vx_bind_projectile_spawn_frame.result.v2 = VX_VALUE_I8(vx_bind_projectile_spawn_frame.vxv_4);
    vx_bind_projectile_spawn_frame.result.v3 = VX_VALUE_I8(vx_bind_projectile_spawn_frame.vxv_5);
    vx_bind_projectile_spawn_frame.result.v4 = ((uint8_t)(((((uint8_t)(vx_bind_projectile_spawn_frame.a0)) != ((uint8_t)(0))) ? ((uint8_t)(255)) : ((uint8_t)(((uint8_t)((((uint8_t)(vx_bind_projectile_spawn_frame.a1)) < 4 ? vx_lut_0[((uint8_t)(vx_bind_projectile_spawn_frame.a1))] : 2))))))));
    vx_bind_projectile_spawn_frame.result.v5 = ((uint8_t)(2));
}
#endif
