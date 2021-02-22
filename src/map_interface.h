#ifndef MAP_INTERFACE
#define MAP_INTERFACE

#include <msxhal.h>
#include <tms99X8.h>


// The following routines draw the corresponding tile(s) from the map to the PN buffer,
// and also update the pattern name tables if needed. Patterns previously appearing in the PN buffer
// are marked to be freed later, when not in use any more.
void APPEND(MAP_NAME,_draw_tile8)(uint8_t row, uint8_t col);
void APPEND(MAP_NAME,_draw_col)(uint8_t col);
void APPEND(MAP_NAME,_draw_row)(uint8_t row);

// The following routines draw a black tile (or anything in pattern nº0) to the PN buffer.
// Pattern previously appearing in the PN buffer are  marked to be freed later, when not in use any more.
void APPEND(MAP_NAME,_erase_tile8)(uint8_t row, uint8_t col);
void APPEND(MAP_NAME,_erase_col)(uint8_t col);
void APPEND(MAP_NAME,_erase_row)(uint8_t row);

// Pattern previously marked to be released ARE released, allowing them to be recycled.
void APPEND(MAP_NAME,_free)();
void APPEND(MAP_NAME,_free0)();
void APPEND(MAP_NAME,_free1)();
void APPEND(MAP_NAME,_free2)();

// Inits the map structure
void APPEND(MAP_NAME,_init)();

void APPEND(MAP_NAME,_update_animation)();
void APPEND(MAP_NAME,_iterate_animation)();

void APPEND(MAP_NAME,_copyPN0)();
void APPEND(MAP_NAME,_copyPN1)();
void APPEND(MAP_NAME,_copyPN0full)();
void APPEND(MAP_NAME,_copyPN1full)();

//INLINE void APPEND(MAP_NAME,_copyPN)(EM2_Buffer buffer) { buffer==0?APPEND(MAP_NAME,_copyPN0)():APPEND(MAP_NAME,_copyPN1)(); }

uint8_t APPEND(MAP_NAME,_get_flags)(uint16_t row, uint16_t col);
uint8_t APPEND(MAP_NAME,_get_tile16)(uint16_t row, uint16_t col);
void APPEND(MAP_NAME,_set_map_index)(uint16_t row, uint16_t col, uint8_t n);

#endif
