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
    populate_snakes(snakes);
    draw_board(board, snakes);

    // for (auto const& [key, val] : snakes) { // See https://stackoverflow.com/a/26282004/12496724
    //     cout << "Snake Start: " << key << "  Snake End: " << val << endl;
    // }

    return 0;
}