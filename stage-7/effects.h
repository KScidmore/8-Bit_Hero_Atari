/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   effects.h
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

#ifndef EFFECTS_H
#define EFFECTS_H


/*---------- FUNCTION PROTOTYPES --------------------------------------------*/
/* main functions */
void play_main_game_song();
void play_wrong_note_fx();
void play_note_not_played_fx();
void play_game_over_win_fx();
void play_game_over_lose_fx();
void play_menu_selection_fx();

/* helper functions */
void play_note(int channel, int note, int tone_on, int noise_on);


#endif