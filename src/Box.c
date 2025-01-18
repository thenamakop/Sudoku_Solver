#include "Sudoku.h"
/*
 * int boxSingles(Square *** sudoku, Box ** boxes)
 *
 * funtion to loop through all boxes and search 
 * for a number within the box that only apppears
 * as possible once
 * */
int boxSingles(Square *** sudoku, Box ** boxes){
    int i,j,x; // Loop Variable
    int count; //Counter Variable
    int temp; //Temporary Var
    //loop through boxes
    for(i=0; i<9; i++){
        //loop through possible array
        for(j=0; j<9; j++){
            //Trying to keep track of the number times a number appeared in a box
            count = 0;
            //Loop THrough Squares
            for(x = 0; x<9; x++){
                if(boxes[i]->squares[x]->number != 0){
                    continue;
                }
                if(boxes[i]->squares[x]->possible[j] == 0){
                    count++;
                    temp = x;
                }
                if(count==2){//Unsolvable for that Square
                    break;
                }
            }
            if(count==1){   //Its Solvable
                boxes[i]->squares[temp]->number = j+1;
                UNSOLVED--;
                boxes[i]->squares[temp]->solveable = 0;
                
                updateSudoku(sudoku, boxes[i]->squares[temp]->row, boxes[i]->squares[temp]->column);
                
                return 1; //On Success
            }
        }
    }
    return 0; //On Failure
}
/*
 * Box ** vreateBosex()
 *
 * Function to create boxes wile setting up the sudoku puzzle
 * */
Box ** createBoxes()//this function is for alloting memmory of the smaller 3x3 boxes of the puzzle
{
    int x, y;///counter variable
    Box ** boxes;//mallocing everything here
    boxes = malloc(sizeof(Box*)*9);//box->9 as there are 9 boxes in a puzzle

    for (x = 0; x < 9; x++){
        boxes[x] = malloc(sizeof(Box));
        boxes[x]->squares = malloc(sizeof(Square*)*9);//9 square in a box
        boxes[x]->numbers = 0;//and there are 0 numbers in any square of the puzzle at the start
        boxes[x]->solveable = 9;//start this at 9 and then we find a square that is solved and decrement this valuve with respect to a box

        //initializing the possible array
        for (y = 0; y < 9; y++){
            boxes[x]->possible[y] = 0;
        }
    }

    return boxes;
}

/*
 * int updateBoxes
 *
 * Once A square is solved within a box all other
 * */

int updateBoxes(Square *** sudoku, int row, int column)
{
    int x;//counter
    int number = sudoku[row][column]->number;//save the number that we found (either solved it or found one that was already there)
    Box * box;// save which box we are working with
    box = sudoku[row][column]->box;

    for (x = 0; x < 9; x++)
    {
        if (box->squares[x]->possible[number - 1] == 0)
        {
            box->squares[x]->solveable--;//one step closer to finding the solution
            box->squares[x]->possible[number - 1] = 1;//when we get fown to 8 1s and 1 zero in the possible array then we can say we found the solution for the square
        }
    }

}

