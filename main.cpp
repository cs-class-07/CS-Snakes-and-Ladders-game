#include <iostream>

#define BOARD_ROWS 6
#define BOARD_COLUMNS 6

using namespace std;

void populate_board(int (&board)[10][10]) {

}

void draw_row(int (&board)[BOARD_ROWS][BOARD_COLUMNS], const int &i, const int &j1, int count, bool reverse = false) {
    for (int k = 3 - to_string(count).length(); k > 0; k--) { // Print initial spacing if needed
    // Could be optimized using maths but a simple to_string() call is easier
        cout << " ";
    }

    if (!reverse) {
        for (int j = 0; j < j1; j++) {
            board[i][j] = count;
            count--;

            cout << board[i][j];
            
            if (j < j1 - 1) {
                cout << " || ";
            }

            for (int k = 3 - to_string(count).length(); k > 0; k--) {
                cout << " ";
            }
        }
    } else {
        for (int j = j1; j > 0; j--) {
            board[i][j] = count; // Populate board
            count++;

            cout << board[i][j]; // Print number

            if (j > 1) { // Check to not print the column divider at the end
                cout << " || ";
            }

            for (int k = 3 - to_string(count).length(); k > 0; k--) { // Print spacing based on chracter length
                cout << " ";
            }
        }
    }
}

void draw_board(int (&board)[BOARD_ROWS][BOARD_COLUMNS], int i1, int j1) {
    int count = BOARD_ROWS * BOARD_COLUMNS;

    int i2 = i1 / 2; // Half the board count to account also for reversed board rows

    for (int i = 0; i < i2; i++) {
        draw_row(board, i, j1, count);
        count -= j1;
        cout << endl;

        count -= j1;
        draw_row(board, i, j1, count + 1, true);
        cout << endl;
    }

    // if (i2 % 2 != 0) {
    //     count -= j1;
    //     draw_row(board, i, j1, count + 1, true);
    //     cout << endl;
    // }
}

int main() {
    int board[BOARD_ROWS][BOARD_COLUMNS];

    draw_board(board, BOARD_ROWS, BOARD_COLUMNS);

    return 0;
}