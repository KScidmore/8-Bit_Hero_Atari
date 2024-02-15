/*
NOTE:
- different from "types.h" provided in stage 2
- adding defines and typedefs in here to consolidate them going forward 
*/

#ifndef TYPES_H
#define TYPES_H

/* DATA TYPE DEFINITIONS */
/* bool type
- tried to make as an enum but was having some trouble with it */
#define bool int
#define TRUE 1
#define FALSE 0 

typedef unsigned char UINT8;
typedef unsigned int  UINT16;
typedef unsigned long UINT32;


/* DEFINING MAGIC NUMBERS */
#define SCREEN_WIDTH 640 
#define SCREEN_HEIGHT 400


#endif