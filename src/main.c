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
USING_MODULE(title, PAGE_B);

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
			
			overworld_copyPN1();
			overworld_free0();
		}
        break;
        
    case 4:    
        if (isr.requestPatternNameTransfer) {
			
            overworld_copyPN0();
			overworld_free1();
        } else {
            CALL_PAGE(sprites, PAGE_B, updateSpriteISR());
        }
        break;
        
    case 5:
        if (isr.requestPatternNameTransfer) {
			overworld_free2();
		}
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


static void title_isr(void) {

    isr.frameCount++;
    isr.em2_Buffer = isr.frameCount & 0x01;

    TMS99X8_activateBuffer(!isr.em2_Buffer);
}

static void spawnOverworldEntities() {

	// WOLFI
	{
		state.entities[0x00].maximum_life = 30;
		state.entities[0x00].life = 22;
		state.entities[0x00].pos.i = 0x4200;
		state.entities[0x00].pos.j = 0x7D00;
		state.entities[0x00].segment = MODULE_SEGMENT(update_wolfi, PAGE_C);
		state.entities[0x00].spawn = spawn_wolfi;
		state.entities[0x00].despawn = despawn_wolfi;
		state.entities[0x00].update = update_wolfi;
		state.entities[0x00].enabled = true;
	}

	// WEAPONS (placeholder)
	{
		state.entities[0x01].pos.i = 0x4200;
		state.entities[0x01].pos.j = 0x7D00;
		state.entities[0x01].segment = MODULE_SEGMENT(update_wolfi, PAGE_C);
		state.entities[0x01].spawn = spawn_wolfi;
		state.entities[0x01].despawn = despawn_wolfi;
		state.entities[0x01].update = update_wolfi;
		state.entities[0x01].enabled = false;
	}
	
	// GHOSTS
	{
		for (int i=0; i<7; i++) {
			
			state.entities[0x10+i].segment = MODULE_SEGMENT(update_ghosti, PAGE_C);
			state.entities[0x10+i].spawn = spawn_ghosti;
			state.entities[0x10+i].despawn = despawn_ghosti;
			state.entities[0x10+i].update = update_ghosti;
			state.entities[0x10+i].enabled = true;
		}
			
		state.entities[0x10].pos.i = 0x6400;
		state.entities[0x10].pos.j = 0x1000;
		state.entities[0x10].anchor.i = 0x6600;
		state.entities[0x10].anchor.j = 0x1800;
		state.entities[0x10].vel.i = 5;

		state.entities[0x11].pos.i = 0x6800;
		state.entities[0x11].pos.j = 0x2000;
		state.entities[0x11].anchor.i = 0x6A00;
		state.entities[0x11].anchor.j = 0x2800;
		state.entities[0x11].vel.i = -5;
		state.entities[0x11].vel.j = -1;

		state.entities[0x12].pos.i = 0x6500;
		state.entities[0x12].pos.j = 0x3000;
		state.entities[0x12].anchor.i = 0x6700;
		state.entities[0x12].anchor.j = 0x3800;
		state.entities[0x12].vel.i = +3;
		state.entities[0x12].vel.j = -3;

		state.entities[0x13].pos.i = 0x6A00;
		state.entities[0x13].pos.j = 0x0C00;
		state.entities[0x13].anchor.i = 0x6C00;
		state.entities[0x13].anchor.j = 0x1400;
		state.entities[0x13].vel.i = +6;
		state.entities[0x13].vel.j = +3;

		state.entities[0x14].pos.i = 0x6C00;
		state.entities[0x14].pos.j = 0x1800;
		state.entities[0x14].anchor.i = 0x6E00;
		state.entities[0x14].anchor.j = 0x2000;
		state.entities[0x14].vel.i = 5;

		state.entities[0x15].pos.i = 0x6A00;
		state.entities[0x15].pos.j = 0x2800;
		state.entities[0x15].anchor.i = 0x6C00;
		state.entities[0x15].anchor.j = 0x3000;
		state.entities[0x15].vel.i = -5;
		state.entities[0x15].vel.j = -1;

		state.entities[0x16].pos.i = 0x6C00;
		state.entities[0x16].pos.j = 0x3800;
		state.entities[0x16].anchor.i = 0x6E00;
		state.entities[0x16].anchor.j = 0x4000;
		state.entities[0x16].vel.i = +3;
		state.entities[0x16].vel.j = -3;
	}

	// SKELETIONS 1
	{
		for (int i=0; i<2; i++) {
			
			state.entities[0x17+i].segment = MODULE_SEGMENT(update_skeleti, PAGE_C);
			state.entities[0x17+i].spawn = spawn_skeleti;
			state.entities[0x17+i].despawn = despawn_skeleti;
			state.entities[0x17+i].update = update_skeleti;
			state.entities[0x17+i].enabled = true;
		}

		state.entities[0x17].pos.i = 0x5600;
		state.entities[0x17].pos.j = 0x1400;
		state.entities[0x17].anchor.i = 0x5600;
		state.entities[0x17].anchor.j = 0x1600;

		state.entities[0x18].pos.i = 0x5800;
		state.entities[0x18].pos.j = 0x1A00;
		state.entities[0x18].anchor.i = 0x5800;
		state.entities[0x18].anchor.j = 0x1A00;
	}
}

