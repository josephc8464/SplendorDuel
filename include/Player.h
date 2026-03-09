#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "Card.h"

/*
*@brief The player class holds all the data on the player. Names, tokens, points, crowns, priveleges, and cards
* 
* @author Joseph Corella
* @date 2026-03-08
*/
class Player {
    public:
        //getters and setters
        std::string getName() const{ return name; };
        void setName(const std::string& name);

        int getTotalPoints() const{ return totalPoints; };
        void setTotalPoints(int points){ totalPoints = points; };

        int getCrowns() const{ return crowns; };
        void setCrowns(int crowns){ crowns = crowns; };

        int getPriveleges() const{ return priveleges; };
        void setPriveleges(int priveleges){ priveleges = priveleges; };

        Card getReservedCard(int index) const{ return reservedCards.at(index); };
        void setReservedCard(const Card& card){ reservedCards.push_back(card); };
        void removeReservedCard(int index) { reservedCards.erase(reservedCards.begin() + index); };
        
        std::vector<Card> getBoughtCards() const{ return boughtCards; };
        void addBoughtCard(const Card& card){ boughtCards.push_back(card); };

        array<int> addTokens();
        array<int> getTokens() { return tokens; };

        array<int> addBonus();
		array<int> getBonus() { return bonus; };

    private:
        std::string name;
        std::array<int> tokens;
        std::array<int> bonus;
        int totalPoints;
        int crowns;
        int priveleges;

        std::vector<Card> reservedCards;
        std::vector<Card> boughtCards;

};

#endif