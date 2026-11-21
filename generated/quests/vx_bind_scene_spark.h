/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_scene_spark_H
#define VX_BIND_scene_spark_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_scene_spark_frame (vx_binding_slot_0.binding_scene_spark)
#define VX_BIND_scene_spark_LOCAL /* fixed workspace */
static void vx_bind_scene_spark_run(void) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        1,0,0,0,0,0,2,0,0,0,0,0,3,0,0,0,
        0,0,4,0,0,0,0,0,5,0,0,0,0,0,6,0,
        0,0,0,0,2,0,0,0,0,0,1,0,0,0,0,0,
        3,0,0,0,0,0,4,0,0,0,0,0,5,0,0,0,
        0,0,6,0,0,0,0,0,1,0,0,0,0,0,2,0,
        0,0,0,0,3,0,0,0,0,0,4,0,0,0,0,0,
        5,0,0,0,0,0,6,0,0,0,0,0,2,0,0,0,
        0,0,1,0,0,0,0,0,3,0,0,0,0,0,4,0,
        0,0,0,0,5,0,0,0,0,0,6
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_1[] = {
        97,100,100,100,100,100,101,100,100,100,100,100,98,100,100,100,
        100,100,99,100,100,100,100,100,97,100,100,100,100,100,100,100,
        100,100,100,100,98,100,100,100,100,100,101,100,100,100,100,100,
        99,100,100,100,100,100,100,100,100,100,100,100,99,100,100,100,
        100,100,100,100,100,100,100,100,97,100,100,100,100,100,101,100,
        100,100,100,100,98,100,100,100,100,100,99,100,100,100,100,100,
        97,100,100,100,100,100,100,100,100,100,100,100,98,100,100,100,
        100,100,101,100,100,100,100,100,99,100,100,100,100,100,100,100,
        100,100,100,100,99
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_2[] = {
        135,136,136,136,136,136,137,136,136,136,136,136,136,136,136,136,
        136,136,135,136,136,136,136,136,137,136,136,136,136,136,136,136,
        136,136,136,136,137,136,136,136,136,136,136,136,136,136,136,136,
        137,136,136,136,136,136,135,136,136,136,136,136,136,136,136,136,
        136,136,136,136,136,136,136,136,135,136,136,136,136,136,137,136,
        136,136,136,136,136,136,136,136,136,136,135,136,136,136,136,136,
        137,136,136,136,136,136,136,136,136,136,136,136,137,136,136,136,
        136,136,136,136,136,136,136,136,137,136,136,136,136,136,135
    };
    vx_bind_scene_spark_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_bind_scene_spark_frame.a1)) != ((uint8_t)(0)))));
    vx_bind_scene_spark_frame.result.v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_bind_scene_spark_frame.a0)) < 139 ? vx_lut_0[((uint8_t)(vx_bind_scene_spark_frame.a0))] : 0)))));
    vx_bind_scene_spark_frame.result.v1 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_bind_scene_spark_frame.a0)) < 133 ? vx_lut_1[((uint8_t)(vx_bind_scene_spark_frame.a0))] : 100)))));
    vx_bind_scene_spark_frame.result.v2 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_bind_scene_spark_frame.a0)) < 127 ? vx_lut_2[((uint8_t)(vx_bind_scene_spark_frame.a0))] : 136)))));
    vx_bind_scene_spark_frame.result.v3 = ((uint8_t)(((vx_bind_scene_spark_frame.vxv_0 ? ((uint8_t)((((uint8_t)(vx_bind_scene_spark_frame.a0)) == ((uint8_t)(0))))) : ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
    vx_bind_scene_spark_frame.result.v4 = ((uint8_t)(((((uint8_t)(vx_bind_scene_spark_frame.a0)) == ((uint8_t)(132))) ? ((uint8_t)((vx_bind_scene_spark_frame.vxv_0 ? ((uint8_t)(1)) : ((uint8_t)(2))))) : ((uint8_t)(0)))));
}
#endif
