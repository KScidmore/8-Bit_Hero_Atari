/*
 ID Header:
   Authors: 	Andrew Boisvert, Kyle Scidmore
   Emails: 		abois526@mtroyal.ca, kscid125@mtroyal.ca
   File Name:	EBH.c
   Citations:  
 Program Purposes: Main game module
*/

#include <osbind.h>
#include <stdio.h>
#include <unistd.h>
#include "types.h"
#include "model.h"
#include "renderer.h"
#include "rast_asm.h"
#include "inputs.h"
#include "events.h"
#include "ebh.h"
#include "sndconst.h"
#include "music.h"
#include "songdat.h"
#include "psg.h "


UINT8 buffer_array[32256];

int main() {

    /*Game Model*/
    Model model, snapshot;

    /*Frame Buffer variables*/
    UINT32 *front_buffer, *back_buffer, *curr_buffer;
    UINT8 *original_buffer = Physbase();

    /*Time variables*/
    UINT32 time_then, time_now, time_elapsed, total_time_elapsed;

    /*Input Variables*/
    char ch;
    BOOL quit = FALSE;
    BOOL music_on = FALSE;
    int count = 0;
    BOOL music_wait = TRUE;

    /*Set Buffers Up*/
    set_buffer(&front_buffer, &back_buffer, buffer_array);

    /*Initalize Game Model/Render Start Scene*/
    init_model(&model);
    init_model(&snapshot);

    init_scene((UINT8*) front_buffer, front_buffer, &model);

    back_buffer = front_buffer;

    curr_buffer = back_buffer;

    /*Get Start Time*/
    time_then = get_time();


    while (!quit) {

        time_now = get_time();

        time_elapsed = time_now - time_then;
        total_time_elapsed += time_now - time_then;

        /*wait to start music until first note hits fret*/
        if (count == 300){
            start_music();
            music_on = TRUE;
        }

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
			render_next(curr_buffer, &model);
			Setscreen(-1, curr_buffer,-1);

            if(music_on){

                update_music(total_time_elapsed, count);

            }

            time_then = time_now;

        }

        if (model.fail_bar.value == 0) {
            break;
        }
        count++;
    }
    stop_sound();
    Setscreen(-1, original_buffer, -1);
    printf("Count: %d\n", count);
    return 0;
}

/*---------- FUNCTION: set_buffer -------------------------
/  PURPOSE:
/    Finds a 256 byte aligned address and sets the front 
/    and back buffer pointers.
/ 
/  CALLER INPUT:
/    - front_buffer: Pointer to the front buffer pointer
/    - back_buffer: Pointer to the back buffer pointer
/    - buffer_array: Array containing the buffer memory
/
/  CALLER OUTPUT:
/    None
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/    None
/--------------------------------------------------------*/
void set_buffer(UINT32** front_buffer, UINT32** back_buffer, UINT8 buffer_array[]){

    UINT8 *address = buffer_array;

	while (((UINT32)address) % 256 != 0)
	{
		address++;
	}

	*back_buffer = (UINT32*)address;
    *front_buffer = Physbase();


}

/*---------- FUNCTION: swap_buffer -------------------------
/  PURPOSE:
/    Swaps the current buffer pointer between front and back
/ 
/  CALLER INPUT:
/       - front_buffer: Pointer to the front buffer.
/       - back_buffer: Pointer to the back buffer.
/       - curr_buffer: Pointer to the the current buffer pointer.
/  CALLER OUTPUT:
/    none
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/    none
/--------------------------------------------------------*/
void swap_buffer(UINT32* front_buffer, UINT32* back_buffer, UINT32** curr_buffer){

    *curr_buffer = (*curr_buffer == front_buffer) ? back_buffer : front_buffer;

}

/*---------- FUNCTION: get_time -------------------------
/  PURPOSE:
/    TODO
/ 
/  CALLER INPUT:
/    TODO
/ 
/  CALLER OUTPUT:
/    N/A
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/    TODO
/--------------------------------------------------------*/
UINT32 get_time() {
    long *timer = (long *)0x462;
    long time_now;
    long old_ssp;

    old_ssp = Super(0);
    time_now = *timer;
    Super(old_ssp);

    return (UINT32)time_now;
}
