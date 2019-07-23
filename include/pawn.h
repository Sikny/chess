#ifndef PAWN_H
#define PAWN_H

#include "piece.h"

class Pawn : public Piece{
    public:
        explicit Pawn(sf::Color color);
        bool canBeMoved(const std::string& pos) override;
        bool canTakeTo(const std::string& pos);
};

#endif // PAWN_H
