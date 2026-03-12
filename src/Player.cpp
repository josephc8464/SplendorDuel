#include "../include/Player.h"

void Player::addBoughtCard(const Card & card) {
	boughtCards.push_back(card);
}

bool Player::canAfford(Card c) {

	int deficit = 0; //Keeps count of deficits in tokens

	for(int i=0; i<6; i++) 
	{
		deficit = bonus.at(i) + tokens.at(i) - c.cost.at(i);
	}

	//If the deficit of tokens is greater than the amount of gold tokens the player owns, the player cannot afford it.
	if(deficit > tokens.at(6)) 
	{
		return false;
	}

	return true;
}

void Player::reserveCard(Card c) {
	reservedCards.push_back(c);
}

void Player::addTokens(std::array<int, 7> newTokens) {
	for (int i = 0; i < 7; i++)
	{
		tokens.at(i) += newTokens.at(i);
	}
}

void Player::removeTokens(std::array<int, 7> cost) {
	for (int i = 0; i < 7; i++)
	{
		tokens.at(i) -= cost.at(i);
	}
}

void Player::addBonus(std::array<int, 7> newBonus) {
	for (int i = 0; i < 7; i++)
	{
		bonus.at(i) += newBonus.at(i);
	}
}


