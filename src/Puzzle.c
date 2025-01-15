#include "Sudoku.h"


Square *** setUpPuzzle(int ** puzzle){
    Square *** sudoku;
    int i, j, x;
    sudoku = (Square***)malloc(sizeof(Square**)*9);
    
    //loop through the rows
    for(i=0; i<SIZE_ROWS; i++){
        // malloc space for each row
        sudoku[i] = (Square**)malloc(sizeof(Square*)*9);
        //loop through the columns 
        for(j=0; j<SIZE_COLUMNS; j++){
            // malloc space for each square/entry
            sudoku[i][j] = (Square*)malloc(sizeof(Square)*9);
            //assign number to sudoku adt
            sudoku[i][j]->number = puzzle[i][j];
            
            //assign row and column numbers to each square/entry
            sudoku[i][j]->row = i;
            sudoku[i][j]->column = j;
            sudoku[i][j]->solveable =9;

            //replacing bit-wise thing with an initialization loop to set all to zero
            for (x=0; x< SIZE_ROWS; x++){
                sudoku[i][j]->possible[x] = 0;
            }
        }
    }
    
    //loop through rows
    for(i=0; i<SIZE_ROWS; i++){
        // loop though columns 
        for(j=0; j<SIZE_COLUMNS; j++){
           //does this number have a value and what dows it tell
           if(sudoku[i][j]->number != 0){
                sudoku[i][j]->solveable;
                updateSudoku(sudoku, i, j);
                UNSOLVED--;
           }
        }
    }

    return sudoku;
}

int updateSudoku(Square *** sudoku, int row, int column){
    int x; //counter variable
    int number = sudoku[row][column]->number; //variable storing the index
    
    //loops through the entire row
    for(x=0; x<SIZE_ROWS; x++){
        if(sudoku[x][column]->possible[number-1] ==0){
            sudoku[x][column]->solveable--;
        }
        sudoku[x][column]->possible[number-1]=1;
    } 
    // loops through the entire column
    for(x=0; x<SIZE_COLUMNS; x++){
        if(sudoku[row][x]->possible[number-1] ==0){
            sudoku[row][x]->solveable--;
        }
        sudoku[row][x]->possible[number-1]=1;
    }
    return 1;
}

int checkPuzzle(Square *** sudoku){
    int i,j,x; //x is a counter
    //looping through the rows
    for(i=0; i<SIZE_ROWS; i++){
        //looping though the columns
        for(j=0; j<SIZE_COLUMNS; j++){
            if(sudoku[i][j]->solveable == 1){ // is the square solveable.?
                solveSquare(sudoku[i][j]); //this func. will figure out what no. is supposed to go in that square
                //since we solved a square now that particular no. cant be repeated in
                //column or that row so we call updateSudoku to update the parameters
                updateSudoku(sudoku, i, j);
            }   
        }
    }
    return 1;
}




int ** createPuzzle(){
    int ** puzzle;
    int i, j;
    int array[9][9] = {0,1,9,   0,0,2,  0,0,0,
                       4,7,0,   6,9,0,  0,0,1,
                       0,0,0,   4,0,0,  0,9,0,

                       8,9,4,   5,0,7,  0,0,0,
                       0,0,0,   0,0,0,  0,0,0,
                       0,0,0,   2,0,1,  9,5,8,

                       0,5,0,   0,0,6,  0,0,0,
                       6,0,0,   0,2,8,  0,7,9,
                       0,0,0,   1,0,0,  8,6,0 };
    
    puzzle = (int**)malloc(sizeof(int*)*9);

    for(i=0; i<9; i++){
        puzzle[i] = (int*)malloc(sizeof(int)*9);
        for(j=0; j<9; j++){
            puzzle[i][j] = array[i][j];
        }
    }

    return puzzle;
    
}

void printPuzzle(Square *** puzzle){
    int i,j;
    printf("-------------------------------\n");
    for(i=0; i<SIZE_ROWS; i++){
        printf("|");
        // prints each row
        for(j=0; j<SIZE_COLUMNS; j++){
            printf(" %d ", puzzle[i][j]->number);
            if((j+1)%3==0){
                printf("|");
            }
        }
        printf("\n");
        if((i+1) % 3 == 0){
            printf("-------------------------------\n");
        }

    }
}
