#include <map/common.h>
#include <tms99X8.h>
////////////////////////////////////////////////////////////////////////
// Implementation variables
static uint8_t PN_Idx;
static uint8_t bank;
static MapBank *bankPtr;

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
    PROFILE(0, _draw_col, 25, _draw_col(colScreen8) ); 
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
    mapper_load_module(MAP_TILES16, PAGE_C);
    {
        uint8_t tile16Idx = MAP_MAP16[rowWorld16][colWorld16];
        const uint8_t *tile8IdxPtr = &MAP_TILES16[tile16Idx][rowWorld8&1][colWorld8&1];
        
        populateTile8(tile8IdxPtr);
    }
}


void APPEND(MAP_NAME,_draw_tile8)(uint8_t rowScreen8, uint8_t colScreen8) {
    PROFILE(4, _draw_tile8, 0, _draw_tile8(rowScreen8, colScreen8) ); 
}

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

static void renew_row_int_block() {
    
    const uint8_t *tile8IdxPtr = tile8IdxBase + 4 * *tile16IdxPtr;
    populateTile8L(tile8IdxPtr); PN_Idx ++;
    populateTile8R(tile8IdxPtr + 1); PN_Idx ++;
    tile16IdxPtr ++; 
}

#endif

void APPEND(MAP_NAME,_draw_row)(uint8_t rowScreen8) {
    
    PROFILE(4, _draw_row, 30,

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
        
    );
}


void APPEND(MAP_NAME,_erase_tile8)(uint8_t rowScreen8, uint8_t colScreen8) {
    
    PROFILE(0, _erase_tile8, 0,

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
    );
}

void APPEND(MAP_NAME,_erase_col)(uint8_t colScreen8) {

    PROFILE(0, _erase_col, 0,
        uint8_t i=0;
        for (i=0; i<24; i++)
            APPEND(MAP_NAME,_erase_tile8)(i,colScreen8);
    );
}

void APPEND(MAP_NAME,_erase_row)(uint8_t rowScreen8) {
    
    PROFILE(0, _erase_row, 0, 
        uint8_t j=0;
        for (j=0; j<32; j++)
            APPEND(MAP_NAME,_erase_tile8)(rowScreen8,j);        
    );
}


INLINE void free_int_inline(uint8_t b) {
    
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

static void free_int_0() { free_int_inline(0); }
static void free_int_1() { free_int_inline(1); }
static void free_int_2() { free_int_inline(2); }

void APPEND(MAP_NAME,_free)() {
    
    PROFILE(4, _free, 41,
        free_int_0();
        free_int_1();
        free_int_2();
    );
}

static void update_animation(uint8_t animatedFrame) __z88dk_fastcall {
    
    uint8_t oldSegmentPageC = mapper_load_module(MAP_ANIMATED, PAGE_C);
    
    TMS99X8_memcpy( MODE2_ADDRESS_PG + 0*(8*256) + (1<<4), &MAP_ANIMATED[animatedFrame][0][0], 16*NUM_ANIMATED_TILES); 
    TMS99X8_memcpy( MODE2_ADDRESS_PG + 1*(8*256) + (1<<4), &MAP_ANIMATED[animatedFrame][0][0], 16*NUM_ANIMATED_TILES); 
    TMS99X8_memcpy( MODE2_ADDRESS_PG + 2*(8*256) + (1<<4), &MAP_ANIMATED[animatedFrame][0][0], 16*NUM_ANIMATED_TILES); 

    TMS99X8_memcpy( MODE2_ADDRESS_CT + 0*(8*256) + (1<<4), &MAP_ANIMATED[animatedFrame][1][0], 16*NUM_ANIMATED_TILES); 
    TMS99X8_memcpy( MODE2_ADDRESS_CT + 1*(8*256) + (1<<4), &MAP_ANIMATED[animatedFrame][1][0], 16*NUM_ANIMATED_TILES); 
    TMS99X8_memcpy( MODE2_ADDRESS_CT + 2*(8*256) + (1<<4), &MAP_ANIMATED[animatedFrame][1][0], 16*NUM_ANIMATED_TILES); 
    
    mapper_load_segment(oldSegmentPageC, PAGE_C);

}
    

void APPEND(MAP_NAME,_update_animation)() {

    PROFILE(4, _update_animation, 21,
        update_animation(map.animatedFrame);
    );
}

void APPEND(MAP_NAME,_iterate_animation)() {
    
    uint8_t i = map.animatedFrame;
    i++;
    if (i>=NUM_ANIMATED_FRAMES) i=0;
    map.animatedFrame = i;
}



void APPEND(MAP_NAME,_init)() {
    
    //printf("%d 0x%04X\n",sizeof(MapStatus), sizeof(MapStatus));


    TMS99X8_memset(MODE2_ADDRESS_PG, 0, 3*8*256);
    TMS99X8_memset(MODE2_ADDRESS_CT, 0, 3*8*256);
    TMS99X8_memset(MODE2_ADDRESS_PN0, 0, 3*256);
    TMS99X8_memset(MODE2_ADDRESS_PN1, 0, 3*256);
    
    memset(&map,0,sizeof(map));
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

static void PN_Copy0(uint8_t *p) __z88dk_fastcall;
static void PN_Copy1(uint8_t *p) __z88dk_fastcall;

inline static void PN_Copy_Placeholder() {

    __asm
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
        PN_Copy0(&map.bank[2].PN[PN_Start]);
    }
}

INLINE void copyPN1() {

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

    uint8_t bank;
    uint16_t vdp = buffer==0?MODE2_ADDRESS_PN0:MODE2_ADDRESS_PN1;
    for (bank=0; bank<3; bank++) {
        uint8_t PN_Start = (map.pos.i<<5) + map.pos.j;
        register uint8_t *p;
        register uint8_t iterations;
        
        if (PN_Start==0) {
            p = &map.bank[bank].PN[0];
            iterations = 256/4;
            while (iterations--) REPEAT4( TMS99X8_memset(vdp++,*p++ + buffer,1); );
        } else {
        
            p = &map.bank[bank].PN[PN_Start];
            iterations = 256-PN_Start;
            while (iterations--) TMS99X8_memset(vdp++,*p++ + buffer,1);
            
            p = &map.bank[bank].PN[0];
            iterations = PN_Start;
            while (iterations--) TMS99X8_memset(vdp++,*p++ + buffer,1);
        }
    }
}

INLINE void copyPN0() { PN_Copy(0); }
INLINE void copyPN1() { PN_Copy(1); }

#endif

void APPEND(MAP_NAME,_copyPN0)() { PROFILE(4, _copyPN0, 40, copyPN0() ); }
void APPEND(MAP_NAME,_copyPN1)() { PROFILE(4, _copyPN1, 42, copyPN1() ); }

