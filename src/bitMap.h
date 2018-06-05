//
// Created by artem on 02.06.2018.
//

#ifndef __BITMAP_H_
#define __BITMAP_H_

void setBitByNumber(char* array, int bit, int position);

int getBitByNumber(char* array, int position);

void setBitByAddress(char* position, int bit);

int getBitByAddress(char* position);

#endif //__BITMAP_H_
