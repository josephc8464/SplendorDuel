#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include <deque>

#include "Card.h"

class Board {
    public:

    
    private:
        int* Token[5][5]; //Tokens on the board
        std::deque<Card> tier1Cards; //Cards in tier 1
        std::deque<Card> tier2Cards; //Cards in tier 2
        std::deque<Card> tier3Cards; //Cards in tier 3
        std::vector<Card> royals;    //Royal cards
        int priveleges; //number of priveleges on the board
};

#endif // BOARD_H