#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class Piece {
    public:
        explicit Piece(sf::Color color);
        std::string getPosition();
        void setPosition(const std::string& pos);
        void draw(sf::RenderWindow& window);
        void setName(const std::string& name);
        void loadTexture();
        bool move(const std::string& pos);
        virtual bool isKnight();
        sf::Color getColor();

    protected:
        std::string imageName();
        virtual bool canBeMoved(const std::string& pos) = 0;

        sf::Color color;
        float cellSize;
        int boardSize;
        std::string position;
        std::string name;

        sf::Sprite sprite;
        sf::Texture texture;
};

#endif // PIECE_H
