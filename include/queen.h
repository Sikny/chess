#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"

class Queen : public Piece {
    public:
        Queen(sf::Color);
        virtual bool canBeMoved(const std::string& pos);
};

#endif // QUEEN_H
