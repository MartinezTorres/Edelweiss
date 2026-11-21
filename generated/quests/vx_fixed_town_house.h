/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_town_house_H
#define VX_FIXED_town_house_H
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
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    VX_STABLE uint8_t vxv_2;
    VX_STABLE uint8_t vxv_3;
    vx_town_house_result result;
} vx_town_house_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_town_house_fixed_size[sizeof(vx_town_house_fixed_frame)==12 ? 1 : -1];
#endif
static void vx_town_house_fixed(void) {
    if ((((uint8_t)(vx_town_house_fixed_frame.a0)) > ((uint8_t)(3)))) {
        vx_town_house_fixed_frame.result.v0 = ((uint8_t)(0));
        vx_town_house_fixed_frame.result.v1 = ((uint8_t)(0));
        vx_town_house_fixed_frame.result.v2 = ((uint8_t)(0));
        vx_town_house_fixed_frame.result.v3 = ((uint8_t)(0));
    } else {
        if ((((uint8_t)(vx_town_house_fixed_frame.a1)) == ((uint8_t)(255)))) {
            vx_town_house_fixed_frame.result.v0 = ((uint8_t)(0));
            vx_town_house_fixed_frame.result.v1 = ((uint8_t)(0));
            vx_town_house_fixed_frame.result.v2 = ((uint8_t)(0));
            vx_town_house_fixed_frame.result.v3 = ((uint8_t)(1));
        } else {
            vx_town_house_fixed_frame.vxv_0 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_town_house_fixed_frame.a1)) & ((uint8_t)(4))))));
            if (((((uint8_t)(vx_town_house_fixed_frame.vxv_0)) == ((uint8_t)(0))) ? ((uint8_t)((((uint8_t)(vx_town_house_fixed_frame.a2)) == ((uint8_t)(255))))) : ((uint8_t)(0)))) {
                vx_town_house_fixed_frame.result.v0 = ((uint8_t)(0));
                vx_town_house_fixed_frame.result.v1 = ((uint8_t)(0));
                vx_town_house_fixed_frame.result.v2 = ((uint8_t)(0));
                vx_town_house_fixed_frame.result.v3 = ((uint8_t)(2));
            } else {
                vx_town_house_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_town_house_fixed_frame.a3)) != ((uint8_t)(0))) ? ((uint8_t)(49)) : ((uint8_t)(48)))));
                vx_town_house_fixed_frame.vxv_1 = ((uint8_t)(((((uint8_t)(vx_town_house_fixed_frame.vxv_0)) != ((uint8_t)(0))) ? ((uint8_t)(0)) : ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_town_house_fixed_frame.a2)) & ((uint8_t)(4)))))) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(2))))))));
                vx_town_house_fixed_frame.vxv_2 = ((uint8_t)(((!VX_VALUE_LT8(((uint8_t)(vx_town_house_fixed_frame.vxv_1)), ((uint8_t)(vx_town_house_fixed_frame.a0)))) ? ((uint8_t)(((uint8_t)(((uint8_t)(vx_town_house_fixed_frame.vxv_1)) + ((uint8_t)(1)))))) : ((uint8_t)(vx_town_house_fixed_frame.vxv_1)))));
                vx_town_house_fixed_frame.vxv_1 = ((uint8_t)((((uint8_t)(vx_town_house_fixed_frame.vxv_2)) == ((uint8_t)(0)))));
                vx_town_house_fixed_frame.vxv_3 = ((uint8_t)((((uint8_t)(vx_town_house_fixed_frame.vxv_2)) == ((uint8_t)(1)))));
                vx_town_house_fixed_frame.result.v1 = ((uint8_t)(((vx_town_house_fixed_frame.vxv_1 ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_town_house_fixed_frame.vxv_2)) == ((uint8_t)(3)))))) ? ((uint8_t)(59)) : ((uint8_t)((vx_town_house_fixed_frame.vxv_3 ? ((uint8_t)(47)) : ((uint8_t)(46))))))));
                vx_town_house_fixed_frame.result.v2 = ((uint8_t)((vx_town_house_fixed_frame.vxv_1 ? ((uint8_t)(60)) : ((uint8_t)((vx_town_house_fixed_frame.vxv_3 ? ((uint8_t)(65)) : ((uint8_t)(71))))))));
                vx_town_house_fixed_frame.result.v3 = ((uint8_t)(0));
            }
        }
    }
}
#endif
