#ifndef RENDERER_H
#define RENDERER_H

#include "types.h"
#include "model.h"


void render_fretboard(unsigned char *base);
void render_frets(unsigned long *base, Model *model);
void render_score(UINT32 *base, Model *model);
void render_multiplier(unsigned long *base, Model *model);
void render_failbar();

#endif