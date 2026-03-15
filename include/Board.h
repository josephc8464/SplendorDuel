#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <string>
#include <memory>

#include "Card.h"
#include "Deck.h"

/*
*@brief The Board class represents the game board, which includes the tokens, cards, royal cards, and priveleges.
* 
*  The board class is responsible for holding the state of the board. It should not know about the players or the rules
*  of the game, only the actions taken from the game controller. Thus logic that inhibits players actions should be handled
*  in the game class. 
* 
*  The board class should hold the tier card decks, the visible tier cards, the royal cards, the bag of tokens, and the board privileges.
*  Thus it acts more of a data structure for the game class to interact with, and not a controller of the game itself.
* 
* @author Joseph Corella
* @date 2026-03-08
*/
enum class ColorEnum { Empty, Red, Green, Blue, White, Black, Pearl, Gold };

class Board {
    public:
        class Position { public: int x; int y; };
        
        Board() {}; //No Args Constructor

        //printing functions for testing
        void printBoard();

        void refillGrid();
        void resetBoard();
        std::vector<ColorEnum> takeTokens(std::vector<Position> gridPositions);

        std::string colorToString(ColorEnum color) {
            switch (color) {
            case ColorEnum::Red:   return "Red";
            case ColorEnum::Green: return "Green";
            case ColorEnum::Blue:  return "Blue";
            case ColorEnum::White: return "White";
            case ColorEnum::Black: return "Black";
            default:               return "Empty";
            }
        }

        //getters, setters
        Deck getTier1DeckCard() { return tier1Cards; };
        void setTier1DeckCard(Deck deck) { tier1Cards = deck; };

        Deck getTier2DeckCard() { return tier2Cards; };
        void setTier2DeckCard(Deck deck) { tier2Cards = deck; };

        Deck getTier3DeckCard() { return tier3Cards; };
        void setTier3DeckCard(Deck deck) { tier3Cards = deck; };

        std::array<Card, 5> getVisibleTier1Cards() { return visibleTier1; };
        void setVisibleTier1Cards(std::array<Card, 5> tier1) { visibleTier1 = tier1; };
        
        std::array<Card, 4> getVisibleTier2Cards() { return visibleTier2; };
        void setVisibleTier2Cards(std::array<Card, 4> tier2) { visibleTier2 = tier2; };

        std::array<Card, 3> getVisibleTier3Cards() { return visibleTier3; };
        void setVisibleTier3Cards(std::array<Card, 3> tier3) { visibleTier3 = tier3; };

        std::vector<ColorEnum> getBagOfTokens() { return bagOfTokens; };
        void setBagOfTokens(std::vector<ColorEnum> tokens) { bagOfTokens = tokens; };

        int getBoardPrivileges() { return boardPrivileges; };
        void setBoardPrivileges(int privileges) { boardPrivileges = privileges; };

    private:
        ColorEnum tokens[5][5] = {};
		Deck tier1Cards;
		Deck tier2Cards;
		Deck tier3Cards;

        std::array<Card, 5> visibleTier1 = {};
        std::array<Card, 4> visibleTier2 = {};
        std::array<Card, 3> visibleTier3 = {};

        std::array<Card, 4> royals = {};
        std::vector<ColorEnum> bagOfTokens;
        int boardPrivileges = 3;
};

#endif // BOARD_H