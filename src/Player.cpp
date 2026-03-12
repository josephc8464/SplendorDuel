#include "../include/Player.h"

void Player::addBoughtCard(const Card & card) {
	boughtCards.push_back(card);

	
}

bool Player::canAfford(Card c) {

}

void Player::buyCard(Card c) {

}

void Player::reserveCard(Card c) {

}

void Player::addTokens(std::array<int, 7> newTokens) {
	for (int i = 0; i < 7; i++)
	{
		tokens.at(i) += newTokens.at(i);
	}
}

void Player::addBonus(std::array<int, 7> newBonus) {
	for (int i = 0; i < 7; i++)
	{
		bonus.at(i) += newBonus.at(i);
	}
}


