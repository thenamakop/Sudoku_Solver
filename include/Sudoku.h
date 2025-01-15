#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

extern char POSSIBLE;//Converting 9 1s i.e.(111111111) using a hex convertor returns 0x1FF
extern int SIZE_ROWS;
extern int SIZE_COLUMNS;


typedef struct Box{
    struct Box * next;  
}Box;

typedef struct Square{
    int number;
    /*111101011 -> 9 bits [this is our bit representation]
      987654321 -> relative count of can it/can it not be that number
                    1 relates to that it cant be, 0 relates to it can be
                    taking this into relation with [0][0] of the sample sudoku
                    the count becomes from 000000000 -> 111101011
                    */
    char code;
    Box * box;
    int row ;
    int column;
}Square;


int ** createPuzzle();
void printPuzzle(int ** puzzle);
Square *** setUpPuzzle(int ** puzzle);


#endif
