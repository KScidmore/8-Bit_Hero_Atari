#include <stdio.h>
#include <osbind.h>
#include "types.h"
#include "inputs.h"
#include "raster.h"
#include "events.h"
#define SIZE 50



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


