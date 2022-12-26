#include <iostream>

#define BOARD_ROWS 4
#define BOARD_COLUMNS 4

using namespace std;

void populate_board(int (&board)[BOARD_ROWS][BOARD_COLUMNS]) {
    int count = BOARD_ROWS * BOARD_COLUMNS;

    for (int i = 0; i < BOARD_ROWS; i++) {
        for (int j = 0; j < BOARD_COLUMNS; j++) {
            board[i][j] = count;
            count--;
        }

        i++; // Manually increase i by 1
        for (int j = BOARD_COLUMNS - 1; j > -1; j--) { // Count down in reverse
            board[i][j] = count;
            count--;
        }
    }
}

void draw_row(int (&board)[BOARD_ROWS][BOARD_COLUMNS], const int &i) {
    for (int j = 0; j < BOARD_COLUMNS; j++) {
        int char_length = 0;
        int length = to_string(board[i][j]).length();
        char_length += 3 - length;
        char_length += length;
        if (j < BOARD_COLUMNS - 1) char_length += 4;
        for (int k = 0; k < char_length; k++) {
            cout << "=";
        }
    }

    cout << endl;

    for (int j = 0; j < BOARD_COLUMNS; j++) {
        for (int k = 3 - to_string(board[i][j]).length(); k > 0; k--) {
            cout << " ";
        }

        cout << board[i][j];
        
        if (j < BOARD_COLUMNS - 1) {
            cout << " || ";
        }
    }
}

void draw_board(int (&board)[BOARD_ROWS][BOARD_COLUMNS]) {
    for (int i = 0; i < BOARD_ROWS; i++) {
        draw_row(board, i);
        cout << endl;
    }

    cout << "Finished!" << endl;
}

int main() {
    int board[BOARD_ROWS][BOARD_COLUMNS];

    populate_board(board);
    draw_board(board);

    return 0;
}