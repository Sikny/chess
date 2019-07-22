#ifndef KING_H
#define KING_H

#include "piece.h"

class King : public Piece{
    public:
        King(sf::Color color);
        virtual bool canBeMoved(const std::string& pos);
};

#endif // KING_H
