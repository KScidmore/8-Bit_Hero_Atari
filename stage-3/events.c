/* ---------- ID HEADER ----------
   Authors:     Andrew Boisvert, Kyle Scidmore
   Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
   File Name:   events.c
   Citations:   
     - TODO 


 Program Purposes:
   Data Structures: 
     - TODO

   Functions:
     - TODO  
*/

#include "model.c"
#include "model.h"
#include "types.h"

/* ---------- ASYNCHRONOUS (INPUT) EVENTS ---------- */

/* ---------- FUNCTION: TODO ----------

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
void set_play_on_fret_a(Model *model)
{
	char input;
	scanf("%c", input);

	if (input == 'a')
	{
		if (note_collision(&model))
		{
			update_score(&model);
			update_multiplier(&model);
			update_fail_bar(&model, 1);
		}
		else 
		{
			update_multiplier(&model);
			update_fail_bar(&model, -1);
			if (model->fail_bar.value == 0)
			{
				fail_song();
			}
		}
	}
}


/* ---------- FUNCTION: TODO ----------

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
void set_play_on_fret_s(Model *model)
{
	char input;
	scanf("%c", input);

	if (input == 's')
	{
		if (note_collision(&model))
		{
			update_score(&model);
			update_multiplier(&model);
			update_fail_bar(&model, 1);
		}
		else 
		{
			update_multiplier(&model);
			update_fail_bar(&model, -1);
			if (model->fail_bar.value == 0)
			{
				fail_song();
			}
		}
	}
}


/* ---------- FUNCTION: TODO ----------

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
void set_play_on_fret_d(Model *model)
{
	char input;
	scanf("%c", input);

	if (input == 'd')
	{
		if (note_collision(&model))
		{
			update_score(&model);
			update_multiplier(&model);
			update_fail_bar(&model, 1);
		}
		else 
		{
			update_multiplier(&model);
			update_fail_bar(&model, -1);
			if (model->fail_bar.value == 0)
			{
				fail_song();
			}
		}
	}
}


/* ---------- FUNCTION: TODO ----------

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
void set_play_on_fret_f(Model *model)
{
	char input;
	scanf("%c", input);

	if (input == 'f')
	{
		if (note_collision(&model))
		{
			update_score(&model);
			update_multiplier(&model);
			update_fail_bar(&model, 1);
		}
		else 
		{
			update_multiplier(&model);
			update_fail_bar(&model, -1);
			if (model->fail_bar.value == 0)
			{
				fail_song();
			}
		}
	}
}


/* ---------- FUNCTION: TODO ----------

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
void quit_game(Model *model)
{
	char input;
	scanf("%c", input);

	if (input == 'q')
	{
		return 0;
		/* need to replace later with proper call */
	}
}

/* ---------- SYNCHRONOUS (TIMED) EVENTS ---------- */

/* ---------- FUNCTION: TODO ----------

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
void move_note(Model *model)
{
	char input;
	scanf("%c", input);

	if (input == ' ') /* emulating clock tick for the time being */
	{
		set_note_pos(&model);
	}
}




/* ---------- CONDITION-BASED (CASCADED) EVENTS ---------- */


/* ---------- FUNCTION: TODO ----------

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
BOOL note_collision_a(Model *model)
{
	/* TODO */
}


/* ---------- FUNCTION: TODO ----------

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
BOOL note_collision_s(Model *model)
{
	/* TODO */
}


/* ---------- FUNCTION: TODO ----------

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
BOOL note_collision_d(Model *model)
{
	/* TODO */
}


/* ---------- FUNCTION: TODO ----------

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
BOOL note_collision_f(Model *model)
{
	/* TODO */
}


/* ---------- FUNCTION: TODO ----------

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
void fail_song()
{
	/* need to replace with return to splash screen or menu */
	return 0;
}
