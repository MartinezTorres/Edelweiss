#pragma once
#include "entities/wolfi/entity_wolfi_sprite.h"
#if EDW_VEXEL
#include "vx_sprite_assets.h"
#endif
/* Shared by normal controls, the intro and door transitions: changing from a
 * scripted animation to gameplay must replace the same pending request. */
static inline void player_sprite(uint8_t slot,uint8_t frame) {
#if EDW_VEXEL
    sprites[slot].spriteInfo=nullptr;
    sprites[slot].resourceRequest=edw_player_sprite(frame);
#else
    static const TSpriteInterlaced *const frames[]={&wolfi_0_0,&wolfi_0_1,&wolfi_1_0,&wolfi_1_1,
        &wolfi_2_0,&wolfi_2_1,&wolfi_3_0,&wolfi_3_1,&wolfi_4_0,&wolfi_4_1};
    sprites[slot].spriteInfo=frames[frame];
#endif
}
