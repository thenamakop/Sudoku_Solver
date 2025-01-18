#include "Sudoku.h"

int checkRows(Square *** sudoku, Box ** boxes){
    int i,j,k;
    int sum[9];
    int place[9]; // Array to store Where we found a solveable square

    //Loop thorugh all rows
    for(i=0; i<9; i++){
        
        //Initialize sum and place to zero
        for(j=0; j<9; j++){
            place[j]=0;
            sum[j]=0;
        }
        //Loop rhough each square in the row
        for(j = 0; j<9; j++){
            if(sudoku[i][j] != 0){
                continue;
            }
            //loop through all possibles
            for(k=0; k<9; k++){
                //check if number [k] is possible
                if(sudoku[i][j]->possible[k]==0){
                    sum[k]++;
                    place[k]=j;
                }
            }
        }
        for(j=0; j<9; j++){
            if(sum[k]==1){
            //We Can Solve It
            //Solveable Square Found
                sudoku[i][place[k]] = k+1;
                sudoku[i][place[k]]->solveable = 0;
                UNSOLVED--;

                updateSudoku(sudoku, i, place[k]);
                updateBoxes(sudoku, i, place[k]);

                return 1;
            }
        }
    }

    return 0; //On Failure
}
