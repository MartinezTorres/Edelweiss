/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_ui_menu_CASES_H
#define VX_VALUE_ui_menu_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_ui_menu_RESULT
#define VX_VALUE_ui_menu_RESULT
typedef struct {
    uint8_t v0; /* ui_menu.option */
    uint8_t v1; /* ui_menu.confirm */
} vx_ui_menu_result;
#endif
static inline uint8_t vx_ui_menu_branch(VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2, VX_STABLE uint8_t vxp_a3) {
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)((((uint8_t)(vxp_a2)) != ((uint8_t)(0)))));
    return ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a3)) & ((uint8_t)((vxv_0 ? ((uint8_t)(64)) : ((uint8_t)(128))))))))) != ((uint8_t)(0))) ? ((uint8_t)((((uint16_t)(((uint16_t)(((uint16_t)((((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a3)) & ((uint8_t)((vxv_0 ? ((uint8_t)(32)) : ((uint8_t)(16))))))))) != ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vxp_a0)) != ((uint8_t)(0))))) : ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) - ((uint8_t)(1)))))) : ((uint8_t)(vxp_a0))))) + ((uint16_t)(1)))))) < ((uint16_t)(vxp_a1))))) : ((uint8_t)(0)))));
}
static inline void vx_ui_menu_case0_value(vx_ui_menu_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a2, VX_STABLE uint8_t vxp_a3) {
    vxo->v0 = ((uint8_t)((((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a3)) & ((uint8_t)(((((uint8_t)(vxp_a2)) != ((uint8_t)(0))) ? ((uint8_t)(32)) : ((uint8_t)(16))))))))) != ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vxp_a0)) != ((uint8_t)(0))))) : ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) - ((uint8_t)(1)))))) : ((uint8_t)(vxp_a0)))));
    vxo->v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a3)) & ((uint8_t)(1))))));
}
static inline void vx_ui_menu_case1_value(vx_ui_menu_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a2, VX_STABLE uint8_t vxp_a3) {
    vxo->v0 = ((uint8_t)(((uint8_t)(((uint8_t)((((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a3)) & ((uint8_t)(((((uint8_t)(vxp_a2)) != ((uint8_t)(0))) ? ((uint8_t)(32)) : ((uint8_t)(16))))))))) != ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vxp_a0)) != ((uint8_t)(0))))) : ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a0)) - ((uint8_t)(1)))))) : ((uint8_t)(vxp_a0))))) + ((uint8_t)(1))))));
    vxo->v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a3)) & ((uint8_t)(1))))));
}
#endif
