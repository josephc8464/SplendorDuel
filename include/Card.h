#ifndef CARD_H
#define CARD_H

#include <string>
#include <array>
/*
* @brief Holds the information of a card, including its gem color, points, cost, crowns, and ability.
* 
* In Splendor Duel, there are two types of cards, tier cards and royals.
* 
* Tier cards can have "Bonus Gems" which add permanent tokens in the player's inventory.
* Tier cards can also have abilities or points that are used by the player to help them reach the three win conditions.
* 
* Royals have "crowns" and abilities that can be used when the player has enough crowns to get the royal card.
* 
* The card should override the regular comparator operator, so that vectors can sort cards by color and by points.
* This will be most important in the player class when the game needs to display the cards of a player.
* 
* BonusJewel ability cards will be initialized to Wild for their bonusColor. After it has been bought, the color will change to what is chosen.
* 
* @author: Joseph Corella
* @date: 2026-03-08
*/


class Card {
    public:
        int id = 0;

        std::array<int, 7> cost = {}; // 0: Red, 1: Green, 2: Blue, 3: White, 4: Black, 5: Pearl, 6: Gold

        enum class bonusColor { Red, Green, Blue, White, Black, Wild};
        enum class ability { None, StealAToken, GetPrivelege, TakeAToken, TakeAnotherTurn, BonusJewel };
    
        bonusColor color = bonusColor::Wild;
        ability cardAbility = ability::None;

        int bonusGems = 0; //The amount of bonus gems the card provides.
        int points = 0;
        int crowns = 0;
};

#endif