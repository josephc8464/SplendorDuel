#include "../include/Player.h"

/*
* @brief determines if the player can buy a card. Does not recognize which tokens will be used.
* 
* This function ONLY determines if a card can be bought by a player! NOT the token combinations to buy a card, that
* should be determined by the player.
* 
* @author Joseph Corella
* @date 2026-03-14
*/
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

/*
* @brief resets the player class. All variables set to default values.
* @author Joseph Corella
* @date 2026-03-14
*/

void Player::reset() {
	name.clear();
	tokens = { 0,0,0,0,0,0,0 };
	bonus = { 0,0,0,0,0,0,0 };
	int totalPoints = 0;
	int crowns = 0;
	int privileges = 0;

	reservedCards.clear();
	boughtCards.clear();
}
