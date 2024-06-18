//
// Created by Keshav Bhandari on 2/7/24.
//
#include "../include/sudoku.h"
#include <iostream>
using namespace std;
/*this function takes the board,the row,and colum as an input and prints the board
 */
void printBoard(int** BOARD, int r, int c, int k)
{
    if(BOARD[r][c]>0) k = 0;
    
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            string board_piece;
            if (BOARD[i][j] == 0) board_piece = "\x1B[93m-\x1B[0m"; // Yellow
            else board_piece = to_string(BOARD[i][j]); // White
            if ((i == r && j == c) && k != 0)
            {
                if (isValid(BOARD, r, c, k))
                    board_piece = "\x1B[32m" + to_string(k) + "\x1B[0m"; // Green
                else
                    board_piece = "\x1B[31m" + to_string(k) + "\x1B[0m"; // Red
            }
            cout << board_piece;
            if (j == 2 || j == 5) cout << " | ";
            else cout << " ";
        }
        if (i == 2 || i == 5)
        {
            cout << endl;
            for (int l = 0; l < 21; l++) cout << ".";
        }
        cout << endl;
    }
}
/*this function is used to verify wether or not the board is a valid and solvable sudoku board
 */
bool isValid(int** BOARD, int r, int c, int k)
{
    for (int i = 0; i < 9; i++)
    {
        if (k == BOARD[r][i] || k == BOARD[i][c])
            return false;
    }

    for (int i = 3 * (r / 3); i < 3 * (r / 3) + 3; i++)
    {
        for (int j = 3 * (c / 3); j < 3 * (c / 3) + 3; j++)
        {
            if (k == BOARD[i][j])
                return false;
        }
    }
    return true;
}
/*this function recursively goes throught the board it's fed and solves it
 */
bool solveBoard(int** BOARD, int r, int c){
    if(r == 9)
        return true;
    else if(c == 9)
        return solveBoard(BOARD, r+1, 0);
    else if(BOARD[r][c] != 0)
        return solveBoard(BOARD, r, c+1);
    else{
        for(int k=1; k<10; k++){
            if(isValid(BOARD, r, c, k)){
                BOARD[r][c] = k;
                if(solveBoard(BOARD, r, c+1))
                    return true;
                else
                    BOARD[r][c] = 0;
            }
        }
        return false;
    }
}