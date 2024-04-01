/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   sndconst.h
/  Citations:   
/    - http://poi.ribbon.free.fr/tmp/freq2regs.htm 
/
/  Instructions:
/    The range of usable note values for this chip is between
/    B-0 and B-8. 
/    The range of C-5 to B-5 is given. Left shifting and right
/    shifting can be used to move up and down octaves,
/    respectively.
/    In use, left shifting the values will lower them one octave
/    and right shifting them will raise them one octave.  
/    P.S. Most of this stuff was done with keyboard hotkeys and 
/    stuff, I'm not a insane.   
/
/--------------------------------------------------------*/

#ifndef SNDCONST_H
#define SNDCONST_H

/*---------- DEFINING ENVELOPE SHAPES ---------------------------------------*/
#define ENV_SHAPE_1 0x0
#define ENV_SHAPE_2 0x4
#define ENV_SHAPE_3 0x8
#define ENV_SHAPE_4 0x9
#define ENV_SHAPE_5 0xA
#define ENV_SHAPE_6 0xB
#define ENV_SHAPE_7 0xC
#define ENV_SHAPE_8 0xD
#define ENV_SHAPE_9 0xE
#define ENV_SHAPE_10 0xF


/*---------- DEFINING ENVELOPE SHAPES ---------------------------------------*/


/*---------- DEFINING NOTE VALUES -------------------------------------------*/
#define C5          0x0EF
#define C5_SHARP    0x0E2
#define D5          0x0D5
#define D5_SHARP    0x0C9
#define E5          0x0BE
#define F5          0x0B3
#define F5_SHARP    0x0A9
#define G5          0x09F
#define G5_SHARP    0x096
#define A5          0x08E
#define A5_SHARP    0x086
#define B5          0x07F

#define C6 C5>>1
#define C6_SHARP C5_SHARP>>1
#define D6 D5>>1
#define D6_SHARP D5_SHARP>>1
#define E6 E5>>1
#define F6 F5>>1
#define F6_SHARP F5_SHARP>>1
#define G6 G5>>1
#define G6_SHARP G5_SHARP>>1
#define A6 A5>>1
#define A6_SHARP A5_SHARP>>1
#define B6 B5>>1

#define C7 C6>>1
#define C7_SHARP C6_SHARP>>1
#define D7 D6>>1
#define D7_SHARP D6_SHARP>>1
#define E7 E6>>1
#define F7 F6>>1
#define F7_SHARP F6_SHARP>>1
#define G7 G6>>1
#define G7_SHARP G6_SHARP>>1
#define A7 A6>>1
#define A7_SHARP A6_SHARP>>1
#define B7 B6>>1

#define C4 C5<<1
#define C4_SHARP C5_SHARP<<1
#define D4 D5<<1
#define D4_SHARP D5_SHARP<<1
#define E4 E5<<1
#define F4 F5<<1
#define F4_SHARP F5_SHARP<<1
#define G4 G5<<1
#define G4_SHARP G5_SHARP<<1
#define A4 A5<<1
#define A4_SHARP A5_SHARP<<1
#define B4 B5<<1

#define C3 C4<<2
#define C3_SHARP C4_SHARP<<2
#define D3 D4<<2
#define D3_SHARP D4_SHARP<<2
#define E3 E4<<2
#define F3 F4<<2
#define F3_SHARP F4_SHARP<<2
#define G3 G4<<2
#define G3_SHARP G4_SHARP<<2
#define A3 A4<<2
#define A3_SHARP A4_SHARP<<2
#define B3 B4<<2

#define C2 C3<<3
#define C2_SHARP C3_SHARP<<3
#define D2 D3<<3
#define D2_SHARP D3_SHARP<<3
#define E2 E3<<3
#define F2 F3<<3
#define F2_SHARP F3_SHARP<<3
#define G2 G3<<3
#define G2_SHARP G3_SHARP<<3
#define A2 A3<<3
#define A2_SHARP A3_SHARP<<3
#define B2 B3<<3

#define C1 C2<<4
#define C1_SHARP C2_SHARP<<4
#define D1 D2<<4
#define D1_SHARP D2_SHARP<<4
#define E1 E2<<4
#define F1 F2<<4
#define F1_SHARP F2_SHARP<<4
#define G1 G2<<4
#define G1_SHARP G2_SHARP<<4
#define A1 A2<<4
#define A1_SHARP A2_SHARP<<4
#define B1 B2<<4



#endif