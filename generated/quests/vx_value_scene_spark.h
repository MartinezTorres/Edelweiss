/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_scene_spark_H
#define VX_VALUE_scene_spark_H
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
static inline void vx_scene_spark_value(vx_scene_spark_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1) {
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
    vxo->v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vxp_a0)) < 139 ? vx_lut_0[((uint8_t)(vxp_a0))] : 0)))));
    vxo->v1 = ((uint8_t)(((uint8_t)((((uint8_t)(vxp_a0)) < 133 ? vx_lut_1[((uint8_t)(vxp_a0))] : 100)))));
    vxo->v2 = ((uint8_t)(((uint8_t)((((uint8_t)(vxp_a0)) < 127 ? vx_lut_2[((uint8_t)(vxp_a0))] : 136)))));
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)((((uint8_t)(vxp_a1)) != ((uint8_t)(0)))));
    vxo->v3 = ((uint8_t)(((vxv_0 ? ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(0))))) : ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
    vxo->v4 = ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(132))) ? ((uint8_t)((vxv_0 ? ((uint8_t)(1)) : ((uint8_t)(2))))) : ((uint8_t)(0)))));
}
#endif
