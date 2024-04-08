/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   ikbd.c
/  Citations:   
/    - N/A
/
/  Program Purposes:
/    The purpose of this program is to implement our own IKBD 
/    ISR to replace TOS's version in order to help our game
/    to stand alone without reliance on TOS.
/--------------------------------------------------------*/

#include <osbind.h>
#include "ikbd.h"
#include "isr.h"
#include "super.h"
#include "types.h"
#include "globals.h"

typedef UINT8 SCANCODE;

/* IKBD 6850 IRQ Vector */
#define VEC_IKBD_ISR 70

/* IKBD 6850 Addresses */
#define CONTROL ((UINT32)0xFFFC00)
#define STATUS  ((UINT32)0xFFFC00)
#define RDR     ((UINT32)0xFFFC02)
#define MASK    ((UINT32)0xFFFFFA09)

/*Mouse Packets*/
#define NO_MOUSE 0
#define MOUSE_PACKET1 1
#define MOUSE_PACKET2 2

/*Make codes for special keys ie: shifts/caps*/
#define LEFT_SHIFT_MAKE 0x2A
#define LEFT_SHIFT_BREAK 0xAA
#define RIGHT_SHIFT_MAKE 0x36
#define RIGHT_SHIFT_BREAK 0xB6
#define CAPS_LOCK 0x3A 
#define NO_CHAR '\0'

/* IKBD 6850 Register Values */
volatile       UINT8    * const IKBD_control = CONTROL;
volatile const UINT8    * const IKBD_status  = STATUS;
volatile const SCANCODE * const IKBD_RDR     = RDR;
volatile       UINT8    * const MASK_REGISTER_B = MASK; 

/* Global Variables */
Char_Buffer char_buffer;
Vector orig_ikbd;
short mouse_packet = NO_MOUSE;
BOOL shift_held = FALSE;
BOOL caps_on = FALSE;

/*---------- FUNCTION: install_ikbd_vector ------------------------
/  PURPOSE:
/    Masks the GPIP4 bit of Interrupt Mask B and installs vector
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
void install_ikbd_vector(){

    enter_super();
    *MASK_REGISTER_B &= 0xBF; /*Mask interrupts, GPIP4*/
    exit_super();

    orig_ikbd = install_vector(VEC_IKBD_ISR, ikbd_isr);

    enter_super();
    *MASK_REGISTER_B |= 0x40; /*Unmask interrupts, GPIP4*/
    exit_super();

}
/*---------- FUNCTION: restore_ikbd_vector ------------------------
/  PURPOSE:
/    Masks the GPIP4 bit of Interrupt Mask B and restores vector
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
void restore_ikbd_vector(){

    enter_super();
    *MASK_REGISTER_B &= 0xBF; /*Mask interrupts, GPIP4*/
    exit_super();

    install_vector(VEC_IKBD_ISR, orig_ikbd);

    enter_super();
    *MASK_REGISTER_B |= 0x40; /*Unmask interrupts, GPIP4*/
    exit_super();

}

/*---------- FUNCTION: do_ikbd_isr ------------------------
/  PURPOSE:
/    Performs the actions of the IKBD ISR. This function 
/    is to be called in the assembly function _ikbd_isr
/  
/  CALLER INPUT:
/    N/A
/  
/  CALLER OUTPUT:
/    N/A
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    - This function MUST be called in _ikbd_isr to ensure that
/      registers d0-d2/a0-a2 are preserved and restored.
/--------------------------------------------------------*/
void do_ikbd_isr() {
    
    UINT8 value = *IKBD_RDR;

    if(mouse_packet == NO_MOUSE){

        if(value >= 0xF8) {

            mouse_packet = MOUSE_PACKET1;

        }
        else {

            char_buffer.buffer[char_buffer.back++] = value;

        }
    }
    else if(mouse_packet == MOUSE_PACKET1){

        mouse_packet = MOUSE_PACKET2;

    }
    else{

        mouse_packet = NO_MOUSE;
    }
    
}


