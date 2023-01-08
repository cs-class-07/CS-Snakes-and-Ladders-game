#include <unordered_map>
#include <ctime>
#include <cstdlib>
#include "common.hpp"

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

void populate_snakes(unordered_map<int, int> &snakes) {
    srand(time(0));

    for (int i = 0; i < SINGLE_FEATURES_LENGTH; i++) {
        int random_pos = (rand() % (BOARD_CELLS - BOARD_ROWS * 3)) + BOARD_ROWS * 3;
        int length = rand() % BOARD_ROWS * 4;

        while (random_pos - length < 0 && !snakes.contains(random_pos)) {
            int random_pos = (rand() % (BOARD_CELLS - BOARD_ROWS * 3)) + BOARD_ROWS * 3;
            int length = rand() % BOARD_ROWS * 4;
        }

        snakes.insert({ random_pos, length });
    }
}