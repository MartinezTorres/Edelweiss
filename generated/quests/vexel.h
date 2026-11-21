#ifndef VX_RELATIONAL_SOURCE_H
#define VX_RELATIONAL_SOURCE_H
#include "vx_runtime.h"
/* Preserve residual roots across SDCC byte arithmetic; see docs/sdcc-operands.md. */
#ifdef __SDCC
#define VX_STABLE volatile
#define VX_SNAPSHOT8(x) (*(volatile uint8_t *)&(x))
#define VX_SNAPSHOT16(x) (*(volatile uint16_t *)&(x))
#define VX_SNAPSHOT32(x) (*(volatile uint32_t *)&(x))
#else
#define VX_STABLE
#define VX_SNAPSHOT8(x) (x)
#define VX_SNAPSHOT16(x) (x)
#define VX_SNAPSHOT32(x) (x)
#endif
/* Private native interface; logical leaf mapping is in runtime_functions. */
typedef struct {
    uint8_t v0;
} vx_flow_0_result;
#ifdef __SDCC_z80
typedef char vx_flow_0_result_size[sizeof(vx_flow_0_result)==1 ? 1 : -1];
#endif
/* Private native interface; logical leaf mapping is in runtime_functions. */
typedef struct {
    uint8_t v0;
} vx_flow_1_result;
#ifdef __SDCC_z80
typedef char vx_flow_1_result_size[sizeof(vx_flow_1_result)==1 ? 1 : -1];
#endif
/* Private native interface; logical leaf mapping is in runtime_functions. */
typedef struct {
    uint8_t v0;
} vx_flow_2_result;
#ifdef __SDCC_z80
typedef char vx_flow_2_result_size[sizeof(vx_flow_2_result)==1 ? 1 : -1];
#endif
/* Private native interface; logical leaf mapping is in runtime_functions. */
typedef struct {
    uint8_t v0;
} vx_flow_3_result;
#ifdef __SDCC_z80
typedef char vx_flow_3_result_size[sizeof(vx_flow_3_result)==1 ? 1 : -1];
#endif
/* Private native interface; logical leaf mapping is in runtime_functions. */
typedef struct {
    uint8_t v0;
} vx_flow_4_result;
#ifdef __SDCC_z80
typedef char vx_flow_4_result_size[sizeof(vx_flow_4_result)==1 ? 1 : -1];
#endif
/* Private native interface; logical leaf mapping is in runtime_functions. */
typedef struct {
    uint8_t v0;
} vx_flow_5_result;
#ifdef __SDCC_z80
typedef char vx_flow_5_result_size[sizeof(vx_flow_5_result)==1 ? 1 : -1];
#endif
/* Private native interface; logical leaf mapping is in runtime_functions. */
typedef struct {
    uint8_t v0;
} vx_flow_6_result;
#ifdef __SDCC_z80
typedef char vx_flow_6_result_size[sizeof(vx_flow_6_result)==1 ? 1 : -1];
#endif
/* Private native interface; logical leaf mapping is in runtime_functions. */
typedef struct {
    uint8_t v0;
} vx_flow_7_result;
#ifdef __SDCC_z80
typedef char vx_flow_7_result_size[sizeof(vx_flow_7_result)==1 ? 1 : -1];
#endif
void vx_flow_0(vx_flow_0_result *vxo, VX_STABLE uint8_t vxa_0) VX_ABI VX_RESIDENT;
void vx_flow_1(vx_flow_1_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI VX_RESIDENT;
void vx_flow_2(vx_flow_2_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1, VX_STABLE uint8_t vxa_2, VX_STABLE uint8_t vxa_3, VX_STABLE uint8_t vxa_4, VX_STABLE uint8_t vxa_5, VX_STABLE uint8_t vxa_6) VX_ABI VX_RESIDENT;
void vx_flow_3(vx_flow_3_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI VX_RESIDENT;
void vx_flow_4(vx_flow_4_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI VX_RESIDENT;
void vx_flow_5(vx_flow_5_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1) VX_ABI VX_RESIDENT;
void vx_flow_6(vx_flow_6_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1, VX_STABLE uint8_t vxa_2, VX_STABLE uint8_t vxa_3, VX_STABLE uint8_t vxa_4, VX_STABLE uint8_t vxa_5, VX_STABLE uint8_t vxa_6, VX_STABLE uint8_t vxa_7, VX_STABLE uint8_t vxa_8, VX_STABLE uint8_t vxa_9, VX_STABLE uint8_t vxa_10, VX_STABLE uint8_t vxa_11, VX_STABLE uint8_t vxa_12, VX_STABLE uint8_t vxa_13, VX_STABLE uint8_t vxa_14) VX_ABI VX_RESIDENT;
void vx_flow_7(vx_flow_7_result *vxo, VX_STABLE uint8_t vxa_0, VX_STABLE uint8_t vxa_1, VX_STABLE uint8_t vxa_2, VX_STABLE uint8_t vxa_3, VX_STABLE uint8_t vxa_4, VX_STABLE uint8_t vxa_5, VX_STABLE uint8_t vxa_6, VX_STABLE uint8_t vxa_7) VX_ABI VX_RESIDENT;
/* Sink ABI: caller-owned result leaves, then value argument leaves. */
void vx_external_motion_query(uint32_t *result, uint16_t p0, uint16_t p1, uint8_t p2, uint8_t p3, uint8_t p4, uint8_t p5, uint8_t p6, uint16_t p7, uint16_t p8) VX_ABI;
void vx_invoke_external_motion_query(uint32_t *result, uint16_t p0, uint16_t p1, uint8_t p2, uint8_t p3, uint8_t p4, uint8_t p5, uint8_t p6, uint16_t p7, uint16_t p8) VX_ABI VX_RESIDENT;
/* Sink ABI: caller-owned result leaves, then value argument leaves. */
void vx_external_flow_yield(uint32_t *result) VX_ABI;
void vx_invoke_external_flow_yield(uint32_t *result) VX_ABI VX_RESIDENT;
/* Sink ABI: caller-owned result leaves, then value argument leaves. */
void vx_external_flow_slot(uint32_t *result, uint8_t p0) VX_ABI;
void vx_invoke_external_flow_slot(uint32_t *result, uint8_t p0) VX_ABI VX_RESIDENT;
/* Sink ABI: caller-owned result leaves, then value argument leaves. */
void vx_external_flow_actor(uint32_t *result, uint8_t p0) VX_ABI;
void vx_invoke_external_flow_actor(uint32_t *result, uint8_t p0) VX_ABI VX_RESIDENT;
/* Sink ABI: caller-owned result leaves, then value argument leaves. */
void vx_external_flow_flags(uint32_t *result, uint8_t p0) VX_ABI;
void vx_invoke_external_flow_flags(uint32_t *result, uint8_t p0) VX_ABI VX_RESIDENT;
/* Sink ABI: caller-owned result leaves, then value argument leaves. */
void vx_external_flow_update(uint32_t *result, uint8_t p0) VX_ABI;
void vx_invoke_external_flow_update(uint32_t *result, uint8_t p0) VX_ABI VX_RESIDENT;
/* Sink ABI: caller-owned result leaves, then value argument leaves. */
void vx_external_flow_despawn(uint32_t *result, uint8_t p0) VX_ABI;
void vx_invoke_external_flow_despawn(uint32_t *result, uint8_t p0) VX_ABI VX_RESIDENT;
/* Sink ABI: caller-owned result leaves, then value argument leaves. */
void vx_external_flow_spawn(uint32_t *result, uint8_t p0) VX_ABI;
void vx_invoke_external_flow_spawn(uint32_t *result, uint8_t p0) VX_ABI VX_RESIDENT;
/* Sink ABI: caller-owned result leaves, then value argument leaves. */
void vx_external_flow_cycle(uint32_t *result) VX_ABI;
void vx_invoke_external_flow_cycle(uint32_t *result) VX_ABI VX_RESIDENT;
extern uint8_t vx_payload[20];
void vx_lumberjack(uint8_t vxp_a0,uint8_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_lumberjack_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_pear(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_pear_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_stew(uint8_t vxp_a0,uint16_t vxp_a1,uint8_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_stew_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_university(uint8_t vxp_a0,uint16_t vxp_a1,uint8_t vxp_a2,uint8_t vxp_a3,uint8_t vxp_a4) VX_ABI VX_RESIDENT;
uint32_t vx_university_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_shop_stock(uint8_t vxp_a0,uint16_t vxp_a1,uint8_t vxp_a2,uint8_t vxp_a3,uint8_t vxp_a4,uint8_t vxp_a5) VX_ABI VX_RESIDENT;
uint32_t vx_shop_stock_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_shop_trade(uint8_t vxp_a0,uint16_t vxp_a1,uint8_t vxp_a2,uint8_t vxp_a3,uint8_t vxp_a4,uint8_t vxp_a5,uint8_t vxp_a6,uint8_t vxp_a7) VX_ABI VX_RESIDENT;
uint32_t vx_shop_trade_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_password_encode(uint8_t vxp_a0,uint8_t vxp_a1,uint16_t vxp_a2,uint8_t vxp_a3) VX_ABI VX_RESIDENT;
uint32_t vx_password_encode_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_password_decode(uint8_t vxp_a0,uint8_t vxp_a1_0,uint8_t vxp_a1_1,uint8_t vxp_a1_2,uint8_t vxp_a1_3,uint8_t vxp_a1_4,uint8_t vxp_a1_5,uint8_t vxp_a1_6,uint8_t vxp_a1_7,uint8_t vxp_a1_8,uint8_t vxp_a1_9,uint8_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_password_decode_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_world_route(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2,uint8_t vxp_a3,uint8_t vxp_a4) VX_ABI VX_RESIDENT;
uint32_t vx_world_route_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_world_rocks(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_world_rocks_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_world_well(uint8_t vxp_a0) VX_ABI VX_RESIDENT;
uint32_t vx_world_well_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_drop_roll(uint8_t vxp_a0,uint8_t vxp_a1,uint16_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_drop_roll_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_drop_collect(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_drop_collect_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_drop_spawn(uint8_t vxp_a0) VX_ABI VX_RESIDENT;
uint32_t vx_drop_spawn_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_drop_step(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_drop_step_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_town_door(uint8_t vxp_a0,uint8_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_town_door_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_town_house(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2,uint8_t vxp_a3) VX_ABI VX_RESIDENT;
uint32_t vx_town_house_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_town_board(uint8_t vxp_a0,uint8_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_town_board_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_town_monster(uint8_t vxp_a0,uint8_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_town_monster_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_ghost_spawn(uint16_t vxp_a0,uint16_t vxp_a1,uint8_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_ghost_spawn_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_ghost_update(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2,uint16_t vxp_a3,uint16_t vxp_a4,uint16_t vxp_a5,uint16_t vxp_a6,int8_t vxp_a7,int8_t vxp_a8,uint16_t vxp_a9,uint16_t vxp_a10) VX_ABI VX_RESIDENT;
uint32_t vx_ghost_update_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_skeleti_tick(uint8_t vxp_a0,uint8_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_skeleti_tick_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_skeleti_draws(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_skeleti_draws_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_skeleti_update(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2,uint8_t vxp_a3,uint8_t vxp_a4,uint16_t vxp_a5,uint16_t vxp_a6,uint16_t vxp_a7,uint16_t vxp_a8,uint16_t vxp_a9,uint16_t vxp_a10,uint8_t vxp_a11) VX_ABI VX_RESIDENT;
uint32_t vx_skeleti_update_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_combat_hit(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2,int16_t vxp_a3,int16_t vxp_a4,uint8_t vxp_a5) VX_ABI VX_RESIDENT;
uint32_t vx_combat_hit_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_combat_tick(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2,uint8_t vxp_a3) VX_ABI VX_RESIDENT;
uint32_t vx_combat_tick_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_combat_death(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2,uint8_t vxp_a3) VX_ABI VX_RESIDENT;
uint32_t vx_combat_death_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_melee_style(uint8_t vxp_a0) VX_ABI VX_RESIDENT;
uint32_t vx_melee_style_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_melee_hit(uint8_t vxp_a0,uint8_t vxp_a1,uint16_t vxp_a2,uint16_t vxp_a3) VX_ABI VX_RESIDENT;
uint32_t vx_melee_hit_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_melee_axe(uint8_t vxp_a0,uint16_t vxp_a1,uint16_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_melee_axe_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_melee_cut(uint8_t vxp_a0) VX_ABI VX_RESIDENT;
uint32_t vx_melee_cut_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_melee_update(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2,uint8_t vxp_a3,uint16_t vxp_a4,uint16_t vxp_a5) VX_ABI VX_RESIDENT;
uint32_t vx_melee_update_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_projectile_spawn(uint8_t vxp_a0,uint8_t vxp_a1,uint16_t vxp_a2,uint16_t vxp_a3) VX_ABI VX_RESIDENT;
uint32_t vx_projectile_spawn_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_projectile_move(uint8_t vxp_a0,uint16_t vxp_a1,uint16_t vxp_a2,int8_t vxp_a3,int8_t vxp_a4,uint8_t vxp_a5,uint8_t vxp_a6) VX_ABI VX_RESIDENT;
uint32_t vx_projectile_move_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_bomb_step(uint8_t vxp_a0,uint8_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_bomb_step_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_bomb_cut(uint8_t vxp_a0) VX_ABI VX_RESIDENT;
uint32_t vx_bomb_cut_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_effect_step(uint8_t vxp_a0,uint8_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_effect_step_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_spark_frame(uint8_t vxp_a0,uint8_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_spark_frame_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_fairy_move(uint8_t vxp_a0,uint8_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_fairy_move_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_lumber_draw(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_lumber_draw_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_ball_tick(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2,uint8_t vxp_a3) VX_ABI VX_RESIDENT;
uint32_t vx_ball_tick_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_ball_leg(uint8_t vxp_a0,uint8_t vxp_a1,uint16_t vxp_a2,uint16_t vxp_a3,uint8_t vxp_a4) VX_ABI VX_RESIDENT;
uint32_t vx_ball_leg_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_ball_reply(uint8_t vxp_a0,uint8_t vxp_a1,uint16_t vxp_a2,uint16_t vxp_a3,uint16_t vxp_a4,uint16_t vxp_a5,uint8_t vxp_a6,uint8_t vxp_a7) VX_ABI VX_RESIDENT;
uint32_t vx_ball_reply_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_ball_home(uint16_t vxp_a0,uint16_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_ball_home_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_player_keys(uint8_t vxp_a0) VX_ABI VX_RESIDENT;
uint32_t vx_player_keys_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_player_weapon(uint8_t vxp_a0,uint8_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_player_weapon_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_player_attack(uint8_t vxp_a0,uint8_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_player_attack_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_player_tick(uint8_t vxp_a0,uint8_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_player_tick_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_player_move(uint8_t vxp_a0,uint16_t vxp_a1,uint16_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_player_move_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_player_slide(uint8_t vxp_a0,uint8_t vxp_a1,uint16_t vxp_a2,uint16_t vxp_a3,uint16_t vxp_a4,uint16_t vxp_a5) VX_ABI VX_RESIDENT;
uint32_t vx_player_slide_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_player_draw(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_player_draw_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_player_view(uint16_t vxp_a0,uint16_t vxp_a1,uint8_t vxp_a2,uint8_t vxp_a3,uint8_t vxp_a4,uint8_t vxp_a5,uint8_t vxp_a6) VX_ABI VX_RESIDENT;
uint32_t vx_player_view_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_player_motion(uint16_t vxp_a0_0,uint16_t vxp_a0_1,uint8_t vxp_a0_2,uint8_t vxp_a0_3,uint8_t vxp_a0_4,uint8_t vxp_a0_5,uint8_t vxp_a0_6) VX_ABI VX_RESIDENT;
uint32_t vx_player_motion_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_scene_intro(uint8_t vxp_a0,uint8_t vxp_a1,uint16_t vxp_a2,uint16_t vxp_a3) VX_ABI VX_RESIDENT;
uint32_t vx_scene_intro_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_scene_spark(uint8_t vxp_a0,uint8_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_scene_spark_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_scene_wipe(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_scene_wipe_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_scene_revive(uint8_t vxp_a0) VX_ABI VX_RESIDENT;
uint32_t vx_scene_revive_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_scene_door(uint8_t vxp_a0,uint8_t vxp_a1,uint16_t vxp_a2,uint16_t vxp_a3,uint8_t vxp_a4) VX_ABI VX_RESIDENT;
uint32_t vx_scene_door_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_scene_camera(uint16_t vxp_a0,uint16_t vxp_a1,uint8_t vxp_a2,uint8_t vxp_a3,uint8_t vxp_a4,uint8_t vxp_a5,uint8_t vxp_a6) VX_ABI VX_RESIDENT;
uint32_t vx_scene_camera_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_scene_brief(uint8_t vxp_a0) VX_ABI VX_RESIDENT;
uint32_t vx_scene_brief_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_world_frame(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_world_frame_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_world_window(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2,uint8_t vxp_a3,uint8_t vxp_a4) VX_ABI VX_RESIDENT;
uint32_t vx_world_window_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_world_follow(uint16_t vxp_a0,uint16_t vxp_a1,uint16_t vxp_a2,uint16_t vxp_a3,uint8_t vxp_a4,uint8_t vxp_a5) VX_ABI VX_RESIDENT;
uint32_t vx_world_follow_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_world_scroll(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2,uint8_t vxp_a3,uint8_t vxp_a4) VX_ABI VX_RESIDENT;
uint32_t vx_world_scroll_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_world_seed(uint8_t vxp_a0) VX_ABI VX_RESIDENT;
uint32_t vx_world_seed_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_world_start(uint16_t vxp_a0,uint16_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_world_start_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_weapon_setup(uint8_t vxp_a0,uint8_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_weapon_setup_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_contact_box(uint16_t vxp_a0,uint16_t vxp_a1,uint16_t vxp_a2,uint16_t vxp_a3,uint8_t vxp_a4,uint8_t vxp_a5) VX_ABI VX_RESIDENT;
uint32_t vx_contact_box_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_contact_player(uint16_t vxp_a0,uint16_t vxp_a1,uint16_t vxp_a2,uint16_t vxp_a3) VX_ABI VX_RESIDENT;
uint32_t vx_contact_player_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_ui_menu(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2,uint8_t vxp_a3) VX_ABI VX_RESIDENT;
uint32_t vx_ui_menu_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_ui_cursor(uint8_t vxp_a0,uint8_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_ui_cursor_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_ui_editor(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_ui_editor_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_title_step(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2,uint8_t vxp_a3) VX_ABI VX_RESIDENT;
uint32_t vx_title_step_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_title_seed(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_title_seed_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_title_frame(uint8_t vxp_a0,uint8_t vxp_a1) VX_ABI VX_RESIDENT;
uint32_t vx_title_frame_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_title_attract(uint8_t vxp_a0,uint8_t vxp_a1,uint8_t vxp_a2) VX_ABI VX_RESIDENT;
uint32_t vx_title_attract_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_world_flow(void) VX_ABI VX_RESIDENT;
uint32_t vx_world_flow_read(uint16_t index) VX_ABI VX_RESIDENT;
void vx_title_flow(void) VX_ABI VX_RESIDENT;
uint32_t vx_title_flow_read(uint16_t index) VX_ABI VX_RESIDENT;
#endif
