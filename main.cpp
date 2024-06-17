#include <iostream>
#include "include/generator.h"
#include "include/sudoku.h"
#include "include/sudokuio.h"
#include "include/utility.h"

string PATH_TO_PUZZLES = "data/puzzles/";
string PATH_TO_SOLUTIONS = "data/solutions/";

string PUZZLE_PREFIX = "PUZZLE";
string SOLUTION_PREFIX = "SOLUTION";

int NUM_PUZZLE_TO_GENERATE = 10;

using namespace std;

int main() {
    initDataFolder();
    createAndSaveNPuzzles(NUM_PUZZLE_TO_GENERATE, PATH_TO_PUZZLES, PUZZLE_PREFIX);
    solveAndSaveNPuzzles(NUM_PUZZLE_TO_GENERATE, PATH_TO_PUZZLES, PATH_TO_SOLUTIONS, SOLUTION_PREFIX);

/*
    vector<int> shuffledNumbers = shuffle();


    int** Board = new int*[9];
    for (int i = 0; i < 9; ++i) {
        Board[i] = new int[9];
    }

    // Print the shuffled numbers
    fillBoxRandom(Board, 0);
    fillBoxRandom(Board, 3);
    fillBoxRandom(Board, 6);

    solveBoard(Board, 0, 0);

    deleteNumbersRandomly(Board, 40);

   for(int i=0;i<9;++i) {
       for(int j=0;j<9;++j) {
           cout << Board[i][j];
           cout << " ";
       }
       cout << endl;
   }

*/


    return 0;

}
