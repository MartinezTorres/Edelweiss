typedef enum {
    
} TileIdx;

enum {
    TILE_WALKABLE = 0x01,
    TILE_SWIM_FLIPPERS_REQUIRED = 0x02,
    TILE_PLANT_BOOTS_REQUIRED = 0x04,
};

typedef struct {

    U8x8 shapes[2][4];
    U8x8 colors[2][4];
    
    uint8_t properties;
        
} TileDescription;

extern const TileDescription tileDescriptions[];



typedef struct {
    uint8_tp localization;
    EntityIdx idx;
    
} EntitySpawns;

typedef struct {
    TileIdx tileIdx[10][16];
    EntitySpawns entitySpawns[16];
} MapSection;

typedef struct {
    uint8_t segments[7][10];
    MapSection sections[7][10];
} Map;

