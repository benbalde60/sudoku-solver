//
// Created by Keshav Bhandari on 2/7/24.
//

#ifndef SUDOKUPROJECT_SUDOKU_H
#define SUDOKUPROJECT_SUDOKU_H
/*this function will print the board it's fed*/
void printBoard(int**, int, int, int);
/*this function will verify if the board is valid and solvable*/
bool isValid(int**, int, int, int);
/*this function will change the board to fully fill it or solve it*/
bool solveBoard(int**, int, int);
int** generateBoard();
#endif //SUDOKUPROJECT_SUDOKU_H
