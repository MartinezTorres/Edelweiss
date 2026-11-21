#pragma once
/* Runtime banks remain small even though Vexel resolves the whole game. */
USING_MODULE(world_orchestration,PAGE_C);
void world_begin_frame(uint8_t previous_isr_count);
void world_update_entities(void);
uint16_t world_scroll(uint8_t request_pattern_name_transfer_internal);
void world_follow(void);
void world_reveal(void);
void world_init_entities(void);
uint8_t world_call_update(Entity *entity);
