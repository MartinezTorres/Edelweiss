/* Independent boundary oracles for the last portable policies. */
#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include "vx_bind_contact_box.h"
#include "vx_bind_contact_player.h"
#include "vx_bind_ui_menu.h"
#include "vx_bind_ui_cursor.h"
#include "vx_bind_ui_editor.h"
#include "vx_bind_title_attract.h"
#include "vx_bind_world_start.h"

static unsigned axis(uint16_t a,uint16_t b,unsigned extent) {
    int8_t distance=(int8_t)((uint16_t)(a-b)>>5);
    uint8_t half=(uint8_t)((extent+16)/2);
    return (uint8_t)(distance+half)<=(uint8_t)(2*half);
}
int main(void) {
    static const uint16_t origins[]={0,31,8191,32768,65535};
    static const uint8_t sizes[]={0,1,8,16,31,239,240,255};
    unsigned origin,size,d,axis_index;
    for(origin=0;origin<sizeof(origins)/sizeof(*origins);++origin) {
        uint8_t row=(uint8_t)(((uint16_t)(origins[origin]+128)>>8)-11);
        uint8_t col=(uint8_t)(((uint16_t)(origins[origin]+128)>>8)-16);
        VX_BIND_world_start_LOCAL;
        vx_bind_world_start_frame.a0=origins[origin];vx_bind_world_start_frame.a1=origins[origin];
        vx_bind_world_start_run();
        assert(vx_bind_world_start_frame.result.v0==0 && vx_bind_world_start_frame.result.v1==0);
        assert(vx_bind_world_start_frame.result.v2==99 && vx_bind_world_start_frame.result.v3==137);
        assert(vx_bind_world_start_frame.result.v4==(row>106?106:row) && vx_bind_world_start_frame.result.v5==col);
        assert(vx_bind_world_start_frame.result.v6==25088 && vx_bind_world_start_frame.result.v7==25600);
        assert(vx_bind_world_start_frame.result.v8==34816 && vx_bind_world_start_frame.result.v9==1);
    }
    for(origin=0;origin<sizeof(origins)/sizeof(*origins);++origin)
    for(size=0;size<sizeof(sizes);++size)
    for(d=0;d<256;++d)
    for(axis_index=0;axis_index<2;++axis_index) {
        uint16_t a=origins[origin],b=(uint16_t)(a+d*32+(d&31));
        uint16_t i=axis_index?a:b,j=axis_index?b:a;
        VX_BIND_contact_box_LOCAL;
        vx_bind_contact_box_frame.a0=i;vx_bind_contact_box_frame.a1=j;
        vx_bind_contact_box_frame.a2=a;vx_bind_contact_box_frame.a3=a;
        vx_bind_contact_box_frame.a4=sizes[size];vx_bind_contact_box_frame.a5=sizes[size];
        vx_bind_contact_box_run();
        assert(vx_bind_contact_box_frame.result.v0==(axis(i,a,sizes[size]) && axis(j,a,sizes[size])));
        { VX_BIND_contact_player_LOCAL;
          vx_bind_contact_player_frame.a0=i;vx_bind_contact_player_frame.a1=j;
          vx_bind_contact_player_frame.a2=a;vx_bind_contact_player_frame.a3=a;
          vx_bind_contact_player_run();
          assert(vx_bind_contact_player_frame.result.v0==(axis(i,a,0) && axis(j,a,0))); }
    }
    /* Include simultaneous opposite directions and confirmation. */
    for(unsigned vertical=0;vertical<2;++vertical)
    for(unsigned count=1;count<=4;++count)
    for(unsigned option=0;option<count;++option)
    for(unsigned keys=0;keys<256;++keys) {
        unsigned expected=option;
        if((keys&(vertical?32:16)) && expected) --expected;
        if((keys&(vertical?64:128)) && expected+1<count) ++expected;
        { VX_BIND_ui_menu_LOCAL;
          vx_bind_ui_menu_frame.a0=option;vx_bind_ui_menu_frame.a1=count;
          vx_bind_ui_menu_frame.a2=vertical;vx_bind_ui_menu_frame.a3=keys;
          vx_bind_ui_menu_run();
          assert(vx_bind_ui_menu_frame.result.v0==expected && vx_bind_ui_menu_frame.result.v1==(keys&1)); }
        { VX_BIND_ui_cursor_LOCAL;
          vx_bind_ui_cursor_frame.a0=option;vx_bind_ui_cursor_frame.a1=vertical;vx_bind_ui_cursor_run();
          assert(vx_bind_ui_cursor_frame.result.v0==(vertical || !option ? 5 : 35));
          assert(vx_bind_ui_cursor_frame.result.v1==2+(vertical ? option : 3)*7); }
    }
    for(unsigned length=0;length<=10;++length)
    for(unsigned ch=0;ch<256;++ch) {
        unsigned accept=length<10 && ch>32 && ch<127;
        VX_BIND_ui_editor_LOCAL;
        vx_bind_ui_editor_frame.a0=length;vx_bind_ui_editor_frame.a1=ch;vx_bind_ui_editor_frame.a2=ch;
        vx_bind_ui_editor_run();
        assert(vx_bind_ui_editor_frame.result.v0==length+accept);
        assert(vx_bind_ui_editor_frame.result.v1==(ch>='a' && ch<='z' ? ch-32 : ch));
        assert(vx_bind_ui_editor_frame.result.v2==accept);
        assert(vx_bind_ui_editor_frame.result.v3==(length>=10 || ch==13 || length+accept==10));
        assert(vx_bind_ui_editor_frame.result.v4==!!(ch&16));
    }
    for(unsigned ticks=0;ticks<=9;++ticks)
    for(unsigned clock=0;clock<256;++clock)
    for(unsigned key=254;key<=255;++key) {
        unsigned poll=ticks && !clock,next=ticks,keys=key,quit=0;
        if(poll) {--next;if(key!=255)next=0;keys=254;quit=next==0;}
        VX_BIND_title_attract_LOCAL;
        vx_bind_title_attract_frame.a0=ticks;vx_bind_title_attract_frame.a1=clock;vx_bind_title_attract_frame.a2=key;
        vx_bind_title_attract_run();
        assert(vx_bind_title_attract_frame.result.v0==next && vx_bind_title_attract_frame.result.v1==poll);
        assert(vx_bind_title_attract_frame.result.v2==keys && vx_bind_title_attract_frame.result.v3==quit);
    }
    puts("Contact, menu, editor and attract policies: wrapped boundaries and input domains agree (UBSan)");
}
