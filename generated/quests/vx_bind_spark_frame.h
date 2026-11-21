/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_spark_frame_H
#define VX_BIND_spark_frame_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_spark_frame_frame (vx_binding_slot_0.binding_spark_frame)
#define VX_BIND_spark_frame_LOCAL /* fixed workspace */
static void vx_bind_spark_frame_run(void) {
    vx_bind_spark_frame_frame.result.v0 = ((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_spark_frame_frame.a0)) + ((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(vx_bind_spark_frame_frame.a0)))) << 1)))))))) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_spark_frame_frame.a1)) & ((uint8_t)(254)))))) == ((uint8_t)(0))) ? ((uint8_t)(vx_bind_spark_frame_frame.a1)) : ((uint8_t)(2)))))))));
}
#endif
