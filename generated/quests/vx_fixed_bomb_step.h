/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_bomb_step_H
#define VX_FIXED_bomb_step_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_bomb_step_RESULT
#define VX_VALUE_bomb_step_RESULT
typedef struct {
    uint8_t v0; /* bomb_step.spent */
    uint8_t v1; /* bomb_step.counter */
    uint8_t v2; /* bomb_step.live */
    uint8_t v3; /* bomb_step.frame */
    uint8_t v4; /* bomb_step.color */
    uint8_t v5; /* bomb_step.move */
    int16_t v6; /* bomb_step.di */
    int16_t v7; /* bomb_step.dj */
    uint8_t v8; /* bomb_step.query */
} vx_bomb_step_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    VX_STABLE uint8_t vxv_2;
    VX_STABLE uint8_t vxv_3;
    vx_bomb_step_result result;
} vx_bomb_step_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_bomb_step_fixed_size[sizeof(vx_bomb_step_fixed_frame)==17 ? 1 : -1];
#endif
static void vx_bomb_step_fixed(void) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_1[] = {
        9,14,9,14,9,14,9,14,9,14,9,14,9,14,9,14,
        9,14,9,14,9,14,9,9,9,9,9,9,9,9,9,9
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint16_t vx_lut_3[] = {
        65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,
        65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,
        65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,
        65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,
        65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,
        65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,65386,
        65386,70,70,65434,65434,134,134,65450,65450,118,118,65386,65386,102,102,102,
        102,102,102,102,102,102,102,102,102,102,102,102,102,102,102,102
    };
    if ((((uint8_t)(vx_bomb_step_fixed_frame.a1)) == ((uint8_t)(0)))) {
        vx_bomb_step_fixed_frame.result.v0 = ((uint8_t)(0));
        vx_bomb_step_fixed_frame.result.v1 = ((uint8_t)(vx_bomb_step_fixed_frame.a0));
        vx_bomb_step_fixed_frame.result.v2 = ((uint8_t)(1));
        vx_bomb_step_fixed_frame.result.v3 = ((uint8_t)(255));
        vx_bomb_step_fixed_frame.result.v4 = ((uint8_t)(0));
        vx_bomb_step_fixed_frame.result.v5 = ((uint8_t)(0));
        vx_bomb_step_fixed_frame.result.v6 = VX_VALUE_I16(0);
        vx_bomb_step_fixed_frame.result.v7 = VX_VALUE_I16(0);
        vx_bomb_step_fixed_frame.result.v8 = ((uint8_t)(0));
    } else {
        vx_bomb_step_fixed_frame.result.v2 = ((uint8_t)(((((uint8_t)(vx_bomb_step_fixed_frame.a0)) < ((uint8_t)(222))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
        vx_bomb_step_fixed_frame.result.v5 = ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)(((((uint8_t)(vx_bomb_step_fixed_frame.a0)) >> 1) & 127U))))) - ((uint8_t)(95)))))) < ((uint8_t)(16))) ? ((uint8_t)(1)) : ((uint8_t)(0)))));
        if ((((uint8_t)(vx_bomb_step_fixed_frame.a0)) < ((uint8_t)(186)))) {
            vx_bomb_step_fixed_frame.result.v6 = VX_VALUE_I16(0);
            vx_bomb_step_fixed_frame.result.v7 = VX_VALUE_I16(0);
            vx_bomb_step_fixed_frame.result.v8 = ((uint8_t)(0));
            if ((((uint8_t)(vx_bomb_step_fixed_frame.a1)) < ((uint8_t)(((uint8_t)(((uint8_t)(186)) - ((uint8_t)(vx_bomb_step_fixed_frame.a0)))))))) {
                vx_bomb_step_fixed_frame.result.v0 = ((uint8_t)(vx_bomb_step_fixed_frame.a1));
                vx_bomb_step_fixed_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bomb_step_fixed_frame.a0)) + ((uint8_t)(vx_bomb_step_fixed_frame.a1))))));
                vx_bomb_step_fixed_frame.result.v1 = ((uint8_t)(vx_bomb_step_fixed_frame.vxv_0));
                vx_bomb_step_fixed_frame.vxv_1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bomb_step_fixed_frame.vxv_0)) - ((uint8_t)(1))))));
                vx_bomb_step_fixed_frame.result.v3 = ((uint8_t)(((((uint8_t)(vx_bomb_step_fixed_frame.vxv_1)) >= ((uint8_t)(180))) ? ((uint8_t)(1)) : ((uint8_t)(((((uint8_t)(vx_bomb_step_fixed_frame.a0)) < ((uint8_t)(120))) ? ((uint8_t)(0)) : ((uint8_t)(255))))))));
                vx_bomb_step_fixed_frame.result.v4 = ((uint8_t)((((((uint8_t)(vx_bomb_step_fixed_frame.vxv_1)) >= ((uint8_t)(120))) ? ((uint8_t)((((uint8_t)(vx_bomb_step_fixed_frame.a0)) < ((uint8_t)(180))))) : ((uint8_t)(0))) ? ((uint8_t)(((uint8_t)(vx_lut_1[((uint8_t)(((uint8_t)(((((uint8_t)(vx_bomb_step_fixed_frame.vxv_1)) >> 3) & 31U)))))])))) : ((uint8_t)(0)))));
            } else {
                vx_bomb_step_fixed_frame.result.v0 = ((uint8_t)(((uint8_t)(((uint8_t)(186)) - ((uint8_t)(vx_bomb_step_fixed_frame.a0))))));
                vx_bomb_step_fixed_frame.result.v1 = ((uint8_t)(186));
                vx_bomb_step_fixed_frame.result.v3 = ((uint8_t)(1));
                vx_bomb_step_fixed_frame.result.v4 = ((uint8_t)(((((uint8_t)(vx_bomb_step_fixed_frame.a0)) < ((uint8_t)(180))) ? ((uint8_t)(9)) : ((uint8_t)(0)))));
            }
        } else {
            vx_bomb_step_fixed_frame.result.v4 = ((uint8_t)(0));
            if ((((uint8_t)(vx_bomb_step_fixed_frame.a0)) < ((uint8_t)(190)))) {
                vx_bomb_step_fixed_frame.result.v0 = ((uint8_t)(1));
                vx_bomb_step_fixed_frame.result.v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bomb_step_fixed_frame.a0)) + ((uint8_t)(1))))));
                vx_bomb_step_fixed_frame.result.v3 = ((uint8_t)(2));
                vx_bomb_step_fixed_frame.result.v6 = VX_VALUE_I16(0);
                vx_bomb_step_fixed_frame.result.v7 = VX_VALUE_I16(0);
                vx_bomb_step_fixed_frame.result.v8 = ((uint8_t)(1));
            } else {
                vx_bomb_step_fixed_frame.result.v8 = ((uint8_t)(0));
                if ((((uint8_t)(vx_bomb_step_fixed_frame.a0)) < ((uint8_t)(222)))) {
                    if ((((uint8_t)(vx_bomb_step_fixed_frame.a1)) < ((uint8_t)(((uint8_t)(((uint8_t)(222)) - ((uint8_t)(vx_bomb_step_fixed_frame.a0)))))))) {
                        vx_bomb_step_fixed_frame.result.v0 = ((uint8_t)(vx_bomb_step_fixed_frame.a1));
                        vx_bomb_step_fixed_frame.vxv_2 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bomb_step_fixed_frame.a0)) + ((uint8_t)(vx_bomb_step_fixed_frame.a1))))));
                        vx_bomb_step_fixed_frame.result.v1 = ((uint8_t)(vx_bomb_step_fixed_frame.vxv_2));
                        vx_bomb_step_fixed_frame.result.v3 = ((uint8_t)((((((uint8_t)(vx_bomb_step_fixed_frame.a0)) < ((uint8_t)(210))) ? ((uint8_t)((((uint8_t)(vx_bomb_step_fixed_frame.vxv_2)) > ((uint8_t)(206))))) : ((uint8_t)(0))) ? ((uint8_t)(3)) : ((uint8_t)(255)))));
                        vx_bomb_step_fixed_frame.vxv_3 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_bomb_step_fixed_frame.vxv_2)) - ((uint8_t)(1))))));
                        vx_bomb_step_fixed_frame.result.v6 = VX_VALUE_I16(VX_VALUE_I16(vx_lut_3[((uint8_t)(((uint8_t)(((((uint8_t)(vx_bomb_step_fixed_frame.vxv_3)) >> 1) & 127U)))))]));
                        vx_bomb_step_fixed_frame.result.v7 = VX_VALUE_I16(((((uint8_t)(vx_bomb_step_fixed_frame.vxv_3)) < ((uint8_t)(194))) ? VX_VALUE_I16(-104) : VX_VALUE_I16(((((uint8_t)(vx_bomb_step_fixed_frame.vxv_3)) < ((uint8_t)(198))) ? VX_VALUE_I16(-120) : VX_VALUE_I16(((((uint8_t)(vx_bomb_step_fixed_frame.vxv_3)) < ((uint8_t)(202))) ? VX_VALUE_I16((VX_VALUE_I16(72) & 255UL)) : VX_VALUE_I16(((((uint8_t)(vx_bomb_step_fixed_frame.vxv_3)) < ((uint8_t)(206))) ? VX_VALUE_I16((VX_VALUE_I16(152) & 255UL)) : VX_VALUE_I16(((((uint8_t)(vx_bomb_step_fixed_frame.vxv_3)) < ((uint8_t)(210))) ? VX_VALUE_I16(-104) : VX_VALUE_I16(((((uint8_t)(vx_bomb_step_fixed_frame.vxv_3)) < ((uint8_t)(214))) ? VX_VALUE_I16(-88) : VX_VALUE_I16((VX_VALUE_I16(((((uint8_t)(vx_bomb_step_fixed_frame.vxv_3)) < ((uint8_t)(218))) ? ((uint8_t)(72)) : ((uint8_t)(136)))) & 255UL))))))))))))));
                    } else {
                        vx_bomb_step_fixed_frame.result.v0 = ((uint8_t)(((uint8_t)(((uint8_t)(222)) - ((uint8_t)(vx_bomb_step_fixed_frame.a0))))));
                        vx_bomb_step_fixed_frame.result.v1 = ((uint8_t)(222));
                        vx_bomb_step_fixed_frame.result.v3 = ((uint8_t)((((((uint8_t)(vx_bomb_step_fixed_frame.a0)) < ((uint8_t)(210))) ? ((uint8_t)(1)) : ((uint8_t)(0))) ? ((uint8_t)(3)) : ((uint8_t)(255)))));
                        vx_bomb_step_fixed_frame.result.v6 = VX_VALUE_I16(102);
                        vx_bomb_step_fixed_frame.result.v7 = VX_VALUE_I16(136);
                    }
                } else {
                    vx_bomb_step_fixed_frame.result.v0 = ((uint8_t)(0));
                    vx_bomb_step_fixed_frame.result.v1 = ((uint8_t)(vx_bomb_step_fixed_frame.a0));
                    vx_bomb_step_fixed_frame.result.v3 = ((uint8_t)(255));
                    vx_bomb_step_fixed_frame.result.v6 = VX_VALUE_I16(0);
                    vx_bomb_step_fixed_frame.result.v7 = VX_VALUE_I16(0);
                }
            }
        }
    }
}
#endif
