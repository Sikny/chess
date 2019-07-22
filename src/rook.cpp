#include "rook.h"

Rook::Rook(sf::Color color) : Piece(color){}

bool Rook::canBeMoved(const std::string &pos) {
    return true;
}
