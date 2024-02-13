#include "types.h"

typedef struct 
{
    const unsigned int pos_x, pos_y;    
    const unsigned int size_x, size_y = 32;
} Fret;

typedef struct 
{
    unsigned int pos_x, pos_y;
    int delta_y;                
    int v_dir;                          
    const unsigned int size_x, size_y = 32; 
} Note;

typedef struct 
{

} Score;

typedef struct 
{

} Multiplier;

typedef struct 
{

} Fretboard;

typedef struct 
{

} Fail_Bar;
