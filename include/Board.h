#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>

#include "Card.h"
#include "Deck.h"

/*
*@brief The Board class represents the game board, which includes the tokens, cards, royal cards, and priveleges.
* 
* @author Joseph Corella
* @date 2026-03-08
*/
class Board {
    public:
        class Positon {int x, int y};

		
    private:
		enum class ColorEnum { Red, Green, Blue, White, Black, Pearl, Gold };

        ColorEnum tokens[5][5]; 
		Deck tier1Cards;
		Deck tier2Cards;
		Deck tier3Cards;

        std::vector<Card> visibleTier1;
		std::vector<Card> visibleTier2;
		std::vector<Card> visibleTier3;

        std::vector<Card> royals;
        std::vector<ColorEnum> bagOfTokens;
        int boardPriveleges;
};

#endif // BOARD_H