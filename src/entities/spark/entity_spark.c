#include <common.h>
#include <entities/spark/entity_spark_sprite.h>

USING_MODULE(entity_spark_sprite, PAGE_D);

static void on_spawn(Entity *entity) {
	
	uint8_t idx = entity->spawn_idx;
	
    sprites[idx].enabled = true;
    sprites[idx].patternBlackRequired = true;
    sprites[idx].patternColorRequired = true;
	sprites[idx].overrideColors = false;
	sprites[idx].spriteInfoSegment = MODULE_SEGMENT(entity_spark_sprite, PAGE_D);	
	sprites[idx].spriteInfo = (entity->spark_type==0?&spark_0_0:entity->spark_type==1?&spark_0_1:&spark_0_2);

	sprites[idx].pos = entity->pos;

	entity->animation_counter = 0;
}

static void on_despawn(Entity *entity) {

	uint8_t idx = entity->spawn_idx;
    sprites[idx].enabled = false;
}

static uint8_t on_update(Entity *entity) {

	uint8_t idx = entity->spawn_idx;

	for (uint8_t i=0; i<state.isr_count_delta; i++) {
		
		if (entity->animation_counter== 6) sprites[idx].spriteInfo = (entity->spark_type==0?&spark_1_0:entity->spark_type==1?&spark_1_1:&spark_1_2);
		if (entity->animation_counter==12) sprites[idx].spriteInfo = (entity->spark_type==0?&spark_2_0:entity->spark_type==1?&spark_2_1:&spark_2_2);
		if (entity->animation_counter==18) sprites[idx].spriteInfo = (entity->spark_type==0?&spark_3_0:entity->spark_type==1?&spark_3_1:&spark_3_2);
		if (entity->animation_counter==24) return false;
		entity->animation_counter++;
	}

	return true;
}

static const struct T_Entity_Callbacks callbacks = {
	on_spawn, on_despawn, on_update, on_hit_null
};

void init_spark(uint8_t idx) {

	Entity *entity = &state.entities[idx];

	entity->spark_type = 0;
	entity->spawn_auto = false;
	entity->spawn_idx = -1;
	entity->spawn_priority = 4;

	entity->segment = MODULE_SEGMENT(entity_spark, PAGE_C);
	entity->callbacks = &callbacks;
}
