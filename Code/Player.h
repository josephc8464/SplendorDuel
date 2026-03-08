#ifndef PLAYER
#define PLAYER

#include <iostream>
#include <string>
#include <vector>
#include "Card.h"

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
        std::string name; //name of player
        
        int tokens[7]; //number of tokens the player has
        int totalPoints; //number of points the player has
        int crowns; //number of crowns the player has
        int priveleges; //number of priveleges the player has

        std::vector<Card> reservedCards; //cards reserved by the player
        std::vector<Card> boughtCards; //number of cards reserved by the player

};

#endif