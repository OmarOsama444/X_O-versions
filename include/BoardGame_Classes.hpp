#ifndef BoardGame_CLASSES_H
#define BoardGame_CLASSES_H
using namespace std;

class Board {
protected:
   int n_rows, n_cols;
   char** board;
   int  n_moves = 0;
public:
   virtual bool update_board (int x, int y, char symbol) = 0;
   virtual bool is_winner() = 0;
   virtual bool is_draw() = 0;
   virtual void display_board() = 0;
   virtual bool game_is_over() = 0;
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
};

class X_O_Board_game_1 : public Board {
public:
    X_O_Board_game_1() ;
    bool update_board ( int x , int y , char mark ) override ;
    void display_board() override ;
    bool is_winner() override ;
    bool is_draw() override ;
    bool game_is_over() override ;
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
    public:
        RandomPlayer (char symbol, int dimension);
        void get_move(int& x, int& y) override;
};

class GameManager {
    private:
        Board* boardPtr;
        Player* players[2];
    public:
        GameManager( Player* playerPtr[2] , Board* = nullptr );
        ~GameManager();
        void intialize( Board* ) ;
        void run();
};

#endif
