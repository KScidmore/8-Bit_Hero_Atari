#ifndef IKBD_H
#define IKBD_H

#include "types.h"

#define SIZE 256

typedef struct{
    int front;
    int back;
    int size;
    UINT8 buffer[SIZE];
}Char_Buffer;



void init_char_buffer(Char_Buffer *char_buffer);
BOOL is_empty(Char_Buffer *char_buffer);
void enqueue(Char_Buffer *char_buffer);
#endif