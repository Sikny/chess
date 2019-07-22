#include "case.h"

Case::Case(){}

Case::Case(int row_p, int col_p, int boardSize_p)
: row(row_p), col(col_p), boardSize(boardSize_p),
caseSize(50.0f), selected(false) {
    if((col%2 == 0 && row%2 == 0) || (row%2 != 0 && col%2 != 0)){
        color = sf::Color(125, 135, 150);
    } else {
        color = sf::Color(232, 235, 239);
    }
    posCol = col*caseSize+caseSize-static_cast<float>(boardSize)/2;
    posRow = boardSize*caseSize-row*caseSize-static_cast<float>(boardSize)/2;
    shape = sf::RectangleShape(sf::Vector2f(caseSize, caseSize));
    shape.setPosition(posCol, posRow);
}

void Case::draw(sf::RenderWindow& window){
    if(!selected) shape.setFillColor(color);
    else shape.setFillColor(sf::Color::Red);
    window.draw(shape);
}

void Case::hover(){
    color.a = 150;
}

void Case::unhover(){
    color.a = 255;
}

void Case::select(){
    selected = true;
}

void Case::unselect(){
    selected = false;
}

bool Case::hasMouseOver(sf::Vector2i mousePos){
    return (mousePos.x >= posCol && mousePos.y >= posRow
        && mousePos.x < posCol+caseSize && mousePos.y < posRow+caseSize);
}

bool Case::isSelected() {
    return selected;
}