#include <stdio.h>
#include <osbind.h>
#include "types.h"
#include "psg.h"
#include "notefrqs.h"

void play_tone();
void play_tone_2();
void play_noise();
void env_test();
void play_D5();
void play_note(int note);
void play_cmaj_scale();

int main()
{
    /* keep here for now

    write_psg(0, 200);
    printf("Current value: %u \n", read_psg(0));
    write_psg(2, 150);
    printf("Current value: %u \n", read_psg(2));
    */

    /*
    play_noise();
    play_tone_2();
    env_test();
    play_tone();
    */

    play_cmaj_scale();


    return 0;
}

/* 
- lab 5 code with wrappers basically 
- exits on keyboard input
*/
void play_tone()
{
    /* need to replace write funcs with mine 
    */

    set_tone(0, 0x0EF);
    enable_channel(0, 1, 0);    /* enable channel A on mixer */
    write_psg(8, 11);           /* set channel A volume = 11 */
	while (!Cconis());          /* tone now playing, await key */     
    write_psg(8, 0);            /* set channel A volume = 0 */
	Cnecin();

}

void play_tone_2()
{
    long i;

    write_psg(0, 248);                  /* set channel A fine tune = 248 */
    write_psg(1, 0);                    /* set channel A coarse tune = 0 */
    set_envelope(0xA, 0xF03);

    enable_channel(0, 1, 0);            /* enable channel A on mixer */
    write_psg(8, 11);                   /* set channel A volume = 11 */
	for (i = 0; i < 500000; i++);       /* tone now playing in loop */  
    stop_sound();
	Cnecin();

}

void play_noise()
{


    write_psg(3, 248);          /* set channel C fine tune = 248 */
    write_psg(3, 0);            /* set channel C coarse tune = 0 */
    
    set_noise(300);
 
    enable_channel(2, 0, 1);    /* enable channel C on mixer */
    write_psg(10, 11);          /* set channel C volume = 11 */
	while (!Cconis());          /* tone now playing, await key */     
    write_psg(10, 0);           /* set channel C volume = 0 */
	Cnecin();

}

void env_test()
{
    write_psg(3, 248);          /* set channel C fine tune = 248 */
    write_psg(3, 0);            /* set channel C coarse tune = 0 */
    
    set_noise(300);
    set_envelope(0xA, 0xF03);

    enable_channel(2, 0, 1);    /* enable channel C on mixer */
    write_psg(10, 11);          /* set channel C volume = 11 */
	while (!Cconis());          /* tone now playing, await key */     
    write_psg(10, 0);           /* set channel C volume = 0 */
	Cnecin();
}

void play_D5()
{
    /* need to replace write funcs with mine 
    */

    set_tone(0, D5<<1);
    enable_channel(0, 1, 0);    /* enable channel A on mixer */
    write_psg(8, 11);           /* set channel A volume = 11 */
	while (!Cconis());          /* tone now playing, await key */     
    write_psg(8, 0);            /* set channel A volume = 0 */
	Cnecin();

}

void play_note(int note)
{
    long i;

    set_tone(0, note);
    enable_channel(0, 1, 0);    /* enable channel A on mixer */
    write_psg(8, 11);           /* set channel A volume = 11 */
	for (i = 0; i < 70000; i++);       /* tone now playing in loop */  
    write_psg(8, 0);            /* set channel A volume = 0 */

}

void play_cmaj_scale()
{
    play_note(C5<<1);
    play_note(D5<<1);
    play_note(E5<<1);
    play_note(F5<<1);
    play_note(G5<<1);
    play_note(A5<<1);
    play_note(B5<<1);
    play_note(C5);
}