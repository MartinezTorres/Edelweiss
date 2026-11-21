#ifndef VX_BINDING_STORAGE_H
#define VX_BINDING_STORAGE_H
#include "vx_binding_types.h"
typedef union {
    vx_bind_world_keep_frame_type binding_world_keep;
    vx_bind_contact_player_frame_type binding_contact_player;
    vx_bind_player_move_frame_type binding_player_move;
    vx_bind_contact_box_frame_type binding_contact_box;
    vx_bind_player_slide_frame_type binding_player_slide;
    vx_bind_player_keys_frame_type binding_player_keys;
    vx_bind_skeleti_tick_frame_type binding_skeleti_tick;
    vx_bind_combat_idle_frame_type binding_combat_idle;
    vx_bind_player_tick_frame_type binding_player_tick;
    vx_bind_world_frame_frame_type binding_world_frame;
    vx_bind_world_spawn_frame_type binding_world_spawn;
    vx_bind_player_draw_frame_type binding_player_draw;
    vx_bind_player_view_frame_type binding_player_view;
    vx_bind_effect_step_frame_type binding_effect_step;
    vx_bind_ball_tick_frame_type binding_ball_tick;
    vx_bind_world_follow_frame_type binding_world_follow;
    vx_bind_skeleti_draws_frame_type binding_skeleti_draws;
    vx_bind_ball_home_frame_type binding_ball_home;
    vx_bind_world_scroll_frame_type binding_world_scroll;
    vx_bind_skeleti_wait_frame_type binding_skeleti_wait;
    vx_bind_ball_leg_frame_type binding_ball_leg;
    vx_bind_ball_reply_frame_type binding_ball_reply;
    vx_bind_bomb_step_frame_type binding_bomb_step;
    vx_bind_projectile_move_frame_type binding_projectile_move;
    vx_bind_melee_update_frame_type binding_melee_update;
    vx_bind_ghost_move_frame_type binding_ghost_move;
    vx_bind_spark_frame_frame_type binding_spark_frame;
    vx_bind_title_frame_frame_type binding_title_frame;
    vx_bind_lumber_draw_frame_type binding_lumber_draw;
    vx_bind_drop_step_frame_type binding_drop_step;
    vx_bind_scene_spark_frame_type binding_scene_spark;
    vx_bind_combat_tick_frame_type binding_combat_tick;
    vx_bind_scene_intro_frame_type binding_scene_intro;
    vx_bind_skeleti_move_frame_type binding_skeleti_move;
    vx_bind_player_attack_frame_type binding_player_attack;
    vx_bind_fairy_move_frame_type binding_fairy_move;
    vx_bind_ui_menu_frame_type binding_ui_menu;
    vx_bind_combat_hit_frame_type binding_combat_hit;
    vx_bind_ui_cursor_frame_type binding_ui_cursor;
    vx_bind_ui_editor_frame_type binding_ui_editor;
    vx_bind_scene_door_frame_type binding_scene_door;
    vx_bind_scene_camera_frame_type binding_scene_camera;
    vx_bind_bomb_cut_frame_type binding_bomb_cut;
    vx_bind_melee_cut_frame_type binding_melee_cut;
    vx_bind_drop_spawn_frame_type binding_drop_spawn;
    vx_bind_scene_revive_frame_type binding_scene_revive;
    vx_bind_player_weapon_frame_type binding_player_weapon;
    vx_bind_weapon_setup_frame_type binding_weapon_setup;
    vx_bind_world_seed_frame_type binding_world_seed;
    vx_bind_combat_death_frame_type binding_combat_death;
    vx_bind_drop_collect_frame_type binding_drop_collect;
    vx_bind_melee_style_frame_type binding_melee_style;
    vx_bind_scene_brief_frame_type binding_scene_brief;
    vx_bind_drop_roll_frame_type binding_drop_roll;
    vx_bind_title_seed_frame_type binding_title_seed;
    vx_bind_melee_axe_frame_type binding_melee_axe;
    vx_bind_scene_wipe_frame_type binding_scene_wipe;
    vx_bind_title_attract_frame_type binding_title_attract;
    vx_bind_ghost_spawn_frame_type binding_ghost_spawn;
    vx_bind_title_step_frame_type binding_title_step;
    vx_bind_melee_hit_frame_type binding_melee_hit;
    vx_bind_world_start_frame_type binding_world_start;
    vx_bind_projectile_spawn_frame_type binding_projectile_spawn;
} vx_binding_slot_0_type;
extern vx_binding_slot_0_type vx_binding_slot_0;
#ifdef __SDCC_z80
typedef char vx_binding_slot_0_size[sizeof(vx_binding_slot_0_type)==29 ? 1 : -1];
#endif
typedef union {
    vx_bind_world_flow_frame_type binding_world_flow;
    vx_bind_title_flow_frame_type binding_title_flow;
} vx_binding_slot_1_type;
extern vx_binding_slot_1_type vx_binding_slot_1;
#ifdef __SDCC_z80
typedef char vx_binding_slot_1_size[sizeof(vx_binding_slot_1_type)==11 ? 1 : -1];
#endif
#endif
