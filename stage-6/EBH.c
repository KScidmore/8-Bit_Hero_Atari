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
void swap_buffers(UINT8** front_buffer, UINT8** back_buffer);

/*void set_buffer(UINT32* orig_buffer, UINT32** back_buffer, UINT32** front_buffer, UINT8 buffer_array[]);*/

UINT8 buffer_array[32256];

int main() {

    /*Game Model*/
    Model model;

    /*Frame Buffer variables*/
    UINT8 *original_buffer = Physbase();
    UINT8 *front_buffer = original_buffer;
    UINT8 *back_buffer = buffer_array;
    UINT32 vbl_counter_then, vbl_counter_now;

    UINT32 temp = (UINT32)(back_buffer);

    /*UINT8 *base = Physbase();
    UINT32 *base32 = Physbase();
    UINT32* orig_buffer = Physbase();
    BOOL is_front = TRUE;*/

    /*Time variables*/
    UINT32 time_then, time_now, time_elapsed;

    /*Note Generation/Loop variables*/
    UINT8 i = 0, j = 0, k = 0, l = 0, note_counter = 0;
    UINT32 note_gen = 0;

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

    /*Initalize vertical blank counter*/
    /*vbl_counter_then = * (volatile UINT32 *) 0x462;*/

    while (!quit) {

        time_now = get_time();
        /*vbl_counter_now = * (volatile UINT32 *) 0x462;*/
        time_elapsed = time_now - time_then;

        /*if(vbl_counter_now != vbl_counter_then){*/

            /*vbl_counter_then = vbl_counter_now;*/
            Vsync();
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

            if (time_elapsed > 1) {



                render_next((UINT32*)(back_buffer), &model);

                if (time_elapsed >= note_gen) {
                    switch (note_counter) {
                        case 0:
                            render_new_note((UINT32*)(back_buffer), &model, FRET_A, i);
                            i++;
                            break;
                        case 1:
                            render_new_note((UINT32*)(back_buffer), &model, FRET_S, j);
                            j++;
                            break;
                        case 2:
                            render_new_note((UINT32*)(back_buffer), &model, FRET_D, k);
                            k++;
                            break;
                        case 3:
                            render_new_note((UINT32*)(back_buffer), &model, FRET_F, l);
                            l++;
                            break;
                    }
                note_counter = (note_counter + 1) % 4;
                note_gen += 60; 
                }

                swap_buffers(&front_buffer, &back_buffer);

            }


            if (model.fail_bar.value == 0) {

                break;

            }
        /*}*/
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

void swap_buffers(UINT8** front_buffer, UINT8** back_buffer)
{
	UINT8* temp = *front_buffer;
	*front_buffer = *back_buffer;
	*back_buffer = temp;
	/*Setscreen(-1, *front_buffer, -1);*/
}