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
        } else {
            CALL_PAGE(sprites, PAGE_B, updateSpriteISR());
        }
        
        
        break;
        
    case 1:
        if (isr.updateScrollStep2==0) {

        } else if (isr.updateScrollStep2==255) {
            overworld_draw_row(8);
            overworld_draw_row(16);
        } else if (isr.updateScrollStep2==1) {
            overworld_draw_row(15);
            overworld_draw_row(23);
        }
        
        isr.updateScrollStep2 = 0;

        break;
        
    case 2:
        CALL_PAGE(sprites, PAGE_B, updateSpriteISR());
        break;
        
    case 3:
        if (isr.requestPatternNameTransfer) {
			
			//TMS99X8_memset(MODE2_ADDRESS_PN1, 0, 2*32);
			overworld_copyPN(1);
		}
        break;
        
    case 4:    
        if (isr.requestPatternNameTransfer) {
			
			//TMS99X8_memset(MODE2_ADDRESS_PN0, 0, 2*32);
            overworld_copyPN(0);
        } else {
            CALL_PAGE(sprites, PAGE_B, updateSpriteISR());
        }
        break;
        
    case 5:
        if (isr.requestPatternNameTransfer) overworld_free();
        isr.requestPatternNameTransfer = false;            

		{
            isr.nAnimationCount++;
            if (isr.nAnimationCount>1) {
                overworld_iterate_animation();
                isr.nAnimationCount=0;
                isr.animationUpdateRequested=true;
            }
                    
            if (isr.requestPatternNameTransfer == false && isr.enableAnimations && isr.animationUpdateRequested==true) { 
                overworld_update_animation();
                isr.animationUpdateRequested=false;
            }                
		}

        isr.frameCount6 = 0;
        break;
    }

    CALL_PAGE(sprites, PAGE_B, updateSpriteAttributeTableISR(isr.em2_Buffer));

    //printf("Expected Delay: %i %d\n", isr.frameCount6, isr.cpuLoad);

    mapper_load_segment(oldSegmentPageB, PAGE_B);
}


USING_MODULE(wolfi, PAGE_D);
USING_MODULE(ghosti, PAGE_D);
USING_MODULE(ghosti2, PAGE_D);
USING_MODULE(ghosti3, PAGE_D);

static void loadPhonySprites() {

    sprites[0].enabled = true;
    sprites[0].patternBlackRequired = true;
    sprites[0].patternColorRequired = true;
    sprites[0].pos.i = 0x4000;
    sprites[0].pos.j = 0x4000;
    sprites[0].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[0].spriteInfo = &wolfi_0_0;

    sprites[1].enabled = true;
    sprites[1].patternBlackRequired = true;
    sprites[1].patternColorRequired = true;
    sprites[1].pos.i = 0x4000;
    sprites[1].pos.j = 0x4200;
    sprites[1].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[1].spriteInfo = &wolfi_0_1;

    sprites[2].enabled = true;
    sprites[2].patternBlackRequired = true;
    sprites[2].patternColorRequired = true;
    sprites[2].pos.i = 0x4200;
    sprites[2].pos.j = 0x4000;
    sprites[2].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[2].spriteInfo = &wolfi_1_0;

    sprites[3].enabled = true;
    sprites[3].patternBlackRequired = true;
    sprites[3].patternColorRequired = true;
    sprites[3].pos.i = 0x4200;
    sprites[3].pos.j = 0x4200;
    sprites[3].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[3].spriteInfo = &wolfi_1_1;

    sprites[4].enabled = true;
    sprites[4].patternBlackRequired = true;
    sprites[4].patternColorRequired = true;
    sprites[4].pos.i = 0x4400;
    sprites[4].pos.j = 0x4000;
    sprites[4].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[4].spriteInfo = &wolfi_2_0;

    sprites[5].enabled = true;
    sprites[5].patternBlackRequired = true;
    sprites[5].patternColorRequired = true;
    sprites[5].pos.i = 0x4400;
    sprites[5].pos.j = 0x4200;
    sprites[5].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[5].spriteInfo = &wolfi_2_1;

    sprites[6].enabled = true;
    sprites[6].patternBlackRequired = true;
    sprites[6].patternColorRequired = true;
    sprites[6].pos.i = 0x4600;
    sprites[6].pos.j = 0x4000;
    sprites[6].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[6].spriteInfo = &wolfi_3_0;

    sprites[7].enabled = true;
    sprites[7].patternBlackRequired = true;
    sprites[7].patternColorRequired = true;
    sprites[7].pos.i = 0x4600;
    sprites[7].pos.j = 0x4200;
    sprites[7].spriteInfoSegment = MODULE_SEGMENT(wolfi, PAGE_D);
    sprites[7].spriteInfo = &wolfi_3_1;
}

