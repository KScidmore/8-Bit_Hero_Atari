#include <osbind.h>
#include "types.h"
#include "renderer.h"
#include "model.h"
#include "RASTER.H"
#include "bitmaps.h"

/*---------- FUNCTION: TODO -------------------------------
/  PURPOSE:
/    TODO - purpose, from the caller's perspective (if not
/    perfectly clear from the name)
/ 
/  CALLER INPUT:
/    TODO - the purpose of each input parameter (if not 
/    perfectly clear from the name)
/ 
/  CALLER OUTPUT:
/    TODO - the purose of each output parameter and return 
/    value (if not perfectly clear from the name)
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/    TODO
/--------------------------------------------------------*/
void render_frets(UINT32 *base, Model *model)
{  

    plot_bitmap_32(base, model->frets[FRET_A].pos_x, model->frets[FRET_A].pos_y, a_map, model->frets[FRET_A].size_y);
    plot_bitmap_32(base, model->frets[FRET_S].pos_x, model->frets[FRET_S].pos_y, s_map, model->frets[FRET_S].size_y);
    plot_bitmap_32(base, model->frets[FRET_D].pos_x, model->frets[FRET_D].pos_y, d_map, model->frets[FRET_D].size_y);
    plot_bitmap_32(base, model->frets[FRET_F].pos_x, model->frets[FRET_F].pos_y, f_map, model->frets[FRET_F].size_y);

}

/*---------- FUNCTION: TODO -------------------------------
/  PURPOSE:
/    TODO - purpose, from the caller's perspective (if not
/    perfectly clear from the name)
/ 
/  CALLER INPUT:
/    TODO - the purpose of each input parameter (if not 
/    perfectly clear from the name)
/ 
/  CALLER OUTPUT:
/    TODO - the purose of each output parameter and return 
/    value (if not perfectly clear from the name)
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/    TODO
/--------------------------------------------------------*/
void render_fretboard(UINT8 *base)
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

/*---------- FUNCTION: TODO -------------------------------
/  PURPOSE:
/    TODO - purpose, from the caller's perspective (if not
/    perfectly clear from the name)
/ 
/  CALLER INPUT:
/    TODO - the purpose of each input parameter (if not 
/    perfectly clear from the name)
/ 
/  CALLER OUTPUT:
/    TODO - the purose of each output parameter and return 
/    value (if not perfectly clear from the name)
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/    TODO
/--------------------------------------------------------*/
void render_score(UINT32 *base, Model *model)
{

}

/*---------- FUNCTION: TODO -------------------------------
/  PURPOSE:
/    TODO - purpose, from the caller's perspective (if not
/    perfectly clear from the name)
/ 
/  CALLER INPUT:
/    TODO - the purpose of each input parameter (if not 
/    perfectly clear from the name)
/ 
/  CALLER OUTPUT:
/    TODO - the purose of each output parameter and return 
/    value (if not perfectly clear from the name)
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/    TODO
/--------------------------------------------------------*/
void render_x(UINT32 *base, Model *model){
    
    plot_bitmap_32(base, model->multiplier.pos_x, model->multiplier.pos_y, x_map, model->multiplier.digit_size_y);

}

/*---------- FUNCTION: TODO -------------------------------
/  PURPOSE:
/    TODO - purpose, from the caller's perspective (if not
/    perfectly clear from the name)
/ 
/  CALLER INPUT:
/    TODO - the purpose of each input parameter (if not 
/    perfectly clear from the name)
/ 
/  CALLER OUTPUT:
/    TODO - the purose of each output parameter and return 
/    value (if not perfectly clear from the name)
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/    TODO
/--------------------------------------------------------*/
void render_multiplier(UINT32 *base, Model *model)
{
    int pos_x = model->multiplier.pos_x + 32;
    int pos_y = model->multiplier.pos_y;
    int height = model->multiplier.digit_size_y;

    if(model->multiplier.value == 1){

        plot_bitmap_32(base, pos_x, pos_y, one_map, height);

    }
    else if(model->multiplier.value == 2){

        plot_bitmap_32(base, pos_x, pos_y, two_map, height);

    }
    else if(model->multiplier.value == 4){

        plot_bitmap_32(base, pos_x, pos_y, four_map, height);

    }
    else {

        plot_bitmap_32(base, pos_x, pos_y, eight_map, height);

    }

}

