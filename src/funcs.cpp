#include <funcs.hpp>
#include <SFML/Graphics.hpp>

bool isPointInsideRect(const sf::Vector2i& point, const sf::RectangleShape& rect) {
    sf::Vector2f rectPos = rect.getPosition();
    sf::Vector2f rectSize = rect.getSize();

    return (point.x >= rectPos.x && point.x <= rectPos.x + rectSize.x &&
            point.y >= rectPos.y && point.y <= rectPos.y + rectSize.y);
}

void win_draw_over( sf::RenderWindow& screen , bool win , bool draw  , char winner ){
    screen.setTitle("Results") ;
    sf::Text inputText;
    sf::Font font ; font.loadFromFile("../textures/arial.ttf") ;

    inputText.setFont(font) ;
    inputText.setCharacterSize(24);
    inputText.setFillColor(sf::Color::White);
    inputText.setPosition(10, 10);
    if ( win ){
        ( winner == 'X' ) ? inputText.setString( "PLayer X wins !" ) : inputText.setString("Player O wins !") ;
    } else if ( draw ) {
        inputText.setString("The Gamed ended in A draw ") ;
    }

    while ( screen.isOpen() ){
        sf::Event evnt ;
        while ( screen.pollEvent(evnt) ) {
            switch (evnt.type) {
                case sf::Event::Closed :
                    screen.close() ;
                    break;
                case sf::Event::MouseButtonPressed :
                    screen.close() ;
                    break;
            }
        }
        screen.clear() ;
        screen.draw(inputText) ;
        screen.display() ;
    }
}
