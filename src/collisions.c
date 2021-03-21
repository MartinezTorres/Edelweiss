#include <common.h>

void on_hit_default(Entity *entity, Entity *aggressor) {

	uint8_t oldSegmentPageD = mapper_load_module(collisions_d, PAGE_D);
    on_hit_default_d(entity, aggressor);
    mapper_load_segment(oldSegmentPageD, PAGE_D);
}

void on_hit_null(Entity *entity, Entity *weapon) {
	
	UNUSED(entity);
	UNUSED(weapon);
}
