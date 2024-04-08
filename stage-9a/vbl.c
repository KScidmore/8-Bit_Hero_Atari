#include "vbl.h"
#include "events.h"
#include "model.h"
#include "globals.h"
#include "psg.h"
#include "music.h"

short render_timer = 0;
short note_timer = 0;
long total_time = 0;
short music_time = 0;
BOOL game_on = FALSE;
BOOL music_on = FALSE;
BOOL stop_gen = FALSE;

void do_vbl_isr(){

    if(game_on){

        total_time++;
        render_timer++;
        note_timer++;

        if(render_timer == 1){

            set_note_pos(&model);
            render_request = 1;
            render_timer = 0;
        }

        if(note_timer == 69){

            if(!stop_gen){

                generate_note(&model);
                
            }

            note_timer = 0;
        }

        if(total_time == 300){
            start_music();
            music_on = TRUE;
        }

        if(music_on == TRUE){

            music_time++;

            if(music_time == 69){
                update_music();
                music_time = 0;
            }


        }
    }
    
}