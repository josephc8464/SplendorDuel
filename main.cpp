#include <iostream>
#include "include/Game.h"
#include "include/Card.h"

using std::cout, std::endl;

int main() {
    Game game;
    
	cout << "Welcome To The Game!" << endl;

    game.startGame();

    return 0;
}