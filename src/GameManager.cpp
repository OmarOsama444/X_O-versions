// Class definition for XO_GameManager class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include"BoardGame_Classes.hpp"
using namespace std;

GameManager::GameManager( Player* playerPtr[2] , Board* bPtr  ) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

void GameManager::intialize(Board* bPTr ) {
    boardPtr = bPTr ;
}

void GameManager::run() {
    int x, y;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            players[i]->get_move(x, y);
            while (  !boardPtr->update_board (x, y, players[i]->get_symbol())){
                players[i]->get_move(x, y);
            }
            boardPtr->display_board();
            if (boardPtr->is_winner()){
                cout  << players[i]->to_string() << " wins\n";
                return;
            }
            if (boardPtr->is_draw()){
                cout << "Draw!\n";
                return;
            }
        }
    }
}

GameManager::~GameManager() {
    delete boardPtr ;
    delete players[0] ;
    delete players[1] ;
}
