#include "../include/Deck.h"
#include <algorithm>
#include <random>

Deck::Deck() {}

void Deck::shuffle() {
	std::shuffle(cards.begin(), cards.end(), std::default_random_engine());
}

Card Deck::drawCard() {
	Card drawnCard = cards.back();
	cards.pop_back();

	return drawnCard;
}

void Deck::reset() {
	cards.clear();
}