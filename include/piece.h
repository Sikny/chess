#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class Piece {
    public:
        Piece(sf::Color color);
        std::string getPosition();
        void setPosition(std::string pos);
        void draw(sf::RenderWindow& window);
        void setName(std::string name);
        void loadTexture();

    protected:
        std::string imageName();

        sf::Color color;
        float cellSize;
        int boardSize;
        std::string position;
        std::string name;

        sf::Sprite sprite;
        sf::Texture texture;
};

#endif // PIECE_H
