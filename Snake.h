#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <ctime>
#include <vector>
#include <utility>
#include <map>
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <algorithm>

enum GameState{MODE_1, MODE_2, MODE_3, MENU_1, MENU_2, MENU_3, RUNNING, FINISHED, SCOREBOARD};
enum Directions{left,right,up,down};

class Snake
{
    std::pair<int, int> head;
    std::pair<int,int> tail;
    std::vector<std::pair<int, int>> body;
    std::pair<int,int> current_direction;

    int width;
    int height;

public:

    Snake();

    GameState state = MENU_1;
    GameState next_menu();
    GameState next_mode();

    std::vector<std::pair<int,int>> getBodyPosition();
    std::vector<std::pair<int,int>> BoxPositions;

    std::string PlayerName;

    std::pair<int,int> getHeadPosition();
    std::pair<int,int> FoodPosition;
    std::pair<int,int> generateFoodPosition();
    std::pair<int,int> generateBoxPosition();
    std::pair<int,int> getCurrentDirection();

    int startLength;
    int number_of_boxes = 10;
    int move_time_in_miliseconds = 100;
    int getBodySize() const;
    int getBoardWidth() const;
    int getBoardHeight() const;

    void Move();
    void SetDirection(Directions direction);
    void Swallow();
    void Restart();
    void uploadScoreBoard(const std::vector<int> &ScoreBoard) const;
    std::vector<int> readScoreBoard() const;
    void addScore(int new_score);


    bool IHitMyself(std::pair<int,int> new_head);
    bool IHitBox(std::pair<int,int> new_head);
    bool direction_cooldown_activated = false;
    bool ScoreSaved = false;

};

#endif //SNAKE_SNAKE_H