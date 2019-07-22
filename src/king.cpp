#include "king.h"

King::King(sf::Color color) : Piece(color){}

bool King::canBeMoved(const std::string &pos) {
    return true;
}
