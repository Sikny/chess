#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece{
    public:
        Pawn(sf::Color color);
        virtual bool canBeMoved(const std::string& pos);
};

#endif // PAWN_H
