#include <osbind.h>
#include "types.h"
#include "renderer.h"
#include "model.h"
#include "RASTER.H"
#include "bitmaps.h"
#include "RAST_ASM.h"

/*figure out something with this global so paul doesnt kill you*/
const UINT32 *num_maps[] = {zero_map, one_map, two_map, three_map, four_map, five_map, six_map, seven_map, eight_map, nine_map};

/*---------- FUNCTION: init_scene ----------------------
/  PURPOSE:
/  	Renders the initial game scene
/  
/  CALLER INPUT:
/    UINT8 *base
/  	- Starting point of the frame buffer (8bit)
/    UINT32 *base
/  	- Starting point of the frame buffer (32bit)
/    Model *model
/  	- Address of the game model
/  
/  CALLER OUTPUT:
/    Returns Void
/  
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/   
/--------------------------------------------------------*/
void init_scene(UINT8 *base, UINT32 *base32, Model *model){

    clear_screen(base);
    render_frets(base32, model);
    render_fretboard(base);
    render_start_score(base32, model);
    render_x(base32, model);
    render_start_multiplier(base32, model);
    render_failbar(base32, model);

}

/*---------- FUNCTION: render_next ---------------------
/  PURPOSE:
/ 	Renders the next frame
/ 
/  CALLER INPUT:
/   UINT32 *base
/ 	- Starting point of the frame buffer
/   Model *model
/   - Address of the game model
/
/  CALLER OUTPUT:
/   Returns Void
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/  
/--------------------------------------------------------*/
void render_next(UINT32 *base, Model *model, UINT8 fret, UINT8 note_index){

    render_frets(base, model);
    render_active_notes(base, model);
    render_new_note(base, model, fret, note_index);
    render_score(base, model);
    render_multiplier(base, model);
    render_failbar(base, model);

}

/*---------- FUNCTION: render_new_note ------------------
/  PURPOSE:
/  	Renders a new note and activates it
/  
/  CALLER INPUT:
/    UINT32 *base
/  	- Starting point of the frame buffer
/    Model *model
/  	- Address of the game model
/  
/  CALLER OUTPUT:
/    Returns Void
/  
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/   
/--------------------------------------------------------*/
void render_new_note(UINT32 *base, Model *model, UINT8 fret, UINT8 note_index){

    model->lanes[fret].notes[note_index].is_active = TRUE;

    plot_bitmap_32(base, model->lanes[fret].notes[note_index].pos_x, model->lanes[fret].notes[note_index].pos_y, note_map, model->lanes[fret].notes[note_index].size_y);

}


/*---------- FUNCTION: render_active_notes ---------------
/  PURPOSE:
/ 	de-renders and re-renders all active notes
/ 
/  CALLER INPUT:
/   UINT32 *base
/ 	- Starting point of the frame buffer
/   Model *model
/   - Address of the game model
/
/  CALLER OUTPUT:
/   Returns Void
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/  
/--------------------------------------------------------*/
void render_active_notes(UINT32 *base, Model *model){


    int i, size;

    size = 50;

    for(i = 0; i < size; i++){

        /*iterate through note array, for active notes update position and render*/
    
        if(model->lanes[FRET_A].notes[i].is_active == TRUE){

            set_note_pos(model, FRET_A, i);
            plot_bitmap_32(base, model->lanes[FRET_A].notes[i].pos_x, model->lanes[FRET_A].notes[i].pos_y, note_map, model->lanes[FRET_A].notes[i].size_y);
        }

        if(model->lanes[FRET_S].notes[i].is_active == TRUE){

            set_note_pos(model, FRET_S, i);
            plot_bitmap_32(base, model->lanes[FRET_S].notes[i].pos_x, model->lanes[FRET_S].notes[i].pos_y, note_map, model->lanes[FRET_S].notes[i].size_y);
        }

        if(model->lanes[FRET_D].notes[i].is_active == TRUE){

            set_note_pos(model, FRET_D, i);
            plot_bitmap_32(base, model->lanes[FRET_D].notes[i].pos_x, model->lanes[FRET_D].notes[i].pos_y, note_map, model->lanes[FRET_D].notes[i].size_y);
        }

        if(model->lanes[FRET_F].notes[i].is_active == TRUE){

            set_note_pos(model, FRET_D, i);
            plot_bitmap_32(base, model->lanes[FRET_F].notes[i].pos_x, model->lanes[FRET_F].notes[i].pos_y, note_map, model->lanes[FRET_F].notes[i].size_y);
        }
    }

}


