#include "knight.h"

Knight::Knight(sf::Color color) : Piece(color) {}

bool Knight::canBeMoved(const std::string &pos) {
    return true;
}
