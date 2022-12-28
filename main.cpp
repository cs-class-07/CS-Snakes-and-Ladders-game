#include <iostream>
#include <unordered_map>
#include "common.hpp"
#include "render.hpp"
#include "game.hpp"

using namespace std;

int main() {
    int board[BOARD_ROWS][BOARD_COLUMNS];

    unordered_map<int, int> snakes;
    unordered_map<int, int> ladders;

    populate_board(board);
    draw_board(board);

    return 0;
}