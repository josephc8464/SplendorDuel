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

    
    private:
        int* Token[5][5]; 
        std::deque<Card> tier1Cards;
        std::deque<Card> tier2Cards;
        std::deque<Card> tier3Cards;
        std::vector<Card> royals;
        int priveleges;
};

#endif // BOARD_H