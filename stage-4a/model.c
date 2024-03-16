/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   model.c
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

#include "model.h"
#include "types.h"

/*---------- Model Functions ------------------------------------------------*/
/*---------- FUNCTION: init_model -------------------------
/  PURPOSE:
/    TODO
/ 
/  CALLER INPUT:
/    TODO
/ 
/  CALLER OUTPUT:
/    N/A
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/    TODO
/--------------------------------------------------------*/
void init_model(Model *model)
{
	init_fret(model, FRET_A, 160, 326);
	init_fret(model, FRET_S, 256, 326);
	init_fret(model, FRET_D, 352, 326);
	init_fret(model, FRET_F, 448, 326);
	init_note(model, 150, 150, 0, SHORT_NOTE);
	init_note_streak(model);
	init_score(model, 32, 0, 0);
	init_multiplier(model, 544, 32, 1);
	init_fretboard(model);
	init_fail_bar(model, 224, 0, 50);
}

/*---------- Fret Functions -------------------------------------------------*/
/*---------- FUNCTION: init_fret --------------------------
/  PURPOSE:
/    Initializes a fret object. 
/ 
/  CALLER INPUT:
/    *fret	=	a pointer to the fret object
/    pos_x	=	the object's x-coordinate for its screen position
/    pos_y	= 	the object's y-coordinate for its screen position
/ 
/  CALLER OUTPUT:
/    N/A
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/    TODO
/--------------------------------------------------------*/
void init_fret(Model *model, FRET_POS fret_pos, UINT16 pos_x, UINT16 pos_y)
{
	model->frets[fret_pos].pos_x = pos_x;
    model->frets[fret_pos].pos_y = pos_y;
    model->frets[fret_pos].size_x = 32;
    model->frets[fret_pos].size_y = 32;
	model->frets[fret_pos].is_depressed = FALSE;
}


/*---------- FUNCTION: set_fret_depressed -----------------
/  PURPOSE:
/    TODO - purpose, from the caller's perspective (if not
/    perfectly clear from the name)
/ 
/  CALLER INPUT:
/    TODO - the purpose of each input parameter (if not 
/    perfectly clear from the name)
/ 
/  CALLER OUTPUT:
/    TODO - the purose of each output parameter and return 
/    value (if not perfectly clear from the name)
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/    TODO
/--------------------------------------------------------*/
void set_fret_depressed(Model *model, FRET_POS fret, BOOL is_depressed)
{
	model->frets[fret].is_depressed = is_depressed;
}

/*---------- Note Functions -------------------------------------------------*/
/*---------- FUNCTION: TODO -------------------------------
/  PURPOSE:
/    TODO - purpose, from the caller's perspective (if not
/    perfectly clear from the name)
/ 
/  CALLER INPUT:
/    TODO - the purpose of each input parameter (if not 
/    perfectly clear from the name)
/ 
/  CALLER OUTPUT:
/    TODO - the purose of each output parameter and return 
/    value (if not perfectly clear from the name)
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/    TODO
/--------------------------------------------------------*/
void init_note(Model *model, UINT16 pos_x, UINT16 pos_y, int delta_y, NOTE_TYPE note_type)
{
    model->note.pos_x = pos_x;
    model->note.pos_y = pos_y;
    model->note.delta_y = delta_y;
    model->note.v_dir = 1;            	/* constant */
    model->note.size_x = 32;          	/* constant */
    model->note.size_y = 16;          	/* constant */
    model->note.is_played = FALSE;
	model->note.note_type = note_type;
}


void init_lane(Model *model, UINT16 start_x, UINT16 curr_x, UINT16 start_y,
			   UINT16 end_y, UINT16 pos_x, UINT16 pos_y, int delta_y, 
			   NOTE_TYPE note_type)
{
	int i;

	model->lane.start_x = start_x;
	model->lane.curr_x = curr_x;
	model->lane.start_y = start_y;
	model->lane.end_y = end_y;
	model->lane.counter = 0;

	for(i = 0; i < NOTES_SIZE; i++)
	{
		init_note(model->lane.notes[i], pos_x, pos_y, delta_y, note_type);
	}
}


/*---------- FUNCTION: TODO -------------------------------
/  PURPOSE:
/    TODO - purpose, from the caller's perspective (if not
/    perfectly clear from the name)
/ 
/  CALLER INPUT:
/    TODO - the purpose of each input parameter (if not 
/    perfectly clear from the name)
/ 
/  CALLER OUTPUT:
/    TODO - the purose of each output parameter and return 
/    value (if not perfectly clear from the name)
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/    TODO
/--------------------------------------------------------*/
void set_note_pos(Model *model)
{
	model->note.pos_y += 1;
}


/*---------- FUNCTION: TODO -------------------------------
/  PURPOSE:
/    TODO - purpose, from the caller's perspective (if not
/    perfectly clear from the name)
/ 
/  CALLER INPUT:
/    TODO - the purpose of each input parameter (if not 
/    perfectly clear from the name)
/ 
/  CALLER OUTPUT:
/    TODO - the purose of each output parameter and return 
/    value (if not perfectly clear from the name)
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/    TODO
/--------------------------------------------------------*/
void set_note_is_played(Model *model, BOOL is_played)
{
	model->note.is_played = is_played;
}


