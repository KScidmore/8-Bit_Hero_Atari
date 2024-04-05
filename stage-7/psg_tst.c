/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   psg_tst.c
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
#include "types.h"
#include "psg.h"
#include "sndconst.h"

void play_tone_C5();
void play_noise();
void env_example();
void play_note(int note);
void play_cmaj_scale();

void test_set_tone();
void test_set_volume();
void test_enable_channel();
void test_set_noise();
void test_set_envelope();


int main()
{    
    /*
    test_set_tone();
    test_set_volume();
    test_set_noise();
    test_enable_channel();
    test_set_envelope();
    */

    return 0;
}


void play_tone_C5()
{
    set_tone(0, C5);            /* set tone freq */
    set_volume(0, 0x0B);        /* set mode and volume */
    enable_channel(0, 1, 0);    /* enable mixer channel */
	while (!Cconis());          /* tone now playing, await key */     
    stop_sound();               /* set channel levels to 0 */
	Cnecin();
}

void play_noise()
{
    set_noise(0x10);            /* set noise freq */
    set_volume(2, 0x0B);        /* set mode and volume */
    enable_channel(2, 0, 1);    /* enable mixer channel */
	while (!Cconis());          /* tone now playing, await key */     
    stop_sound();               /* set channel levels to 0 */
	Cnecin();
}

void env_example()
{
    /* Envelope Shape 1 */    
    set_tone(0, C5);                    /* set tone */
    set_volume(0, 0x13);                /* set mode and volume */
    set_envelope(ENV_SHAPE_1, 0x0F00);  /* set envelope */
    enable_channel(0, 1, 0);            /* enable channel A on mixer */
	while (!Cconis());                  /* tone now playing, await key */     
    stop_sound();                       /* set channel levels to 0 */
	Cnecin();

    /* Envelope Shape 2 */    
    set_volume(0, 0x13);                /* set mode and volume */
    set_envelope(ENV_SHAPE_2, 0x0F00);  /* set envelope */
    enable_channel(0, 1, 0);            /* enable channel A on mixer */
	while (!Cconis());                  /* tone now playing, await key */     
    stop_sound();                       /* set channel levels to 0 */
	Cnecin();

    /* Envelope Shape 3 */    
    set_volume(0, 0x13);                /* set mode and volume */
    set_envelope(ENV_SHAPE_3, 0x0F00);  /* set envelope */
    enable_channel(0, 1, 0);            /* enable channel A on mixer */
	while (!Cconis());                  /* tone now playing, await key */     
    stop_sound();                       /* set channel levels to 0 */
	Cnecin();

    /* Envelope Shape 4 */    
    set_volume(0, 0x13);                /* set mode and volume */
    set_envelope(ENV_SHAPE_4, 0x0F00);  /* set envelope */
    enable_channel(0, 1, 0);            /* enable channel A on mixer */
	while (!Cconis());                  /* tone now playing, await key */     
    stop_sound();                       /* set channel levels to 0 */
	Cnecin();

    /* Envelope Shape 5 */    
    set_volume(0, 0x13);                /* set mode and volume */
    set_envelope(ENV_SHAPE_5, 0x0F00);  /* set envelope */
    enable_channel(0, 1, 0);            /* enable channel A on mixer */
	while (!Cconis());                  /* tone now playing, await key */     
    stop_sound();                       /* set channel levels to 0 */
	Cnecin();

    /* Envelope Shape 6 */    
    set_volume(0, 0x13);                /* set mode and volume */
    set_envelope(ENV_SHAPE_6, 0x0F00);  /* set envelope */
    enable_channel(0, 1, 0);            /* enable channel A on mixer */
	while (!Cconis());                  /* tone now playing, await key */     
    stop_sound();                       /* set channel levels to 0 */
	Cnecin();

    /* Envelope Shape 7 */    
    set_volume(0, 0x13);                /* set mode and volume */
    set_envelope(ENV_SHAPE_7, 0x0F00);  /* set envelope */
    enable_channel(0, 1, 0);            /* enable channel A on mixer */
	while (!Cconis());                  /* tone now playing, await key */     
    stop_sound();                       /* set channel levels to 0 */
	Cnecin();

    /* Envelope Shape 8 */    
    set_volume(0, 0x13);                /* set mode and volume */
    set_envelope(ENV_SHAPE_8, 0x0F00);  /* set envelope */
    enable_channel(0, 1, 0);            /* enable channel A on mixer */
	while (!Cconis());                  /* tone now playing, await key */     
    stop_sound();                       /* set channel levels to 0 */
	Cnecin();

    /* Envelope Shape 9 */    
    set_volume(0, 0x13);                /* set mode and volume */
    set_envelope(ENV_SHAPE_9, 0x0F00);  /* set envelope */
    enable_channel(0, 1, 0);            /* enable channel A on mixer */
	while (!Cconis());                  /* tone now playing, await key */     
    stop_sound();                       /* set channel levels to 0 */
	Cnecin();

    /* Envelope Shape 10*/    
    set_volume(0, 0x13);                /* set mode and volume */
    set_envelope(ENV_SHAPE_10, 0x0F00);  /* set envelope */
    enable_channel(0, 1, 0);            /* enable channel A on mixer */
	while (!Cconis());                  /* tone now playing, await key */     
    stop_sound();                       /* set channel levels to 0 */
	Cnecin();
}


