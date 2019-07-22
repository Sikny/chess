#ifndef ROOK_H
#define ROOK_H

#include <piece.h>


class Rook : public Piece
{
    public:
        Rook(sf::Color);
        virtual bool canBeMoved(const std::string& pos);
};

#endif // ROOK_H
