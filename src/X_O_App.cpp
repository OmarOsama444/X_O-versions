// Class definition for XO_App class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include"BoardGame_Classes.hpp"
using namespace std;

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 3);

    cout << "Choose whih game to play :\n" ;
    cout << "1) normal 3x3 XO boring game -_-\n" ;
    cout << "2) pyramid Tic-Tac-Toe \n" ;
    cout << "3) Four-in-a-row \n" ;
    cout << "4) 5 x 5 Tic Tac Toe \n" ;
    int chc ; cin >> chc ;
    GameManager x_o_game (players);
    switch ( chc ) {
        case 1 :
            x_o_game.intialize(new X_O_Board() ) ;
            break;
        case 2 :
            x_o_game.intialize(new X_O_Board_game_1() ) ;
            break;
        case 3 :
            break;
        case 4 :
            break;
    }

    x_o_game.run();
    system ("pause");
}
