/*
 ID Header:
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

/*
- should later try to consolidate this and other typedefs into a file 
NOTE: This will actually make 0 = false and !0 = true. Any -ve or +ve number
that is not 0 will represent a non-zero truth value.
- tried to make it as an enum but it was causing some trouble 
*/
#define bool int
#define TRUE 1
#define FALSE 0 

/*
- type definition for a Fret object
- pos_x, pos_y 		= position coordinates
- size_x, size_y 	= size of the object in px
*/
typedef struct 
{
    unsigned int pos_x, pos_y;    
    unsigned int size_x, size_y;
} Fret;

/*
- type definition for a Note object
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
	bool is_played;
} Note;

/*
- type definition for a Score object
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
} Score;



/*
- type definition for a Multiplier object
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
- type definition for a Fretboard object
- pos_x, pos_y 		= position coordinates
- size_x, size_y	= size of the object in px
*/
typedef struct 
{
	unsigned int pos_x, pos_y;
	unsigned int size_x, size_y;
} Fretboard;

/*
- type definition for a Fail_Bar object
- pos_x, pos_y 		= position coordinates
- size_x, size_y	= size of the object in px
- value 			= the value of the fail bar, starts at 50%
*/
typedef struct 
{
	const unsigned int pos_x, pos_y;
	const unsigned int size_x = 136;
	const unsigned int size_y = 16;
	unsigned int value = 50;
} Fail_Bar;


void init_fret(Fret *fret, unsigned int pos_x, unsigned int pos_y);
void init_note(Note *note, unsigned int pos_x, unsigned int pos_y,
               int delta_y, bool is_played);
void init_score(Score *score, unsigned int pos_x, unsigned int pos_y,
                unsigned int value);
void init_multiplier(Multiplier *multiplier, unsigned int pos_x,
                     unsigned int pos_y, unsigned int value);
void init_fretboard(Fretboard *fretboard, unsigned int pos_x,
                    unsigned int pos_y);
