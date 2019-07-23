#include "knight.h"

Knight::Knight(sf::Color color) : Piece(color) {}

bool Knight::canBeMoved(const std::string &pos) {
    int colFrom = position.at(1) - '0';
    int colDest = pos.at(1) - '0';
    char rowFrom = position.at(0);
    char rowDest = pos.at(0);
    return ((std::abs(colDest-colFrom) == 1) && (std::abs(rowDest-rowFrom) == 2))
        || ((std::abs(colDest-colFrom) == 2) && (std::abs(rowDest-rowFrom) == 1));
}

bool Knight::isKnight() {
    return true;
}