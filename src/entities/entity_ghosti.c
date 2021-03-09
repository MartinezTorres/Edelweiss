#include <common.h>
#include <entities/entity_ghosti_sprite.h>

USING_MODULE(entity_ghosti_sprite, PAGE_D);

static void on_spawn(Entity *entity) {
	
	uint8_t idx = entity->spawn_idx;
    sprites[idx].enabled = true;
    sprites[idx].patternBlackRequired = true;
    sprites[idx].patternColorRequired = true;
    sprites[idx].spriteInfoSegment = MODULE_SEGMENT(entity_ghosti_sprite, PAGE_D);	
}

static void on_despawn(Entity *entity) {
	
	uint8_t idx = entity->spawn_idx;
    sprites[idx].enabled = false;
}

static uint8_t on_update(Entity *entity) {
	
	uint8_t idx = entity->spawn_idx;
	

	if (((state.game_cycles+idx)&3) != 0) return true;

	entity->vel.i += ((int16_t)(entity->anchor.i - entity->pos.i))/512;
	entity->vel.j += ((int16_t)(entity->anchor.j - entity->pos.j))/512;

	entity->pos.i += entity->vel.i;
	entity->pos.j += entity->vel.j;

	sprites[idx].pos.i = entity->pos.i;
	sprites[idx].pos.j = entity->pos.j;

	if ((idx&7) == 0) {
		sprites[idx].spriteInfo = (entity->vel.j>0?&ghosti_0_0 : &ghosti_0_1) ;
	} else if ((idx&7) == 1) {
		sprites[idx].spriteInfo = (entity->vel.j>0?&ghosti_1_0 : &ghosti_1_1) ;
	} else if ((idx&7) == 2) {
		sprites[idx].spriteInfo = (entity->vel.j>0?&ghosti_2_0 : &ghosti_2_1) ;
	} else if ((idx&7) == 3) {
		sprites[idx].spriteInfo = (entity->vel.j>0?&ghosti_3_0 : &ghosti_3_1) ;
	} else if ((idx&7) == 4) {
		sprites[idx].spriteInfo = (entity->vel.j>0?&ghosti_4_0 : &ghosti_4_1) ;
	} else if ((idx&7) == 5) {
		sprites[idx].spriteInfo = (entity->vel.j>0?&ghosti_5_0 : &ghosti_5_1) ;
	} else {
		sprites[idx].spriteInfo = (entity->vel.j>0?&ghosti_6_0 : &ghosti_6_1) ;
	}

	return true;
}


static uint8_t on_hit(Entity *entity, Entity *weapon) {
	
	if (entity->invulnerable_frames) {
		
		return true;
	}
	
	if (entity->life > weapon->damage) {
		
		entity->life -= weapon->damage;
		return true;
		// TODO: add push
	} 
	
	entity->life = 0;
	return false;
	// TODO: death animation
}

void init_ghosti(uint8_t idx, uint8_t i, uint8_t j) {

	Entity *entity = &state.entities[idx];

	entity->enabled = true;
	entity->spawn_idx = -1;
	entity->spawn_priority = 6;

	entity->anchor.i = ((uint16_t)i)<<8;
	entity->anchor.j = ((uint16_t)j)<<8;

	entity->pos.i = ((uint16_t)i)<<8;
	entity->pos.j = ((uint16_t)j)<<8;

	entity->vel.i = (rand7()>>2)&0x3 - 0x02;
	entity->vel.j = (rand7()>>2)&0xF - 0x07;

	entity->push.i = 0;
	entity->push.j = 0;

	entity->life = 4;
	entity->maximum_life = 4;
	entity->invulnerable_frames = 0;

	entity->damage = 1;

	entity->segment = MODULE_SEGMENT(entity_ghosti, PAGE_C);
	entity->on_spawn   = on_spawn;
	entity->on_despawn = on_despawn;
	entity->on_update  = on_update;
	entity->on_hit  = on_hit;

}
