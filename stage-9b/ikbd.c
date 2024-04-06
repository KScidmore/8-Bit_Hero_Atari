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

typedef UINT8 SCANCODE;
typedef void (*Vector)(); 

/* IKBD 6850 IRQ Vector */
#define VEC_IKBD_ISR 70

/* IKBD 6850 Addresses */
#define CONTROL ((UINT32)0xFFFC00)
#define STATUS  ((UINT32)0xFFFC00)
#define RDR     ((UINT32)0xFFFC02)

/* IKBD 6850 Register Values */
#define RX_ENABLE       ((UINT8)0x96)
#define RX_DISABLE      ((UINT8)0x16)
#define RDR_FULL        ((UINT8)0x01)

/* Make and Break Codes, Masks */
#define MAKE_MASK   ((SCANCODE)0x80)
#define ESC_MAKE    ((SCANCODE)0x01)
#define ESC_BREAK   ((SCANCODE)0x81)
#define A_MAKE      ((SCANCODE)0x1E)
#define A_BREAK     ((SCANCODE)0x9E)
#define S_MAKE      ((SCANCODE)0x1F)
#define S_BREAK     ((SCANCODE)0x9F)
#define D_MAKE      ((SCANCODE)0x20)
#define D_BREAK     ((SCANCODE)0xA0)
#define F_MAKE      ((SCANCODE)0x21)
#define F_BREAK     ((SCANCODE)0xA1)

/* IKBD 6850 Register Values */
volatile       UINT8    * const IKBD_control = 0xFFFC00;
volatile const UINT8    * const IKBD_status  = 0xFFFC00;
volatile const SCANCODE * const IKBD_RDR     = 0xFFFC02;

/* Function Prototypes */
SCANCODE read_scancode();
Vector install_vector(int num, Vector vector);
void ikbd_isr();
void do_ikbd_isr(int *ptr);
void lab_6_reference();

int main() {

    
    lab_6_reference();

    /*
    Vector orig_vector = install_vector(VEC_IKBD_ISR, ikbd_isr);
    */
    
    /* TODO */

    /*
    install_vector(VEC_IKBD_ISR, orig_vector);
    */

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
    Vector *vectp = (Vector *)((long)num << 2); /* request vector, over */
    
    long old_ssp = Super(0); /* we have clearance, Clarence */
    orig = *vectp;
    *vectp = vector; /* what's our vector, Victor? */
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
    lab_6_reference();
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

void lab_6_reference() {
    SCANCODE scancode;
    char *scancode_2_ascii = (char *)((Keytbl(-1, -1, -1))->unshift);
    char ch;
    long orig_ssp;

    orig_ssp = Super(0);                    /* enter supervisor mode */
    *IKBD_control = RX_DISABLE;             /* disable Rx interrupts */

    while (1)
    {
        scancode = read_scancode();
        if (scancode == ESC_MAKE){
            break;
        } 
        else if (!(scancode & MAKE_MASK)) { /* check high order bit */
            ch = scancode_2_ascii[scancode];
            (void)Cconout(ch);
        }
    }

    *IKBD_control = RX_ENABLE;              /* enable Rx interrupts */
    Super(orig_ssp);                        /* leave supervisor mode */
}