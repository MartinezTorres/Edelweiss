#include <common.h>


void wolfi_takes_damage() {
	
	if (state.entities[0].life > 1) {
		state.entities[0].life -= 1;
	} else {
		state.entities[0].life = 0;
	}
}

