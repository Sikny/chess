#include "pawn.h"

Pawn::Pawn(sf::Color color) : Piece(color){}

bool Pawn::canBeMoved(const std::string &pos) {
    int colFrom = position.at(1) - '0';
    int colDest = pos.at(1) - '0';
    char rowFrom = position.at(0);
    char rowDest = pos.at(0);
    return rowFrom == rowDest
        && ((color == sf::Color::White && (colDest == colFrom+1 || (colFrom == 2 && colDest == colFrom+2)))
            || (color == sf::Color::Black && (colDest == colFrom-1 || (colFrom == 7 && colDest == colFrom-2))));
}
