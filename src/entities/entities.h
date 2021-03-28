#pragma once
#include <common.h>

USING_MODULE(entity_wolfi, PAGE_C);
void init_wolfi(uint8_t idx, uint8_t i, uint8_t j);

USING_MODULE(entity_skeleti, PAGE_C);
void init_skeleti(uint8_t idx, uint8_t i, uint8_t j);

USING_MODULE(entity_ghosti, PAGE_C);
void init_ghosti(uint8_t idx, uint8_t i, uint8_t j);

USING_MODULE(enemy_ball, PAGE_C);
void init_enemy_ball(uint8_t idx, uint8_t i, uint8_t j);

USING_MODULE(enemy_zombie, PAGE_C);
void init_enemy_zombie(uint8_t idx, uint8_t i, uint8_t j);

USING_MODULE(enemy_skull, PAGE_C);
void init_enemy_skull(uint8_t idx, uint8_t i, uint8_t j);

USING_MODULE(enemy_rock, PAGE_C);
void init_enemy_rock(uint8_t idx, uint8_t i, uint8_t j);

USING_MODULE(enemy_megaghosti, PAGE_C);
void init_enemy_megaghosti(uint8_t idx, uint8_t i, uint8_t j);

USING_MODULE(enemy_ugly_tree, PAGE_C);
void init_enemy_ugly_tree(uint8_t idx, uint8_t i, uint8_t j);

USING_MODULE(enemy_rhino, PAGE_C);
void init_enemy_rhino(uint8_t idx, uint8_t i, uint8_t j);

USING_MODULE(enemy_hooded, PAGE_C);
void init_enemy_hooded(uint8_t idx, uint8_t i, uint8_t j);

USING_MODULE(enemy_pig, PAGE_C);
void init_enemy_pig(uint8_t idx, uint8_t i, uint8_t j);



USING_MODULE(entity_fairy, PAGE_C);
void init_fairy();



USING_MODULE(entity_lumberjack, PAGE_C);
void init_lumberjack(uint8_t idx, uint8_t i, uint8_t j);

USING_MODULE(entity_weapon_slash, PAGE_C);
void init_weapon_slash(uint8_t idx, uint8_t weapon_type);

USING_MODULE(entity_weapon_bow, PAGE_C);
void init_weapon_bow(uint8_t idx);

USING_MODULE(entity_weapon_fire, PAGE_C);
void init_weapon_fire(uint8_t idx);

USING_MODULE(entity_weapon_bomb, PAGE_C);
void init_weapon_bomb(uint8_t idx);

USING_MODULE(entity_explosion, PAGE_C);
void init_explosion(uint8_t idx);

USING_MODULE(entity_spark, PAGE_C);
void init_spark(uint8_t idx);

USING_MODULE(entity_drop_item, PAGE_C);
void init_drop_item(uint8_t idx);

