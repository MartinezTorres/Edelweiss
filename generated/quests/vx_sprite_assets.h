/* Generated from gameplay/sprite_assets.vx. Zero means no request. */
#ifndef EDW_SPRITE_ASSETS_H
#define EDW_SPRITE_ASSETS_H
typedef uint8_t EdwSprite;
#define EDW_GHOST_SPRITE_COUNT 12
#define EDW_GHOST_SPRITE_FIRST 1
static inline EdwSprite edw_ghost_sprite(uint8_t frame) {
    return frame < EDW_GHOST_SPRITE_COUNT ? frame + EDW_GHOST_SPRITE_FIRST : 0;
}
#define EDW_SKELETI_SPRITE_COUNT 10
#define EDW_SKELETI_SPRITE_FIRST 13
static inline EdwSprite edw_skeleti_sprite(uint8_t frame) {
    return frame < EDW_SKELETI_SPRITE_COUNT ? frame + EDW_SKELETI_SPRITE_FIRST : 0;
}
#define EDW_MELEE_SMALL_SPRITE_COUNT 12
#define EDW_MELEE_SMALL_SPRITE_FIRST 23
static inline EdwSprite edw_melee_small_sprite(uint8_t frame) {
    return frame < EDW_MELEE_SMALL_SPRITE_COUNT ? frame + EDW_MELEE_SMALL_SPRITE_FIRST : 0;
}
#define EDW_MELEE_LARGE_SPRITE_COUNT 12
#define EDW_MELEE_LARGE_SPRITE_FIRST 35
static inline EdwSprite edw_melee_large_sprite(uint8_t frame) {
    return frame < EDW_MELEE_LARGE_SPRITE_COUNT ? frame + EDW_MELEE_LARGE_SPRITE_FIRST : 0;
}
#define EDW_ARROW_SPRITE_COUNT 4
#define EDW_ARROW_SPRITE_FIRST 47
static inline EdwSprite edw_arrow_sprite(uint8_t frame) {
    return frame < EDW_ARROW_SPRITE_COUNT ? frame + EDW_ARROW_SPRITE_FIRST : 0;
}
#define EDW_FIRE_SPRITE_COUNT 4
#define EDW_FIRE_SPRITE_FIRST 51
static inline EdwSprite edw_fire_sprite(uint8_t frame) {
    return frame < EDW_FIRE_SPRITE_COUNT ? frame + EDW_FIRE_SPRITE_FIRST : 0;
}
#define EDW_BOMB_SPRITE_COUNT 4
#define EDW_BOMB_SPRITE_FIRST 55
static inline EdwSprite edw_bomb_sprite(uint8_t frame) {
    return frame < EDW_BOMB_SPRITE_COUNT ? frame + EDW_BOMB_SPRITE_FIRST : 0;
}
#define EDW_SPARK_SPRITE_COUNT 12
#define EDW_SPARK_SPRITE_FIRST 59
static inline EdwSprite edw_spark_sprite(uint8_t frame) {
    return frame < EDW_SPARK_SPRITE_COUNT ? frame + EDW_SPARK_SPRITE_FIRST : 0;
}
#define EDW_EXPLOSION_SPRITE_COUNT 4
#define EDW_EXPLOSION_SPRITE_FIRST 71
static inline EdwSprite edw_explosion_sprite(uint8_t frame) {
    return frame < EDW_EXPLOSION_SPRITE_COUNT ? frame + EDW_EXPLOSION_SPRITE_FIRST : 0;
}
#define EDW_BALL_SPRITE_COUNT 4
#define EDW_BALL_SPRITE_FIRST 75
static inline EdwSprite edw_ball_sprite(uint8_t frame) {
    return frame < EDW_BALL_SPRITE_COUNT ? frame + EDW_BALL_SPRITE_FIRST : 0;
}
#define EDW_PLAYER_SPRITE_COUNT 10
#define EDW_PLAYER_SPRITE_FIRST 79
static inline EdwSprite edw_player_sprite(uint8_t frame) {
    return frame < EDW_PLAYER_SPRITE_COUNT ? frame + EDW_PLAYER_SPRITE_FIRST : 0;
}
#define EDW_DROP_SPRITE_COUNT 4
#define EDW_DROP_SPRITE_FIRST 89
static inline EdwSprite edw_drop_sprite(uint8_t frame) {
    return frame < EDW_DROP_SPRITE_COUNT ? frame + EDW_DROP_SPRITE_FIRST : 0;
}
#define EDW_FAIRY_SPRITE_COUNT 2
#define EDW_FAIRY_SPRITE_FIRST 93
static inline EdwSprite edw_fairy_sprite(uint8_t frame) {
    return frame < EDW_FAIRY_SPRITE_COUNT ? frame + EDW_FAIRY_SPRITE_FIRST : 0;
}
#define EDW_LUMBERJACK_SPRITE_COUNT 4
#define EDW_LUMBERJACK_SPRITE_FIRST 95
static inline EdwSprite edw_lumberjack_sprite(uint8_t frame) {
    return frame < EDW_LUMBERJACK_SPRITE_COUNT ? frame + EDW_LUMBERJACK_SPRITE_FIRST : 0;
}
#define EDW_SPRITE_COUNT 98
#endif
