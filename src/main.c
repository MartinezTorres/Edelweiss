#include <common.h>

////////////////////////////////////////////////////////////////////////
// AUDIO

////////////////////////////////////////////////////////////////////////
// GAME

////////////////////////////////////////////////////////////////////////
// MAIN
USING_MODULE(front_page, PAGE_B);
USING_MODULE(menu, PAGE_B);

USING_MODULE(overworld, PAGE_B);

T_ISR isr;

static void overworld_isr(void) {

    uint8_t oldSegmentPageB = mapper_load_module(overworld, PAGE_B);

    isr.frameCount++;
    isr.em2_Buffer = isr.frameCount & 0x01;
    
    isr.cpuLoad = 2; // base IRC cost is 2%

    TMS99X8_activateBuffer(!isr.em2_Buffer);

    switch (isr.frameCount6++) {
    case 0:
        if (isr.updateScroll) {
            if        (isr.targetPos.j<map.pos.j) {
                map.pos.j--;
                overworld_draw_col(0);
            } else if (isr.targetPos.j>map.pos.j) {
                map.pos.j++;
                overworld_draw_col(31);
            }
            if        (isr.targetPos.i<map.pos.i) {
                map.pos.i--;
                overworld_draw_row(0);
                isr.updateScrollStep2 = 255;
            } else if (isr.targetPos.i>map.pos.i) {
                map.pos.i++;
                overworld_draw_row(7);
                isr.updateScrollStep2 = 1;
            }
            isr.requestPatternNameTransfer = true;
            isr.updateScroll = false;
        }
        
        CALL_PAGE(sprites, PAGE_B, updateSpriteAttributeTableISR(0));
        
        break;
        
    case 1:
    
        CALL_PAGE(sprites, PAGE_B, updateSpriteAttributeTableISR(1));
        if (isr.enableSprites) CALL_PAGE(sprites, PAGE_B, updateSpriteISR());

        break;
        
    case 2:
        
        if (isr.updateScrollStep2==0) {

            isr.nAnimationCount++;
            if (isr.nAnimationCount>1) {
                overworld_iterate_animation();
                isr.nAnimationCount=0;
                isr.animationUpdateRequested=true;
            }
                    
            if (isr.enableAnimations && isr.animationUpdateRequested==true) { 
                overworld_update_animation();
                isr.animationUpdateRequested=false;
            }                
        } else if (isr.updateScrollStep2==255) {
            overworld_draw_row(8);
            overworld_draw_row(16);
        } else if (isr.updateScrollStep2==1) {
            overworld_draw_row(15);
            overworld_draw_row(23);
        }
        
        isr.updateScrollStep2 = 0;
        
        if (isr.requestPatternNameTransfer == false) CALL_PAGE(sprites, PAGE_B, updateSpriteAttributeTableISR(0));

        break;
        
    case 3:
        if (isr.requestPatternNameTransfer) overworld_copyPN(1);
        CALL_PAGE(sprites, PAGE_B, updateSpriteAttributeTableISR(1));
        if (isr.enableSprites && isr.requestPatternNameTransfer==false)  CALL_PAGE(sprites, PAGE_B, updateSpriteISR());
        break;
        
    case 4:    
        if (isr.requestPatternNameTransfer) overworld_copyPN(0);
        CALL_PAGE(sprites, PAGE_B, updateSpriteAttributeTableISR(0));
        break;
        
    case 5:
        if (isr.requestPatternNameTransfer) overworld_free();
        CALL_PAGE(sprites, PAGE_B, updateSpriteAttributeTableISR(1));
        if (isr.enableSprites && isr.requestPatternNameTransfer==false) CALL_PAGE(sprites, PAGE_B, updateSpriteISR());
        isr.requestPatternNameTransfer = false;            
        isr.frameCount6 = 0;
        break;
    }

    //printf("Expected Delay: %i %d\n", isr.frameCount6, isr.cpuLoad);

    mapper_load_segment(oldSegmentPageB, PAGE_B);
}


USING_MODULE(wolfi, PAGE_D);

