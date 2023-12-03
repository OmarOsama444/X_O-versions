
#include<iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include<BoardGame_Classes.hpp>

X_O_Board_game_1::X_O_Board_game_1() {
    n_rows = 3 ;
    n_cols = 5 ;
    board = new char*[n_rows] ;
    for ( int i = 0 ; i < 3 ; i++ ){
        board[i] = new char[n_cols] ;
        for ( int j = 0 ; j < 5 ; j++ ){
            board[i][j] = 0 ;
        }
    }
}

bool X_O_Board_game_1::update_board ( int x , int y , char mark ){
    switch ( x ) {
        case 0 :
            if ( y == 2 ){
                board[x][y] = mark ;
                n_moves++ ;
                return true ;
            } else
                return false ;
            break;
        case 1 :
            if ( y >= 1 && y <= 3 ){
                board[x][y] = mark ;
                n_moves++ ;
                return true ;
            } else
                return false ;
            break;
        case 2 :
            if ( y >= 0 && y <= 4  ){
                board[x][y] = mark ;
                n_moves++ ;
                return true ;
            } else
                return false ;
            break;
        default:
            return false ;
    }
}

void X_O_Board_game_1::display_board() {
    for (int i = 0 ; i < 3 ; i++ ) {
        cout << "\n| ";
        for (int j = 0 ; j < 5 ; j++ ) {
            cout << "(" << i << "," << j << ")";
            cout << setw(2) << board [i][j] << " |";
        }
        cout << "\n-----------------------------" ;
    }
    cout << '\n' ;
}

bool X_O_Board_game_1::is_winner() {
    for ( int i = 0 ; i < 3 ; i++ ){
        if ( board[2][i] == board[2][i+1] && board[2][i+1] == board[2][i+2] && board[2][i+1] ) {
            return true ;
        }
    }
    if ( board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] ){
        return true ;
    }
    if ( board[0][2] == board[1][3] && board[1][3] == board[2][4] && board[0][2] ){
        return true ;
    }
    if ( board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] ){
        return true ;
    }
    return false ;
}

bool X_O_Board_game_1::is_draw() {
    return ( n_moves == 9 && !is_winner() ) ;
}

bool X_O_Board_game_1::game_is_over() {
    return ( n_moves >= 9 ) ;
}
