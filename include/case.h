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
        bool hasMouseOver(sf::Vector2i mousePos);

    private:
        float posRow, posCol;
        int row, col;
        int boardSize;
        float caseSize;
        sf::Color color;
        sf::RectangleShape shape;
};

#endif // CASE_H
