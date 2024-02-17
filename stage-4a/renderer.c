#include <osbind.h>
#include "types.h"
#include "renderer.h"
#include "model.h"
#include "RASTER.H"

void render_frets(unsigned long *base, Model *model)
{  

    plot_bitmap_32(base, model->frets[FRET_A].pos_x, model->frets[FRET_A].pos_y, a_map, model->frets[FRET_A].size_y);
    plot_bitmap_32(base, model->frets[FRET_S].pos_x, model->frets[FRET_S].pos_y, s_map, model->frets[FRET_S].size_y);
    plot_bitmap_32(base, model->frets[FRET_D].pos_x, model->frets[FRET_D].pos_y, d_map, model->frets[FRET_D].size_y);
    plot_bitmap_32(base, model->frets[FRET_F].pos_x, model->frets[FRET_F].pos_y, f_map, model->frets[FRET_F].size_y);

}


void render_fretboard(unsigned char *base)
{
    int i;
    int start_y = 108;
    int start_x = 173;

    for(i=0, i < 8, i++){

        plot_h_line(base, 173, 468, start_y);
        
        start_y += 1;

        i++

    }

    for(i = 0, i < 8, i++);
    {
        vertical_line(base, start_x, 116, 217)

        start_x += 1;

        i++

    }

    start_x += 88;

    for(i = 0, i < 8, i++);
    {
        vertical_line(base, start_x, 116, 217)

        start_x += 1;

        i++

    }

     start_x += 88;

    for(i = 0, i < 8, i++);
    {
        vertical_line(base, start_x, 116, 217)

        start_x += 1;

        i++

    }

     start_x += 88;

    for(i = 0, i < 8, i++);
    {
        vertical_line(base, start_x, 116, 217)

        start_x += 1;

        i++

    }


}

/*void render_score(UINT32 *base, Model *model)
{

}*/


void render_multiplier(unsigned long *base, Model *model)
{
    plot_bitmap_32(base, model->multiplier.pos_x, model->multiplier.pos_y, x_map, model->multiplier.digit_size_y);

    plot_bitmap_32(base, model->multiplier.pos_x + 32, model->multiplier.pos_y, one_map, model->multiplier.digit_size_y);

    /* TODO: add if statment for different bitmaps based on multiplier value*/

}


void render_failbar()
{
    /* Make fail bar bitmap and add functionality*/
}