void _putchar(char character) {
	
	static __sfr __at 0x2C putchar_sfr;
	putchar_sfr = character;
}


void prepareInfoBar() {

	SA0[4].y = 255;
	SA0[4].x = 0;
	SA0[4].pattern = 0;
	SA0[4].color = (uint8_t)0x80 + (uint8_t)BBlack; //ec

	SA0[5].y = 255;
	SA0[5].x = 0;
	SA0[5].pattern = 0;
	SA0[5].color = (uint8_t)0x80 + (uint8_t)BBlack; //ec

	SA0[6].y = 255;
	SA0[6].x = 0;
	SA0[6].pattern = 0;
	SA0[6].color = (uint8_t)0x80 + (uint8_t)BBlack; //ec

	SA0[7].y = 255;
	SA0[7].x = 0;
	SA0[7].pattern = 0;
	SA0[7].color = (uint8_t)0x80 + (uint8_t)BBlack; //ec

	SA1[4].y = 255;
	SA1[4].x = 0;
	SA1[4].pattern = 0;
	SA1[4].color = (uint8_t)0x80 + (uint8_t)BBlack; //ec

	SA1[5].y = 255;
	SA1[5].x = 0;
	SA1[5].pattern = 0;
	SA1[5].color = (uint8_t)0x80 + (uint8_t)BBlack; //ec

	SA1[6].y = 255;
	SA1[6].x = 0;
	SA1[6].pattern = 0;
	SA1[6].color = (uint8_t)0x80 + (uint8_t)BBlack; //ec

	SA1[7].y = 255;
	SA1[7].x = 0;
	SA1[7].pattern = 0;
	SA1[7].color = (uint8_t)0x80 + (uint8_t)BBlack; //ec
	
}

static uint8_t updateWolfi(Entity *entity, uint8_t entityIdx) {

	// KEYBOARD AND MOVE WOLFI
	if (isr.globalFrameCount3 == 0) return true;
	if (state.joy==0) {

		// SPRITE POS
		sprites[entityIdx].pos.i = entity->pos.i;
		sprites[entityIdx].pos.j = entity->pos.j;

		entity->animationCounter = 0;
		return true;
	}
		
	uint16_t tpi = entity->pos.i + 14*32;
	uint16_t tpj1 = entity->pos.j + 4*32;
	uint16_t tpjm1 = entity->pos.j + 6*32;
	uint16_t tpjm2 = entity->pos.j + 9*32;
	uint16_t tpj2 = entity->pos.j + 11*32;
	
	entity->animationCounter++;
	if (state.joy & J_UP) {
		
		for (int i=0; i<2; i++) {
			uint8_t flags = overworld_get_flags(tpi-32, tpj1) | overworld_get_flags(tpi-32, tpj2);
			flags |= overworld_get_flags(tpi-32, tpjm1) | overworld_get_flags(tpi-32, tpjm2);
			if ((flags & 0x1) == 0) {
				entity->pos.i -= 32;
				tpi-=32;
			} else {
				//entity->pos.i -= 32;
			}
		}
		sprites[entityIdx].spriteInfo = (entity->animationCounter & 0x04? &wolfi_1_0 : &wolfi_1_1) ;
	}
	if (state.joy & J_DOWN) {

		for (int i=0; i<2; i++) {
			uint8_t flags = overworld_get_flags(tpi+32, tpj1) | overworld_get_flags(tpi+32, tpj2);
			flags |= overworld_get_flags(tpi+32, tpjm1) | overworld_get_flags(tpi+32, tpjm2);
			if ((flags & 0x1) == 0) {
				entity->pos.i += 32;
				tpi+=32;
			} else {
				//entity->pos.i += 32;
			}
		}

		sprites[entityIdx].spriteInfo = (entity->animationCounter & 0x04? &wolfi_2_0 : &wolfi_2_1);
	}
	if (state.joy & J_RIGHT) {

		for (int i=0; i<2; i++) {
			uint8_t flags = overworld_get_flags(tpi, tpj2+32);
			if ((flags & 0x1) == 0) {
				entity->pos.j += 32;
				tpj1+=32;
				tpj2+=32;
			} else {
				//entity->pos.j += 32;
			}
		}
		sprites[entityIdx].spriteInfo = (entity->animationCounter & 0x04? &wolfi_3_0 : &wolfi_3_1);
	} 
	if (state.joy & J_LEFT) {

		for (int i=0; i<2; i++) {
			uint8_t flags = overworld_get_flags(tpi, tpj1-32);
			if ((flags & 0x1) == 0) {
				entity->pos.j -= 32;
				tpj1-=32;
				tpj2-=32;
			} else {
				//entity->pos.j -= 32;
			}
		}
		sprites[entityIdx].spriteInfo = (entity->animationCounter & 0x04? &wolfi_4_0 : &wolfi_4_1);
	}
		
	// SPRITE POS
	sprites[entityIdx].pos.i = entity->pos.i;
	sprites[entityIdx].pos.j = entity->pos.j;


	// SCROLLING			
	{
		if ( (state.entities[0].pos.j + 0x80 >> 8) < 16 ) {
			
			isr.targetPos.j = 0;
		
		} else if ( (state.entities[0].pos.j + 0x80 >> 8) > (256-16) ) {

			isr.targetPos.j = (uint8_t)(255-31);
			
		} else {
			
			isr.targetPos.j = (state.entities[0].pos.j + 0x80 >> 8)-16;
		}

		if ( (state.entities[0].pos.i + 0x80 >> 8) < 11 ) {
			
			isr.targetPos.i = 0;
		
		} else if ( (state.entities[0].pos.i + 0x80 >> 8) > (128-14) ) {

			isr.targetPos.i = 127-23;
			
		} else {
			
			isr.targetPos.i = (state.entities[0].pos.i + 0x80 >> 8)-11;
		}

		isr.updateScroll |= (map.pos.j != isr.targetPos.j);
		isr.updateScroll |= (map.pos.i != isr.targetPos.i);
	}


	return true;
}

