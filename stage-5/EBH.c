#include <osbind.h>
#include <stdio.h>
#include <unistd.h>
#include "types.h"
#include "model.h"
#include "renderer.h"
#include "rast_asm.h"
#include "inputs.h"
#include "events.h"


int main()
{
    
    UINT32 time_then, time_now, time_elapsed;
    UINT8 *base = Physbase();
	UINT32 *base32 = Physbase();

    Model model;
    int note_gen = 0;
    UINT8 i = 0;
    UINT8 j = 0;
    UINT8 k = 0;
    UINT8 l = 0;
    UINT8 note_counter = 0;
    char input_value;
    char ch;
    UINT16 score;
    init_model(&model);

    init_scene(base, base32, &model);
   
    time_then = get_time();

    /*Main game loop*/
    while(1){

        /*Get time*/
        time_now = get_time();
        time_elapsed = time_now - time_then;


        /*Check for input*/
        ch = read_char();

        /*Handle input*/
        if(ch != -1){
            switch(ch) {
                case 'a':
                    play_on_fret(&model, FRET_A, base32);
                    break;
                case 's':
                    play_on_fret(&model, FRET_S, base32);
                    break;
                case 'd':
                    play_on_fret(&model, FRET_D, base32);
                    break;
                case 'f':
                    play_on_fret(&model, FRET_F, base32);
                    break;
                case 27:
                    score = model.score.value;

                    printf("Model score value: %d\n", score);
                    return 0;

        }
    }

        /*Sync Events*/

        /*Generate and move notesY*/

        if(time_elapsed >= 1){

            render_next(base32, &model);  
        }

         if(time_elapsed >= note_gen){

            if(note_counter == 0){

                render_new_note(base32, &model, FRET_A, i);
                note_counter += 1;
                i++;
                note_gen += 60;

            }
            else if(note_counter == 1){

                render_new_note(base32, &model, FRET_S, j);
                note_counter += 1;
                j++;
                note_gen += 60;


            }
            else if(note_counter == 2){

                render_new_note(base32, &model, FRET_D, k);
                note_counter += 1;
                k++;
                note_gen += 60;

            }
            else{

                render_new_note(base32, &model, FRET_F, l);
                note_counter = 0;
                l++;
                note_gen += 60;

            } 
        }

        

    }



    return 0;
    
}

UINT32 get_time(){

	UINT32 time_now;
	UINT32 old_ssp;
	UINT32 *timer = (UINT32 *)0x462;
	
	old_ssp = Super(0); 
	time_now = *timer;
	Super(old_ssp); 
	
	return time_now;
	
}
