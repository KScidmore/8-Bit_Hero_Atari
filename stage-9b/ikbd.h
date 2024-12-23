/*---------- ID HEADER ------------------------------------
/  Authors:     Andrew Boisvert, Kyle Scidmore
/  Emails:      abois526@mtroyal.ca, kscid125@mtroyal.ca 
/  File Name:   ikbd.h
/  Citations:   
/    - keytables: scancodes.txt and scancodes.bmp
/
/  Program Purposes:
/    This file contains constant defintions, struct declarations,
/    and function prototypes for ikbd.c and ikbdisr.s 
/--------------------------------------------------------*/

#ifndef IKBD_H
#define IKBD_H

#include "types.h"

#define SIZE 256 /* buffer size */

/* IKBD 6850 IRQ Vector */
#define VEC_IKBD_ISR 70

/* IKBD 6850 Addresses */
#define CONTROL ((UINT32)0xFFFC00)
#define STATUS  ((UINT32)0xFFFC00)
#define RDR     ((UINT32)0xFFFC02)
#define MASK    ((UINT32)0xFFFA15)

/*Mouse Packets*/
#define NO_MOUSE 0
#define MOUSE_PACKET1 1
#define MOUSE_PACKET2 2

/*Make codes for special keys ie: shifts/caps*/
#define LEFT_SHIFT_MAKE 0x2A
#define LEFT_SHIFT_BREAK 0xAA
#define RIGHT_SHIFT_MAKE 0x36
#define RIGHT_SHIFT_BREAK 0xB6
#define MAKE_MASK ((UINT8)0x80)
#define CAPS_LOCK 0x3A 

/*Misc Defines*/
#define NO_CHAR '\0'
#define DISABLE 0xBF
#define ENABLE 0x40


/*---------- STRUCTURE: Char_Buffer -----------------------
/  INFO:
/    A circular queue, implemented as an array, that is used 
/    to enqueue each key press's scan code.
/  
/  ATTRIBUTES:
/    int front 
/      the first value in the queue 
/    int back
/      the last value in the queue 
/    int size
/      the current size of the queue
/    UINT8 buffer[SIZE]
/      the array, which will act as a circular queue 
/--------------------------------------------------------*/
typedef struct{
    int front;
    int back;
    int size;
    UINT8 buffer[SIZE];
}Char_Buffer;


/*---------- Keytables ----------*/
/*
- key table for the atari ST based on make/break scancodes
- index # = scancode; the value at that index is the ASCII value 
- using this to convert scancodes to ASCII 
*/
extern const UINT8 unshifted_key_table[] = {
    0x00,
    0x1B, /* 0x01 */
    0x31, /* 0x02 */
    0x32, /* 0x03 */
    0x33, /* 0x04 */
    0x34, /* 0x05 */
    0x35, /* 0x06 */
    0x36, /* 0x07 */
    0x37, /* 0x08 */
    0x38, /* 0x09 */
    0x39, /* 0x0A */
    0x30, /* 0x0B */
    0x2D, /* 0x0C */
    0x3D, /* 0x0D */
    0x08, /* 0x0E */
    0x09, /* 0x0F */
    0x71, /* 0x10 */
    0x77, /* 0x11 */
    0x65, /* 0x12 */
    0x72, /* 0x13 */
    0x74, /* 0x14 */
    0x79, /* 0x15 */
    0x75, /* 0x16 */
    0x69, /* 0x17 */
    0x6F, /* 0x18 */
    0x70, /* 0x19 */
    0x5B, /* 0x1A */
    0x5D, /* 0x1B */
    0x0D, /* 0x1C */
    0x00, /* 0x1D */
    0x61, /* 0x1E */
    0x73, /* 0x1F */
    0x64, /* 0x20 */
    0x66, /* 0x21 */
    0x67, /* 0x22 */
    0x68, /* 0x23 */
    0x6A, /* 0x24 */
    0x6B, /* 0x25 */
    0x6C, /* 0x26 */
    0x3B, /* 0x27 */
    0x27, /* 0x28 */
    0x60, /* 0x29 */
    0x00, /* 0x2A */
    0x5C, /* 0x2B */
    0x7A, /* 0x2C */
    0x78, /* 0x2D */
    0x63, /* 0x2E */
    0x76, /* 0x2F */
    0x62, /* 0x30 */
    0x6E, /* 0x31 */
    0x6D, /* 0x32 */
    0x2C, /* 0x33 */
    0x2E, /* 0x34 */
    0x2F, /* 0x35 */
    0x00, /* 0x36 */
    0x00, /* 0x37 */
    0x00, /* 0x38 */
    0x20, /* 0x39 */
    0x00, /* 0x3A */
    0x00, /* 0x3B */
    0x00, /* 0x3C */
    0x00, /* 0x3D */
    0x00, /* 0x3E */
    0x00, /* 0x3F */
    0x00, /* 0x40 */
    0x00, /* 0x41 */
    0x00, /* 0x42 */
    0x00, /* 0x43 */
    0x00, /* 0x44 */
    0x00, /* 0x45 */
    0x00, /* 0x46 */
    0x00, /* 0x47 */
    0x00, /* 0x48 */
    0x00, /* 0x49 */
    0x2D, /* 0x4A */
    0x00, /* 0x4B */
    0x00, /* 0x4C */
    0x00, /* 0x4D */
    0x2B, /* 0x4E */
    0x00, /* 0x4F */
    0x00, /* 0x50 */
    0x00, /* 0x51 */
    0x00, /* 0x52 */
    0x7F, /* 0x53 */
    0x00, /* 0x54 */
    0x00, /* 0x55 */
    0x00, /* 0x56 */
    0x00, /* 0x57 */
    0x00, /* 0x58 */
    0x00, /* 0x59 */
    0x00, /* 0x5A */
    0x00, /* 0x5B */
    0x00, /* 0x5C */
    0x00, /* 0x5D */
    0x00, /* 0x5E */
    0x00, /* 0x5F */
    0x00, /* 0x61 */
    0x00, /* 0x62 */
    0x28, /* 0x63 */
    0x29, /* 0x64 */
    0x2F, /* 0x65 */
    0x2A, /* 0x66 */
    0x37, /* 0x67 */
    0x38, /* 0x68 */
    0x39, /* 0x69 */
    0x34, /* 0x6A */
    0x35, /* 0x6B */
    0x36, /* 0x6C */
    0x31, /* 0x6D */
    0x32, /* 0x6E */
    0x33, /* 0x6F */
    0x30, /* 0x70 */
    0x2E, /* 0x71 */
    0x0D  /* 0x72 */
};

