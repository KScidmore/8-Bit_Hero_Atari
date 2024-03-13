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
	init_score(model, 32, 32, 0);
	init_multiplier(model, 544, 32, 1);
	init_fretboard(model);
	init_fail_bar(model, 224, 41, 50);
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
    model->note.v_dir = 1;            /* constant */
    model->note.size_x = 32;          /* constant */
    model->note.size_y = 32;          /* constant */
    model->note.is_played = FALSE;
	model->note.note_type = note_type;
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
void generate_note(Model *model)
{
	/* TODO */
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
    model->score.pos_x = pos_x;
    model->score.pos_y = pos_y;
    model->score.size_x = 128;
    model->score.size_y = 32;
	model->score.value = 0;
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
void init_score_digit(Model *model, DIGIT_POS digit_pos, UINT16 pos_x, UINT16 pos_y)
{
	model->score.scores[digit_pos].pos_x = pos_x;
	model->score.scores[digit_pos].pos_y = pos_y;
	model->score.scores[digit_pos].size_x = 32;
	model->score.scores[digit_pos].size_y = 32;
	model->score.scores[digit_pos].pos_x = 0;
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
	UINT8 ones_val = model->score.scores[ONES].value;
	UINT8 tens_val = model->score.scores[TENS].value;

	if (update_val == 0)
	{
		return;
	}
	else if (update_val < 10)
	{
		if ((ones_val + update_val) < 10)
		{
			model->score.scores[ONES].value += update_val;
		}
		else
		{
			model->score.scores[TENS].value += update_val / 10; 
			model->score.scores[ONES].value += update_val % 10;
		}
	}
	else if (update_val >= 10)
	{
		model->score.scores[TENS].value += update_val / 10; 
		model->score.scores[ONES].value += update_val % 10;
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
	if (model->note_streak.value > 40)
	{
		model->multiplier.value = 8;
	}
	else if (model->note_streak.value <= 9)
	{
		model->multiplier.value = 4;
	}
	else if (model->note_streak.value <= 9)
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