//
// Created by Keshav Bhandari on 2/8/24.

// This function generates a 9x9 static sudoku board.

int** generateBoard(){
    // Following initialization is important
    int** BOARD = new int*[9];
    for(int i = 0; i < 9; i++){
        BOARD[i] = new int[9] {0, 0, 0, 0, 0, 0, 0, 0, 0};
    }//Initialization ends here

    // Guys following are the things to do
    /*
     * 1. Create a randomnumber generator
     * ....*/

    BOARD[0] = new int[9] {0, 0, 4, 0, 5, 0, 0, 0, 0};
    BOARD[1] = new int[9] {9, 0, 0, 7, 3, 4, 6, 0, 0};
    BOARD[2] = new int[9] {0, 0, 3, 0, 2, 1, 0, 4, 9};
    BOARD[3] = new int[9] {0, 3, 5, 0, 9, 0, 4, 8, 0};
    BOARD[4] = new int[9] {0, 9, 0, 0, 0, 0, 0, 3, 0};
    BOARD[5] = new int[9] {0, 7, 6, 0, 1, 0, 9, 2, 0};
    BOARD[6] = new int[9] {3, 1, 0, 9, 7, 0, 2, 0, 0};
    BOARD[7] = new int[9] {0, 0, 9, 1, 8, 2, 0, 0, 3};
    BOARD[8] = new int[9] {0, 0, 0, 0, 6, 0, 1, 0, 0};
    return BOARD;
}