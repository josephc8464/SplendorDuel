#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "Player.h"
#include "Board.h"

class Game {
    public:
        Player players[2]; //Array of players
        Board board; //Game board
        int currentPlayerIndex; //Index of the current player
        int winningPlayerIndex; //Index of the winning player
        
    private:
        bool isRunning;

};

#endif // GAME_H