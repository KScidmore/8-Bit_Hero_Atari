/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   eff_tst.c
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
#include "psg.h"
#include "types.h"
#include "sndconst.h"
#include "effects.h"


int main ()
{
    long i;
    
    play_wrong_note_fx();
    for (i = 0; i < 60000; i++);
    play_note_not_played_fx();
    for (i = 0; i < 60000; i++);
    play_game_over_win_fx();
    for (i = 0; i < 60000; i++);
    play_game_over_lose_fx();
    for (i = 0; i < 60000; i++);
    play_menu_selection_fx();
    


}