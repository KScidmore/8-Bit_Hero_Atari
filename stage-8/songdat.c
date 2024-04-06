/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   songdat.c
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

#include "songdat.h"
#include "sndconst.h"

Psg_notes channel_a[SONG_LENGTH] = {
    {A5<<3, 0x13, ENV_SHAPE_4, 0x1F00},            /* part 1 */
    {C5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {D5<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {D5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {E5<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {D5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {D5<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {C5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},

    {A5<<3, 0x13, ENV_SHAPE_4, 0x1F00},            /* part 2 */
    {C5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {D5<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {D5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {E5<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {D5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {D5<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {C5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},

    {D5<<2, 0x13, ENV_SHAPE_4, 0x1F00},            /* part 3 */
    {F5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {G5<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {G5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {A5<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {G5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {G5<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {F5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},

    {A5<<3, 0x13, ENV_SHAPE_4, 0x1F00},            /* part 4 */
    {C5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {D5<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {D5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {E5<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {D5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {D5<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {C5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},

    {E5<<2, 0x13, ENV_SHAPE_4, 0x1F00},            /* part 5 */
    {G5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {A5<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {A5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {B5<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {A5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {A5<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {G5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},

    {D5<<2, 0x13, ENV_SHAPE_4, 0x1F00},            /* part 6 */
    {F5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {G5<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {G5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {A5<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {G5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {G5<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {F5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},

    {A5<<3, 0x13, ENV_SHAPE_4, 0x1F00},            /* part 7 */
    {C5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {D5<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {D5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {E5<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {D5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {D5<<2, 0x13, ENV_SHAPE_4, 0x1F00},
    {C5_SHARP<<2, 0x13, ENV_SHAPE_4, 0x1F00},

    {A5<<3, 0x13, ENV_SHAPE_4, 0x1F00},            /* part 8 */
    {A5<<3, 0x13, ENV_SHAPE_4, 0x1F00},
    {G5<<3, 0x13, ENV_SHAPE_4, 0x1F00},
    {G5<<3, 0x13, ENV_SHAPE_4, 0x1F00},
    {A5<<3, 0x13, ENV_SHAPE_4, 0x1F00},
    {A5<<3, 0x13, ENV_SHAPE_4, 0x1F00},
    {A5<<3, 0x13, ENV_SHAPE_4, 0x1F00}
};