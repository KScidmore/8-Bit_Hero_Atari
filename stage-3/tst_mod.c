/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   tst_mod.c
/  Citations:   
/    - TODO 
/
/  Program Purposes:
/    Model testing file
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
/    Test for checking relevant model details
/  
/  CALLER INPUT:
/    N/A
/  
/  CALLER OUTPUT:
/    N/A
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    N/A 
/--------------------------------------------------------*/
void test_1()
{
	Model model;
	init_model(&model);
	
	print_model_details(&model);
}


/*---------- FUNCTION: print_model_details ----------------
/  PURPOSE:
/    Prints all relevant model details
/  
/  CALLER INPUT:
/    Model *model
/ 		-Pointer to a model structure
/  
/  CALLER OUTPUT:
/    N/A
/  
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    N/A
/--------------------------------------------------------*/
void print_model_details(Model *model) {
    int i;

	printf("Model Structure:\n\n");

    for (i = 0; i < FRETS_SIZE; i++) {
        printf("Fret %d: Position X: %u, Position Y: %u, Size X: %u, Size Y: %u\n\n",
               i, model->frets[i].pos_x, model->frets[i].pos_y, 
			   model->frets[i].size_x, model->frets[i].size_y);
    }
	
	printf("Score: Ones X: %u, Tens X: %u, Hundereds X: %u, Thousands X: %u, Position Y: %u, Total Size X: %u, Total Size Y: %u, Value: %u\n\n",
           model->score.ones_x, model->score.tens_x, model->score.hunds_x, model->score.thous_x, model->score.pos_y, model->score.size_x, 
		   model->score.size_y, model->score.value);

    printf("Multiplier: Position X: %u, Position Y: %u, Total Size X: %u, Total Size Y: %u, Digit Size X: %u, Digit Size Y: %u, Value: %u\n\n",
           model->multiplier.pos_x, model->multiplier.pos_y, model->multiplier.total_size_x, 
		   model->multiplier.total_size_y, model->multiplier.digit_size_x, 
		   model->multiplier.digit_size_y, model->multiplier.value);


    printf("Fail Bar: Position X: %u, Position Y: %u, Size X: %u, Size Y: %u, Value: %u\n\n",
           model->fail_bar.pos_x, model->fail_bar.pos_y, model->fail_bar.size_x, 
		   model->fail_bar.size_y, model->fail_bar.value);
}
