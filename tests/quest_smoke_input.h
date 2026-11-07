#pragma once
#include <stdint.h>

extern volatile uint8_t edw_smoke_status, edw_smoke_capture, edw_smoke_messages;
extern uint8_t edw_smoke_keys[12], edw_smoke_key_count, edw_smoke_key_index, edw_smoke_menu;
extern uint8_t edw_smoke_random_calls;
void quest_smoke_checkpoint(uint8_t id);

extern char edw_smoke_password[11];
extern uint8_t edw_smoke_save_password;
uint8_t quest_smoke_getch(void);

extern volatile uint8_t edw_smoke_small_messages, edw_smoke_world_stage;
extern uint16_t edw_smoke_drop_roll;
extern uint8_t edw_smoke_drop_calls;
uint16_t quest_smoke_drop_random(void);
void drop_smoke_update(void);
void world_smoke(void);
uint8_t quest_smoke_town_random(void);
uint16_t quest_smoke_ghost_random(void);
void ghost_smoke_update(void);
extern uint8_t edw_smoke_town_calls, edw_smoke_ghost_calls;
