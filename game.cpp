#include <unordered_map>
#include <unordered_set>
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

void populate_snakes(unordered_map<int, int> &snakes, unordered_set<int> &banned_pos) {
    srand(time(0));

    for (int i = 0; i < SINGLE_FEATURES_LENGTH; i++) {
        int random_pos = (rand() % (BOARD_CELLS - BOARD_ROWS * 3 - 1)) + BOARD_ROWS * 3; // Do not add + 1 to avoid getting a random_pos of 100
        int length = rand() % BOARD_ROWS * 3 + BOARD_ROWS;

        while (random_pos - length < 1 || banned_pos.contains(random_pos) || banned_pos.contains(random_pos - length)) {
            random_pos = (rand() % (BOARD_CELLS - BOARD_ROWS * 3 - 1)) + BOARD_ROWS * 3;
            length = rand() % BOARD_ROWS * 3 + BOARD_ROWS;
        }

        snakes.insert({ random_pos, random_pos - length });
        banned_pos.insert(random_pos);
        banned_pos.insert(random_pos - length);
    }
}

void populate_ladders(unordered_map<int, int> &ladders, unordered_set<int> &banned_pos) {
    srand(time(0));

    for (int i = 0; i < SINGLE_FEATURES_LENGTH; i++) {
        int random_pos = (rand() % (BOARD_CELLS - BOARD_ROWS * 3 - 1)) + 1;
        int length = rand() % BOARD_ROWS * 3 + BOARD_ROWS;

        while (random_pos + length > 100 || banned_pos.contains(random_pos) || banned_pos.contains(random_pos + length)) {
            random_pos = (rand() % (BOARD_CELLS - BOARD_ROWS * 3 - 1)) + 1;
            length = rand() % BOARD_ROWS * 3 + BOARD_ROWS;
        }

        ladders.insert({ random_pos, random_pos + length });
        banned_pos.insert(random_pos);
        banned_pos.insert(random_pos + length);
    }
}