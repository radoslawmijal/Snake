#include "View.h"

//color palette
sf::Color DarkGreen(5,130,30);
sf::Color LightGreen(15,190,20);
sf::Color BorderColor(30,70,50);



View::View(Snake &snake) : snake(snake) {}

void View::draw_snake(sf::RenderWindow &window)
{
    sf::Texture dark_blue;
    dark_blue.loadFromFile("Images/dark_blue.png");
    sf::Texture light_blue;
    light_blue.loadFromFile("Images/light_blue.png");

    for (const auto &snake_part : snake.getBodyPosition())
    {
        sf::RectangleShape shape(sf::Vector2f(size, size));
        shape.setPosition(snake_part.first * size, snake_part.second * size);

        if((snake_part.first + snake_part.second) % 2 == 0)
            shape.setTexture(&dark_blue);
        else
            shape.setTexture(&light_blue);

        window.draw(shape);
    }

    sf::RectangleShape shape_head(sf::Vector2f(size, size));
    sf::Texture snake_head;
    snake_head.loadFromFile("Images/snake_head.png");
    shape_head.setOrigin(size / 2,size / 2);
    shape_head.setPosition(snake.getHeadPosition().first * size + size / 2, snake.getHeadPosition().second * size + size / 2);
    shape_head.setTexture(&snake_head);

    if(snake.getCurrentDirection() == std::make_pair(1,0))
        shape_head.setRotation(90);
    if(snake.getCurrentDirection() == std::make_pair(0,1))
        shape_head.setRotation(180);
    if(snake.getCurrentDirection() == std::make_pair(-1,0))
        shape_head.setRotation(270);

    window.draw(shape_head);
}

void View::draw_food(sf::RenderWindow &window)
{
    sf::RectangleShape shape_food(sf::Vector2f(size, size));
    sf::Texture texture_food;
    texture_food.loadFromFile("Images/apple.png");
    shape_food.setTexture(&texture_food);
    shape_food.setPosition(snake.FoodPosition.first * size, snake.FoodPosition.second * size);
    window.draw(shape_food);
}

void View::draw_background(sf::RenderWindow &window)
{
    sf::RectangleShape shape_border(sf::Vector2f(size * snake.getBoardHeight(), size * snake.getBoardWidth()));
    shape_border.setFillColor(BorderColor);
    window.draw(shape_border);

    for (int row = 1; row < snake.getBoardHeight() - 1; ++row)
        for(int col = 1; col < snake.getBoardWidth() - 1; ++col)
        {
            sf::RectangleShape background_part(sf::Vector2f(size,size));
            background_part.setPosition(sf::Vector2f(size * row, size * col));
            if((row + col) % 2 == 0)
                background_part.setFillColor(DarkGreen);
            else
                background_part.setFillColor(LightGreen);
            window.draw(background_part);
        }
}

void View::draw_box(sf::RenderWindow &window)
{
    for(int it = 0; it < snake.number_of_boxes; ++it)
    {
        sf::RectangleShape shape_box (sf::Vector2f(size,size));
        sf::Texture texture_box;
        texture_box.loadFromFile("Images/box.png");
        shape_box.setTexture(&texture_box);
        shape_box.setPosition(snake.BoxPositions[it].first * size, snake.BoxPositions[it].second * size);
        window.draw(shape_box);
    }
}

void View::draw_finished(sf::RenderWindow &window)
{
    sf::RectangleShape shape_Finished (sf::Vector2f( snake.getBoardHeight() * size / 2 , snake.getBoardWidth() * size / 2));
    sf::Texture texture_Finished;
    texture_Finished.loadFromFile("Images/FINISHED.png");
    shape_Finished.setTexture(&texture_Finished);
    shape_Finished.setPosition(snake.getBoardHeight() * size / 4, snake.getBoardWidth() * size / 4);
    window.draw(shape_Finished);
}

void View::draw_menu_1(sf::RenderWindow &window)
{
    sf::RectangleShape shape_menu_1 (sf::Vector2f (snake.getBoardHeight() * size, snake.getBoardWidth() * size));
    sf::Texture texture_menu_1;
    texture_menu_1.loadFromFile("Images/menu1.png");
    shape_menu_1.setTexture(&texture_menu_1);
    window.draw(shape_menu_1);
}

void View::draw_menu_2(sf::RenderWindow &window)
{
    sf::RectangleShape shape_menu_2 (sf::Vector2f (snake.getBoardHeight() * size, snake.getBoardWidth() * size));
    sf::Texture texture_menu_2;
    texture_menu_2.loadFromFile("Images/menu2.png");
    shape_menu_2.setTexture(&texture_menu_2);
    window.draw(shape_menu_2);
}

