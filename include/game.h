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
#include "PieceFactory.h"
#include "chesspieces.h"

class Game {
    public:
        Game();
        Game(int, int, const char*);
        void run();
        Piece* getPieceAtPos(const std::string& position);

    private:
        void processEvents();
        void update();
        void render();
        bool isObstructed(const std::string& position, const std::string& dest);

        std::map<std::string,Case> board;
        std::vector<Piece*> whitePieces;
        std::vector<Piece*> blackPieces;

        int boardSize;
        Piece* selectedPiece;
        sf::Color currentPlayer;

        sf::Text currentPlayerDisplay;
        sf::Font font;

        sf::RenderWindow window;
};

#endif // GAME_H
