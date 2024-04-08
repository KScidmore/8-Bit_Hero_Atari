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

#endif