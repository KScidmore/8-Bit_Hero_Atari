/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   psg.c
/  Citations:   
/    - geeksforgeeks.org, https://www.geeksforgeeks.org/set-clear-and-toggle-a-given-bit-of-a-number-in-c/
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


/*---------- FUNCTION: write_psg --------------------------
/  PURPOSE:
/    Selects a register and writes a value to it. This is
/    a helper function for the library.
/  
/  CALLER INPUT:
/    int reg
/      the register which is to be selected
/    UINT8 val
/      the value which is to be assigned to the selected register
/  
/  CALLER OUTPUT:
/    N/A
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    N/A
/--------------------------------------------------------*/
void write_psg(int reg, UINT8 val)
{
    if (reg >= 0 && reg <= 15 && val <= 255) 
    {
        volatile UINT8 *register_select = SELECT_ADDRESS;
        volatile UINT8 *register_write = WRITE_ADDRESS;

        UINT32 old_ssp;

        old_ssp = Super(0);

        *register_select = (UINT8)reg;
        *register_write = val;

        Super(old_ssp);
    }
}


/*---------- FUNCTION: read_psg ---------------------------
/  PURPOSE:
/    Reads the value at the selected register.
/  
/  CALLER INPUT:
/    int reg
/      the register which is to be selected
/  
/  CALLER OUTPUT:
/    UINT8 curr_val
/      the current value held by the selected register
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    This function is currently fubar'd, need to work on 
/    it. It is returning 255 regardless of the value it
/    actually currently holds.
/--------------------------------------------------------*/
UINT8 read_psg(int reg)
{
    if (reg >= 0 && reg <= 15) 
    {
        volatile UINT8 *register_select = SELECT_ADDRESS;
        volatile UINT8 *register_write = WRITE_ADDRESS;
        UINT8 curr_val;

        UINT32 old_ssp;

        old_ssp = Super(0);

        *register_select = (UINT8)reg;
        curr_val = *register_write;

        Super(old_ssp);

        return curr_val;
    }
}


/*---------- FUNCTION: set_tone ---------------------------
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
void set_tone(int channel, int tuning)
{
    if (channel >= 0 && channel <= 2 && tuning >= 0 && tuning <= 0xFFF)
    {
        int fine_reg = channel * 2;
        int rough_reg = (channel * 2) + 1;

        int fine_tone = tuning & 0x0FF;
        int rough_tone = (tuning >> 8) & 0x0FF;

        write_psg(fine_reg, fine_tone);
        write_psg(rough_reg, rough_tone);
    }
}


/*---------- FUNCTION: set_volume -------------------------
/  PURPOSE:
/    Loads the volume register for the given channel.
/  
/  CALLER INPUT:
/    int channel
/      The channel to be selected (0=A, 1=B, 2=C)
/    int volume 
/      The value to load the register with.
/  
/  CALLER OUTPUT:
/    N/A
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    N/A 
/--------------------------------------------------------*/
void set_volume(int channel, int volume)
{
    if (channel >= 0 && channel <= 2 && volume >= 0 && volume <= 0x1F)
    {
        /* R8-10 are channel A, B, C */
        write_psg(channel+8, volume);
    }
}


/*---------- FUNCTION: enable_channel ---------------------
/  PURPOSE:
/    Turns the given channel's tone/noise signals on/off. 
/  
/  CALLER INPUT:
/    int channel
/      The channel to be selected (0=A, 1=B, 2=C)
/    int tone_on
/      Turns the tone for the channel on/off (0=off, 1=on)
/    int noise_on
/      Turns the noise for the channel on/off (0=off, 1=on)
/  
/  CALLER OUTPUT:
/    N/A 
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    N/A 
/--------------------------------------------------------*/
void enable_channel(int channel, int tone_on, int noise_on)
{
    if (channel >= 0 && channel <= 2 && 
        tone_on >= 0 && tone_on <= 1 &&
        noise_on >= 0 && noise_on <= 1)
    {
        int foo = IO_PORT_BITS; /* everything disabled but I/O ports */

        if (tone_on) {
            foo &= ~(1 << channel); /* clear bit for tone */
        }

        if (noise_on) {
            foo &= ~(1 << (channel + 3)); /* clear bit for noise */
        }
        
        write_psg(7, foo);
    }
}


/*---------- FUNCTION: stop_sound -------------------------
/  PURPOSE:
/    Silences all PSG sound production.
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
void stop_sound()
{
    write_psg(8, 0);
    write_psg(9, 0);
    write_psg(10, 0);
}


/*---------- FUNCTION: set_noise --------------------------
/  PURPOSE:
/    Loads the noise register with the given tuning. 
/  
/  CALLER INPUT:
/    int tuning
/      The value for the noise frequency register. There
/      are 5 bits of values to set.
/  
/  CALLER OUTPUT:
/    N/A
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    N/A
/--------------------------------------------------------*/
void set_noise(int tuning)
{
    if (tuning >= 0 && tuning <= 0x1F) 
    {
        write_psg(6, tuning);
    }
}

/*---------- FUNCTION: set_envelope -----------------------
/  PURPOSE:
/    Loads the PSG envelope control registers with the given 
/    envelope shape and 16-bit sustain. 
/  
/  CALLER INPUT:
/    int shape
/      The shape is controlled by a 4-bit value where:
/      b3 = CONT
/      b2 = ATT
/      b1 = ALT
/      b0 = HOLD
/    int sustain
/      16-bit value used to help calculate the envelope
/      frequency.
/  
/  CALLER OUTPUT:
/    N/A
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    N/A
/--------------------------------------------------------*/
void set_envelope(int shape, unsigned int sustain)
{
    if (shape >= 0 && shape <= 0xF &&
        sustain >= 0 && sustain <= 0xFFFF)
    {
        UINT16 fine = sustain & 0x00FF;
        UINT16 rough = (sustain & 0x00FF) >> 8;

        write_psg(11, fine);
        write_psg(12, rough);
        write_psg(13, shape);    
    }
}
