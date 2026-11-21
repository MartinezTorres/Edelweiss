#ifndef VX_BINDING_TYPES_H
#define VX_BINDING_TYPES_H
#include "vexel.h"
#ifndef VX_VALUE_ball_home_RESULT
#define VX_VALUE_ball_home_RESULT
typedef struct {
    uint16_t v0; /* ball_home */
} vx_ball_home_result;
#endif
typedef struct {
    VX_STABLE uint16_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint16_t vxv_0;
    vx_ball_home_result result;
} vx_bind_ball_home_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_ball_home_size[sizeof(vx_bind_ball_home_frame_type)==8 ? 1 : -1];
#endif
#ifndef VX_VALUE_ball_leg_RESULT
#define VX_VALUE_ball_leg_RESULT
typedef struct {
    uint8_t v0; /* ball_leg.query */
    uint16_t v1; /* ball_leg.j */
    uint8_t v2; /* ball_leg.facing */
    uint8_t v3; /* ball_leg.counter */
} vx_ball_leg_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint16_t a2;
    VX_STABLE uint16_t a3;
    VX_STABLE uint8_t a4;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint16_t vxv_1;
    VX_STABLE uint16_t vxv_2;
    vx_ball_leg_result result;
} vx_bind_ball_leg_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_ball_leg_size[sizeof(vx_bind_ball_leg_frame_type)==17 ? 1 : -1];
#endif
#ifndef VX_VALUE_ball_reply_RESULT
#define VX_VALUE_ball_reply_RESULT
typedef struct {
    uint16_t v0; /* ball_reply.i */
    uint16_t v1; /* ball_reply.j */
    uint8_t v2; /* ball_reply.facing */
    uint8_t v3; /* ball_reply.counter */
} vx_ball_reply_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint16_t a2;
    VX_STABLE uint16_t a3;
    VX_STABLE uint16_t a4;
    VX_STABLE uint16_t a5;
    VX_STABLE uint8_t a6;
    VX_STABLE uint8_t a7;
    vx_ball_reply_result result;
} vx_bind_ball_reply_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_ball_reply_size[sizeof(vx_bind_ball_reply_frame_type)==18 ? 1 : -1];
#endif
#ifndef VX_VALUE_ball_tick_RESULT
#define VX_VALUE_ball_tick_RESULT
typedef struct {
    uint8_t v0; /* ball_tick.run */
    uint8_t v1; /* ball_tick.move */
    uint8_t v2; /* ball_tick.counter */
    uint8_t v3; /* ball_tick.frame */
} vx_ball_tick_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    vx_ball_tick_result result;
} vx_bind_ball_tick_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_ball_tick_size[sizeof(vx_bind_ball_tick_frame_type)==8 ? 1 : -1];
#endif
#ifndef VX_VALUE_bomb_cut_RESULT
#define VX_VALUE_bomb_cut_RESULT
typedef struct {
    uint8_t v0; /* bomb_cut */
} vx_bomb_cut_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    vx_bomb_cut_result result;
} vx_bind_bomb_cut_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_bomb_cut_size[sizeof(vx_bind_bomb_cut_frame_type)==2 ? 1 : -1];
#endif
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
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    VX_STABLE uint8_t vxv_2;
    VX_STABLE uint8_t vxv_3;
    VX_STABLE uint8_t vxv_4;
    vx_bomb_step_result result;
} vx_bind_bomb_step_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_bomb_step_size[sizeof(vx_bind_bomb_step_frame_type)==18 ? 1 : -1];
#endif
#ifndef VX_VALUE_combat_death_RESULT
#define VX_VALUE_combat_death_RESULT
typedef struct {
    uint8_t v0; /* combat_death.explosion */
    uint8_t v1; /* combat_death.drop */
} vx_combat_death_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    vx_combat_death_result result;
} vx_bind_combat_death_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_combat_death_size[sizeof(vx_bind_combat_death_frame_type)==6 ? 1 : -1];
#endif
#ifndef VX_VALUE_combat_hit_RESULT
#define VX_VALUE_combat_hit_RESULT
typedef struct {
    uint8_t v0; /* combat_hit.accepted */
    uint8_t v1; /* combat_hit.life */
    uint8_t v2; /* combat_hit.immunity */
    uint8_t v3; /* combat_hit.ticks */
    int8_t v4; /* combat_hit.di */
    int8_t v5; /* combat_hit.dj */
} vx_combat_hit_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE int16_t a3;
    VX_STABLE int16_t a4;
    VX_STABLE uint8_t a5;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint16_t vxv_1;
    VX_STABLE uint8_t vxv_2;
    VX_STABLE uint16_t vxv_3;
    VX_STABLE uint8_t vxv_4;
    vx_combat_hit_result result;
} vx_bind_combat_hit_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_combat_hit_size[sizeof(vx_bind_combat_hit_frame_type)==21 ? 1 : -1];
#endif
#ifndef VX_VALUE_combat_tick_RESULT
#define VX_VALUE_combat_tick_RESULT
typedef struct {
    uint8_t v0; /* combat_tick.status */
    uint8_t v1; /* combat_tick.immunity */
    uint8_t v2; /* combat_tick.ticks */
    uint8_t v3; /* combat_tick.steps */
    uint8_t v4; /* combat_tick.visible */
} vx_combat_tick_result;
#endif
typedef struct {
    vx_combat_tick_result result;
} vx_bind_combat_idle_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_combat_idle_size[sizeof(vx_bind_combat_idle_frame_type)==5 ? 1 : -1];
#endif
#ifndef VX_VALUE_combat_tick_RESULT
#define VX_VALUE_combat_tick_RESULT
typedef struct {
    uint8_t v0; /* combat_tick.status */
    uint8_t v1; /* combat_tick.immunity */
    uint8_t v2; /* combat_tick.ticks */
    uint8_t v3; /* combat_tick.steps */
    uint8_t v4; /* combat_tick.visible */
} vx_combat_tick_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    vx_combat_tick_result result;
} vx_bind_combat_tick_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_combat_tick_size[sizeof(vx_bind_combat_tick_frame_type)==11 ? 1 : -1];
#endif
#ifndef VX_VALUE_contact_box_RESULT
#define VX_VALUE_contact_box_RESULT
typedef struct {
    uint8_t v0; /* contact_box */
} vx_contact_box_result;
#endif
typedef struct {
    VX_STABLE uint16_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint16_t a2;
    VX_STABLE uint16_t a3;
    VX_STABLE uint8_t a4;
    VX_STABLE uint8_t a5;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    vx_contact_box_result result;
} vx_bind_contact_box_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_contact_box_size[sizeof(vx_bind_contact_box_frame_type)==13 ? 1 : -1];
#endif
#ifndef VX_VALUE_contact_player_RESULT
#define VX_VALUE_contact_player_RESULT
typedef struct {
    uint8_t v0; /* contact_player */
} vx_contact_player_result;
#endif
typedef struct {
    VX_STABLE uint16_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint16_t a2;
    VX_STABLE uint16_t a3;
    vx_contact_player_result result;
} vx_bind_contact_player_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_contact_player_size[sizeof(vx_bind_contact_player_frame_type)==9 ? 1 : -1];
#endif
#ifndef VX_VALUE_drop_collect_RESULT
#define VX_VALUE_drop_collect_RESULT
typedef struct {
    uint8_t v0; /* drop_collect.life */
    uint8_t v1; /* drop_collect.credit */
} vx_drop_collect_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t vxv_0;
    vx_drop_collect_result result;
} vx_bind_drop_collect_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_drop_collect_size[sizeof(vx_bind_drop_collect_frame_type)==6 ? 1 : -1];
#endif
#ifndef VX_VALUE_drop_roll_RESULT
#define VX_VALUE_drop_roll_RESULT
typedef struct {
    uint8_t v0; /* drop_roll.item */
    uint8_t v1; /* drop_roll.draw */
} vx_drop_roll_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint16_t a2;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    vx_drop_roll_result result;
} vx_bind_drop_roll_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_drop_roll_size[sizeof(vx_bind_drop_roll_frame_type)==8 ? 1 : -1];
#endif
#ifndef VX_VALUE_drop_spawn_RESULT
#define VX_VALUE_drop_spawn_RESULT
typedef struct {
    uint8_t v0; /* drop_spawn.enabled */
    uint8_t v1; /* drop_spawn.frame */
} vx_drop_spawn_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    vx_drop_spawn_result result;
} vx_bind_drop_spawn_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_drop_spawn_size[sizeof(vx_bind_drop_spawn_frame_type)==3 ? 1 : -1];
#endif
#ifndef VX_VALUE_drop_step_RESULT
#define VX_VALUE_drop_step_RESULT
typedef struct {
    uint8_t v0; /* drop_step.live */
    uint8_t v1; /* drop_step.counter */
    uint8_t v2; /* drop_step.visible */
} vx_drop_step_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    vx_drop_step_result result;
} vx_bind_drop_step_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_drop_step_size[sizeof(vx_bind_drop_step_frame_type)==8 ? 1 : -1];
#endif
#ifndef VX_VALUE_effect_step_RESULT
#define VX_VALUE_effect_step_RESULT
typedef struct {
    uint8_t v0; /* effect_step.live */
    uint8_t v1; /* effect_step.counter */
    uint8_t v2; /* effect_step.frame */
} vx_effect_step_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t vxv_0;
    vx_effect_step_result result;
} vx_bind_effect_step_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_effect_step_size[sizeof(vx_bind_effect_step_frame_type)==6 ? 1 : -1];
#endif
#ifndef VX_VALUE_fairy_move_RESULT
#define VX_VALUE_fairy_move_RESULT
typedef struct {
    uint16_t v0; /* fairy_move */
} vx_fairy_move_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    vx_fairy_move_result result;
} vx_bind_fairy_move_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_fairy_move_size[sizeof(vx_bind_fairy_move_frame_type)==4 ? 1 : -1];
#endif
#ifndef VX_VALUE_ghost_update_RESULT
#define VX_VALUE_ghost_update_RESULT
typedef struct {
    uint8_t v0; /* ghost_update.run */
    uint8_t v1; /* ghost_update.life */
    uint16_t v2; /* ghost_update.i */
    uint16_t v3; /* ghost_update.j */
    int8_t v4; /* ghost_update.vi */
    int8_t v5; /* ghost_update.vj */
    uint8_t v6; /* ghost_update.frame */
} vx_ghost_update_result;
#endif
typedef struct {
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint16_t a3;
    VX_STABLE uint16_t a4;
    VX_STABLE uint16_t a5;
    VX_STABLE uint16_t a6;
    VX_STABLE int8_t a7;
    VX_STABLE int8_t a8;
    VX_STABLE uint16_t a9;
    VX_STABLE uint16_t a10;
    VX_STABLE uint16_t vxv_0;
    VX_STABLE int8_t vxv_1;
    VX_STABLE int8_t vxv_2;
    vx_ghost_update_result result;
} vx_bind_ghost_move_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_ghost_move_size[sizeof(vx_bind_ghost_move_frame_type)==29 ? 1 : -1];
#endif
#ifndef VX_VALUE_ghost_spawn_RESULT
#define VX_VALUE_ghost_spawn_RESULT
typedef struct {
    uint16_t v0; /* ghost_spawn.i */
    uint16_t v1; /* ghost_spawn.j */
    int8_t v2; /* ghost_spawn.vi */
    int8_t v3; /* ghost_spawn.vj */
} vx_ghost_spawn_result;
#endif
typedef struct {
    VX_STABLE uint16_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint8_t a2;
    vx_ghost_spawn_result result;
} vx_bind_ghost_spawn_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_ghost_spawn_size[sizeof(vx_bind_ghost_spawn_frame_type)==11 ? 1 : -1];
#endif
#ifndef VX_VALUE_lumber_draw_RESULT
#define VX_VALUE_lumber_draw_RESULT
typedef struct {
    uint8_t v0; /* lumber_draw.facing */
    uint8_t v1; /* lumber_draw.frame */
} vx_lumber_draw_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    vx_lumber_draw_result result;
} vx_bind_lumber_draw_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_lumber_draw_size[sizeof(vx_bind_lumber_draw_frame_type)==7 ? 1 : -1];
#endif
#ifndef VX_VALUE_melee_axe_RESULT
#define VX_VALUE_melee_axe_RESULT
typedef struct {
    uint16_t v0; /* melee_axe.i */
    uint16_t v1; /* melee_axe.j */
} vx_melee_axe_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint16_t a2;
    vx_melee_axe_result result;
} vx_bind_melee_axe_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_melee_axe_size[sizeof(vx_bind_melee_axe_frame_type)==9 ? 1 : -1];
#endif
#ifndef VX_VALUE_melee_cut_RESULT
#define VX_VALUE_melee_cut_RESULT
typedef struct {
    uint8_t v0; /* melee_cut */
} vx_melee_cut_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    vx_melee_cut_result result;
} vx_bind_melee_cut_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_melee_cut_size[sizeof(vx_bind_melee_cut_frame_type)==2 ? 1 : -1];
#endif
#ifndef VX_VALUE_melee_hit_RESULT
#define VX_VALUE_melee_hit_RESULT
typedef struct {
    uint16_t v0; /* melee_hit.i */
    uint16_t v1; /* melee_hit.j */
    uint8_t v2; /* melee_hit.height */
    uint8_t v3; /* melee_hit.width */
} vx_melee_hit_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint16_t a2;
    VX_STABLE uint16_t a3;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    VX_STABLE uint8_t vxv_2;
    VX_STABLE uint8_t vxv_3;
    vx_melee_hit_result result;
} vx_bind_melee_hit_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_melee_hit_size[sizeof(vx_bind_melee_hit_frame_type)==16 ? 1 : -1];
#endif
#ifndef VX_VALUE_melee_style_RESULT
#define VX_VALUE_melee_style_RESULT
typedef struct {
    uint8_t v0; /* melee_style.damage */
    uint8_t v1; /* melee_style.override */
    uint8_t v2; /* melee_style.color0 */
    uint8_t v3; /* melee_style.color1 */
    uint8_t v4; /* melee_style.axe */
} vx_melee_style_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    vx_melee_style_result result;
} vx_bind_melee_style_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_melee_style_size[sizeof(vx_bind_melee_style_frame_type)==6 ? 1 : -1];
#endif
#ifndef VX_VALUE_melee_update_RESULT
#define VX_VALUE_melee_update_RESULT
typedef struct {
    uint8_t v0; /* melee_update.live */
    uint8_t v1; /* melee_update.apply */
    uint8_t v2; /* melee_update.counter */
    uint16_t v3; /* melee_update.i */
    uint16_t v4; /* melee_update.j */
    uint8_t v5; /* melee_update.frame */
    uint8_t v6; /* melee_update.small */
} vx_melee_update_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    VX_STABLE uint16_t a4;
    VX_STABLE uint16_t a5;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    VX_STABLE uint8_t vxv_2;
    VX_STABLE uint8_t vxv_3;
    VX_STABLE uint8_t vxv_4;
    VX_STABLE uint8_t vxv_5;
    vx_melee_update_result result;
} vx_bind_melee_update_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_melee_update_size[sizeof(vx_bind_melee_update_frame_type)==23 ? 1 : -1];
#endif
#ifndef VX_VALUE_player_attack_RESULT
#define VX_VALUE_player_attack_RESULT
typedef struct {
    uint8_t v0; /* player_attack */
} vx_player_attack_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    vx_player_attack_result result;
} vx_bind_player_attack_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_player_attack_size[sizeof(vx_bind_player_attack_frame_type)==3 ? 1 : -1];
#endif
#ifndef VX_VALUE_player_draw_RESULT
#define VX_VALUE_player_draw_RESULT
typedef struct {
    uint8_t v0; /* player_draw.facing */
    uint8_t v1; /* player_draw.frame */
} vx_player_draw_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    VX_STABLE uint8_t vxv_2;
    vx_player_draw_result result;
} vx_bind_player_draw_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_player_draw_size[sizeof(vx_bind_player_draw_frame_type)==8 ? 1 : -1];
#endif
#ifndef VX_VALUE_player_keys_RESULT
#define VX_VALUE_player_keys_RESULT
typedef struct {
    uint8_t v0; /* player_keys */
} vx_player_keys_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t vxv_0;
    vx_player_keys_result result;
} vx_bind_player_keys_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_player_keys_size[sizeof(vx_bind_player_keys_frame_type)==3 ? 1 : -1];
#endif
typedef struct {
    VX_STABLE uint16_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    VX_STABLE uint8_t a4;
    VX_STABLE uint8_t a5;
    VX_STABLE uint8_t a6;
    VX_STABLE uint16_t a7;
    VX_STABLE uint16_t a8;
    VX_STABLE uint16_t r0;
    VX_STABLE uint16_t r1;
    VX_STABLE uint8_t r2;
    VX_STABLE uint8_t r3;
    VX_STABLE uint8_t r4;
    VX_STABLE uint8_t r5;
    VX_STABLE uint8_t r6;
    VX_STABLE uint8_t r7;
} vx_bind_player_motion_boundary_motion_query_type;
#ifndef VX_VALUE_player_motion_RESULT
#define VX_VALUE_player_motion_RESULT
typedef struct {
    uint16_t v0; /* player_motion.m.i */
    uint16_t v1; /* player_motion.m.j */
    uint8_t v2; /* player_motion.m.keys */
    uint8_t v3; /* player_motion.m.elapsed */
    uint8_t v4; /* player_motion.m.skip */
    uint8_t v5; /* player_motion.m.counter */
    uint8_t v6; /* player_motion.m.facing */
    uint8_t v7; /* player_motion.flags */
    uint8_t v8; /* player_motion.frame */
    uint8_t v9; /* player_motion.view */
} vx_player_motion_result;
#endif
typedef struct {
    VX_STABLE uint16_t a0_0;
    VX_STABLE uint16_t a0_1;
    VX_STABLE uint8_t a0_2;
    VX_STABLE uint8_t a0_3;
    VX_STABLE uint8_t a0_4;
    VX_STABLE uint8_t a0_5;
    VX_STABLE uint8_t a0_6;
    VX_STABLE uint8_t l2_s14616_v0;
    VX_STABLE uint8_t l3_s20180_v0;
    VX_STABLE uint16_t l5_s22657_v0;
    VX_STABLE uint16_t l5_s22659_v0;
    VX_STABLE uint8_t l5_s22661_v0;
    VX_STABLE uint8_t l5_s22663_v0;
    VX_STABLE uint8_t tmp_expr_uint8_t_0;
    VX_STABLE uint8_t tmp_expr_uint8_t_1;
    VX_STABLE uint8_t tmp_expr_uint8_t_2;
    VX_STABLE uint8_t tmp_test_uint8_t_0;
    vx_bind_player_motion_boundary_motion_query_type boundary_motion_query;
    vx_player_motion_result result;
} vx_bind_player_motion_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_player_motion_size[sizeof(vx_bind_player_motion_frame_type)==56 ? 1 : -1];
#endif
#ifndef VX_VALUE_player_move_RESULT
#define VX_VALUE_player_move_RESULT
typedef struct {
    uint16_t v0; /* player_move.i */
    uint16_t v1; /* player_move.j */
} vx_player_move_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint16_t a2;
    vx_player_move_result result;
} vx_bind_player_move_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_player_move_size[sizeof(vx_bind_player_move_frame_type)==9 ? 1 : -1];
#endif
#ifndef VX_VALUE_player_slide_RESULT
#define VX_VALUE_player_slide_RESULT
typedef struct {
    uint16_t v0; /* player_slide.i */
    uint16_t v1; /* player_slide.j */
    uint16_t v2; /* player_slide.qi */
    uint16_t v3; /* player_slide.qj */
    uint8_t v4; /* player_slide.query */
} vx_player_slide_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint16_t a2;
    VX_STABLE uint16_t a3;
    VX_STABLE uint16_t a4;
    VX_STABLE uint16_t a5;
    vx_player_slide_result result;
} vx_bind_player_slide_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_player_slide_size[sizeof(vx_bind_player_slide_frame_type)==19 ? 1 : -1];
#endif
#ifndef VX_VALUE_player_tick_RESULT
#define VX_VALUE_player_tick_RESULT
typedef struct {
    uint8_t v0; /* player_tick.skip */
    uint8_t v1; /* player_tick.counter */
    uint8_t v2; /* player_tick.move */
} vx_player_tick_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t vxv_0;
    vx_player_tick_result result;
} vx_bind_player_tick_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_player_tick_size[sizeof(vx_bind_player_tick_frame_type)==6 ? 1 : -1];
#endif
#ifndef VX_VALUE_player_view_RESULT
#define VX_VALUE_player_view_RESULT
typedef struct {
    uint8_t v0; /* player_view.i */
    uint8_t v1; /* player_view.j */
    uint8_t v2; /* player_view.request */
} vx_player_view_result;
#endif
typedef struct {
    VX_STABLE uint16_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    VX_STABLE uint8_t a4;
    VX_STABLE uint8_t a5;
    VX_STABLE uint8_t a6;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    VX_STABLE uint8_t vxv_2;
    vx_player_view_result result;
} vx_bind_player_view_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_player_view_size[sizeof(vx_bind_player_view_frame_type)==15 ? 1 : -1];
#endif
#ifndef VX_VALUE_player_weapon_RESULT
#define VX_VALUE_player_weapon_RESULT
typedef struct {
    uint8_t v0; /* player_weapon */
} vx_player_weapon_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    vx_player_weapon_result result;
} vx_bind_player_weapon_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_player_weapon_size[sizeof(vx_bind_player_weapon_frame_type)==5 ? 1 : -1];
#endif
#ifndef VX_VALUE_projectile_move_RESULT
#define VX_VALUE_projectile_move_RESULT
typedef struct {
    uint16_t v0; /* projectile_move.i */
    uint16_t v1; /* projectile_move.j */
    uint8_t v2; /* projectile_move.counter */
    uint8_t v3; /* projectile_move.frame */
} vx_projectile_move_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint16_t a2;
    VX_STABLE int8_t a3;
    VX_STABLE int8_t a4;
    VX_STABLE uint8_t a5;
    VX_STABLE uint8_t a6;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    VX_STABLE uint8_t vxv_2;
    VX_STABLE uint8_t vxv_3;
    VX_STABLE uint8_t vxv_4;
    vx_projectile_move_result result;
} vx_bind_projectile_move_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_projectile_move_size[sizeof(vx_bind_projectile_move_frame_type)==20 ? 1 : -1];
#endif
#ifndef VX_VALUE_projectile_spawn_RESULT
#define VX_VALUE_projectile_spawn_RESULT
typedef struct {
    uint16_t v0; /* projectile_spawn.i */
    uint16_t v1; /* projectile_spawn.j */
    int8_t v2; /* projectile_spawn.vi */
    int8_t v3; /* projectile_spawn.vj */
    uint8_t v4; /* projectile_spawn.frame */
    uint8_t v5; /* projectile_spawn.damage */
} vx_projectile_spawn_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint16_t a2;
    VX_STABLE uint16_t a3;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE int8_t vxv_1;
    VX_STABLE uint8_t vxv_2;
    VX_STABLE uint8_t vxv_3;
    VX_STABLE int8_t vxv_4;
    VX_STABLE int8_t vxv_5;
    vx_projectile_spawn_result result;
} vx_bind_projectile_spawn_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_projectile_spawn_size[sizeof(vx_bind_projectile_spawn_frame_type)==20 ? 1 : -1];
#endif
#ifndef VX_VALUE_scene_brief_RESULT
#define VX_VALUE_scene_brief_RESULT
typedef struct {
    uint8_t v0; /* scene_brief.text */
    uint8_t v1; /* scene_brief.next */
    uint8_t v2; /* scene_brief.marker */
    uint8_t v3; /* scene_brief.i */
    uint8_t v4; /* scene_brief.j */
} vx_scene_brief_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t vxv_0;
    vx_scene_brief_result result;
} vx_bind_scene_brief_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_scene_brief_size[sizeof(vx_bind_scene_brief_frame_type)==7 ? 1 : -1];
#endif
#ifndef VX_VALUE_scene_camera_RESULT
#define VX_VALUE_scene_camera_RESULT
typedef struct {
    uint8_t v0; /* scene_camera.i */
    uint8_t v1; /* scene_camera.j */
    uint8_t v2; /* scene_camera.request */
} vx_scene_camera_result;
#endif
typedef struct {
    VX_STABLE uint16_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    VX_STABLE uint8_t a4;
    VX_STABLE uint8_t a5;
    VX_STABLE uint8_t a6;
    VX_STABLE int16_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    VX_STABLE int16_t vxv_2;
    VX_STABLE uint8_t vxv_3;
    vx_scene_camera_result result;
} vx_bind_scene_camera_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_scene_camera_size[sizeof(vx_bind_scene_camera_frame_type)==18 ? 1 : -1];
#endif
#ifndef VX_VALUE_scene_door_RESULT
#define VX_VALUE_scene_door_RESULT
typedef struct {
    uint8_t v0; /* scene_door.op */
    uint16_t v1; /* scene_door.i */
    uint16_t v2; /* scene_door.j */
    uint8_t v3; /* scene_door.facing */
    uint8_t v4; /* scene_door.frame */
    uint8_t v5; /* scene_door.waits */
} vx_scene_door_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint16_t a2;
    VX_STABLE uint16_t a3;
    VX_STABLE uint8_t a4;
    VX_STABLE uint8_t vxv_0;
    vx_scene_door_result result;
} vx_bind_scene_door_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_scene_door_size[sizeof(vx_bind_scene_door_frame_type)==16 ? 1 : -1];
#endif
#ifndef VX_VALUE_scene_intro_RESULT
#define VX_VALUE_scene_intro_RESULT
typedef struct {
    uint8_t v0; /* scene_intro.action */
    uint8_t v1; /* scene_intro.movie */
    uint8_t v2; /* scene_intro.counter */
    uint16_t v3; /* scene_intro.i */
    uint16_t v4; /* scene_intro.j */
    uint8_t v5; /* scene_intro.facing */
    uint8_t v6; /* scene_intro.frame */
    uint8_t v7; /* scene_intro.again */
} vx_scene_intro_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint16_t a2;
    VX_STABLE uint16_t a3;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    vx_scene_intro_result result;
} vx_bind_scene_intro_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_scene_intro_size[sizeof(vx_bind_scene_intro_frame_type)==18 ? 1 : -1];
#endif
#ifndef VX_VALUE_scene_revive_RESULT
#define VX_VALUE_scene_revive_RESULT
typedef struct {
    uint8_t v0; /* scene_revive */
} vx_scene_revive_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t vxv_0;
    vx_scene_revive_result result;
} vx_bind_scene_revive_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_scene_revive_size[sizeof(vx_bind_scene_revive_frame_type)==3 ? 1 : -1];
#endif
#ifndef VX_VALUE_scene_spark_RESULT
#define VX_VALUE_scene_spark_RESULT
typedef struct {
    uint8_t v0; /* scene_spark.slot */
    uint8_t v1; /* scene_spark.i */
    uint8_t v2; /* scene_spark.j */
    uint8_t v3; /* scene_spark.initialize */
    uint8_t v4; /* scene_spark.statue */
} vx_scene_spark_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t vxv_0;
    vx_scene_spark_result result;
} vx_bind_scene_spark_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_scene_spark_size[sizeof(vx_bind_scene_spark_frame_type)==8 ? 1 : -1];
#endif
#ifndef VX_VALUE_scene_wipe_RESULT
#define VX_VALUE_scene_wipe_RESULT
typedef struct {
    uint8_t v0; /* scene_wipe.op */
    uint8_t v1; /* scene_wipe.arg */
    uint8_t v2; /* scene_wipe.round */
    uint8_t v3; /* scene_wipe.step */
} vx_scene_wipe_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    vx_scene_wipe_result result;
} vx_bind_scene_wipe_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_scene_wipe_size[sizeof(vx_bind_scene_wipe_frame_type)==9 ? 1 : -1];
#endif
#ifndef VX_VALUE_skeleti_draws_RESULT
#define VX_VALUE_skeleti_draws_RESULT
typedef struct {
    uint8_t v0; /* skeleti_draws */
} vx_skeleti_draws_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    vx_skeleti_draws_result result;
} vx_bind_skeleti_draws_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_skeleti_draws_size[sizeof(vx_bind_skeleti_draws_frame_type)==4 ? 1 : -1];
#endif
#ifndef VX_VALUE_skeleti_update_RESULT
#define VX_VALUE_skeleti_update_RESULT
typedef struct {
    uint8_t v0; /* skeleti_update.action */
    uint8_t v1; /* skeleti_update.delay */
    uint16_t v2; /* skeleti_update.i */
    uint16_t v3; /* skeleti_update.j */
    uint8_t v4; /* skeleti_update.frame */
} vx_skeleti_update_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    VX_STABLE uint8_t a4;
    VX_STABLE uint16_t a5;
    VX_STABLE uint16_t a6;
    VX_STABLE uint16_t a7;
    VX_STABLE uint16_t a8;
    VX_STABLE uint16_t a9;
    VX_STABLE uint16_t a10;
    VX_STABLE uint8_t a11;
    vx_skeleti_update_result result;
} vx_bind_skeleti_move_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_skeleti_move_size[sizeof(vx_bind_skeleti_move_frame_type)==24 ? 1 : -1];
#endif
#ifndef VX_VALUE_skeleti_tick_RESULT
#define VX_VALUE_skeleti_tick_RESULT
typedef struct {
    uint8_t v0; /* skeleti_tick */
} vx_skeleti_tick_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    vx_skeleti_tick_result result;
} vx_bind_skeleti_tick_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_skeleti_tick_size[sizeof(vx_bind_skeleti_tick_frame_type)==3 ? 1 : -1];
#endif
#ifndef VX_VALUE_skeleti_update_RESULT
#define VX_VALUE_skeleti_update_RESULT
typedef struct {
    uint8_t v0; /* skeleti_update.action */
    uint8_t v1; /* skeleti_update.delay */
    uint16_t v2; /* skeleti_update.i */
    uint16_t v3; /* skeleti_update.j */
    uint8_t v4; /* skeleti_update.frame */
} vx_skeleti_update_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint16_t a5;
    VX_STABLE uint16_t a6;
    vx_skeleti_update_result result;
} vx_bind_skeleti_wait_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_skeleti_wait_size[sizeof(vx_bind_skeleti_wait_frame_type)==14 ? 1 : -1];
#endif
#ifndef VX_VALUE_spark_frame_RESULT
#define VX_VALUE_spark_frame_RESULT
typedef struct {
    uint8_t v0; /* spark_frame */
} vx_spark_frame_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    vx_spark_frame_result result;
} vx_bind_spark_frame_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_spark_frame_size[sizeof(vx_bind_spark_frame_frame_type)==3 ? 1 : -1];
#endif
#ifndef VX_VALUE_title_attract_RESULT
#define VX_VALUE_title_attract_RESULT
typedef struct {
    uint8_t v0; /* title_attract.ticks */
    uint8_t v1; /* title_attract.poll */
    uint8_t v2; /* title_attract.keys */
    uint8_t v3; /* title_attract.quit */
} vx_title_attract_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    vx_title_attract_result result;
} vx_bind_title_attract_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_title_attract_size[sizeof(vx_bind_title_attract_frame_type)==9 ? 1 : -1];
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t r0;
} vx_bind_title_flow_boundary_flow_despawn_type;
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE int8_t r0;
} vx_bind_title_flow_boundary_flow_slot_type;
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t r0;
} vx_bind_title_flow_boundary_flow_update_type;
#ifndef VX_VALUE_title_flow_RESULT
#define VX_VALUE_title_flow_RESULT
typedef struct {
    uint8_t v0; /* title_flow */
} vx_title_flow_result;
#endif
typedef struct {
    union {
        vx_bind_title_flow_boundary_flow_despawn_type boundary_flow_despawn;
        vx_bind_title_flow_boundary_flow_update_type boundary_flow_update;
    } boundary_slot_0;
    vx_bind_title_flow_boundary_flow_slot_type boundary_flow_slot;
    vx_title_flow_result result;
} vx_bind_title_flow_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_title_flow_size[sizeof(vx_bind_title_flow_frame_type)==5 ? 1 : -1];
#endif
#ifndef VX_VALUE_title_frame_RESULT
#define VX_VALUE_title_frame_RESULT
typedef struct {
    uint8_t v0; /* title_frame.clock */
    uint8_t v1; /* title_frame.spawn */
    uint8_t v2; /* title_frame.skip */
} vx_title_frame_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t vxv_0;
    vx_title_frame_result result;
} vx_bind_title_frame_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_title_frame_size[sizeof(vx_bind_title_frame_frame_type)==6 ? 1 : -1];
#endif
#ifndef VX_VALUE_title_seed_RESULT
#define VX_VALUE_title_seed_RESULT
typedef struct {
    uint8_t v0; /* title_seed.accept */
    uint16_t v1; /* title_seed.position */
    uint8_t v2; /* title_seed.kind */
} vx_title_seed_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t vxv_0;
    vx_title_seed_result result;
} vx_bind_title_seed_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_title_seed_size[sizeof(vx_bind_title_seed_frame_type)==8 ? 1 : -1];
#endif
#ifndef VX_VALUE_title_step_RESULT
#define VX_VALUE_title_step_RESULT
typedef struct {
    uint8_t v0; /* title_step.op */
    uint8_t v1; /* title_step.a */
    uint8_t v2; /* title_step.b */
    uint8_t v3; /* title_step.phase */
    uint8_t v4; /* title_step.round */
    uint8_t v5; /* title_step.step */
} vx_title_step_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    VX_STABLE uint8_t vxv_2;
    vx_title_step_result result;
} vx_bind_title_step_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_title_step_size[sizeof(vx_bind_title_step_frame_type)==13 ? 1 : -1];
#endif
#ifndef VX_VALUE_ui_cursor_RESULT
#define VX_VALUE_ui_cursor_RESULT
typedef struct {
    uint8_t v0; /* ui_cursor.x */
    uint8_t v1; /* ui_cursor.y */
} vx_ui_cursor_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t vxv_0;
    vx_ui_cursor_result result;
} vx_bind_ui_cursor_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_ui_cursor_size[sizeof(vx_bind_ui_cursor_frame_type)==5 ? 1 : -1];
#endif
#ifndef VX_VALUE_ui_editor_RESULT
#define VX_VALUE_ui_editor_RESULT
typedef struct {
    uint8_t v0; /* ui_editor.length */
    uint8_t v1; /* ui_editor.character */
    uint8_t v2; /* ui_editor.accept */
    uint8_t v3; /* ui_editor.done */
    uint8_t v4; /* ui_editor.cursor */
} vx_ui_editor_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    vx_ui_editor_result result;
} vx_bind_ui_editor_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_ui_editor_size[sizeof(vx_bind_ui_editor_frame_type)==10 ? 1 : -1];
#endif
#ifndef VX_VALUE_ui_menu_RESULT
#define VX_VALUE_ui_menu_RESULT
typedef struct {
    uint8_t v0; /* ui_menu.option */
    uint8_t v1; /* ui_menu.confirm */
} vx_ui_menu_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    vx_ui_menu_result result;
} vx_bind_ui_menu_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_ui_menu_size[sizeof(vx_bind_ui_menu_frame_type)==8 ? 1 : -1];
#endif
#ifndef VX_VALUE_weapon_setup_RESULT
#define VX_VALUE_weapon_setup_RESULT
typedef struct {
    uint8_t v0; /* weapon_setup.kind */
    uint8_t v1; /* weapon_setup.slot */
} vx_weapon_setup_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t vxv_0;
    vx_weapon_setup_result result;
} vx_bind_weapon_setup_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_weapon_setup_size[sizeof(vx_bind_weapon_setup_frame_type)==5 ? 1 : -1];
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t r0;
    VX_STABLE uint8_t r1;
    VX_STABLE uint8_t r2;
    VX_STABLE uint8_t r3;
} vx_bind_world_flow_boundary_flow_actor_type;
typedef struct {
    VX_STABLE uint8_t r0;
} vx_bind_world_flow_boundary_flow_cycle_type;
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t r0;
} vx_bind_world_flow_boundary_flow_despawn_type;
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t r0;
    VX_STABLE int8_t r1;
} vx_bind_world_flow_boundary_flow_flags_type;
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE int8_t r0;
} vx_bind_world_flow_boundary_flow_slot_type;
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t r0;
} vx_bind_world_flow_boundary_flow_spawn_type;
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t r0;
} vx_bind_world_flow_boundary_flow_update_type;
typedef struct {
    VX_STABLE uint8_t r0;
} vx_bind_world_flow_boundary_flow_yield_type;
#ifndef VX_VALUE_world_flow_RESULT
#define VX_VALUE_world_flow_RESULT
typedef struct {
    uint8_t v0; /* world_flow */
} vx_world_flow_result;
#endif
typedef struct {
    VX_STABLE uint8_t l4_s30083_v0;
    VX_STABLE uint8_t l4_s3466_v0;
    union {
        vx_bind_world_flow_boundary_flow_actor_type boundary_flow_actor;
        vx_bind_world_flow_boundary_flow_despawn_type boundary_flow_despawn;
        vx_bind_world_flow_boundary_flow_flags_type boundary_flow_flags;
        vx_bind_world_flow_boundary_flow_spawn_type boundary_flow_spawn;
        vx_bind_world_flow_boundary_flow_update_type boundary_flow_update;
        vx_bind_world_flow_boundary_flow_yield_type boundary_flow_yield;
    } boundary_slot_0;
    vx_bind_world_flow_boundary_flow_cycle_type boundary_flow_cycle;
    vx_bind_world_flow_boundary_flow_slot_type boundary_flow_slot;
    vx_world_flow_result result;
} vx_bind_world_flow_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_world_flow_size[sizeof(vx_bind_world_flow_frame_type)==11 ? 1 : -1];
#endif
#ifndef VX_VALUE_world_follow_RESULT
#define VX_VALUE_world_follow_RESULT
typedef struct {
    uint8_t v0; /* world_follow */
} vx_world_follow_result;
#endif
typedef struct {
    VX_STABLE uint16_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint16_t a2;
    VX_STABLE uint16_t a3;
    VX_STABLE uint8_t a4;
    VX_STABLE uint8_t a5;
    vx_world_follow_result result;
} vx_bind_world_follow_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_world_follow_size[sizeof(vx_bind_world_follow_frame_type)==11 ? 1 : -1];
#endif
#ifndef VX_VALUE_world_frame_RESULT
#define VX_VALUE_world_frame_RESULT
typedef struct {
    uint8_t v0; /* world_frame.elapsed */
    uint8_t v1; /* world_frame.cycle */
} vx_world_frame_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t vxv_0;
    vx_world_frame_result result;
} vx_bind_world_frame_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_world_frame_size[sizeof(vx_bind_world_frame_frame_type)==6 ? 1 : -1];
#endif
#ifndef VX_VALUE_world_window_RESULT
#define VX_VALUE_world_window_RESULT
typedef struct {
    uint8_t v0; /* world_window */
} vx_world_window_result;
#endif
typedef struct {
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    VX_STABLE uint8_t a4;
    vx_world_window_result result;
} vx_bind_world_keep_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_world_keep_size[sizeof(vx_bind_world_keep_frame_type)==5 ? 1 : -1];
#endif
#ifndef VX_VALUE_world_scroll_RESULT
#define VX_VALUE_world_scroll_RESULT
typedef struct {
    uint8_t v0; /* world_scroll.i */
    uint8_t v1; /* world_scroll.j */
    uint8_t v2; /* world_scroll.row */
    uint8_t v3; /* world_scroll.col */
    uint8_t v4; /* world_scroll.second */
    uint8_t v5; /* world_scroll.transfer */
} vx_world_scroll_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    VX_STABLE uint8_t a4;
    vx_world_scroll_result result;
} vx_bind_world_scroll_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_world_scroll_size[sizeof(vx_bind_world_scroll_frame_type)==11 ? 1 : -1];
#endif
#ifndef VX_VALUE_world_seed_RESULT
#define VX_VALUE_world_seed_RESULT
typedef struct {
    uint8_t v0; /* world_seed.kind */
    uint8_t v1; /* world_seed.slot */
    uint8_t v2; /* world_seed.i */
    uint8_t v3; /* world_seed.j */
} vx_world_seed_result;
#endif
typedef struct {
    VX_STABLE uint8_t a0;
    vx_world_seed_result result;
} vx_bind_world_seed_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_world_seed_size[sizeof(vx_bind_world_seed_frame_type)==5 ? 1 : -1];
#endif
#ifndef VX_VALUE_world_window_RESULT
#define VX_VALUE_world_window_RESULT
typedef struct {
    uint8_t v0; /* world_window */
} vx_world_window_result;
#endif
typedef struct {
    VX_STABLE uint8_t a1;
    VX_STABLE uint8_t a2;
    VX_STABLE uint8_t a3;
    VX_STABLE uint8_t a4;
    VX_STABLE uint8_t vxv_0;
    VX_STABLE uint8_t vxv_1;
    vx_world_window_result result;
} vx_bind_world_spawn_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_world_spawn_size[sizeof(vx_bind_world_spawn_frame_type)==7 ? 1 : -1];
#endif
#ifndef VX_VALUE_world_start_RESULT
#define VX_VALUE_world_start_RESULT
typedef struct {
    uint8_t v0; /* world_start.coins */
    uint8_t v1; /* world_start.weapon */
    uint8_t v2; /* world_start.flower_i */
    uint8_t v3; /* world_start.flower_j */
    uint8_t v4; /* world_start.mi */
    uint8_t v5; /* world_start.mj */
    uint16_t v6; /* world_start.patch_i */
    uint16_t v7; /* world_start.patch_next_i */
    uint16_t v8; /* world_start.patch_j */
    uint8_t v9; /* world_start.patch_value */
} vx_world_start_result;
#endif
typedef struct {
    VX_STABLE uint16_t a0;
    VX_STABLE uint16_t a1;
    VX_STABLE uint8_t vxv_0;
    vx_world_start_result result;
} vx_bind_world_start_frame_type;
#ifdef __SDCC_z80
typedef char vx_bind_world_start_size[sizeof(vx_bind_world_start_frame_type)==18 ? 1 : -1];
#endif
#endif
