#include "rook.h"

Rook::Rook(sf::Color color) : Piece(color){}

bool Rook::canBeMoved(const std::string &pos) {
    int colFrom = position.at(1) - '0';
    int colDest = pos.at(1) - '0';
    char rowFrom = position.at(0);
    char rowDest = pos.at(0);
    return colFrom == colDest || rowFrom == rowDest;
}
