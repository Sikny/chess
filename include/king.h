#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece{
    public:
        explicit King(sf::Color color);
        bool canBeMoved(const std::string& pos) override;
};

#endif // KING_H
