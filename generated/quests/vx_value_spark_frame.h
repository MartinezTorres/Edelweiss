/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_spark_frame_H
#define VX_VALUE_spark_frame_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_spark_frame_RESULT
#define VX_VALUE_spark_frame_RESULT
typedef struct {
    uint8_t v0; /* spark_frame */
} vx_spark_frame_result;
#endif
static inline void vx_spark_frame_value(vx_spark_frame_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1) {
    vxo->v0 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) + ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vxp_a0)))) << 1)))))))) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) & ((uint8_t)(254)))))) == ((uint8_t)(0))) ? ((uint8_t)(vxp_a1)) : ((uint8_t)(2)))))))));
}
#endif
