/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_university_CASES_H
#define VX_VALUE_university_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_university_RESULT
#define VX_VALUE_university_RESULT
typedef struct {
    uint8_t v0; /* university.next */
    uint8_t v1; /* university.choices */
    uint8_t v2; /* university.debit */
    uint8_t v3; /* university.weapon */
    uint8_t v4; /* university.text */
} vx_university_result;
#endif
static inline uint8_t vx_university_branch(VX_STABLE uint8_t vxp_a0) {
    return ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(0)))));
}
static inline void vx_university_case0_value(vx_university_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint16_t vxp_a1, VX_STABLE uint8_t vxp_a2, VX_STABLE uint8_t vxp_a3, VX_STABLE uint8_t vxp_a4) {
    if ((((uint8_t)(vxp_a0)) == ((uint8_t)(1)))) {
        if (((((uint8_t)(vxp_a2)) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vxp_a4)) == ((uint8_t)(1))))))) {
            vxo->v0 = ((uint8_t)(2));
            vxo->v1 = ((uint8_t)(0));
            vxo->v2 = ((uint8_t)(0));
            vxo->v3 = ((uint8_t)(0));
            vxo->v4 = ((uint8_t)(0));
        } else {
            VX_STABLE uint8_t vxv_0;
            vxv_0 = ((uint8_t)((((uint16_t)(vxp_a1)) >= ((uint16_t)(50)))));
            if (((((uint8_t)(vxp_a4)) == ((uint8_t)(2))) && vxv_0)) {
                vxo->v0 = ((uint8_t)(2));
                vxo->v1 = ((uint8_t)(0));
                vxo->v2 = ((uint8_t)(50));
                vxo->v3 = ((uint8_t)(1));
                vxo->v4 = ((uint8_t)(13));
            } else {
                vxo->v0 = ((uint8_t)(1));
                vxo->v1 = ((uint8_t)((vxv_0 ? ((uint8_t)(2)) : ((uint8_t)(1)))));
                vxo->v2 = ((uint8_t)(0));
                vxo->v3 = ((uint8_t)(0));
                vxo->v4 = ((uint8_t)(12));
            }
        }
    } else {
        if ((((uint8_t)(vxp_a0)) == ((uint8_t)(2)))) {
            if (((((uint8_t)(vxp_a3)) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vxp_a4)) == ((uint8_t)(1))))))) {
                vxo->v0 = ((uint8_t)(255));
                vxo->v1 = ((uint8_t)(0));
                vxo->v2 = ((uint8_t)(0));
                vxo->v3 = ((uint8_t)(0));
                vxo->v4 = ((uint8_t)(0));
            } else {
                VX_STABLE uint8_t vxv_1;
                vxv_1 = ((uint8_t)((((uint16_t)(vxp_a1)) >= ((uint16_t)(50)))));
                if (((((uint8_t)(vxp_a4)) == ((uint8_t)(2))) && vxv_1)) {
                    vxo->v0 = ((uint8_t)(255));
                    vxo->v1 = ((uint8_t)(0));
                    vxo->v2 = ((uint8_t)(50));
                    vxo->v3 = ((uint8_t)(4));
                    vxo->v4 = ((uint8_t)(15));
                } else {
                    vxo->v0 = ((uint8_t)(2));
                    vxo->v1 = ((uint8_t)((vxv_1 ? ((uint8_t)(2)) : ((uint8_t)(1)))));
                    vxo->v2 = ((uint8_t)(0));
                    vxo->v3 = ((uint8_t)(0));
                    vxo->v4 = ((uint8_t)(14));
                }
            }
        } else {
            vxo->v0 = ((uint8_t)(255));
            vxo->v1 = ((uint8_t)(0));
            vxo->v2 = ((uint8_t)(0));
            vxo->v3 = ((uint8_t)(0));
            vxo->v4 = ((uint8_t)(0));
        }
    }
}
static inline void vx_university_case1_value(vx_university_result *vxo) {
    vxo->v0 = ((uint8_t)(1));
    vxo->v1 = ((uint8_t)(0));
    vxo->v2 = ((uint8_t)(0));
    vxo->v3 = ((uint8_t)(0));
    vxo->v4 = ((uint8_t)(11));
}
#endif
