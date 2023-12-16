#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.hpp"

RandomPlayer_game_2::RandomPlayer_game_2 (char symbol, int dimension1,int dimension2, Board* brd ):
        Player(symbol) , brd(brd) {
    this->dimension1 = dimension1;
    this->dimension2 = dimension2;
    this->name = "Pyramid Computer Player";
    cout << "My names is " << name << endl;
}
void RandomPlayer_game_2::get_move (int& x, int& y) {
    int mv = -1 ;
    for (int i = 0; i < 6 ; ++i) {
        for (int j = 0; j < 7; ++j){
            if ( brd->win_with( i , j ) >= mv ){
                x = i , y = j ;
                mv = brd->win_with( i , j ) ;
            }
        }
    }
}
