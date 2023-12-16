#include<BoardGame_Classes.hpp>
#include<SFML/Graphics.hpp>
#include<funcs.hpp>

void game_2 ( sf::RenderWindow& screen , int is_ai ) {
    screen.setTitle("pyramidic XO game by Omar Osama id:20220221") ;

    const int cubeSize = 100 ;
    const int gap = 30 ;
    const int rows = 3;
    const int columns = 5;

    sf::Texture X ; X.loadFromFile( "../textures/X.png") ;
    sf::Texture O ; O.loadFromFile( "../textures/O.png") ;

    std::vector<std::vector<sf::RectangleShape>> blocks (rows , std::vector<sf::RectangleShape>(columns , sf::RectangleShape() ) ) ;
    std::vector<std::vector<bool>> clicked ( 3 , std::vector<bool>( 5 , false ) ) ;
    float totalWidth = columns * (cubeSize + gap) - gap;
    float totalHeight = rows * (cubeSize + gap) - gap;


    float startX = (screen.getSize().x - totalWidth) / 2.0f;
    float startY = (screen.getSize().y - totalHeight) / 2.0f;

    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            if ( column < 2 - row || column > 2 + row )
                continue;
            sf::RectangleShape cube(sf::Vector2f(cubeSize, cubeSize));
            cube.setPosition(startX + (cubeSize + gap) * column, startY + (cubeSize + gap) * row);
            blocks[row][column] = cube ;
        }
    }
    X_O_Board_game_1 board ;
    RandomPlayer_game_1 smart ( 'O' , 3 , 5 , &board ) ;
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
                        for ( int j = 0 ; j < 5 ; j++ ) {
                            if ( j < 2 - i || j > 2 + i ) {
                                continue;
                            }
                            if ( isPointInsideRect( sf::Mouse::getPosition(screen) , blocks[i][j] ) && !clicked[i][j] ) {
                                board.update_board( i , j , player[turn] ) ;
                                clicked[i][j] = true ;
                                blocks[i][j].setTexture( &textures[turn] ) ;
                                turn = !turn ;
                            }
                            if ( board.is_winner() ){
                                win = true ;
                                win_draw_over( screen , win , draw , 'X' ) ;
                            }
                            if ( board.is_draw() ) {
                                draw = true ;
                                win_draw_over( screen , win , draw , 'X' ) ;
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
            for ( int j = 0 ; j < 5 ; j++ ) {
                if ( j < 2 - i || j > 2 + i ) {
                    continue;
                }
                if (isPointInsideRect(sf::Mouse::getPosition(screen), blocks[i][j]) && !clicked[i][j]) {
                    blocks[i][j].setFillColor(sf::Color::Green);
                } else {
                    blocks[i][j].setFillColor(sf::Color::White);
                }
            }
        }

        screen.clear();
        for ( int i = 0 ; i < 3 ; i++ ){
            for ( int j = 0 ; j < 5 ; j++ ){
                if ( j < 2 - i || j > 2 + i ) {
                    continue;
                }
                screen.draw(blocks[i][j]) ;
            }
        }
        screen.display() ;
    }
}