static uint8_t updateGhosti(Entity *entity, uint8_t entityIdx) {

	// KEYBOARD AND MOVE WOLFI
	if (((isr.globalFrameCount+entityIdx)&3) != 0) return true;

	entity->vel.i += ((int16_t)(entity->anchor.i - entity->pos.i))/512;
	entity->vel.j += ((int16_t)(entity->anchor.j - entity->pos.j))/512;

	entity->pos.i += entity->vel.i;
	entity->pos.j += entity->vel.j;

	sprites[entityIdx].pos.i = entity->pos.i;
	sprites[entityIdx].pos.j = entity->pos.j;
    sprites[entityIdx].enabled = true;
    sprites[entityIdx].patternBlackRequired = true;
    sprites[entityIdx].patternColorRequired = true;

	if ((entityIdx&3) == 0) {
		sprites[entityIdx].spriteInfoSegment = MODULE_SEGMENT(ghosti, PAGE_D);
		sprites[entityIdx].spriteInfo = (entity->vel.j>0?&ghosti_0_0 : &ghosti_1_0) ;
	} else if ((entityIdx&3) == 1) {
		sprites[entityIdx].spriteInfoSegment = MODULE_SEGMENT(ghosti2, PAGE_D);
		sprites[entityIdx].spriteInfo = (entity->vel.j>0?&ghosti2_0_0 : &ghosti2_1_0) ;
	} else {
		sprites[entityIdx].spriteInfoSegment = MODULE_SEGMENT(ghosti3, PAGE_D);
		sprites[entityIdx].spriteInfo = (entity->vel.j>0?&ghosti3_0_0 : &ghosti3_1_0) ;
	}

	return true;
}

