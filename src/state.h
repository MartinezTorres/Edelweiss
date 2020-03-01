#pragma once
#include <common.h>

typedef struct {
    
    int16_tp pos, vel;
    
} Entity;


typedef struct {
    
    // Entities can have a bounding box and or are interactive: e.g., player, enemies, obstacles, traps, triggers, spawn points.
    SplitList_T(196,17,Entity) entities;
    
    uint8_t joy; // Joystick status;
    
    Entity player;
    
} State;

extern State state;