void play_note(int note)
{
    long i;
    set_tone(0, note);
    enable_channel(0, 1, 0);        /* enable channel A on mixer */
    write_psg(8, 11);               /* set channel A volume = 11 */
	for (i = 0; i < 70000; i++);    /* tone now playing in loop */  
    write_psg(8, 0);                /* set channel A volume = 0 */
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


/*---------- FUNCTION: test_set_tone ----------------------
/  PURPOSE:
/    Tests the set_tone function in a modular way 
/    by using arrays to store the test values. These values 
/    are used to test that the function is accepting and 
/    rejecting the proper values. 
/    
/  CURRENT STATUS:
/    All tests are passing/failing as expected. 
/
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    This function outputs a lot of text that may not all
/    fit to the console. It is easier to redirect the output
/    to a text file with this command:
/    psg_tst.c > psg_tst.txt
/--------------------------------------------------------*/
void test_set_tone()
{
    int channels[] = {0, 1, 2};
    int tunings[] = {-1, 0, 1, 4094, 4095, 4096};
    const int CHANNELS_SIZE = 3;
    const int TUNINGS_SIZE = 6;
    int i, j, fine_tone, rough_tone;

    printf("**********\n\nRunning test_set_tone()\n\n");

    for (i = 0; i < CHANNELS_SIZE; i++) 
    {
        for (j = 0; j < TUNINGS_SIZE; j++)
        {
            set_tone(channels[i], tunings[j]);

            fine_tone = tunings[j] & 0x0FF;
            rough_tone = (tunings[j] >> 8) & 0x0FF;

            if (read_psg(2*i) == fine_tone && read_psg(2*i+1) == rough_tone)
            {
                printf("PASS -- EDGE CASE AND IN-BOUNDS CHECK\n"
                "\tRegister: %d, Expected Value: 0x%X, Read Value: 0x%X\n"
                "\tRegister: %d, Expected Value: 0x%X, Read Value: 0x%X\n",
                2*i, fine_tone, read_psg(2*i),
                2*i+1, rough_tone, read_psg(2*i+1));
            }
            else if (tunings[j] < 0 || tunings[j] > 4095)
            {
                printf("VALID FAIL -- OUT-OF-BOUNDS CHECK\n"
                "\tRegister: %d, Expected Value: 0x%X, Read Value: 0x%X\n"
                "\tRegister: %d, Expected Value: 0x%X, Read Value: 0x%X\n",
                2*i, fine_tone, read_psg(2*i),
                2*i+1, rough_tone, read_psg(2*i+1));
            }
            else
            {
                printf("INVALID FAIL -- UNEXPECTED BEHAVIOUR\n"
                "\tRegister: %d, Expected Value: 0x%X, Read Value: 0x%X\n"
                "\tRegister: %d, Expected Value: 0x%X, Read Value: 0x%X\n",
                2*i, fine_tone, read_psg(2*i),
                2*i+1, rough_tone, read_psg(2*i+1));
            }
        }
        printf("\n");
    }
    printf("Completed running test_set_tone()\n\n**********\n\n");
}


/*---------- FUNCTION: test_set_volume --------------------
/  PURPOSE:
/    Tests the set_volume function in a modular way 
/    by using arrays to store the test values. These values 
/    are used to test that the function is accepting and 
/    rejecting the proper values. 
/    
/  CURRENT STATUS:
/    All tests are passing/failing as expected. 
/
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    This function outputs a lot of text that may not all
/    fit to the console. It is easier to redirect the output
/    to a text file with this command:
/    psg_tst.c > psg_tst.txt
/--------------------------------------------------------*/
void test_set_volume()
{
    int channels[] = {0, 1, 2};
    int volumes[] = {-1, 0, 1, 30, 31, 32};
    const int CHANNELS_SIZE = 3;
    const int VOLUMES_SIZE = 6;
    int i, j;

    printf("**********\n\nRunning test_set_volume()\n\n");

    for (i = 0; i < CHANNELS_SIZE; i++) 
    {
        for (j = 0; j < VOLUMES_SIZE; j++)
        {
            set_volume(channels[i], volumes[j]);

            if (read_psg(i+8) == volumes[j])
            {
                printf("PASS -- EDGE CASE AND IN-BOUNDS CHECK\n"
                "\tRegister: %d, Expected Value: 0x%X, Read Value: 0x%X\n",
                i+8, volumes[j], read_psg(i+8));
            }
            else if (volumes[j] < 0 || volumes[j] > 31)
            {
                printf("VALID FAIL -- OUT-OF-BOUNDS CHECK\n"
                "\tRegister: %d, Expected Value: 0x%X, Read Value: 0x%X\n",
                i+8, volumes[j], read_psg(i+8));
            }
            else 
            {
                printf("INVALID FAIL -- UNEXPECTED BEHAVIOUR\n"
                "\tRegister: %d, Expected Value: 0x%X, Read Value: 0x%X\n",
                i+8, volumes[j], read_psg(i+8));
            }
        }
        printf("\n");
    }
    printf("Completed running test_set_volume()\n\n**********\n\n");
}


/*---------- FUNCTION: test_enable_channel ----------------
/  PURPOSE:
/    Tests the enable_channel function in a modular way 
/    by using arrays to store the test values. These values 
/    are used to test that the function is accepting and 
/    rejecting the proper values. 
/    
/  CURRENT STATUS:
/    All tests are passing/failing as expected. 
/
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    This function outputs a lot of text that may not all
/    fit to the console. It is easier to redirect the output
/    to a text file with this command:
/    psg_tst.c > psg_tst.txt
/--------------------------------------------------------*/
void test_enable_channel()
{
    int channels[] = {0, 1, 2};
    int tone_states[] = {-1, 0, 1, 2};
    int noise_states[] = {-1, 0, 1, 2};
    const int CHANNELS_SIZE = 3;
    const int TONE_STATES_SIZE = 4;
    const int NOISE_STATES_SIZE = 4;
    int i, j, k, mixer_settings;


    printf("**********\n\nRunning test_enable_channel()\n\n");

    for (i = 0; i < CHANNELS_SIZE; i++) 
    {
        for (j = 0; j < TONE_STATES_SIZE; j++)
        {
            for (k = 0; k < NOISE_STATES_SIZE; k++)
            {
                mixer_settings = IO_PORT_BITS;

                if (tone_states[j] == 1) {
                    mixer_settings &= ~(1 << channels[i]);
                }

                if (noise_states[k] == 1) {
                    mixer_settings &= ~(1 << (channels[i] + 3));
                }

                enable_channel(channels[i], tone_states[j], noise_states[k]);

                if (read_psg(7) == mixer_settings)
                {
                    printf("PASS -- EDGE CASE AND IN-BOUNDS CHECK\n"
                    "\tRegister: 7, Expected Value: 0x%X, Read Value: 0x%X\n",
                    mixer_settings, read_psg(7));
                }
                else if (tone_states[j] < 0 || tone_states[j] > 1 ||
                         noise_states[k] < 0 || noise_states[k] > 1)
                {
                    printf("VALID FAIL -- OUT-OF-BOUNDS CHECK\n"
                    "\tRegister: 7, Expected Value: 0x%X, Read Value: 0x%X\n",
                    mixer_settings, read_psg(7));
                }
                else
                {
                    printf("INVALID FAIL -- UNEXPECTED BEHAVIOUR\n"
                    "\tRegister: 7, Expected Value: 0x%X, Read Value: 0x%X\n",
                    mixer_settings, read_psg(7));
                }
                

            }
        }
        printf("\n");
    }
    printf("Completed running test_enable_channel()\n\n**********\n\n");
}




/*---------- FUNCTION: test_set_noise ---------------------
/  PURPOSE:
/    Tests the set_noise function in a modular way 
/    by using arrays to store the test values. These values 
/    are used to test that the function is accepting and 
/    rejecting the proper values. 
/    
/  CURRENT STATUS:
/    All tests are passing/failing as expected. 
/
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    This function outputs a lot of text that may not all
/    fit to the console. It is easier to redirect the output
/    to a text file with this command:
/    psg_tst.c > psg_tst.txt
/--------------------------------------------------------*/
void test_set_noise()
{
    int tunings[] = {-1, 0, 1, 30, 31, 32};
    const int TUNINGS_SIZE = 6;
    int i;

    printf("**********\n\nRunning test_set_noise()\n\n");

    for (i = 0; i < TUNINGS_SIZE; i++) 
    {
        set_noise(tunings[i]);

        if (read_psg(6) == tunings[i])
        {
            printf("PASS -- EDGE CASE AND IN-BOUNDS CHECK\n"
            "\tRegister: 6, Expected Value: 0x%X, Read Value: 0x%X\n",
            tunings[i], read_psg(6));
        }
        else if (tunings[i] < 0 || tunings[i] > 31)
        {
            printf("VALID FAIL -- OUT-OF-BOUNDS CHECK\n"
            "\tRegister: 6, Expected Value: 0x%X, Read Value: 0x%X\n",
            tunings[i], read_psg(6));
        }
        else 
        {
            printf("INVALID FAIL -- UNEXPECTED BEHAVIOUR\n"
            "\tRegister: 6, Expected Value: 0x%X, Read Value: 0x%X\n",
            tunings[i], read_psg(6));
        }
        printf("\n");
    }
    printf("Completed running test_set_noise()\n\n**********\n\n");
}


/*---------- FUNCTION: test_set_envelope ------------------
/  PURPOSE:
/    Tests the set_envelope function in a modular way 
/    by using arrays to store the test values. These values 
/    are used to test that the function is accepting and 
/    rejecting the proper values. 
/    
/  CURRENT STATUS:
/    All tests are passing/failing as expected. 
/
/  ASSUMPTIONS, LIMITATIONS, AND KNOWN BUGS:
/    This function outputs a lot of text that may not all
/    fit to the console. It is easier to redirect the output
/    to a text file with this command:
/    psg_tst.c > psg_tst.txt
/--------------------------------------------------------*/
void test_set_envelope()
{
    int shapes[] = {-1, 0, 1, 14, 15, 16};
    int sustains[] = {-1, 0, 1, 65534, 65535, 65536};
    const int SHAPES_SIZE = 6;
    const int SUSTAINS_SIZE = 6;
    int i, j, fine, rough;

    printf("**********\n\nRunning test_set_envelope()\n\n");

    for (i = 0; i < SHAPES_SIZE; i++) 
    {
        for (j = 0; j < SUSTAINS_SIZE; j++)
        {
            set_envelope(shapes[i], sustains[j]);

            fine = sustains[j] & 0x0FF;
            rough = (sustains[j] >> 8) & 0x0FF;

            if (read_psg(11) == fine && read_psg(12) == rough &&
                read_psg(13) == shapes[i])
            {
                printf("PASS -- EDGE CASE AND IN-BOUNDS CHECK\n"
                "\tRegister: 11, Expected Value: 0x%X, Read Value: 0x%X\n"
                "\tRegister: 12, Expected Value: 0x%X, Read Value: 0x%X\n"
                "\tRegister: 13, Expected Value: 0x%X, Read Value: 0x%X\n",
                fine, read_psg(11), rough, read_psg(12), shapes[i], read_psg(13));
            }
            else if (shapes[i] < 0 || shapes[i] > 15 || 
                     sustains[j] < 0 || sustains[j] > 65535)
            {
                printf("VALID FAIL -- OUT-OF-BOUNDS CHECK\n"
                "\tRegister: 11, Expected Value: 0x%X, Read Value: 0x%X\n"
                "\tRegister: 12, Expected Value: 0x%X, Read Value: 0x%X\n"
                "\tRegister: 13, Expected Value: 0x%X, Read Value: 0x%X\n",
                fine, read_psg(11), rough, read_psg(12), shapes[i], read_psg(13));
            }
            else
            {
                printf("INVALID FAIL -- UNEXPECTED BEHAVIOUR\n"
                "\tRegister: 11, Expected Value: 0x%X, Read Value: 0x%X\n"
                "\tRegister: 12, Expected Value: 0x%X, Read Value: 0x%X\n"
                "\tRegister: 13, Expected Value: 0x%X, Read Value: 0x%X\n",
                fine, read_psg(11), rough, read_psg(12), shapes[i], read_psg(13));
            }
        }
        printf("\n");
    }
    printf("Completed running test_set_envelope()\n\n**********\n\n");
}