#include<iostream>
#include <iomanip>
#include <algorithm>
#include<BoardGame_Classes.hpp>
using namespace std;
X_O_Board_game_2::X_O_Board_game_2() {
    n_rows = 12 ;
    n_cols = 13 ;
    board = new char*[n_rows];
    for ( int i = 0 ; i < 12 ; i++ ){
        board[i] = new char[n_cols] ;
        for ( int j = 0 ; j < 13 ; j++ ){
            board[i][j] = 0 ;
        }
    }
    for (int i = 0; i < 13; ++i) {
        board[9][i]='x';

    }
}

bool X_O_Board_game_2::update_board(int x, int y, char mark) {
     if ( (x >= 0 && x <= 5 && y >= 0 && y <= 6) && (board[x+3][y+3]==0 )) {
            while(board[x + 4][y + 3] ==0){
                x++;
            }
            board[x + 3][y + 3] = mark;
            n_moves++;
            return true;
        }
    else {
        return false;
    }
}

void X_O_Board_game_2::display_board() {
    for (int i = 3 ; i < 9 ; i++ ) {
        cout << "\n| ";
        for (int j = 3 ; j < 10 ; j++ ) {
            if(!board[i][j]){
                cout << "(" << i-3 << "," << j-3 << ")";
                cout << setw(2) << board [i][j] << " |";
            }
            else{
                cout << setw(2) << board [i][j] <<"     "<< " |";
            }

        }
        cout << "\n----------------------------------------------------------------" ;
    }
    cout << '\n' ;
}

bool X_O_Board_game_2::is_winner() {
    for (int i = 3; i < 9 ; ++i) {
        for (int j = 3; j < 10; ++j) {
            if ((board[i][j]!= 0) && (board[i][j] == board[i + 1][j + 1] && board[i][j]== board[i + 2][j + 2] && board[i][j]== board[i + 3][j + 3] )) {
                return true;
            }
            if ((board[i][j]!= 0) && (board[i][j] == board[i + 1][j ] && board[i][j]== board[i + 2][j] && board[i][j] == board[i + 3][j] )) {
                return true;
            }
            if ((board[i][j]!= 0) && (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j]== board[i][j + 3] )) {
                return true;
            }
            if ((board[i][j]!= 0) && (board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] && board[i][j] == board[i + 3][j - 3] )) {
                return true;
            }
        }
    }
    return false;
}

bool X_O_Board_game_2::is_draw() {
    if(n_moves==42 && !is_winner()){
        return true;
    }
    return false;
}

bool X_O_Board_game_2::game_is_over() {
    return (n_moves>=42);
}

int X_O_Board_game_2::win_with(int x, int y) {
    return 0;
}
