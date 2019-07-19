#include "game.h"

using namespace std;

Game::Game() : Game(640, 480, "SFML Application"){}

Game::Game(int w, int h, const char* title)
 : boardSize(8), window(sf::VideoMode(w, h), title){
    cout << "Building board..." << endl;
    char maxChar = static_cast<char>(static_cast<int>('a')+boardSize-1);
    for(char col = 'a'; col <= maxChar; col++){
        for(int row = 1; row <= boardSize; row++){
            stringstream strStream;
            strStream << col << row;
            int intCol = static_cast<int>(col)-static_cast<int>('a');
            Case newCase(row-1, intCol, boardSize);
            board[strStream.str()] = newCase;
        }
    }
    cout << "Building Pieces..." << endl;
    // pawns
    for(int i = 0; i < 8; i++){
        char currentPos = static_cast<char>(i+static_cast<int>('a'));
        Pawn* white_pawn = new Pawn(sf::Color::White);
        white_pawn->setName("pawn");
        white_pawn->loadTexture();
        stringstream strStreamW;
        strStreamW << currentPos;
        strStreamW << 2; // white position;
        white_pawn->setPosition(strStreamW.str());
        whitePieces.push_back(white_pawn);
        Pawn* black_pawn = new Pawn(sf::Color::Black);
        black_pawn->setName("pawn");
        black_pawn->loadTexture();
        stringstream strStreamB;
        strStreamB << currentPos;
        strStreamB << 7; // white position;
        black_pawn->setPosition(strStreamB.str());
        blackPieces.push_back(black_pawn);
    }
    stringstream strStream;
    // kings
    King* white_king = new King(sf::Color::White);
    white_king->setName("king");
    white_king->loadTexture();
    strStream << 'e' << 1;
    white_king->setPosition(strStream.str());
    whitePieces.push_back(white_king);

    strStream.str("");
    King* black_king = new King(sf::Color::Black);
    black_king->setName("king");
    black_king->loadTexture();
    strStream << 'e' << 8;
    black_king->setPosition(strStream.str());
    blackPieces.push_back(black_king);

    strStream.str("");
    // queens
    Queen* white_Queen = new Queen(sf::Color::White);
    white_Queen->setName("queen");
    white_Queen->loadTexture();
    strStream << 'd' << 1;
    white_Queen->setPosition(strStream.str());
    whitePieces.push_back(white_Queen);

    strStream.str("");
    Queen* black_Queen = new Queen(sf::Color::Black);
    black_Queen->setName("queen");
    black_Queen->loadTexture();
    strStream << 'd' << 8;
    black_Queen->setPosition(strStream.str());
    blackPieces.push_back(black_Queen);

    strStream.str("");
    // rooks
    Rook* white_Rook1 = new Rook(sf::Color::White);
    white_Rook1->setName("rook");
    white_Rook1->loadTexture();
    strStream << 'a' << 1;
    white_Rook1->setPosition(strStream.str());
    whitePieces.push_back(white_Rook1);
    strStream.str("");
    Rook* white_Rook2 = new Rook(sf::Color::White);
    white_Rook2->setName("rook");
    white_Rook2->loadTexture();
    strStream << 'h' << 1;
    white_Rook2->setPosition(strStream.str());
    whitePieces.push_back(white_Rook2);
    strStream.str("");

    Rook* black_Rook1 = new Rook(sf::Color::Black);
    black_Rook1->setName("rook");
    black_Rook1->loadTexture();
    strStream << 'a' << 8;
    black_Rook1->setPosition(strStream.str());
    blackPieces.push_back(black_Rook1);
    strStream.str("");
    Rook* black_Rook2 = new Rook(sf::Color::Black);
    black_Rook2->setName("rook");
    black_Rook2->loadTexture();
    strStream << 'h' << 8;
    black_Rook2->setPosition(strStream.str());
    blackPieces.push_back(black_Rook2);
    strStream.str("");
    // bishops
    Bishop* white_Bishop1 = new Bishop(sf::Color::White);
    white_Bishop1->setName("bishop");
    white_Bishop1->loadTexture();
    strStream << 'c' << 1;
    white_Bishop1->setPosition(strStream.str());
    whitePieces.push_back(white_Bishop1);
    strStream.str("");
    Bishop* white_Bishop2 = new Bishop(sf::Color::White);
    white_Bishop2->setName("bishop");
    white_Bishop2->loadTexture();
    strStream << 'f' << 1;
    white_Bishop2->setPosition(strStream.str());
    whitePieces.push_back(white_Bishop2);
    strStream.str("");

    Bishop* black_Bishop1 = new Bishop(sf::Color::Black);
    black_Bishop1->setName("bishop");
    black_Bishop1->loadTexture();
    strStream << 'c' << 8;
    black_Bishop1->setPosition(strStream.str());
    blackPieces.push_back(black_Bishop1);
    strStream.str("");
    Bishop* black_Bishop2 = new Bishop(sf::Color::Black);
    black_Bishop2->setName("bishop");
    black_Bishop2->loadTexture();
    strStream << 'f' << 8;
    black_Bishop2->setPosition(strStream.str());
    blackPieces.push_back(black_Bishop2);
    strStream.str("");
    // knights
    Knight* white_Knight1 = new Knight(sf::Color::White);
    white_Knight1->setName("knight");
    white_Knight1->loadTexture();
    strStream << 'b' << 1;
    white_Knight1->setPosition(strStream.str());
    whitePieces.push_back(white_Knight1);
    strStream.str("");
    Knight* white_Knight2 = new Knight(sf::Color::White);
    white_Knight2->setName("knight");
    white_Knight2->loadTexture();
    strStream << 'g' << 1;
    white_Knight2->setPosition(strStream.str());
    whitePieces.push_back(white_Knight2);
    strStream.str("");

    Knight* black_Knight1 = new Knight(sf::Color::Black);
    black_Knight1->setName("knight");
    black_Knight1->loadTexture();
    strStream << 'b' << 8;
    black_Knight1->setPosition(strStream.str());
    blackPieces.push_back(black_Knight1);
    strStream.str("");
    Knight* black_Knight2 = new Knight(sf::Color::Black);
    black_Knight2->setName("knight");
    black_Knight2->loadTexture();
    strStream << 'g' << 8;
    black_Knight2->setPosition(strStream.str());
    blackPieces.push_back(black_Knight2);
    strStream.str("");
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
    window.clear(sf::Color(0, 74, 158));
    map<string,Case>::iterator it;
    for(it = board.begin(); it != board.end(); it++){
        it->second.draw(window);
    }
    vector<Piece*>::iterator itW, itB;
    for(itW = whitePieces.begin(); itW != whitePieces.end(); itW++){
        (*itW)->draw(window);
    }
    for(itB = blackPieces.begin(); itB != blackPieces.end(); itB++){
        (*itB)->draw(window);
    }
    window.display();
}
