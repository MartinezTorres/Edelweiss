/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_university_H
#define VX_FIXED_university_H
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
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    VX_STABLE uint8_t a4;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    vx_university_result result;
} vx_university_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_university_fixed_size[sizeof(vx_university_fixed_frame)==13 ? 1 : -1];
#endif
static void vx_university_fixed(void) {
    if ((((uint8_t)(vx_university_fixed_frame.a0)) == ((uint8_t)(0)))) {
        vx_university_fixed_frame.result.v0 = ((uint8_t)(1));
        vx_university_fixed_frame.result.v1 = ((uint8_t)(0));
        vx_university_fixed_frame.result.v2 = ((uint8_t)(0));
        vx_university_fixed_frame.result.v3 = ((uint8_t)(0));
        vx_university_fixed_frame.result.v4 = ((uint8_t)(11));
    } else {
        if ((((uint8_t)(vx_university_fixed_frame.a0)) == ((uint8_t)(1)))) {
            if (((((uint8_t)(vx_university_fixed_frame.a2)) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_university_fixed_frame.a4)) == ((uint8_t)(1))))))) {
                vx_university_fixed_frame.result.v0 = ((uint8_t)(2));
                vx_university_fixed_frame.result.v1 = ((uint8_t)(0));
                vx_university_fixed_frame.result.v2 = ((uint8_t)(0));
                vx_university_fixed_frame.result.v3 = ((uint8_t)(0));
                vx_university_fixed_frame.result.v4 = ((uint8_t)(0));
            } else {
                vx_university_fixed_frame.vxv_0 = ((uint8_t)((((uint16_t)(vx_university_fixed_frame.a1)) >= ((uint16_t)(50)))));
                if (((((uint8_t)(vx_university_fixed_frame.a4)) == ((uint8_t)(2))) && vx_university_fixed_frame.vxv_0)) {
                    vx_university_fixed_frame.result.v0 = ((uint8_t)(2));
                    vx_university_fixed_frame.result.v1 = ((uint8_t)(0));
                    vx_university_fixed_frame.result.v2 = ((uint8_t)(50));
                    vx_university_fixed_frame.result.v3 = ((uint8_t)(1));
                    vx_university_fixed_frame.result.v4 = ((uint8_t)(13));
                } else {
                    vx_university_fixed_frame.result.v0 = ((uint8_t)(1));
                    vx_university_fixed_frame.result.v1 = ((uint8_t)((vx_university_fixed_frame.vxv_0 ? ((uint8_t)(2)) : ((uint8_t)(1)))));
                    vx_university_fixed_frame.result.v2 = ((uint8_t)(0));
                    vx_university_fixed_frame.result.v3 = ((uint8_t)(0));
                    vx_university_fixed_frame.result.v4 = ((uint8_t)(12));
                }
            }
        } else {
            if ((((uint8_t)(vx_university_fixed_frame.a0)) == ((uint8_t)(2)))) {
                if (((((uint8_t)(vx_university_fixed_frame.a3)) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_university_fixed_frame.a4)) == ((uint8_t)(1))))))) {
                    vx_university_fixed_frame.result.v0 = ((uint8_t)(255));
                    vx_university_fixed_frame.result.v1 = ((uint8_t)(0));
                    vx_university_fixed_frame.result.v2 = ((uint8_t)(0));
                    vx_university_fixed_frame.result.v3 = ((uint8_t)(0));
                    vx_university_fixed_frame.result.v4 = ((uint8_t)(0));
                } else {
                    vx_university_fixed_frame.vxv_1 = ((uint8_t)((((uint16_t)(vx_university_fixed_frame.a1)) >= ((uint16_t)(50)))));
                    if (((((uint8_t)(vx_university_fixed_frame.a4)) == ((uint8_t)(2))) && vx_university_fixed_frame.vxv_1)) {
                        vx_university_fixed_frame.result.v0 = ((uint8_t)(255));
                        vx_university_fixed_frame.result.v1 = ((uint8_t)(0));
                        vx_university_fixed_frame.result.v2 = ((uint8_t)(50));
                        vx_university_fixed_frame.result.v3 = ((uint8_t)(4));
                        vx_university_fixed_frame.result.v4 = ((uint8_t)(15));
                    } else {
                        vx_university_fixed_frame.result.v0 = ((uint8_t)(2));
                        vx_university_fixed_frame.result.v1 = ((uint8_t)((vx_university_fixed_frame.vxv_1 ? ((uint8_t)(2)) : ((uint8_t)(1)))));
                        vx_university_fixed_frame.result.v2 = ((uint8_t)(0));
                        vx_university_fixed_frame.result.v3 = ((uint8_t)(0));
                        vx_university_fixed_frame.result.v4 = ((uint8_t)(14));
                    }
                }
            } else {
                vx_university_fixed_frame.result.v0 = ((uint8_t)(255));
                vx_university_fixed_frame.result.v1 = ((uint8_t)(0));
                vx_university_fixed_frame.result.v2 = ((uint8_t)(0));
                vx_university_fixed_frame.result.v3 = ((uint8_t)(0));
                vx_university_fixed_frame.result.v4 = ((uint8_t)(0));
            }
        }
    }
}
#endif
