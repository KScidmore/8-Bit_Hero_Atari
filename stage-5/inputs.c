#include <stdio.h>
#include <osbind.h>
#include "types.h"
#include "inputs.h"


volatile       UINT8    * const IKBD_control = CONTROL;
volatile const UINT8    * const IKBD_status = STATUS;
volatile const SCANCODE * const IKBD_RDR = RDR;


char read_char() {
    if (Cconis() != 0) { 
        char ch = Cconin();
        if (ch >= 'A' && ch <= 'Z') { 
            ch += 32;
        }
        return ch;
    } else {
        return -1; 
    }
}

SCANCODE read_scancode()
{

    long orig_ssp;

    UINT16 timeout_counter = 0;

    orig_ssp = Super(0);

    *IKBD_control = RX_DISABLE;

    while(!(*IKBD_status & FULL)){

        if(timeout_counter >= TIMEOUT_VALUE){

            break;

        }

        timeout_counter++;
    }
    
    *IKBD_control = RX_ENABLE;

    Super(orig_ssp);

    return *IKBD_RDR;

}