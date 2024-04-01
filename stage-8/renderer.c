#include <osbind.h>
#include "types.h"
#include "renderer.h"
#include "model.h"
#include "RASTER.H"
#include "bitmaps.h"
#include "RAST_ASM.h"
#include "events.h"

#define CHECK_GENERATE 69

const UINT32 *num_maps[] = {zero_map, one_map, two_map, three_map, four_map, five_map, six_map, seven_map, eight_map, nine_map};


void init_scene(UINT8 *base, UINT32 *base32, Model *model){

    clear_screen(base);
    render_frets(base32, model);
    render_fretboard(base);
    render_start_score(base32, model);
    render_x(base32, model);
    render_start_multiplier(base32, model);
    render_start_failbar(base32, model);

}

void render_next(UINT32 *base, Model *model){

    static int note_counter = 0;
    static int note_gen = 0;
    static UINT8 i = 0;
    static UINT8 j = 0;
    static UINT8 k = 0;
    static UINT8 l = 0;

    render_active_notes(base, model);
    render_score(base, model);
    render_multiplier(base, model);
    render_failbar(base, model);
    render_frets(base, model);

     if(note_gen == CHECK_GENERATE){
        switch (note_counter){
                case 0:
                    clear_top(base, model);
                    render_new_note(base, model, FRET_A, i);
                    i++;
                    break;
                case 1:
                    clear_top(base, model);
                    render_new_note(base, model, FRET_S, j);
                    j++;
                    break;
                case 2:
                    clear_top(base, model);
                    render_new_note(base, model, FRET_D, k);
                    k++;
                    break;
                case 3:
                    clear_top(base, model);
                    render_new_note(base, model, FRET_F, l);
                    l++;
                    break;
            }
        note_counter++;
        note_gen = 0;
        if(note_counter == 4){
            note_counter = 0;
        }
    }
    else{
        note_gen++;
    }
}

void render_splashscreen(UINT8* base){

int i, j;
    for (i = 0; i < 400; i++) {
        
        for (j = 0; j < 640 / 8; j++) {
            plot_bitmap_8(base, 0 + j * 8, 0 + i, splashscreen + i * (640 / 8) + j, 1);
        }
    }


}

void render_new_note(UINT32 *base, Model *model, UINT8 fret, UINT8 note_index){

    model->lanes[fret].notes[note_index].is_active = TRUE;

}

