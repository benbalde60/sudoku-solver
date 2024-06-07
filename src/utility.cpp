//
// Created by Keshav Bhandari on 2/8/24.
//
#include <iostream>
#include <string>
#include <vector>
#include "../include/generator.h"
#include "../include/sudokuio.h"
#include "../include/sudoku.h"
using namespace std;
string getFileName(int index, const string &destination, const string &prefix){
    string index_str = to_string(index);
    string index_fill = string(4 - index_str.length(), '0');
    string filename = destination + index_fill + index_str + prefix + ".txt";
    return filename;
}
void createAndSaveNPuzzles(const int& num_puzzles, const string& destination, const string& prefix){
    int total_success = 0;
    for(int i=0; i < num_puzzles; i++){
        int** BOARD = generateBoard();
        string filename = getFileName(i, destination, prefix);
        if(writeSudokuToFile(BOARD, filename)){
            total_success++;
            cout << "Successfully written(" << filename << ") "<< total_success << "of " << num_puzzles << endl;
        }else{
            cout << "!! Failed to write(" << filename << ") "<< total_success << "of " << num_puzzles << endl;
        }
    }
    cout << total_success << " files written out of " << num_puzzles <<endl;
}

void solveAndSaveNPuzzles(const int &num_puzzles, const string& source, const string& destination, const string& prefix){
    int total_success_solve = 0;
    int total_success_write = 0;
    vector<string> path_to_sudokus = getAllSudokuInFolder(source);

    cout << "Number of loaded puzzles:" << path_to_sudokus.size() << "/" << num_puzzles << endl;
    for(int i = 0; i < path_to_sudokus.size(); i++){
        int** sudoku = readSudokuFromFile(path_to_sudokus[i]);
        if(solveBoard(sudoku, 0, 0)){
            if(checkIfSolutionIsValid(sudoku)){
                total_success_solve++;
                string filename = getFileName(i, destination, prefix);
                cout << "Puzzle Solved(over available): " << total_success_solve << "/" << path_to_sudokus.size() << " | ";
                cout << "Puzzle Solved(over total): " << total_success_solve << "/" << num_puzzles << endl;
                if(writeSudokuToFile(sudoku, filename)){
                    total_success_write++;
                }
                cout << "Puzzle Solved Written(over available): " << total_success_write << "/" << path_to_sudokus.size() << " | ";
                cout << "Puzzle Solved Written(over total): " << total_success_write << "/" << num_puzzles << endl;
            }
        }
    }
}
