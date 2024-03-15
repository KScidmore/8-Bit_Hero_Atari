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
void initalize_scene(UINT8 *base, UINT32 *base_long, Model *model);

#endif