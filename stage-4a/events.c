/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   events.c
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
#include "types.h"

/*---------- ASYNCHRONOUS (INPUT) EVENTS ------------------------------------*/

/*---------- FUNCTION: set_play_on_fret_a -----------------
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
void set_play_on_fret_a(Model *model, FRET_POS fret, UINT8 index)
{
	if (note_collision_a(model, fret, index))
	{
		update_score(model, fret, index);
		update_multiplier(model);
		update_fail_bar(model, 1);
	}
	else 
	{
		update_multiplier(model);
		update_fail_bar(model, -1);
		if (model->fail_bar.value == 0)
		{
			fail_song();
		}
	}
}


/*---------- FUNCTION: set_play_on_fret_s -----------------
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
void set_play_on_fret_s(Model *model, FRET_POS fret, UINT8 index)
{
	if (note_collision_s(model, fret, index))
	{
		update_score(model, fret, index);
		update_multiplier(model);
		update_fail_bar(model, 1);
	}
	else 
	{
		update_multiplier(model);
		update_fail_bar(model, -1);
		if (model->fail_bar.value == 0)
		{
			fail_song();
		}
	}
}


/*---------- FUNCTION: set_play_on_fret_d -----------------
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
void set_play_on_fret_d(Model *model, FRET_POS fret, UINT8 index)
{
	if (note_collision_d(model, fret, index))
	{
		update_score(model, fret, index);
		update_multiplier(model);
		update_fail_bar(model, 1);
	}
	else 
	{
		update_multiplier(model);
		update_fail_bar(model, -1);
		if (model->fail_bar.value == 0)
		{
			fail_song();
		}
	}
}


/*---------- FUNCTION: set_play_on_fret_f -----------------
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
void set_play_on_fret_f(Model *model, FRET_POS fret, UINT8 index)
{
	if (note_collision_f(model, fret, index))
	{
		update_score(model, fret, index);
		update_multiplier(model);
		update_fail_bar(model, 1);
	}
	else 
	{
		update_multiplier(model);
		update_fail_bar(model, -1);
		if (model->fail_bar.value == 0)
		{
			fail_song();
		}
	}
}


/*---------- FUNCTION: quit_game --------------------------
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
void quit_game(Model *model)
{
	/* exit, need to replace later with proper call */
}

/*---------- SYNCHRONOUS (TIMED) EVENTS -------------------------------------*/

/*---------- FUNCTION: move_note --------------------------
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
void move_note(Model *model, FRET_POS fret, UINT8 index)
{
	set_note_pos(model, fret, index);
}




/*---------- CONDITION-BASED (CASCADED) EVENTS ------------------------------*/

/*---------- FUNCTION: note_collision_a -------------------
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
BOOL note_collision_a(Model *model, FRET_POS fret, UINT8 index)
{
	if (model->lanes[fret].notes[index].pos_y > 320 ||
		model->lanes[fret].notes[index].pos_y < 384)
	{
		if (model->frets[FRET_A].is_depressed)
		{
			return TRUE;
		}
	}

	return FALSE;
}


/*---------- FUNCTION: note_collision_s -------------------
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
BOOL note_collision_s(Model *model, FRET_POS fret, UINT8 index)
{
	if (model->lanes[fret].notes[index].pos_y > 320 ||
		model->lanes[fret].notes[index].pos_y < 384)
	{
		if (model->frets[FRET_S].is_depressed)
		{
			return TRUE;
		}
	}

	return FALSE;
}


/*---------- FUNCTION: note_collision_d -------------------
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
BOOL note_collision_d(Model *model, FRET_POS fret, UINT8 index)
{
	if (model->lanes[fret].notes[index].pos_y > 320 ||
		model->lanes[fret].notes[index].pos_y < 384)
	{
		if (model->frets[FRET_D].is_depressed)
		{
			return TRUE;
		}
	}

	return FALSE;
}


/*---------- FUNCTION: note_collision_f -------------------
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
BOOL note_collision_f(Model *model, FRET_POS fret, UINT8 index)
{
	if (model->lanes[fret].notes[index].pos_y > 320 ||
		model->lanes[fret].notes[index].pos_y < 384)
	{
		if (model->frets[FRET_F].is_depressed)
		{
			return TRUE;
		}
	}

	return FALSE;
}


/*---------- FUNCTION: fail_song --------------------------
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
void fail_song()
{
	/* need to replace with return to splash screen or menu */
}
