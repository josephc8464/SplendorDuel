#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "Player.h"
#include "Board.h"

/*
*@brief The game holds the game logic, and controls player to board interactions.
* 
*@author: Joseph Corella
*@date: 2026-03-08
*/


class Game {
    public:
		Player getCurrentPlayer() const { return players[currentPlayerIndex]; };
        void nextTurn() { currentPlayerIndex = (currentPlayerIndex + 1) % 2; };
        bool checkWinCondition(Player p);
		void performAction();

    
    private:
        Player players[2];
        Board board;
        int currentPlayerIndex;

};

#endif // GAME_H