#pragma once
#include <common.h>

USING_MODULE(entity_wolfi, PAGE_C);
void init_wolfi(uint8_t idx, uint8_t i, uint8_t j);

USING_MODULE(entity_skeleti, PAGE_C);
void init_skeleti(uint8_t idx, uint8_t i, uint8_t j);

USING_MODULE(entity_ghosti, PAGE_C);
void init_ghosti(uint8_t idx, uint8_t i, uint8_t j);

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

USING_MODULE(entity_drop_item, PAGE_C);
void init_drop_item(uint8_t idx);

