#include "game.h"
#include "Settings.h"


int main(int argc, char** argv){
    Game game(Settings::boardSize*Settings::cellSize+Settings::cellSize*2,
            Settings::boardSize*Settings::cellSize+Settings::cellSize*4, "Chess");
    game.run();
}
