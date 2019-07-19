#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <map>
#include <utility>
#include <sstream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

#include "case.h"
#include "chesspieces.h"

class Game {
    public:
        Game();
        Game(int, int, const char*);
        void run();

    private:
        void processEvents();
        void update();
        void render();

        std::map<std::string,Case> board;
        std::vector<Piece*> whitePieces;
        std::vector<Piece*> blackPieces;

        int boardSize;

        sf::RenderWindow window;
};

#endif // GAME_H
