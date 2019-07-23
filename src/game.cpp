#include "game.h"

using namespace std;

Game::Game() : Game(640, 480, "SFML Application"){}

Game::Game(int w, int h, const char* title)
 : boardSize(8), window(sf::VideoMode(w, h), title) {
    font.loadFromFile("resources/fonts/arial.ttf");
    currentPlayerDisplay.setFont(font);

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
    currentPlayer = sf::Color::White;
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
                        board[strStream.str()].unselect();
                    } else if(board[strStream.str()].hasMouseOver(mousePos)) {
                        Piece* piece = getPieceAtPos(strStream.str());
                        if(piece != nullptr) {
                            selectedPiece = piece;
                            board[strStream.str()].select();
                        } else if(selectedPiece != nullptr && selectedPiece->getColor() == currentPlayer &&
                        (selectedPiece->isKnight() || (!selectedPiece->isKnight()
                                && !isObstructed(selectedPiece->getPosition(), strStream.str())))){
                            if(selectedPiece->move(strStream.str()))
                                currentPlayer = currentPlayer==sf::Color::White?sf::Color::Black:sf::Color::White;
                            selectedPiece = nullptr;
                        }
                    }
                    strStream.str("");
                }
            }
        }
    }
}

void Game::update(){
    currentPlayerDisplay.setString(std::string(currentPlayer==sf::Color::White?"White":"Black")+" turn");
    currentPlayerDisplay.setFillColor(currentPlayer);
    currentPlayerDisplay.setPosition(sf::Vector2f(
            window.getView().getSize().x/2-currentPlayerDisplay.getGlobalBounds().width/2, 0));
}

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
    window.draw(currentPlayerDisplay);
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

bool Game::isObstructed(const std::string &position, const std::string &dest) {
    int colFrom = position.at(1) - '0';
    int colDest = dest.at(1) - '0';
    char rowFrom = position.at(0);
    char rowDest = dest.at(0);
    std::stringstream tmpPos;
    if(colFrom == colDest){ // vertically
        for(char c = std::min(rowFrom, rowDest)+1; c < std::max(rowFrom, rowDest); c++){
            tmpPos << c << colFrom;
            if(getPieceAtPos(tmpPos.str()) != nullptr)
                return true;
            tmpPos.str("");
        }
    } else if(rowFrom == rowDest){  // horizontally
        for(int i = std::min(colFrom, colDest)+1; i < std::max(colFrom, colDest); i++){
            tmpPos << rowFrom << i;
            if(getPieceAtPos(tmpPos.str()) != nullptr)
                return true;
            tmpPos.str("");
        }
    } else if(colDest-colFrom == std::abs(rowDest-rowFrom)) { // diagonals
        int rowChg = signbit(rowDest - rowFrom)?-1:1;
        int colChg = signbit(colDest - colFrom)?-1:1;
        for(int i = 1; i < std::abs(colDest-colFrom); i++){
            tmpPos << static_cast<char>(rowFrom+rowChg) << (colFrom+colChg);
            if(getPieceAtPos(tmpPos.str()))
                return true;
        }
    }
    return false;
}