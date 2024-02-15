/* ---------- ID HEADER ----------
   Authors: 	Andrew Boisvert, Kyle Scidmore
   Emails: 		abois526@mtroyal.ca, kscid125@mtroyal.ca
   File Name:	model.h
   Citations:  
     - TODO


 Program Purposes:
   Data Structures: 
     - TODO

   Functions:
     - TODO  
*/

#include "types.h"

/* ---------- STRUCTURE DEFINITIONS ---------- */

/*
- type definition for a Fret structure
- pos_x, pos_y 		= position coordinates
- size_x, size_y 	= size of the object in px
*/
typedef struct 
{
    unsigned int pos_x, pos_y;    
    unsigned int size_x, size_y;
} Fret;

/*
- type definition for a Note structure
- pos_x, pos_y 		= position coordinates
- delta_y 			= velocity 
- size_x, size_y 	= size of the object in px
- isPlayed 			= played/not-played boolean state of the note
*/
typedef struct 
{
    unsigned int pos_x, pos_y;
    int delta_y;                
    int v_dir;                          
    unsigned int size_x;
	unsigned int size_y; 
	BOOL is_played;
} Note;

/*
- type definition for a Score structure
- pos_x, pos_y 					= position coordinates
- total_size_x, total_size_y 	= total size of the entirety of the object 
- digit_size_x, digit_size_y	= size of each individual digit 
- value 						= the value of the score for the game 
*/
typedef struct 
{
	unsigned int pos_x, pos_y;
	unsigned int total_size_x;
	unsigned int total_size_y;
	unsigned int digit_size_x;
	unsigned int digit_size_y;
	unsigned int value;
	NOTE_TYPE note_type;
} Score;



/*
- type definition for a Multiplier structure
- pos_x, pos_y 					= position coordinates
- total_size_x, total_size_y 	= total size of the entirety of the object 
- digit_size_x, digit_size_y	= size of the individual digit 
- value 						= the value of the score multiplier
*/
typedef struct 
{
	unsigned int pos_x, pos_y;
	unsigned int total_size_x;
	unsigned int total_size_y;
	unsigned int digit_size_x;
	unsigned int digit_size_y;
	unsigned int value;
} Multiplier;

/*
- type definition for a Fretboard structure
- pos_x, pos_y 		= position coordinates
- size_x, size_y	= size of the object in px
*/
typedef struct 
{
	unsigned int pos_x, pos_y;
	unsigned int size_x, size_y;
} Fretboard;

/*
- type definition for a Fail_Bar structure
- pos_x, pos_y 		= position coordinates
- size_x, size_y	= size of the object in px
- value 			= the value of the fail bar, starts at 50%
*/
typedef struct 
{
	unsigned int pos_x, pos_y;
	unsigned int size_x;
	unsigned int size_y;
	unsigned int value;
} Fail_Bar;


/* ---------- FUNCTION PROTOTYPES ---------- */

void init_fret(Fret *fret, unsigned int pos_x, unsigned int pos_y);


void init_note(Note *note, unsigned int pos_x, unsigned int pos_y,
               int delta_y, BOOL is_played);
void move_note(Note *note, unsigned int pos_y);
void set_note_is_played(Note *note, BOOL is_played);


void init_score(Score *score, unsigned int pos_x, unsigned int pos_y,
                unsigned int value, NOTE_TYPE note_type);
void update_score(Score *score, unsigned int value, NOTE_TYPE note_type);


void init_multiplier(Multiplier *multiplier, unsigned int pos_x,
                     unsigned int pos_y, unsigned int value);
void update_multiplier(Multiplier *multiplier, unsigned int value);

void init_fretboard(Fretboard *fretboard, unsigned int pos_x,
                    unsigned int pos_y, unsigned int size_x,
					unsigned int size_y);


void init_fail_bar(Fail_Bar *fail_bar, unsigned int pos_x,
				   unsigned int pos_y, unsigned int value);
void update_fail_bar(Fail_Bar *fail_bar, unsigned int value);