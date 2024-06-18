#include <vector>
// Created by Keshav Bhandari on 2/8/24.
//
using namespace std;

#ifndef SUDOKUPROJECT_GENERATOR_H
#define SUDOKUPROJECT_GENERATOR_H
/*this functions deletes a specified number of items randomly in the board
 */
void deleteNumbersRandomly(int** Board, int numToDelete);
/*this function fills a 3x3 boards with random numbers
 */
void fillBoxRandom(int **Board,int start);
/*this function returns an vector containing numbers 1-9 in a random order
 */
vector<int> shuffle();
/*this function will generate and return a fully valid and solvable 9x9 sudoku board*/
int** generateBoard();
#endif //SUDOKUPROJECT_GENERATOR_H
