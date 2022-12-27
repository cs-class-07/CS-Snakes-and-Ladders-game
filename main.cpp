#include <iostream>
#include "common.hpp"
#include "render.hpp"

using namespace std;

void populate_board(int (&board)[BOARD_ROWS][BOARD_COLUMNS]) {
    int count = BOARD_ROWS * BOARD_COLUMNS;

    for (int i = 0; i < BOARD_ROWS; i++) {
        for (int j = 0; j < BOARD_COLUMNS; j++) {
            board[i][j] = count;
            count--;
        }

        i++; // Manually increase i by 1
        for (int j = BOARD_COLUMNS - 1; j > -1; j--) { // Count down in reverse
            board[i][j] = count;
            count--;
        }
    }
}

int main() {
    int board[BOARD_ROWS][BOARD_COLUMNS];

    populate_board(board);
    draw_board(board);

    return 0;
}