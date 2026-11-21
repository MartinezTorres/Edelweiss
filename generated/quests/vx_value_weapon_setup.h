/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_weapon_setup_H
#define VX_VALUE_weapon_setup_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_weapon_setup_RESULT
#define VX_VALUE_weapon_setup_RESULT
typedef struct {
    uint8_t v0; /* weapon_setup.kind */
    uint8_t v1; /* weapon_setup.slot */
} vx_weapon_setup_result;
#endif
static inline void vx_weapon_setup_value(vx_weapon_setup_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1) {
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)((((uint8_t)(vxp_a1)) < ((uint8_t)(2)))));
    vxo->v0 = ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(4))) ? ((uint8_t)((vxv_0 ? ((uint8_t)(2)) : ((uint8_t)(0))))) : ((uint8_t)((((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) - ((uint8_t)(5)))))) < ((uint8_t)(2))) ? ((uint8_t)(1)) : ((uint8_t)(0))) ? ((uint8_t)((vxv_0 ? ((uint8_t)(3)) : ((uint8_t)(((((uint8_t)(vxp_a1)) < ((uint8_t)(4))) ? ((uint8_t)(((((uint8_t)(vxp_a0)) == ((uint8_t)(5))) ? ((uint8_t)(4)) : ((uint8_t)(5))))) : ((uint8_t)(0)))))))) : ((uint8_t)(((((uint8_t)(vxp_a1)) == ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))))))))));
    vxo->v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) & ((uint8_t)(1))))));
}
#endif
