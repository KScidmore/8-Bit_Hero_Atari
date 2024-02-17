/* ---------- ID HEADER ----------
   Authors:     Andrew Boisvert, Kyle Scidmore
   Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
   File Name:   model.c
   Citations:   
     - TODO 


 Program Purposes:
   Data Structures: 
     - TODO

   Functions:
     - TODO  
*/

#include "model.h"
#include "types.h"

/* ---------- FUNCTION: init_model ----------

 PURPOSE:
   TODO

 CALLER INPUT:
   TODO

 CALLER OUTPUT:
   N/A

 ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
   TODO
*/
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


/* ---------- FUNCTION: init_fret ----------

 PURPOSE:
   Initializes a fret object. 

 CALLER INPUT:
   *fret	=	a pointer to the fret object
   pos_x	=	the object's x-coordinate for its screen position
   pos_y	= 	the object's y-coordinate for its screen position

 CALLER OUTPUT:
   N/A

 ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
   TODO
*/
void init_fret(Model *model, FRET_POS fret_pos, UINT16 pos_x, UINT16 pos_y)
{
	model->frets[fret_pos].pos_x = pos_x;
    model->frets[fret_pos].pos_y = pos_y;
    model->frets[fret_pos].size_x = 32;
    model->frets[fret_pos].size_y = 32;
}


/* ---------- FUNCTION: init_note ----------

 PURPOSE:
   TODO - purpose, from the caller's perspective (if not
   perfectly clear from the name)

 CALLER INPUT:
   TODO - the purpose of each input parameter (if not 
   perfectly clear from the name)

 CALLER OUTPUT:
   TODO - the purose of each output parameter and return 
   value (if not perfectly clear from the name)

 ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
   TODO
*/
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


/* ---------- FUNCTION: set_note_pos ----------

 PURPOSE:
   TODO - purpose, from the caller's perspective (if not
   perfectly clear from the name)

 CALLER INPUT:
   TODO - the purpose of each input parameter (if not 
   perfectly clear from the name)

 CALLER OUTPUT:
   TODO - the purose of each output parameter and return 
   value (if not perfectly clear from the name)

 ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
   TODO
*/
void set_note_pos(Model *model)
{
	model->note.pos_y += 1;
}


/* ---------- FUNCTION: set_note_is_played ----------

 PURPOSE:
   TODO - purpose, from the caller's perspective (if not
   perfectly clear from the name)

 CALLER INPUT:
   TODO - the purpose of each input parameter (if not 
   perfectly clear from the name)

 CALLER OUTPUT:
   TODO - the purose of each output parameter and return 
   value (if not perfectly clear from the name)

 ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
   TODO
*/
void set_note_is_played(Model *model, BOOL is_played)
{
	model->note.is_played = is_played;
}


/* ---------- FUNCTION: generate_note ----------

 PURPOSE:
   TODO - purpose, from the caller's perspective (if not
   perfectly clear from the name)

 CALLER INPUT:
   TODO - the purpose of each input parameter (if not 
   perfectly clear from the name)

 CALLER OUTPUT:
   TODO - the purose of each output parameter and return 
   value (if not perfectly clear from the name)

 ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
   TODO
*/
void generate_note(Model *model)
{
	/* TODO */
}


/* ---------- FUNCTION: init_note_streak ----------

 PURPOSE:
   TODO - purpose, from the caller's perspective (if not
   perfectly clear from the name)

 CALLER INPUT:
   TODO - the purpose of each input parameter (if not 
   perfectly clear from the name)

 CALLER OUTPUT:
   TODO - the purose of each output parameter and return 
   value (if not perfectly clear from the name)

 ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
   TODO
*/
void init_note_streak(Model *model)
{
	model->note_streak.pos_x = 32;
	model->note_streak.pos_y = 64;
	model->note_streak.total_size_x = 128;
	model->note_streak.total_size_y = 32;
	model->note_streak.digit_size_x = 32;
	model->note_streak.digit_size_y = 32;
	model->note_streak.value = 0;
}

void update_note_streak(Model *model)
{

}


