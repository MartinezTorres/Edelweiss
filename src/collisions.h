#pragma once
#include <common.h>

USING_MODULE(collisions_d, PAGE_D);

void weapon_collision_detection_d(uint8_t weapon_spawn_idx, uint8_t bounding_box_rows_pixels, uint8_t bounding_box_cols_pixels);
bool collision_wolfi_d(uint8_t enemy_spawn_idx);
void hit_wolfi_d(uint8_t enemy_spawn_idx);
void on_hit_default_d(Entity *entity, Entity *aggressor);

INLINE void weapon_collision_detection(uint8_t weapon_spawn_idx, uint8_t bounding_box_rows_pixels, uint8_t bounding_box_cols_pixels) {
	
	uint8_t oldSegmentPageD = mapper_load_module(collisions_d, PAGE_D);
    weapon_collision_detection_d(weapon_spawn_idx, bounding_box_rows_pixels, bounding_box_cols_pixels);
    mapper_load_segment(oldSegmentPageD, PAGE_D);
}

INLINE bool collision_wolfi(uint8_t enemy_spawn_idx) {

	uint8_t oldSegmentPageD = mapper_load_module(collisions_d, PAGE_D);
	bool ret = collision_wolfi_d(enemy_spawn_idx);
    mapper_load_segment(oldSegmentPageD, PAGE_D);
    return ret;
}


INLINE void hit_wolfi(uint8_t enemy_spawn_idx) { 

	uint8_t oldSegmentPageD = mapper_load_module(collisions_d, PAGE_D);
	hit_wolfi_d(enemy_spawn_idx); 
    mapper_load_segment(oldSegmentPageD, PAGE_D);
}

void on_hit_default(Entity *entity, Entity *aggressor);
void on_hit_null(Entity *entity, Entity *weapon);
