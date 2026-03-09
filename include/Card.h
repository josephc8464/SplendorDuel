#ifndef CARD_H
#define CARD_H

#include "Cost.h"
#include <string>
/*
* @brief Holds the information of a card, including its gem color, points, cost, crowns, and ability.
* 
* In Splendor Duel, there are two types of cards, tier cards and royals.
* 
* - Tier cards can have "gemAdditions" which add permanent tokens in the player's inventory.
* Tier cards can also have abilities or points that are used by the player to help them reach the three win conditions.
* 
- Royals have "crowns" and abilities that can be used when the player has enough crowns to get the royal card.
* 
* @author: Joseph Corella
* @date: 2026-03-08
*/


class Card {
    public:
        int id;
		enum class bonusColor{ Red, Green, Blue, White, Black, RedTwo, BlueTwo, GreenTwo, WhiteTwo, BlackTwo, None };
        int points;
		Cost cost; 
        int crowns;
        enum class ability {None, StealAToken, GetPrivelege, TakeAToken, TakeAnotherTurn, BonusJewel};
};

#endif