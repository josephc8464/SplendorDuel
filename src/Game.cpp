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

	/*
	name1 = askForPlayerName("1");
	name2 = askForPlayerName("2");

	players.at(0).setName(name1);
	players.at(1).setName(name2);
	*/
	
	// --- Initialize the bag of Tokens and disperse the tokens onto the board ---
	std::vector<ColorEnum> tempBag;

	for (int i = 0; i < 4; i++) {
		tempBag.push_back(ColorEnum::Red);
		tempBag.push_back(ColorEnum::Green);
		tempBag.push_back(ColorEnum::Blue);
		tempBag.push_back(ColorEnum::Black);
		tempBag.push_back(ColorEnum::White);
	}
	tempBag.push_back(ColorEnum::Gold);
	tempBag.push_back(ColorEnum::Gold);
	tempBag.push_back(ColorEnum::Gold);
	tempBag.push_back(ColorEnum::Pearl);
	tempBag.push_back(ColorEnum::Pearl);

	board.setBagOfTokens(tempBag);
	board.refillGrid();
	
	/*
	*  --------------------------------- Scan in decks into board class. ------------------------------------------
	* 
	* tempDeck is used multiple times to read in data from CSV file.
	* Since royals cards are an array, the tempDeck is popped four times to move the royal cards into the Royal Array.
	*/
	Deck tempDeck;

	tempDeck.loadFromCSV("deck/firstTier.csv");
	board.setTier1DeckCard(tempDeck);
	tempDeck.reset();

	tempDeck.loadFromCSV("deck/secondTier.csv");
	board.setTier2DeckCard(tempDeck);
	tempDeck.reset();

	tempDeck.loadFromCSV("deck/thirdTier.csv");
	board.setTier3DeckCard(tempDeck);
	tempDeck.reset();

	tempDeck.loadFromCSV("deck/royalCards.csv");
	std::array<Card, 4> newRoyals;

	//Add royals
	for (int i = 0; i < 4; i++) {
		newRoyals.at(i) = tempDeck.drawCard();
	}

	// -- Setup visible tier cards ---
	// Same idea here, since visible tiers are an array of cards, the deck is drawn upon by the corresponding amount.

	std::array<Card, 5> vTier1 = {};
	std::array<Card, 4> vTier2 = {};
	std::array<Card, 3> vTier3 = {};

	for (int i = 0; i < 5; i++) {
		vTier1.at(i) = board.getTier1DeckCard().drawCard();

		if (i < 4) {
			vTier2.at(i) = board.getTier2DeckCard().drawCard();
		}
		if (i < 3) {
			vTier3.at(i) = board.getTier3DeckCard().drawCard();
		}
	}

	board.setVisibleTier1Cards(vTier1);
	board.setVisibleTier2Cards(vTier2);
	board.setVisibleTier3Cards(vTier3);

	int currentPlayer = std::uniform_int_distribution<int>(0, 1)(std::mt19937{ std::random_device{}() });

	currPIndx = currentPlayer;
	cout << "Current Player: " << currPIndx;

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

