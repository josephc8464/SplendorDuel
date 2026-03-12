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
        //Constructor
        Player() {};
        Player(std::string playerName) : name(playerName) {};

        bool canAfford(Card c);
        void reserveCard(Card c);
        void reset();

        //getters and setters
        std::string getName() const { return name; };
        void setName(const std::string& name) { this->name = name; };

        int getTotalPoints() const { return totalPoints; };
        void setTotalPoints(int points) { totalPoints = points; };
		void addPoints(int newPoints) { totalPoints += newPoints; };

        int getCrowns() const { return crowns; };
        void setCrowns(int crowns) { this->crowns = crowns; };
        void addCrowns(int newCrowns) { crowns += newCrowns; };

        int getPrivileges() const { return privileges; };
        void setPrivileges(int privileges) { this->privileges = privileges; };
        void addPrivileges(int newPrivileges) { privileges += newPrivileges;  };
		void removePrivileges(int numPrivileges) { privileges -= numPrivileges; };

        int getNumOfReservedCards() { return reservedCards.size(); };
        Card getReservedCard(int index) const{ return reservedCards.at(index); };
        void setReservedCard(const Card& card){ reservedCards.push_back(card); };
        void removeReservedCard(int index) { reservedCards.erase(reservedCards.begin() + index); };
        
        std::vector<Card> getBoughtCards() const{ return boughtCards; };
        void addBoughtCard(const Card& card); 

        void addTokens(std::array<int, 7> newTokens);
        void removeTokens(std::array<int, 7> cost);
        std::array<int, 7> getTokens() { return tokens; };

        void addBonus(std::array<int, 7> newBonus);
		std::array<int, 7> getBonus() { return bonus; };

    private:
        std::string name;
        std::array<int, 7> tokens = {0,0,0,0,0,0,0};
        std::array<int, 7> bonus = {0,0,0,0,0,0,0};
        int totalPoints = 0;
        int crowns = 0;
        int privileges= 0;

        std::vector<Card> reservedCards;
        std::vector<Card> boughtCards;

};

#endif