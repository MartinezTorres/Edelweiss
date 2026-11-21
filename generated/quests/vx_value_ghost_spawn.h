/* Pure, total integer value projection. Caller owns the result. */
#ifndef VX_VALUE_ghost_spawn_H
#define VX_VALUE_ghost_spawn_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_ghost_spawn_RESULT
#define VX_VALUE_ghost_spawn_RESULT
typedef struct {
    uint16_t v0; /* ghost_spawn.i */
    uint16_t v1; /* ghost_spawn.j */
    int8_t v2; /* ghost_spawn.vi */
    int8_t v3; /* ghost_spawn.vj */
} vx_ghost_spawn_result;
#endif
static inline void vx_ghost_spawn_value(vx_ghost_spawn_result *vxo, VX_STABLE uint16_t vxp_a0, VX_STABLE uint16_t vxp_a1, VX_STABLE uint8_t vxp_a2) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        1,255,1,255,2,254,2,254
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_1[] = {
        2,254,2,254,4,252,4,252
    };
    vxo->v0 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a0)) - ((uint16_t)(256))))));
    vxo->v1 = ((uint16_t)(((uint16_t)(((uint16_t)(vxp_a1)) - ((uint16_t)(512))))));
    vxo->v2 = VX_VALUE_I8(VX_VALUE_I8(vx_lut_0[((uint8_t)(((uint8_t)(((uint8_t)(vxp_a2)) & ((uint8_t)(7))))))]));
    vxo->v3 = VX_VALUE_I8(VX_VALUE_I8(vx_lut_1[((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vxp_a2)) >> 1))))) & ((uint8_t)(7))))))]));
}
#endif
