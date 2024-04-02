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
    {C3, 0x0B, 0, 0},
    {D3, 0x0B, 0, 0},
    {E3, 0x0B, 0, 0},
    {F3, 0x0B, 0, 0},
    {G3, 0x0B, 0, 0},
    {F3, 0x0B, 0, 0},
    {E3, 0x0B, 0, 0},
    {D3, 0x0B, 0, 0}
};

Psg_notes channel_b[SONG_LENGTH] = {
    {C3, 0x13, ENV_SHAPE_4, 0X0F00},
    {D3, 0x13, ENV_SHAPE_4, 0X0F00},
    {E3, 0x13, ENV_SHAPE_4, 0X0F00},
    {F3, 0x13, ENV_SHAPE_4, 0X0F00},
    {G3, 0x13, ENV_SHAPE_4, 0X0F00},
    {A4, 0x13, ENV_SHAPE_4, 0X0F00},
    {B4, 0x13, ENV_SHAPE_4, 0X0F00},
    {C4, 0x13, ENV_SHAPE_4, 0X0F00}
};

