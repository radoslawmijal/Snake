#include "Controller.h"

Controller::Controller( Snake &snake, View &view, sf::RenderWindow &window) :  snake(snake), view(view), window(window) {}

void Controller::play()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(snake.state == MENU_1 or snake.state == MENU_2 or snake.state == MENU_3)
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
            {
                snake.state = snake.next_menu();
                std::this_thread::sleep_for(std::chrono::milliseconds(150));
            }

        if(snake.state == MODE_1 or snake.state == MODE_2 or snake.state == MODE_3)
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
            {
                snake.state = snake.next_mode();
                std::this_thread::sleep_for(std::chrono::milliseconds(150));
            }


        if(snake.state == MENU_1)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                for(int nr = 0; nr < snake.number_of_boxes; ++nr )
                    snake.BoxPositions.push_back(snake.generateBoxPosition());

                start = true;
                snake.state = RUNNING;
            }
        }

        if(snake.state == MENU_2)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                snake.state = MODE_1;
                std::this_thread::sleep_for(std::chrono::milliseconds(150));
            }
        }

        if(snake.state == MENU_3)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                snake.state = SCOREBOARD;
                std::this_thread::sleep_for(std::chrono::milliseconds(150));
            }
        }

        if(snake.state == MODE_1)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                snake.BoxPositions.clear();
                snake.number_of_boxes = 0;
                snake.state = MENU_1;
                std::this_thread::sleep_for(std::chrono::milliseconds(150));
            }
        }

        if(snake.state == MODE_2)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                snake.BoxPositions.clear();
                snake.number_of_boxes = 10;
                snake.state = MENU_1;
                std::this_thread::sleep_for(std::chrono::milliseconds(150));
            }
        }

        if(snake.state == MODE_3)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
            {
                snake.BoxPositions.clear();
                snake.number_of_boxes = 20;
                snake.state = MENU_1;
                std::this_thread::sleep_for(std::chrono::milliseconds(150));
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            snake.Restart();
            snake.state = MENU_1;
        }


        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if(!snake.direction_cooldown_activated)
            {
                snake.SetDirection(up);
                snake.direction_cooldown_activated = true;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if(!snake.direction_cooldown_activated)
            {
                snake.SetDirection(down);
                snake.direction_cooldown_activated = true;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if(!snake.direction_cooldown_activated)
            {
                snake.SetDirection(left);
                snake.direction_cooldown_activated = true;
            }
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if(!snake.direction_cooldown_activated)
            {
                snake.SetDirection(right);
                snake.direction_cooldown_activated = true;
            }
        }

        if (snake.state == FINISHED)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                snake.ScoreSaved = true;
                std::vector<int> ScoreBoard = snake.readScoreBoard();
                snake.addScore(snake.getBodySize() - snake.startLength);
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
            {
                start = true;
                snake.Restart();
            }
        }

        window.clear();
        view.draw(window);
        window.display();

        if(start)
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            start = false;
        }
    }
}