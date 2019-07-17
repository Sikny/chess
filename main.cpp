#include "game.h"

int main(int argc, char** argv){
    int boardSize = 8;
    float cellSize = 30.0f;
    Game game(boardSize*cellSize+cellSize*2, boardSize*cellSize+cellSize*2, "Chess");
    game.run();
}
