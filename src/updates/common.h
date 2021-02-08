#pragma once
#include <common.h>

USING_MODULE(update_wolfi, PAGE_C);
USING_MODULE(update_skeleti, PAGE_C);
USING_MODULE(update_ghosti, PAGE_C);

void spawn_wolfi(Entity *entity, uint8_t entityIdx);
void despawn_wolfi(Entity *entity, uint8_t entityIdx);
uint8_t update_wolfi(Entity *entity, uint8_t entityIdx);
void spawn_skeleti(Entity *entity, uint8_t entityIdx);
void despawn_skeleti(Entity *entity, uint8_t entityIdx);
uint8_t update_skeleti(Entity *entity, uint8_t entityIdx);
void spawn_ghosti(Entity *entity, uint8_t entityIdx);
void despawn_ghosti(Entity *entity, uint8_t entityIdx);
uint8_t update_ghosti(Entity *entity, uint8_t entityIdx);
