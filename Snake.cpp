#include "Snake.h"


std::map<Directions, std::pair<int,int>> directions =
        {
                {left, std::make_pair(-1,0)},
                {right, std::make_pair(1,0)},
                {up, std::make_pair(0,-1)},
                {down, std::make_pair(0,1)}
        };

Snake::Snake()
{
    width = 20;
    height = 20;
    FoodPosition = generateFoodPosition();
    startLength = 4;
    current_direction = directions[down];
    body.push_back(std::make_pair(1,4));
    body.push_back(std::make_pair(1,3));
    body.push_back(std::make_pair(1,2));
    body.push_back(std::make_pair(1,1));
    head.first = body.begin()->first;
    head.second = body.begin()->second;
    tail.first = body.back().first;
    tail.second = body.back().second;
}

int Snake::getBoardWidth() const {return width;}
int Snake::getBoardHeight() const {return height;}
int Snake::getBodySize() const { return body.size(); }
std::vector<std::pair<int, int>> Snake::getBodyPosition()
{
    std::vector<std::pair<int,int>> body_no_head;
    for (size_t it = 1; it < body.size(); ++it) {
        body_no_head.push_back(body[it]);
    }
    return body_no_head;
}
std::pair<int,int> Snake::getHeadPosition() { return head; }
std::pair<int, int> Snake::getCurrentDirection() { return current_direction; }

std::pair<int,int> Snake::generateFoodPosition()
{
    lottery_food:
    int row = std::rand() % (height - 2) + 1;
    int col = std::rand() % (width - 2) + 1;
    std::pair new_food_pair = std::make_pair(row,col);

    for(auto pair = BoxPositions.begin(); pair != BoxPositions.end(); ++pair)
        if(*pair == new_food_pair)
             goto lottery_food;
    for(auto pair = body.begin(); pair != body.end(); ++pair)
        if(*pair == new_food_pair)
            goto lottery_food;

    return new_food_pair;
}

std::pair<int, int> Snake::generateBoxPosition()
{
    lottery_box:
    int row = std::rand() % (height - 2) + 1;
    int col = std::rand() % (width - 2) + 1;
    std::pair new_box_pair = std::make_pair(row,col);

    for(auto pair = BoxPositions.begin(); pair != BoxPositions.end(); ++pair)
        if(*pair == new_box_pair or new_box_pair == FoodPosition or new_box_pair == std::make_pair(1,1)
        or new_box_pair == std::make_pair(1,2) or new_box_pair == std::make_pair(1,3)
        or new_box_pair == std::make_pair(1,4) or new_box_pair == std::make_pair(1,5)
        or new_box_pair == std::make_pair(1,6) or new_box_pair == std::make_pair(2,4)
        or new_box_pair == std::make_pair(2,5) or new_box_pair == std::make_pair(2,6))
            goto lottery_box;

    return new_box_pair;
}

void Snake::SetDirection(Directions direction)
{
    if(state != RUNNING)
        return;

    if((current_direction == directions[right] and direction == left)
    or (current_direction == directions[left] and direction == right)
    or (current_direction == directions[up] and direction == down)
    or (current_direction == directions[down] and direction == up))
        return;

    current_direction = directions[direction];
}

bool Snake::IHitMyself(std::pair<int,int> new_head)
{
    for (auto pair = body.begin() + 1; pair != body.end(); ++pair )
    {
        if (*pair == new_head)
            return true;
    }
    return false;
}

bool Snake::IHitBox(std::pair<int, int> new_head)
{
    for(auto pair = BoxPositions.begin(); pair != BoxPositions.end(); ++pair)
    {
        if(*pair == new_head)
            return true;
    }

    return false;
}

void Snake::Move()
{
    if(state == FINISHED)
        return;

    std::pair<int, int> new_head = {head.first + current_direction.first, head.second + current_direction.second};

    if( new_head.first < 1 or new_head.first > height - 2
       or new_head.second < 1 or new_head.second > width - 2
       or IHitMyself(new_head) or IHitBox(new_head))
    {
        state = FINISHED;
        return;
    }

    head = new_head;
    body.pop_back();
    body.insert(body.begin(),std::make_pair(head.first, head.second));
    tail.first = body.back().first;
    tail.second = body.back().second;

    direction_cooldown_activated = false;
}

void Snake::Swallow()
{
    std::pair <int, int> new_part = tail;
    body.push_back(std::pair(new_part.first, new_part.second));
    tail = new_part;
}

void Snake::Restart()
{
    if(state == RUNNING)
        return;

    state = RUNNING;
    ScoreSaved = false;
    FoodPosition = generateFoodPosition();
    startLength = 4;
    current_direction = directions[down];
    body.clear();
    body.push_back(std::make_pair(1,4));
    body.push_back(std::make_pair(1,3));
    body.push_back(std::make_pair(1,2));
    body.push_back(std::make_pair(1,1));
    head.first = body.begin()->first;
    head.second = body.begin()->second;
    tail.first = body.back().first;
    tail.second = body.back().second;
}

GameState Snake::next_mode()
{
    if(state == MODE_1)
        return MODE_2;

    if(state == MODE_2)
        return MODE_3;

    return MODE_1;
}

GameState Snake::next_menu()
{
    if(state == MENU_1)
        return MENU_2;

    if(state == MENU_2)
        return MENU_3;

    return MENU_1;
}

std::vector<int> Snake::readScoreBoard() const
{
    std::fstream file;
    std::vector<int> ScoreBoard;
    std::string Score;

    file.open("Images/ScoreBoard.txt",std::ios::in);

    if(!file.good())
        throw std::runtime_error("Nie udało się otworzyć pliku (read)");

    int score;
    while(file >> score)
        ScoreBoard.push_back(score);

    file.close();
    return ScoreBoard;
}

void Snake::uploadScoreBoard(const std::vector<int> &ScoreBoard) const
{
    std::fstream file;
    file.open("Images/ScoreBoard.txt",std::ios::trunc | std::ios::out);

    if(!file.good())
        throw std::runtime_error("Nie udało się otworzyć pliku (upload)");

    for(const auto & input : ScoreBoard)
        file << input << std::endl;

    file.close();
}

void Snake::addScore(int new_score)
{
    std::vector<int> ScoreBoard = readScoreBoard();

    ScoreBoard.push_back(new_score);

    std::sort(ScoreBoard.begin(), ScoreBoard.end(),std::greater());

    if(ScoreBoard.size() > 10)
        ScoreBoard.resize(10);

    uploadScoreBoard(ScoreBoard);
}
