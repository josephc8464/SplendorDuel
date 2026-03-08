#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <string>
#include <vector>
#include "Card.h"

/*
*@brief The player class holds all the data on the player. Names, tokens, points, crowns, priveleges, and cards.
* - Tokens are stored in an array, where the index corresponds to the type of token. This includes gold tokens (wildcards).
* - totalPoints are an aggregate from the boughtCards.
* - crowns are an aggregate from the boughtCards.
* - privelges have a constraint of three total. Stored as an int since they are only used for an action,
* thus deduction is only needed, and an object does not need to exist. Needs extra logic to prevent fluctations of privelges across the board and players.
* - reservedCards are stored in a vector, however they can only have three at max.
* - boughtCards are stored in a vector, there is no limit to how many cards a player can buy.
* 
* @author Joseph Corella
* @date 2026-03-08
*/
class Player {
    public:
        //getters and setters
        std::string getName() const{ return name; };
        void setName(const std::string& name);

        int getTokens(int index) const{ return tokens[index]; };
        void setTokens(int index, int value){ tokens[index] = value; };

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

    private:
        std::string name;
        
        int tokens[7];
        int totalPoints;
        int crowns;
        int priveleges;

        std::vector<Card> reservedCards;
        std::vector<Card> boughtCards;

};

#endif