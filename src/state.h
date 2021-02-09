#pragma once
#include <common.h>

struct Entity_T {
    
    uint8_t enabled;
    uint8_t active;
    
    uint8_t maximum_life;
    uint8_t life;
    uint8_t info[4]; // to be used by the update routine
    uint8_t invulnerable_frames;
    
    uint8_t segment;
    void (*spawn)(struct Entity_T *, uint8_t entityIdx);
    void (*despawn)(struct Entity_T *, uint8_t entityIdx);
    uint8_t (*update)(struct Entity_T *, uint8_t entityIdx);
    
    uint16_tp pos;
    int16_tp vel;
    uint16_tp anchor;
    uint8_t animationCounter;
    
};

typedef struct Entity_T Entity;


typedef struct {
	
	bool hasBoots;
	bool hasCoat;
	bool hasFruit;
	uint16_t rupees;
	enum {E_PAW, E_CLAW, E_SWORD, E_AXE, E_BOMB, E_FIRE, E_BOW, E_MASTER_SWORD} weapon;
	
	uint8_tp nextFlower;

    uint8_t nEntities;
    Entity entities[64]; // Entity 0 is the main player
    
    uint8_t nActiveEntities;
    int8_t activeEntities[8];
    
    uint8_t joy; // Joystick status;
    
} State;

extern State state;
