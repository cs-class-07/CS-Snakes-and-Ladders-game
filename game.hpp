#pragma once

#include <map>
#include <unordered_map>
#include "common.hpp"

void populate_board(int (&board)[BOARD_ROWS][BOARD_COLUMNS]);
void populate_snakes(std::unordered_map<int, int> &snakes);