//
// Created by puzankova 02.06.18
//
#include <stddef.h>
#include <stdio.h>
#include "bitMap.h"
#include "math.h"

int getBitByNumber(int* array, int position)
{
    int size  = 8*sizeof(int);
    int n = position/size;
    int k = array[n];

    n = (position)%size;
    k = k >> (size - n - 1);
    k = k & 1;
    return k;
}


void setBitByNumber(int* array, int bit, int position)
{
    int size = 8*sizeof(int);
    int n = position/size;

    if(getBitByNumber(array, position) == bit) return;

    int bitPos = size - 1 - (position%size);
    int mask = 1 << bitPos;
    array[n] ^= mask;
}

void setBitByAddress(void* position, int bit)
{
    char mask;
    if(bit) {
        mask = -128;
        *((char*) position) |= mask;
    }else {
        mask = 127;
        *((char*) position) &= mask;
    }
}

int getBitByAddress(void* position) {
    return *((char*) position)&(-128);
}
