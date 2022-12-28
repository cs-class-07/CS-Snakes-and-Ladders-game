#pragma once

#include <map>
#include "common.hpp"

void populate_board(int (&board)[BOARD_ROWS][BOARD_COLUMNS]);
void populate_snakes(unordered_map<int, int> &snakes);