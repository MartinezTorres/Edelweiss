#pragma once 
#include <common.h>

void popupInitCanvas(uint8_t x, uint8_t y);

void popupSetPoint(uint8_t x, uint8_t y, uint8_t value, uint8_t color);

void popupWriteText(const char *str);

void largePopupInitCanvas(uint8_t x);

void largePopupSetPoint(uint8_t x, uint8_t y, uint8_t value, uint8_t color);

void largePopupWriteText(const char *str);

typedef struct {
	uint8_t font_segment;
    const uint16_t *font_pts;
    const uint16_t *font_pos;
    const uint8_t *font_len;
    uint8_t space_between_lines;

    int16_t x, y;
    uint8_t value;
    uint8_t color;
    uint8_t sz;
    uint8_t faster; // Skips color, history, and ROI calculations
    
    void (*dotCallback)();
    void (*charCallback)();    
} TTextProperties;
extern TTextProperties popupTextProperties;
extern TTextProperties largePopupTextProperties;


USING_MODULE(popup, PAGE_C);

extern const uint16_t font_newsgeek_pts[];
extern const uint16_t font_newsgeek_pos[];
extern const uint8_t font_newsgeek_len[];
USING_MODULE(font_newsgeek, PAGE_D);

extern const uint16_t font_didone_pts[];
extern const uint16_t font_didone_pos[];
extern const uint8_t font_didone_len[];
USING_MODULE(font_didone, PAGE_D);


extern const uint16_t font_tiny_pts[];
extern const uint16_t font_tiny_pos[];
extern const uint8_t font_tiny_len[];
USING_MODULE(font_tiny, PAGE_D);

extern const uint16_t font_thin_pts[];
extern const uint16_t font_thin_pos[];
extern const uint8_t font_thin_len[];
USING_MODULE(font_thin, PAGE_D);

//void graphicsInitCO(uint8_t co, EObjectClass oClass);
//void graphicsUpdateCOs();
