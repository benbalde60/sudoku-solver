#include <random>
#include <iomanip>

using namespace std;
// Created by Keshav Bhandari on 2/8/24.

// This function generates a blank 9x9 sudoku board.

//getRandEntry() -> {1,......9}
int randIntGenerator(int low, int high) {
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
}

//fillBoxDiagonally(from [0],to [3]) (then 3-6 and 6-9)

//Then solve board();
  //getRandEntry();

  //solveBoard(Board...)
  //randDeleteBoard();

  //return BOARD;


//create function to fill from 0-3, 3-6, 6-9 fillRandomlyFromto([i],[j])

int** generateBoard(){
    // Following initialization is important
    int** BOARD = new int*[9];
    for(int i = 0; i < 9; i++){
        BOARD[i] = new int[9] {0, 0, 0, 0, 0, 0, 0, 0, 0};
    }//Initialization ends here

Will



main

}