/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_weapon_setup_H
#define VX_FIXED_weapon_setup_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_weapon_setup_RESULT
#define VX_VALUE_weapon_setup_RESULT
typedef struct {
    uint8_t v0; /* weapon_setup.kind */
    uint8_t v1; /* weapon_setup.slot */
} vx_weapon_setup_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t vxv_0;
    vx_weapon_setup_result result;
} vx_weapon_setup_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_weapon_setup_fixed_size[sizeof(vx_weapon_setup_fixed_frame)==5 ? 1 : -1];
#endif
static void vx_weapon_setup_fixed(void) {
    vx_weapon_setup_fixed_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_weapon_setup_fixed_frame.a1)) < ((uint8_t)(2)))));
    vx_weapon_setup_fixed_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_weapon_setup_fixed_frame.a0)) == ((uint8_t)(4))) ? ((uint8_t)((vx_weapon_setup_fixed_frame.vxv_0 ? ((uint8_t)(2)) : ((uint8_t)(0))))) : ((uint8_t)((((((uint8_t)(((uint8_t)(((uint8_t)(vx_weapon_setup_fixed_frame.a0)) - ((uint8_t)(5)))))) < ((uint8_t)(2))) ? ((uint8_t)(1)) : ((uint8_t)(0))) ? ((uint8_t)((vx_weapon_setup_fixed_frame.vxv_0 ? ((uint8_t)(3)) : ((uint8_t)(((((uint8_t)(vx_weapon_setup_fixed_frame.a1)) < ((uint8_t)(4))) ? ((uint8_t)(((((uint8_t)(vx_weapon_setup_fixed_frame.a0)) == ((uint8_t)(5))) ? ((uint8_t)(4)) : ((uint8_t)(5))))) : ((uint8_t)(0)))))))) : ((uint8_t)(((((uint8_t)(vx_weapon_setup_fixed_frame.a1)) == ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0)))))))))));
    vx_weapon_setup_fixed_frame.result.v1 = ((uint8_t)(((uint8_t)(((uint8_t)(vx_weapon_setup_fixed_frame.a1)) & ((uint8_t)(1))))));
}
#endif
