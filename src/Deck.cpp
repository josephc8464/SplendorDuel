#include "../include/Deck.h"
#include <algorithm>
#include <random>

Deck::Deck() {}

void Deck::shuffle() {
	std::shuffle(cards.begin(), cards.end(), std::default_random_engine());
}

Card Deck::drawCard() {
	Card drawnCard = cards.at(0);
	cards.erase(cards.begin() + 0);

	return drawnCard;
}