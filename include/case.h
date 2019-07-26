#ifndef CASE_H
#define CASE_H

#include <iostream>
#include <SFML/Graphics.hpp>

#include "Settings.h"

class Case {
    public:
        Case();
        Case(int, int);
        void draw(sf::RenderWindow& window);
        void hover();
        void unHover();
        void select();
        void unselect();
        bool hasMouseOver(sf::Vector2i mousePos);
        bool isSelected();

    private:
        float posRow, posCol;
        int row, col;
        bool selected;
        sf::Color color;
        sf::RectangleShape shape;
};

#endif // CASE_H