void render_active_notes(UINT32 *base, Model *model){


    int i, SIZE, bottom;
    SIZE = 50;
    bottom = 358;

    for(i = 0; i< SIZE; i++){

        /*iterate through note array, for active notes update position and render*/
    
        if(model->lanes[FRET_A].notes[i].is_active == TRUE){
            
            clear_32(base, model->lanes[FRET_A].notes[i].pos_x, model->lanes[FRET_A].notes[i].pos_y, model->lanes[FRET_A].notes[i].size_y);
            set_note_pos(model, FRET_A, i);
            plot_bitmap_32(base, model->lanes[FRET_A].notes[i].pos_x, model->lanes[FRET_A].notes[i].pos_y, note_map, model->lanes[FRET_A].notes[i].size_y);

            if(model->lanes[FRET_A].notes[i].pos_y >= bottom){
                
                model->lanes[FRET_A].notes[i].is_active = FALSE;
                clear_32(base, model->lanes[FRET_A].notes[i].pos_x, model->lanes[FRET_A].notes[i].pos_y, model->lanes[FRET_A].notes[i].size_y);

            }
            
        }

        if(model->lanes[FRET_S].notes[i].is_active == TRUE){
            
            clear_32(base, model->lanes[FRET_S].notes[i].pos_x, model->lanes[FRET_S].notes[i].pos_y, model->lanes[FRET_S].notes[i].size_y);
            set_note_pos(model, FRET_S, i);
            plot_bitmap_32(base, model->lanes[FRET_S].notes[i].pos_x, model->lanes[FRET_S].notes[i].pos_y, note_map, model->lanes[FRET_S].notes[i].size_y);

            if(model->lanes[FRET_S].notes[i].pos_y >= bottom){
                
                model->lanes[FRET_S].notes[i].is_active = FALSE;
                clear_32(base, model->lanes[FRET_S].notes[i].pos_x, model->lanes[FRET_S].notes[i].pos_y, model->lanes[FRET_S].notes[i].size_y);

            }
        }

        if(model->lanes[FRET_D].notes[i].is_active == TRUE){
            
            clear_32(base, model->lanes[FRET_D].notes[i].pos_x, model->lanes[FRET_D].notes[i].pos_y, model->lanes[FRET_D].notes[i].size_y);
            set_note_pos(model, FRET_D, i);
            plot_bitmap_32(base, model->lanes[FRET_D].notes[i].pos_x, model->lanes[FRET_D].notes[i].pos_y, note_map, model->lanes[FRET_D].notes[i].size_y);

            if(model->lanes[FRET_D].notes[i].pos_y >= bottom){
                
                model->lanes[FRET_D].notes[i].is_active = FALSE;
                clear_32(base, model->lanes[FRET_D].notes[i].pos_x, model->lanes[FRET_D].notes[i].pos_y, model->lanes[FRET_D].notes[i].size_y);

            }
        }

        if(model->lanes[FRET_F].notes[i].is_active == TRUE){

            clear_32(base, model->lanes[FRET_F].notes[i].pos_x, model->lanes[FRET_F].notes[i].pos_y, model->lanes[FRET_F].notes[i].size_y);
            set_note_pos(model, FRET_F, i);
            plot_bitmap_32(base, model->lanes[FRET_F].notes[i].pos_x, model->lanes[FRET_F].notes[i].pos_y, note_map, model->lanes[FRET_F].notes[i].size_y);

            if(model->lanes[FRET_F].notes[i].pos_y >= bottom){
                
                model->lanes[FRET_F].notes[i].is_active = FALSE;
                clear_32(base, model->lanes[FRET_F].notes[i].pos_x, model->lanes[FRET_F].notes[i].pos_y, model->lanes[FRET_F].notes[i].size_y);

            }
        }
    }

}

void clear_top(UINT32 *base, Model *model){

    clear_32(base, model->lanes[FRET_A].notes[FRET_A].pos_x, 84, model->lanes[FRET_A].notes[FRET_A].size_y);
    clear_32(base, model->lanes[FRET_S].notes[FRET_S].pos_x, 84, model->lanes[FRET_S].notes[FRET_S].size_y);
    clear_32(base, model->lanes[FRET_D].notes[FRET_D].pos_x, 84, model->lanes[FRET_D].notes[FRET_D].size_y);
    clear_32(base, model->lanes[FRET_F].notes[FRET_F].pos_x, 84, model->lanes[FRET_F].notes[FRET_F].size_y);
    
}

void render_frets(UINT32 *base, Model *model) 
{  

    plot_bitmap_32(base, model->frets[FRET_A].pos_x, model->frets[FRET_A].pos_y, a_map, model->frets[FRET_A].size_y);
    plot_bitmap_32(base, model->frets[FRET_S].pos_x, model->frets[FRET_S].pos_y, s_map, model->frets[FRET_S].size_y);
    plot_bitmap_32(base, model->frets[FRET_D].pos_x, model->frets[FRET_D].pos_y, d_map, model->frets[FRET_D].size_y);
    plot_bitmap_32(base, model->frets[FRET_F].pos_x, model->frets[FRET_F].pos_y, f_map, model->frets[FRET_F].size_y);

}


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

void render_start_score(UINT32 *base, Model *model){

    int pos_y = model->score.pos_y;
    int height = model->score.size_y;

    plot_bitmap_32(base, model->score.ones_x, pos_y, num_maps[0], height);
    plot_bitmap_32(base, model->score.tens_x, pos_y, num_maps[0], height);
    plot_bitmap_32(base, model->score.hunds_x, pos_y, num_maps[0], height);
    plot_bitmap_32(base, model->score.thous_x, pos_y, num_maps[0], height);

}

