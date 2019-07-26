#include "case.h"

Case::Case()= default;

Case::Case(int row_p, int col_p)
: row(row_p), col(col_p), selected(false) {
    if((col%2 == 0 && row%2 == 0) || (row%2 != 0 && col%2 != 0)){
        color = sf::Color(125, 135, 150);
    } else {
        color = sf::Color(232, 235, 239);
    }
    posCol = col*Settings::cellSize+Settings::cellSize-static_cast<float>(Settings::boardSize)/2;
    posRow = Settings::boardSize*Settings::cellSize+Settings::cellSize-row*Settings::cellSize-static_cast<float>(Settings::boardSize)/2;
    shape = sf::RectangleShape(sf::Vector2f(Settings::cellSize, Settings::cellSize));
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

void Case::unHover(){
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
        && mousePos.x < posCol+Settings::cellSize && mousePos.y < posRow+Settings::cellSize);
}

bool Case::isSelected() {
    return selected;
}