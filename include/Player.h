#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "Card.h"

/*
*@brief The player class holds all the data on the player. Names, tokens, points, crowns, priveleges, and cards.
* 
* Tokens are an array of 7 integers , representing the number of each type of token the player has.    
* The first 5 are the normal colors in this order: Red, Green, Blue, White, Black. The last two are pearls and gold, index 5 = pearls, index 6 = gold.
* 
* Bonus is an array of 7 integers, representing the number of each type of bonus the player has.
* 
* The bonuses are determined at the instance a card is purchased. For example when a card is added to the bought card vector,
* the card's attribute describing bonus gem colors is read and updated in the bonus array. This way there is no need to iterate through
* the purchased card vector everytime for bonus calculations.
* 
* @author Joseph Corella
* @date 2026-03-08
*/
class Player {
    public:
         
        //testing
        //friend void testPlayerVariables(); 

        // --- Constructors ---
        Player() {}
        Player(std::string playerName) : name(playerName) {}

        bool canAfford(Card c);
        void reset();

        // --- Getters & Setters ---
        std::string getName() const { return name; }
        void setName(const std::string& name) { this->name = name; }

        int getTotalPoints() const { return totalPoints; }
        void setTotalPoints(int points) { totalPoints = points; }

        int getCrowns() const { return crowns; }
        void setCrowns(int crowns) { this->crowns = crowns; }

        int getPrivileges() const { return privileges; }
        void setPrivileges(int privileges) { this->privileges = privileges; }

        // --- Reserved & Bought Cards ---
        const std::vector<Card> getReservedCards() const { return reservedCards; }
        void setReservedCards(const std::vector<Card> newReservedCards) { reservedCards = newReservedCards; }

        const std::vector<Card> getBoughtCards() const { return boughtCards; }
        void setBoughtCards(const std::vector<Card> newBoughtCards) { boughtCards = newBoughtCards; }
        void addBoughtCard(Card c) { boughtCards.push_back(c); }

        // --- Tokens & Bonuses ---
        const std::array<int, 7> getTokens() const { return tokens; }
        void setTokens(const std::array<int, 7> newTokens) { tokens = newTokens; }

        const std::array<int, 7> getBonus() const { return bonus; }
        void setBonus(const std::array<int, 7> newBonus) { bonus = newBonus; }

    private:
        std::string name;
        std::array<int, 7> tokens = {0,0,0,0,0,0,0}; //Red, Green, Blue, White, Black, Pearl, Gold
        std::array<int, 7> bonus = {0,0,0,0,0,0,0};
        int totalPoints = 0;
        int crowns = 0;
        int privileges= 0;

        std::vector<Card> reservedCards;
        std::vector<Card> boughtCards;

};

#endif