/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_melee_hit_CASES_H
#define VX_VALUE_melee_hit_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_melee_hit_RESULT
#define VX_VALUE_melee_hit_RESULT
typedef struct {
    uint16_t v0; /* melee_hit.i */
    uint16_t v1; /* melee_hit.j */
    uint8_t v2; /* melee_hit.height */
    uint8_t v3; /* melee_hit.width */
} vx_melee_hit_result;
#endif
static inline uint8_t vx_melee_hit_branch(VX_STABLE uint8_t vxp_a1) {
    return ((uint8_t)((((uint8_t)(vxp_a1)) == ((uint8_t)(3)))));
}
static inline void vx_melee_hit_case0_value(vx_melee_hit_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint16_t vxp_a2, VX_STABLE uint16_t vxp_a3) {
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)((((uint8_t)(vxp_a1)) == ((uint8_t)(4)))));
    if (vxv_0) {
        VX_STABLE uint8_t vxv_1;
        vxv_1 = ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(0)))));
        VX_VALUE_COPY16(vxo->v1, vxp_a3);
        if (vxv_1) {
            vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) + ((uint16_t)(160))))));
            vxo->v2 = ((uint8_t)(10));
            vxo->v3 = ((uint8_t)(36));
        } else {
            vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) + ((uint16_t)(192))))));
            vxo->v2 = ((uint8_t)(12));
            vxo->v3 = ((uint8_t)(40));
        }
    } else {
        VX_STABLE uint8_t vxv_2;
        vxv_2 = ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(0)))));
        VX_VALUE_COPY16(vxo->v0, vxp_a2);
        if (vxv_2) {
            if ((((uint8_t)(vxp_a1)) == ((uint8_t)(1)))) {
                vxo->v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a3)) - ((uint16_t)(160))))))));
            } else {
                vxo->v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a3)) + ((uint16_t)(160))))))));
            }
            vxo->v2 = ((uint8_t)(36));
            vxo->v3 = ((uint8_t)(10));
        } else {
            if ((((uint8_t)(vxp_a1)) == ((uint8_t)(1)))) {
                vxo->v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a3)) - ((uint16_t)(192))))))));
            } else {
                vxo->v1 = ((uint16_t)(((uint16_t)(((uint16_t)(((uint16_t)(vxp_a3)) + ((uint16_t)(192))))))));
            }
            vxo->v2 = ((uint8_t)(40));
            vxo->v3 = ((uint8_t)(12));
        }
    }
}
static inline void vx_melee_hit_case1_value(vx_melee_hit_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint16_t vxp_a2, VX_STABLE uint16_t vxp_a3) {
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(0)))));
    VX_VALUE_COPY16(vxo->v1, vxp_a3);
    if (vxv_0) {
        vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) - ((uint16_t)(160))))));
        vxo->v2 = ((uint8_t)(10));
        vxo->v3 = ((uint8_t)(36));
    } else {
        vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a2)) - ((uint16_t)(192))))));
        vxo->v2 = ((uint8_t)(12));
        vxo->v3 = ((uint8_t)(40));
    }
}
#endif
