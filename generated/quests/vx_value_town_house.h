/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_town_house_H
#define VX_VALUE_town_house_H
#include "vexel.h"
#include "vx_support_value_base.h"
#include "vx_support_value_lt8.h"
#ifndef VX_VALUE_town_house_RESULT
#define VX_VALUE_town_house_RESULT
typedef struct {
    uint8_t v0; /* town_house.text */
    uint8_t v1; /* town_house.i */
    uint8_t v2; /* town_house.j */
    uint8_t v3; /* town_house.draw */
} vx_town_house_result;
#endif
static inline void vx_town_house_value(vx_town_house_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2, VX_STABLE uint8_t vxp_a3) {
    if ((((uint8_t)(vxp_a0)) > ((uint8_t)(3)))) {
        vxo->v0 = ((uint8_t)(0));
        vxo->v1 = ((uint8_t)(0));
        vxo->v2 = ((uint8_t)(0));
        vxo->v3 = ((uint8_t)(0));
    } else {
        if ((((uint8_t)(vxp_a1)) == ((uint8_t)(255)))) {
            vxo->v0 = ((uint8_t)(0));
            vxo->v1 = ((uint8_t)(0));
            vxo->v2 = ((uint8_t)(0));
            vxo->v3 = ((uint8_t)(1));
        } else {
            VX_STABLE uint8_t vxv_0;
            vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) & ((uint8_t)(4))))));
            if (((((uint8_t)(vxv_0)) == ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vxp_a2)) == ((uint8_t)(255))))) : ((uint8_t)(0)))) {
                vxo->v0 = ((uint8_t)(0));
                vxo->v1 = ((uint8_t)(0));
                vxo->v2 = ((uint8_t)(0));
                vxo->v3 = ((uint8_t)(2));
            } else {
                vxo->v0 = ((uint8_t)(((((uint8_t)(vxp_a3)) != ((uint8_t)(0))) ? ((uint8_t)(49)) : ((uint8_t)(48)))));
                VX_STABLE uint8_t vxv_1;
                vxv_1 = ((uint8_t)(((((uint8_t)(vxv_0)) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) & ((uint8_t)(4)))))) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(2))))))));
                VX_STABLE uint8_t vxv_2;
                vxv_2 = ((uint8_t)(((!VX_VALUE_LT8(((uint8_t)(vxv_1)), ((uint8_t)(vxp_a0)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxv_1)) + ((uint8_t)(1)))))) : ((uint8_t)(vxv_1)))));
                vxv_1 = ((uint8_t)((((uint8_t)(vxv_2)) == ((uint8_t)(0)))));
                VX_STABLE uint8_t vxv_3;
                vxv_3 = ((uint8_t)((((uint8_t)(vxv_2)) == ((uint8_t)(1)))));
                vxo->v1 = ((uint8_t)(((vxv_1 ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vxv_2)) == ((uint8_t)(3)))))) ? ((uint8_t)(59)) : ((uint8_t)((vxv_3 ? ((uint8_t)(47)) : ((uint8_t)(46))))))));
                vxo->v2 = ((uint8_t)((vxv_1 ? ((uint8_t)(60)) : ((uint8_t)((vxv_3 ? ((uint8_t)(65)) : ((uint8_t)(71))))))));
                vxo->v3 = ((uint8_t)(0));
            }
        }
    }
}
#endif
