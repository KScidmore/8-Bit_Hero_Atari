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
    {C5<<2, 0x0B, 0, 0},
    {D5<<2, 0x0B, 0, 0},
    {E5<<2, 0x0B, 0, 0},
    {F5<<2, 0x0B, 0, 0},
    {G5<<2, 0x0B, 0, 0},
    {F5<<2, 0x0B, 0, 0},
    {E5<<2, 0x0B, 0, 0},
    {D5<<2, 0x0B, 0, 0}
};

Psg_notes channel_b[SONG_LENGTH] = {
    {C5<<2, 0x13, ENV_SHAPE_4, 0X0F00},
    {D5<<2, 0x13, ENV_SHAPE_4, 0X0F00},
    {E5<<2, 0x13, ENV_SHAPE_4, 0X0F00},
    {F5<<2, 0x13, ENV_SHAPE_4, 0X0F00},
    {G5<<2, 0x13, ENV_SHAPE_4, 0X0F00},
    {F5<<2, 0x13, ENV_SHAPE_4, 0X0F00},
    {E5<<2, 0x13, ENV_SHAPE_4, 0X0F00},
    {D5<<2, 0x13, ENV_SHAPE_4, 0X0F00}
};