/*---------- Note Streak Functions ------------------------------------------*/
/*---------- FUNCTION: TODO -------------------------------
/  PURPOSE:
/    TODO - purpose, from the caller's perspective (if not
/    perfectly clear from the name)
/ 
/  CALLER INPUT:
/    TODO - the purpose of each input parameter (if not 
/    perfectly clear from the name)
/ 
/  CALLER OUTPUT:
/    TODO - the purose of each output parameter and return 
/    value (if not perfectly clear from the name)
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/    TODO
/--------------------------------------------------------*/
void init_note_streak(Model *model)
{
	model->note_streak.pos_x = 32;
	model->note_streak.pos_y = 72;
	model->note_streak.total_size_x = 128;
	model->note_streak.total_size_y = 32;
	model->note_streak.digit_size_x = 32;
	model->note_streak.digit_size_y = 32;
	model->note_streak.value = 0;
	model->note_streak.incremented_flag = FALSE;
}

/*---------- FUNCTION: TODO -------------------------------
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
void update_note_streak(Model *model)
{
	/* TODO */
}

/*---------- Score Functions ------------------------------------------------*/
/*---------- FUNCTION: TODO -------------------------------
/  PURPOSE:
/    TODO - purpose, from the caller's perspective (if not
/    perfectly clear from the name)
/ 
/  CALLER INPUT:
/    TODO - the purpose of each input parameter (if not 
/    perfectly clear from the name)
/ 
/  CALLER OUTPUT:
/    TODO - the purose of each output parameter and return 
/    value (if not perfectly clear from the name)
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/    TODO
/--------------------------------------------------------*/
void init_score(Model *model, UINT16 pos_x, UINT16 pos_y, UINT16 value)
{
    model->score.ones_x = pos_x;
	model->score.tens_x = pos_x + 32;
	model->score.hunds_x = pos_x + 64;
	model->score.thous_x = pos_x + 96;
    model->score.pos_y = pos_y;
    model->score.size_x = 128;
    model->score.size_y = 32;
	model->score.value = 0;
	model->score.prev_ones = 0;
	model->score.prev_tens = 0;
	model->score.prev_hunds = 0;
	model->score.prev_thous = 0;
	model->score.updated_flag = FALSE;
}


/*---------- FUNCTION: TODO -------------------------------
/  PURPOSE:
/    TODO - purpose, from the caller's perspective (if not
/    perfectly clear from the name)
/ 
/  CALLER INPUT:
/    TODO - the purpose of each input parameter (if not 
/    perfectly clear from the name)
/ 
/  CALLER OUTPUT:
/    TODO - the purose of each output parameter and return 
/    value (if not perfectly clear from the name)
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/    TODO
/--------------------------------------------------------*/
void update_score(Model *model)
{	
	UINT8 update_val = model->multiplier.value * model->note.note_type;
	if (update_val == 0)
	{
		model->score.updated_flag = FALSE;
	}
	else
	{
		model->score.updated_flag = TRUE;
		model->score.value += update_val;
	}
}

/*---------- Multiplier Functions -------------------------------------------*/
/*---------- FUNCTION: TODO -------------------------------
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
void init_multiplier(Model *model, UINT16 pos_x, UINT16 pos_y, UINT16 value)
{
    model->multiplier.pos_x = pos_x;
    model->multiplier.pos_y = pos_y;
    model->multiplier.total_size_x = 64;
    model->multiplier.total_size_y = 32;
    model->multiplier.digit_size_x = 32;
    model->multiplier.digit_size_y = 32;
    model->multiplier.value = value;
	model->multiplier.prev_value = 1;
}


/*---------- FUNCTION: TODO -------------------------------
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
void update_multiplier(Model *model)
{
	if (model->note_streak.value >= 40)
	{
		model->multiplier.value = 8;
	}
	else if (model->note_streak.value >= 30)
	{
		model->multiplier.value = 4;
	}
	else if (model->note_streak.value >= 20)
	{
		model->multiplier.value = 2;
	}
	else 
	{
		model->multiplier.value = 1;
	}
}

/*---------- Fretboard Functions --------------------------------------------*/
/*---------- FUNCTION: TODO -------------------------------
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
void init_fretboard(Model *model)
{
    model->fretboard.pos_x = 150;
    model->fretboard.pos_y = 150;
    model->fretboard.size_x = 350;
    model->fretboard.size_y = 350;
}

/*---------- Failbar Functions ----------------------------------------------*/
/*---------- FUNCTION: TODO -------------------------------
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
void init_fail_bar(Model *model, UINT16 pos_x, UINT16 pos_y, UINT16 value)
{
    model->fail_bar.pos_x = pos_x; 
    model->fail_bar.pos_y = pos_y; 
    model->fail_bar.size_x = 136; 
    model->fail_bar.size_y = 16; 
    model->fail_bar.value = 50;
}


/*---------- FUNCTION: TODO -------------------------------
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
void update_fail_bar(Model *model, UINT16 value)
{
	model->fail_bar.value += value;
}