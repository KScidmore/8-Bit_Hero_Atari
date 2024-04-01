/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   mus_tst.c
/  Citations:   
/    - TODO
/
/  Program Purposes:
/    Data Structures: 
/      - TODO
/
/    Functions:
/      - TODO  
/--------------------------------------------------------*/

#include <stdio.h>
#include <osbind.h>
#include "psg.h  "
#include "types.h"
#include "sndconst.h"
#include "music.h"
#include "songdat.h"


#define ESC_KEY 27

UINT32 get_time();




int main() {
    UINT32 time_then, time_now, time_elapsed;
    BOOL quit = FALSE;
    char ch;

    time_then = 0;
    time_now = 0;
    time_elapsed = 0;


    
    start_music();
    

    while(!quit) {
        time_now = get_time();
        time_elapsed += time_now - time_then;

        /* if clock has ticked */

        if(time_elapsed > 0) {
            
            update_music(time_elapsed);
            
            printf("Time Then: %d \n", time_then);
            printf("Time Now: %d \n", time_now);
            printf("Time Elapsed: %d \n", time_elapsed);

            time_then = time_now;
        }

        if (Cconis()) {
            ch = (char)Cnecin();
            if(ch == ESC_KEY) {
                quit = TRUE;
                stop_sound();
            }
        }
        

    }
    
    /*
    start_music();
    */
    
    /*
    while (measures <= 4) {
        //prints past 4 w/o second if condition
        if ((w_beats != old_w_beats || h_beats != old_h_beats ||
            q_beats != old_q_beats) && measures <= 4) {
            printf("Measure:\t\t%u\n", measures);
            printf("Whole Beats:\t%u\n", w_beats);
            printf("Half Beats:\t\t%u\n", h_beats);
            printf("Quarter Beats:\t%u\n\n", q_beats);
            old_w_beats = w_beats;
            old_h_beats = h_beats;
            old_q_beats = q_beats;
        }
    }
    */


    return 0;
}

UINT32 get_time() {
    long *timer = (long *)0x462;
    long time_now;
    long old_ssp;

    old_ssp = Super(0);
    time_now = *timer;
    Super(old_ssp);

    return (UINT32)time_now;
}