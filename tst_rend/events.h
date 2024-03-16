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
void set_play_on_fret_a(Model *model);
void set_play_on_fret_s(Model *model);
void set_play_on_fret_d(Model *model);
void set_play_on_fret_f(Model *model);
void quit_game(Model *model);

/*----------Synchronous (Timed) Events --------------------------------------*/
void move_note(Model *model);

/*---------- Condition-Based (Cascaded) Events ------------------------------*/
BOOL note_collision_a(Model *model);
BOOL note_collision_s(Model *model);
BOOL note_collision_d(Model *model);
BOOL note_collision_f(Model *model);

void fail_song();

#endif 