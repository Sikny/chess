#include "piece.h"

Piece::Piece(sf::Color color_p) : color(color_p){}

std::string Piece::getPosition(){
    return position;
}

void Piece::setPosition(const std::string& pos){
    position = pos;
    char col = position.at(0);
    int row = static_cast<int>(position.at(1)-'0')-1;
    int intCol = static_cast<int>(col)-static_cast<int>('a');
    float paddingX = Settings::cellSize-(static_cast<float>(texture.getSize().x)*sprite.getScale().x);
    float paddingY = Settings::cellSize*3-(static_cast<float>(texture.getSize().y)*sprite.getScale().y);
    sprite.setPosition(sf::Vector2f(intCol*Settings::cellSize+Settings::cellSize-static_cast<float>(Settings::boardSize)/2+paddingX/2,
            static_cast<float>(Settings::boardSize)*Settings::cellSize-row*Settings::cellSize-static_cast<float>(Settings::boardSize)/2+paddingY/2));
}

sf::Vector2f Piece::getAbsolutePosition(){
    return sprite.getPosition();
}

void Piece::setAbsolutePosition(const sf::Vector2f& pos){
    sprite.setPosition(pos);
}

std::string Piece::imageName(){
    std::string imgName = "resources/images/";
    if(color == sf::Color::White)
        imgName += "white";
    else imgName += "black";
    imgName += "_" + name + ".png";
    return imgName;
}

void Piece::setName(const std::string& newName){
    name = newName;
}

void Piece::loadTexture(){
    if(!texture.loadFromFile(imageName())){
        std::cout << "Error loading image " << imageName() << std::endl;
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sf::Vector2u textureSize = texture.getSize();
    float imageRatio = static_cast<float>(textureSize.x)/static_cast<float>(textureSize.y);
    float growthRatio;
    float destSize = Settings::cellSize - 5;
    if(imageRatio > 1){
        growthRatio = (destSize/static_cast<float>(textureSize.x));
    } else {
        growthRatio = (destSize/static_cast<float>(textureSize.y));
    }
    sprite.scale(sf::Vector2f(growthRatio, growthRatio));
}

void Piece::draw(sf::RenderWindow& window){
    window.draw(sprite);
}

bool Piece::move(const std::string &pos) {
    if(canBeMoved(pos)){
        std::cout << position << " " << pos << std::endl;
        setPosition(pos);
        return true;
    }
    return false;
}

sf::Color Piece::getColor() {
    return color;
}

std::string Piece::getName() {
    return name;
}
