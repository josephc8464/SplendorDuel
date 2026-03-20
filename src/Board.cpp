#include "../include/Board.h"
#include <random>
#include <iostream>
#include <algorithm>
#include <iomanip>

void Board::printRow(const std::vector<Card>& row, std::string label) const {
	if (row.empty()) return;

	std::cout << "--- " << label << " ---" << std::endl;

	// 1. Gather all lines for each card in the row
	std::vector<std::vector<std::string>> allLines;
	for (const auto& card : row) {
		allLines.push_back(card.getCardLines());
	}

	// 2. Print across: Row 0 of Card A, then Row 0 of Card B...
	size_t rowHeight = allLines[0].size();
	for (size_t i = 0; i < rowHeight; ++i) {
		for (size_t j = 0; j < allLines.size(); ++j) {
			std::cout << allLines[j][i] << "   "; // Space between cards
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}
/*
* @brief prints out all the variables of the board in terminal. For development and testing.
* 
* @author Joseph Corella
* @date 2026-03-14
*/
void Board::printBoard() const {
	
	// --- Print out Royals ---
	std::vector<Card> r(royals.begin(), royals.end());
	printRow(r, "ROYALS");

	// --- Print out the token grid as an asterisk grid with the token color in each cell ---
	const int rows = 5;
	const int cols = 5;
	const int cellWidth = 8; // adjust if you need wider cells
	const int borderLen = cols * (cellWidth + 3) + 1; // calculates total '*' per border line

	std::cout << " --- TOKEN GRID --- " << std::endl;
	for (int i = 0; i < rows; ++i) {
		// top border for this row
		std::cout << std::string(borderLen, '*') << std::endl;

		// content row: | <color> | <color> | ...
		std::cout << "*";
		for (int j = 0; j < cols; ++j) {
			std::string name = colorToString(tokens[i][j]);
			std::cout << " " << std::setw(cellWidth) << std::left << name << " *";
		}
		std::cout << std::endl;
	}

	// final bottom border
	std::cout << std::string(borderLen, '*') << std::endl << std::endl;

	// --- Print out visible tier cards ---
	// Print Tier 3 (3 cards)
	std::vector<Card> t3(visibleTier3.begin(), visibleTier3.end());
	printRow(t3, "TIER 3");

	// Print Tier 2 (4 cards)
	std::vector<Card> t2(visibleTier2.begin(), visibleTier2.end());
	printRow(t2, "TIER 2");

	// Print Tier 1 (5 cards)
	std::vector<Card> t1(visibleTier1.begin(), visibleTier1.end());
	printRow(t1, "TIER 1");
}	

/*
* @brief Set up the board after initialization.
*  - Fills the decks of cards, fills the visible tier cards.
*  - Fills the royal cards
*  - Fills the bag of tokens and disperses tokens using the refillGrid
*  - Reset the board privileges to 3
* 
* @author Joseph Corella
* @date 2026-03-18
*/
void Board::boardSetUp() {
	// --- Initialize the bag of Tokens and disperse the tokens onto the board ---
	for (int i = 0; i < 4; i++) {
		bagOfTokens.push_back(ColorEnum::Red);
		bagOfTokens.push_back(ColorEnum::Green);
		bagOfTokens.push_back(ColorEnum::Blue);
		bagOfTokens.push_back(ColorEnum::Black);
		bagOfTokens.push_back(ColorEnum::White);
	}
	bagOfTokens.push_back(ColorEnum::Gold);
	bagOfTokens.push_back(ColorEnum::Gold);
	bagOfTokens.push_back(ColorEnum::Gold);
	bagOfTokens.push_back(ColorEnum::Pearl);
	bagOfTokens.push_back(ColorEnum::Pearl);

	refillGrid();

	/*
	*  --------------------------------- Scan in decks into board class. ------------------------------------------
	*
	* tier cards are load in the csv file card information directly into their decks.
	* Since royals cards are an array, the tempDeck is popped four times to move the royal cards into the Royal Array.
	*/
	Deck tempDeck;

	tier1Cards.loadFromCSV("deck/firstTier.csv");
	tier2Cards.loadFromCSV("deck/secondTier.csv");
	tier3Cards.loadFromCSV("deck/thirdTier.csv");
	tempDeck.loadFromCSV("deck/royalCards.csv");

	//Add royals
	for (int i = 0; i < 4; i++) {
		royals.at(i) = tempDeck.drawCard();
	}

	// -- Setup visible tier cards ---
	// Same idea here, since visible tiers are an array of cards, the deck is drawn upon by the corresponding amount.

	tier1Cards.shuffle();
	tier2Cards.shuffle();
	tier3Cards.shuffle();

	for (int i = 0; i < 5; i++) {
		visibleTier1.at(i) = tier1Cards.drawCard();

		if (i < 4) {
			visibleTier2.at(i) = tier2Cards.drawCard();
		}
		if (i < 3) {
			visibleTier3.at(i) = tier3Cards.drawCard();
		}
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

	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(bagOfTokens.begin(), bagOfTokens.end(), g);

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