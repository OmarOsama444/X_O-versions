#include <iostream>
#include"BoardGame_Classes.hpp"
using namespace std;

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'X');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;

    if ( choice != 1 ){
        players[1] = new Player( 2 , 'O' ) ;
    }

    cout << "Choose whih game to play :\n" ;
    cout << "1) normal 3x3 XO boring game -_-\n" ;
    cout << "2) pyramid Tic-Tac-Toe \n" ;
    cout << "3) Four-in-a-row \n" ;
    cout << "4) 5 x 5 Tic Tac Toe \n" ;
    int chc ; cin >> chc ;

    Board* brd ;

    if ( chc == 1 ) {
        brd = new X_O_Board();
        if (choice == 1) {
            players[1] = new RandomPlayer('O', 3 , brd);
        }
        GameManager( brd , players ).run() ;
    } else if ( chc == 2 ) {
        brd = new X_O_Board_game_1() ;
        if ( choice == 1 )
            players[1] = new RandomPlayer_game_1( 'O' , 3 , 5 , brd ) ;
        GameManager( brd , players ).run() ;
    } else if ( chc == 3 ) {
        brd = new X_O_Board_game_2();
        if ( choice == 1 )
            players[1] = new RandomPlayer_game_2( 'O' , 6 , 7 , brd ) ;
        GameManager( brd , players ).run() ;
    } else if (chc == 4) {
        brd = new X_O_Board_game_3() ;
        if ( choice == 1 )
            players[1] = new RandomPlayer_game_3( 'O', 5 );
        GameManager( brd , players).run() ;
    } else {
        cout << "INVALID CHOICE \n" ;
        system("pause") ;
    }

    system ("pause");
}