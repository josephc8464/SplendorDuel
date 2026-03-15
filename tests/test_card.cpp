#include <iostream>
#include <cassert>
#include "../include/Card.h"

void testCardDefaults() {
    Card c;

    assert(c.points == 0);
    assert(c.color == Card::bonusColor::Wild);
    assert(c.cost[0] == 0);
    std::cout << "testCardDefaults passed!" << std::endl;
}

void testCardCustomization() {
    Card c;
    c.points = 2;
    c.color = Card::bonusColor::Red;
    c.cost[0] = 3; // 3 Red cost

    assert(c.points == 2);
    assert(c.color == Card::bonusColor::Red);
    assert(c.cost[0] == 3);
    std::cout << "testCardCustomization passed!" << std::endl;
}

int main() {
    try {
        testCardDefaults();
        testCardCustomization();
        std::cout << "\nALL TESTS PASSED!" << std::endl;
    }
    catch (...) {
        std::cerr << "A test failed!" << std::endl;
        return -1;
    }
    return 0;
}