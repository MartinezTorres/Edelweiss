/* Compare every title command with the independent original sequence. Sinks
 * clobber the pure workspace; cancellation samples every presentation phase. */
#include <common.h>
#include <gameplay/title_sequence.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#if EDW_VEXEL
#include "vx_bind_player_move.h"
#endif
TSpriteStatus sprites[12];
TMS99X8_Register TMS99X8;
uint8_t keyboard[16],keyboard_prev[16],keyboard_click[16];
static unsigned ticks,skip_at,draws;
static uint32_t hash;
static uint16_t random_state;
static isr_function installed;
static void record(unsigned op,unsigned a,unsigned b) {
    hash=hash*33+op;hash=hash*33+a;hash=hash*33+b;
    hash=hash*33+map.pos.i;hash=hash*33+map.pos.j;
    hash=hash*33+TMS99X8.blankScreen;hash=hash*33+TMS99X8.backdrop;
#if EDW_VEXEL
    memset(&vx_bind_player_move_frame,0xA5,sizeof(vx_bind_player_move_frame));
#endif
}
isr_function msxhal_install_isr(isr_function f) {isr_function old=installed;installed=f;return old;}
void title_isr(void) {++state.isr_count;}
void wait_frame(void) {assert(++ticks<4000);if(installed)installed();record(1,ticks,0);}
void update_keyboard_and_joystick(void) {keyboard[8]=skip_at && ticks>=skip_at ? 254 : 255;}
uint16_t rand16(void) {++draws;random_state=(uint16_t)(random_state*25173u+13849u);return random_state;}
void titlemap_init(void) {record(2,0,0);}
void titlemap_draw_row(uint8_t n) {record(3,n,0);}
void titlemap_draw_col(uint8_t n) {record(4,n,0);}
void titlemap_draw_tile8(uint8_t i,uint8_t j) {record(5,i,j);}
void titlemap_copyPN0full(void) {record(6,0,0);}
void titlemap_copyPN1full(void) {record(7,0,0);}
void titlemap_free(void) {record(8,0,0);}
void titlemap_free0(void) {record(9,0,0);}
void titlemap_free1(void) {record(10,0,0);}
void titlemap_free2(void) {record(11,0,0);}
void sprites_init(void) {memset(sprites,0,sizeof(sprites));record(12,0,0);}
void updateSpriteISR(void) {record(13,0,0);}
static void spawned(Entity *e) {record(14,(unsigned)(e-state.entities),e->spark_type);}
static void despawned(Entity *e) {record(15,(unsigned)(e-state.entities),0);}
static uint8_t updated(Entity *e) {record(16,(unsigned)(e-state.entities),e->pos.j);return 1;}
static const struct T_Entity_Callbacks callbacks={spawned,despawned,updated,0};
void init_spark(uint8_t n) {state.entities[n].callbacks=&callbacks;record(17,n,0);}
int main(void) {
    static const unsigned skips[]={0,2,3,10,37,38,70,100,166,167,200,500,1000,1800};
    unsigned i,j;
    for(i=0;i<sizeof(skips)/sizeof(*skips);++i) {
        memset(&state,0,sizeof(state));memset(&configuration,0,sizeof(configuration));
        memset(&map,0,sizeof(map));memset(&TMS99X8,0,sizeof(TMS99X8));
        random_state=123;hash=0;ticks=draws=0;installed=0;skip_at=skips[i];
        title_routine();
        printf("title %u ticks %u draws %u hash %lu attract %u color %u\n",skip_at,ticks,draws,
            (unsigned long)hash,configuration.attract_mode,TMS99X8.backdrop);
        for(j=0;j<12;++j)printf("spark %u %u %u %u %u\n",j,state.entities[j].pos.i,
            state.entities[j].pos.j,state.entities[j].spark_type,state.entities[j].spawn_auto);
        assert(configuration.attract_mode==(skip_at ? 0 : 9));
    }
    puts("title: command order, draws, spark cadence, full presentation and skipping agree");
}
