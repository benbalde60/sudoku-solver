//
// Created by Keshav Bhandari on 2/7/24.
//
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include "../include/sudokuio.h"
#include "../include/sudoku.h"

/* `sudokuio.cpp`, includes functions to create and initialize data folders, convert Sudoku boards to and
 * from string representations, and write or read boards to and from files. Additionally,
 * it offers utility functions to replace characters in strings, extract numbers from strings using regular expressions,
 * fill boards with numbers from vectors, and validate Sudoku solutions. The file also includes a function to list all
 * Sudoku puzzle files in a specified folder, facilitating comprehensive data handling and validation for Sudoku games. */

using namespace std;
void createFolder(const std::string& folderPath) {
    // Creates a folder if it doesn't exist.
    if (!filesystem::exists(folderPath)) {
        if (filesystem::create_directory(folderPath)) {
            std::cout << "Folder created successfully: " << folderPath << std::endl;
        } else {
            std::cerr << "Failed to create folder: " << folderPath << std::endl;
        }
    } else {
        std::cout << "Folder already exists: " << folderPath << std::endl;
    }
}

void initDataFolder(){
    // Initializes the data folders for puzzles and solutions.

    createFolder("data/");
    createFolder("data/puzzles/");
    createFolder("data/solutions/");
}

void boardToString(int** BOARD, string &content){
    // Converts the Sudoku board to a string representation.
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            string board_piece;

            if (BOARD[i][j] == 0) content += "-";
            else content += to_string(BOARD[i][j]);

            if (j == 2 || j == 5)  content += " | ";
            else content += " ";
        }
        if (i == 2 || i == 5)
        {
            content += "\n";
            for (int l = 0; l < 21; l++) content += ".";
        }
        content += "\n";
    }
}
bool writeSudokuToFile(int** BOARD, const string& filename) {
    // Writes the string representation of the Sudoku board to a file.
    string content;
    boardToString(BOARD, content);
    ofstream outFile(filename); // Open file for writing
    if (outFile.is_open()) {
        outFile << content; // Write content to file
        outFile.close(); // Close the file
        cout << "Content has been written to the file: " << filename << endl;
        return true;
    } else {
        cerr << "Unable to open file: " << filename << endl;
        return false;
    }
}

void replaceCharacter(std::string& str, char oldChar, char newChar) {
    // Replaces characters in a string.
    for (char &ch: str) {
        if (ch == oldChar) {
            ch = newChar;
        }
    }
}

void extractNumbers(const string& input, vector<int>& numbers) {
    // Extracts numbers from a string using regex.

    regex regex("\\d+");

    auto iterator = sregex_iterator(input.begin(), input.end(), regex);
    auto end = sregex_iterator();

    for (; iterator != end; ++iterator) {
        numbers.push_back(stoi(iterator->str()));
    }
}

void fillBoard(const vector<int>& numbers, int **BOARD){
    // Fills the Sudoku board with numbers from a vector.
    for(int i = 0; i < 9; i++) {
        BOARD[i] = new int[9];
        for(int j = 0; j < 9; j++){
            BOARD[i][j] = numbers[i * 9 + j];
        }
    }
}

int** readSudokuFromFile(const string& filename){
    // Reads a Sudoku board from a file and returns it as a 2D array.
    int** BOARD = new int*[9];
    vector<int> numbers;
    string sudoku;

    ifstream file(filename);
    sudoku = string(istreambuf_iterator<char>(file), istreambuf_iterator<char>());

    replaceCharacter(sudoku, '-', '0');
    extractNumbers(sudoku, numbers);
    fillBoard(numbers, BOARD);
    return BOARD;
}

bool checkIfSolutionIsValid(int** BOARD){
    // Checks if the Sudoku solution is valid.
    for(int r = 0; r < 9; r++) {
        for(int c = 0; c < 9; c++) {
            int k = BOARD[r][c];
            BOARD[r][c] = 0;
            if(!isValid(BOARD, r, c, k)){
                BOARD[r][c] = k;
                cout << "!!!!!!!!!!!!!!!! TEST FAILED !!!!!!!!!!!!!!!!" << endl;
                return false;
            }
            BOARD[r][c] = k;
        }
    }
    cout << "--------------- TEST PASSED ---------------" << endl;
    return true;
}

vector<string> getAllSudokuInFolder(const string& folderPath){
    // Retrieves all Sudoku files in a folder.
    vector<std::string> sudokus;
    for (const auto& entry : filesystem::directory_iterator(folderPath)) {
        if (filesystem::is_regular_file(entry)) {
            sudokus.push_back(entry.path().string());
        }
    }
    cout << sudokus.size() << " Sudoku Puzzle found @ " << folderPath << endl;
    cout << setfill('-') << setw(55)<< "" << setfill(' ') <<endl;
    cout << setw(5) << "Index" << setw(50) << "File Name" << endl;
    cout << setfill('-') << setw(55)<< "" << setfill(' ') <<endl;
    for(int i = 0; i < sudokus.size(); i++)
        cout << setw(5) << i << setw(50) << sudokus[i] << endl;
    cout << setfill('-') << setw(55)<< "" << setfill(' ') <<endl;
    return sudokus;
}
