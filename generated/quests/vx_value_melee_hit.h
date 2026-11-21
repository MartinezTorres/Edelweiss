/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_melee_hit_H
#define VX_VALUE_melee_hit_H
#include "vexel.h"
#include "vx_support_value_base.h"
#include "vx_support_value_add16.h"
#ifndef VX_VALUE_melee_hit_RESULT
#define VX_VALUE_melee_hit_RESULT
typedef struct {
    uint16_t v0; /* melee_hit.i */
    uint16_t v1; /* melee_hit.j */
    uint8_t v2; /* melee_hit.height */
    uint8_t v3; /* melee_hit.width */
} vx_melee_hit_result;
#endif
static inline void vx_melee_hit_value(vx_melee_hit_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint16_t vxp_a2, VX_STABLE uint16_t vxp_a3) {
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)((((uint8_t)(vxp_a1)) == ((uint8_t)(3)))));
    VX_STABLE uint8_t vxv_1;
    vxv_1 = ((uint8_t)((((uint8_t)(vxp_a1)) == ((uint8_t)(4)))));
    VX_STABLE uint8_t vxv_2;
    vxv_2 = ((uint8_t)((vxv_0 ? ((uint8_t)(1)) : ((uint8_t)(vxv_1)))));
    VX_STABLE uint8_t vxv_3;
    vxv_3 = ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(0))) ? ((uint8_t)(160)) : ((uint8_t)(192)))));
    if (vxv_0) {
        vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) - ((uint16_t)(vxv_3))))))));
    } else {
        if (vxv_1) {
            vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(VX_VALUE_ADD16(((uint16_t)(vxp_a2)), ((uint16_t)(vxv_3)))))))))));
        } else {
            VX_VALUE_COPY16(vxo->v0, vxp_a2);
        }
    }
    if (vxv_2) {
        if ((((uint8_t)(vxp_a1)) == ((uint8_t)(1)))) {
            vxo->v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a3)) - ((uint16_t)(vxv_3))))))));
        } else {
            VX_VALUE_COPY16(vxo->v1, vxp_a3);
        }
        if ((((uint8_t)(vxp_a0)) == ((uint8_t)(0)))) {
            vxo->v2 = ((uint8_t)(10));
            vxo->v3 = ((uint8_t)(36));
        } else {
            vxo->v2 = ((uint8_t)(12));
            vxo->v3 = ((uint8_t)(40));
        }
    } else {
        if ((((uint8_t)(vxp_a1)) == ((uint8_t)(1)))) {
            vxo->v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a3)) - ((uint16_t)(vxv_3))))))));
        } else {
            vxo->v1 = ((uint16_t)(((uint16_t)(((uint16_t)(VX_VALUE_ADD16(((uint16_t)(vxp_a3)), ((uint16_t)(vxv_3)))))))));
        }
        if ((((uint8_t)(vxp_a0)) == ((uint8_t)(0)))) {
            vxo->v2 = ((uint8_t)(36));
            vxo->v3 = ((uint8_t)(10));
        } else {
            vxo->v2 = ((uint8_t)(40));
            vxo->v3 = ((uint8_t)(12));
        }
    }
}
#endif
