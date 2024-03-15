#include "types.h"
#include "inputs.h"





SCANCODE read_scancode()
{
    volatile       UINT8    * const IKBD_control = CONTROL;
    volatile const UINT8    * const IKBD_status = STATUS;
    volatile const SCANCODE * const IKBD_RDR = RDR;
    long orig_ssp;

    orig_ssp = Super(0);

    *IKBD_control = RX_DISABLE;

    while(!(*IKBD_status & FULL));
    
    *IKBD_control = RX_ENABLE;

    Super(orig_ssp);

    return *IKBD_RDR;

}