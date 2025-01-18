#include "Sudoku.h"

int UNSOLVED = 81; //setting unsolved to 81 as any sudoku puzzle starts out with 81 unsolved squares
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

int main(){
    int ** puzzle;
    int progress;
    Sudoku * sudoku;

    puzzle = createPuzzle();

    sudoku = setUpPuzzle(puzzle);

    printPuzzle(sudoku->squares);
    
    checkPuzzle(sudoku->squares, sudoku->boxes); /*this function will loop though every single number/square
                     and say/return have we found any numbers that have
                     solveble = 1 therefore tha tnumber will be placed there*/
    //We Will be using a loop to call Check_Puzzle From now
    while(UNSOLVED > 0){
         progress =checkPuzzle(sudoku->squares, sudoku->boxes);
        
         if(progress == 0){
            printf("\n\n!!Failed To Solve The Puzzle!!\n\n");
            break;
         }
         else{
            printf("\n\n Horray!! Puzzle Solved !! \n\n");
         }
    }

    printf("\n\n");

    printPuzzle(sudoku->squares);


    return 0;
}
