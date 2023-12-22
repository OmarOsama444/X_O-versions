#include<iostream>
#include <iomanip>
#include <algorithm>
#include<BoardGame_Classes.hpp>

using namespace std;

X_O_Board_game_3::X_O_Board_game_3() {
    n_rows = n_cols = 5;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

bool X_O_Board_game_3::update_board(int x, int y, char mark) {

    // Only update if move is valid
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    } else
        return false;
}

void X_O_Board_game_3::display_board() {

    for (int i: {0, 1, 2, 3, 4}) {
        cout << "\n| ";
        for (int j: {0, 1, 2, 3, 4}) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board[i][j] << " |";
        }
        cout << "\n__________________________________________";
    }
    cout << endl;

}

bool X_O_Board_game_3::is_winner() {
    if (n_moves == 24) {
        for (int i = 0; i < 3; ++i) { //diagonals wins
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2]) //left diagonal{
                    if (board[i + 2][j + 2] == 'X')
                        x_wins++;
                    else
                        o_wins++;
                if (board[i][j + 2] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j]) //right diagonal
                    if (board[i + 2][j] == 'X')
                        x_wins++;
                    else
                        o_wins++;
            }
        }
        for (int i = 0; i < 5; i++) //rows wins
            for (int j = 0; j < 3; j++)
                if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2]) {
                    if (board[i][j + 2] == 'X')
                        x_wins++;
                    else
                        o_wins++;
                }
        for (int i = 0; i < 3; i++) //columns wins
            for (int j = 0; j < 5; j++) {
                if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j]) {
                    if (board[i + 2][j] == 'X')
                        x_wins++;
                    else
                        o_wins++;
                }
            }
    }
    if (x_wins > o_wins) {
        cout << "X wins congratulations!!!\n";
        cout << "X wins " << x_wins << " times while O wins " << o_wins << "\n";
    } else if (x_wins < o_wins) {
        cout << "O wins congratulations!!!\n";
        cout << "X wins " << x_wins << " times while O wins " << o_wins << " \n";
    }
    return false;
}

bool X_O_Board_game_3::is_draw() {
    if (game_is_over() && x_wins == o_wins)
        return true;
    return false;
}

int X_O_Board_game_3::win_with(int x, int y) {
    return 0;
}

bool X_O_Board_game_3::game_is_over() {
    return n_moves == 24;
}
