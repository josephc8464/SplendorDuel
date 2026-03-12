#ifndef CARD_H
#define CARD_H

#include <string>
#include <array>
/*
* @brief Holds the information of a card, including its gem color, points, cost, crowns, and ability.
* 
* In Splendor Duel, there are two types of cards, tier cards and royals.
* 
* Tier cards can have "gemAdditions" which add permanent tokens in the player's inventory.
* Tier cards can also have abilities or points that are used by the player to help them reach the three win conditions.
* 
* Royals have "crowns" and abilities that can be used when the player has enough crowns to get the royal card.
* 
* The card should override the regular comparator operator, so that vectors can sort cards by color and by points.
* This will be most important in the player class when the game needs to display the cards of a player.
* 
* @author: Joseph Corella
* @date: 2026-03-08
*/


class Card {
    public:
        int id;

        std::array<int, 7> cost;
        enum class bonusColor{ Red, Green, Blue, White, Black, RedTwo, BlueTwo, GreenTwo, WhiteTwo, BlackTwo, None }; //RedTwo - represents two bonus red gems
        enum class ability { None, StealAToken, GetPrivelege, TakeAToken, TakeAnotherTurn, BonusJewel };
        
        int points;
        int crowns;
};

#endif