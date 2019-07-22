#ifndef CHESS_PIECEFACTORY_H
#define CHESS_PIECEFACTORY_H


#include "chesspieces.h"

class PieceFactory {
public:
    static Piece* buildPiece(const std::string& name, sf::Color color, const std::string& position);
};


#endif //CHESS_PIECEFACTORY_H
