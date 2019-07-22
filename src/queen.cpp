#include "queen.h"

Queen::Queen(sf::Color color) : Piece(color) {}

bool Queen::canBeMoved(const std::string &pos) {
    return true;
}
