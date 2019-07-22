#include "PieceFactory.h"

Piece* PieceFactory::buildPiece(const std::string& name, sf::Color color, const std::string& position) {
    Piece* piece = nullptr;
    if(name == "pawn"){
        piece = new Pawn(color);
    } else if(name == "king") {
        piece = new King(color);
    } else if(name == "queen"){
        piece = new Queen(color);
    } else if(name == "bishop") {
        piece = new Bishop(color);
    } else if(name == "rook"){
        piece = new Rook(color);
    } else if(name == "knight"){
        piece =  new Knight(color);
    }
    piece->setName(name);
    piece->loadTexture();
    piece->setPosition(position);
    return piece;
}