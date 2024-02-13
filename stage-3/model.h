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
*/
typedef enum
{
	false = 0,
	true = 1
} bool;

/*
- type definition for a Fret object
- pos_x, pos_y 		= position coordinates
- size_x, size_y 	= size of the object in px
*/
typedef struct 
{
    const unsigned int pos_x, pos_y;    
    const unsigned int size_x, size_y = 32;
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
    const unsigned int pos_x, pos_y;
    int delta_y;                
    int v_dir;                          
    const unsigned int size_x, size_y = 32; 
	bool isPlayed = false;
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
	const unsigned int pos_x, pos_y;
	const unsigned int total_size_x = 128;
	const unsigned int total_size_y = 32;
	const unsigned int digit_size_x = 32;
	const unsigned int digit_size_x = 32;
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
	const unsigned int pos_x, pos_y;
	const unsigned int total_size_x = 64;
	const unsigned int total_size_y = 32;
	const unsigned int digit_size_x = 32;
	const unsigned int digit_size_x = 32;
	unsigned int value;
} Multiplier;

/*
- type definition for a Fretboard object
- pos_x, pos_y 		= position coordinates
- size_x, size_y	= size of the object in px
*/
typedef struct 
{
	const unsigned int pos_x, pos_y;
	const unsigned int size_x, size_y;
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
