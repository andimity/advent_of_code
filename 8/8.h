#ifndef __8_H__
#define __8_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define FILENAME        "input.txt"

/* Tree struct containing position and height*/
typedef struct Tree{
    uint16_t row;
    uint16_t col;
    uint8_t height;
}Tree;

#endif