static void mainGameRoutine() {
	
    enable_keyboard_routine = false;
    
    mapper_load_module(overworld, PAGE_B);
    overworld_init();
    CALL_PAGE(sprites, PAGE_B, sprites_init());
    
    TMS99X8.sprites16 = true;
    TMS99X8_syncFlags();
    
    memset(&isr,0,sizeof(isr));    
    map.pos = isr.targetPos;

    msxhal_install_isr(overworld_isr);

    memset(&state,0,sizeof(state));    
	for (int i=0; i<8; i++)
		state.activeEntities[i] = -1;
	
	state.rupees = 274;
	
	spawnOverworldEntities();
	
	// SPAWN wolfi
	state.activeEntities[0] = 0;
	IN_SEGMENT( state.entities[0].segment, 
		PAGE_C,         
		(*state.entities[0].spawn)(&state.entities[0],0);
		state.entities[0].active = true;
	);
	state.nActiveEntities++;	

	map.pos.j = ( (state.entities[0].pos.j + 0x80) >> 8)-16;
	map.pos.i = ( (state.entities[0].pos.i + 0x80) >> 8)-11;
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
    
    infoBarInit();
    
        
    {
        isr.enableSprites = true;
        isr.enableAnimations = true;

		isr.globalFrameCount = 255;
		isr.globalFrameCount3 = 2;
        while (true) {

			// WAIT FOR FRAME
			uint8_t preFrameCount = isr.frameCount;
            wait_frame();

            isr.deltaFrames = isr.frameCount - preFrameCount;
            
            isr.globalFrameCount++;
            isr.globalFrameCount3++;
            if (isr.globalFrameCount3==3) isr.globalFrameCount3=0;

//			CALL_PAGE( printf, PAGE_D, printf_("isr: %d %d\n",(int)isr.frameCount, (int)preFrameCount); );

			if (0) { for (uint8_t i=0; i<isr.deltaFrames; i++)	_putchar('.'); _putchar('\n'); }
				
//			CALL_PAGE( printf, PAGE_D, printf_("%d\n",isr.deltaFrames); );

			// UPDATE JOYSTICK
			state.joy = msxhal_joystick_read(0);
			
			// UPDATE ACTIVE ENTITIES
			for (int i=0; i<8; i++) {
				
				int8_t n = state.activeEntities[i];
				
				if (n<0) continue;
				Entity *entity = &state.entities[n];

				//CALL_PAGE( printf, PAGE_D, printf_("update: %d %d\n",i, n); );

				IN_SEGMENT(
					entity->segment, 
					PAGE_C,         
					if ((*entity->update)(entity,i) == false) {
						state.activeEntities[i] = -1;
						state.nActiveEntities--;
						entity->active = false;
					};

					// Check out of bounds
					if (((uint8_t)((entity->pos.i >> 8) + 3 - map.pos.i) >= 24+6) ||
						((uint8_t)((entity->pos.j >> 8) + 3 - map.pos.j) >= 32+6)) {

						(*entity->despawn)(entity,i);

						state.activeEntities[i] = -1;
						state.nActiveEntities--;
						entity->active = false;
					}
				);
			}
			
			// CHECK IF WE CAN ACTIVATE OTHER ENTITIES 
			{
				uint8_t i = (isr.globalFrameCount<<1)&63;
				for (uint8_t j=0; j<4; j++) {
					
					Entity *entity = &state.entities[i+j];
					
					if (!entity->enabled) continue;
					if (entity->active) continue;

					
					// Check out of bounds
					if ((uint8_t)((entity->pos.i >> 8) + 6 - map.pos.i) >= 24+12) continue; 
					if ((uint8_t)((entity->pos.j >> 8) + 6 - map.pos.j) >= 32+12) continue;

					if (((uint8_t)((entity->pos.i >> 8) - map.pos.i) < 24) &&
						((uint8_t)((entity->pos.j >> 8) - map.pos.j) < 32)) continue;
					
					//fprintf(stderr, "i %d, j %d \n", (entity->pos.i >> 8) + 3 - map.pos.i, (entity->pos.j >> 8) + 3 - map.pos.j);
					
					
					// Entity 0 is wolfie, Entity 1 is wolfie's weapon
					for (uint8_t k=2; k<8; k++) { 
						if (state.activeEntities[k] < 0) {
							state.activeEntities[k] = i + j;

							IN_SEGMENT(
								entity->segment, 
								PAGE_C,         
								(*entity->spawn)(entity,k);
							);
							state.nActiveEntities++;
							entity->active = true;
							break;
						}
					}
				}
			}
			
			//largePopupInitCanvas(3);
        }
    }
}



static void show_title_screen() {
	
    enable_keyboard_routine = false;
    
    mapper_load_module(title, PAGE_B);
    title_init();
    CALL_PAGE(sprites, PAGE_B, sprites_init());

    TMS99X8.sprites16 = true;
    TMS99X8_syncFlags();
    
    memset(&isr,0,sizeof(isr));    
    map.pos = isr.targetPos;

    msxhal_install_isr(title_isr);

    memset(&state,0,sizeof(state));    
	for (int i=0; i<8; i++)
		state.activeEntities[i] = -1;
    
	map.pos.j = 0;
	map.pos.i = 0;
	isr.targetPos.i = map.pos.i;
	isr.targetPos.j = map.pos.j;

    {
        for (uint8_t i=0; i<8; i++) {

//            title_draw_row(11-i);
//            title_draw_row(12+i);
            title_draw_row(8+i);
//            title_draw_row(19-i);
			wait_frame();
			title_copyPN0full();
			wait_frame();
			title_copyPN1full();
			wait_frame();
			title_free0();
			wait_frame();
			title_free1();
			wait_frame();
			title_free2();
			wait_frame();
        }
    }
    
    while (true) wait_frame();
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
    
//    show_title_screen();
    
    while (true) {
        mainGameRoutine();
    }
    
    return 0;
}
