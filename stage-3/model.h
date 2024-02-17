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
- type definition for a Model structure
- 
*/
typedef struct 
{
	Fret frets[FRETS_SIZE]; /* frets A, S, D, and F */
	Note note;
	Note_Streak note_streak;
	Score score;
	Multiplier multiplier;
	Fretboard fretboard;
	Fail_Bar fail_bar;	
} Model;

/*
- type definition for a Fret structure
- pos_x, pos_y 		= position coordinates
- size_x, size_y 	= size of the object in px
*/
typedef struct 
{
    UINT16 pos_x, pos_y;    
    UINT8 size_x, size_y;
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
    UINT16 pos_x, pos_y;
    int delta_y;                
    int v_dir;                          
    UINT8 size_x, size_y; 
	BOOL is_played;
	NOTE_TYPE note_type;
} Note;

typedef struct 
{
	UINT16 pos_x, pos_y; 
	UINT16 total_size_x, total_size_y, digit_size_x, digit_size_y;
	UINT16 value;
} Note_Streak;

/*
- type definition for a Score structure
- pos_x, pos_y 					= position coordinates
- total_size_x, total_size_y 	= total size of the entirety of the object 
- digit_size_x, digit_size_y	= size of each individual digit 
- value 						= the value of the score for the game 
- NOTE_TYPE 					= type of note (SHORT_NOTE, CHORD, LONG_NOTE)
*/
typedef struct 
{
	UINT16 pos_x, pos_y;
	UINT8 total_size_x, total_size_y, digit_size_x, digit_size_y;
	UINT16 value;
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
	UINT16 pos_x, pos_y;
	UINT8 total_size_x, total_size_y, digit_size_x, digit_size_y;
	UINT16 value;
} Multiplier;

/*
- type definition for a Fretboard structure
- pos_x, pos_y 		= position coordinates
- size_x, size_y	= size of the object in px
*/
typedef struct 
{
	UINT16 pos_x, pos_y;
	UINT16 size_x, size_y;
} Fretboard;


/*
- type definition for a Fail_Bar structure
- pos_x, pos_y 		= position coordinates
- size_x, size_y	= size of the object in px
- value 			= the value of the fail bar, starts at 50%
*/
typedef struct 
{
	UINT16 pos_x, pos_y;
	UINT16 size_x, size_y;
	UINT8 value;
} Fail_Bar;



/* ---------- FUNCTION PROTOTYPES ---------- */

void init_model(Model *model);

void init_fret(Model *model, FRET_POS fret_pos, UINT16 pos_x, UINT16 pos_y);

void init_note(Model *model, UINT16 pos_x, UINT16 pos_y, int delta_y, NOTE_TYPE note_type);
void set_note_pos(Model *model);
void set_note_is_played(Model *model, BOOL is_played);
void generate_note(Model *model);

void init_note_streak(Model *model);
void update_note_streak(Model *model);

void init_score(Model *model, UINT16 pos_x, UINT16 pos_y, UINT16 value);
void update_score(Model *model);


void init_multiplier(Model *model, UINT16 pos_x, UINT16 pos_y, UINT16 value);
void update_multiplier(Model *model);

void init_fretboard(Model *model);


void init_fail_bar(Model *model, UINT16 pos_x, UINT16 pos_y, UINT16 value);
void update_fail_bar(Model *model, UINT16 value);