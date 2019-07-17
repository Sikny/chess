#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "case.h"

class Game
{
    public:
        Game();
        Game(int, int, const char*);
        void run();

    private:
        void processEvents();
        void update();
        void render();

        sf::RenderWindow window;
};

#endif // GAME_H
