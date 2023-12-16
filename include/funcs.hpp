#ifndef funcs_h
#define funcs_h
#include <SFML/Graphics.hpp>

bool isPointInsideRect(const sf::Vector2i& point, const sf::RectangleShape& rect) ;
void win_draw_over( sf::RenderWindow& screen , bool win , bool draw  , char winner );
void game_1 ( sf::RenderWindow& screen , int is_ai ) ;
void game_2 ( sf::RenderWindow& window , int is_ai );

#endif