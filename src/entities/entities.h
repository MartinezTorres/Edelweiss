#pragma once
#include <common.h>

struct Entity_T {
    union {
		uint8_t buffer[32];
		
		struct {
			uint8_t enabled;
			uint8_t active;
			
			uint8_t maximum_life;
			uint8_t life;
			uint8_t type;
			uint8_t info[4]; // to be used by the update routine
			uint8_t invulnerable_frames;
			
			uint8_t segment;
			void (*spawn)(struct Entity_T *, uint8_t entityIdx);
			void (*despawn)(struct Entity_T *, uint8_t entityIdx);
			uint8_t (*update)(struct Entity_T *, uint8_t entityIdx);
			
			uint16_tp pos;
			int16_tp vel;
			uint16_tp anchor;
			uint8_t animationCounter;
		};
	};
};

typedef struct Entity_T Entity;


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

USING_MODULE(entity_weapon_bomb, PAGE_C);
void spawn_weapon_bomb(Entity *entity, uint8_t entityIdx);
void despawn_weapon_bomb(Entity *entity, uint8_t entityIdx);
uint8_t update_weapon_bomb(Entity *entity, uint8_t entityIdx);
