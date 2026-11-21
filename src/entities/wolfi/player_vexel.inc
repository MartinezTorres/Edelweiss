#include "gameplay/player_motion.h"
#if EDW_PLAYER_REGION && !EDW_PLAYER_REGION_BANKED
#include "gameplay/player_motion.inc"
#endif
#include "vx_bind_player_weapon.h"
#include "vx_bind_player_attack.h"
#include "vx_bind_player_view.h"
#if !EDW_PLAYER_REGION
#include "vx_bind_player_keys.h"
#include "vx_bind_player_tick.h"
#include "vx_bind_player_move.h"
#include "vx_bind_player_slide.h"
#include "vx_bind_player_draw.h"
#endif
/* Each small binding is consumed before any engine call. Only ordinary continuation
 * values (tentative position, query stage) survive a map observation. */
static uint8_t player_control(Entity *entity) {
    static const uint8_t slots[]={ENTITY_SLASH,ENTITY_BOMB_0,ENTITY_BOMB_1,ENTITY_PROJECTILE_0,ENTITY_PROJECTILE_1};
    uint8_t n,flags=0;
    if(keyboard_click[4]&K_M) {
        VX_BIND_player_weapon_LOCAL;
        uint8_t mask=0;
        for(n=0;n<8;++n)if(state.has_weapon[n])mask|=(uint8_t)(1u<<n);
        vx_bind_player_weapon_frame.a0=state.weapon;vx_bind_player_weapon_frame.a1=mask;vx_bind_player_weapon_run();
        state.weapon=vx_bind_player_weapon_frame.result.v0;
        init_weapon();IN_MODULE(infobar,PAGE_B,infobar_update_weapon());
    }
    if(keyboard_click[8]&K_SPACE) {
        VX_BIND_player_attack_LOCAL;
        uint8_t free=0,choice;
        for(n=0;n<5;++n)if(state.entities[slots[n]].spawn_idx<0)free|=(uint8_t)(1u<<n);
        vx_bind_player_attack_frame.a0=state.weapon;vx_bind_player_attack_frame.a1=free;vx_bind_player_attack_run();
        choice=vx_bind_player_attack_frame.result.v0;
        if(choice)spawn_entity(slots[choice-1]);
    }
#if EDW_PLAYER_REGION
#if EDW_PLAYER_REGION_BANKED
    {
        uint8_t old=mapper_load_module(player_motion,PAGE_D);
        uint8_t view=player_motion_region(entity);
        mapper_load_segment(old,PAGE_D);
        return view;
    }
#else
    return player_motion_region(entity);
#endif
#else
    {
        VX_BIND_player_keys_LOCAL;
        vx_bind_player_keys_frame.a0=keyboard[8];vx_bind_player_keys_run();keyboard[8]=vx_bind_player_keys_frame.result.v0;
    }
    if(keyboard[8]==255) {
        sprites[0].pos=entity->pos;entity->animation_counter=0;return false;
    }
    for(n=0;n<state.isr_count_delta;++n) {
        VX_BIND_player_tick_LOCAL;
        uint8_t k;
        vx_bind_player_tick_frame.a0=entity->skip_23_frame;vx_bind_player_tick_frame.a1=entity->animation_counter;
        vx_bind_player_tick_run();
        entity->skip_23_frame=vx_bind_player_tick_frame.result.v0;entity->animation_counter=vx_bind_player_tick_frame.result.v1;
        if(!vx_bind_player_tick_frame.result.v2)continue;
        for(k=0;k<2;++k) {
            VX_BIND_player_move_LOCAL;
            uint16_tp tentative;
            uint16_t qi,qj;
            uint8_t stage=0,next;
            vx_bind_player_move_frame.a0=keyboard[8];vx_bind_player_move_frame.a1=entity->pos.i;
            vx_bind_player_move_frame.a2=entity->pos.j;vx_bind_player_move_run();
            tentative.i=vx_bind_player_move_frame.result.v0;tentative.j=vx_bind_player_move_frame.result.v1;
            qi=tentative.i;qj=tentative.j;
            do {
                VX_BIND_player_slide_LOCAL;
                flags=overworld_get_entity_flags(qi,qj);
                vx_bind_player_slide_frame.a0=stage;vx_bind_player_slide_frame.a1=flags&MAP_OBSTACLE;
                vx_bind_player_slide_frame.a2=entity->pos.i;vx_bind_player_slide_frame.a3=entity->pos.j;
                vx_bind_player_slide_frame.a4=tentative.i;vx_bind_player_slide_frame.a5=tentative.j;
                vx_bind_player_slide_run();
                entity->pos.i=vx_bind_player_slide_frame.result.v0;entity->pos.j=vx_bind_player_slide_frame.result.v1;
                qi=vx_bind_player_slide_frame.result.v2;qj=vx_bind_player_slide_frame.result.v3;
                next=vx_bind_player_slide_frame.result.v4;stage=next;
            } while(next);
        }
    }
    {
        VX_BIND_player_draw_LOCAL;
        vx_bind_player_draw_frame.a0=keyboard[8];vx_bind_player_draw_frame.a1=entity->animation_counter;
        vx_bind_player_draw_frame.a2=entity->orientation;vx_bind_player_draw_run();
        entity->orientation=vx_bind_player_draw_frame.result.v0;
        if(vx_bind_player_draw_frame.result.v1!=255)player_sprite(0,vx_bind_player_draw_frame.result.v1);
    }
    if(flags&MAP_TRIGGER)TRAMPOLINE_PAGE_C(wolfi_triggers);
    return true;
#endif
}
static void player_view(Entity *entity) {
    VX_BIND_player_view_LOCAL;
    vx_bind_player_view_frame.a0=entity->pos.i;vx_bind_player_view_frame.a1=entity->pos.j;
    vx_bind_player_view_frame.a2=map.pos.i;vx_bind_player_view_frame.a3=map.pos.j;
    vx_bind_player_view_frame.a4=state.target_map_pos.i;vx_bind_player_view_frame.a5=state.target_map_pos.j;
    vx_bind_player_view_frame.a6=state.request_scroll_update;vx_bind_player_view_run();
    state.target_map_pos.i=vx_bind_player_view_frame.result.v0;state.target_map_pos.j=vx_bind_player_view_frame.result.v1;
    state.request_scroll_update=vx_bind_player_view_frame.result.v2;
}
