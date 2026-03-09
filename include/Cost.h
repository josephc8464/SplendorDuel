#ifndef COST_H
#define COST_H

#include <array>
#include <iostream>

class Cost{
	public:
		Cost();
		Cost(std::array<int, 6> cost);

		std::array<int, 7> getCost() const { return cost; };
		std::array<int, 7> setCost(std::array<int, 7> newCost) { cost = newCost; };

	private:
		std::array<int, 7> cost;
};

#endif