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
#define NO_CHAR "\0"

UINT8 read_char();


int main () {

    UINT8 ch;

    init_char_buffer();

    install_ikbd_vector();

    ch = read_char();

    while(ch != 27){


        printf("Character %d:\n", ch);

        ch = read_char();

    }


    restore_ikbd_vector();

    return 0;
}

UINT8 read_char() {

    UINT8 ch;

    if (!is_empty()) { 
       
        ch = dequeue_to_ascii();

        return ch;

    } else {

        return NULL; 

    }
}