void render_score(UINT32 *base, Model *model){

    UINT16 value, ones, tens, hundreds, thousands, height, pos_y;

    if(model->score.updated_flag == TRUE){

        height = model->score.size_y;

        pos_y = 16;

        value = model->score.value;

        ones = value % 10;         
        tens = (value / 10) % 10;    
        hundreds = (value / 100) % 10;
        thousands = (value / 1000); 
    
        if(ones != model->score.prev_ones){

            model->score.prev_ones = ones;

            clear_32(base, model->score.ones_x, pos_y, height);
            plot_bitmap_32(base, model->score.ones_x, pos_y, num_maps[ones], height);

        }

        if(tens != model->score.prev_tens){

            model->score.prev_tens = tens;

            clear_32(base, model->score.tens_x, pos_y, height);
            plot_bitmap_32(base, model->score.tens_x, pos_y, num_maps[tens], height);

        }

        if(hundreds != model->score.prev_hunds){

            model->score.prev_hunds = hundreds;
            clear_32(base, model->score.hunds_x, pos_y, height);
            plot_bitmap_32(base, model->score.hunds_x, pos_y, num_maps[hundreds], height);

        }

        if(thousands != model->score.prev_thous){

            model->score.prev_thous = thousands;

            clear_32(base, model->score.thous_x, pos_y, height);
            plot_bitmap_32(base, model->score.thous_x, pos_y, num_maps[thousands], height);

        }

         model->score.updated_flag = FALSE;
    }
}

void render_x(UINT32 *base, Model *model){
    
    plot_bitmap_32(base, model->multiplier.pos_x, model->multiplier.pos_y, x_map, model->multiplier.digit_size_y);

}

void render_start_multiplier(UINT32 *base, Model *model){

    int pos_x = model->multiplier.pos_x + 32;
    int pos_y = model->multiplier.pos_y;
    int height = model->multiplier.digit_size_y;

    plot_bitmap_32(base, pos_x, pos_y, one_map, height);

}

void render_multiplier(UINT32 *base, Model *model)
{
    int pos_x = model->multiplier.pos_x + 32;
    int pos_y = 0;
    int height = model->multiplier.digit_size_y;

    if(model->multiplier.prev_value != model->multiplier.value){


        if(model->multiplier.value == 1){
            
            clear_32(base, pos_x, pos_y, height);
            plot_bitmap_32(base, pos_x, pos_y, one_map, height);

        }
        else if(model->multiplier.value == 2){

            clear_32(base, pos_x, pos_y, height);
            plot_bitmap_32(base, pos_x, pos_y, two_map, height);

        }
        else if(model->multiplier.value == 4){

            clear_32(base, pos_x, pos_y, height);
            plot_bitmap_32(base, pos_x, pos_y, four_map, height);

        }
        else {

            clear_32(base, pos_x, pos_y, height);
            plot_bitmap_32(base, pos_x, pos_y, eight_map, height);

        }

        model->multiplier.prev_value = model->multiplier.value;

    }

}

