#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

/*
*@brief Holds the logic for the deck of tier cards.
* 
* The main reason for this to be directly separate from the Board class, is so the board class can handle 
* the higher level transactions of cards with the game class. 
* 
* The goal of the deck class is to simplify the state of cards in the board class. By having drawCard() and shuffle(),
* as separate logic from the board we can keep consistency in data integrity of the cards. 
* 
* The board class will only have to worry about the visible cards and the cards in the deck, and not the 
* logic of how to shuffle or draw cards.
* 
* @author Joseph Corella
* @date 2026-03-11
*/

class Deck {
	public:
		Deck();
		void shuffle();
		Card drawCard();
		void reset();

	private:
		std::vector<Card> cards;
		
};
#endif