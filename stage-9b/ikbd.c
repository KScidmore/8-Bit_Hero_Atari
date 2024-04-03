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

#define RX_DISABLE 0x16;
#define RX_ENABLE 0x96;
#define ESC_MAKE ((SCANCODE) 0x01)
#define ESC_BREAK ((SCANCODE) 0x81)
#define RDR_FULL ((UINT8) 0x01)
#define MAKE_MASK ((SCANCODE) 0x80)
#define VEC_IKBD_ISR 70

typedef unsigned char UINT8;
typedef UINT8 SCANCODE;
typedef void (*Vector)(); 

volatile       UINT8    * const IKBD_control = 0xFFFC00;
volatile const UINT8    * const IKBD_status  = 0xFFFC00;
volatile const SCANCODE * const IKBD_RDR     = 0xFFFC02;

SCANCODE read_scancode();
Vector install_vector(int num, Vector vector);
void ikbd_isr();
void do_ikbd_isr(int *ptr);


int main() {

    Vector orig_vector = install_vector(VEC_IKBD_ISR, ikbd_isr);
    
    /* TODO */

    install_vector(VEC_IKBD_ISR, orig_vector);

    return 0;
}


/*---------- FUNCTION: install_vector ---------------------
/  PURPOSE:
/    This function installs a new ISR for a given interrupt. It does this by
/    modifying the address for the given vector number. To do this, supervisor 
/    mode must be entered, so this function also acts as a wrapper for 
/    this process.
/  
/  CALLER INPUT:
/    int num 
/      The number of the interrupt in the vector table.
/    Vector vector
/      The new ISR address that num will point to.
/  
/  CALLER OUTPUT:
/    Vector orig
/      A pointer to the original ISR that has been changed,
/      allowing the user to restore the state later.
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    - The original ISR must be stored while using the custom ISR and restored
/      before the program ends, or else TOS will not function properly.
/--------------------------------------------------------*/
Vector install_vector(int num, Vector vector) {
    Vector orig;
    Vector *vectp = (Vector *)((long)num << 2);
    long old_ssp = Super(0);

    orig = *vectp;
    *vectp = vector;

    Super(old_ssp);
    return orig;
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
    /* TODO */
}


/*---------- FUNCTION: read_scancode ----------------------
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
SCANCODE read_scancode() {
    while (!(*IKBD_status & RDR_FULL));

    return *IKBD_RDR;
}