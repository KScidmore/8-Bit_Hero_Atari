#include <osbind.h>
#include <stdio.h>
#include <unistd.h>
#include "types.h"
#include "model.h"
#include "renderer.h"
#include "rast_asm.h"
#include "inputs.h"
#include "events.h"


UINT32 get_time();

UINT8 buffer_array[32256];

int main() {

    /*Game Model*/
    Model model;

    /*Frame Buffer variables*/
    UINT8 *original_buffer = Physbase();
    UINT8 *front_buffer = original_buffer;
    UINT8 *back_buffer = buffer_array;

    UINT32 temp = (UINT32)(back_buffer);

    BOOL curr_buffer = TRUE;

    /*Time variables*/
    UINT32 time_then, time_now, time_elapsed;

    /*Input Variables*/
    char ch;
    BOOL quit = FALSE;


    /*Set Buffers*/
	while ((temp % 256) != 0)
	{
		temp++;
	}
	back_buffer = (UINT8*)(temp);

    /*Initalize Game Model/Render Start Scene*/
    init_model(&model);

    init_scene(front_buffer, (UINT32*)(front_buffer), &model);
    init_scene(back_buffer, (UINT32*)(back_buffer), &model);

    /*Get Start Time*/
    time_then = get_time();


    while (!quit) {

        time_now = get_time();

        time_elapsed = time_now - time_then;

        ch = read_char();
        if (ch != -1) {
            switch (ch) {
                case 'a':
                    play_on_fret(&model, FRET_A);
                    break;
                case 's':
                    play_on_fret(&model, FRET_S);
                    break;
                case 'd':
                    play_on_fret(&model, FRET_D);
                    break;
                case 'f':
                    play_on_fret(&model, FRET_F);
                    break;
                case 27: 
                    quit = TRUE;
                    break;
            }
        }

        if (time_elapsed >= 1) {

            Vsync();
            if(curr_buffer == TRUE) {
				render_next((UINT32*)(back_buffer), &model);
				Setscreen(-1,back_buffer,-1);
				curr_buffer = FALSE;
			} else {
				render_next((UINT32*)(front_buffer), &model);
				Setscreen(-1,front_buffer,-1);
				curr_buffer = TRUE;
			}

            time_then = time_now;

        }

        if (model.fail_bar.value == 0) {
            break;
        }

    }

    Setscreen(-1, original_buffer, -1);

    return 0;
}

UINT32 get_time() {
    UINT32 time_now;
    UINT32 old_ssp;
    UINT32 *timer = (UINT32 *)0x462;
    
    old_ssp = Super(0); 
    time_now = *timer;
    Super(old_ssp); 
    
    return time_now;
}
