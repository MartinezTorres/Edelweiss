/* Exclusive fixed-address alternative. Set every input before calling;
 * consume/copy the result before this occurrence is invoked again.
 * No source effects, callbacks or recursive calls occur inside.
 * Each including translation unit owns its own frame. */
#ifndef VX_FIXED_town_door_H
#define VX_FIXED_town_door_H
#include "vexel.h"
#include "vx_support_value_base.h"
#ifndef VX_VALUE_town_door_RESULT
#define VX_VALUE_town_door_RESULT
typedef struct {
    uint8_t v0; /* town_door */
} vx_town_door_result;
#endif
static struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    VX_STABLE uint8_t vxv_2;
    vx_town_door_result result;
} vx_town_door_fixed_frame;
#ifdef __SDCC_z80
typedef char vx_town_door_fixed_size[sizeof(vx_town_door_fixed_frame)==6 ? 1 : -1];
#endif
static void vx_town_door_fixed(void) {
    vx_town_door_fixed_frame.vxv_0 = ((uint8_t)((((uint8_t)(vx_town_door_fixed_frame.a0)) == ((uint8_t)(57)))));
    vx_town_door_fixed_frame.vxv_1 = ((uint8_t)((((uint8_t)(vx_town_door_fixed_frame.a0)) == ((uint8_t)(59)))));
    vx_town_door_fixed_frame.vxv_2 = ((uint8_t)((((uint8_t)(vx_town_door_fixed_frame.a1)) == ((uint8_t)(71)))));
    vx_town_door_fixed_frame.result.v0 = ((uint8_t)((((((uint8_t)(vx_town_door_fixed_frame.a0)) == ((uint8_t)(45))) ? ((uint8_t)((((uint8_t)(vx_town_door_fixed_frame.a1)) == ((uint8_t)(52))))) : ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(((vx_town_door_fixed_frame.vxv_0 ? ((uint8_t)((((uint8_t)(vx_town_door_fixed_frame.a1)) == ((uint8_t)(53))))) : ((uint8_t)(0))) ? ((uint8_t)(2)) : ((uint8_t)((((((uint8_t)(vx_town_door_fixed_frame.a0)) == ((uint8_t)(48))) ? ((uint8_t)((((uint8_t)(vx_town_door_fixed_frame.a1)) == ((uint8_t)(57))))) : ((uint8_t)(0))) ? ((uint8_t)(3)) : ((uint8_t)((((((uint8_t)(vx_town_door_fixed_frame.a0)) == ((uint8_t)(53))) ? ((uint8_t)((((uint8_t)(vx_town_door_fixed_frame.a1)) == ((uint8_t)(73))))) : ((uint8_t)(0))) ? ((uint8_t)(4)) : ((uint8_t)(((vx_town_door_fixed_frame.vxv_1 ? ((uint8_t)((((uint8_t)(vx_town_door_fixed_frame.a1)) == ((uint8_t)(76))))) : ((uint8_t)(0))) ? ((uint8_t)(5)) : ((uint8_t)(((vx_town_door_fixed_frame.vxv_0 ? ((uint8_t)((((uint8_t)(vx_town_door_fixed_frame.a1)) == ((uint8_t)(67))))) : ((uint8_t)(0))) ? ((uint8_t)(6)) : ((uint8_t)(((vx_town_door_fixed_frame.vxv_1 ? ((uint8_t)((((uint8_t)(vx_town_door_fixed_frame.a1)) == ((uint8_t)(60))))) : ((uint8_t)(0))) ? ((uint8_t)(7)) : ((uint8_t)((((((uint8_t)(vx_town_door_fixed_frame.a0)) == ((uint8_t)(47))) ? ((uint8_t)((((uint8_t)(vx_town_door_fixed_frame.a1)) == ((uint8_t)(65))))) : ((uint8_t)(0))) ? ((uint8_t)(8)) : ((uint8_t)((((((uint8_t)(vx_town_door_fixed_frame.a0)) == ((uint8_t)(46))) ? ((uint8_t)(vx_town_door_fixed_frame.vxv_2)) : ((uint8_t)(0))) ? ((uint8_t)(9)) : ((uint8_t)(((vx_town_door_fixed_frame.vxv_1 ? ((uint8_t)(vx_town_door_fixed_frame.vxv_2)) : ((uint8_t)(0))) ? ((uint8_t)(10)) : ((uint8_t)(0))))))))))))))))))))))))))))))));
}
#endif
