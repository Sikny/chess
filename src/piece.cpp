#include "piece.h"

Piece::Piece(sf::Color color_p) : color(color_p), cellSize(50.0f), boardSize(8){}

std::string Piece::getPosition(){
    return position;
}

void Piece::setPosition(std::string pos){
    position = pos;
    char col = position.at(0);
    int row = static_cast<int>(position.at(1)-'0')-1;
    int intCol = static_cast<int>(col)-static_cast<int>('a');
    float paddingX = cellSize-(static_cast<float>(texture.getSize().x)*sprite.getScale().x);
    float paddingY = cellSize-(static_cast<float>(texture.getSize().y)*sprite.getScale().y);
    std::cout << paddingX << ", " << paddingY << std::endl;
    sprite.setPosition(sf::Vector2f(intCol*cellSize+cellSize-boardSize/2+paddingX/2, row*cellSize+cellSize-boardSize/2+paddingY/2));
}

std::string Piece::imageName(){
    std::string imgName = "resources/images/";
    if(color == sf::Color::White)
        imgName += "white";
    else imgName += "black";
    imgName += "_" + name + ".png";
    return imgName;
}

void Piece::setName(std::string newName){
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
    float destSize = cellSize - 5;
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
