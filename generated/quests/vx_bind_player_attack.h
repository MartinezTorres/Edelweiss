/* Selected C binding. Declare LOCAL in each owning scope, set all reported
 * inputs, run, and consume/copy results before reusing its workspace.
 * Case entries require the matching guard and one unchanged snapshot. */
#ifndef VX_BIND_player_attack_H
#define VX_BIND_player_attack_H
#include "vx_binding_types.h"
#include "vx_support_value_base.h"
#include "vx_binding_storage.h"
#define vx_bind_player_attack_frame (vx_binding_slot_0.binding_player_attack)
#define VX_BIND_player_attack_LOCAL /* fixed workspace */
static void vx_bind_player_attack_run(void) {
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_0[] = {
        0,2,3,2
    };
    /* Exhaustive byte-domain realization; immutable, bank-local ROM. */
    static const uint8_t vx_lut_1[] = {
        0,4,5,4
    };
    vx_bind_player_attack_frame.result.v0 = ((uint8_t)(((((uint8_t)(vx_bind_player_attack_frame.a0)) > ((uint8_t)(7))) ? ((uint8_t)(0)) : ((uint8_t)(((((uint8_t)(vx_bind_player_attack_frame.a0)) == ((uint8_t)(4))) ? ((uint8_t)(((uint8_t)(vx_lut_0[((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vx_bind_player_attack_frame.a1)) >> 1))))) & ((uint8_t)(3))))))])))) : ((uint8_t)((((((uint8_t)(vx_bind_player_attack_frame.a0)) == ((uint8_t)(5))) ? ((uint8_t)(1)) : ((uint8_t)((((uint8_t)(vx_bind_player_attack_frame.a0)) == ((uint8_t)(6)))))) ? ((uint8_t)(((uint8_t)(vx_lut_1[((uint8_t)(((uint8_t)(((uint8_t)(((uint8_t)((((uint8_t)(vx_bind_player_attack_frame.a1)) >> 3))))) & ((uint8_t)(3))))))])))) : ((uint8_t)(((((uint8_t)(((uint8_t)(((uint8_t)(vx_bind_player_attack_frame.a1)) & ((uint8_t)(1)))))) != ((uint8_t)(0))) ? ((uint8_t)(1)) : ((uint8_t)(0))))))))))))));
}
#endif
