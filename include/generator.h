#include <vector>
// Created by Keshav Bhandari on 2/8/24.
//
using namespace std;

#ifndef SUDOKUPROJECT_GENERATOR_H
#define SUDOKUPROJECT_GENERATOR_H
void deleteNumbersRandomly(int** Board, int numToDelete);
void fillBoxRandom(int **Board,int start);
vector<int> shuffle();
int* randArr();
int** generateBoard();
#endif //SUDOKUPROJECT_GENERATOR_H
