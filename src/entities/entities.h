#pragma once
#include <common.h>

USING_MODULE(entity_wolfi, PAGE_C);
void spawn_wolfi(Entity *entity, uint8_t entityIdx);
void despawn_wolfi(Entity *entity, uint8_t entityIdx);
uint8_t update_wolfi(Entity *entity, uint8_t entityIdx);

USING_MODULE(entity_skeleti, PAGE_C);
void spawn_skeleti(Entity *entity, uint8_t entityIdx);
void despawn_skeleti(Entity *entity, uint8_t entityIdx);
uint8_t update_skeleti(Entity *entity, uint8_t entityIdx);

USING_MODULE(entity_ghosti, PAGE_C);
void spawn_ghosti(Entity *entity, uint8_t entityIdx);
void despawn_ghosti(Entity *entity, uint8_t entityIdx);
uint8_t update_ghosti(Entity *entity, uint8_t entityIdx);

USING_MODULE(entity_weapon_slash, PAGE_C);
void spawn_weapon_slash(Entity *entity, uint8_t entityIdx);
void despawn_weapon_slash(Entity *entity, uint8_t entityIdx);
uint8_t update_weapon_slash(Entity *entity, uint8_t entityIdx);

USING_MODULE(entity_weapon_bow, PAGE_C);
void spawn_weapon_bow(Entity *entity, uint8_t entityIdx);
void despawn_weapon_bow(Entity *entity, uint8_t entityIdx);
uint8_t update_weapon_bow(Entity *entity, uint8_t entityIdx);

USING_MODULE(entity_weapon_fire, PAGE_C);
void spawn_weapon_fire(Entity *entity, uint8_t entityIdx);
void despawn_weapon_fire(Entity *entity, uint8_t entityIdx);
uint8_t update_weapon_fire(Entity *entity, uint8_t entityIdx);

USING_MODULE(entity_weapon_bomb, PAGE_C);
void spawn_weapon_bomb(Entity *entity, uint8_t entityIdx);
void despawn_weapon_bomb(Entity *entity, uint8_t entityIdx);
uint8_t update_weapon_bomb(Entity *entity, uint8_t entityIdx);