static void loadPhonySprites() {

    sprites[0].enabled = true;
    sprites[0].patternBlackRequired = true;
    sprites[0].patternColorRequired = true;
    sprites[0].pos.i = 0x0000;
    sprites[0].pos.j = 0x0000;
    sprites[0].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[0].spriteInfo = &wolfi_0_0;

    sprites[1].enabled = true;
    sprites[1].patternBlackRequired = true;
    sprites[1].patternColorRequired = true;
    sprites[1].pos.i = 0x0000;
    sprites[1].pos.j = 0x0200;
    sprites[1].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[1].spriteInfo = &wolfi_0_1;

    sprites[2].enabled = true;
    sprites[2].patternBlackRequired = true;
    sprites[2].patternColorRequired = true;
    sprites[2].pos.i = 0x0200;
    sprites[2].pos.j = 0x0000;
    sprites[2].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[2].spriteInfo = &wolfi_1_0;

    sprites[3].enabled = true;
    sprites[3].patternBlackRequired = true;
    sprites[3].patternColorRequired = true;
    sprites[3].pos.i = 0x0200;
    sprites[3].pos.j = 0x0200;
    sprites[3].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[3].spriteInfo = &wolfi_1_1;

    sprites[4].enabled = true;
    sprites[4].patternBlackRequired = true;
    sprites[4].patternColorRequired = true;
    sprites[4].pos.i = 0x0400;
    sprites[4].pos.j = 0x0000;
    sprites[4].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[4].spriteInfo = &wolfi_2_0;

    sprites[5].enabled = true;
    sprites[5].patternBlackRequired = true;
    sprites[5].patternColorRequired = true;
    sprites[5].pos.i = 0x0400;
    sprites[5].pos.j = 0x0200;
    sprites[5].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[5].spriteInfo = &wolfi_2_1;

    sprites[6].enabled = true;
    sprites[6].patternBlackRequired = true;
    sprites[6].patternColorRequired = true;
    sprites[6].pos.i = 0x0600;
    sprites[6].pos.j = 0x0000;
    sprites[6].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[6].spriteInfo = &wolfi_3_0;

    sprites[7].enabled = true;
    sprites[7].patternBlackRequired = true;
    sprites[7].patternColorRequired = true;
    sprites[7].pos.i = 0x0600;
    sprites[7].pos.j = 0x0200;
    sprites[7].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[7].spriteInfo = &wolfi_3_1;


    sprites[8].enabled = true;
    sprites[8].patternBlackRequired = true;
    sprites[8].patternColorRequired = true;
    sprites[8].pos.i = 0x0800;
    sprites[8].pos.j = 0x0000;
    sprites[8].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[8].spriteInfo = &wolfi_0_0;

    sprites[9].enabled = true;
    sprites[9].patternBlackRequired = true;
    sprites[9].patternColorRequired = true;
    sprites[9].pos.i = 0x0800;
    sprites[9].pos.j = 0x0200;
    sprites[9].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[9].spriteInfo = &wolfi_0_1;

    sprites[10].enabled = true;
    sprites[10].patternBlackRequired = true;
    sprites[10].patternColorRequired = true;
    sprites[10].pos.i = 0x0800;
    sprites[10].pos.j = 0x0400;
    sprites[10].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[10].spriteInfo = &wolfi_1_0;

    sprites[11].enabled = true;
    sprites[11].patternBlackRequired = true;
    sprites[11].patternColorRequired = true;
    sprites[11].pos.i = 0x0A00;
    sprites[11].pos.j = 0x0000;
    sprites[11].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[11].spriteInfo = &wolfi_1_1;

    sprites[12].enabled = true;
    sprites[12].patternBlackRequired = true;
    sprites[12].patternColorRequired = true;
    sprites[12].pos.i = 0x0A00;
    sprites[12].pos.j = 0x0200;
    sprites[12].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[12].spriteInfo = &wolfi_2_0;

    sprites[13].enabled = true;
    sprites[13].patternBlackRequired = true;
    sprites[13].patternColorRequired = true;
    sprites[13].pos.i = 0x0A00;
    sprites[13].pos.j = 0x0400;
    sprites[13].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[13].spriteInfo = &wolfi_2_1;

    sprites[14].enabled = true;
    sprites[14].patternBlackRequired = true;
    sprites[14].patternColorRequired = true;
    sprites[14].pos.i = 0x0A00;
    sprites[14].pos.j = 0x0600;
    sprites[14].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[14].spriteInfo = &wolfi_3_0;

    sprites[15].enabled = true;
    sprites[15].patternBlackRequired = true;
    sprites[15].patternColorRequired = true;
    sprites[15].pos.i = 0x0A00;
    sprites[15].pos.j = 0x0800;
    sprites[15].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[15].spriteInfo = &wolfi_3_1;
    
}

static void mapBrowser() {
    
    enable_keyboard_routine = false;
    
    mapper_load_module(overworld, PAGE_B);
    overworld_init();
    CALL_PAGE(sprites, PAGE_B, sprites_init());

    loadPhonySprites();    
    
    TMS99X8.sprites16 = true;
    TMS99X8_syncFlags();
    
    memset(&isr,0,sizeof(isr));    
    map.pos = isr.targetPos;

    msxhal_install_isr(overworld_isr);
    
    {
        uint8_t i=0;
        for (i=0; i<24; i++) {

            CALL_PAGE( overworld, PAGE_B, overworld_draw_row(i) );
            isr.updateScroll = true;

            wait_frame();
        }
    }
        
    {
        isr.enableSprites = true;
        isr.enableAnimations = true;

        while (true) {
            wait_frame();
            uint8_t key = msxhal_joystick_read(0);

            if (key) {
                if (key & J_LEFT) {
                    isr.targetPos.j = (map.pos.j?map.pos.j-1:0);
                    isr.updateScroll = true;
                }
                if (key & J_RIGHT) {
                    isr.targetPos.j = (map.pos.j<255-32?map.pos.j+1:255-32);
                    isr.updateScroll = true;
                } 
                if (key & J_UP) {
                    isr.targetPos.i = (map.pos.i?map.pos.i-1:0);
                    isr.updateScroll = true;
                }
                if (key & J_DOWN) {
                    isr.targetPos.i = (map.pos.i<127-24?map.pos.i+1:127-24);
                    isr.updateScroll = true;
                }
                if (key==J_SPACE) {
                }
            }
        }
    }
}

int main(void) {

    // Normal initialization routine
    msxhal_init(); // Bare minimum initialization of the msx support 
    DI(); // This game has normally disabled interrupts. 

#ifdef MSX    
__asm
ld   hl,#0xFFE8
ld   a,(hl)
and   #0xFD
ld   (hl),a
out  (_VDP1),a
ld   a,#0x89
out  (_VDP1),a


ld   A,(#0x0180) ; CHGCPU
cp   #0xC3
ld   a,#0x81              ; can be ld a,81h for R800 ROM if you wish
call z,#0x0180
__endasm; 
#endif
    
    TMS99X8_activateMode2(MODE2_ALL_ROWS); 
    // Activates mode 2 and clears the screen (in black)
    
    while (true) {
        mapBrowser();
    }
    
    return 0;
}
