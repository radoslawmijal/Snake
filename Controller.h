#ifndef SNAKE_CONTROLLER_H
#define SNAKE_CONTROLLER_H

#include "Snake.h"
#include "View.h"

class Controller
{
    Snake &snake;
    View &view;
    sf::RenderWindow &window;
    bool start = true;


public:

    Controller( Snake &snake, View &view, sf::RenderWindow &window);
    void play();
};

#endif //SNAKE_CONTROLLER_H
