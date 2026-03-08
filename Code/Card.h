#ifndef CARD_H
#define CARD_H

#include <string>
/*
*
*/


class Card {
    public:
        enum class GemColor { Red, Green, Blue, White, Black}; //Gem Color
        int gemAddition; //Number of permanent gems the card provides
        int points; //Number of points the card provides
        int cost[6]; //Cost of the card
        int crowns; //Number of crowns the card provides
        enum class ability {None, StealAToken, GetPrivelege, TakeAToken, TakeAnotherTurn, BonusJewel}; //Ability of the card
};

#endif