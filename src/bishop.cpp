#include "bishop.h"

Bishop::Bishop(sf::Color color) : Piece(color){}

bool Bishop::canBeMoved(const std::string &pos) {
    return true;
}
