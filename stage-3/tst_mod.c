/* ---------- ID HEADER ----------
   Authors:     Andrew Boisvert, Kyle Scidmore
   Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
   File Name:   tst_mod.c
   Citations:   
     - TODO 


 Program Purposes:
   Data Structures: 
     - TODO

   Functions:
     - TODO  
*/

#include <stdio.h>
#include "model.h"
#include "model.c"

int main() 
{
	test_1();
	return 0;
}

void test_1()
{
	Model model;
	init_model(&model);
	
	print_model(&model);
}

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

    printf("Score: Position X: %u, Position Y: %u, Total Size X: %u, Total Size Y: %u, Digit Size X: %u, Digit Size Y: %u, Value: %u\n",
           model->score.pos_x, model->score.pos_y, model->score.total_size_x, model->score.total_size_y,
           model->score.digit_size_x, model->score.digit_size_y, model->score.value);

    printf("Multiplier: Position X: %u, Position Y: %u, Total Size X: %u, Total Size Y: %u, Digit Size X: %u, Digit Size Y: %u, Value: %u\n",
           model->multiplier.pos_x, model->multiplier.pos_y, model->multiplier.total_size_x, model->multiplier.total_size_y,
           model->multiplier.digit_size_x, model->multiplier.digit_size_y, model->multiplier.value);

    printf("Fretboard: Position X: %u, Position Y: %u, Size X: %u, Size Y: %u\n",
           model->fretboard.pos_x, model->fretboard.pos_y, model->fretboard.size_x, model->fretboard.size_y);

    printf("Fail Bar: Position X: %u, Position Y: %u, Size X: %u, Size Y: %u, Value: %u\n",
           model->fail_bar.pos_x, model->fail_bar.pos_y, model->fail_bar.size_x, model->fail_bar.size_y, model->fail_bar.value);
}
