#include "vbl.h"
#include "globals.h"

short render_timer = 0;
BOOL game_on = FALSE;

void do_vbl_isr(){

    if(game_on){

        render_timer++;
        if(render_timer == 1){

            render_request = 1;
            render_timer = 0;
        }

    }
    
}