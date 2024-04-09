/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   ebh.c
/  Citations:   
/    
/
/  Program Purposes:
/    Main game module
/--------------------------------------------------------*/
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

#define ESC 27
#define BUFFER_SIZE 32256
#define LAST_NOTE 19

UINT8 buffer_array[BUFFER_SIZE];

int main() {

    /*Game Model*/
    Model model;

    /*Frame Buffer variables*/
    UINT32 *front_buffer, *back_buffer, *curr_buffer;
    UINT8 *original_buffer = Physbase();

    /*Time variables*/
    UINT32 time_then, time_now, time_elapsed;

    /*Input Variables*/
    char ch;
    BOOL quit = FALSE;

    /*Set Buffers Up*/
    set_buffer(&front_buffer, &back_buffer, buffer_array);

    /*Initalize Game Model/Render Start Scene*/
    init_model(&model);

    init_scene((UINT8*) front_buffer, front_buffer, &model);

    back_buffer = front_buffer;

    curr_buffer = back_buffer;

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
                case ESC: 
                    quit = TRUE;
                    break;
            }
        }

        if (time_elapsed >= 1) {

        if (!model.lanes[FRET_A].notes[LAST_NOTE].is_active){
            
            generate_note(&model);
            Vsync();
			render_next(curr_buffer, &model);
			Setscreen(-1, curr_buffer,-1);
            swap_buffer(front_buffer, back_buffer, &curr_buffer);

        }else{

            Vsync();
			render_next(curr_buffer, &model);
			Setscreen(-1, curr_buffer,-1);
            swap_buffer(front_buffer, back_buffer, &curr_buffer);
            if(!model.lanes[FRET_A].notes[LAST_NOTE].is_active){
                break;
            }
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
/    Accesses the vbclock at address 0x462 to get current time
/ 
/  CALLER INPUT:
/    N/A
/ 
/  CALLER OUTPUT:
/   Returns current time
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/    N/A
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
