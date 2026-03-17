#ifndef SNAKE_VIEW_H
#define SNAKE_VIEW_H

#include <SFML/Graphics.hpp>
#include "Snake.h"

class View
{
    Snake &snake;
    int size = 50;


public:

    View(Snake &snake);
    void draw(sf::RenderWindow &window);
    void draw_snake(sf::RenderWindow &window);
    void draw_food(sf::RenderWindow &window);
    void draw_background(sf::RenderWindow &window);
    void draw_box(sf::RenderWindow &window);
    void draw_finished(sf::RenderWindow &window);
    void draw_menu_1(sf::RenderWindow &window);
    void draw_menu_2(sf::RenderWindow &window);
    void draw_menu_3(sf::RenderWindow &window);
    void draw_mode_1(sf::RenderWindow &window);
    void draw_mode_2(sf::RenderWindow &window);
    void draw_mode_3(sf::RenderWindow &window);
    void draw_saved(sf::RenderWindow &window);
    void draw_scoreboard(sf::RenderWindow &window, const std::vector<int> &scoreboard);
};

#endif //SNAKE_VIEW_H
