#include "../include/Card.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>

using std::cout, std::endl;

/*
* @brief Helper function to implement printing functionality of vectors of cards
* - Returns the printing lines of a card, so cards can be printed side-by-side
* 
* @author Joseph Corella
* @date 2026-03-19
*/
std::vector<std::string> Card::getCardLines() const {
    const int WIDTH = 19;
    std::vector<std::string> lines;
    std::vector<std::string> costColors = { "Red", "Green", "Blue", "White", "Black", "Gold", "Pearl" };

    // Helper to wrap text in * * and pad with spaces to exactly WIDTH
    auto format = [&](std::string text) {
        std::stringstream ss;
        ss << "* " << std::left << std::setw(WIDTH - 4) << text << " *";
        return ss.str();
        };

    // 1. Top Border
    lines.push_back(std::string(WIDTH, '*'));

    // 2. Points and Bonus
    std::string header = std::to_string(points) + " P.   " + std::to_string(bonusGems) + " " + colorToString(color);
    lines.push_back(format(header));

    // 3. Ability
    lines.push_back(format(abilityToString(cardAbility)));

    // 4. Crowns
    lines.push_back(format(std::to_string(crowns) + " Crowns"));

    // 5. Spacer & Cost Header
    lines.push_back(format(""));
    lines.push_back(format("-Cost-"));

    // 6. Costs (Dynamic)
    int costLines = 0;
    for (int i = 0; i < 7; i++) {
        if (cost.at(i) > 0) {
            lines.push_back(format(costColors[i] + ": " + std::to_string(cost.at(i))));
            costLines++;
        }
    }

    // 7. Padding (Ensures every card is the same height: 12 lines total)
    while (lines.size() < 11) {
        lines.push_back(format(""));
    }

    // 8. Bottom Border
    lines.push_back(std::string(WIDTH, '*'));

    return lines;
}

/*
* @brief Prints the details of a card in the terminal. 
*
* @author Joseph Corella
* @date 2026-03-15
*/
void Card::printCard() {
    const int CARD_WIDTH = 19;
    std::vector<std::string> costColors = { "Red", "Green", "Blue", "White", "Black", "Pearl" };

    // Helper to print a line with a border
    auto printLine = [&](std::string leftText, std::string rightText = "") {
        std::cout << "* " << std::left << std::setw(CARD_WIDTH - 4) << (leftText + rightText) << " *" << std::endl;
        };

    std::cout << std::string(CARD_WIDTH, '*') << std::endl;

    // Header: Points, Bonus, and Color
    // Format: "P. [pts]    [bonus] [color]"
    std::string stats = std::to_string(points) + " P.   " + std::to_string(bonusGems) + " " + colorToString(color);
    printLine(stats);

    // Ability and Crowns
    printLine(abilityToString(cardAbility));
    printLine(std::to_string(crowns) + " Crowns");

    // Divider
    printLine("");
    printLine("-Cost-");

    // Costs
    int linesPrinted = 0;
    for (int i = 0; i < 6; i++) {
        if (cost.at(i) > 0) {
            printLine(costColors.at(i) + ": ", std::to_string(cost.at(i)));
            linesPrinted++;
        }
    }

    // Fill empty space to keep card height consistent (5 lines for cost area)
    for (int i = linesPrinted; i < 5; i++) {
        printLine("");
    }

    std::cout << std::string(CARD_WIDTH, '*') << std::endl;
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