#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "BoardGame_Classes.hpp"
#include <funcs.hpp>
using namespace std ;

int main() {

    // window for choosing the game ;

    int chc {0} ;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Choose a game" , sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize  );

    vector<sf::RectangleShape> games ;
    games.emplace_back( sf::Vector2f ( 100.0f , 100.0f ) ) ;
    games.emplace_back( sf::Vector2f ( 100.0f , 100.0f ) ) ;
    games.emplace_back( sf::Vector2f ( 100.0f , 100.0f ) ) ;
    games.emplace_back( sf::Vector2f ( 100.0f , 100.0f ) ) ;

    vector<sf::Texture> textures ;
    sf::Texture game1 ; game1.loadFromFile( "../textures/Game1.png") ;
    textures.push_back(game1) ;
    sf::Texture game2 ; game2.loadFromFile( "../textures/Game2.png") ;
    textures.push_back(game2) ;
    sf::Texture game3 ; game3.loadFromFile( "../textures/Game3.png") ;
    textures.push_back(game3) ;
    sf::Texture game4 ; game4.loadFromFile( "../textures/Game4.png") ;
    textures.push_back(game4) ;

    float total_w = 4 * ( 100 + 50 ) - 50 ;
    float total_h = 100 ;

    float start_x = ( window.getSize().x - total_w ) / 2.0f ;
    float start_y = ( window.getSize().y - total_h ) / 2.0f ;

    for ( int i = 0 ; i < 4 ; i++ ){
        games[i].setPosition( start_x + ( 150 ) * i , start_y ) ;
        games[i].setTexture(&textures[i]) ;
    }

    while ( window.isOpen() && !chc ) {
        sf::Event evnt ;
        while ( window.pollEvent(evnt) ) {
            switch (evnt.type) {
                case sf::Event::Closed  :
                    window.close() ;
                    break;
                case sf::Event::MouseButtonPressed :
                    for ( int i = 0 ; i < 4 ; i++ ){
                        if ( isPointInsideRect( sf::Mouse::getPosition(window) , games[i] ) ){
                            chc = i + 1 ;
                        }
                    }
                    break;
            }
        }

        for ( int i = 0 ; i < 4 ; i++ ){
            if ( isPointInsideRect( sf::Mouse::getPosition(window) , games[i] ) ){
                games[i].setFillColor( sf::Color::Green ) ;
            } else {
                games[i].setFillColor( sf::Color::White ) ;
            }
        }
        window.clear() ;
        for ( int i = 0 ; i < 4 ; i++ ){
            window.draw(games[i]) ;
        }
        window.display() ;
    }

    vector<sf::RectangleShape> human_AI ;
    human_AI.emplace_back( sf::Vector2f ( 100.0f , 100.0f ) ) ;
    human_AI.emplace_back( sf::Vector2f ( 100.0f , 100.0f ) ) ;

    vector<sf::Texture> hu_Ai_texture ;
    sf::Texture human ; human.loadFromFile("../textures/human.png") ;
    sf::Texture Ai ; Ai.loadFromFile("../textures/ai.png") ;
    hu_Ai_texture.push_back(human) ;
    hu_Ai_texture.push_back(Ai) ;

    for ( int i = 0 ; i < 2 ; i++ ){
        human_AI[i].setTexture(&hu_Ai_texture[i]) ;
    }

    total_w = 2 * ( 100 + 50 ) - 50 ;
    total_h = 100 ;

    start_x = ( window.getSize().x - total_w ) / 2.0f ;
    start_y = ( window.getSize().y - total_h ) / 2.0f ;

    for ( int i = 0 ; i < 2 ; i++ ){
        human_AI[i].setPosition( start_x + (float)i * ( 150.0f ) , start_y ) ;
    }

    int is_ai = 0 ;
    while ( window.isOpen() && !is_ai ) {
        sf::Event evnt ;
        while ( window.pollEvent(evnt) ){
            switch ( evnt.type )  {
                case sf::Event::Closed :
                    window.close() ;
                    break;
                case sf::Event::MouseButtonPressed :
                    for ( int i = 0 ; i < human_AI.size() ; i++ ){
                        if (isPointInsideRect( sf::Mouse::getPosition( window ) , human_AI[i] )) {
                            if ( i == 0 ){
                                is_ai = 1 ;
                            } else {
                                is_ai = 2 ;
                            }
                        }
                    }
            }
        }
        for ( int i = 0 ; i < 2 ; i++ ){
            if ( isPointInsideRect( sf::Mouse::getPosition(window) , human_AI[i] ) ){
                human_AI[i].setFillColor( sf::Color::Green ) ;
            } else {
                human_AI[i].setFillColor( sf::Color::White ) ;
            }
        }
        window.clear() ;
        for ( int i = 0 ; i < 2 ; i++ ){
            window.draw(human_AI[i]) ;
        }
        window.display() ;
    }

    if ( !chc )
        return 0 ;

    switch (chc) {
        case 1 :
            game_1(window , is_ai ) ;
            break;
        case 2 :
            game_2(window , is_ai ) ;
            break;
        case 3 :
            break;
        case 4 :
            break;
        default:
            break;
    }
    return 0 ;
}