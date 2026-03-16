#include "../include/Deck.h"
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>
#include <iostream>

namespace {

    /*
    * @brief converts a string to a bonus color in the card attributes. Used for CSV file input.
    *
    * @author Joseph Corella
    * @date 2026-03-15
    */
    bonusColor stringToBonusColor(std::string color) {
        if (color == "Red")   return bonusColor::Red;
        if (color == "Green") return bonusColor::Green;
        if (color == "Blue")  return bonusColor::Blue;
        if (color == "White") return bonusColor::White;
        if (color == "Black") return bonusColor::Black;
        if (color == "Wild")  return bonusColor::Wild;

        return bonusColor::None;
    }

    /*
    * @brief converts a string to an ability in the card attributes. Used for CSV file input.
    *
    * @author Joseph Corella
    * @date 2026-03-15
    */
    ability stringToAbility(std::string abilityStr) {
        if (abilityStr == "None")            return ability::None;
        if (abilityStr == "StealAToken")     return ability::StealAToken;
        if (abilityStr == "GetPrivilege")    return ability::GetPrivilege;
        if (abilityStr == "TakeAToken")      return ability::TakeAToken;
        if (abilityStr == "TakeAnotherTurn") return ability::TakeAnotherTurn;
        if (abilityStr == "BonusJewel")      return ability::BonusJewel;
        if (abilityStr == "BonusJewelTurn")  return ability::BonusJewelTurn;

        return ability::None; // Default case
    }


}

/*
* @brief shuffles the deck pseudorandom.
* @author Joseph Corella
* @date 2026-03-14
*/
void Deck::shuffle() {
	std::shuffle(cards.begin(), cards.end(), std::default_random_engine());
}

/*
* @brief draw a card from the "top" of the deck.
* @author Joseph Corella
* @date 2026-03-14
*/
Card Deck::drawCard() {
	Card drawnCard = cards.back();
	cards.pop_back();

	return drawnCard;
}

/*
* @brief clears the deck of cards.
* @author Joseph Corella
* @date 2026-03-14
*/
void Deck::reset() {
	cards.clear();
}

/*
* @brief loads in a deck from a csv file.
* 
* @author Joseph Corella
* @date 2026-03-15
*/
void Deck::loadFromCSV(std::string fileName) {
    std::ifstream file(fileName);

    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << fileName << std::endl;
        return;
    }

    std::string line;
    Card c;

    // Read the file line by line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;

        //Id
        std::getline(ss, cell, ',');
        c.setId(std::stoi(cell));

        //Color
        std::getline(ss, cell, ',');
        cell.erase(std::remove(cell.begin(), cell.end(), ' '), cell.end());
        c.setColor(stringToBonusColor(cell));
        
        //Points
        std::getline(ss, cell, ',');
        c.setPoints(std::stoi(cell));
        
        //Bonus Gems
        std::getline(ss, cell, ',');
        c.setBonusGems(std::stoi(cell));

        //Ability
        std::getline(ss, cell, ',');
        cell.erase(std::remove(cell.begin(), cell.end(), ' '), cell.end());
        c.setAbility(stringToAbility(cell));

        //Crowns
        std::getline(ss, cell, ',');
        c.setCrowns(std::stoi(cell));

        //Tokens!
        std::array<int, 7> newTokens = { 0,0,0,0,0,0,0 };
        
        for (int i = 0; i < 6; i++) {
            std::getline(ss, cell, ',');

            newTokens.at(i) = std::stoi(cell);
        }

        c.setCost(newTokens);

        c.printCard();
    }

    file.close();
}
