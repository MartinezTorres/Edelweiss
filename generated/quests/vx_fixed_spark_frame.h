/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_spark_frame_H
#define VX_FIXED_spark_frame_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_spark_frame_RESULT
#define VX_VALUE_spark_frame_RESULT
typedef struct {
    uint8_t v0; /* spark_frame */
} vx_spark_frame_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    vx_spark_frame_result result;
} vx_spark_frame_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_spark_frame_fixed_size[sizeof(vx_spark_frame_fixed_frame)==3 ? 1 : -1];
#endif
static void vx_spark_frame_fixed(void) {
    vx_spark_frame_fixed_frame.result.v0 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vx_spark_frame_fixed_frame.a0)) + ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vx_spark_frame_fixed_frame.a0)))) << 1)))))))) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_spark_frame_fixed_frame.a1)) & ((uint8_t)(254)))))) == ((uint8_t)(0))) ? ((uint8_t)(vx_spark_frame_fixed_frame.a1)) : ((uint8_t)(2)))))))));
}
#endif
