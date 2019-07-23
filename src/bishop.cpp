#include "bishop.h"

Bishop::Bishop(sf::Color color) : Piece(color){}

bool Bishop::canBeMoved(const std::string &pos) {
    int colFrom = position.at(1) - '0';
    int colDest = pos.at(1) - '0';
    char rowFrom = position.at(0);
    char rowDest = pos.at(0);
    return (colDest-colFrom == std::abs(rowDest-rowFrom));
}