/*---------- FUNCTION: render_frets ---------------------
/  PURPOSE:
/ 	Renders the 4 frets
/ 
/  CALLER INPUT:
/   UINT32 *base
/ 	- Starting point of the frame buffer
/   Model *model
/   - Address of the game model
/
/  CALLER OUTPUT:
/   Returns Void
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/  
/--------------------------------------------------------*/
void render_frets(UINT32 *base, Model *model) 
{  

    plot_bitmap_32(base, model->frets[FRET_A].pos_x, model->frets[FRET_A].pos_y, a_map, model->frets[FRET_A].size_y);
    plot_bitmap_32(base, model->frets[FRET_S].pos_x, model->frets[FRET_S].pos_y, s_map, model->frets[FRET_S].size_y);
    plot_bitmap_32(base, model->frets[FRET_D].pos_x, model->frets[FRET_D].pos_y, d_map, model->frets[FRET_D].size_y);
    plot_bitmap_32(base, model->frets[FRET_F].pos_x, model->frets[FRET_F].pos_y, f_map, model->frets[FRET_F].size_y);

}

/*---------- FUNCTION: render_fretboard -----------------
/  PURPOSE:
/ 	Renders the 4 fretboard lanes and upper bar
/ 
/  CALLER INPUT:
/   UINT32 *base
/ 	- Starting point of the frame buffer
/
/  CALLER OUTPUT:
/   Returns Void
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/  
/--------------------------------------------------------*/
void render_fretboard(UINT8 *base)
{
    int i, start_y, start_x;
    start_y = 80;
    start_x = 156;

    for(i = 0; i < 4; i++)
    {

        plot_h_line(base, 156, 482, start_y);
        
        start_y += 1;

    }

    /* Plot first track*/
    for(i = 0; i < 4; i++)
    {
        vertical_line(base, start_x, 84, 274);

        start_x += 1;

    }
    
    start_x = 192;

      for(i = 0; i < 4; i++)
    {
        vertical_line(base, start_x, 84, 274);

        start_x += 1;

    }

    /*Plot second track*/

    start_x = 252;
    
    for(i = 0; i < 4; i++)
    {
        vertical_line(base, start_x, 84, 274);

        start_x += 1;

    }
    
    start_x = 287;

      for(i = 0; i < 4; i++)
    {
        vertical_line(base, start_x, 84, 274);

        start_x += 1;

    }

    /*plot third track*/
    start_x = 348;
    
    for(i = 0; i < 4; i++)
    {
        vertical_line(base, start_x, 84, 274);

        start_x += 1;

    }
    
    start_x = 383;

      for(i = 0; i < 4; i++)
    {
        vertical_line(base, start_x, 84, 274);

        start_x += 1;

    }

    /*Plot fourth track*/
    start_x = 444;
    
    for(i = 0; i < 4; i++)
    {
        vertical_line(base, start_x, 84, 274);

        start_x += 1;

    }
    
    start_x = 479;

      for(i = 0; i < 4; i++)
    {
        vertical_line(base, start_x, 84, 274);

        start_x += 1;

    }
}

/*---------- FUNCTION: render_start_score ----------------
/  PURPOSE:
/ 	Renders the initial score
/ 
/  CALLER INPUT:
/   UINT32 *base
/ 	- Starting point of the frame buffer
/   Model *model
/   - Address of the game model
/
/  CALLER OUTPUT:
/   Returns Void
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/  
/--------------------------------------------------------*/
void render_start_score(UINT32 *base, Model *model){

    int pos_y = model->score.pos_y;
    int height = model->score.size_y;

    plot_bitmap_32(base, model->score.ones_x, pos_y, num_maps[0], height);
    plot_bitmap_32(base, model->score.tens_x, pos_y, num_maps[0], height);
    plot_bitmap_32(base, model->score.hunds_x, pos_y, num_maps[0], height);
    plot_bitmap_32(base, model->score.thous_x, pos_y, num_maps[0], height);

}