/* ---------- FUNCTION: init_score ----------

 PURPOSE:
   TODO - purpose, from the caller's perspective (if not
   perfectly clear from the name)

 CALLER INPUT:
   TODO - the purpose of each input parameter (if not 
   perfectly clear from the name)

 CALLER OUTPUT:
   TODO - the purose of each output parameter and return 
   value (if not perfectly clear from the name)

 ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
   TODO
*/
void init_score(Model *model, UINT16 pos_x, UINT16 pos_y, UINT16 value)
{
    model->score.pos_x = pos_x;
    model->score.pos_y = pos_y;
    model->score.total_size_x = 128;
    model->score.total_size_y = 32;
    model->score.digit_size_x = 32;
    model->score.digit_size_y = 32;
    model->score.value = value;
}


/* ---------- FUNCTION: update_score ----------

 PURPOSE:
   TODO - purpose, from the caller's perspective (if not
   perfectly clear from the name)

 CALLER INPUT:
   TODO - the purpose of each input parameter (if not 
   perfectly clear from the name)

 CALLER OUTPUT:
   TODO - the purose of each output parameter and return 
   value (if not perfectly clear from the name)

 ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
   TODO
*/
void update_score(Model *model)
{
	model->score.value += model->multiplier.value * model->note.note_type;
}


/* ---------- FUNCTION: init_multiplier ----------

 PURPOSE:
   TODO - purpose, from the caller's perspective (if not
   perfectly clear from the name)

 CALLER INPUT:
   TODO - the purpose of each input parameter (if not 
   perfectly clear from the name)

 CALLER OUTPUT:
   TODO - the purose of each output parameter and return 
   value (if not perfectly clear from the name)

 ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
   TODO
*/
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


/* ---------- FUNCTION: update_multiplier ----------

 PURPOSE:
   TODO - purpose, from the caller's perspective (if not
   perfectly clear from the name)

 CALLER INPUT:
   TODO - the purpose of each input parameter (if not 
   perfectly clear from the name)

 CALLER OUTPUT:
   TODO - the purose of each output parameter and return 
   value (if not perfectly clear from the name)

 ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
   TODO
*/
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


/* ---------- FUNCTION: init_fretboard ----------

 PURPOSE:
   TODO - purpose, from the caller's perspective (if not
   perfectly clear from the name)

 CALLER INPUT:
   TODO - the purpose of each input parameter (if not 
   perfectly clear from the name)

 CALLER OUTPUT:
   TODO - the purose of each output parameter and return 
   value (if not perfectly clear from the name)

 ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
   TODO
*/
void init_fretboard(Model *model)
{
    model->fretboard.pos_x = 150;
    model->fretboard.pos_y = 150;
    model->fretboard.size_x = 350;
    model->fretboard.size_y = 350;
}


/* ---------- FUNCTION: init_fail_bar ----------

 PURPOSE:
   TODO - purpose, from the caller's perspective (if not
   perfectly clear from the name)

 CALLER INPUT:
   TODO - the purpose of each input parameter (if not 
   perfectly clear from the name)

 CALLER OUTPUT:
   TODO - the purose of each output parameter and return 
   value (if not perfectly clear from the name)

 ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
   TODO
*/
void init_fail_bar(Model *model, UINT16 pos_x, UINT16 pos_y, UINT16 value)
{
    model->fail_bar.pos_x = pos_x; 
    model->fail_bar.pos_y = pos_y; 
    model->fail_bar.size_x = 136; 
    model->fail_bar.size_y = 16; 
    model->fail_bar.value = 50;
}


/* ---------- FUNCTION: update_fail_bar ----------

 PURPOSE:
   TODO - purpose, from the caller's perspective (if not
   perfectly clear from the name)

 CALLER INPUT:
   TODO - the purpose of each input parameter (if not 
   perfectly clear from the name)

 CALLER OUTPUT:
   TODO - the purose of each output parameter and return 
   value (if not perfectly clear from the name)

 ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
   TODO
*/
void update_fail_bar(Model *model, UINT16 value)
{
	model->fail_bar.value += value;
}