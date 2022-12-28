#include <iostream>
#include "common.hpp"

using namespace std;

const int MAX_LENGTH = to_string(BOARD_ROWS * BOARD_COLUMNS).length();

int compute_row_padding(int (&board)[BOARD_ROWS][BOARD_COLUMNS], const int &i) {
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

int computer_column_padding(int (&board)[BOARD_ROWS][BOARD_COLUMNS], const int &i, const int &j) {
    int char_length = 0; // A variable that will store how many times we have to print the space

    int length = to_string(board[i][j]).length(); // Grab the length of the number

    char_length += MAX_LENGTH - length; // Add padding spacing
    char_length += length; // Add actual character length

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

void draw_column_padding(const int length, const int times) {
    cout << "│ ";

    for (int i = 0; i < times; i++) {
        for (int j = 0; j < length; j++) {
            cout << " ";
        }
        if (i < BOARD_COLUMNS - 1) cout << " │ ";
    }

    cout << " │";
}

void draw_row(int (&board)[BOARD_ROWS][BOARD_COLUMNS], const int &i) {
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

void draw_board(int (&board)[BOARD_ROWS][BOARD_COLUMNS]) {
    int row_length = compute_row_padding(board, 0);
    int col_length = computer_column_padding(board, 0, 0);

    draw_row_padding(row_length, 1);
    
    for (int i = 0; i < BOARD_ROWS; i++) {
        if (i > 0) draw_row_padding(row_length, 2);
        cout << endl;

        draw_column_padding(col_length, BOARD_COLUMNS);
        cout << endl;

        draw_row(board, i);
        cout << endl;

        draw_column_padding(col_length, BOARD_COLUMNS);
        cout << endl;
    }

    draw_row_padding(row_length, 3);
    cout << endl;

    cout << "Finished!" << endl;
}