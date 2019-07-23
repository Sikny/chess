#include "knight.h"

Knight::Knight(sf::Color color) : Piece(color) {}

bool Knight::canBeMoved(const std::string &pos) {
    int colFrom = position.at(1) - '0';
    int colDest = pos.at(1) - '0';
    char rowFrom = position.at(0);
    char rowDest = pos.at(0);
    return ((colDest == colFrom-1 || colDest == colFrom+1) && (rowDest == rowFrom+2 || rowDest == rowFrom-2))
        || ((colDest == colFrom-2 || colDest == colFrom+2) && (rowDest == rowFrom+1 || rowDest == rowFrom-1));
}
