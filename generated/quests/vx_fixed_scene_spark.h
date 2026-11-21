/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_scene_spark_H
#define VX_FIXED_scene_spark_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_scene_spark_RESULT
#define VX_VALUE_scene_spark_RESULT
typedef struct {
    uint8_t v0; /* scene_spark.slot */
    uint8_t v1; /* scene_spark.i */
    uint8_t v2; /* scene_spark.j */
    uint8_t v3; /* scene_spark.initialize */
    uint8_t v4; /* scene_spark.statue */
} vx_scene_spark_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t vxv_0;
    vx_scene_spark_result result;
} vx_scene_spark_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_scene_spark_fixed_size[sizeof(vx_scene_spark_fixed_frame)==8 ? 1 : -1];
#endif
static void vx_scene_spark_fixed(void) {
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
    vx_scene_spark_fixed_frame.result.v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_scene_spark_fixed_frame.a0)) < 139 ? vx_lut_0[((uint8_t)(vx_scene_spark_fixed_frame.a0))] : 0)))));
    vx_scene_spark_fixed_frame.result.v1 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_scene_spark_fixed_frame.a0)) < 133 ? vx_lut_1[((uint8_t)(vx_scene_spark_fixed_frame.a0))] : 100)))));
    vx_scene_spark_fixed_frame.result.v2 = ((uint8_t)(((uint8_t)((((uint8_t)(vx_scene_spark_fixed_frame.a0)) < 127 ? vx_lut_2[((uint8_t)(vx_scene_spark_fixed_frame.a0))] : 136)))));
    vx_scene_spark_fixed_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_scene_spark_fixed_frame.a1)) != ((uint8_t)(0)))));
    vx_scene_spark_fixed_frame.result.v3 = ((uint8_t)(((vx_scene_spark_fixed_frame.vxv_0 ? ((uint8_t)((((uint8_t)(vx_scene_spark_fixed_frame.a0)) == ((uint8_t)(0))))) : ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
    vx_scene_spark_fixed_frame.result.v4 = ((uint8_t)(((((uint8_t)(vx_scene_spark_fixed_frame.a0)) == ((uint8_t)(132))) ? ((uint8_t)((vx_scene_spark_fixed_frame.vxv_0 ? ((uint8_t)(1)) : ((uint8_t)(2))))) : ((uint8_t)(0)))));
}
#endif
