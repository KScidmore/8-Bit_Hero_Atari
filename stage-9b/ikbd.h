/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   ikbd.h
/  Citations:   
/    - keytables: scancodes.txt and scancodes.bmp
/
/  Program Purposes:
/    This file contains constant defintions, struct declarations,
/    and function prototypes for ikbd.c and ikbdisr.s 
/--------------------------------------------------------*/

#ifndef IKBD_H
#define IKBD_H

#include "types.h"

#define SIZE 256 /* buffer size */

/* Make and Break Codes */
#define BREAK 0x80
#define LS_MAKE 0x2A
#define RS_MAKE 0x36
#define CAPS_MAKE 0x3A

/*
- key table for the atari ST based on make/break scancodes
- index # = scancode; the value at that index is the ASCII value 
- using this to convert scancodes to ASCII 
*/
UINT8 unshifted_key_table[] = {
    /* TODO*/
};


/*---------- STRUCTURE: Char_Buffer -----------------------
/  INFO:
/    A circular queue, implemented as an array, that is used 
/    to enqueue each key press's scan code.
/  
/  ATTRIBUTES:
/    int front 
/      the first value in the queue 
/    int back
/      the last value in the queue 
/    int size
/      the current size of the queue
/    UINT8 buffer[SIZE]
/      the array, which will act as a circular queue 
/--------------------------------------------------------*/
typedef struct{
    int front;
    int back;
    int size;
    UINT8 buffer[SIZE];
}Char_Buffer;

/* assembly prototypes from ikbdisr.s */
void ikbd_isr();
void set_ipl();

/* C prototypes */
void install_ikbd_vector();
void restore_ikbd_vector();
void do_ikbd_isr(int *ptr);
void init_char_buffer(Char_Buffer *char_buffer);
BOOL is_empty(Char_Buffer *char_buffer);
void enqueue(Char_Buffer *char_buffer, UINT8 value);
UINT8 dequeue_to_ascii();

#endif