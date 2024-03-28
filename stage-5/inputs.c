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

void play_on_fret(Model *model, FRET_POS fret, UINT32 *base) {
    
    int i;

    for (i = 0; i < SIZE; i++) {
        if (model->lanes[fret].notes[i].is_active == TRUE) {
            switch (fret) {
                case FRET_A:
                    set_play_on_fret_a(model, i, base);
                    break;
                case FRET_S:
                    set_play_on_fret_s(model, i, base);
                    break;
                case FRET_D:
                    set_play_on_fret_d(model, i, base);
                    break;
                case FRET_F:
                    set_play_on_fret_f(model, i, base);
                    break;
            }
            break;
        }
    }
}
/*void check_input(Model *model, char input_value){

    int i, size;

    size = 50;

    switch(input_value){
        case 'a':
        
        for(i = 0; i < size; i++){

            if(model->lanes[FRET_A].notes[i].is_active == TRUE){

                set_play_on_fret_a(model, i);

                break;
                
            }

        }
            break;

        case 's':
        
        for(i = 0; i < size; i++){

            if(model->lanes[FRET_S].notes[i].is_active == TRUE){

                set_play_on_fret_s(model, i);

                break;
                
            }

        }
            break;

        case 'd':
        for(i = 0; i < size; i++){

            if(model->lanes[FRET_D].notes[i].is_active == TRUE){

                set_play_on_fret_d(model, i);

                break;
                
            }

        }
            break;

        case 'f':

        for(i = 0; i < size; i++){

            if(model->lanes[FRET_F].notes[i].is_active == TRUE){

                set_play_on_fret_f(model, i);

                break;
                
            }

        }
            break;
    }


}*/

