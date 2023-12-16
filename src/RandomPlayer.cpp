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
RandomPlayer::RandomPlayer (char symbol, int dimension , Board* brd ):
    Player(symbol) , brd(brd) {
    this->dimension = dimension;
    this->name = "Random Computer Player";
    cout << "My names is " << name << endl;
}

// Generate a random move
void RandomPlayer::get_move (int& x, int& y) {
    int mv = -1 ;
    for ( int i = 0 ; i < dimension ; i++ ){
        for ( int j = 0 ; j < dimension ; j++ ){
            if ( brd->win_with( i , j ) > mv ){
                x = i , y = j ;
                mv = brd->win_with( i , j ) ;
            }
        }
    }
}
