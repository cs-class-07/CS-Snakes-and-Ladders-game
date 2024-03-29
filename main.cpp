#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <chrono>
#include <thread>
#include "common.hpp"
#include "render.hpp"
#include "game.hpp"

using namespace std;
using namespace this_thread;
using namespace chrono_literals;

int main() {
    int board[BOARD_ROWS][BOARD_COLUMNS];

    unordered_map<int, int> snakes;
    unordered_map<int, int> ladders;
    unordered_set<int> banned_pos;
    int players_pos[PLAYERS_LENGTH];

    memset(players_pos, 0, PLAYERS_LENGTH*sizeof(players_pos[0])); // Memset everything to 0, setting 1 will result in 0x01010101 as memset works on a byte by byte basis and int is 4 bytes long

    for (int i = 0; i < PLAYERS_LENGTH; i++) {
        players_pos[i] += 1;
    }

    initialize_random_numbers();

    populate_board(board);
    populate_snakes(snakes, banned_pos);
    populate_ladders(ladders, banned_pos);
    draw_board(board, snakes, ladders, players_pos);

    int winning_player = -1;

    while (winning_player < 0) {
        for (int i = 0; i < PLAYERS_LENGTH; i++) {
            cout << "Playing Player " << (char)('A' + i) << "'s turn";
            
            cout << "..." << endl;
            sleep_for(3s);

            int random_dice_roll = get_dice_roll();
            cout << "Player " << (char)('A' + i) << " rolled a " << random_dice_roll;

            cout << "..." << endl;
            sleep_for(3s);

            players_pos[i] += random_dice_roll;

            cout << "The player now advances to " << players_pos[i];

            cout << "..." << endl;
            sleep_for(3s);

            unordered_map<int, int>::iterator snakes_iter = snakes.find(players_pos[i]);
            unordered_map<int, int>::iterator ladders_iter = ladders.find(players_pos[i]);

            if (snakes_iter != snakes.end()) {
                cout << "Oh No! Player " << (char)('A' + i) << " landed on a Snake. Player " << (char)('A' + i) << " slides to " << snakes_iter->second;

                players_pos[i] = snakes_iter->second;

                cout << "..." << endl;
                sleep_for(3s);
            } else if (ladders_iter != ladders.end()) {
                cout << "Player " << (char)('A' + i) << " landed on a Ladder! Player " << (char)('A' + i) << " climbs to " << ladders_iter->second;

                players_pos[i] = ladders_iter->second;

                cout << "..." << endl;
                sleep_for(3s);
            } else if (players_pos[i] >= BOARD_CELLS) {
                winning_player = i;
                break;
            }

            cout << endl << endl << endl << "\033c"; // Print 3 newlines in case stdout is being redirected to something like a file, where character \033c may not be interpreted correctly

            draw_board(board, snakes, ladders, players_pos);
        }
    }
    
    cout << "Player " << (char)('A' + winning_player) << " has won the game!" << endl;

    return 0;
}