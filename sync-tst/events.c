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
#include "raster.h"

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
void set_play_on_fret_a(Model *model, UINT8 index)
{
	if (note_collision_a(model, index))
	{
		update_score(model);
		update_multiplier(model);
		update_fail_bar(model, 20);
		update_note_streak(model, FALSE);
	}
	else 
	{
		update_multiplier(model);
		update_fail_bar(model, -20);
		update_note_streak(model, TRUE);
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
void set_play_on_fret_s(Model *model, UINT8 index)
{
	if (note_collision_s(model, index))
	{
		update_score(model);
		update_multiplier(model);
		update_fail_bar(model, 20);
		update_note_streak(model, FALSE);

	}
	else 
	{
		update_multiplier(model);
		update_fail_bar(model, -20);
		update_note_streak(model, TRUE);
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
void set_play_on_fret_d(Model *model, UINT8 index)
{
	if (note_collision_d(model, index))
	{
		update_score(model);
		update_multiplier(model);
		update_fail_bar(model, 20);
		update_note_streak(model, FALSE);
		
	}
	else 
	{
		update_multiplier(model);
		update_fail_bar(model, -20);
		update_note_streak(model, TRUE);
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
void set_play_on_fret_f(Model *model, UINT8 index)
{
	if (note_collision_f(model, index))
	{
		update_score(model);
		update_multiplier(model);
		update_fail_bar(model, 20);
		update_note_streak(model, FALSE);
	}
	else 
	{
		update_multiplier(model);
		update_fail_bar(model, -20);
		update_note_streak(model, TRUE);
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
BOOL note_collision_a(Model *model, UINT8 index)
{
	if (model->lanes[FRET_A].notes[index].pos_y > 300 &&
		model->lanes[FRET_A].notes[index].pos_y < 384)
	{
	
		return TRUE;
	}
	else{

			return FALSE;
	}

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
BOOL note_collision_s(Model *model, UINT8 index)
{
	if (model->lanes[FRET_S].notes[index].pos_y > 300 &&
		model->lanes[FRET_S].notes[index].pos_y < 384)
	{
	
		return TRUE;

	}else{

		return FALSE;
	}
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
BOOL note_collision_d(Model *model, UINT8 index)
{
	if (model->lanes[FRET_D].notes[index].pos_y > 300 &&
		model->lanes[FRET_D].notes[index].pos_y < 384)
	{
	
		return TRUE;

	}else{

	return FALSE;
	}
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
BOOL note_collision_f(Model *model, UINT8 index)
{
	if (model->lanes[FRET_F].notes[index].pos_y > 300 &&
		model->lanes[FRET_F].notes[index].pos_y < 384)
	{
	
		return TRUE;

	}else{

	return FALSE;

	}
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
