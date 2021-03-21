#include <common.h>

////////////////////////////////////////////////////////////////////////
// Implementation variables
static uint8_t PN_Idx;
static uint8_t bank;
static T_MapBank *bankPtr;

static const uint8_t *tile16IdxPtr;
static const uint8_t *tile8IdxBase;
static const uint8_t *stagesPtr;

static void populateTile8(const uint8_t *tile8IdxPtr) __z88dk_fastcall;
static void populateTile8L(const uint8_t *tile8IdxPtr) __z88dk_fastcall;
static void populateTile8R(const uint8_t *tile8IdxPtr) __z88dk_fastcall;
#ifdef MSX

inline static void populateTile8_placeholder() {
    
    __asm

_populateTile8:
    ld  a, (_PN_Idx)
    bit 0,a
    jp Z, _populateTile8L
    jp _populateTile8R
    
_populateTile8L:
    ld  l, (hl) ; l: tile8idx
    ld  a, (#(_bankPtr+1))
    ld  h, a 
	ld	a, (hl)
	or	a, a
    jp  Z, loadTile8L
	inc	a
	ld	(hl), a ; countL[tileIdx]++;
    inc h
    inc h
    ld  e, l
    ld  d, (hl) ; d: is the pattern ; h: is patternL ; e: is tileIdx
    inc h
    inc h ; h is tile8
    ld  a, (_PN_Idx)
    ld  l, a ; hl is &tile8[PN_Idx]
    ld  a, (hl) ; a is oldTile
    ld  (hl), e ; tile8[PN_Idx] = tileIdx
    inc h ; hl is &PN[PN_Idx]
    ld  (hl), d ; PN[PN_Idx] = pattern
    or a, a
    ret Z
    inc h
    inc h
    ld  l,#0x7F
    ld  c,(hl)
    inc (hl)
    ld  l,c
    ld  (hl),a
    ret
    
    

_populateTile8R:
    ld  l, (hl) ; l: tile8idx
    ld  a, (#(_bankPtr+1))
    ld  h, a 
    inc h
	ld	a, (hl)
	or	a, a
    jp  Z, loadTile8R
	inc	a
	ld	(hl), a ; countR[tileIdx]++;
    inc h
    inc h
    ld  e, l
    ld  d, (hl) ; d: is the pattern ; h: is patternR ; e: is tileIdx
    inc h ; h is tile8
    ld  a, (_PN_Idx)
    ld  l, a ; hl is &tile8[PN_Idx]
    ld  a, (hl) ; a is oldTile
    ld  (hl), e ; tile8[PN_Idx] = tileIdx
    inc h ; hl is &PN[PN_Idx]
    ld  (hl), d ; PN[PN_Idx] = pattern
    or a, a
    ret Z
    inc h
    inc h
    ld  l,#0xFF
    ld  c,(hl)
    inc (hl)
    set 7,c
    ld  l,c
    ld  (hl),a
    ret

loadTile8L:
	inc	a
	ld	(hl), a ; countL[tileIdx]++;
    ld  b, l
    ld  a, h 
    add	a, #0x06
	ld  h, a 
    ld  l, #0x70
	ld	a, (hl)
    ld  c, a
    inc a
    ld  (hl), a
    ld  l, c
    ld  c, (hl)
    // b is tile8Idx
    // c is the new pattern.
    dec h
	ld	a, (_PN_Idx)
    ld  l, a
    ld  (hl), c // bankPtr->PN[PN_Idx] = patternIdx;
    dec h
    ld  d, (hl) // d = oldTile
    ld  (hl), b // bankPtr->tile8[PN_Idx] = tile8Idx;
    dec h
    dec h
    ld  l, b
    ld  (hl), c // bankPtr->patternL[tile8Idx] = patternIdx;

    //mapper_load_module(MAP_TILES8, PAGE_C);
    ld a, #<( APPEND( _MAPPER_MODULE_, APPEND( MAP_NAME, _tiles8L_PAGE_C) ) )
    ld (#0x9000), a
    
    ld  a, d
    or a, a
    jp Z, uploadTile8
    inc h
    inc h
    inc h
    inc h
    inc h
    ld  l,#0x7F
    ld  e,(hl)
    inc (hl)
    ld  l,e
    ld  (hl),a
    jp uploadTile8

loadTile8R:
	inc	a
	ld	(hl), a ; countR[tileIdx]++;
    ld  b, l
    ld  a, h 
    add	a, #0x05
	ld  h, a 
    ld  l, #0x70
	ld	a, (hl)
    ld  c, a
    inc a
    ld  (hl), a
    ld  l, c
    ld  c, (hl)
    // b is tile8Idx
    // c is the new pattern.
    dec h
	ld	a, (_PN_Idx)
    ld  l, a
    ld  (hl), c // bankPtr->PN[PN_Idx] = patternIdx;
    dec h
    ld  d, (hl) // d = oldTile
    ld  (hl), b // bankPtr->tile8[PN_Idx] = tile8Idx;
    dec h
    ld  l, b
    ld  (hl), c // bankPtr->patternR[tile8Idx] = patternIdx;

    //mapper_load_module(MAP_TILES8, PAGE_C);
    ld a, #<( APPEND( _MAPPER_MODULE_, APPEND( MAP_NAME, _tiles8R_PAGE_C) ) )
    ld (#0x9000), a


    ld  a, d
    or a, a
    jp Z, uploadTile8
    inc h
    inc h
    inc h
    inc h
    ld  l,#0xFF
    ld  e,(hl)
    inc (hl)
    set 7,e
    ld  l,e
    ld  (hl),a
    
uploadTile8:
;src/map/implementation.h:164: register uint16_t dst = MODE2_ADDRESS_PG + bank*(8*256) + (((uint16_t)patternIdx)<<3);
	ld	a,(_bank)
    ld  h, a
    ld  l, c
    add hl, hl
    add hl, hl
    add hl, hl
    ex  de, hl

;src/map/implementation.h:165: register const uint8_t *p = &MAP_TILES8[tile8Idx][0][0];
	ld	h, #0x04 //_overworld_tiles8 / 32
	ld	l, b
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl
	add	hl, hl

;src/map/implementation.h:169: VDP1 = dst & 0xFF; 
	ld	a, e
	out	(_VDP1), a
;src/map/implementation.h:170: VDP1 = 0x40 | (dst>>8);
	ld	a, d
	or	a, #0x40
	out	(_VDP1), a
    ld  c, #_VDP0
    ld  a, #16
    ld  b, a
;src/map/implementation.h:171: REPEAT16(VDP0 = *p++;);
loadTile8_l1:
    outi
    jp nz, loadTile8_l1

;src/map/implementation.h:173: dst += (MODE2_ADDRESS_CT - MODE2_ADDRESS_PG);
;src/map/implementation.h:175: VDP1 = dst & 0xFF; 
	ld	a, e
	out	(_VDP1), a
;src/map/implementation.h:176: VDP1 = 0x40 | (dst>>8);
	ld	a, d
	or	a, #0x60
	out	(_VDP1), a
;src/map/implementation.h:177: REPEAT16(VDP0 = *p++;);
    ld  a, #16
    ld  b, a
loadTile8_l2:
    outi
    jp nz, loadTile8_l2
;src/map/implementation.h:179: 

    ld a, #<( APPEND( _MAPPER_MODULE_, APPEND( MAP_NAME, _tiles16_PAGE_C) ) )
    ld (#0x9000), a

	ret

    __endasm;
}

# else

static uint8_t getPattern(uint8_t bank) { return map.bank[bank].freePatterns[map.bank[bank].numUsedPatterns++]; }

static void populateTile8(const uint8_t *tile8IdxPtr) __z88dk_fastcall {
    
    if ((PN_Idx & 1) == 0) 
        populateTile8L(tile8IdxPtr);
    else
        populateTile8R(tile8IdxPtr);
}

static void populateTile8L(const uint8_t *tile8IdxPtr) __z88dk_fastcall {

    uint8_t tile8Idx = *tile8IdxPtr;

    if (bankPtr->countL[tile8Idx]++ == 0) {
        
        uint8_t patternIdx = bankPtr->patternL[tile8Idx] = getPattern(bank);
        mapper_load_module(MAP_TILES8L, PAGE_C);
        TMS99X8_memcpy(MODE2_ADDRESS_PG + bank*(8*256) + (((uint16_t)patternIdx)<<3), MAP_TILES8L[tile8Idx][0], 16);
        TMS99X8_memcpy(MODE2_ADDRESS_CT + bank*(8*256) + (((uint16_t)patternIdx)<<3), MAP_TILES8L[tile8Idx][1], 16);
    }
    
    {
        uint8_t oldTile = bankPtr->tile8[PN_Idx];
        if (oldTile) bankPtr->tilesToReleaseL[bankPtr->numTilesToReleaseL++] = oldTile;
    }
    
    bankPtr->tile8[PN_Idx] = tile8Idx;
    bankPtr->PN[PN_Idx] = bankPtr->patternL[tile8Idx];
}

static void populateTile8R(const uint8_t *tile8IdxPtr) __z88dk_fastcall {
    
    uint8_t tile8Idx = *tile8IdxPtr;
    if (bankPtr->countR[tile8Idx]++ == 0) {
        
        uint8_t patternIdx = bankPtr->patternR[tile8Idx] = getPattern(bank);
        mapper_load_module(MAP_TILES8R, PAGE_C);
        TMS99X8_memcpy(MODE2_ADDRESS_PG + bank*(8*256) + (((uint16_t)patternIdx)<<3), MAP_TILES8R[tile8Idx][0], 16);
        TMS99X8_memcpy(MODE2_ADDRESS_CT + bank*(8*256) + (((uint16_t)patternIdx)<<3), MAP_TILES8R[tile8Idx][1], 16);
    }

    {
        uint8_t oldTile = bankPtr->tile8[PN_Idx];
        if (oldTile) bankPtr->tilesToReleaseR[bankPtr->numTilesToReleaseR++] = oldTile;
    }

    bankPtr->tile8[PN_Idx] = tile8Idx;
    bankPtr->PN[PN_Idx] = bankPtr->patternR[tile8Idx];
}

#endif

static void renew_col_int_blockL();
static void renew_col_int_blockR();

#ifdef MSX
inline static void renew_col_int_blockL_placeholder() {

__asm
;	---------------------------------
; Function renew_col_int_blockL
; ---------------------------------
_renew_col_int_blockL:
;src/map/implementation.h:615: const uint8_t *tile8IdxPtr = tile8IdxBase + 4 * *tile16IdxPtr;
	ld	hl, (_tile16IdxPtr)
	ld	l, (hl)
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	ld	de, (_tile8IdxBase)
	add	hl, de
    push hl
	call	_populateTile8L
	ld	a, (_PN_Idx)
	add	a, #0x20
	ld	(_PN_Idx), a
;src/map/implementation.h:617: populateTile8L(tile8IdxPtr + 2); PN_Idx += 32;
	pop	hl
	inc	l
	inc	l
	call	_populateTile8L
	ld	a, (_PN_Idx)
	add	a, #0x20
	ld	(_PN_Idx), a
;src/map/implementation.h:618: tile16IdxPtr += MAP16_X; 
	ld	hl, #_tile16IdxPtr
	ld	a, (hl)
	add	a, #0x80
	ld	(hl), a
	ret	NC
	inc	hl
	inc	(hl)
;src/map/implementation.h:619:
	ret
__endasm;    
    
}

inline static void renew_col_int_blockR_placeholder() {


__asm
;	---------------------------------
; Function renew_col_int_blockR
; ---------------------------------
_renew_col_int_blockR:
;src/map/implementation.h:622: const uint8_t *tile8IdxPtr = tile8IdxBase + 4 * *tile16IdxPtr;
	ld	hl, (_tile16IdxPtr)
	ld	l, (hl)
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	ld	de, (_tile8IdxBase)
	add	hl, de
    push hl
;src/map/implementation.h:623: populateTile8R(tile8IdxPtr); PN_Idx += 32;
	call	_populateTile8R
	ld	a, (_PN_Idx)
	add	a, #0x20
	ld	(_PN_Idx), a
;src/map/implementation.h:617: populateTile8L(tile8IdxPtr + 2); PN_Idx += 32;
	pop	hl
	inc	l
	inc	l
	call	_populateTile8R
	ld	a, (_PN_Idx)
	add	a, #0x20
	ld	(_PN_Idx), a
;src/map/implementation.h:618: tile16IdxPtr += MAP16_X; 
	ld	hl, #_tile16IdxPtr
	ld	a, (hl)
	add	a, #0x80
	ld	(hl), a
	ret	NC
	inc	hl
	inc	(hl)
;src/map/implementation.h:619:
	ret
__endasm;    
}


#else
static void renew_col_int_blockL() {
    const uint8_t *tile8IdxPtr = tile8IdxBase + 4 * *tile16IdxPtr;
    populateTile8L(tile8IdxPtr); PN_Idx += 32;
    populateTile8L(tile8IdxPtr + 2); PN_Idx += 32;
    tile16IdxPtr += MAP16_X; 
}

static void renew_col_int_blockR() {
    const uint8_t *tile8IdxPtr = tile8IdxBase + 4 * *tile16IdxPtr;
    populateTile8R(tile8IdxPtr); PN_Idx += 32;
    populateTile8R(tile8IdxPtr + 2); PN_Idx += 32;
    tile16IdxPtr += MAP16_X; 
}
#endif

INLINE void _draw_col(uint8_t colScreen8) { 
        
    uint8_t rowWorld8 = map.pos.i;
    uint8_t colWorld8 = colScreen8 + map.pos.j;

    uint8_t rowWorld16 = rowWorld8 >> 1;
    uint8_t colWorld16 = colWorld8 >> 1;

    tile16IdxPtr = &MAP_MAP16[rowWorld16][colWorld16];
    tile8IdxBase = &MAP_TILES16[0][0][colWorld8&1];
        
        
    stagesPtr = &map.stages[rowWorld16>>1][colWorld16>>1];
    mapper_load_segment(*stagesPtr, PAGE_D); // stages apply in blocks of 32x32 pixels
    
    PN_Idx =  (rowWorld8<<5) + colWorld8;
    mapper_load_module(MAP_TILES16, PAGE_C);
    
    if ((colWorld8&1)==0) {
        if ((map.pos.i&1)==0)  {
            if ((rowWorld16&1)==0) {
                UNROLL4(0,3, 
                    bank = n;
                    bankPtr = &map.bank[n];
                    
                    renew_col_int_blockL();
                    renew_col_int_blockL();                        
                    { register const uint8_t *p = stagesPtr; p += 64; mapper_load_segment_fast(*p, PAGE_D); stagesPtr=p; }

                    renew_col_int_blockL();
                    renew_col_int_blockL();                        
                    { register const uint8_t *p = stagesPtr; p += 64; mapper_load_segment_fast(*p, PAGE_D); stagesPtr=p; }

                );
            } else {
                UNROLL4(0,3, 
                    bank = n;
                    bankPtr = &map.bank[n];
                    
                    renew_col_int_blockL();
                    { register const uint8_t *p = stagesPtr; p += 64; mapper_load_segment_fast(*p, PAGE_D); stagesPtr=p; }


                    renew_col_int_blockL();
                    renew_col_int_blockL();
                    { register const uint8_t *p = stagesPtr; p += 64; mapper_load_segment_fast(*p, PAGE_D); stagesPtr=p; }


                    renew_col_int_blockL(); 
                );
            }
        } else {
            if ((rowWorld16&1)==0) {
                UNROLL4(0,3, 
                    const uint8_t *tile8IdxPtr;

                    bank = n;
                    bankPtr = &map.bank[n];
                                            
                    tile8IdxPtr = tile8IdxBase + 4 * *tile16IdxPtr;
                    populateTile8L(tile8IdxPtr + 2); PN_Idx += 32;
                    tile16IdxPtr += MAP16_X; 

                    renew_col_int_blockL();
                    { register const uint8_t *p = stagesPtr; p += 64; mapper_load_segment_fast(*p, PAGE_D); stagesPtr=p; }


                    renew_col_int_blockL();
                    renew_col_int_blockL();
                    { register const uint8_t *p = stagesPtr; p += 64; mapper_load_segment_fast(*p, PAGE_D); stagesPtr=p; }


                    tile8IdxPtr = tile8IdxBase + 4 * *tile16IdxPtr;
                    populateTile8L(tile8IdxPtr); PN_Idx += 32;
                );
            } else {
                UNROLL4(0,3, 
                    const uint8_t *tile8IdxPtr;

                    bank = n;
                    bankPtr = &map.bank[n];
                    
                    tile8IdxPtr = tile8IdxBase + 4 * *tile16IdxPtr;
                    populateTile8L(tile8IdxPtr + 2); PN_Idx += 32;
                    tile16IdxPtr += MAP16_X; 
                    { register const uint8_t *p = stagesPtr; p += 64; mapper_load_segment_fast(*p, PAGE_D); stagesPtr=p; }


                    renew_col_int_blockL();
                    renew_col_int_blockL();
                    { register const uint8_t *p = stagesPtr; p += 64; mapper_load_segment_fast(*p, PAGE_D); stagesPtr=p; }


                    renew_col_int_blockL();
                    tile8IdxPtr = tile8IdxBase + 4 * *tile16IdxPtr;
                    populateTile8L(tile8IdxPtr); PN_Idx += 32;
                );
            }            
        }
    } else {
        if ((map.pos.i&1)==0)  {
            if ((rowWorld16&1)==0) {
                UNROLL4(0,3, 
                    bank = n;
                    bankPtr = &map.bank[n];
                    
                    renew_col_int_blockR();
                    renew_col_int_blockR();
                    { register const uint8_t *p = stagesPtr; p += 64; mapper_load_segment_fast(*p, PAGE_D); stagesPtr=p; }


                    renew_col_int_blockR();
                    renew_col_int_blockR();
                    { register const uint8_t *p = stagesPtr; p += 64; mapper_load_segment_fast(*p, PAGE_D); stagesPtr=p; }

                );
            } else {
                UNROLL4(0,3, 
                    bank = n;
                    bankPtr = &map.bank[n];
                    
                    renew_col_int_blockR();
                    { register const uint8_t *p = stagesPtr; p += 64; mapper_load_segment_fast(*p, PAGE_D); stagesPtr=p; }


                    renew_col_int_blockR();
                    renew_col_int_blockR();
                    { register const uint8_t *p = stagesPtr; p += 64; mapper_load_segment_fast(*p, PAGE_D); stagesPtr=p; }


                    renew_col_int_blockR();
                );
            }
        } else {
            if ((rowWorld16&1)==0) {
                UNROLL4(0,3, 
                    const uint8_t *tile8IdxPtr;

                    bank = n;
                    bankPtr = &map.bank[n];
                    
                    tile8IdxPtr = tile8IdxBase + 4 * *tile16IdxPtr;
                    populateTile8R(tile8IdxPtr + 2); PN_Idx += 32;
                    tile16IdxPtr += MAP16_X; 

                    renew_col_int_blockR();
                    { register const uint8_t *p = stagesPtr; p += 64; mapper_load_segment_fast(*p, PAGE_D); stagesPtr=p; }


                    renew_col_int_blockR();
                    renew_col_int_blockR();
                    { register const uint8_t *p = stagesPtr; p += 64; mapper_load_segment_fast(*p, PAGE_D); stagesPtr=p; }


                    tile8IdxPtr = tile8IdxBase + 4 * *tile16IdxPtr;
                    populateTile8R(tile8IdxPtr); PN_Idx += 32;
                );
            } else {
                UNROLL4(0,3, 
                    const uint8_t *tile8IdxPtr;

                    bank = n;
                    bankPtr = &map.bank[n];
                    
                    tile8IdxPtr = tile8IdxBase + 4 * *tile16IdxPtr;
                    populateTile8R(tile8IdxPtr + 2); PN_Idx += 32;
                    tile16IdxPtr += MAP16_X; 
                    { register const uint8_t *p = stagesPtr; p += 64; mapper_load_segment_fast(*p, PAGE_D); stagesPtr=p; }


                    renew_col_int_blockR();
                    renew_col_int_blockR();
                    { register const uint8_t *p = stagesPtr; p += 64; mapper_load_segment_fast(*p, PAGE_D); stagesPtr=p; }


                    renew_col_int_blockR();
                    tile8IdxPtr = tile8IdxBase + 4 * *tile16IdxPtr;
                    populateTile8R(tile8IdxPtr); PN_Idx += 32;
                );
            }            
        }
    }
}

void APPEND(MAP_NAME,_draw_col)(uint8_t colScreen8) {  
	
#ifdef MSX
	_draw_col(colScreen8); 
#else
	for (uint8_t i=0; i<24; i++)
		APPEND(MAP_NAME,_draw_tile8)(i, colScreen8);
#endif
}


INLINE void _draw_tile8(uint8_t rowScreen8, uint8_t colScreen8) {

    uint8_t rowWorld8 = rowScreen8 + map.pos.i;
    uint8_t colWorld8 = colScreen8 + map.pos.j;

    uint8_t rowWorld16 = rowWorld8 >> 1;
    uint8_t colWorld16 = colWorld8 >> 1;

    bank = rowScreen8>>3;
    bankPtr = &map.bank[bank];
    PN_Idx =  (rowWorld8<<5) + colWorld8;

    mapper_load_segment(map.stages[rowWorld16>>1][colWorld16>>1], PAGE_D); // stages apply in blocks of 32x32 pixels
	
#ifdef MSX
	const uint8_t (*map_map16)[64][128] = &MAP_MAP16;
#else 
	
	const uint8_t (*map_map16)[64][128];
	
	if (map.stages[rowWorld16>>1][colWorld16>>1] == 0) map_map16 = &MAP0_MAP16;
	if (map.stages[rowWorld16>>1][colWorld16>>1] == 1) map_map16 = &MAP1_MAP16;
	if (map.stages[rowWorld16>>1][colWorld16>>1] == 2) map_map16 = &MAP2_MAP16;
	if (map.stages[rowWorld16>>1][colWorld16>>1] == 3) map_map16 = &MAP3_MAP16;
#endif


    uint8_t old_c = mapper_load_module(MAP_TILES16, PAGE_C);
    {
        uint8_t tile16Idx = (*map_map16)[rowWorld16][colWorld16];
        const uint8_t *tile8IdxPtr = &MAP_TILES16[tile16Idx][rowWorld8&1][colWorld8&1];
        
        populateTile8(tile8IdxPtr);
    }
    mapper_load_segment(old_c, PAGE_C);
}


void APPEND(MAP_NAME,_draw_tile8)(uint8_t rowScreen8, uint8_t colScreen8) { _draw_tile8(rowScreen8, colScreen8); }

static void renew_row_int_block();
#ifdef MSX

inline static void renew_row_int_block_placeholder() {

__asm
;	---------------------------------
; Function renew_row_int_block
; ---------------------------------
_renew_row_int_block:
	ld	hl, (_tile16IdxPtr)
	ld	l, (hl)
	ld	h, #0x00
	add	hl, hl
	add	hl, hl
	ld	de, (_tile8IdxBase)
	add	hl, de
    push hl
	call	_populateTile8L
	ld	hl, #_PN_Idx
	inc	(hl)
    pop hl
    inc hl
	call	_populateTile8R
	ld	hl, #_PN_Idx
	inc	(hl)
	ld	hl, (_tile16IdxPtr)
	inc	hl
	ld	(_tile16IdxPtr), hl
	ret
__endasm;    

}

#else

INLINE void renew_row_int_block() {
    
    const uint8_t *tile8IdxPtr = tile8IdxBase + 4 * *tile16IdxPtr;
    populateTile8L(tile8IdxPtr); PN_Idx ++;
    populateTile8R(tile8IdxPtr + 1); PN_Idx ++;
    tile16IdxPtr ++; 
}

#endif

void APPEND(MAP_NAME,_draw_row)(uint8_t rowScreen8) {
    

#ifdef MSX
	uint8_t rowWorld8 = rowScreen8 + map.pos.i;
	uint8_t colWorld8 =  map.pos.j;

	uint8_t rowWorld16 = rowWorld8 >> 1;
	uint8_t colWorld16 = colWorld8 >> 1;

	tile16IdxPtr = &MAP_MAP16[rowWorld16][colWorld16];
	tile8IdxBase = &MAP_TILES16[0][rowWorld8&1][0];
		
		
	stagesPtr = &map.stages[rowWorld16>>1][colWorld16>>1];
	mapper_load_segment(*stagesPtr, PAGE_D); // stages apply in blocks of 32x32 pixels
	
	PN_Idx =  (rowWorld8<<5) + colWorld8;
	mapper_load_module(MAP_TILES16, PAGE_C);
	
	bank = rowScreen8>>3;
	bankPtr = &map.bank[bank];
	
	if ((map.pos.j&1)==0)  {
		if ((colWorld16&1)==0) {
			REPEAT8(
				renew_row_int_block();
				renew_row_int_block();
				{ register const uint8_t *p = stagesPtr; p += 1; mapper_load_segment_fast(*p, PAGE_D); stagesPtr=p; }
			);

		} else {
			REPEAT8(
				renew_row_int_block();
				{ register const uint8_t *p = stagesPtr; p += 1; mapper_load_segment_fast(*p, PAGE_D); stagesPtr=p; }
				renew_row_int_block();
			);
		}
	} else {
		if ((colWorld16&1)==0) {
			{
				const uint8_t *tile8IdxPtr = tile8IdxBase + 4 * *tile16IdxPtr;
				populateTile8R(tile8IdxPtr + 1); PN_Idx ++;
				tile16IdxPtr ++; 
			}
			UNROLL8(0,7,
				renew_row_int_block();
				{ register const uint8_t *p = stagesPtr; p += 1; mapper_load_segment_fast(*p, PAGE_D); stagesPtr=p; }
				renew_row_int_block();
			);
			renew_row_int_block();
			{ register const uint8_t *p = stagesPtr; p += 1; mapper_load_segment_fast(*p, PAGE_D); stagesPtr=p; }
			{
				const uint8_t *tile8IdxPtr = tile8IdxBase + 4 * *tile16IdxPtr;
				populateTile8L(tile8IdxPtr); PN_Idx ++;
			}
		

		} else {
			{
				const uint8_t *tile8IdxPtr = tile8IdxBase + 4 * *tile16IdxPtr;
				populateTile8R(tile8IdxPtr + 1); PN_Idx ++;
				tile16IdxPtr ++; 
			}
			{ register const uint8_t *p = stagesPtr; p += 1; mapper_load_segment_fast(*p, PAGE_D); stagesPtr=p; }
			UNROLL8(0,7,
				renew_row_int_block();
				renew_row_int_block();
				{ register const uint8_t *p = stagesPtr; p += 1; mapper_load_segment_fast(*p, PAGE_D); stagesPtr=p; }
			);
			renew_row_int_block();
			{
				const uint8_t *tile8IdxPtr = tile8IdxBase + 4 * *tile16IdxPtr;
				populateTile8L(tile8IdxPtr); PN_Idx ++;
				tile16IdxPtr ++; 
			}                        
		}
    }

#else
	for (uint8_t i=0; i<32; i++)
		APPEND(MAP_NAME,_draw_tile8)(rowScreen8, i);
#endif
}


void APPEND(MAP_NAME,_erase_tile8)(uint8_t rowScreen8, uint8_t colScreen8) {
    
	uint8_t rowWorld8 = rowScreen8 + map.pos.i;
	uint8_t colWorld8 = colScreen8 + map.pos.j;

	bank = rowScreen8>>3;
	bankPtr = &map.bank[bank];
	PN_Idx =  (rowWorld8<<5) + colWorld8;
	
	{
		uint8_t oldTile = bankPtr->tile8[PN_Idx];
		if (oldTile) {
			if ((colWorld8&1)==0) {
				bankPtr->tilesToReleaseL[bankPtr->numTilesToReleaseL++] = oldTile;
			} else {
				bankPtr->tilesToReleaseR[bankPtr->numTilesToReleaseR++] = oldTile;
			}
		}
	}
	
	bankPtr->tile8[PN_Idx] = 0;
	bankPtr->PN[PN_Idx] = 0;
}

void APPEND(MAP_NAME,_erase_col)(uint8_t colScreen8) {

	uint8_t i=0;
	for (i=0; i<24; i++)
		APPEND(MAP_NAME,_erase_tile8)(i,colScreen8);
}

void APPEND(MAP_NAME,_erase_row)(uint8_t rowScreen8) {
    
	uint8_t j=0;
	for (j=0; j<32; j++)
		APPEND(MAP_NAME,_erase_tile8)(rowScreen8,j);        
}


INLINE void free_int_inline(uint8_t b) {
    
//    printf("Freeing from bank %d: %d and %d tiles\n", b, map.bank[b].numTilesToReleaseL, map.bank[b].numTilesToReleaseR);
//    printf("Freeing from bank %d: uses %d tiles\n", b, map.bank[b].numUsedPatterns);
    
    while (map.bank[b].numTilesToReleaseL) {
        uint8_t oldTile = map.bank[b].tilesToReleaseL[--map.bank[b].numTilesToReleaseL];
        if (--map.bank[b].countL[oldTile]==0) {
            uint8_t pattern = map.bank[b].patternL[oldTile];
            map.bank[b].freePatterns[--map.bank[b].numUsedPatterns] = pattern;
        }
    }

    while (map.bank[b].numTilesToReleaseR) {
        uint8_t oldTile = map.bank[b].tilesToReleaseR[--map.bank[b].numTilesToReleaseR];
        if (--map.bank[b].countR[oldTile]==0) {
            uint8_t pattern = map.bank[b].patternR[oldTile];
            map.bank[b].freePatterns[--map.bank[b].numUsedPatterns] = pattern;
        }
    }
}

void APPEND(MAP_NAME,_free0)() { free_int_inline(0); }
void APPEND(MAP_NAME,_free1)() { free_int_inline(1); }
void APPEND(MAP_NAME,_free2)() { free_int_inline(2); }

void APPEND(MAP_NAME,_free)() {
    
	APPEND(MAP_NAME,_free0)();
	APPEND(MAP_NAME,_free1)();
	APPEND(MAP_NAME,_free2)();
}

static void update_animation(uint8_t animatedFrame) __z88dk_fastcall {
    
    uint8_t oldSegmentPageC = mapper_load_module(MAP_ANIMATED, PAGE_C);
    const uint8_t *p = &MAP_ANIMATED[animatedFrame][0][0];
    TMS99X8_memcpy( MODE2_ADDRESS_PG + 0*(8*256) + (1<<4), p, 16*NUM_ANIMATED_TILES); 
    TMS99X8_memcpy( MODE2_ADDRESS_PG + 1*(8*256) + (1<<4), p, 16*NUM_ANIMATED_TILES); 
    TMS99X8_memcpy( MODE2_ADDRESS_PG + 2*(8*256) + (1<<4), p, 16*NUM_ANIMATED_TILES); 

    p += 16*NUM_ANIMATED_TILES;

    TMS99X8_memcpy( MODE2_ADDRESS_CT + 0*(8*256) + (1<<4), p, 16*NUM_ANIMATED_TILES); 
    TMS99X8_memcpy( MODE2_ADDRESS_CT + 1*(8*256) + (1<<4), p, 16*NUM_ANIMATED_TILES); 
    TMS99X8_memcpy( MODE2_ADDRESS_CT + 2*(8*256) + (1<<4), p, 16*NUM_ANIMATED_TILES); 
    
    mapper_load_segment(oldSegmentPageC, PAGE_C);

}
    

void APPEND(MAP_NAME,_update_animation)() {

	update_animation(map.animatedFrame);
}

void APPEND(MAP_NAME,_iterate_animation)() {
    
    uint8_t i = map.animatedFrame;
    i++;
    if (i>=NUM_ANIMATED_FRAMES) i=0;
    map.animatedFrame = i;
}

static uint8_t flag_segments[16];


void APPEND(MAP_NAME,_init)() {
    
    //printf("%d 0x%04X\n",sizeof(MapStatus), sizeof(MapStatus));

    TMS99X8_memset(MODE2_ADDRESS_PG, 0, 3*8*256);
    TMS99X8_memset(MODE2_ADDRESS_CT, 0, 3*8*256);
    TMS99X8_memset(MODE2_ADDRESS_PN0, 0, 3*256);
    TMS99X8_memset(MODE2_ADDRESS_PN1, 0, 3*256);

	flag_segments[ 0] = MODULE_SEGMENT(MAP_TILES16_FLAGS_0, PAGE_C);
	flag_segments[ 1] = MODULE_SEGMENT(MAP_TILES16_FLAGS_1, PAGE_C);
	flag_segments[ 2] = MODULE_SEGMENT(MAP_TILES16_FLAGS_2, PAGE_C);
	flag_segments[ 3] = MODULE_SEGMENT(MAP_TILES16_FLAGS_3, PAGE_C);
	flag_segments[ 4] = MODULE_SEGMENT(MAP_TILES16_FLAGS_4, PAGE_C);
	flag_segments[ 5] = MODULE_SEGMENT(MAP_TILES16_FLAGS_5, PAGE_C);
	flag_segments[ 6] = MODULE_SEGMENT(MAP_TILES16_FLAGS_6, PAGE_C),
	flag_segments[ 7] = MODULE_SEGMENT(MAP_TILES16_FLAGS_7, PAGE_C);
	flag_segments[ 8] = MODULE_SEGMENT(MAP_TILES16_FLAGS_8, PAGE_C);
	flag_segments[ 9] = MODULE_SEGMENT(MAP_TILES16_FLAGS_9, PAGE_C);
	flag_segments[10] = MODULE_SEGMENT(MAP_TILES16_FLAGS_10, PAGE_C);
	flag_segments[11] = MODULE_SEGMENT(MAP_TILES16_FLAGS_11, PAGE_C);
	flag_segments[12] = MODULE_SEGMENT(MAP_TILES16_FLAGS_12, PAGE_C);
	flag_segments[13] = MODULE_SEGMENT(MAP_TILES16_FLAGS_13, PAGE_C);
	flag_segments[14] = MODULE_SEGMENT(MAP_TILES16_FLAGS_14, PAGE_C);
	flag_segments[15] = MODULE_SEGMENT(MAP_TILES16_FLAGS_15, PAGE_C);
    
    memset(&map,0,sizeof(map));
//    debug_printf("map size: %04X\n", &map);
    {
        uint8_t b,i;
        for (b=0; b<3; b++) {

            for (i=0; i<128-16; i++) 
                map.bank[b].freePatterns[i]=(127-i)<<1;

            for (i=0; i<NUM_ANIMATED_TILES; i++) 
                map.bank[b].countL[i+1]++;

            for (i=0; i<NUM_ANIMATED_TILES; i++) 
                map.bank[b].countR[i+1]++;

            for (i=0; i<NUM_ANIMATED_TILES; i++) 
                map.bank[b].patternL[i+1] = (i+1)<<1;

            for (i=0; i<NUM_ANIMATED_TILES; i++) 
                map.bank[b].patternR[i+1] = (i+1)<<1;

            update_animation(0);
        }
    }
    
    memset(&map.stages[0], MODULE_SEGMENT(MAP0_MAP16, PAGE_D), sizeof(map.stages));
}



#ifdef MSX

static void PN_Copy0s(uint8_t *p) __z88dk_fastcall;
static void PN_Copy1s(uint8_t *p) __z88dk_fastcall;
static void PN_Copy0(uint8_t *p) __z88dk_fastcall;
static void PN_Copy1(uint8_t *p) __z88dk_fastcall;

inline static void PN_Copy_Placeholder() {

    __asm
_PN_Copy0s:
	ld	c, l
	ld	b, h
    ld  hl, #_PN_Copy0_loop
	ld	e, #0x30
_PN_Copy0s_loop:
	ld	a, (bc)
	out	(_VDP0), a
	inc	c
    nop
	ld	a, (bc)
	out	(_VDP0), a
	inc	c
	ld	a, (bc)
	inc	c
	out	(_VDP0), a
	ld	a, (bc)
	inc	c    
	dec	e
	out	(_VDP0), a
	ret Z
    jp	(hl)

_PN_Copy0:
	ld	c, l
	ld	b, h
    ld  hl, #_PN_Copy0_loop
	ld	e, #0x40
_PN_Copy0_loop:
	ld	a, (bc)
	out	(_VDP0), a
	inc	c
    nop
	ld	a, (bc)
	out	(_VDP0), a
	inc	c
	ld	a, (bc)
	inc	c
	out	(_VDP0), a
	ld	a, (bc)
	inc	c    
	dec	e
	out	(_VDP0), a
	ret Z
    jp	(hl)

_PN_Copy1s:
	ld	b, #0x18
_PN_Copy1s_loop:
	ld	a, (hl)
	inc	l
	inc	a
	out	(_VDP0), a
	ld	a, (hl)
	inc	l
	inc	a
	out	(_VDP0), a
	ld	a, (hl)
	inc	l
	inc	a
	out	(_VDP0), a
	ld	a, (hl)
	inc	l
	inc	a
	out	(_VDP0), a
	ld	a, (hl)
	inc	l
	inc	a
	out	(_VDP0), a
	ld	a, (hl)
	inc	l
	inc	a
	out	(_VDP0), a
	ld	a, (hl)
	inc	l
	inc	a
	out	(_VDP0), a
	ld	a, (hl)
	inc	l
	inc	a
	out	(_VDP0), a
    djnz _PN_Copy1s_loop
    ret

    
_PN_Copy1:
	ld	b, #0x20
_PN_Copy1_loop:
	ld	a, (hl)
	inc	l
	inc	a
	out	(_VDP0), a
	ld	a, (hl)
	inc	l
	inc	a
	out	(_VDP0), a
	ld	a, (hl)
	inc	l
	inc	a
	out	(_VDP0), a
	ld	a, (hl)
	inc	l
	inc	a
	out	(_VDP0), a
	ld	a, (hl)
	inc	l
	inc	a
	out	(_VDP0), a
	ld	a, (hl)
	inc	l
	inc	a
	out	(_VDP0), a
	ld	a, (hl)
	inc	l
	inc	a
	out	(_VDP0), a
	ld	a, (hl)
	inc	l
	inc	a
	out	(_VDP0), a
    djnz _PN_Copy1_loop
    ret
    
	__endasm;    
}


INLINE void copyPN0() {
    
    TMS99X8_setPtr(MODE2_ADDRESS_PN0);
    {
        uint8_t PN_Start = (map.pos.i<<5) + map.pos.j;
        PN_Copy0(&map.bank[0].PN[PN_Start]);
        PN_Copy0(&map.bank[1].PN[PN_Start]);
        PN_Copy0s(&map.bank[2].PN[PN_Start]);
    }
}

INLINE void copyPN1() {

    TMS99X8_setPtr(MODE2_ADDRESS_PN1);
    {
        uint8_t PN_Start = (map.pos.i<<5) + map.pos.j;
        PN_Copy1(&map.bank[0].PN[PN_Start]);
        PN_Copy1(&map.bank[1].PN[PN_Start]);
        PN_Copy1s(&map.bank[2].PN[PN_Start]);
    }
}


INLINE void copyPN0full() {
    
    TMS99X8_setPtr(MODE2_ADDRESS_PN0);
    {
        uint8_t PN_Start = (map.pos.i<<5) + map.pos.j;
        PN_Copy0(&map.bank[0].PN[PN_Start]);
        PN_Copy0(&map.bank[1].PN[PN_Start]);
        PN_Copy0(&map.bank[2].PN[PN_Start]);
    }
}

INLINE void copyPN1full() {

    TMS99X8_setPtr(MODE2_ADDRESS_PN1);
    {
        uint8_t PN_Start = (map.pos.i<<5) + map.pos.j;
        PN_Copy1(&map.bank[0].PN[PN_Start]);
        PN_Copy1(&map.bank[1].PN[PN_Start]);
        PN_Copy1(&map.bank[2].PN[PN_Start]);
    }
}
#else

INLINE void PN_Copy(EM2_Buffer buffer) {

    TMS99X8_setPtr(buffer==0?MODE2_ADDRESS_PN0:MODE2_ADDRESS_PN1);

    for (uint8_t bank=0; bank<2; bank++) {
        register uint8_t PN_Start = (map.pos.i<<5) + map.pos.j;
        register uint8_t *p = &map.bank[bank].PN[0];
        register uint8_t iterations = 128;
		while (iterations--) {
			TMS99X8_write(*(p + PN_Start++) + buffer);
			TMS99X8_write(*(p + PN_Start++) + buffer);
		}
    }

	{
		uint8_t bank = 2;
        register uint8_t PN_Start = (map.pos.i<<5) + map.pos.j;
        register uint8_t *p = &map.bank[bank].PN[0];
        register uint8_t iterations = 128 - 32;
		while (iterations--) {
			TMS99X8_write(*(p + PN_Start++) + buffer);
			TMS99X8_write(*(p + PN_Start++) + buffer);
		}
    }
}

INLINE void copyPN0() { PN_Copy(0); }
INLINE void copyPN1() { PN_Copy(1); }

INLINE void copyPN0full() { PN_Copy(0); }
INLINE void copyPN1full() { PN_Copy(1); }

#endif

void APPEND(MAP_NAME,_copyPN0)() { copyPN0(); }
void APPEND(MAP_NAME,_copyPN1)() { copyPN1(); }

void APPEND(MAP_NAME,_copyPN0full)() { copyPN0full(); }
void APPEND(MAP_NAME,_copyPN1full)() { copyPN1full(); }

#ifdef MSX

inline static void get_flags_placeholder() {
	
	__asm
	
; ---------------------------------
; Function overworld_get_flags
; ---------------------------------
_overworld_get_flags::

;src/map_implementation.h:1186: debugBorder(4);
;	ld	a, #0x04
;	out	(_VDP1), a
;	ld	a, #0x87
;	out	(_VDP1), a

	pop	iy ; return address
;src/map_implementation.h:1183: row = row_;
	pop bc
;src/map_implementation.h:1184: col = col_;
	pop de
	push de
	push bc


;src/map_implementation.h:1193: mapper_load_segment(flag_segments[(row>>5)&0xF], PAGE_C);
	ld	a, c
	ld  l, b
	srl	l
	rr	a
	rrca
	rrca
	rrca
	rrca
	and	a, #0x0f
	push de
	ld	e, a
	ld	d, #0x00
	ld	hl, #_flag_segments
	add	hl, de
	pop de
	ld	a, (hl)
	ld	(#0x9000), a


;uint8_t stages[64/2][128/2]; // 2K
;src/map_implementation.h:1191: mapper_load_segment(map.stages[row>>10][col>>10], PAGE_D); // stages apply in blocks of 32x32 pixels
	ld	a,b
	ld	l,d
	srl a
	srl a
	srl a
	rr l
	srl a
	rr l
	add a, #((_map + 0x1800)>>8)
	ld	h, a
	ld	a, (hl)
	ld	(#0xb000), a


; extern const uint8_t MAP_MAP16[64][128];
; extern const uint8_t MAP_TILES16_FLAGS_0[16][256];
;src/map_implementation.h:1195: flags = MAP_TILES16_FLAGS_0[(col>>5)&0xF][MAP_MAP16[row>>9][col>>9]];
	ld	a, d
	rrca
	ld	a, e
	rr	a
	rrca
	rrca
	rrca
	rrca
	and	a, #0x0f
	add a, #((_overworld_tiles16_flags_0 + 0)>>8)
	ld 	h, b
	ld 	b, a
	
	ld 	l, d
	srl	h
	srl	h
	rr 	l
	ld 	a, h
	add a, #((_overworld_map0_map16 + 0)>>8)
	ld	h, a
	ld	c, (hl)
	ld	a, (bc)
	ld 	l, a

;src/map_implementation.h:1198: mapper_load_segment(old_c, PAGE_C);
	ld	a, (#_mapper_current_segments + 0x0002)
	ld	(#0x9000), a
;src/map_implementation.h:1197: mapper_load_segment(old_d, PAGE_D);
	ld	a, (#_mapper_current_segments + 0x0003)
	ld	(#0xb000), a

;src/map_implementation.h:1200: debugBorder(0);
;	ld	a, #0x00
;	out	(_VDP1), a
;	ld	a, #0x87
;	out	(_VDP1), a

	jp (iy)

	__endasm;
}

#else

INLINE uint8_t APPEND(MAP_NAME,_get_flags_c_optimized)(uint16_t row, uint16_t col) {

	mapper_load_segment_fast(map.stages[row>>10][col>>10], PAGE_D); // stages apply in blocks of 32x32 pixels

	mapper_load_segment_fast(flag_segments[(row>>5)&0xF], PAGE_C);
	
	uint8_t flags = MAP_TILES16_FLAGS_0[(col>>5)&0xF][MAP_MAP16[row>>9][col>>9]];

	mapper_load_segment(CURRENT_SEGMENT(PAGE_D), PAGE_D);
	mapper_load_segment(CURRENT_SEGMENT(PAGE_C), PAGE_C);

	return flags;
}

uint8_t APPEND(MAP_NAME,_get_flags)(uint16_t row, uint16_t col) {

	const uint8_t (*map_map16)[64][128];
	
	if (map.stages[row>>10][col>>10] == 0) map_map16 = &MAP0_MAP16;
	if (map.stages[row>>10][col>>10] == 1) map_map16 = &MAP1_MAP16;
	if (map.stages[row>>10][col>>10] == 2) map_map16 = &MAP2_MAP16;
	if (map.stages[row>>10][col>>10] == 3) map_map16 = &MAP3_MAP16;
	
	
	uint8_t flags = 0;
	if ( ((row>>5)&0xF) ==  0 ) flags = MAP_TILES16_FLAGS_0 [(col>>5)&0xF][(*map_map16)[row>>9][col>>9]];
	if ( ((row>>5)&0xF) ==  1 ) flags = MAP_TILES16_FLAGS_1 [(col>>5)&0xF][(*map_map16)[row>>9][col>>9]];
	if ( ((row>>5)&0xF) ==  2 ) flags = MAP_TILES16_FLAGS_2 [(col>>5)&0xF][(*map_map16)[row>>9][col>>9]];
	if ( ((row>>5)&0xF) ==  3 ) flags = MAP_TILES16_FLAGS_3 [(col>>5)&0xF][(*map_map16)[row>>9][col>>9]];
	if ( ((row>>5)&0xF) ==  4 ) flags = MAP_TILES16_FLAGS_4 [(col>>5)&0xF][(*map_map16)[row>>9][col>>9]];
	if ( ((row>>5)&0xF) ==  5 ) flags = MAP_TILES16_FLAGS_5 [(col>>5)&0xF][(*map_map16)[row>>9][col>>9]];
	if ( ((row>>5)&0xF) ==  6 ) flags = MAP_TILES16_FLAGS_6 [(col>>5)&0xF][(*map_map16)[row>>9][col>>9]];
	if ( ((row>>5)&0xF) ==  7 ) flags = MAP_TILES16_FLAGS_7 [(col>>5)&0xF][(*map_map16)[row>>9][col>>9]];
	if ( ((row>>5)&0xF) ==  8 ) flags = MAP_TILES16_FLAGS_8 [(col>>5)&0xF][(*map_map16)[row>>9][col>>9]];
	if ( ((row>>5)&0xF) ==  9 ) flags = MAP_TILES16_FLAGS_9 [(col>>5)&0xF][(*map_map16)[row>>9][col>>9]];
	if ( ((row>>5)&0xF) == 10 ) flags = MAP_TILES16_FLAGS_10[(col>>5)&0xF][(*map_map16)[row>>9][col>>9]];
	if ( ((row>>5)&0xF) == 11 ) flags = MAP_TILES16_FLAGS_11[(col>>5)&0xF][(*map_map16)[row>>9][col>>9]];
	if ( ((row>>5)&0xF) == 12 ) flags = MAP_TILES16_FLAGS_12[(col>>5)&0xF][(*map_map16)[row>>9][col>>9]];
	if ( ((row>>5)&0xF) == 13 ) flags = MAP_TILES16_FLAGS_13[(col>>5)&0xF][(*map_map16)[row>>9][col>>9]];
	if ( ((row>>5)&0xF) == 14 ) flags = MAP_TILES16_FLAGS_14[(col>>5)&0xF][(*map_map16)[row>>9][col>>9]];
	if ( ((row>>5)&0xF) == 15 ) flags = MAP_TILES16_FLAGS_15[(col>>5)&0xF][(*map_map16)[row>>9][col>>9]];
	
	return flags;
}

#endif


#ifdef MSX

inline static void get_entity_flags_placeholder() {
	
	__asm

; ---------------------------------
; Function overworld_get_entity_flags
; ---------------------------------
_overworld_get_entity_flags::
;	ld	a, #0x04
;	out	(_VDP1), a
;	ld	a, #0x87
;	out	(_VDP1), a

	pop	iy ; return address
	pop bc ; row
	pop de ; col

	push de
	push bc

;row += 14*32;
	ld hl, #(14*32);
	add hl, bc
	ld	b, h
	ld 	c, l

;col += #(4*32);
	ld hl, #(4*32);
	add hl, de
	ex de, hl

;src/map_implementation.h:1193: mapper_load_segment(flag_segments[(row>>5)&0xF], PAGE_C);
	ld	a, c
	ld  l, b
	srl	l
	rr	a
	rrca
	rrca
	rrca
	rrca
	and	a, #0x0f
	push de
	ld	e, a
	ld	d, #0x00
	ld	hl, #_flag_segments
	add	hl, de
	pop de
	ld	a, (hl)
	ld	(#0x9000), a


	push bc  ; we save row

;uint8_t stages[64/2][128/2]; // 2K
;src/map_implementation.h:1191: mapper_load_segment(map.stages[row>>10][col>>10], PAGE_D); // stages apply in blocks of 32x32 pixels
	ld	a,b
	ld	l,d
	srl a
	srl a
	srl a
	rr l
	srl a
	rr l
	add a, #((_map + 0x1800)>>8)
	ld	h, a
	ld	a, (hl)
	ld	(#0xb000), a


; extern const uint8_t MAP_MAP16[64][128];
; extern const uint8_t MAP_TILES16_FLAGS_0[16][256];
;src/map_implementation.h:1195: flags = MAP_TILES16_FLAGS_0[(col>>5)&0xF][MAP_MAP16[row>>9][col>>9]];
	ld	a, d
	rrca
	ld	a, e
	rr	a
	rrca
	rrca
	rrca
	rrca
	and	a, #0x0f
	add a, #((_overworld_tiles16_flags_0 + 0)>>8)
	ld 	h, b
	ld 	b, a
	
	ld 	l, d
	srl	h
	srl	h
	rr 	l
	ld 	a, h
	add a, #((_overworld_map0_map16 + 0)>>8)
	ld	h, a
	ld	c, (hl)
	ld	a, (bc)
	ex 	af,af';'


;col += #(2*32);
	ld hl, #(2*32);
	add hl, de
	ex de, hl
	
	pop bc
	push bc
	

;uint8_t stages[64/2][128/2]; // 2K
;src/map_implementation.h:1191: mapper_load_segment(map.stages[row>>10][col>>10], PAGE_D); // stages apply in blocks of 32x32 pixels
	ld	a,b
	ld	l,d
	srl a
	srl a
	srl a
	rr l
	srl a
	rr l
	add a, #((_map + 0x1800)>>8)
	ld	h, a
	ld	a, (hl)
	ld	(#0xb000), a


; extern const uint8_t MAP_MAP16[64][128];
; extern const uint8_t MAP_TILES16_FLAGS_0[16][256];
;src/map_implementation.h:1195: flags = MAP_TILES16_FLAGS_0[(col>>5)&0xF][MAP_MAP16[row>>9][col>>9]];
	ld	a, d
	rrca
	ld	a, e
	rr	a
	rrca
	rrca
	rrca
	rrca
	and	a, #0x0f
	add a, #((_overworld_tiles16_flags_0 + 0)>>8)
	ld 	h, b
	ld 	b, a
	
	ld 	l, d
	srl	h
	srl	h
	rr 	l
	ld 	a, h
	add a, #((_overworld_map0_map16 + 0)>>8)
	ld	h, a
	ld	c, (hl)
	ld	a, (bc)
	ld  l, a
	ex 	af,af';'
	or	l
	ex 	af,af';'
	
;col += #(3*32);
	ld hl, #(3*32);
	add hl, de
	ex de, hl
	
	pop bc
	push bc
	

;uint8_t stages[64/2][128/2]; // 2K
;src/map_implementation.h:1191: mapper_load_segment(map.stages[row>>10][col>>10], PAGE_D); // stages apply in blocks of 32x32 pixels
	ld	a,b
	ld	l,d
	srl a
	srl a
	srl a
	rr l
	srl a
	rr l
	add a, #((_map + 0x1800)>>8)
	ld	h, a
	ld	a, (hl)
	ld	(#0xb000), a


; extern const uint8_t MAP_MAP16[64][128];
; extern const uint8_t MAP_TILES16_FLAGS_0[16][256];
;src/map_implementation.h:1195: flags = MAP_TILES16_FLAGS_0[(col>>5)&0xF][MAP_MAP16[row>>9][col>>9]];
	ld	a, d
	rrca
	ld	a, e
	rr	a
	rrca
	rrca
	rrca
	rrca
	and	a, #0x0f
	add a, #((_overworld_tiles16_flags_0 + 0)>>8)
	ld 	h, b
	ld 	b, a
	
	ld 	l, d
	srl	h
	srl	h
	rr 	l
	ld 	a, h
	add a, #((_overworld_map0_map16 + 0)>>8)
	ld	h, a
	ld	c, (hl)
	ld	a, (bc)
	ld  l, a
	ex 	af,af';'
	or	l
	ex 	af,af';'


;col += #(2*32);
	ld hl, #(2*32);
	add hl, de
	ex de, hl
	
	pop bc
	

;uint8_t stages[64/2][128/2]; // 2K
;src/map_implementation.h:1191: mapper_load_segment(map.stages[row>>10][col>>10], PAGE_D); // stages apply in blocks of 32x32 pixels
	ld	a,b
	ld	l,d
	srl a
	srl a
	srl a
	rr l
	srl a
	rr l
	add a, #((_map + 0x1800)>>8)
	ld	h, a
	ld	a, (hl)
	ld	(#0xb000), a


; extern const uint8_t MAP_MAP16[64][128];
; extern const uint8_t MAP_TILES16_FLAGS_0[16][256];
;src/map_implementation.h:1195: flags = MAP_TILES16_FLAGS_0[(col>>5)&0xF][MAP_MAP16[row>>9][col>>9]];
	ld	a, d
	rrca
	ld	a, e
	rr	a
	rrca
	rrca
	rrca
	rrca
	and	a, #0x0f
	add a, #((_overworld_tiles16_flags_0 + 0)>>8)
	ld 	h, b
	ld 	b, a
	
	ld 	l, d
	srl	h
	srl	h
	rr 	l
	ld 	a, h
	add a, #((_overworld_map0_map16 + 0)>>8)
	ld	h, a
	ld	c, (hl)
	ld	a, (bc)
	ld  l, a
	ex 	af,af';'
	or	l
	ld	l, a

;src/map_implementation.h:1198: mapper_load_segment(old_c, PAGE_C);
	ld	a, (#_mapper_current_segments + 0x0002)
	ld	(#0x9000), a
;src/map_implementation.h:1197: mapper_load_segment(old_d, PAGE_D);
	ld	a, (#_mapper_current_segments + 0x0003)
	ld	(#0xb000), a

;src/map_implementation.h:1200: debugBorder(0);
;	ld	a, #0x00
;	out	(_VDP1), a
;	ld	a, #0x87
;	out	(_VDP1), a
	
	jp (iy)
			
	__endasm;
}

#else 

INLINE uint8_t APPEND(MAP_NAME,_get_entity_flags_optimized)(uint16_t row, uint16_t col) { 

	row += 14*32;
	col +=  4*32;
	
	mapper_load_segment_fast(flag_segments[(row>>5)&0xF], PAGE_C);
	
	uint8_t flags = 0;

	mapper_load_segment_fast(map.stages[row>>10][col>>10], PAGE_D); // stages apply in blocks of 32x32 pixels	
	flags |= MAP_TILES16_FLAGS_0[(col>>5)&0xF][MAP_MAP16[row>>9][col>>9]];

	col += 2*32;

	mapper_load_segment_fast(map.stages[row>>10][col>>10], PAGE_D); // stages apply in blocks of 32x32 pixels	
	flags |= MAP_TILES16_FLAGS_0[(col>>5)&0xF][MAP_MAP16[row>>9][col>>9]];

	col += 3*32;

	mapper_load_segment_fast(map.stages[row>>10][col>>10], PAGE_D); // stages apply in blocks of 32x32 pixels	
	flags |= MAP_TILES16_FLAGS_0[(col>>5)&0xF][MAP_MAP16[row>>9][col>>9]];

	col += 2*32;

	mapper_load_segment_fast(map.stages[row>>10][col>>10], PAGE_D); // stages apply in blocks of 32x32 pixels	
	flags |= MAP_TILES16_FLAGS_0[(col>>5)&0xF][MAP_MAP16[row>>9][col>>9]];

	mapper_load_segment(CURRENT_SEGMENT(PAGE_D), PAGE_D);
	mapper_load_segment(CURRENT_SEGMENT(PAGE_C), PAGE_C);

	return flags;
}


uint8_t APPEND(MAP_NAME,_get_entity_flags)(uint16_t row, uint16_t col) { 
		
	row += 14*32;
	col +=  4*32;
	
	uint8_t flags = 0;

	flags |= APPEND(MAP_NAME,_get_flags)(row, col);

	col += 2*32;

	flags |= APPEND(MAP_NAME,_get_flags)(row, col);

	col += 3*32;

	flags |= APPEND(MAP_NAME,_get_flags)(row, col);

	col += 2*32;

	flags |= APPEND(MAP_NAME,_get_flags)(row, col);
	
	return flags;

	
}
#endif

uint8_t APPEND(MAP_NAME,_get_tile16)(uint16_t row, uint16_t col) {

#ifdef MSX
	uint8_t old_d = CURRENT_SEGMENT(PAGE_D);

	mapper_load_segment(map.stages[row>>10][col>>10], PAGE_D); // stages apply in blocks of 32x32 pixels
	
	uint8_t tile16 = MAP_MAP16[row>>9][col>>9];

	mapper_load_segment(old_d, PAGE_D);
	
	return tile16;

#else

	const uint8_t (*map_map16)[64][128];
	
	if (map.stages[row>>10][col>>10] == 0) map_map16 = &MAP0_MAP16;
	if (map.stages[row>>10][col>>10] == 1) map_map16 = &MAP1_MAP16;
	if (map.stages[row>>10][col>>10] == 2) map_map16 = &MAP2_MAP16;
	if (map.stages[row>>10][col>>10] == 3) map_map16 = &MAP3_MAP16;


	uint8_t tile16  = (*map_map16)[row>>9][col>>9];

	return tile16;

#endif
}

void APPEND(MAP_NAME,_set_map_index)(uint16_t row, uint16_t col, uint8_t n) {


#ifdef MSX
	if (n==0) map.stages[row>>10][col>>10] = MODULE_SEGMENT(MAP0_MAP16, PAGE_D);
	if (n==1) map.stages[row>>10][col>>10] = MODULE_SEGMENT(MAP1_MAP16, PAGE_D);
	if (n==2) map.stages[row>>10][col>>10] = MODULE_SEGMENT(MAP2_MAP16, PAGE_D);
	if (n==3) map.stages[row>>10][col>>10] = MODULE_SEGMENT(MAP3_MAP16, PAGE_D);	
#else
	map.stages[row>>10][col>>10] = n;
#endif

}
