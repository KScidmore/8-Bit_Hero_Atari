/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   vbl.c
/  Citations:   
/    - N/A
/
/  Program Purposes:
/    The purpose of this program is to implement our own VBL 
/    ISR to replace TOS's version in order to help our game
/    to stand alone without reliance on TOS.
/--------------------------------------------------------*/

#include <stdio.h>
#include <osbind.h>

#define VEC_VBL_ISR 28

typedef void (*Vector)(); 

Vector install_vector(int num, Vector vector);
void vbl_isr();
void do_vbl_isr(int *counterPtr);

/* has to be global to work */
int seconds = 0;
BOOL render_request;

int main() {
    long i;
    int old_seconds = -1; /* start at -1 to offset it */

    Vector orig_vector = install_vector(VEC_VBL_ISR, vbl_isr);
    
    while (seconds <= 10) {
        if (seconds != old_seconds && seconds <= 10) {
            printf("Seconds passed: %d \n", seconds);
            old_seconds = seconds;
        }
    }

    install_vector(VEC_VBL_ISR, orig_vector);

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


/*---------- FUNCTION: do_vbl_isr -------------------------
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
void do_vbl_isr() {
    /* 
    TODO
    - update music (as necessary)
    - process synchronous events and update model (as necessary)
    - set render_request = TRUE
    */

    static int counter = 0;
    if (counter == 69) {
        seconds += 1;
        counter = 0;
    } else {
        counter += 1;
    }
}