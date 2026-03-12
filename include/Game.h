#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <array>
#include "Player.h"
#include "Board.h"

/*
*@brief The game holds the game logic, and controls player to board interactions.
*
* The board should not know about the players, and the players should not know about the board. The game
* handles all interactions of players and the board by only permitting and displaying valid options. In addition,
* the game can concurrently handle win conditions, royal card additions and handle data integrity transfers between
* both the board and players. 
* 
* Thus player and board functions are only setters and accessors to help assist in the performance of the game, since
* all of the game logic and object transfers will take place in the game class itself.
*
*@author: Joseph Corella
*@date: 2026-03-08
*/

class Game {
    public:
        //Constructor
        Game() : currentPlayerIndex(2) {}

        Player& getCurrentPlayer() { return players[currentPlayerIndex]; }
        void nextTurn() { currentPlayerIndex = (currentPlayerIndex + 1) % 2; }

        void startGame();
        void takeTurn();
        bool checkWinCondition(Player p);
		void performAction(Player p);
        void performOptionalAction(Player p);
    
    private:
        std::array<Player, 2> players;
        Board board;
        int currentPlayerIndex;

};

#endif // GAME_H