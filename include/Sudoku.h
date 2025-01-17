#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

extern int UNSOLVED;               //Converting 9 1s i.e.(111111111) using a hex convertor returns 0x1FF
extern int SIZE_ROWS;
extern int SIZE_COLUMNS;


typedef struct Box{
    struct Square ** squares;
    int numbers;
    int possible[9];
    int solveable;
    struct Box * next;  
}Box;

typedef struct Square{
    int number;
    /*111101011-> 9 bits [this is our bit representation]
     [1][1][1][1][0][1][0][1][1] -> this is the changed array representation
     [9][8][7][6][5][4][3][2][1] -> index
        this way we can loop through the array and easily check for solveable and possible numbers
         relative count of can it/can it not be that number
                    1 relates to that it cant be, 0 relates to it can be
                    taking this into relation with [0][0] of the sample sudoku
                    the count becomes from 000000000 -> 111101011
                    */
    int possible[9];//shifting from bit representation to array representation

    int solveable;//this variable indicates how many numbers are unknown(kind of)
    Box * box;
    int row ;
    int column;
}Square;


int ** createPuzzle();
void printPuzzle(Square  *** puzzle);
Square *** setUpPuzzle(int ** puzzle);

int updateSudoku(Square *** sudoku, int row, int column);
int checkPuzzle(Square *** sudoku);

int solveSquare(Square * square);

//Box Functions
Box ** createBoxes();
int updateBoxes(Square *** sudoku, int row, int column);


#endif
