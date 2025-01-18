#include "Sudoku.h"

Sudoku * createSudoku(Square *** squares, Box ** boxes){
    Sudoku * sudoku;
    sudoku = malloc(sizeof(Sudoku));

    sudoku->squares = squares;
    sudoku->boxes = boxes;

    return sudoku;
    
}

/*
 * Sudoku * setUpPuzzle
 *
 * Initial Puzlle Creation
 * */

Sudoku * setUpPuzzle(int ** puzzle){
    Square *** sudoku;
    Box ** boxes;
    int i, j, x;
    int currentBox = 0;

    sudoku = (Square***)malloc(sizeof(Square**)*9);
    boxes = createBoxes();
    
    //setting up our puzzle
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
            
            //we want to add this sqaure to the box and this box to the square (as they both reference each other)
            boxes[currentBox]->squares[boxes[currentBox]->numbers] = sudoku[i][j];
            sudoku[i][j]->box = boxes[currentBox];
            boxes[currentBox]->numbers++;

            //replacing bit-wise thing with an initialization loop to set all to zero
            for (x=0; x< SIZE_ROWS; x++){ 
                sudoku[i][j]->possible[x] = 0;
            } 
            if(j==2){ 
                currentBox++;
            } 
            if(j==5){ 
                currentBox++;
            }
                sudoku[i][j]->possible[x] = 0;
        }
        currentBox -= 2; //Using this to reset back to the first box
        //Special Case: when in Box[2] & row [2] we want to go to the
        //next box i.e. Box[3] and not box[0]
        if(i == 2){
            currentBox = 3;
        }
        //Likewise for Box[5] & row[5] goto Box[6]
        if(i==5){
            currentBox = 6;
        }
    }
    
    //loop through rows
    for(i=0; i<SIZE_ROWS; i++){
        // loop though columns 
        for(j=0; j<SIZE_COLUMNS; j++){
           //does this number have a value and what dows it tell
        if(sudoku[i][j]->number != 0){
            sudoku[i][j]->solveable = 0;
            updateSudoku(sudoku, i, j);
            updateBoxes(sudoku, i, j);
            UNSOLVED--;
        }
        }
    }

    return createSudoku(sudoku, boxes);
}
/*
 *int UpdateSudoku

 Once a single Square Is solved all other squares along
 the same row and column must be updated to reflect the change
 * */
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

/*
 *int checkPuzzle
 * 
 * loop through all squares in the puzzle to check for a solveable square
 * */
int checkPuzzle(Square *** sudoku, Box ** boxes){
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
                updateBoxes(sudoku, i, j);
                
                return 1;
            }   
        }
    }
    if(boxSingles(sudoku, boxes)){
        return 1;
    }
    return checkRows(sudoku, boxes);
}



/*
 *int ** createPuzzle()
 *
 * Create a double array containing the puzzle
 * */
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
    //Planning to add direct input based addition of sudoku puzzle rather than having to edit the code manually
    
    puzzle = (int**)malloc(sizeof(int*)*9);

    for(i=0; i<9; i++){
        puzzle[i] = (int*)malloc(sizeof(int)*9);
        for(j=0; j<9; j++){
            puzzle[i][j] = array[i][j];
        }
    }

    return puzzle;
    
}


/*
 * void PrintPuzzle
 *
 * Display the puzzle in a sudoku form
 * */
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
