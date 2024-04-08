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

#include <stdio.h>
#include <osbind.h>
#include "types.h"
#include "super.h"
#include "isr.h"

typedef UINT8 SCANCODE;
typedef void (*Vector)(); 

/* IKBD 6850 IRQ Vector */
#define VEC_IKBD_ISR 70

/* IKBD 6850 Addresses */
#define CONTROL ((UINT32)0xFFFC00)
#define STATUS  ((UINT32)0xFFFC00)
#define RDR     ((UINT32)0xFFFC02)
#define MASK    ((UINT32)0xFFFFFA15)

/* IKBD 6850 Register Values */
volatile       UINT8    * const IKBD_control = CONTROL;
volatile const UINT8    * const IKBD_status  = STATUS;
volatile const SCANCODE * const IKBD_RDR     = RDR;
volatile       UINT8    * const MASK_REGISTER_B = MASK; 

Char_Buffer char_buffer;
Vector orig_kbd;

/* Function Prototypes */

void ikbd_isr();
void do_ikbd_isr(int *ptr);

void init_char_buffer();


/*---------- FUNCTION: install_kbd_vector ------------------------
/  PURPOSE:
/    Masks the GPIP4 bit of Interrupt Mask B and installs vector
/  
/  CALLER INPUT:
/    TODO - the purpose of each input parameter
/  
/  CALLER OUTPUT:
/    TODO - the purpose of each output parameter and return 
/    value 
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    TODO 
/--------------------------------------------------------*/
void install_kbd_vector(){

    enter_super();
    *MASK_REGISTER_B &= 0xBF; /*Mask interrupts, GPIP4*/
    exit_super();

    orig_kbd = install_vector(VEC_IKBD_ISR, kbd_isr);

    enter_super();
    *MASK_REGISTER_B |= 0x40; /*Unmask interrupts, GPIP4*/
    exit_super();

}
/*---------- FUNCTION: restore_kbd_vector ------------------------
/  PURPOSE:
/    Masks the GPIP4 bit of Interrupt Mask B and restores vector
/  
/  CALLER INPUT:
/    TODO - the purpose of each input parameter
/  
/  CALLER OUTPUT:
/    TODO - the purpose of each output parameter and return 
/    value 
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    TODO 
/--------------------------------------------------------*/
void restore_kbd_vector(){

    enter_super();
    *MASK_REGISTER_B &= 0xBF; /*Mask interrupts, GPIP4*/
    exit_super();

    install_vector(VEC_IKBD_ISR, orig_kbd);

    enter_super();
    *MASK_REGISTER_B |= 0x40; /*Unmask interrupts, GPIP4*/
    exit_super();

}

/*---------- FUNCTION: do_ikbd_isr ------------------------
/  PURPOSE:
/    TODO - purpose, from the caller's perspective
/  
/  CALLER INPUT:
/    TODO - the purpose of each input parameter
/  
/  CALLER OUTPUT:
/    TODO - the purpose of each output parameter and return 
/    value 
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    TODO 
/--------------------------------------------------------*/
void do_ikbd_isr() {
    
    UINT8 value = *IKBD_RDR;


}

/*Circular Queue Functions*/
void init_char_buffer(){

    char_buffer.front = 0;
    char_buffer.rear = -1;
    char_buffer.size = 0;

}

BOOL is_empty(Char_Buffer *char_buffer){


    return
}