/*---------- FUNCTION: render_score ---------------------
/  PURPOSE:
/ 	Renders the updated score based on models value
/ 
/  CALLER INPUT:
/   UINT32 *base
/ 	- Starting point of the frame buffer
/   Model *model
/   - Address of the game model
/
/  CALLER OUTPUT:
/   Returns Void
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/  
/--------------------------------------------------------*/
void render_score(UINT32 *base, Model *model){

    UINT16 value, ones, tens, hundreds, thousands, height, pos_y;

    if(model->score.updated_flag == TRUE){

        height = model->score.size_y;

        pos_y = model->score.pos_y;

        value = model->score.value;

        ones = value & 0xF;

        tens = (value >> 4) & 0xF;

        hundreds = (value >> 8) & 0xF;

        thousands = (value >> 12) & 0xF;

        if(ones != model->score.prev_ones){

            model->score.prev_ones = ones;

            plot_bitmap_32(base, model->score.ones_x, pos_y, num_maps[ones], height);

        }

        if(tens != model->score.prev_tens){

            model->score.prev_tens = tens;

            plot_bitmap_32(base, model->score.tens_x, pos_y, num_maps[tens], height);

        }

        if(hundreds != model->score.prev_hunds){

            model->score.prev_hunds = hundreds;

            plot_bitmap_32(base, model->score.hunds_x, pos_y, num_maps[hundreds], height);

        }

        if(thousands != model->score.prev_thous){

            model->score.prev_thous = thousands;

            plot_bitmap_32(base, model->score.thous_x, pos_y, num_maps[thousands], height);

        }

        model->score.updated_flag = FALSE;
    }
}

/*---------- FUNCTION: render_x -------------------------
/  PURPOSE:
/ 	Renders the X for the multiplier
/ 
/  CALLER INPUT:
/   UINT32 *base
/ 	- Starting point of the frame buffer
/   Model *model
/   - Address of the game model
/
/  CALLER OUTPUT:
/   Returns Void
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/  
/--------------------------------------------------------*/
void render_x(UINT32 *base, Model *model){
    
    plot_bitmap_32(base, model->multiplier.pos_x, model->multiplier.pos_y, x_map, model->multiplier.digit_size_y);

}

/*---------- FUNCTION: render_start_multiplier -----------
/  PURPOSE:
/ 	Renders the initial multiplier number
/ 
/  CALLER INPUT:
/   UINT32 *base
/ 	- Starting point of the frame buffer
/   Model *model
/   - Address of the game model
/
/  CALLER OUTPUT:
/   Returns Void
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/  
/--------------------------------------------------------*/
void render_start_multiplier(UINT32 *base, Model *model){

    int pos_x = model->multiplier.pos_x + 32;
    int pos_y = model->multiplier.pos_y;
    int height = model->multiplier.digit_size_y;

    plot_bitmap_32(base, pos_x, pos_y, one_map, height);

}


/*---------- FUNCTION: render_multiplier -----------------
/  PURPOSE:
/ 	Renders the updated multipler number based 
/   on the models value
/ 
/  CALLER INPUT:
/   UINT32 *base
/ 	- Starting point of the frame buffer
/   Model *model
/   - Address of the game model
/
/  CALLER OUTPUT:
/   Returns Void
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/  
/--------------------------------------------------------*/
void render_multiplier(UINT32 *base, Model *model)
{
    int pos_x = model->multiplier.pos_x + 32;
    int pos_y = model->multiplier.pos_y;
    int height = model->multiplier.digit_size_y;

    if(model->multiplier.prev_value != model->multiplier.value){


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

        model->multiplier.prev_value = model->multiplier.value;

    }

}

/*---------- FUNCTION: render_failbar -------------------
/  PURPOSE:
/   Renders the failbar based on the models value
/ 
/  CALLER INPUT:
/   UINT32 *base
/ 	- Starting point of the frame buffer
/   Model *model
/   - Address of the game model
/
/  CALLER OUTPUT:
/   Returns Void
/ 
/  ASSUMPTIONS, LIMITATIONS, KNOWN BUGS:
/   - Re-renders the entire failbar every update
/--------------------------------------------------------*/
void render_failbar(UINT32 *base, Model *model)
{
    int pos_y, sec_one, sec_two, sec_three, sec_four, sec_five, sec_six, height;
    
    pos_y = model->fail_bar.pos_y;
    height = model->fail_bar.size_y;
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