#include "../include/Board.h"
#include <random>
#include <iostream>

/*
* @brief prints out all the variables of the board in terminal. For development and testing.
* 
* @author Joseph Corella
* @date 2026-03-14
*/
void Board::printBoard() {
	
	for (int i = 0; i < 4; i++) {
		for(int j=0; j<4; j++) {
			std::cout << "[ " << colorToString(tokens[i][j]) << "] ";
		}
		std::cout << std::endl;
	}
}

/*
* @brief Refills the token grid in a spiral pattern. Stops when the bag of tokens is empty.
* 
* @author Joseph Corella
* @date 2026-03-14
*/
void Board::refillGrid() {
	static const int SPIRAL_X[] = { 2, 2, 3, 3, 3, 2, 1, 1, 1, 1, 2, 3, 4, 4, 4, 4, 4, 3, 2, 1, 0, 0, 0, 0, 0 };
	static const int SPIRAL_Y[] = { 2, 3, 3, 2, 1, 1, 1, 2, 3, 4, 4, 4, 4, 3, 2, 1, 0, 0, 0, 0, 0, 1, 2, 3, 4 };

	std::shuffle(bagOfTokens.begin(), bagOfTokens.end(), std::default_random_engine());

	for(int i=0; i<25; i++) {
		int x = SPIRAL_X[i];
		int y = SPIRAL_Y[i];

		if(tokens[x][y] == ColorEnum::Empty && !bagOfTokens.empty() ) {
			tokens[x][y] = bagOfTokens.back();
			bagOfTokens.pop_back();
		}
	}
}

/*
* @brief resets the board back to a default state. Empties the cards, tokens and bag. Returns privileges to 3.
* 
* @author Joseph Corella
* @date 2026-03-14
*/
void Board::resetBoard() {

	for (int i = 0; i < 5; i++) {
		for(int j=0; j<5; j++) {
			tokens[i][j] = ColorEnum::Empty;
		}
	}

	tier1Cards.reset();
	tier2Cards.reset();
	tier3Cards.reset();

	visibleTier1 = {};
	visibleTier2 = {};
	visibleTier3 = {};

	royals = {};

	bagOfTokens.clear();

	boardPrivileges = 3;
}

/*
* @brief Takes up to 3 tokens in sequence. Contains no game logic, is given a vector of positions to take from the tokenGrid array.
* 
* @author Joseph Corella
* @date 2026-03-14
*/
std::vector<ColorEnum> Board::takeTokens(std::vector<Board::Position> gridPositions) {
	
	std::vector<ColorEnum> tokensTaken;

	for(int i=0; i<gridPositions.size(); i++) {
		tokensTaken.push_back(tokens[gridPositions.at(i).x][gridPositions.at(i).y]);
		tokens[gridPositions.at(i).x][gridPositions.at(i).y] = ColorEnum::Empty;
	}

	return tokensTaken;
}