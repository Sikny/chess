#ifndef BISHOP_H
#define BISHOP_H

#include <piece.h>


class Bishop : public Piece
{
    public:
        Bishop(sf::Color);
        virtual bool canBeMoved(const std::string& pos);
};

#endif // BISHOP_H