extern const UINT8 shifted_key_table[] = {
    0x00,
    0x1B, /* 0x01 */ 
    0x21, /* 0x02 */ 
    0x40, /* 0x03 */ 
    0x23, /* 0x04 */ 
    0x24, /* 0x05 */ 
    0x25, /* 0x06 */ 
    0x5E, /* 0x07 */ 
    0x26, /* 0x08 */ 
    0x2A, /* 0x09 */ 
    0x28, /* 0x0A */ 
    0x29, /* 0x0B */ 
    0x5F, /* 0x0C */ 
    0x2B, /* 0x0D */ 
    0x08, /* 0x0E */ 
    0x09, /* 0x0F */ 
    0x51, /* 0x10 */ 
    0x57, /* 0x11 */ 
    0x45, /* 0x12 */ 
    0x52, /* 0x13 */ 
    0x54, /* 0x14 */ 
    0x59, /* 0x15 */ 
    0x55, /* 0x16 */ 
    0x49, /* 0x17 */ 
    0x4F, /* 0x18 */ 
    0x50, /* 0x19 */ 
    0x7B, /* 0x1A */ 
    0x7D, /* 0x1B */ 
    0x0D, /* 0x1C */
    0X00, /* 0X1D */ 
    0x41, /* 0x1E */ 
    0x53, /* 0x1F */ 
    0x44, /* 0x20 */ 
    0x46, /* 0x21 */ 
    0x47, /* 0x22 */ 
    0x48, /* 0x23 */ 
    0x4A, /* 0x24 */ 
    0x4B, /* 0x25 */ 
    0x4C, /* 0x26 */ 
    0x3A, /* 0x27 */ 
    0x22, /* 0x28 */ 
    0x7E, /* 0x29 */
    0X00, /* 0X2A */ 
    0x7C, /* 0x2B */ 
    0x5A, /* 0x2C */ 
    0x58, /* 0x2D */ 
    0x43, /* 0x2E */ 
    0x56, /* 0x2F */ 
    0x42, /* 0x30 */ 
    0x4E, /* 0x31 */ 
    0x4D, /* 0x32 */ 
    0x3C, /* 0x33 */ 
    0x3E, /* 0x34 */ 
    0x3F, /* 0x35 */
    0X00, /* 0X36 */
    0X00, /* 0X37 */
    0X00, /* 0X38 */    
    0x20, /* 0x39 */
    0X00, /* 0X3A */
    0X00, /* 0X3B */
    0X00, /* 0X3C */
    0X00, /* 0X3D */
    0X00, /* 0X3E */
    0X00, /* 0X3F */
    0X00, /* 0X40 */
    0X00, /* 0X41 */
    0X00, /* 0X42 */
    0X00, /* 0X43 */
    0X00, /* 0X44 */
    0X00, /* 0X45 */
    0X00, /* 0X46 */             
    0x37, /* 0x47 */ 
    0x38, /* 0x48 */
    0X00, /* 0X49 */  
    0x2D, /* 0x4A */ 
    0x34, /* 0x4B */
    0X00, /* 0X4C */  
    0x36, /* 0x4D */ 
    0x2B, /* 0x4E */
    0X00, /* 0X4F */  
    0x32, /* 0x50 */
    0x32, /* 0x51 */ 
    0x30, /* 0x52 */ 
    0x7F, /* 0x53 */ 
    0x00, /* 0x54 */ 
    0x00, /* 0x55 */ 
    0x00, /* 0x56 */ 
    0x00, /* 0x57 */ 
    0x00, /* 0x58 */ 
    0x00, /* 0x59 */ 
    0x00, /* 0x5A */ 
    0x00, /* 0x5B */ 
    0x00, /* 0x5C */ 
    0x00, /* 0x5D */
    0x00, /* 0x5E */
    0x00, /* 0x5F */
    0x00, /* 0x60 */ 
    0x00, /* 0x61 */ 
    0x00, /* 0x62 */ 
    0x28, /* 0x63 */ 
    0x29, /* 0x64 */ 
    0x2F, /* 0x65 */ 
    0x2A, /* 0x66 */ 
    0x37, /* 0x67 */ 
    0x38, /* 0x68 */ 
    0x39, /* 0x69 */ 
    0x34, /* 0x6A */ 
    0x35, /* 0x6B */ 
    0x36, /* 0x6C */ 
    0x31, /* 0x6D */ 
    0x32, /* 0x6E */ 
    0x33, /* 0x6F */ 
    0x30, /* 0x70 */ 
    0x2E, /* 0x71 */ 
    0x0D  /* 0x72 */ 
};


/* assembly prototypes from ikbdisr.s */
void ikbd_isr();
void set_ipl();

/* C prototypes */
void install_ikbd_vector();
void restore_ikbd_vector();
void do_ikbd_isr();
void init_char_buffer();
BOOL is_empty();
UINT8 dequeue_to_ascii();


#endif