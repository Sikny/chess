#include "pawn.h"

Pawn::Pawn(sf::Color color) : Piece(color){}

bool Pawn::canBeMoved(const std::string &pos) {
    return true;
}
