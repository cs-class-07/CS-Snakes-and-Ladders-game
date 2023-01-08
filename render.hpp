#pragma once

#include <unordered_map>
#include "common.hpp"

void draw_board(int (&board)[BOARD_ROWS][BOARD_COLUMNS], std::unordered_map<int, int> &snakes);