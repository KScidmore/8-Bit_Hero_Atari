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
void init_fret(Fret *fret, unsigned int pos_x, unsigned int pos_y)
{
    /*TODO*/
    fret->pos_x = pos_x;
    fret->pos_y = pos_y;
    fret->size_x = 32;
    fret->size_y = 32;
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
void init_note(Note *note, unsigned int pos_x, unsigned int pos_y,
               int delta_y, BOOL is_played)
{
    note->pos_x = pos_x;
    note->pos_y = pos_y;
    note->delta_y = delta_y;
    note->v_dir = 1;            /* constant */
    note->size_x = 32;          /* constant */
    note->size_y = 32;          /* constant */
    note->is_played = FALSE;
}


/* ---------- FUNCTION: move_note ----------

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
void move_note(Note *note, unsigned int pos_y)
{
	note->pos_y = pos_y;
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
void set_note_is_played(Note *note, BOOL is_played)
{
	note->is_played = is_played;
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
void init_score(Score *score, unsigned int pos_x, unsigned int pos_y,
                unsigned int value, NOTE_TYPE note_type)
{
    score->pos_x = pos_x;
    score->pos_y = pos_y;
    score->total_size_x = 128;
    score->total_size_y = 32;
    score->digit_size_x = 32;
    score->digit_size_y = 32;
    score->value = value;
	score->note_type = note_type;
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
void update_score(Score *score, unsigned int value, NOTE_TYPE note_type)
{
		score->value += note_type;
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
void init_multiplier(Multiplier *multiplier, unsigned int pos_x,
                     unsigned int pos_y, unsigned int value)
{
    multiplier->pos_x = pos_x;
    multiplier->pos_y = pos_y;
    multiplier->total_size_x = 64;
    multiplier->total_size_y = 32;
    multiplier->digit_size_x = 32;
    multiplier->digit_size_y = 32;
    multiplier->value = value;
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
void update_multiplier(Multiplier *multiplier, unsigned int value)
{
	multiplier->value = value;
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
void init_fretboard(Fretboard *fretboard, unsigned int pos_x,
                    unsigned int pos_y, unsigned int size_x,
                    unsigned int size_y)
{
    fretboard->pos_x = pos_x;
    fretboard->pos_y = pos_y;
    fretboard->size_x = size_x;
    fretboard->size_y = size_y;
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
void init_fail_bar(Fail_Bar *fail_bar, unsigned int pos_x,
				   unsigned int pos_y, unsigned int value)
{
    fail_bar->pos_x = pos_x; 
    fail_bar->pos_y = pos_y; 
    fail_bar->size_x = 136; 
    fail_bar->size_y = 16; 
    fail_bar->value = 50;
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
void update_fail_bar(Fail_Bar *fail_bar, unsigned int value)
{
	fail_bar->value = value;
}