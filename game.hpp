#pragma once

#include <map>
#include <unordered_map>
#include <unordered_set>
#include "common.hpp"

void populate_board(int (&board)[BOARD_ROWS][BOARD_COLUMNS]);
void populate_snakes(std::unordered_map<int, int> &snakes, std::unordered_set<int> &banned_pos);
void populate_ladders(std::unordered_map<int, int> &ladders, std::unordered_set<int> &banned_pos);

int get_dice_roll();
void initialize_random_numbers();