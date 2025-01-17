#include "Sudoku.h"

int UNSOLVED = 81; //setting unsolved to 81 as any sudoku puzzle starts out with 81 unsolved squares
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

int main(){
    int ** puzzle;
    Square *** sudoku;

    puzzle = createPuzzle();

    sudoku = setUpPuzzle(puzzle);

    printPuzzle(sudoku);
    
    checkPuzzle(sudoku); /*this function will loop though every single number/square
                     and say/return have we found any numbers that have
                     solveble = 1 therefore tha tnumber will be placed there*/

    printf("\n\n");

    printPuzzle(sudoku);


    return 0;
}
