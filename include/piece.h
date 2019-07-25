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
        void setAbsolutePosition(const sf::Vector2f& pos);
        sf::Vector2f getAbsolutePosition();
        void draw(sf::RenderWindow& window);
        void setName(const std::string& name);
        std::string getName();
        void loadTexture();
        bool move(const std::string& pos);
        sf::Color getColor();
        virtual bool canBeMoved(const std::string& pos) = 0;

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
