#ifndef GLOBALS_H
#define GLOBALS_H

#include "types.h"
/*#include "model.h"*/
#include "ikbd.h"

/*extern Model model;*/
extern short render_request;
extern BOOL game_on;
extern BOOL music_on;
extern UINT32 *curr_buffer;
extern long old_ssp;
extern BOOL stop_gen;
extern BOOL shift_held;
extern BOOL caps_on;

#endif