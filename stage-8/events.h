/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   events.h
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

#ifndef EVENTS_H
#define EVENTS_H

#include "model.h"
#include "types.h"

/*---------- Asynchronous (Input) Events ------------------------------------*/
void set_play_on_fret_a(Model *model, UINT8 index, UINT32 *base);
void set_play_on_fret_s(Model *model, UINT8 index, UINT32 *base);
void set_play_on_fret_d(Model *model, UINT8 index, UINT32 *base);
void set_play_on_fret_f(Model *model, UINT8 index, UINT32 *base);
void quit_game(Model *model);

/*----------Synchronous (Timed) Events --------------------------------------*/
void move_note(Model *model, FRET_POS fret, UINT8 index);

/*---------- Condition-Based (Cascaded) Events ------------------------------*/
BOOL note_collision_a(Model *model, UINT8 index, UINT32 *base);
BOOL note_collision_s(Model *model, UINT8 index, UINT32 *base);
BOOL note_collision_d(Model *model, UINT8 index, UINT32 *base);
BOOL note_collision_f(Model *model, UINT8 index, UINT32 *base);

void fail_song();

#endif 