/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   types.h
/  Citations:   
/    N/A
/
/  Purpose:
/    To provide better code legibility, regularly used custom
/    data types and magic numbers will be defined in this file.
/--------------------------------------------------------*/

#ifndef TYPES_H
#define TYPES_H

/*---------- DATA TYPE DEFINITIONS ------------------------------------------*/
/* boolean data type; tried to make as an enum but was having some trouble */
#define BOOL int
#define TRUE 1
#define FALSE 0 

/* unsigned integer 8/16/32 bits */
typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;

/* note types for scoring */
#define NOTE_TYPE UINT8
#define SHORT_NOTE 1
#define CHORD 2
#define LONG_NOTE 3

/* fret positions for readability */
#define FRET_POS UINT8
#define FRET_A 0 
#define FRET_S 1
#define FRET_D 2
#define FRET_F 3

/* numerical positions for readability */
#define DIGIT_POS UINT8
#define THOUSANDS 0 
#define HUNDREDS 1 
#define TENS 2 
#define ONES 3


/*---------- MISC MAGIC NUMBER DEFINITIONS ----------------------------------*/
/* screen dimensions */
#define SCREEN_WIDTH 640 
#define SCREEN_HEIGHT 400

/* for array sizing */
#define FRETS_SIZE 4
#define NOTES_SIZE 100


#endif