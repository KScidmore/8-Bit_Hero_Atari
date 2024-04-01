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
#include "music.h"
#include "psg.h"
#include "types.h"
#include "songdat.h"
#include "sndconst.h"

#define BPM 80

const UINT32 ms_per_q_note = 60000 / BPM;

UINT32 curr_note_index;

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

    set_tone(0, channel_a[curr_note_index].pitch);
    set_volume(0, channel_a[curr_note_index].level);
    enable_channel(0, 1, 0);
    set_envelope(channel_a[curr_note_index].env_shape, 
                 channel_a[curr_note_index].env_sustain);

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
    static UINT32 time_last_note, foo, note_duration;
    
    time_last_note = 0;
    foo = 0;
    note_duration = ms_per_q_note;

    if(time_elapsed > 0) {
        foo += time_elapsed;

        if(foo >= note_duration) {
            foo = 0;
    
            stop_sound();

            set_tone(0, channel_a[curr_note_index].pitch);
            set_volume(0, channel_a[curr_note_index].level);
            enable_channel(0, 1, 0);
            set_envelope(channel_a[curr_note_index].env_shape,
                            channel_a[curr_note_index].env_sustain);
            
            /* making sure it wraps back around */
            curr_note_index = (curr_note_index + 1) % SONG_LENGTH; 
        }
    }

    
}