void render_start_failbar(UINT32 *base, Model *model){

    int pos_y, sec_one, sec_two, sec_three, sec_four, sec_five, sec_six, height;
    
    pos_y = model->fail_bar.pos_y;
    height = model->fail_bar.size_y;
    sec_one = model->fail_bar.pos_x;
    sec_two = model->fail_bar.pos_x + 32;
    sec_three = model->fail_bar.pos_x + 64;
    sec_four = model->fail_bar.pos_x + 96;
    sec_five = model->fail_bar.pos_x + 128;
    sec_six = model->fail_bar.pos_x + 160;
        
    
    plot_bitmap_32(base, sec_one, pos_y, LEF_fail, height);
    plot_bitmap_32(base, sec_two, pos_y, MF_fail, height);
    plot_bitmap_32(base, sec_three, pos_y, MF_fail, height);
    plot_bitmap_32(base, sec_four, pos_y, ME_fail, height);
    plot_bitmap_32(base, sec_five, pos_y, ME_fail, height);
    plot_bitmap_32(base, sec_six, pos_y, REE_fail, height);

}
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

        clear_32(base, sec_one, pos_y, height);
        plot_bitmap_32(base, sec_one, pos_y, LEE_fail, height);

        /*plot_bitmap_32(base, sec_two, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_three, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_four, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_five, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_six, pos_y, REE_fail, height);*/
    }
    else if(model->fail_bar.value == 20 ){

        plot_bitmap_32(base, sec_one, pos_y, LEF_fail, height);
        clear_32(base, sec_two, pos_y, height);
        plot_bitmap_32(base, sec_two, pos_y, ME_fail, height);

        /*plot_bitmap_32(base, sec_three, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_four, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_five, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_six, pos_y, REE_fail, height);*/

    }
    else if(model->fail_bar.value == 40 ){

        /*plot_bitmap_32(base, sec_one, pos_y, LEF_fail, height);*/

        plot_bitmap_32(base, sec_two, pos_y, MF_fail, height);
        clear_32(base, sec_three, pos_y, height);
        plot_bitmap_32(base, sec_three, pos_y, ME_fail, height);

        /*plot_bitmap_32(base, sec_four, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_five, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_six, pos_y, REE_fail, height);*/

    }
    else if(model->fail_bar.value == 60 ){

        /*plot_bitmap_32(base, sec_one, pos_y, LEF_fail, height);
        plot_bitmap_32(base, sec_two, pos_y, MF_fail, height);*/

        plot_bitmap_32(base, sec_three, pos_y, MF_fail, height);
        clear_32(base, sec_four, pos_y, height);
        plot_bitmap_32(base, sec_four, pos_y, ME_fail, height);

        /*plot_bitmap_32(base, sec_five, pos_y, ME_fail, height);
        plot_bitmap_32(base, sec_six, pos_y, REE_fail, height);*/

    }
    else if(model->fail_bar.value == 80 ){

        /*plot_bitmap_32(base, sec_one, pos_y, LEF_fail, height);
        plot_bitmap_32(base, sec_two, pos_y, MF_fail, height);
        plot_bitmap_32(base, sec_three, pos_y, MF_fail, height);*/

        plot_bitmap_32(base, sec_four, pos_y, MF_fail, height);
        clear_32(base, sec_five, pos_y, height);
        plot_bitmap_32(base, sec_five, pos_y, ME_fail, height);

        /*plot_bitmap_32(base, sec_six, pos_y, REE_fail, height);*/

    }
    else if(model->fail_bar.value == 100 ){

        /*plot_bitmap_32(base, sec_one, pos_y, LEF_fail, height);
        plot_bitmap_32(base, sec_two, pos_y, MF_fail, height);
        plot_bitmap_32(base, sec_three, pos_y, MF_fail, height);
        plot_bitmap_32(base, sec_four, pos_y, MF_fail, height);*/

        plot_bitmap_32(base, sec_five, pos_y, MF_fail, height);
        clear_32(base, sec_six, pos_y, height);
        plot_bitmap_32(base, sec_six, pos_y, REE_fail, height);

    }
    else{

        /*plot_bitmap_32(base, sec_one, pos_y, LEF_fail, height);
        plot_bitmap_32(base, sec_two, pos_y, MF_fail, height);
        plot_bitmap_32(base, sec_three, pos_y, MF_fail, height);
        plot_bitmap_32(base, sec_four, pos_y, MF_fail, height);
        plot_bitmap_32(base, sec_five, pos_y, MF_fail, height);*/

        plot_bitmap_32(base, sec_six, pos_y, REF_fail, height);

    }
}