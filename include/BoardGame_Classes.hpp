#ifndef BoardGame_CLASSES_H
#define BoardGame_CLASSES_H
#include <iostream>
using namespace std;

class Board {
protected:
   int n_rows, n_cols;
   int  n_moves = 0;
   char** board;
public:
   virtual bool update_board (int x, int y, char symbol) = 0;
   virtual bool is_winner() = 0;
   virtual bool is_draw() = 0;
   virtual void display_board() = 0;
   virtual bool game_is_over() = 0;
   virtual int win_with(  int x , int y ) = 0 ;
   virtual ~Board() = default ;
};

class X_O_Board:public Board {
public:
   X_O_Board ();
   bool update_board (int x, int y, char mark) override ;
   void display_board() override ;
   bool is_winner() override ;
   bool is_draw() override ;
   bool game_is_over() override ;
   int win_with(  int x , int y ) override ;
};

class X_O_Board_game_1 : public Board {
public:
    X_O_Board_game_1() ;
    bool update_board ( int x , int y , char mark ) override ;
    void display_board() override ;
    bool is_winner() override ;
    bool is_draw() override ;
    bool game_is_over() override ;
    int win_with( int x , int y ) override ;
};

class X_O_Board_game_2 : public Board {
public:
    X_O_Board_game_2() ;
    bool update_board ( int x , int y , char mark ) override ;
    void display_board() override ;
    bool is_winner() override ;
    bool is_draw() override ;
    bool game_is_over() override ;
    int win_with( int x , int y ) ;
};

class X_O_Board_game_3 : public Board {
public:
    X_O_Board_game_3() ;
    bool update_board ( int x , int y , char mark ) override ;
    void display_board() override ;
    bool is_winner() override ;
    bool is_draw() override ;
    bool game_is_over() override ;
    int win_with( int x , int y )override;
private:
    int x_wins = 0, o_wins = 0;
};

class Player {
    protected:
        string name;
        char symbol;
    public:
        Player (char symbol);
        Player (int order, char symbol);
        virtual void get_move(int& x, int& y);
        string to_string();
        char get_symbol();
};

class RandomPlayer: public Player {
    protected:
        int dimension;
        int chc {} ;
        Board* brd = nullptr ;
    public:
        RandomPlayer (char symbol, int dimension , Board* brd );
        void get_move( int& x, int& y ) override ;
};


class RandomPlayer_game_1 : public Player {
    protected:
        int dimension1 {} ;
        int dimension2 {} ;
        Board* brd = nullptr ; 
    public:
        RandomPlayer_game_1( char symbol , int dimension1 , int dimension2 , Board* brd ) ;
        virtual void get_move( int&x , int&y ) override ;
};


class RandomPlayer_game_2 : public Player {
protected:
    int dimension1 {} ;
    int dimension2 {} ;
    Board* brd = nullptr ;
public:
    RandomPlayer_game_2( char symbol , int dimension1 , int dimension2 , Board* brd ) ;
    virtual void get_move( int&x , int&y ) override ;
};

class RandomPlayer_game_3: public Player {
protected:
    int dimension;
    int chc {} ;
public:
    RandomPlayer_game_3 ( char symbol, int dimension  );
    void get_move( int& x, int& y ) override ;
};


class GameManager {
    private:
        Board* boardPtr;
        Player* players[2];
    public:
        GameManager( Board* , Player* playerPtr[2] );
        ~GameManager();
        void run();
};

#endif
