/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   music.c
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

UINT32 curr_note_index, note_start_time;

/*---------- FUNCTION: start_music ------------------------
/  PURPOSE:
/    TODO - purpose, from the caller's perspective (if not 
/    perfectly clear from the name)
/  
/  CALLER INPUT:
/    TODO - the purpose of each input parameter (if not 
/    perfectly clear from the name)
/  
/  CALLER OUTPUT:
/    TODO - the purpose of each output parameter and return 
/    value (if not perfectly clear from the name)
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    TODO 
/--------------------------------------------------------*/
void start_music()
{
    curr_note_index = 0;
    note_start_time = 0;

    Psg_notes first_note = channel_a[curr_note_index];

    set_tone(0, first_note.pitch);
    set_volume(0, first_note.level);
    set_envelope(first_note.env_shape, first_note.env_sustain);

}

/*---------- FUNCTION: update_music -----------------------
/  PURPOSE:
/    TODO - purpose, from the caller's perspective (if not 
/    perfectly clear from the name)
/  
/  CALLER INPUT:
/    TODO - the purpose of each input parameter (if not 
/    perfectly clear from the name)
/  
/  CALLER OUTPUT:
/    TODO - the purpose of each output parameter and return 
/    value (if not perfectly clear from the name)
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    TODO 
/--------------------------------------------------------*/
void update_music(UINT32 time_elapsed)
{
    curr_note_index += 1;

    Psg_notes next_note = channel_a[curr_note_index];

    if(time_elapsed % 14 == 0) {
        set_tone(0, next_note.pitch);
        set_volume(0, next_note.level);
        set_envelope(next_note.env_shape, next_note.env_sustain);
    }

}