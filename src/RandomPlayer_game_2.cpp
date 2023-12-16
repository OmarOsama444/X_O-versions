#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.hpp"

RandomPlayer_game_2::RandomPlayer_game_2 (char symbol, int dimension1 , int dimension2  )
    : Player(symbol) , dimension1( dimension1 ) , dimension2( dimension2 ) {
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
void RandomPlayer_game_2::get_move (int& x, int& y) {
    x = rand() % dimension1 ;
    y = rand() % dimension2 ;
}
