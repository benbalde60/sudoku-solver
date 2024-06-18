//
// Created by Keshav Bhandari on 2/8/24.
//

#ifndef SUDOKUPROJECT_UTILITY_H
#define SUDOKUPROJECT_UTILITY_H
#include <iostream>
using namespace std;

//Declares utility functions for generating filenames and managing the creation and solving of multiple Sudoku puzzles

string getFileName(int, const string &, const string &);     // Generates a filename based on parameters.
void createAndSaveNPuzzles(const int&, const string&, const string&); // Creates and saves multiple puzzles.
void solveAndSaveNPuzzles(const int &, const string&, const string&, const string&); // Solves and saves multiple puzzles.
#endif //SUDOKUPROJECT_UTILITY_H
