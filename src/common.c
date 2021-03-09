#include <common.h>

struct T_State state;

#ifndef MSX
    T_Map map;
#endif

void trampoline_page_c( uint8_t segment, void (*f)() ) {
	
    uint8_t oldSegmentPageC = mapper_load_segment(segment, PAGE_C);
    (*f)();
    mapper_load_segment(oldSegmentPageC, PAGE_C);
}

bool spawn_entity(uint8_t idx) {

	Entity *entity = &state.entities[idx];

	for (uint8_t k=entity->spawn_priority; k<12; k++) { 
		if (state.spawns[k] < 0) {

			state.spawns[k] = idx;
			state.num_spawns++;

			IN_SEGMENT(
				entity->segment, 
				PAGE_C,         
				entity->spawn_idx = k;
				(*entity->on_spawn)(entity);
			);
			
			return true;
		}
	}
	return false;
}
