#include <stdio>
#include "PSG.h"

void psg_write(UINT8 register, UINT8 value){

    volatile UINT8 *register_select = SELECT_ADDRESS;
    volatile UINT8 *register_write = WRITE_ADDRESS;

    UINT32 old_ssp;

    old_ssp = Super(0);

    *register_select = register;
    *register_write = value;

    Super(old_ssp);

}

void psg_read(UINT8 register){

}



void set_tone(){


}

void set_volume(){


}

void set_envelope(){
    
}

void enable_channel(){


}