/*---------- FUNCTION: TODO -------------------------------
/  PURPOSE:
/    TODO - purpose, from the caller's perspective (if not
/    perfectly clear from the name)
/ 
/  CALLER INPUT:
/    TODO - the purpose of each input parameter (if not 
/    perfectly clear from the name)
/ 
/  CALLER OUTPUT:
/    TODO - the purose of each output parameter and return 
/    value (if not perfectly clear from the name)
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/    TODO
/--------------------------------------------------------*/
void render_failbar(UINT32 *base, Model *model)
{
    int pos_y, sec_one, sec_two, sec_three, sec_four, sec_five, sec_six, height;
    
    pos_y = model->fail_bar.pos_y;
    height = model->fail_bar.size_y
    sec_one = model->fail_bar.pos_x;
    sec_two = model->fail_bar.pos_x + 32;
    sec_three = model->fail_bar.pos_x + 64;
    sec_four = model->fail_bar.pos_x + 96;
    sec_five = model->fail_bar.pos_x + 128;
    sec_six = model->fail_bar.pos_x + 160;

    if(model->fail_bar.value == 0 ){

        plot_bitmap_32(base, sec_one, pos_y, LEE_fail, height);
        plot_bitmap_32(base, sec_two, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_three, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_four, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_five, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_six, pos_y, REE_fail, height);
    }
    else if(model->fail_bar.value == 20 ){

        plot_bitmap_32(base, sec_one, pos_y, LEF_fail, height);
        plot_bitmap_32(base, sec_two, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_three, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_four, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_five, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_six, pos_y, REE_fail, height);

    }
    else if(model->fail_bar.value == 40 ){

        plot_bitmap_32(base, sec_one, pos_y, LEF_fail, height);
        plot_bitmap_32(base, sec_two, pos_y, MF_fail, height);
        plot_bitmap_32(base, sec_three, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_four, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_five, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_six, pos_y, REE_fail, height);

    }
    else if(model->fail_bar.value == 60 ){

        plot_bitmap_32(base, sec_one, pos_y, LEF_fail, height);
        plot_bitmap_32(base, sec_two, pos_y, MF_fail, height);
        plot_bitmap_32(base, sec_three, pos_y, MF_fail, height);
        plot_bitmap_32(base, sec_four, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_five, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_six, pos_y, REE_fail, height);

    }
    else if(model->fail_bar.value == 80 ){

        plot_bitmap_32(base, sec_one, pos_y, LEF_fail, height);
        plot_bitmap_32(base, sec_two, pos_y, MF_fail, height);
        plot_bitmap_32(base, sec_three, pos_y, MF_fail, height);
        plot_bitmap_32(base, sec_four, pos_y, MF_fail, height);
        plot_bitmap_32(base, sec_five, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_six, pos_y, REE_fail, height);

    }
    else if(model->fail_bar.value == 100 ){

        plot_bitmap_32(base, sec_one, pos_y, LEF_fail, height);
        plot_bitmap_32(base, sec_two, pos_y, MF_fail, height);
        plot_bitmap_32(base, sec_three, pos_y, MF_fail, height);
        plot_bitmap_32(base, sec_four, pos_y, MF_fail, height);
        plot_bitmap_32(base, sec_five, pos_y, MF_fail, height);
        plot_bitmap_32(base, sec_six, pos_y, REE_fail, height);

    }
    else{

        plot_bitmap_32(base, sec_one, pos_y, LEF_fail, height);
        plot_bitmap_32(base, sec_two, pos_y, MF_fail, height);
        plot_bitmap_32(base, sec_three, pos_y, MF_fail, height);
        plot_bitmap_32(base, sec_four, pos_y, MF_fail, height);
        plot_bitmap_32(base, sec_five, pos_y, MF_fail, height);
        plot_bitmap_32(base, sec_six, pos_y, REF_fail, height);

    }
}