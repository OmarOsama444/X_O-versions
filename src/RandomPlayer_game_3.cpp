// Class definition for XO_RandomPlayer class
// Which is a computer player playing randomly
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1
#include<iostream>
#include<random>
#include<iomanip>
#include<algorithm>
#include"BoardGame_Classes.hpp"
using namespace std;

// Set player symbol and name as Random Computer Player
RandomPlayer_game_3::RandomPlayer_game_3( char symbol, int dimension  ):
        Player(symbol) , dimension(dimension) {
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
void RandomPlayer_game_3::get_move (int& x, int& y) {
    x = rand() % 5 ;
    y = rand() % 5 ;
}
