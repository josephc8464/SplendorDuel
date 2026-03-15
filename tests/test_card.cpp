#include <iostream>
#include <cassert>
#include <array>
#include "../include/Card.h"

void testCardDefaults() {
    Card c;

    // Now using getters instead of direct access
    assert(c.getPoints() == 0);
    assert(c.getColor() == bonusColor::Wild);
    assert(c.getCost()[0] == 0);

    std::cout << "testCardDefaults passed!" << std::endl;
}

void testCardCustomization() {
    Card c;

    // Now using setters
    c.setPoints(2);
    c.setColor(bonusColor::Red);

    std::array<int, 7> newCost = { 3, 0, 0, 0, 0, 0, 0 }; // 3 Red cost
    c.setCost(newCost);

    // Verifying with getters
    assert(c.getPoints() == 2);
    assert(c.getColor() == bonusColor::Red);
    assert(c.getCost()[0] == 3);

    std::cout << "testCardCustomization passed!" << std::endl;
}

void testAllArgsConstructor() {
    // Testing the new Member Initializer List constructor
    std::array<int, 7> cost = { 1, 1, 1, 0, 0, 1, 0 };
    Card c(99, cost, bonusColor::Blue, ability::TakeAnotherTurn, 1, 3, 2);

    assert(c.getId() == 99);
    assert(c.getPoints() == 3);
    assert(c.getAbility() == ability::TakeAnotherTurn);
    assert(c.getCrowns() == 2);
    assert(c.getCost()[5] == 1); // Pearl cost check

    std::cout << "testAllArgsConstructor passed!" << std::endl;
}

int main() {
    try {
        testCardDefaults();
        testCardCustomization();
        testAllArgsConstructor();
        std::cout << "\nALL TESTS PASSED!" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "A test failed with error: " << e.what() << std::endl;
        return -1;
    }
    catch (...) {
        std::cerr << "An unknown test failure occurred!" << std::endl;
        return -1;
    }
    return 0;
}