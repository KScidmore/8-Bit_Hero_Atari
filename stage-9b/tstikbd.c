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

#include "ikbd.h"
#include "super.h"

Char_Buffer buffer;

int main () {

    init_char_buffer(&buffer);

    install_ikbd_vector();

    /* can fill in later and test it out */

    restore_ikbd_vector();

    return 0;
}