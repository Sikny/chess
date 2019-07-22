#include "king.h"

King::King(sf::Color color) : Piece(color){}

bool King::canBeMoved(const std::string &pos) {
    int colFrom = position.at(1) - '0';
    int colDest = pos.at(1) - '0';
    char rowFrom = position.at(0);
    char rowDest = pos.at(0);
    return (colFrom == colDest + 1 || colFrom == colDest - 1 || colFrom == colDest)
           && (rowFrom == rowDest + 1 || rowFrom == rowDest - 1 || rowFrom == rowDest);
}
