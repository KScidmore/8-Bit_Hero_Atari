/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   effects.c
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

#include <osbind.h>
#include "psg.h"
#include "types.h"
#include "sndconst.h"

void play_main_game_song();
void play_wrong_note_fx();
void play_note_not_played_fx();
void play_game_over_win_fx();
void play_game_over_lose_fx();
void play_menu_selection_fx();


/*---------- FUNCTION: play_main_game_song ----------------
/  PURPOSE:
/    Plays the song that plays through the main game loop. 
/    This occurs at the start of the game round.
/  
/  CALLER INPUT:
/    N/A
/  
/  CALLER OUTPUT:
/    N/A
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    N/A 
/--------------------------------------------------------*/
void play_main_game_song()
{
    /* TODO*/
}


/*---------- FUNCTION: play_wrong_note_fx -----------------
/  PURPOSE:
/    Plays the sound effect that signals that a wrong note
/    was played. This occurs when a fret is depressed and 
/    there is no collision with a note.
/  
/  CALLER INPUT:
/    N/A
/  
/  CALLER OUTPUT:
/    N/A
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    N/A 
/--------------------------------------------------------*/
void play_wrong_note_fx()
{
    /* TODO*/
}


/*---------- FUNCTION: play_note_not_played_fx ------------
/  PURPOSE:
/    Plays the sound effect that signals that plays when a 
/    note passes the fret without being played. This occurs
/    when the note and fret collide without the fret's key 
/    being depressed. 
/  
/  CALLER INPUT:
/    N/A
/  
/  CALLER OUTPUT:
/    N/A
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    N/A 
/--------------------------------------------------------*/
void play_note_not_played_fx()
{
    /* TODO*/
}


/*---------- FUNCTION: play_game_over_win_fx --------------
/  PURPOSE:
/    Plays the sound effect that signals that the player has
/    won the game.
/  
/  CALLER INPUT:
/    N/A
/  
/  CALLER OUTPUT:
/    N/A
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    N/A 
/--------------------------------------------------------*/
void play_game_over_win_fx()
{
    /* TODO*/
}


/*---------- FUNCTION: play_game_over_lose_fx -------------
/  PURPOSE:
/    Plays the sound effect that signals that the player has
/    lost the game.
/  
/  CALLER INPUT:
/    N/A
/  
/  CALLER OUTPUT:
/    N/A
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    N/A 
/--------------------------------------------------------*/
void play_game_over_lose_fx()
{
    /* TODO*/
}


/*---------- FUNCTION: play_menu_selection_fx -------------
/  PURPOSE:
/    Plays the sound effect that signals a menu selection 
/    has been made.
/  
/  CALLER INPUT:
/    N/A
/  
/  CALLER OUTPUT:
/    N/A
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    N/A 
/--------------------------------------------------------*/
void play_menu_selection_fx()
{
    /* TODO*/
}

