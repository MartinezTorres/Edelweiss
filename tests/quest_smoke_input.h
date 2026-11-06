#pragma once
#include <stdint.h>

extern volatile uint8_t edw_smoke_status, edw_smoke_capture;
extern uint8_t edw_smoke_keys[2], edw_smoke_key_count, edw_smoke_key_index, edw_smoke_menu;
void quest_smoke_checkpoint(uint8_t id);
