#include "../include/Deck.h"
#include <algorithm>
#include <random>

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