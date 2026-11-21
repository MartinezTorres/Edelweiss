/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_ui_editor_CASES_H
#define VX_VALUE_ui_editor_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#include "vx_support_value_add8.h"
#ifndef VX_VALUE_ui_editor_RESULT
#define VX_VALUE_ui_editor_RESULT
typedef struct {
    uint8_t v0; /* ui_editor.length */
    uint8_t v1; /* ui_editor.character */
    uint8_t v2; /* ui_editor.accept */
    uint8_t v3; /* ui_editor.done */
    uint8_t v4; /* ui_editor.cursor */
} vx_ui_editor_result;
#endif
static inline uint8_t vx_ui_editor_branch(VX_STABLE uint8_t vxp_a1) {
    return ((uint8_t)(((((uint8_t)(vxp_a1)) >= ((uint8_t)(97))) ? ((uint8_t)((((uint8_t)(vxp_a1)) <= ((uint8_t)(122))))) : ((uint8_t)(0)))));
}
static inline void vx_ui_editor_case0_value(vx_ui_editor_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2) {
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)(((((((uint8_t)(vxp_a0)) < ((uint8_t)(10))) ? ((uint8_t)((((uint8_t)(vxp_a1)) > ((uint8_t)(32))))) : ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vxp_a1)) < ((uint8_t)(127))))) : ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
    VX_STABLE uint8_t vxv_1;
    vxv_1 = ((uint8_t)(((uint8_t)(VX_VALUE_ADD8(((uint8_t)(vxp_a0)), ((uint8_t)(vxv_0)))))));
    vxo->v0 = ((uint8_t)(vxv_1));
    vxo->v1 = ((uint8_t)(vxp_a1));
    vxo->v2 = ((uint8_t)(vxv_0));
    vxo->v3 = ((uint8_t)(((((((uint8_t)(vxp_a0)) >= ((uint8_t)(10))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vxp_a1)) == ((uint8_t)(13)))))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vxv_1)) == ((uint8_t)(10)))))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
    vxo->v4 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) & ((uint8_t)(16)))))) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
static inline void vx_ui_editor_case1_value(vx_ui_editor_result *vxo, VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1, VX_STABLE uint8_t vxp_a2) {
    VX_STABLE uint8_t vxv_0;
    vxv_0 = ((uint8_t)(((((uint8_t)(vxp_a0)) < ((uint8_t)(10))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
    vxo->v0 = ((uint8_t)(((uint8_t)(VX_VALUE_ADD8(((uint8_t)(vxp_a0)), ((uint8_t)(vxv_0)))))));
    vxo->v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vxp_a1)) - ((uint8_t)(32))))));
    vxo->v2 = ((uint8_t)(vxv_0));
    vxo->v3 = ((uint8_t)(((((uint8_t)(vxp_a0)) < ((uint8_t)(9))) ? ((uint8_t)(0)) : ((uint8_t)(1)))));
    vxo->v4 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) & ((uint8_t)(16)))))) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
}
#endif
