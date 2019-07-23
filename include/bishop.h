#ifndef BISHOP_H
#define BISHOP_H

#include <piece.h>


class Bishop : public Piece
{
    public:
        explicit Bishop(sf::Color);
        bool canBeMoved(const std::string& pos) override;
};

#endif // BISHOP_H
