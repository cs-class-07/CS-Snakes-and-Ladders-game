#include <iostream>
#include <unordered_map>
#include "common.hpp"

using namespace std;

const int MAX_LENGTH = to_string(BOARD_CELLS).length();

int compute_row_padding(const int (&board)[BOARD_ROWS][BOARD_COLUMNS], const int i) {
    int char_length = 0; // A variable that will store how many times we have to print the spacing character

    for (int j = 0; j < BOARD_COLUMNS; j++) {
        int length = to_string(board[i][j]).length(); // Grab the length of the number

        char_length += MAX_LENGTH - length; // Add padding spacing
        char_length += length; // Add actual character length

        if (j < BOARD_COLUMNS - 1) char_length += 3;
    }

    char_length += 4;

    return char_length;
}

/**
 * @param length How many times to print the padding character
 * @param type 0 for no corner characters, 1 for down characters, 2 for middle characters, 3 for up characters
*/
void draw_row_padding(const int length, const int type = 0) {
    if (type == 0) {
        for (int i = 0; i < length; i++) {
            cout << "─";
        }
    } else if (type == 1) {
        cout << "┌";
        for (int i = 0; i < length - 2; i++) {
            cout << "─";
        }
        cout << "┐";
    } else if (type == 2) {
        cout << "├";
        for (int i = 0; i < length - 2; i++) {
            cout << "─";
        }
        cout << "┤";
    } else if (type == 3) {
        cout << "└";
        for (int i = 0; i < length - 2; i++) {
            cout << "─";
        }
        cout << "┘";
    }
}

void draw_row(const int (&board)[BOARD_ROWS][BOARD_COLUMNS], const int i) {
    cout << "│ ";

    for (int j = 0; j < BOARD_COLUMNS; j++) {
        for (int k = MAX_LENGTH - to_string(board[i][j]).length(); k > 0; k--) {
            cout << " ";
        }

        cout << board[i][j];

        if (j < BOARD_COLUMNS - 1) cout << " │ ";
    }

    cout << " │";
}

void draw_features_row(const int (&board)[BOARD_ROWS][BOARD_COLUMNS], unordered_map<int, int> &snakes, unordered_map<int, int> &ladders, const int i) {
    cout << "│";

    for (int j = 0; j < BOARD_COLUMNS; j++) {
        unordered_map<int, int>::iterator snakes_iter = snakes.find(board[i][j]); // See https://stackoverflow.com/a/25144953/12496724, this also avoids a second lookup
        unordered_map<int, int>::iterator ladders_iter = ladders.find(board[i][j]);

        if (snakes_iter != snakes.end()) { // Use C++ iterator to check that the returned iterator isn't non-existent. Remember, the iterator returned by find() will be equal to that of the one returned by the end() method if nothing is found
            cout << "S"; // Print to stdout that this is a snake

            for (int k = MAX_LENGTH - to_string(snakes_iter->second).length(); k > 0; k--) { // Calculate needed padding for the number
                cout << " ";
            }

            cout << snakes_iter->second; // Print the number to which falling on that cell would bring you to
        } else if (ladders_iter != ladders.end()) {
            cout << "L";

            for (int k = MAX_LENGTH - to_string(ladders_iter->second).length(); k > 0; k--) {
                cout << " ";
            }

            cout << ladders_iter->second;
        } else {
            cout << " "; // Extra space to account for the spaces not printed in case of a feature

            for (int k = 0; k < MAX_LENGTH; k++) {
                cout << " ";
            }
        }

        if (j < BOARD_COLUMNS - 1) cout << " │";
    }

    cout << " │";
}

void draw_players_row(const int (&board)[BOARD_ROWS][BOARD_COLUMNS], const int (&players_pos)[PLAYERS_LENGTH], const int i) {
    cout << "│ ";

    for (int j = 0; j < BOARD_COLUMNS; j++) {
        int players_printed_count = 0;

        for (int k = 0; k < PLAYERS_LENGTH && players_printed_count <= MAX_LENGTH; k++) {
            if (players_pos[k] == board[i][j]) {
                if (players_printed_count < MAX_LENGTH) cout << (char)('A' + k);
                players_printed_count++; // Allow it to count up once more
            }
        }

        for (int k = MAX_LENGTH - players_printed_count; k > 0; k--) { // Calculate needed padding for the number
            cout << " ";
        }

        if (players_printed_count + 1 > MAX_LENGTH) cout << "+"; // Print a plus to indicate that there are more players on this cell
        else cout << " ";

        if (j < BOARD_COLUMNS - 1) cout << "│ ";
    }

    cout << "│";
}

void draw_board(const int (&board)[BOARD_ROWS][BOARD_COLUMNS], unordered_map<int, int> &snakes, unordered_map<int, int> &ladders, const int (&players_pos)[PLAYERS_LENGTH]) {
    int row_length = compute_row_padding(board, 0);

    draw_row_padding(row_length, 1);
    
    for (int i = 0; i < BOARD_ROWS; i++) {
        if (i > 0) draw_row_padding(row_length, 2);
        cout << endl;

        draw_players_row(board, players_pos, i);
        cout << endl;

        draw_row(board, i);
        cout << endl;

        draw_features_row(board, snakes, ladders, i);
        cout << endl;
    }

    draw_row_padding(row_length, 3);
    cout << endl;
}