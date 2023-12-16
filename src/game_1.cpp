#include <BoardGame_Classes.hpp>
#include <SFML/Graphics.hpp>
#include <funcs.hpp>

void game_1 ( sf::RenderWindow& screen , int is_ai ) {
    screen.setTitle("normal XO game by Dr Mohamed El Ramly ") ;

    vector<vector<sf::RectangleShape>> blocks ( 3 , vector<sf::RectangleShape> ( 3 , sf::RectangleShape( sf::Vector2f(100.0f , 100.0f)) ) ) ;
    vector<vector<bool>> clicked ( 3 , vector<bool>( 3 , false ) ) ;
    X_O_Board board ;
    RandomPlayer smart( 'X' , 3 , &board ) ;

    float total_x = 3 * ( 100 + 30 ) - 30 ;
    float total_y = 3 * ( 100 + 30 ) - 30 ;

    float start_x = ( screen.getSize().x - total_x ) / 2.0f ;
    float start_y = ( screen.getSize().y - total_y ) / 2.0f ;

    for ( int i = 0 ; i < 3 ; i++ ){
        for ( int j = 0 ; j < 3 ; j++ ){
            blocks[i][j].setPosition( start_x + (j * ( 130.0f )) , start_y + i * ( 130.0f ) ) ;
        }
    }

    sf::Texture textures[2] { sf::Texture() , sf::Texture() } ;
    textures[0].loadFromFile( "../textures/X.png") ;
    textures[1].loadFromFile( "../textures/O.png") ;
    char player[2] = { 'X' , 'O' }; bool turn = false ;

    bool draw = false , win = false , AI = ( is_ai == 2 );
    while ( screen.isOpen() ) {
        sf::Event evnt ;
        while ( screen.pollEvent( evnt ) ){
            switch (evnt.type) {
                case sf::Event::Closed :
                    screen.close() ;
                    break;
                case sf::Event::MouseButtonPressed :
                    for ( int i = 0 ; i < 3 ; i++ ) {
                        for ( int j = 0 ; j < 3 ; j++ ) {
                            if ( isPointInsideRect( sf::Mouse::getPosition(screen) , blocks[i][j] ) && !clicked[i][j] ) {
                                board.update_board( i , j , player[turn] ) ;
                                clicked[i][j] = true ;
                                blocks[i][j].setTexture( &textures[turn] ) ;
                                turn = !turn ;
                            }
                            if ( board.is_winner() ){
                                win = true ;
                                win_draw_over( screen , win , draw , player[!turn] ) ;
                            }
                            if ( board.is_draw() ) {
                                draw = true ;
                                win_draw_over( screen , win , draw , player[!turn] ) ;
                            }
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        if ( win || draw ){
            screen.close() ;
            break;
        }
        if ( turn && AI ) {
            int x , y ;
            smart.get_move( x , y ) ;
            board.update_board( x , y , player[turn] );
            clicked[x][y] = true ;
            blocks[x][y].setTexture( &textures[turn] ) ;
            turn = !turn ;
            if ( board.is_winner() ){
                win = true ;
                win_draw_over( screen , win , draw , 'O' ) ;
            }
            if ( board.is_draw() ) {
                draw = true ;
                win_draw_over( screen , win , draw , 'O' ) ;
            }
        }

        for ( int i = 0 ; i < 3 ; i++ ){
            for ( int j = 0 ; j < 3 ; j++ ) {
                if (isPointInsideRect(sf::Mouse::getPosition(screen), blocks[i][j]) && !clicked[i][j]) {
                    blocks[i][j].setFillColor(sf::Color::Green);
                } else {
                    blocks[i][j].setFillColor(sf::Color::White);
                }
            }
        }

        screen.clear();
        for ( int i = 0 ; i < 3 ; i++ ){
            for ( int j = 0 ; j < 3 ; j++ ){
                screen.draw(blocks[i][j]) ;
            }
        }
        screen.display() ;
    }
}
