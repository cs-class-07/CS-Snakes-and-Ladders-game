#pragma once

#include <unordered_map>
#include "common.hpp"

void draw_board(const int (&board)[BOARD_ROWS][BOARD_COLUMNS], std::unordered_map<int, int> &snakes, std::unordered_map<int, int> &ladders, const int (&players_pos)[PLAYERS_LENGTH]);