static void wolfiWalks() {
	
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

    memset(&state,0,sizeof(state));    
	for (int i=0; i<8; i++)
		state.activeEntities[i] = -1;
    
    state.entities[0].pos.i = 0x4000;
    state.entities[0].pos.j = 0x8000;
    state.entities[0].update = updateWolfi;
    state.entities[0].enabled = true;
	
	state.entities[0x10].pos.i = 0x6400;
    state.entities[0x10].pos.j = 0x1000;
	state.entities[0x10].anchor.i = 0x6600;
    state.entities[0x10].anchor.j = 0x1800;
	state.entities[0x10].vel.i = 5;
    state.entities[0x10].update = updateGhosti;
    state.entities[0x10].enabled = true;

	state.entities[0x11].pos.i = 0x6800;
    state.entities[0x11].pos.j = 0x2000;
	state.entities[0x11].anchor.i = 0x6A00;
    state.entities[0x11].anchor.j = 0x2800;
	state.entities[0x11].vel.i = -5;
	state.entities[0x11].vel.j = -1;
    state.entities[0x11].update = updateGhosti;
    state.entities[0x11].enabled = true;

	state.entities[0x12].pos.i = 0x6500;
    state.entities[0x12].pos.j = 0x3000;
	state.entities[0x12].anchor.i = 0x6700;
    state.entities[0x12].anchor.j = 0x3800;
	state.entities[0x12].vel.i = +3;
	state.entities[0x12].vel.j = -3;
    state.entities[0x12].update = updateGhosti;
    state.entities[0x12].enabled = true;

	state.entities[0x13].pos.i = 0x6A00;
    state.entities[0x13].pos.j = 0x0C00;
	state.entities[0x13].anchor.i = 0x6C00;
    state.entities[0x13].anchor.j = 0x1400;
	state.entities[0x13].vel.i = +6;
	state.entities[0x13].vel.j = +3;
    state.entities[0x13].update = updateGhosti;
    state.entities[0x13].enabled = true;

	state.entities[0x14].pos.i = 0x6C00;
    state.entities[0x14].pos.j = 0x1800;
	state.entities[0x14].anchor.i = 0x6E00;
    state.entities[0x14].anchor.j = 0x2000;
	state.entities[0x14].vel.i = 5;
    state.entities[0x14].update = updateGhosti;
    state.entities[0x14].enabled = true;

	state.entities[0x15].pos.i = 0x6A00;
    state.entities[0x15].pos.j = 0x2800;
	state.entities[0x15].anchor.i = 0x6C00;
    state.entities[0x15].anchor.j = 0x3000;
	state.entities[0x15].vel.i = -5;
	state.entities[0x15].vel.j = -1;
    state.entities[0x15].update = updateGhosti;
    state.entities[0x15].enabled = true;

	state.entities[0x16].pos.i = 0x6C00;
    state.entities[0x16].pos.j = 0x3800;
	state.entities[0x16].anchor.i = 0x6E00;
    state.entities[0x16].anchor.j = 0x4000;
	state.entities[0x16].vel.i = +3;
	state.entities[0x16].vel.j = -3;
    state.entities[0x16].update = updateGhosti;
    state.entities[0x16].enabled = true;





	map.pos.j = (state.entities[0].pos.j + 0x80 >> 8)-16;
	map.pos.i = (state.entities[0].pos.i + 0x80 >> 8)-11;
	isr.targetPos.i = map.pos.i;
	isr.targetPos.j = map.pos.j;

    {

        overworld_draw_row(0);
        overworld_draw_row(1);
		wait_frame();
		wait_frame();
		wait_frame();
		wait_frame();
		wait_frame();
		wait_frame();
        for (uint8_t i=0; i<11; i++) {

            overworld_draw_row(2+i);
            overworld_draw_row(23-i);
            overworld_draw_col(31-i);
            overworld_draw_col(i);
			isr.updateScroll = true;
			wait_frame();
			wait_frame();
			wait_frame();
			wait_frame();
			wait_frame();
			wait_frame();
        }
    }
    
    prepareInfoBar();
    
        
    {
        isr.enableSprites = true;
        isr.enableAnimations = true;

		isr.globalFrameCount = 255;
		isr.globalFrameCount3 = 2;
        while (true) {
			
			

			// WAIT FOR FRAME
			//int8_t pre = isr.frameCount;
            wait_frame();
            
            isr.globalFrameCount++;
            isr.globalFrameCount3++;
            if (isr.globalFrameCount3==3) isr.globalFrameCount3=0;

			//CALL_PAGE( printf, PAGE_D, printf_("isr: %d %d\n",isr.frameCount, isr.frameCount - pre); );

			// UPDATE JOYSTICK
			state.joy = msxhal_joystick_read(0);
			
			// UPDATE ACTIVE ENTITIES
			for (int i=0; i<8; i++) {
				
				int8_t n = state.activeEntities[i];
				
				if (n<0) continue;

				//CALL_PAGE( printf, PAGE_D, printf_("update: %d %d\n",i, n); );

				IN_SEGMENT(
					state.entities[n].segment, 
					PAGE_C,         
					if ((*state.entities[n].update)(&state.entities[n],i) == false) {
						state.activeEntities[i] = -1;
						state.nActiveEntities--;
					};
				);
			}
			
			// CHECK IF WE CAN ACTIVATE OTHER ENTITIES 
			{
				uint8_t i = (isr.globalFrameCount<<1)&63;
				for (uint8_t j=0; j<2; j++) {
					
					Entity *entity = &state.entities[i+j];
					
					if (state.nActiveEntities==8) continue;
					if (!entity->enabled) continue;
					if (entity->active) continue;

					
					// Check out of bounds
					if ((entity->pos.i >> 8) + 3 - map.pos.i >= 24+6) continue; 
					if ((entity->pos.j >> 8) + 3 - map.pos.j >= 32+6) continue;
					
					
					for (uint8_t k=0; k<8; k++) {
						if (state.activeEntities[k] < 0) {
							state.activeEntities[k] = i + j;
							state.nActiveEntities++;
							break;
						}
					}
					
					entity->active = true;
					
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
    
    while (true) {
//        mapBrowser();
        wolfiWalks();
    }
    
    return 0;
}
