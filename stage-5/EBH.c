#include <osbind.h>
#include <stdio.h>
#include "types.h"
#include "model.h"
#include "renderer.h"
#include "rast_asm.h"
#include "inputs.h"


int main()
{
    
    UINT32 time_then, time_now, time_elapsed;
    UINT8 *base = Physbase();
	UINT32 *base_long = Physbase();
    SCANCODE scancode;

    Model model;

    init_model(&model);

    initalize_screen(base, base_long, &model);

    time_then = get_time();

    /*Main game loop*/
    while(1){

        /*Async Events*/

        /*Check for user input*/
        scancode = read_scancode();

        if(scancode == ESC_MAKE)
        {
            break;
        }
        else if(scancode == A_MAKE){

            set_play_on_fret_a(&model);
        }
        else if(scancode == S_MAKE){

            set_play_on_fret_s(&model);
        }
        else if(scancode == D_MAKE){

            set_play_on_fret_d(&model);
        }
        else if(scancode == F_MAKE){

            set_play_on_fret_f(&model);
        }


        /*Sync Events*/

        /*Get time*/
        time_now = get_time();
        time_elapsed = time_now - time_then;

        /*Generate and move notes*/

        if(time_elapsed >= (cycles_per_beat * CONVERT_MIL) / REFRESH_RATE){
            
            move_notes();
            generate_note();
            
            
        }

        

    }



    return 0;
    
}

UINT32 get_time(){

	UINT32 time_now;
	UINT32 old_ssp;
	UINT32 *timer = (UINT32 *)0x462;
	
	old_ssp = Super(0); 
	time_now = *timer;
	Super(old_ssp); 
	
	return time_now;
	
}

void move_notes(){


}

void generate_note(){

    
}