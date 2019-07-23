#include "game.h"

int main(int argc, char** argv){
    int boardSize = 8;  // 8*8 board
    float cellSize = 50.0f;
    Game game(boardSize*cellSize+cellSize*2,
            boardSize*cellSize+cellSize*4, "Chess");
    game.run();
}
