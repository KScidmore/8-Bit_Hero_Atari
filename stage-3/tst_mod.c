/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   tst_mod.c
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

#include <stdio.h>
#include "model.h"
#include "events.h"

void test_1();
void print_model_details(Model *model);

int main() 
{
	test_1();
	return 0;
}


/*---------- FUNCTION: test_1 -----------------------------
/  PURPOSE:
/    TODO - purpose, from the caller's perspective (if not 
/    perfectly clear from the name)
/  
/  CALLER INPUT:
/    TODO - the purpose of each input parameter (if not 
/    perfectly clear from the name)
/  
/  CALLER OUTPUT:
/    TODO - the purpose of each output parameter and return 
/    value (if not perfectly clear from the name)
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    TODO 
/--------------------------------------------------------*/
void test_1()
{
	Model model;
	init_model(&model);
	
	print_model_details(&model);
}


/*---------- FUNCTION: print_model_details ----------------
/  PURPOSE:
/    TODO - purpose, from the caller's perspective (if not 
/    perfectly clear from the name)
/  
/  CALLER INPUT:
/    TODO - the purpose of each input parameter (if not 
/    perfectly clear from the name)
/  
/  CALLER OUTPUT:
/    TODO - the purpose of each output parameter and return 
/    value (if not perfectly clear from the name)
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    TODO 
/--------------------------------------------------------*/
void print_model_details(Model *model) {
	int i;
	printf("Model Structure:\n");
    for (i = 0; i < FRETS_SIZE; i++) {
        printf("Fret %d: Position X: %u, Position Y: %u, Size X: %u, Size Y: %u\n",
               i, model->frets[i].pos_x, model->frets[i].pos_y, model->frets[i].size_x, model->frets[i].size_y);
    }

    printf("Note: Position X: %u, Position Y: %u, Delta Y: %d, Vertical Direction: %d, Size X: %u, Size Y: %u, Is Played: %s\n",
           model->note.pos_x, model->note.pos_y, model->note.delta_y, model->note.v_dir,
           model->note.size_x, model->note.size_y, model->note.is_played ? "True" : "False");

    /*printf("Score: Position X: %u, Position Y: %u, Total Size X: %u, Total Size Y: %u, ",
           model->score.pos_x, model->score.pos_y, model->score.size_x, model->score.size_y);*/

    for (i = 0; i < 4; i++) {
        printf("Digit Position X: %u, Digit Position Y: %u, Digit Size X: %u, Digit Size Y: %u, Value: %u", model->score.scores[i].pos_x, model->score.scores[i].pos_y, model->score.scores[i].size_x, model->score.scores[i].size_y, model->score.scores[i].value); 
    }
    printf("\n");

    printf("Multiplier: Position X: %u, Position Y: %u, Total Size X: %u, Total Size Y: %u, Digit Size X: %u, Digit Size Y: %u, Value: %u\n",
           model->multiplier.pos_x, model->multiplier.pos_y, model->multiplier.total_size_x, model->multiplier.total_size_y,
           model->multiplier.digit_size_x, model->multiplier.digit_size_y, model->multiplier.value);

    printf("Fretboard: Position X: %u, Position Y: %u, Size X: %u, Size Y: %u\n",
           model->fretboard.pos_x, model->fretboard.pos_y, model->fretboard.size_x, model->fretboard.size_y);

    printf("Fail Bar: Position X: %u, Position Y: %u, Size X: %u, Size Y: %u, Value: %u\n",
           model->fail_bar.pos_x, model->fail_bar.pos_y, model->fail_bar.size_x, model->fail_bar.size_y, model->fail_bar.value);
}
