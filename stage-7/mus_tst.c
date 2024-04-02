/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   mus_tst.c
/  Citations:   
/    - https://toolstud.io/music/bpm.php?bpm=80&bpm_unit=4%2F4&base=16
/      - BPM to seconds calc, used for calculating everything
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
    UINT32 time_then, time_now, time_elapsed, total_time_elapsed;
    BOOL quit = FALSE;
    char ch;

    start_music();
    
    while(!quit) {
        time_now = get_time();
        time_elapsed = time_now - time_then;
        total_time_elapsed += time_now - time_then;


        /* if clock has ticked */

        if(time_elapsed > 0) {
            
            update_music(total_time_elapsed);
            
            /*
            printf("Time Then: %d \n", time_then);
            printf("Time Now: %d \n", time_now);
            printf("Time Elapsed: %d \n", time_elapsed);
            printf("Addr 0x462: %u \n\n", get_time());
            */
            

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
    
}


UINT32 get_time() {
    long *timer = (long *)0x462; /* # of v-blanks processed since last reset*/
    long time_now;
    long old_ssp;

    old_ssp = Super(0);
    time_now = *timer;
    Super(old_ssp);

    return (UINT32)time_now;
}