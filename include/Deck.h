#ifndef DECK_H
#define DECK_H

#include <stack>
#include "Card.h"

class Deck {
	public:
		Deck();
		void shuffle();
		Card drawCard();

	private:
		std::stack<Card> cards;
		
};
#endif