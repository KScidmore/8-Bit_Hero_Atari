#ifndef RENDERER_H
#define RENDERER_H

#include "raster.h"
#include "model.h"
#include "bitmaps.h"
#include "types.h"

void render_fretboard(UINT8 *base);
void render_frets(UINT32 *base);
void render_score(UINT32 *base);
void render_multiplier(UINT32 *base);
void render_failbar();

#endif