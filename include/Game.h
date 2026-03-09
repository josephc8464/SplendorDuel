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
*  players - there are only allowed to be 2 players, there must also be two players to play
*  board - the holder of the data on the board
*  currentPlayerIndex - the index of the player whose turn it is
*  winningPlayerIndex - the index of the player who has won the game, -1 if no winner yet
* 
*@author: Joseph Corella
*@date: 2026-03-08
*/


class Game {
    public:
		Player getCurrentPlayer() const { return players[currentPlayerIndex]; };
        void nextTurn() { currentPlayerIndex = (currentPlayerIndex + 1) % 2; };
        bool checkWinCondition();
		void performAction();

    
    private:
        Player players[2];
        Board board;
        int currentPlayerIndex;
        int winningPlayerIndex = -1;

};

#endif // GAME_H