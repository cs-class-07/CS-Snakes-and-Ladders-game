#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include "common.hpp"
#include "render.hpp"
#include "game.hpp"

using namespace std;

int main() {
    int board[BOARD_ROWS][BOARD_COLUMNS];

    unordered_map<int, int> snakes;
    unordered_map<int, int> ladders;
    unordered_set<int> banned_pos;
    int player_pos[PLAYERS_LENGTH];

    memset(player_pos, 1, PLAYERS_LENGTH);

    populate_board(board);
    populate_snakes(snakes, banned_pos);
    populate_ladders(ladders, banned_pos);
    draw_board(board, snakes, ladders, player_pos);

    // for (auto const& [key, val] : snakes) { // See https://stackoverflow.com/a/26282004/12496724
    //     cout << "Snake Start: " << key << "  Snake End: " << val << endl;
    // }

    return 0;
}