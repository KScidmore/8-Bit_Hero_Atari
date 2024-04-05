/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   model.h
/  Citations:   
/    - TODO 
/
/
/  Program Purposes:
/    Data Structures: 
/      - TODO
/
/    Functions:
/      - TODO  
/--------------------------------------------------------*/
#ifndef MODEL_H
#define MODEL_H

#include "types.h"

/*---------- STRUCTURE DEFINITIONS ------------------------------------------*/

/*---------- STRUCTURE: Fret ------------------------------
/  INFO:
/    TODO - general explanation 
/  
/  ATTRIBUTES:
/    pos_x			= x-val for position coordinate
/    pos_y			= y-val for position coordinate
/    size_x			= x-val for size of the object in px
/    size_y			= y-val for size of the object in px
/    is_depressed	= Boolean state for if fret is currently
/                     being depressed (0=F / 1=T)
/--------------------------------------------------------*/
typedef struct 
{
    UINT16 pos_x, pos_y;    
    UINT8 size_x, size_y;
	BOOL is_depressed;
} Fret; 


/*---------- STRUCTURE: Note ------------------------------
/  INFO:
/    TODO - general explanation 
/  
/  ATTRIBUTES:
/    pos_x			= x-val for position coordinate
/    pos_y			= y-val for position coordinate
/    delta_y 		= velocity 
/    size_x			= x-val for size of the object in px
/    size_y			= y-val for size of the object in px
/    isPlayed 		= Boolean state for if note has been
/                     played (0=F / 1=T)
/--------------------------------------------------------*/
typedef struct 
{
    UINT16 pos_x, pos_y;
    int delta_y;                
    int v_dir;                          
    UINT8 size_x, size_y; 
	BOOL is_played;
	BOOL is_active;
	NOTE_TYPE note_type;
} Note;

/*---------- STRUCTURE: Lane ------------------------------
/  INFO:
/    TODO - general explanation 
/  
/  ATTRIBUTES:
/    TODO
/--------------------------------------------------------*/
typedef struct 
{
    UINT16 start_x, curr_x, start_y, end_y;
	UINT8 counter;
	Note notes[NOTES_SIZE];
} Lane;

/*---------- STRUCTURE: Score -----------------------------
/  INFO:
/    TODO - general explanation 
/  
/  ATTRIBUTES:
/    TODO
/--------------------------------------------------------*/
typedef struct 
{
	UINT16  ones_x, tens_x, hunds_x, thous_x, pos_y;
	UINT8 size_x, size_y;
	UINT16 value, prev_ones, prev_tens, prev_hunds, prev_thous;
	BOOL updated_flag;
} Score;


/*---------- STRUCTURE: Multiplier ------------------------
/  INFO:
/    TODO - general explanation 
/  
/  ATTRIBUTES:
/    pos_x				= x-val for position coordinate
/    pos_y				= y-val for position coordinate
/    total_size_x		= x-val for total object size
/    total_size_y		= y-val for total object size
/    digit_size_x		= x-val for digit size
/    digit_size_y		= y-val for digit size
/    value				= the value of the score for the game
/--------------------------------------------------------*/
typedef struct 
{
	UINT16 pos_x, pos_y;
	UINT8 total_size_x, total_size_y, digit_size_x, digit_size_y;
	UINT16 value, prev_value;
} Multiplier;


/*---------- STRUCTURE: Fail_Bar --------------------------
/  INFO:
/    TODO - general explanation 
/  
/  ATTRIBUTES:
/    pos_x		= x-val for position coordinate
/    pos_y		= y-val for position coordinate
/    size_x		= x-val for size of the object in px
/    size_y		= y-val for size of the object in px
/    value 		= the value of the bail bar (starts @ 50%)
/--------------------------------------------------------*/
typedef struct 
{
	UINT16 pos_x, pos_y;
	UINT16 size_x, size_y;
	UINT8 value;
} Fail_Bar;

/*---------- STRUCTURE: Model ------------------------------
/  INFO:
/    TODO - general explanation 
/  
/  ATTRIBUTES:
/    TODO - what sort of attributes does this structure 
/    have that isn't immediately apparent
/--------------------------------------------------------*/
typedef struct 
{
	Fret frets[FRETS_SIZE]; /* frets A, S, D, and F */
	Lane lanes[LANES_SIZE]; /* lanes for the 4 frets */
	Note_Streak note_streak;
	Score score;
	Multiplier multiplier;
	Fretboard fretboard;
	Fail_Bar fail_bar;	
} Model;



/*---------- FUNCTION PROTOTYPES --------------------------------------------*/
/* Model Functions */
void init_model(Model *model);

/* Fret Functions */
void init_fret(Model *model, FRET_POS fret_pos, UINT16 pos_x, UINT16 pos_y);
void set_fret_depressed(Model *model, FRET_POS fret, BOOL is_depressed);

/* Note Functions */
void init_note(Note *note, FRET_POS fret, UINT8 index, UINT16 pos_x, UINT16 pos_y, int delta_y, NOTE_TYPE note_type);
void set_note_pos(Model *model, FRET_POS fret, UINT8 index);
void set_note_is_played(Model *model, FRET_POS fret, UINT8 index, BOOL is_played);

/* Lane Functions */
void init_lane(Model *model, FRET_POS fret, UINT8 index, UINT16 pos_x, UINT16 pos_y, int delta_y, 
				NOTE_TYPE note_type);

/* Note Streak Functions */
void update_note_streak(Model *model, BOOL miss);

/* Score Functions */
void init_score(Model *model, UINT16 pos_x, UINT16 pos_y, UINT16 value);
void update_score(Model *model);

/* Multiplier Functions */
void init_multiplier(Model *model, UINT16 pos_x, UINT16 pos_y, UINT16 value);
void update_multiplier(Model *model);

/* Failbar Functions */
void init_fail_bar(Model *model, UINT16 pos_x, UINT16 pos_y, UINT16 value);
void update_fail_bar(Model *model, UINT16 value);


#endif 