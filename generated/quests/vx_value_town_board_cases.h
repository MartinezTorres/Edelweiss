/* Dependency-split value API. Evaluate branch, then ONLY its selected
 * case with the same input snapshot. No effects may intervene. */
#ifndef VX_VALUE_town_board_CASES_H
#define VX_VALUE_town_board_CASES_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_town_board_RESULT
#define VX_VALUE_town_board_RESULT
typedef struct {
    uint8_t v0; /* town_board.text */
    uint8_t v1; /* town_board.next */
} vx_town_board_result;
#endif
static inline uint8_t vx_town_board_branch(VX_STABLE uint8_t vxp_a0, VX_STABLE uint8_t vxp_a1) {
    return ((uint8_t)((((uint8_t)(vxp_a0)) == ((uint8_t)(vxp_a1)))));
}
static inline void vx_town_board_case0_value(vx_town_board_result *vxo, VX_STABLE uint8_t vxp_a0) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,50,0,0,0,0,51,0,0,0,
        0,0,0,0,0,0,0,0,0,52,0,53,0,0,0,0,
        54,0,55,0,0,0,0,0,56,0,57,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,0,0,58
    };
    vxo->v0 = ((uint8_t)(((uint8_t)((((uint8_t)(vxp_a0)) < 93 ? vx_lut_0[((uint8_t)(vxp_a0))] : 0)))));
    vxo->v1 = ((uint8_t)(vxp_a0));
}
static inline void vx_town_board_case1_value(vx_town_board_result *vxo, VX_STABLE uint8_t vxp_a0) {
    vxo->v0 = ((uint8_t)(0));
    vxo->v1 = ((uint8_t)(vxp_a0));
}
#endif
