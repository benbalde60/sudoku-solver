//
// Created by Keshav Bhandari on 2/8/24.
//

#ifndef SUDOKUPROJECT_UTILITY_H
#define SUDOKUPROJECT_UTILITY_H
#include <iostream>
using namespace std;
string getFileName(int, const string &, const string &);
void createAndSaveNPuzzles(const int&, const string&, const string&);
void solveAndSaveNPuzzles(const int &, const string&, const string&, const string&);
#endif //SUDOKUPROJECT_UTILITY_H
