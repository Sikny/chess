#include "game.h"

Game::Game() : Game(640, 480, "SFML Application"){}

Game::Game(int w, int h, const char* title)
 : window(sf::VideoMode(w, h), title){
    std::cout << "Building board..." << std::endl;
}

void Game::run(){
    while(window.isOpen()){
        processEvents();
        update();
        render();
    }
}

void Game::processEvents(){
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update(){}

void Game::render(){
    window.clear();
    // draw here
    window.display();
}
