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
	if (position!=NULL&&position>=0&&(bit==0||bit==1)) {
        *((int *) position) = bit;
    }
    else{
	    printf("Error! Try again\n");
	}
}

int getBitByAddress(void* position) {
    if (position != NULL) {
        int res=*((int *) position);
        return res;
    }
    else{
        printf("Error, try again!\n");
    }
}