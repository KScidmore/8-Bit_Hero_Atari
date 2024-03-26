#ifndef RENDERER_H
#define RENDERER_H

#include "types.h"
#include "model.h"


void render_fretboard(UINT8 *base);
void render_frets(UINT32 *base, Model *model);
void render_score(UINT32 *base, Model *model);
void render_multiplier(UINT32 *base, Model *model);
void render_failbar(UINT32 *base, Model *model);
void render_x(UINT32 *base, Model *model);
void render_start_score(UINT32 *base, Model *model);
void render_start_multiplier(UINT32 *base, Model *model);
void init_scene(UINT8 *base, UINT32 *base_long, Model *model);
void render_next(UINT32 *base, Model *model);
void render_new_note(UINT32 *base, Model *model, UINT8 fret, UINT8 note_index);
void render_active_notes(UINT32 *base, Model *model);
void clear_bottom(UINT32 *base, Model *model);

#endif