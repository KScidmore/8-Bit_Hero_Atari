#include <osbind.h>
#include <stdio.h>
#include <unistd.h>
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

    Model model;

    char input_value;
    char ch;

    init_model(&model);

    init_scene(base, base32, &model);
   
    time_then = get_time();

    /*Main game loop*/
    while(1){

        /*Get time*/
        time_now = get_time();
        time_elapsed = time_now - time_then;


        /*Check for input*/
        ch = read_char();

        /*Handle input*/
        if(ch != -1){
            switch(ch) {
                case 'a':
                    play_on_fret(&model, FRET_A, base32);
                    break;
                case 's':
                    play_on_fret(&model, FRET_S, base32);
                    break;
                case 'd':
                    play_on_fret(&model, FRET_D, base32);
                    break;
                case 'f':
                    play_on_fret(&model, FRET_F, base32);
                    break;
                case 27:
                    return 0;

            }
        }

        /*Sync Events*/

        /*Generate and move notes*/

        if(time_elapsed >= 1){

            render_next(base32, &model);  
        }

        if(model.fail_bar.value == 0){

            break;
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
