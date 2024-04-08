#include <stdio.h>
#include <osbind.h>
#include "types.h"
#include "inputs.h"
#include "raster.h"
#include "events.h"
#define SIZE 50


/*---------- FUNCTION: read_char -------------------------
/  PURPOSE:
/    Reads a character from the keyboard
/ 
/  CALLER INPUT:
/    None
/
/  CALLER OUTPUT:
/    Returns the character that was read, -1 if no input
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/    None
/--------------------------------------------------------*/
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
/*---------- FUNCTION: play_on_fret ----------------------
/  PURPOSE:
/    Input helper function that iterates through the lane
/    where input was detected until an active note is found and calls
/    the set play on fret event
/ 
/  CALLER INPUT:
/    Model *model - Pointer to the game model
/    FRET_POS fret - The inputted fret
/
/  CALLER OUTPUT:
/    None
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/    None
/--------------------------------------------------------*/
void play_on_fret(Model *model, FRET_POS fret) {
    
    int i;

    for (i = 0; i < SIZE; i++) {
        if (model->lanes[fret].notes[i].is_active == TRUE) {
            switch (fret) {
                case FRET_A:
                    set_play_on_fret_a(model, i);                
                    break;
                case FRET_S:
                    set_play_on_fret_s(model, i);
                    break;
                case FRET_D:
                    set_play_on_fret_d(model, i);
                    break;
                case FRET_F:
                    set_play_on_fret_f(model, i);
                    break;
            }
            break;
        }
    }
}


