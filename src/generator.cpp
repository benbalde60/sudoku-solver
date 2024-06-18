#include <random>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include "../include/sudoku.h"
#include "../include/sudokuio.h"


using namespace std;
// Created by Keshav Bhandari on 2/8/24.

// This function generates a blank 9x9 sudoku board.

//getRandEntry() -> {1,......9}
/*int randIntGenerator(int low, int high) {
    random_device rd;  // Obtain a random number from hardware
    mt19937 eng(rd()); // Seed the generator
    uniform_int_distribution<> distribution(0, 9); // Define the range
    return distribution(eng); // Generate the random number
}

int* randArr(int size, int low, int high) {
    int* arr = new int[size];
    for(int i = 0; i < size; i++)
        arr[i] = randIntGenerator(low, high);
    return arr;
} */
/* this function initializes a vector of 9 int elements from 1 to 9 and shuffles in a random order and then returns the shuffled vector
 */
vector<int> shuffle(){
    vector<int> num = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Seed with a real random value, if available
    random_device rd;

    // Initialize a Mersenne Twister random number generator
    mt19937 g(rd());


    shuffle(num.begin(), num.end(), g);

    return num;

}
/* this function uses the shuffle vector and uses to fill a 3x3 box
 */
void fillBoxRandom(int** BOARD, int start){
    vector<int> num = shuffle();


    for(int i = start; i < start + 3; i++){
        for(int j = start; j < start + 3; j++){
            if (start == 0) {
                BOARD[i][j] = num[(3 * i) + j];
            }
            else if (start == 3){
                BOARD[i][j] = num[(i - 3) * 3 + (j - 3)];
            }
            else if (start == 6){
                BOARD[i][j] = num[(i - 6) * 3 + (j - 6)];
            }
        }
    }
}
/*this function selects random numbers in the row and colum and deletes the number of elements entered for numtoDelete
 */
void deleteNumbersRandomly(int** Board, int numToDelete) {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    int deletedCount = 0;
    while (deletedCount < numToDelete) {
        int row = rand() % 9;    // Generate random row index (0 to 8)
        int col = rand() % 9;    // Generate random column index (0 to 8)

        if (Board[row][col] != 0) {  // Check if the cell is not already empty
            Board[row][col] = 0;     // Set the cell to 0 (or another empty value)
            deletedCount++;          // Increment the count of deleted numbers
        }
    }
}

//fillBoxDiagonally(from [0],to [3]) (then 3-6 and 6-9)

//Then solve board();
  //getRandEntry()-> {1.......9};

  //solveBoard(Board...)
  //randDeleteBoard();

  //return BOARD;


//create function to fill from 0-3, 3-6, 6-9 fillRandomlyFromto([i],[j])
/*this function create a full 2d array that is gonna be our 9x9 board, initializes it and then uses the random shuffle function to fill 3x3 with random numbers diagonally in our 9x9 board and uses the solveBoard function to fill the missing numbers creating a fully filled 9x9 sudoku board
 */
int** generateBoard(){
    // Following initialization is important
    int** BOARD = new int*[9];
    for(int i = 0; i < 9; i++){
        BOARD[i] = new int[9] {0, 0, 0, 0, 0, 0, 0, 0, 0};
    }

    vector<int> shuffledNumbers = shuffle();


//    int** Board = new int*[9];
//    for (int i = 0; i < 9; ++i) {
//        Board[i] = new int[9];
//    }

    // Print the shuffled numbers
    fillBoxRandom(BOARD, 0);
    fillBoxRandom(BOARD, 3);
    fillBoxRandom(BOARD, 6);

    solveBoard(BOARD, 0, 0);

    deleteNumbersRandomly(BOARD, 40);

    for(int i=0;i<9;++i) {
        for(int j=0;j<9;++j) {
            cout << BOARD[i][j];
            cout << " ";
        }
        cout << endl;
    }
return BOARD;

}