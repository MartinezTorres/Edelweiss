/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_player_draw_H
#define VX_VALUE_player_draw_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_player_draw_RESULT
#define VX_VALUE_player_draw_RESULT
typedef struct {
    uint8_t v0; /* player_draw.facing */
    uint8_t v1; /* player_draw.frame */
} vx_player_draw_result;
#endif
static inline void vx_player_draw_value(vx_player_draw_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2) {
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) & ((uint8_t)(64)))))) == ((uint8_t)(0))) ? ((uint8_t)(4)) : ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) & ((uint8_t)(32)))))) == ((uint8_t)(0))) ? ((uint8_t)(3)) : ((uint8_t)(vxp_a2))))))));
    VX_STABLE uint8_t vxv_1;
    vxv_1 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) & ((uint8_t)(128)))))) == ((uint8_t)(0))) ? ((uint8_t)(2)) : ((uint8_t)(vxv_0)))));
    VX_STABLE uint8_t vxv_2;
    vxv_2 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) & ((uint8_t)(16)))))) == ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(vxv_1)))));
    vxo->v0 = ((uint8_t)(vxv_2));
    vxo->v1 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) & ((uint8_t)(240)))))) == ((uint8_t)(240))) ? ((uint8_t)(255)) : ((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vxv_2)) == ((uint8_t)(1))) ? ((uint8_t)(8)) : ((uint8_t)(((((uint8_t)(vxv_1)) == ((uint8_t)(2))) ? ((uint8_t)(6)) : ((uint8_t)(((((uint8_t)(vxv_0)) == ((uint8_t)(3))) ? ((uint8_t)(2)) : ((uint8_t)(4))))))))))) + ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) & ((uint8_t)(4)))))) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(1))))))))))));
}
#endif
