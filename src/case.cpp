#include "case.h"

Case::Case(){}

Case::Case(int row_p, int col_p, int boardSize_p)
: row(row_p), col(col_p), boardSize(boardSize_p),
caseSize(50.0f) {
    if((col%2 == 0 && row%2 == 0) || (row%2 != 0 && col%2 != 0)){
        color = sf::Color(232, 235, 239);
    } else {
        color = sf::Color(125, 135, 150);
    }
    posCol = col*caseSize+caseSize-boardSize/2;
    posRow = row*caseSize+caseSize-boardSize/2;
    shape = sf::RectangleShape(sf::Vector2f(caseSize, caseSize));
    shape.setPosition(posRow, posCol);
}

void Case::draw(sf::RenderWindow& window){
    shape.setFillColor(color);
    window.draw(shape);
}
