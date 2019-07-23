#include "queen.h"

Queen::Queen(sf::Color color) : Piece(color) {}

bool Queen::canBeMoved(const std::string &pos) {
    int colFrom = position.at(1) - '0';
    int colDest = pos.at(1) - '0';
    char rowFrom = position.at(0);
    char rowDest = pos.at(0);
    return colFrom == colDest || rowFrom == rowDest  // rook
        || colDest-colFrom == std::abs(rowDest-rowFrom);    // bishop

}
