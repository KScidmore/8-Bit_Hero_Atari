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
#include "effects.c"


#define ESC_KEY 27

UINT32 get_time();


int main() {
    UINT32 time_then = 0, time_now, time_elapsed, total_time_elapsed;
    BOOL quit = FALSE;
    BOOL first_loop = TRUE;
    char ch;

    start_music();
    
    while(!quit) {
        time_now = get_time();
        time_elapsed = time_now - time_then;
        total_time_elapsed += time_now - time_then;
        /*
        */

        /*---------- asynchronous events --------*/
        if (Cconis()) {
            ch = (char)Cnecin();
            if(ch == ESC_KEY) {
                quit = TRUE;
                stop_sound();
            }
        }

        /*---------- synchronous events ---------*/
        if(time_elapsed > 0) {
            update_music(total_time_elapsed);
            time_then = time_now;
        }
        
    }

    play_wrong_note_fx();
    play_note_not_played_fx();
    play_game_over_lose_fx();
    play_menu_selection_fx();
    
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