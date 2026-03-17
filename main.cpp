#include "Controller.h"

int main()
{
    srand(time(0));

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Grafika w C++/SFML");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(60);

    Snake snake;
    View view(snake);
    Controller controller(snake, view, window);

    controller.play();

    /*          DOKUMENTACJA
     *
     *      grafiki zostaly stworzone za pomoca: https://www.pixilart.com/
     *
     *      3 tryby gry
     *
     *      enter - wybierz
     *      esc - powrot do menu
     *      tab - wybranie kolejnej opcji w menu
     *
     *      r - reset
     *      space - zapisanie wyniku
     *
     *      w a s d - sterowanie wężem
     *
     * */

    return 0;
}