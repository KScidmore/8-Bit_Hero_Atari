/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   mus_tst.c
/  Citations:   
/    - TODO
/
/  Program Purposes:
/    Data Structures: 
/      - TODO
/
/    Functions:
/      - TODO  
/--------------------------------------------------------*/

#include <stdio.h>
#include <osbind.h>
#include "psg.h  "
#include "types.h"
#include "sndconst.h"
#include "music.h"
#include "songdat.h"

#define VEC_VBL_ISR 28
#define ESC 27

#define BPM 80

typedef void (*Vector)(); 

Vector install_vector(int num, Vector vector);
void vbl_isr();
void do_vbl_isr(int *counterPtr);

int measures = 1;
int w_beats = 1;
int h_beats = 1;
int q_beats = 1;

int main() {
    int old_w_beats = 0;
    int old_h_beats = 0;
    int old_q_beats = 0;

    Vector orig_vector = install_vector(VEC_VBL_ISR, vbl_isr);
    
    



    /*
    start_music();
    */

    while (measures <= 4) {
        /* prints past 4 w/o second if condition */
        if ((w_beats != old_w_beats || h_beats != old_h_beats ||
            q_beats != old_q_beats) && measures <= 4) {
            printf("Measure:\t\t%u\n", measures);
            printf("Whole Beats:\t%u\n", w_beats);
            printf("Half Beats:\t\t%u\n", h_beats);
            printf("Quarter Beats:\t%u\n\n", q_beats);
            old_w_beats = w_beats;
            old_h_beats = h_beats;
            old_q_beats = q_beats;
        }
    }

    install_vector(VEC_VBL_ISR, orig_vector);

    return 0;
}

Vector install_vector(int num, Vector vector) {
    Vector orig;
    Vector *vectp = (Vector *)((long)num << 2);
    long old_ssp = Super(0);

    orig = *vectp;
    *vectp = vector;

    Super(old_ssp);
    return orig;
}

void do_vbl_isr() {
    /*
    - math is very slightly off to avoid floats or weird logic
    - shouldn't affect timing, miniscule difference 
    */
    static UINT32 measure_counter = 0;
    static UINT32 w_beat_counter = 0;
    static UINT32 h_beat_counter = 0;
    static UINT32 q_beat_counter = 0;

    measure_counter += 1;
    w_beat_counter += 1;
    h_beat_counter += 1;
    q_beat_counter += 1;

    /*-------- measures ------------------------*/
    if (measure_counter == 210) 
    {
        measures += 1;
        measure_counter = 0;
    }

    /*-------- whole beats ---------------------*/
    if (w_beat_counter == 52 || w_beat_counter == 105 || w_beat_counter == 157) 
    {
        w_beats += 1;
    }
    else if (w_beat_counter == 210) {
        w_beats = 1;
        w_beat_counter = 0;
    }

    /*-------- half beats ----------------------*/
    if (h_beat_counter == 26 || h_beat_counter == 52 || h_beat_counter == 78 || 
        h_beat_counter == 105 || h_beat_counter == 131 || h_beat_counter == 157 || 
        h_beat_counter == 183) 
    {
        h_beats += 1;
    }
    else if (h_beat_counter == 210) {
        h_beats = 1;
        h_beat_counter = 0;
    }


    /*-------- quarter beats -------------------*/
    if (q_beat_counter == 13 || q_beat_counter == 26 || q_beat_counter == 39 || 
        q_beat_counter == 52 || q_beat_counter == 65 || q_beat_counter == 78 || 
        q_beat_counter == 91 || q_beat_counter == 105 || q_beat_counter == 118 || 
        q_beat_counter == 131 || q_beat_counter == 144 || q_beat_counter == 157 || 
        q_beat_counter == 170 || q_beat_counter == 183 || q_beat_counter == 196 )
    {
        q_beats += 1;
    }
    else if (q_beat_counter == 210) {
        q_beats = 1;
        q_beat_counter = 0;
    }

}