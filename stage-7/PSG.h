/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   PSG.h
/  Citations:   
/    - TODO 
/
/  Program Purposes:
/    Data Structures: 
/      - TODO
/
/    Functions:
/      - TODO  
/--------------------------------------------------------*/

#ifndef PSG_H
#define PSG_H

#include "types.h"

/*---------- REGISTER ADDRESSES ---------------------------------------------*/
#define SELECT_ADDRESS 0xFF8800
#define WRITE_ADDRESS 0xFF8802

/*---------- NOTES ----------------------------------------------------------*/
/* TODO */

/*---------- FUNCTION PROTOTYPES --------------------------------------------*/
void psg_write(UINT8 register, UINT8 value);

#endif