void View::draw_menu_3(sf::RenderWindow &window)
{
    sf::RectangleShape shape_menu_3 (sf::Vector2f (snake.getBoardHeight() * size, snake.getBoardWidth() * size));
    sf::Texture texture_menu_3;
    texture_menu_3.loadFromFile("Images/menu3.png");
    shape_menu_3.setTexture(&texture_menu_3);
    window.draw(shape_menu_3);
}

void View::draw_mode_1(sf::RenderWindow &window)
{
    sf::RectangleShape shape_mode_1 (sf::Vector2f  (snake.getBoardHeight() * size, snake.getBoardWidth() * size));
    sf::Texture texture_mode_1;
    texture_mode_1.loadFromFile("Images/mode1.png");
    shape_mode_1.setTexture(&texture_mode_1);
    window.draw(shape_mode_1);
}

void View::draw_mode_2(sf::RenderWindow &window)
{
    sf::RectangleShape shape_mode_2 (sf::Vector2f  (snake.getBoardHeight() * size, snake.getBoardWidth() * size));
    sf::Texture texture_mode_2;
    texture_mode_2.loadFromFile("Images/mode2.png");
    shape_mode_2.setTexture(&texture_mode_2);
    window.draw(shape_mode_2);
}

void View::draw_mode_3(sf::RenderWindow &window)
{
    sf::RectangleShape shape_mode_3 (sf::Vector2f  (snake.getBoardHeight() * size, snake.getBoardWidth() * size));
    sf::Texture texture_mode_3;
    texture_mode_3.loadFromFile("Images/mode3.png");
    shape_mode_3.setTexture(&texture_mode_3);
    window.draw(shape_mode_3);
}

void View::draw_saved(sf::RenderWindow &window)
{
    sf::RectangleShape shape_saved(sf::Vector2f (snake.getBoardHeight() * size / 2, snake.getBoardWidth() * size / 2));
    shape_saved.setPosition(snake.getBoardHeight() * size / 4, snake.getBoardWidth() * size / 4);
    sf::Texture texture_saved;
    texture_saved.loadFromFile("Images/saved.png");
    shape_saved.setTexture(&texture_saved);
    window.draw(shape_saved);
}

void View::draw_scoreboard(sf::RenderWindow &window, const std::vector<int> &scoreboard)
{
    sf::Text text;
    sf::Text highscore;
    sf::Font font;
    std::vector<int> scores = scoreboard;

    font.loadFromFile("Images/Anonymous_Pro.ttf");

    if (!font.loadFromFile("Images/Anonymous_Pro.ttf")) {
        throw std::runtime_error("Nie mozna zaladowac czcionki");
    }

    sf::RectangleShape shape_scoreboard(sf::Vector2f (snake.getBoardHeight() * size, snake.getBoardWidth() * size));
    sf::Texture texture_scoreboard;
    texture_scoreboard.loadFromFile("Images/scoreboard.png");
    shape_scoreboard.setTexture(&texture_scoreboard);
    window.draw(shape_scoreboard);

    int gap = 70;
    sf::Color brown = {150,90,60};

    highscore.setFont(font);
    highscore.setString(std::to_string(scores[0]));
    highscore.setPosition(650,50);
    highscore.setCharacterSize(200);
    highscore.setFillColor(brown);
    window.draw(highscore);

    for(size_t i = 1; i < scores.size(); ++i)
    {
        text.setFont(font);
        text.setString(std::to_string(scores[i]));
        text.setPosition(snake.getBoardWidth() * size / 2,(i + 3) * gap);
        text.setCharacterSize(70);
        text.setFillColor(brown);
        window.draw(text);
    }
}


void View::draw(sf::RenderWindow &window)
{
    if(snake.state == MENU_1)
    {
        draw_menu_1(window);
        return;
    }
    if(snake.state == MENU_2)
    {
        draw_menu_2(window);
        return;
    }
    if(snake.state == MENU_3)
    {
        draw_menu_3(window);
        return;
    }
    if(snake.state == MODE_1)
    {
        draw_mode_1(window);
        return;
    }
    if(snake.state == MODE_2)
    {
        draw_mode_2(window);
        return;
    }
    if(snake.state == MODE_3)
    {
        draw_mode_3(window);
        return;
    }
    if(snake.state == SCOREBOARD)
    {
        draw_scoreboard(window, snake.readScoreBoard());
        return;
    }


    draw_background(window);


    std::this_thread::sleep_for(std::chrono::milliseconds(snake.move_time_in_miliseconds));


    snake.Move();


    draw_food(window);


    draw_snake(window);


    draw_box(window);


    // Food process
    if(snake.getHeadPosition().first == snake.FoodPosition.first and snake.getHeadPosition().second == snake.FoodPosition.second)
    {
        snake.Swallow();
        snake.FoodPosition = snake.generateFoodPosition();

        draw_food(window);
    }

    if(snake.state == FINISHED)
        draw_finished(window);

    if(snake.ScoreSaved)
        draw_saved(window);

}