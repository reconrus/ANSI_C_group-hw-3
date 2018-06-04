//
// Created by puzankova 02.06.18
//
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
	// position - pointer to the bit to change
	// bit - have to be equal to 0 or 1
	//
	// this function changes bit by memory address to 'bit'

	/* YOUR CODE */
}

int getBitByAddress(void* position)
{
	// this function returns first bit by memory address 'position'
	
	/* YOUR CODE */
}