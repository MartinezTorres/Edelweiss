/* Private renderer table. Its page B must remain mapped while selecting an entry. */
typedef struct { uint8_t segment; const TSpriteInterlaced *info; } EdwSpriteBinding;
#ifdef MSX
typedef char edw_binding_size_check[sizeof(EdwSpriteBinding)==3?1:-1];
#endif
typedef char edw_sprite_size_check[sizeof(TSpriteInterlaced)==98?1:-1];
USING_MODULE(entity_ghosti_sprite, PAGE_D);
extern const TSpriteInterlaced ghosti_0_0;
extern const TSpriteInterlaced ghosti_0_1;
extern const TSpriteInterlaced ghosti_1_0;
extern const TSpriteInterlaced ghosti_1_1;
extern const TSpriteInterlaced ghosti_2_0;
extern const TSpriteInterlaced ghosti_2_1;
extern const TSpriteInterlaced ghosti_3_0;
extern const TSpriteInterlaced ghosti_3_1;
extern const TSpriteInterlaced ghosti_4_0;
extern const TSpriteInterlaced ghosti_4_1;
extern const TSpriteInterlaced ghosti_5_0;
extern const TSpriteInterlaced ghosti_5_1;
USING_MODULE(entity_skeleti_sprite, PAGE_D);
extern const TSpriteInterlaced skeleti_0_0;
extern const TSpriteInterlaced skeleti_0_1;
extern const TSpriteInterlaced skeleti_1_0;
extern const TSpriteInterlaced skeleti_1_1;
extern const TSpriteInterlaced skeleti_2_0;
extern const TSpriteInterlaced skeleti_2_1;
extern const TSpriteInterlaced skeleti_3_0;
extern const TSpriteInterlaced skeleti_3_1;
extern const TSpriteInterlaced skeleti_4_0;
extern const TSpriteInterlaced skeleti_4_1;
USING_MODULE(entity_weapon_slash_small_sprite, PAGE_D);
extern const TSpriteInterlaced weapon_slash_small_0_0;
extern const TSpriteInterlaced weapon_slash_small_0_1;
extern const TSpriteInterlaced weapon_slash_small_0_2;
extern const TSpriteInterlaced weapon_slash_small_0_3;
extern const TSpriteInterlaced weapon_slash_small_1_0;
extern const TSpriteInterlaced weapon_slash_small_1_3;
extern const TSpriteInterlaced weapon_slash_small_2_0;
extern const TSpriteInterlaced weapon_slash_small_2_3;
extern const TSpriteInterlaced weapon_slash_small_3_0;
extern const TSpriteInterlaced weapon_slash_small_3_1;
extern const TSpriteInterlaced weapon_slash_small_3_2;
extern const TSpriteInterlaced weapon_slash_small_3_3;
USING_MODULE(entity_weapon_slash_large_sprite, PAGE_D);
extern const TSpriteInterlaced weapon_slash_large_0_0;
extern const TSpriteInterlaced weapon_slash_large_0_1;
extern const TSpriteInterlaced weapon_slash_large_0_2;
extern const TSpriteInterlaced weapon_slash_large_0_3;
extern const TSpriteInterlaced weapon_slash_large_1_0;
extern const TSpriteInterlaced weapon_slash_large_1_3;
extern const TSpriteInterlaced weapon_slash_large_2_0;
extern const TSpriteInterlaced weapon_slash_large_2_3;
extern const TSpriteInterlaced weapon_slash_large_3_0;
extern const TSpriteInterlaced weapon_slash_large_3_1;
extern const TSpriteInterlaced weapon_slash_large_3_2;
extern const TSpriteInterlaced weapon_slash_large_3_3;
USING_MODULE(entity_weapon_arrow_sprite, PAGE_D);
extern const TSpriteInterlaced weapon_arrow_0_0;
extern const TSpriteInterlaced weapon_arrow_1_0;
extern const TSpriteInterlaced weapon_arrow_2_0;
extern const TSpriteInterlaced weapon_arrow_3_0;
USING_MODULE(entity_weapon_fire_sprite, PAGE_D);
extern const TSpriteInterlaced weapon_fire_0_0;
extern const TSpriteInterlaced weapon_fire_1_0;
extern const TSpriteInterlaced weapon_fire_2_0;
extern const TSpriteInterlaced weapon_fire_3_0;
USING_MODULE(entity_weapon_bomb_sprite, PAGE_D);
extern const TSpriteInterlaced weapon_bomb_0_0;
extern const TSpriteInterlaced weapon_bomb_1_0;
extern const TSpriteInterlaced weapon_bomb_2_0;
extern const TSpriteInterlaced weapon_bomb_3_0;
USING_MODULE(entity_spark_sprite, PAGE_D);
extern const TSpriteInterlaced spark_0_0;
extern const TSpriteInterlaced spark_0_1;
extern const TSpriteInterlaced spark_0_2;
extern const TSpriteInterlaced spark_1_0;
extern const TSpriteInterlaced spark_1_1;
extern const TSpriteInterlaced spark_1_2;
extern const TSpriteInterlaced spark_2_0;
extern const TSpriteInterlaced spark_2_1;
extern const TSpriteInterlaced spark_2_2;
extern const TSpriteInterlaced spark_3_0;
extern const TSpriteInterlaced spark_3_1;
extern const TSpriteInterlaced spark_3_2;
USING_MODULE(entity_explosion_sprite, PAGE_D);
extern const TSpriteInterlaced explosion_0_0;
extern const TSpriteInterlaced explosion_1_0;
extern const TSpriteInterlaced explosion_2_0;
extern const TSpriteInterlaced explosion_3_0;
USING_MODULE(enemy_ball_sprite, PAGE_D);
extern const TSpriteInterlaced enemy_ball_0_0;
extern const TSpriteInterlaced enemy_ball_1_0;
extern const TSpriteInterlaced enemy_ball_2_0;
extern const TSpriteInterlaced enemy_ball_3_0;
USING_MODULE(entity_wolfi_sprite, PAGE_D);
extern const TSpriteInterlaced wolfi_0_0;
extern const TSpriteInterlaced wolfi_0_1;
extern const TSpriteInterlaced wolfi_1_0;
extern const TSpriteInterlaced wolfi_1_1;
extern const TSpriteInterlaced wolfi_2_0;
extern const TSpriteInterlaced wolfi_2_1;
extern const TSpriteInterlaced wolfi_3_0;
extern const TSpriteInterlaced wolfi_3_1;
extern const TSpriteInterlaced wolfi_4_0;
extern const TSpriteInterlaced wolfi_4_1;
USING_MODULE(entity_drop_item_sprite, PAGE_D);
extern const TSpriteInterlaced drop_items_0_0;
extern const TSpriteInterlaced drop_items_1_0;
extern const TSpriteInterlaced drop_items_2_0;
extern const TSpriteInterlaced drop_items_3_0;
USING_MODULE(entity_fairy_sprite, PAGE_D);
extern const TSpriteInterlaced fairy_0_0;
extern const TSpriteInterlaced fairy_1_0;
USING_MODULE(entity_npcs_sprites, PAGE_D);
extern const TSpriteInterlaced npcs_0_0;
extern const TSpriteInterlaced npcs_0_1;
extern const TSpriteInterlaced npcs_0_2;
extern const TSpriteInterlaced npcs_0_3;
const EdwSpriteBinding edw_sprite_bindings[]={
    {MODULE_SEGMENT(entity_ghosti_sprite, PAGE_D), &ghosti_0_0},
    {MODULE_SEGMENT(entity_ghosti_sprite, PAGE_D), &ghosti_0_1},
    {MODULE_SEGMENT(entity_ghosti_sprite, PAGE_D), &ghosti_1_0},
    {MODULE_SEGMENT(entity_ghosti_sprite, PAGE_D), &ghosti_1_1},
    {MODULE_SEGMENT(entity_ghosti_sprite, PAGE_D), &ghosti_2_0},
    {MODULE_SEGMENT(entity_ghosti_sprite, PAGE_D), &ghosti_2_1},
    {MODULE_SEGMENT(entity_ghosti_sprite, PAGE_D), &ghosti_3_0},
    {MODULE_SEGMENT(entity_ghosti_sprite, PAGE_D), &ghosti_3_1},
    {MODULE_SEGMENT(entity_ghosti_sprite, PAGE_D), &ghosti_4_0},
    {MODULE_SEGMENT(entity_ghosti_sprite, PAGE_D), &ghosti_4_1},
    {MODULE_SEGMENT(entity_ghosti_sprite, PAGE_D), &ghosti_5_0},
    {MODULE_SEGMENT(entity_ghosti_sprite, PAGE_D), &ghosti_5_1},
    {MODULE_SEGMENT(entity_skeleti_sprite, PAGE_D), &skeleti_0_0},
    {MODULE_SEGMENT(entity_skeleti_sprite, PAGE_D), &skeleti_0_1},
    {MODULE_SEGMENT(entity_skeleti_sprite, PAGE_D), &skeleti_1_0},
    {MODULE_SEGMENT(entity_skeleti_sprite, PAGE_D), &skeleti_1_1},
    {MODULE_SEGMENT(entity_skeleti_sprite, PAGE_D), &skeleti_2_0},
    {MODULE_SEGMENT(entity_skeleti_sprite, PAGE_D), &skeleti_2_1},
    {MODULE_SEGMENT(entity_skeleti_sprite, PAGE_D), &skeleti_3_0},
    {MODULE_SEGMENT(entity_skeleti_sprite, PAGE_D), &skeleti_3_1},
    {MODULE_SEGMENT(entity_skeleti_sprite, PAGE_D), &skeleti_4_0},
    {MODULE_SEGMENT(entity_skeleti_sprite, PAGE_D), &skeleti_4_1},
    {MODULE_SEGMENT(entity_weapon_slash_small_sprite, PAGE_D), &weapon_slash_small_0_0},
    {MODULE_SEGMENT(entity_weapon_slash_small_sprite, PAGE_D), &weapon_slash_small_0_1},
    {MODULE_SEGMENT(entity_weapon_slash_small_sprite, PAGE_D), &weapon_slash_small_0_2},
    {MODULE_SEGMENT(entity_weapon_slash_small_sprite, PAGE_D), &weapon_slash_small_0_3},
    {MODULE_SEGMENT(entity_weapon_slash_small_sprite, PAGE_D), &weapon_slash_small_1_0},
    {MODULE_SEGMENT(entity_weapon_slash_small_sprite, PAGE_D), &weapon_slash_small_1_3},
    {MODULE_SEGMENT(entity_weapon_slash_small_sprite, PAGE_D), &weapon_slash_small_2_0},
    {MODULE_SEGMENT(entity_weapon_slash_small_sprite, PAGE_D), &weapon_slash_small_2_3},
    {MODULE_SEGMENT(entity_weapon_slash_small_sprite, PAGE_D), &weapon_slash_small_3_0},
    {MODULE_SEGMENT(entity_weapon_slash_small_sprite, PAGE_D), &weapon_slash_small_3_1},
    {MODULE_SEGMENT(entity_weapon_slash_small_sprite, PAGE_D), &weapon_slash_small_3_2},
    {MODULE_SEGMENT(entity_weapon_slash_small_sprite, PAGE_D), &weapon_slash_small_3_3},
    {MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D), &weapon_slash_large_0_0},
    {MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D), &weapon_slash_large_0_1},
    {MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D), &weapon_slash_large_0_2},
    {MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D), &weapon_slash_large_0_3},
    {MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D), &weapon_slash_large_1_0},
    {MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D), &weapon_slash_large_1_3},
    {MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D), &weapon_slash_large_2_0},
    {MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D), &weapon_slash_large_2_3},
    {MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D), &weapon_slash_large_3_0},
    {MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D), &weapon_slash_large_3_1},
    {MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D), &weapon_slash_large_3_2},
    {MODULE_SEGMENT(entity_weapon_slash_large_sprite, PAGE_D), &weapon_slash_large_3_3},
    {MODULE_SEGMENT(entity_weapon_arrow_sprite, PAGE_D), &weapon_arrow_0_0},
    {MODULE_SEGMENT(entity_weapon_arrow_sprite, PAGE_D), &weapon_arrow_1_0},
    {MODULE_SEGMENT(entity_weapon_arrow_sprite, PAGE_D), &weapon_arrow_2_0},
    {MODULE_SEGMENT(entity_weapon_arrow_sprite, PAGE_D), &weapon_arrow_3_0},
    {MODULE_SEGMENT(entity_weapon_fire_sprite, PAGE_D), &weapon_fire_0_0},
    {MODULE_SEGMENT(entity_weapon_fire_sprite, PAGE_D), &weapon_fire_1_0},
    {MODULE_SEGMENT(entity_weapon_fire_sprite, PAGE_D), &weapon_fire_2_0},
    {MODULE_SEGMENT(entity_weapon_fire_sprite, PAGE_D), &weapon_fire_3_0},
    {MODULE_SEGMENT(entity_weapon_bomb_sprite, PAGE_D), &weapon_bomb_0_0},
    {MODULE_SEGMENT(entity_weapon_bomb_sprite, PAGE_D), &weapon_bomb_1_0},
    {MODULE_SEGMENT(entity_weapon_bomb_sprite, PAGE_D), &weapon_bomb_2_0},
    {MODULE_SEGMENT(entity_weapon_bomb_sprite, PAGE_D), &weapon_bomb_3_0},
    {MODULE_SEGMENT(entity_spark_sprite, PAGE_D), &spark_0_0},
    {MODULE_SEGMENT(entity_spark_sprite, PAGE_D), &spark_0_1},
    {MODULE_SEGMENT(entity_spark_sprite, PAGE_D), &spark_0_2},
    {MODULE_SEGMENT(entity_spark_sprite, PAGE_D), &spark_1_0},
    {MODULE_SEGMENT(entity_spark_sprite, PAGE_D), &spark_1_1},
    {MODULE_SEGMENT(entity_spark_sprite, PAGE_D), &spark_1_2},
    {MODULE_SEGMENT(entity_spark_sprite, PAGE_D), &spark_2_0},
    {MODULE_SEGMENT(entity_spark_sprite, PAGE_D), &spark_2_1},
    {MODULE_SEGMENT(entity_spark_sprite, PAGE_D), &spark_2_2},
    {MODULE_SEGMENT(entity_spark_sprite, PAGE_D), &spark_3_0},
    {MODULE_SEGMENT(entity_spark_sprite, PAGE_D), &spark_3_1},
    {MODULE_SEGMENT(entity_spark_sprite, PAGE_D), &spark_3_2},
    {MODULE_SEGMENT(entity_explosion_sprite, PAGE_D), &explosion_0_0},
    {MODULE_SEGMENT(entity_explosion_sprite, PAGE_D), &explosion_1_0},
    {MODULE_SEGMENT(entity_explosion_sprite, PAGE_D), &explosion_2_0},
    {MODULE_SEGMENT(entity_explosion_sprite, PAGE_D), &explosion_3_0},
    {MODULE_SEGMENT(enemy_ball_sprite, PAGE_D), &enemy_ball_0_0},
    {MODULE_SEGMENT(enemy_ball_sprite, PAGE_D), &enemy_ball_1_0},
    {MODULE_SEGMENT(enemy_ball_sprite, PAGE_D), &enemy_ball_2_0},
    {MODULE_SEGMENT(enemy_ball_sprite, PAGE_D), &enemy_ball_3_0},
    {MODULE_SEGMENT(entity_wolfi_sprite, PAGE_D), &wolfi_0_0},
    {MODULE_SEGMENT(entity_wolfi_sprite, PAGE_D), &wolfi_0_1},
    {MODULE_SEGMENT(entity_wolfi_sprite, PAGE_D), &wolfi_1_0},
    {MODULE_SEGMENT(entity_wolfi_sprite, PAGE_D), &wolfi_1_1},
    {MODULE_SEGMENT(entity_wolfi_sprite, PAGE_D), &wolfi_2_0},
    {MODULE_SEGMENT(entity_wolfi_sprite, PAGE_D), &wolfi_2_1},
    {MODULE_SEGMENT(entity_wolfi_sprite, PAGE_D), &wolfi_3_0},
    {MODULE_SEGMENT(entity_wolfi_sprite, PAGE_D), &wolfi_3_1},
    {MODULE_SEGMENT(entity_wolfi_sprite, PAGE_D), &wolfi_4_0},
    {MODULE_SEGMENT(entity_wolfi_sprite, PAGE_D), &wolfi_4_1},
    {MODULE_SEGMENT(entity_drop_item_sprite, PAGE_D), &drop_items_0_0},
    {MODULE_SEGMENT(entity_drop_item_sprite, PAGE_D), &drop_items_1_0},
    {MODULE_SEGMENT(entity_drop_item_sprite, PAGE_D), &drop_items_2_0},
    {MODULE_SEGMENT(entity_drop_item_sprite, PAGE_D), &drop_items_3_0},
    {MODULE_SEGMENT(entity_fairy_sprite, PAGE_D), &fairy_0_0},
    {MODULE_SEGMENT(entity_fairy_sprite, PAGE_D), &fairy_1_0},
    {MODULE_SEGMENT(entity_npcs_sprites, PAGE_D), &npcs_0_0},
    {MODULE_SEGMENT(entity_npcs_sprites, PAGE_D), &npcs_0_1},
    {MODULE_SEGMENT(entity_npcs_sprites, PAGE_D), &npcs_0_2},
    {MODULE_SEGMENT(entity_npcs_sprites, PAGE_D), &npcs_0_3},
};
