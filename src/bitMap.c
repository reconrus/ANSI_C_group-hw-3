//
// Created by puzankova 02.06.18
//
#include <stddef.h>
#include <stdio.h>
#include "bitMap.h"
#include "math.h"

int getBitByNumber(char *array, int position) {
    char size = 8;
    int n = position / size;
    char bitPos = size - 1 - (position % size);
    char k = (array[n] >> bitPos) & 1;

    return k ? 1 : 0;
}


void setBitByNumber(char *array, int bit, int position) {
    char size = 8;
    int n = position / size;

    if (getBitByNumber(array, position) == bit) return;

    char bitPos = size - 1 - (position % size);
    char mask = 1 << bitPos;
    array[n] ^= mask;
}

void setBitByAddress(char *position, int bit) {
    char mask;
    if (bit) {
        mask = -128;
        *position |= mask;
    } else {
        mask = 127;
        *position &= mask;
    }
}

int getBitByAddress(char *position) {
    return (*position & (char) (-128)) ? 1 : 0;
}
