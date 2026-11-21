#include "encounter.h"
uint8_t edw_player_view;
void encounter_player_control(void) {
    Entity *e=&state.entities[0];
    edw_player_view=player_control(e);
    if(edw_player_view)player_view(e);
}
