#include "../include/Game.h"

using std::cout, std::endl, std::cin;

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
* @author Joseph Corella
* @date 2026-03-14
*/
void Game::startGame() {
	std::string name1, name2;

	cout << "Starting Game..." << endl;

	
	cout << "Player 1 name: " << endl;
	cin >> name1;
	
	cout << "Player 2 name: " << endl;
	cin >> name2;
	
	players.at(0).setName(name1);
	players.at(1).setName(name2);


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

