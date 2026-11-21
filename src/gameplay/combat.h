#pragma once

USING_MODULE(combat, PAGE_D);
enum { COMBAT_DEAD, COMBAT_READY, COMBAT_STUNNED };

/* Caller-owned entity state; no live projection crosses an engine effect. */
uint8_t combat_update(uint8_t spawn_idx);
uint8_t combat_update_d(uint8_t spawn_idx);
