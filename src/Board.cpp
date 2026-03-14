#include "../include/Board.h"
#include <random>

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

void Board::resetBoard() {

	std::fill(&tokens[0][0], &tokens[0][0] + (5 * 5), ColorEnum::Empty);

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

std::vector<ColorEnum> Board::takeTokens(std::vector<Board::Position> gridPositions) {
	
	std::vector<ColorEnum> tokensTaken;

	for(int i=0; i<gridPositions.size(); i++) {
		tokensTaken.push_back(tokens[gridPositions.at(i).x][gridPositions.at(i).y]);
		tokens[gridPositions.at(i).x][gridPositions.at(i).y] = ColorEnum::Empty;
	}

	return tokensTaken;
}