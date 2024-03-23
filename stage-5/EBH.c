#include <osbind.h>
#include <stdio.h>
#include "types.h"
#include "model.h"
#include "renderer.h"
#include "rast_asm.h"
#include "inputs.h"
#include "events.h"


int main()
{
    
    UINT32 time_then, time_now, time_elapsed;
    UINT8 *base = Physbase();
	UINT32 *base32 = Physbase();
    SCANCODE scancode;

    Model model;
    UINT8 i = 0;
    init_model(&model);

    init_scene(base, base32, &model);

    time_then = get_time();

    /*Main game loop*/
    while(1){

        /*Async Events*/

        /*Check for user input*/
        
        /*Input currently broke as heck*/

        /*scancode = read_scancode();

        if(scancode == ESC_MAKE)
        {
            break;
        }
        else if(scancode == A_MAKE){

            set_play_on_fret_a(&model, FRET_A, 1);
        }
        else if(scancode == S_MAKE){

            set_play_on_fret_s(&model, FRET_S, 1);
        }
        else if(scancode == D_MAKE){

            set_play_on_fret_d(&model, FRET_D, 1);
        }
        else if(scancode == F_MAKE){

            set_play_on_fret_f(&model, FRET_F, 1);
        }*/


        /*Sync Events*/

        /*Get time*/
        time_now = get_time();
        time_elapsed = time_now - time_then;

        /*Generate and move notes - THIS WAS A TEST AND IT WENT BADLY*/

        if(time_elapsed >= 1){

            render_active_notes(base32, &model);
            render_new_note(base32, &model, FRET_A, i);
            render_new_note(base32, &model, FRET_S, i);
            render_new_note(base32, &model, FRET_D, i);
            render_new_note(base32, &model, FRET_F, i);
               
        }

        i++;

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
