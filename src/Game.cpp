#include "../include/Game.h"
#include <cctype>
#include <iostream>
#include <limits>
#include <random>

using std::cout, std::endl, std::cin;

namespace 
{

	/*
	* @brief Function to validate player names. No restrictions on player names.
	* Returns confirmed name by user.
	* 
	* @param playerNum - used for printing player number when asking for name.
	* 
	* @author Joseph Corella
	* @date 2026-03-15
	*/
	std::string askForPlayerName(std::string playerNum) {
		std::string playerName;
		char response;

		do {
			std::cout << "Please enter player " << playerNum << " name: ";
			std::cin >> playerName;

			do {
				std::cout << "You entered " << playerName << ". Confirm name? (Y/N): ";
				std::cin >> response;

				//Clear the stream
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

				response = std::toupper(response);
			} while (response != 'Y' && response != 'N');

		} while (response == 'N');

		return playerName;
	}
}

/*
* @brief Checks if a player has satisfied one of three win conditions.
* 
* Players can win by three conditions:
* 1. By having 20 points across all bought cards (also know as prestiege points)
* 2. By having 10 crowns across all bought cards
* 3. By having 10 points across one color. (must be bought cards, for example: 3 red cards that add to 10 points wins the game)
* 
* Returns false if a player has not reached any of these win conditions.
* 
* @author Joseph Corella
* @date 2026-03-14
*/
bool Game::checkWinCondition(int pIndx) {
	Player p = players.at(pIndx);
	std::vector<Card> boughtCards = p.getBoughtCards();

	//Checking win condition 1
	if(p.getTotalPoints() > 20) 
	{
		return true;
	}

	//Checking win condition 2
	if(p.getCrowns() > 10) 
	{
		return true;
	}

	//Checking win condition 3
	if (boughtCards.size() > 1) {

		int totalColorSum = 0;
		Card prevCard = boughtCards.at(0);

		totalColorSum += prevCard.getPoints();

		for (int i = 1; i < boughtCards.size(); i++)
		{
			Card currCard = boughtCards.at(i);

			//Adds to total sum if cards have the same color.
			if (currCard.getColor() == prevCard.getColor()) {
				totalColorSum += currCard.getPoints();

				if (totalColorSum >= 20) {
					return true;
				}
			}

			//Otherwise start a new sum
			else {
				totalColorSum = currCard.getPoints();
			}

			
			prevCard = currCard;
		}
	}

	return false;
}

void Game::performAction(int pIndx) {

}

void Game::performOptionalAction(int pIndx) {

}

/*
* @brief initializes the game. Sets up the board, adds player names, chooses first player to start.
* 
* Creates new instances for the board to copy into its own memory.
* 
* @author Joseph Corella
* @date 2026-03-14
*/
void Game::startGame() {

	// --- SET PLAYER NAMES ---
	std::string name1, name2;

	/*name1 = askForPlayerName("1");
	name2 = askForPlayerName("2");

	players.at(0).setName(name1);
	players.at(1).setName(name2);*/
	
	//Board Setup
	board.boardSetUp();

	//Set the starting player
	int currentPlayer = std::uniform_int_distribution<int>(0, 1)(std::mt19937{ std::random_device{}() });

	currPIndx = currentPlayer;

	// ------------------- TITLE DISPLAY ------------------------------
	std::cout << R"(
   _____  _____  _      ______ _   _ _____   ____  _____  
  / ____||  __ \| |    |  ____| \ | |  __ \ / __ \|  __ \ 
 | (___  | |__) | |    | |__  |  \| | |  | | |  | | |__) |
  \___ \ |  ___/| |    |  __| | . ` | |  | | |  | |  _  / 
  ____) || |    | |____| |____| |\  | |__| | |__| | | \ \ 
 |_____/ |_|    |______|______|_| \_|_____/ \____/|_|  \_\
                                                          
   _____  _    _  _____  _      
  |  __ \| |  | || ____|| |     
  | |  | | |  | || |__  | |     
  | |  | | |  | ||  __| | |     
  | |__| | |__| || |____| |____ 
  |_____/ \____/ |______||______|
    )" << std::endl;
	
}

void Game::takeTurn() {

}

