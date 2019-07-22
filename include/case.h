#ifndef CASE_H
#define CASE_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Case {
    public:
        Case();
        Case(int, int, int);
        void draw(sf::RenderWindow& window);
        void hover();
        void unhover();
        void select();
        void unselect();
        bool hasMouseOver(sf::Vector2i mousePos);
        bool isSelected();

    private:
        float posRow, posCol;
        int row, col;
        int boardSize;
        float caseSize;
        bool selected;
        sf::Color color;
        sf::RectangleShape shape;
};

#endif // CASE_H
