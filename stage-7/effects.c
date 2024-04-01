/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   effects.c
/  Citations:   
/    - https://www.songsterr.com/a/wsa/van-halen-eruption-tab-s92811
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
#include "effects.h"


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
    /*
    - need to work out timing 
    */

    long i;
    long length = 80000;
    set_tone(0, A5_SHARP<<3);
    set_volume(0, 0x08);                /* M = off, vol = 8/15 */
    enable_channel(0, 1, 0);
    for (i = 0; i < length; i++);
    stop_sound();
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
    long i; 
    long length = 100000;
    set_noise(0x00);
    set_volume(2, 0x18);                /* M = on, vol = 8/15 */
    set_envelope(ENV_SHAPE_4, 0x0600);
    enable_channel(2, 0, 1);
    for (i = 0; i < length; i++);
    stop_sound();
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
    /* 
    - using part of the solo from Megdeth's "Sweating Bullets"
    - 140 BPM
    E3 D3 E3 G3 E3 G3 A3 G3 A3 B3 A3 
    B3 D4 B3 D4 E4 D4 E4 G4 F4 E4 F4
    */

    /* TODO */

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
    /*
    - need to work out timing 
    */

    long i;
    long length_1 = 100000;
    long length_2 = 200000;
    set_tone(0, D5_SHARP<<3);
    set_volume(0, 0x08);                /* M = off, vol = 8/15 */
    enable_channel(0, 1, 0);
    for (i = 0; i < length_1; i++);
    stop_sound();

    for (i = 0; i < length_1; i++);

    set_tone(0, C5<<3);
    set_volume(0, 0x08);                /* M = off, vol = 8/15 */
    enable_channel(0, 1, 0);
    for (i = 0; i < length_1; i++);
    stop_sound();

    for (i = 0; i < length_1; i++);
    
    set_tone(0, F6_SHARP<<3);
    set_volume(0, 0x08);                /* M = off, vol = 8/15 */
    enable_channel(0, 1, 0);
    for (i = 0; i < length_2; i++);
    stop_sound();
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
    /* 
    - need to work out timing 
    */

    long i;
    UINT32 length_1 = 60000;
    UINT32 length_2 = 120000;
    UINT16 sustain_1 = 0x0F00;
    UINT16 sustain_2 = 0x8F00;  

    set_tone(0, B7);
    set_volume(0, 0x18);                    /* M = 1, vol = 8/15 */
    set_envelope(ENV_SHAPE_4, sustain_1);
    for (i = 0; i < length_1; i++);
    stop_sound();

    set_tone(0, E7);
    set_volume(0, 0x18);                    /* M = 1, vol = 8/15 */
    set_envelope(ENV_SHAPE_4, sustain_2);
    for (i = 0; i < length_2; i++);
    stop_sound();
}


/*---------- FUNCTION: play_note --------------------------
/  PURPOSE:
/    Helper function to make the other functions a bit 
/    easier to manage and more readable.
/  
/  CALLER INPUT:
/    int note
/      the note to be played, ranges from B0-B8
/  
/  CALLER OUTPUT:
/    N/A
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    N/A 
/--------------------------------------------------------*/
void play_note(int channel, int note, int tone_on, int noise_on)
{
    long i;
    set_tone(channel, note);                    /* set tone freq */
    set_volume(channel, 0x0B);                  /* set mode and volume */
    enable_channel(channel, tone_on, noise_on); /* enable mixer channel */
	for (i = 0; i < 70000; i++);                /* tone now playing in loop */  
    stop_sound();                               /* set channel levels to 0 */
}