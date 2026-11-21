/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_contact_box_H
#define VX_VALUE_contact_box_H
#include "vexel.h"
#include "vx_support_value_base.h"
#include "vx_support_value_add8.h"
#include "vx_support_value_lt8.h"
#ifndef VX_VALUE_contact_box_RESULT
#define VX_VALUE_contact_box_RESULT
typedef struct {
    uint8_t v0; /* contact_box */
} vx_contact_box_result;
#endif
static inline void vx_contact_box_value(vx_contact_box_result *vxo, VX_STABLE uint16_t vxp_a0, VX_STABLE uint16_t vxp_a1, VX_STABLE uint16_t vxp_a2, VX_STABLE uint16_t vxp_a3, VX_STABLE uint8_t vxp_a4, VX_STABLE uint8_t vxp_a5) {
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a4)) + ((uint16_t)(16)))))) >> 1)))));
    VX_STABLE uint8_t vxv_1;
    vxv_1 = ((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a5)) + ((uint16_t)(16)))))) >> 1)))));
    vxo->v0 = ((uint8_t)((((((uint8_t)(((!VX_VALUE_LT8(((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(((uint8_t)(vxv_0)))))) << 1)))), ((uint8_t)(((uint8_t)(VX_VALUE_ADD8(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a0)) - ((uint16_t)(vxp_a2)))))) >> 5))))))), ((uint8_t)(((uint8_t)(vxv_0))))))))))) ? ((uint8_t)(1)) : ((uint8_t)(0))))) != ((uint8_t)(0))) && (((uint8_t)(((!VX_VALUE_LT8(((uint8_t)(((uint8_t)(((uint16_t)(((uint8_t)(((uint8_t)(vxv_1)))))) << 1)))), ((uint8_t)(((uint8_t)(VX_VALUE_ADD8(((uint8_t)(((uint8_t)(((uint16_t)((((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) - ((uint16_t)(vxp_a3)))))) >> 5))))))), ((uint8_t)(((uint8_t)(vxv_1))))))))))) ? ((uint8_t)(1)) : ((uint8_t)(0))))) != ((uint8_t)(0)))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
#endif
