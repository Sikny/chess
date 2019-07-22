#include "game.h"

using namespace std;

Game::Game() : Game(640, 480, "SFML Application"){}

Game::Game(int w, int h, const char* title)
 : boardSize(8), window(sf::VideoMode(w, h), title) {
    cout << "Building board..." << endl;
    char maxChar = static_cast<char>(static_cast<int>('a') + boardSize - 1);
    for (char col = 'a'; col <= maxChar; col++) {
        for (int row = boardSize; row >= 1; row--) {
            stringstream strStream;
            strStream << col << row;
            int intCol = static_cast<int>(col) - static_cast<int>('a');
            Case newCase(row - 1, intCol, boardSize);
            board[strStream.str()] = newCase;
        }
    }
    cout << "Building Pieces..." << endl;
    stringstream strStream;
    // pawns
    for (int i = 0; i < 8; i++) {
        char currentPos = static_cast<char>(i + static_cast<int>('a'));
        strStream << currentPos;
        strStream << 2;
        whitePieces.push_back(PieceFactory::buildPiece("pawn", sf::Color::White, strStream.str()));
        strStream.str("");
        strStream << currentPos;
        strStream << 7; // white position;
        blackPieces.push_back(PieceFactory::buildPiece("pawn", sf::Color::Black, strStream.str()));
        strStream.str("");
    }
    // kings
    whitePieces.push_back(PieceFactory::buildPiece("king", sf::Color::White, "e1"));
    blackPieces.push_back(PieceFactory::buildPiece("king", sf::Color::Black, "e8"));
    // queens
    whitePieces.push_back(PieceFactory::buildPiece("queen", sf::Color::White, "d1"));
    blackPieces.push_back(PieceFactory::buildPiece("queen", sf::Color::Black, "d8"));
    // rooks
    whitePieces.push_back(PieceFactory::buildPiece("rook", sf::Color::White, "a1"));
    whitePieces.push_back(PieceFactory::buildPiece("rook", sf::Color::White, "h1"));

    blackPieces.push_back(PieceFactory::buildPiece("rook", sf::Color::Black, "a8"));
    blackPieces.push_back(PieceFactory::buildPiece("rook", sf::Color::Black, "h8"));
    // bishops
    whitePieces.push_back(PieceFactory::buildPiece("bishop", sf::Color::White, "c1"));
    whitePieces.push_back(PieceFactory::buildPiece("bishop", sf::Color::White, "f1"));

    blackPieces.push_back(PieceFactory::buildPiece("bishop", sf::Color::Black, "c8"));
    blackPieces.push_back(PieceFactory::buildPiece("bishop", sf::Color::Black, "f8"));
    // knights
    whitePieces.push_back(PieceFactory::buildPiece("knight", sf::Color::White, "b1"));
    whitePieces.push_back(PieceFactory::buildPiece("knight", sf::Color::White, "g1"));

    blackPieces.push_back(PieceFactory::buildPiece("knight", sf::Color::Black, "b8"));
    blackPieces.push_back(PieceFactory::buildPiece("knight", sf::Color::Black, "g8"));

    selectedPiece = nullptr;
}

void Game::run(){
    while(window.isOpen()){
        processEvents();
        update();
        render();
    }
}

void Game::processEvents(){
    sf::Event event = sf::Event();
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        else if(event.type == sf::Event::MouseMoved) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            char maxChar = static_cast<char>(static_cast<int>('a') + boardSize - 1);
            for (char col = 'a'; col <= maxChar; col++) {
                for (int row = boardSize; row >= 1; row--) {
                    stringstream strStream;
                    strStream << col << row;
                    if (board[strStream.str()].hasMouseOver(mousePos)) {
                        board[strStream.str()].hover();
                    } else {
                        board[strStream.str()].unhover();
                    }
                }
            }
        } else if(event.type == sf::Event::MouseButtonReleased){
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            char maxChar = static_cast<char>(static_cast<int>('a') + boardSize - 1);
            for (char col = 'a'; col <= maxChar; col++) {
                for (int row = boardSize; row >= 1; row--) {
                    stringstream strStream;
                    strStream << col << row;
                    if(board[strStream.str()].isSelected()){
                        cout << "unselect: " << strStream.str() << endl;
                        board[strStream.str()].unselect();
                    } else if(board[strStream.str()].hasMouseOver(mousePos)) {
                        Piece* piece = getPieceAtPos(strStream.str());
                        if(piece != nullptr) {
                            selectedPiece = piece;
                            board[strStream.str()].select();
                            cout << "select: " << strStream.str() << endl;
                        } else if(selectedPiece != nullptr){
                            cout << "moving from: " << selectedPiece->getPosition() << " to: " << strStream.str() << endl;
                            selectedPiece->move(strStream.str());
                            selectedPiece = nullptr;
                        }
                    }
                    strStream.str("");
                }
            }
        }
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

Piece* Game::getPieceAtPos(const std::string &position) {
    for(auto & whitePiece : whitePieces){
        if(whitePiece->getPosition() == position)
            return whitePiece;
    }
    for(auto & blackPiece : blackPieces) {
        if (blackPiece->getPosition() == position)
            return blackPiece;
    }
    return nullptr;
}