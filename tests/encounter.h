#pragma once
#include <stdint.h>
extern volatile uint8_t edw_encounter_marker,edw_encounter_error,edw_encounter_frame;
extern uint16_t edw_encounter_draws;
/* Z80 rand7 reads the refresh register: different instruction sequences cannot
 * share that stream. Use a reproducible stream in this test profile only. */
static inline uint8_t encounter_random(void) { return (uint8_t)(++edw_encounter_draws)&127; }
void encounter_setup(void);
void encounter_after(void);
void encounter_wolfi(void);
void encounter_wolfi_step(void);
void encounter_skeleti(void);
void encounter_ghosts(void);
extern uint8_t edw_melee_checks;
void encounter_melee(void);

extern uint8_t edw_projectile_checks;
void encounter_arrow(void);
void encounter_fire(void);
void encounter_bomb(void);

extern uint8_t edw_actor_checks;
extern uint16_t edw_ball_hash,edw_player_hash;
void encounter_spark(void);
void encounter_explosion(void);
void encounter_ball(void);
void encounter_player(void);
static inline uint16_t actor_hash(uint16_t hash,uint16_t value) {return (uint16_t)(((hash<<5)|(hash>>11))^value);}

void encounter_actor_policies(void);
void encounter_drops(void);
void encounter_fairy(void);
void encounter_follower(void);
