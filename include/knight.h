#ifndef KNIGHT_H
#define KNIGHT_H

#include <piece.h>


class Knight : public Piece
{
    public:
        Knight(sf::Color);
        virtual bool canBeMoved(const std::string& pos);
        virtual bool isKnight();
};

#endif // KNIGHT_H
