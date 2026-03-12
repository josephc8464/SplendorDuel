#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <memory>

#include "Card.h"
#include "Deck.h"

/*
*@brief The Board class represents the game board, which includes the tokens, cards, royal cards, and priveleges.
* 
*  The board class is responsible for holding the state of the board. It should not know about the players or the rules
*  of the game, only the actions taken from the game controller. Thus logic that inhibits players actions should be handled
*  in the game class. 
* 
*  The board class should hold the tier card decks, the visible tier cards, the royal cards, the bag of tokens, and the board priveleges.
*  Thus it acts more of a data structure for the game class to interact with, and not a controller of the game itself.
* 
* @author Joseph Corella
* @date 2026-03-08
*/
enum class ColorEnum { Red, Green, Blue, White, Black, Pearl, Gold };

class Board {
    public:
        class Position { int x; int y; };
        
        void refillGrid();
        std::vector<ColorEnum> takeTokens(std::vector<Position> gridPositions);
        Card takeVisibleTierCard(std::string tier, int position);
        Card takeDeckTierCard(std::string tier, int position);
        Card takeRoyalCard(int position);
		void takePrivilege();
        void resetBoard();

        //getters, setters
        Deck getTier1DeckCard();
		void setTier1DeckCard(Deck deck);

		Deck getTier2DeckCard();
		void setTier2DeckCard(Deck deck);

		Deck getTier3DeckCard();
        void setTier3DeckCard(Deck deck);

		std::vector<Card> getVisibleTier1();
		void setVisibleTier1(std::vector<Card> cards);

		std::vector<Card> getVisibleTier2();
		void setVisibleTier2(std::vector<Card> cards);

		std::vector<Card> getVisibleTier3();
        void setVisibleTier3(std::vector<Card> cards);

        std::vector<Card> getRoyals();
        void setRoyals(std::vector<Card> royals);

        std::vector<ColorEnum> getBagOfTokens();
        void setBagOfTokens(std::vector<ColorEnum> tokens);

        int getBoardPrivileges();
		void setBoardPrivileges(int privileges);
		
    private:
        ColorEnum tokens[5][5]; 
		Deck tier1Cards;
		Deck tier2Cards;
		Deck tier3Cards;

        std::vector<Card> visibleTier1;
		std::vector<Card> visibleTier2;
		std::vector<Card> visibleTier3;

        std::vector<Card> royals;
        std::vector<ColorEnum> bagOfTokens;
        int boardPrivileges;
};

#endif // BOARD_H