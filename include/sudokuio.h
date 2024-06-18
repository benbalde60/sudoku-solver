//
// Created by Keshav Bhandari on 2/7/24.
//
#ifndef SUDOKUPROJECT_SUDOKUIO_H
#define SUDOKUPROJECT_SUDOKUIO_H
#include<vector>
using namespace std;
void createFolder(const std::string&);  // Function to create a folder.
void initDataFolder();                  // Function to initialize data folders.
void boardToString(int**, string&);     // Converts the board to a string representation.
bool writeSudokuToFile(int**, const string&);  // Writes the Sudoku board to a file.
void replaceCharacter(string&, char, char);     // Replaces characters in a string.
void extractNumbers(const string&, vector<int>&);  // Extracts numbers from a string.
void fillBoard(const vector<int>&, int**);         // Fills the board with numbers from a vector.
int** readSudokuFromFile(const string&);           // Reads a Sudoku board from a file.
bool checkIfSolutionIsValid(int**);                // Validates the solution of the Sudoku board.
vector<string> getAllSudokuInFolder(const string&);// Retrieves all Sudoku files in a folder.
#endif //SUDOKUPROJECT_SUDOKUIO_H