/*----------------- Circular Queue Functions --------------------------------*/

/*---------- FUNCTION: init_char_buffer -------------------
/  PURPOSE:
/    Initializes the buffer to an empty default state.
/  
/  CALLER INPUT:
/    Char_Buffer *char_buffer
/      A pointer to the buffer
/  
/  CALLER OUTPUT:
/    N/A
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    N/A
/--------------------------------------------------------*/
void init_char_buffer(){

    char_buffer.front = 0;
    char_buffer.back = -1;
    char_buffer.size = 0;
}


/*---------- FUNCTION: is_empty ---------------------------
/  PURPOSE:
/    Checks if the buffer is empty.
/  
/  CALLER INPUT:
/    Char_Buffer *char_buffer
/      A pointer to the buffer
/  
/  CALLER OUTPUT:
/    BOOL
/      returns TRUE (1) or FALSE (0)
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    TODO 
/--------------------------------------------------------*/
BOOL is_empty(){

    if(char_buffer.front == char_buffer.back){

        return TRUE;
    }
    else{
        return FALSE;
    }

}


/*---------- FUNCTION: enqueue ----------------------------
/  PURPOSE:
/    Used to enqueue a value to the buffer, and if the length 
/    of the buffer has been reached, it wraps back around to 
/    the beginning.
/  
/  CALLER INPUT:
/    Char_Buffer *char_buffer
/      A pointer to the buffer
/    UINT8 value
/      The value to be added to the queue
/  
/  CALLER OUTPUT:
/    N/A
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    N/A
/--------------------------------------------------------*/
void enqueue(Char_Buffer *char_buffer, UINT8 value){

    char_buffer->back = (char_buffer->back + 1) % SIZE;
    char_buffer->buffer[char_buffer->back] = value;
    char_buffer->size++;
}


/*---------- FUNCTION: dequeue_to_ascii -------------------
/  PURPOSE:
/    This function dequeues a value from the buffer and converts
/    that value to it's ASCII equivalent. The scancode is used 
/    as the index value in the keytable to access its equivalent 
/    value.
/  
/  CALLER INPUT:
/    Char_Buffer *char_buffer
/      A pointer to the buffer
/  
/  CALLER OUTPUT:
/    UINT8 ascii
/      The ASCII value which has been converted from the scancode.
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    TODO 
/--------------------------------------------------------*/
UINT8 dequeue_to_ascii() {

    /* in progress */

    UINT8 scancode;
    UINT8 ascii;

    /*if(!is_empty){
    scancode = char_buffer.buffer[char_buffer.front++];

    ascii = unshifted_key_table[scancode];
    }*/

    while(!is_empty()){

        scancode = char_buffer.buffer[char_buffer.front++];

        ascii = unshifted_key_table[scancode];
    }

    /*scancode = char_buffer.buffer[char_buffer.front];
    char_buffer.front = (char_buffer.front +1) % SIZE;
    char_buffer.size -= 1;*/

    /*if(scancode == RIGHT_SHIFT_MAKE || scancode == LEFT_SHIFT_MAKE){

        shift_held = TRUE;

        return NO_CHAR;
    }
    else if(scancode == RIGHT_SHIFT_BREAK || scancode == LEFT_SHIFT_BREAK){

        shift_held = FALSE;

        return NO_CHAR;
    }
    else if(scancode == CAPS_LOCK){

        if(caps_on == TRUE){

            caps_on = FALSE;

        }
        return NO_CHAR;
    }
    else{

        if(shift_held){

            ascii = shifted_key_table[scancode];

        }
        else if(caps_on){
            ascii = caps_key_table[scancode];
        }
        else{
            ascii = unshifted_key_table[scancode];
        }
    }*/

    ascii = unshifted_key_table[scancode];

    return ascii;
}

