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
#define ESC 27

int main()
{
    
    UINT32 time_then, time_now, time_elapsed;
    UINT8 *base = Physbase();
	UINT32 *base32 = Physbase();

    Model model;

    char input_value;
    char ch;
    BOOL quit = FALSE;

    init_model(&model);

    init_scene(base, base32, &model);
   
    time_then = get_time();

    /*Main game loop*/
    while(!quit){

        /*Get time*/
        time_now = get_time();
        time_elapsed = time_now - time_then;


        /*Check for input*/
        ch = read_char();

        /*Handle input*/
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

        /*Sync Events*/

        /*Generate and move notes*/

        if(time_elapsed >= 1){
            
            generate_note(&model);
            render_next(base32, &model);  
        }

        if(model.fail_bar.value == 0){

            break;
        } 

    }

    return 0;
    
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