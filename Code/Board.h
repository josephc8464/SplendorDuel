#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include <deque>

#include "Card.h"
/*
*@brief The Board class represents the game board, which includes the tokens, cards, royal cards, and priveleges.
* tier1Cards - A deque of cards in tier 1, which are the cheapest cards that players can purchase. (5 of them are visible)
* tier2Cards - A deque of cards in tier 2, which are more expensive than tier 1 cards. (4 of them are visible)
* tier3Cards - A deque of cards in tier 3, which are the most expensive cards. (3 of them is visible)
* royals - ONLY FOUR OF THESE CARD EXIST, can be bought once three or six crowns have been obtained 
* priveleges - The number of priveleges on the board, which players can obtain by three actions on the board (or ability from a card)
* 
* Token - a 5x5 array of integers. Each integer corresponds to a token ID, which can be found in documentation.
* 
* @author Joseph Corella
* @date 2026-03-08
*/
class Board {
    public:
		int getToken(int row, int col) const { return *Token[row][col]; };
		int setToken(int row, int col, int value) { *Token[row][col] = value; };
        std::deque<Card> getTier1Cards() const{ return tier1Cards; };
         void setTier1Cards(const std::deque<Card>& cards){ tier1Cards = cards; };
         std::deque<Card> getTier2Cards() const{ return tier2Cards; };
         void setTier2Cards(const std::deque<Card>& cards){ tier2Cards = cards; };
         std::deque<Card> getTier3Cards() const{ return tier3Cards; };
         void setTier3Cards(const std::deque<Card>& cards){ tier3Cards = cards; };
         std::vector<Card> getRoyals() const{ return royals; };
         void setRoyals(const std::vector<Card>& cards){ royals = cards; };
         int getPriveleges() const{ return priveleges; };
		 void setPriveleges(int priveleges) { this->priveleges = priveleges; };
    
    private:
        int* Token[5][5]; 
        std::deque<Card> tier1Cards;
        std::deque<Card> tier2Cards;
        std::deque<Card> tier3Cards;
        std::vector<Card> royals;
        int priveleges;
};

#endif // BOARD_H