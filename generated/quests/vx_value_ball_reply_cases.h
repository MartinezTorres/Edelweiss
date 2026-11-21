/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_ball_reply_CASES_H
#define VX_VALUE_ball_reply_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_ball_reply_RESULT
#define VX_VALUE_ball_reply_RESULT
typedef struct {
    uint16_t v0; /* ball_reply.i */
    uint16_t v1; /* ball_reply.j */
    uint8_t v2; /* ball_reply.facing */
    uint8_t v3; /* ball_reply.counter */
} vx_ball_reply_result;
#endif
static inline uint8_t vx_ball_reply_branch(VX_STABLE uint8_t vxp_a1) {
    return ((uint8_t)((((uint8_t)(vxp_a1)) != ((uint8_t)(0)))));
}
static inline void vx_ball_reply_case0_value(vx_ball_reply_result *vxo, VX_STABLE uint16_t vxp_a2, VX_STABLE uint16_t vxp_a3, VX_STABLE uint8_t vxp_a6, VX_STABLE uint8_t vxp_a7) {
    VX_VALUE_COPY16(vxo->v0, vxp_a2);
    VX_VALUE_COPY16(vxo->v1, vxp_a3);
    vxo->v2 = ((uint8_t)(vxp_a6));
    vxo->v3 = ((uint8_t)(vxp_a7));
}
static inline void vx_ball_reply_case1_value(vx_ball_reply_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint16_t vxp_a4, VX_STABLE uint16_t vxp_a5) {
    VX_VALUE_COPY16(vxo->v0, vxp_a4);
    VX_VALUE_COPY16(vxo->v1, vxp_a5);
    vxo->v2 = ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(1))) ? ((uint8_t)(2)) : ((uint8_t)(1)))));
    vxo->v3 = ((uint8_t)(30));
}
#endif
