#include "../include/Card.h"
#include <iostream>
#include <vector>

using std::cout, std::endl;

/*
* @brief Prints the details of a card in the terminal. 
*
* @author Joseph Corella
* @date 2026-03-15
*/
void Card::printCard() {
    cout << "------------------" << endl;
    cout << "Color: " << colorToString(color) << endl;
    cout << "Ability: " << abilityToString(cardAbility) << endl;
    cout << "Points: " << points << endl;
    cout << "Crowns: " << crowns << endl;
    std::vector<std::string> costColors = { "Red", "Green", "Blue", "White", "Black", "Pearl" };

    cout << endl << "-Cost-" << endl;

    for(int i=0; i<6; i++) { 
        cout << costColors.at(i) << ": " << cost.at(i) << endl;
    }
}

/*
* @brief Converts a color to a string.
*
* @author Joseph Corella
* @date 2026-03-15
*/
std::string Card::colorToString(bonusColor color) const {
        switch (color) {
        case bonusColor::Red:   return "Red";
        case bonusColor::Green: return "Green";
        case bonusColor::Blue:  return "Blue";
        case bonusColor::White: return "White";
        case bonusColor::Black: return "Black";
        case bonusColor::Wild:  return "Wild";
        default:                return "None";
        }
}

/*
* @brief Converts an ability to a string.
*
* @author Joseph Corella
* @date 2026-03-15
*/
std::string Card::abilityToString(ability ability) const {
    switch (ability) {
    case ability::None:            return "None";
    case ability::StealAToken:     return "StealAToken";
    case ability::GetPrivilege:    return "GetPrivilege";
    case ability::TakeAToken:      return "TakeAToken";
    case ability::TakeAnotherTurn: return "TakeAnotherTurn";
    case ability::BonusJewel:      return "BonusJewel";
    case ability::BonusJewelTurn:  return "BonusJewelTurn";
    default:                       return "Unknown";
    }
}