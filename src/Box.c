#include "Sudoku.h"

Box ** createBoxes(){ //this function is for alloting memory of the smaller 3x3 boxes of the puzzle
    int x, y; //counter vaiables
    Box ** boxes; //mallocing everything here
    boxes = malloc(sizeof(Box*)*9); // box->9 as there are 9 boxes in a puzzle
    
    for(x=0; x<9; x++){
        boxes[x]=malloc(sizeof(Box));
        boxes[x]->squares = malloc(sizeof(Square*)*9); //9 square in a box
        boxes[x]->numbers = 0; // and there a 0 numbers in any square of the puzzle at the start
        boxes[x]->solveable = 9;// start this at 9 and then when we find a square that is solved decrement this value with respect to a box
        
        //initializing the possible array
        for(y=0; y<9; y++){
            boxes[x]->possible[y] = 0;
        }
    }   

    return boxes;
}

int updateBoxes(Square *** sudoku, int row, int column){
    int x;//counter
    int number = sudoku[row][column]->number; //save the number that we found (either solved it or found one that was already there)
    Box * box; //save which box we are working with
    box = sudoku[row][column]->box;

    for(x=0; x<9; x++){
        if(box->squares[x]->possible[number - 1] == 0){
            box->squares[x]->solveable--; //One step closer to finding the solution
            box->squares[x]->possible[number - 1] = 1;//when we get down to 8 1s and 1 zero in the possible array then we can say we found the solution for the square                                                   
        }
    } 

}
