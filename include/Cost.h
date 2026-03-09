#ifndef COST_H
#define COST_H

#include <array>
#include <iostream>

class Cost{
	public:
		Cost();
		Cost(std::array<int> cost);

		std::array<int> getCost() const { return cost; };
		std::array<int> setCost(array<int> newCost) { cost = newCost; };

	private:
		std::array<int> cost;
};

#endif