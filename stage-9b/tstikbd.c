/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   tstikbd.c
/  Citations:   
/    - N/A
/
/  Program Purposes:
/    The purpose of this program is to test your IKBD
/    implementation to make sure it is working as expected.
/--------------------------------------------------------*/

#include <stdio.h>
#include "ikbd.h"
#include "super.h"
#include "types.h"
#include "globals.h"
#define NO_CHAR '\0'

UINT8 read_char();


int main () {

    UINT8 ch;

    init_char_buffer();

    install_ikbd_vector();

    ch = read_char();

    while(ch != 27){

        if(ch != NO_CHAR){

            printf("Character :%c \n", ch);

        }

        ch = read_char();

    }


    restore_ikbd_vector();

    return 0;
}
/*---------- FUNCTION: read_char ------------------------
/  PURPOSE:
/    Reads a character from the input buffer
/  
/  CALLER INPUT:
/    N/A
/  
/  CALLER OUTPUT:
/    Returns the character as a UINT8 if valid
/    Otherwise returns NULL
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    N/A
/--------------------------------------------------------*/
UINT8 read_char() {

    UINT8 ch;

    if (!is_empty()) { 
       
        ch = dequeue_to_ascii();

        return ch;

    } else {

        return NO_CHAR; 

    }
}