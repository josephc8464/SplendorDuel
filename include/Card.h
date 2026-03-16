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
* 
* @note: Updated 2026-03-15 - Refactored for private encapsulation and removed gold costs.
*/

enum class bonusColor { Red, Green, Blue, White, Black, Wild, None };
enum class ability { None, StealAToken, GetPrivilege, TakeAToken, TakeAnotherTurn, BonusJewel, BonusJewelTurn };

class Card {
    public:
        void printCard();
        std::string colorToString(bonusColor color) const;
        std::string abilityToString(ability ability) const;

        // --- Constructors ---
        Card() {};
        Card(int newId, std::array<int, 7> newCost, bonusColor newColor,
            ability newAbility, int newBonus, int newPoints, int newCrowns)
            : id(newId), cost(newCost), color(newColor),
            cardAbility(newAbility), bonusGems(newBonus),
            points(newPoints), crowns(newCrowns) {
        };

        // --- Id ---
        int getId() const { return id; };
        void setId(int newId) { id = newId; };

        // --- Cost ---
        std::array<int, 7> getCost() const { return cost; };
        void setCost(std::array<int, 7> newCost) { cost = newCost; };

        // --- Color & Ability ---
        bonusColor getColor() const { return color; };
        void setColor(bonusColor newColor) { color = newColor; };
        ability getAbility() const { return cardAbility; };
        void setAbility(ability newAbility) { cardAbility = newAbility; };

        // --- Stats ---
        int getBonusGems() const { return bonusGems; };
        void setBonusGems(int newBonus) { bonusGems = newBonus; };
        int getPoints() const { return points; };
        void setPoints(int newPoints) { points = newPoints; };
        int getCrowns() const { return crowns; };
        void setCrowns(int newCrowns) { crowns = newCrowns; };

        // --- Comparators ---
        bool operator<(const Card& other) const {
            if (this->color != other.color) {
                return static_cast<int>(this->color) < static_cast<int>(other.color);
            }
            return this->points < other.points;
        };

    private:
        int id = 0;
        std::array<int, 7> cost = {}; //Red, Green, Blue, White, Black, Pearl, (gold but cards don't have this in cost)
        bonusColor color = bonusColor::Wild;
        ability cardAbility = ability::None;
        int bonusGems = 0;
        int points = 0;
        int crowns = 0;
};

#endif //CARD_H
