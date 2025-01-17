#include "Sudoku.h"

int solveSquare(Square * square){
    int x; //counter variable
    
    for(x=0; x<SIZE_ROWS; x++){
        if(square->possible[x] ==0){
            square->number = x+1;
            square->solveable = 0;
            UNSOLVED--;
        }
    }

}
