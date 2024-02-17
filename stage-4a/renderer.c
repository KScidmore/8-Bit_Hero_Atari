#include <osbind.h>
#include "types.h"
#include "renderer.h"

void render_frets(UINT32 *base, Fret a_fret, Fret s_fret, d_fret, Fret f_fret)
{  
    a.pos_x = 64;
    a.pos_y = 300;
    

    s.pos_x = 0;
    s.pos_y = 0;
    

    d.pos_x = 0;
    d.pos_y = 0;
    d.size_y = 32;

    f.pos_x = 0;
    f.pos_y = 0;
    f.size_y = 32;

    plot_bitmap_32(base, a.pos_x, a.pos_y, a_map, a.size_y);
    plot_bitmap_32(base, s.pos_x, s.pos_y, a_map, s.size_y);
    plot_bitmap_32(base, d.pos_x, d.pos_y, a_map, d.size_y);
    plot_bitmap_32(base, f.pos_x, f.pos_y, a_map, f.size_y);

}


void render_fretboard(UINT8 *base)
{
    plot_h_line();
    plot_h_line();
    plot_h_line();
    plot_h_line();
    vertical_line();
    vertical_line();



}

void render_score(UINT32 *base)
{

}



