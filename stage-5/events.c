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
void set_play_on_fret_a(Model *model, UINT8 index, UINT32 *base)
{
	if (note_collision_a(model, index, base))
	{
		update_score(model);
		update_multiplier(model);
		update_fail_bar(model, 20);
		update_note_streak(model);
	}
	else 
	{
		update_multiplier(model);
		update_fail_bar(model, -20);
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
void set_play_on_fret_s(Model *model, UINT8 index, UINT32 *base)
{
	if (note_collision_s(model, index, base))
	{
		update_score(model);
		update_multiplier(model);
		update_fail_bar(model, 20);
		update_note_streak(model);
	}
	else 
	{
		update_multiplier(model);
		update_fail_bar(model, -20);
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
void set_play_on_fret_d(Model *model, UINT8 index, UINT32 *base)
{
	if (note_collision_d(model, index, base))
	{
		update_score(model);
		update_multiplier(model);
		update_fail_bar(model, 20);
		update_note_streak(model);
		
	}
	else 
	{
		update_multiplier(model);
		update_fail_bar(model, -20);
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
void set_play_on_fret_f(Model *model, UINT8 index, UINT32 *base)
{
	if (note_collision_f(model, index, base))
	{
		update_score(model);
		update_multiplier(model);
		update_fail_bar(model, 20);
		update_note_streak(model);
	}
	else 
	{
		update_multiplier(model);
		update_fail_bar(model, -20);
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
BOOL note_collision_a(Model *model, UINT8 index, UINT32 *base)
{
	if (model->lanes[FRET_A].notes[index].pos_y > 320 &&
		model->lanes[FRET_A].notes[index].pos_y < 384)
	{
		model->lanes[FRET_A].notes[index].is_active = FALSE;
		clear_32(base, model->lanes[FRET_A].notes[index].pos_x, model->lanes[FRET_A].notes[index].pos_y, model->lanes[FRET_A].notes[index].size_y);
	
		return TRUE;
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
BOOL note_collision_s(Model *model, UINT8 index, UINT32 *base)
{
	if (model->lanes[FRET_S].notes[index].pos_y > 320 &&
		model->lanes[FRET_S].notes[index].pos_y < 384)
	{

		model->lanes[FRET_S].notes[index].is_active = FALSE;
		clear_32(base, model->lanes[FRET_S].notes[index].pos_x, model->lanes[FRET_S].notes[index].pos_y, model->lanes[FRET_S].notes[index].size_y);
	
		return TRUE;
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
BOOL note_collision_d(Model *model, UINT8 index, UINT32 *base)
{
	if (model->lanes[FRET_D].notes[index].pos_y > 320 &&
		model->lanes[FRET_D].notes[index].pos_y < 384)
	{
		model->lanes[FRET_D].notes[index].is_active = FALSE;
		clear_32(base, model->lanes[FRET_D].notes[index].pos_x, model->lanes[FRET_D].notes[index].pos_y, model->lanes[FRET_D].notes[index].size_y);
	
		return TRUE;
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
BOOL note_collision_f(Model *model, UINT8 index, UINT32 *base)
{
	if (model->lanes[FRET_F].notes[index].pos_y > 320 &&
		model->lanes[FRET_F].notes[index].pos_y < 384)
	{
		model->lanes[FRET_F].notes[index].is_active = FALSE;
		clear_32(base, model->lanes[FRET_F].notes[index].pos_x, model->lanes[FRET_F].notes[index].pos_y, model->lanes[FRET_F].notes[index].size_y);
	
		return TRUE;
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
