#include <common.h>


#ifdef MSX
void update_keyboard_and_joystick_placeholder() {


	__asm
	_update_keyboard_and_joystick::


; Read keyboard lines 4 and 8

		ld a, #0x04
		call #0x0141 ; SNSMAT
		ld (_state+0x04), a ; state.keyboard[4];

		ld a, #0x08
		call #0x0141 ; SNSMAT
		ld (_state+0x08), a ; state.keyboard[8];
		

; Read joystick status

		ld a,#15 ; read the joystick 1 status:
		call #0x0096; RDPSG
		and #0xbf
		ld e,a
		ld a,#15
		call #0x0093; WRTPSG
		dec a
		call #0x0096; RDPSG  ; a = -, -, B, A, right, left, down, up
		; convert the joystick input to keyboard input
		ld c,a
		; arrows/space:
		ld a, (_state+0x08) ; state.keyboard[8];
    
		di
		
		rr c
		jr c,read_joystick_noUp
		and #0xdf
read_joystick_noUp:

		rr c
		jr c,read_joystick_noDown
		and #0xbf
read_joystick_noDown:

		rr c
		jr c,read_joystick_noLeft
		and #0xef
read_joystick_noLeft:

		rr c
		jr c,read_joystick_noRight
		and #0x7f
read_joystick_noRight:

		rr c
		jr c,read_joystick_noA
		and #0xfe
read_joystick_noA:

		ld (_state+0x08),a   ; we add the joystick input to the keyboard input

		; m (button 2):
		ld a, (_state+0x04) ; state.keyboard[4];
		rr c
		jr c,read_joystick_noB
		and #0xfb
read_joystick_noB:
		ld (_state+0x04),a   ; we add the joystick input to the keyboard input

; Calculate clicks;

		ld de, #_state+0x04 ; state.keyboard[4];
		ld a, (de)          

		ld hl, #_state+0x14 ; state.keyboard_prev[4];
		xor (hl)            ; did it change?
		and (hl)            ; was unpressed?
		ld (_state+0x24), a ; state.keyboard_click[4];
		
		ld a, (de)
		ld (hl), a

		ld de, #_state+0x08 ; state.keyboard[8];
		ld a, (de)          

		ld hl, #_state+0x18 ; state.keyboard_prev[8];
		xor (hl)            ; did it change?
		and (hl)            ; was unpressed?
		ld (_state+0x28), a ; state.keyboard_click[8];
		
		ld a, (de)
		ld (hl), a
				
		ret
	__endasm;
	
	
	
	
}

#else

#include <SDL2/SDL.h>
#define N_KEYS  8831
extern bool keys[N_KEYS];

void update_keyboard_and_joystick() {

    // 4; R, Q, P, O, N, M, L, K
    // 8; RIGHT, DOWN, UP, LEFT, DEL, INS, HOME, SPACE
	
	state.keyboard_prev[8] = state.keyboard[8];
    state.keyboard[8] = 255;
	if (keys[SDLK_RIGHT % N_KEYS]) state.keyboard[8] -= K_RIGHT;
	if (keys[SDLK_DOWN  % N_KEYS]) state.keyboard[8] -= K_DOWN;
	if (keys[SDLK_UP    % N_KEYS]) state.keyboard[8] -= K_UP;
	if (keys[SDLK_LEFT  % N_KEYS]) state.keyboard[8] -= K_LEFT;
	if (keys[SDLK_DELETE% N_KEYS]) state.keyboard[8] -= K_DEL;
	if (keys[SDLK_INSERT% N_KEYS]) state.keyboard[8] -= K_INS;
	if (keys[SDLK_HOME  % N_KEYS]) state.keyboard[8] -= K_HOME;
	if (keys[SDLK_SPACE % N_KEYS]) state.keyboard[8] -= K_SPACE;

	state.keyboard_click[8] = (state.keyboard[8] ^ state.keyboard_prev[8]) & state.keyboard_prev[8];  
	
	state.keyboard_prev[4] = state.keyboard[4];
    state.keyboard[4] = 255;
	if (keys[SDLK_r % N_KEYS]) state.keyboard[4] -= K_R;
	if (keys[SDLK_q % N_KEYS]) state.keyboard[4] -= K_Q;
	if (keys[SDLK_p % N_KEYS]) state.keyboard[4] -= K_P;
	if (keys[SDLK_o % N_KEYS]) state.keyboard[4] -= K_O;
	if (keys[SDLK_n % N_KEYS]) state.keyboard[4] -= K_N;
	if (keys[SDLK_m % N_KEYS]) state.keyboard[4] -= K_M;
	if (keys[SDLK_l % N_KEYS]) state.keyboard[4] -= K_L;
	if (keys[SDLK_k % N_KEYS]) state.keyboard[4] -= K_K;

	state.keyboard_click[4] = (state.keyboard[4] ^ state.keyboard_prev[4]) & state.keyboard_prev[4];  

}

#endif
