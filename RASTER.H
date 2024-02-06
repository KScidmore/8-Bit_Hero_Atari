#ifndef RASTER_H
#define RASTER_H

#include "types.h"

void plot_pixel(UINT8 *base, int x, int y);
void plot_hline(UINT8 *base, int x1, int x2, int y);
void plot_genline(UINT8 *base, int x0, int y0, int x1, int y1);
void plot_line_low(UINT8 *base, int x0, int y0, int x1, int y1);
void plot_line_high(UINT8 *base, int x0, int y0, int x1, int y1);
int abs_val(int value);
void plot_diamond(UINT8 *base, int cx, int cy, int r);
void test_plot_pixel(UINT8 *base);
void test_plot_hline(UINT8 *base);
void test_plot_genline(UINT8 *base);

#endif
