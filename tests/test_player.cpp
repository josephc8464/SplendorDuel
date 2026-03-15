#include <iostream>
#include <cassert>
#include <array>
#include "../include/Player.h"

void testPlayerVariables() {
    Player p("TestPlayer");

    // 1. Test basic attributes (using setters and getters)
    p.setTotalPoints(15);
    p.setCrowns(2);
    assert(p.getTotalPoints() == 15);
    assert(p.getCrowns() == 2);

    // 2. Test Token array
    std::array<int, 7> newTokens = { 1, 1, 1, 0, 0, 2, 1 };
    p.setTokens(newTokens);

    std::array<int, 7> retrievedTokens = p.getTokens();
    assert(retrievedTokens[5] == 2); // Check Pearl
    assert(retrievedTokens[6] == 1); // Check Gold

    // 3. Test Bonus calculation (using getters/setters, not friend access)
    std::array<int, 7> newBonus = { 3, 0, 0, 0, 0, 0, 0 };
    p.setBonus(newBonus);
    assert(p.getBonus()[0] == 3);

    // 4. Test Bought Cards vector
    Card c;
    c.setPoints(5); // Use setter here!
    p.addBoughtCard(c);

    assert(p.getBoughtCards().size() == 1);
    assert(p.getBoughtCards()[0].getPoints() == 5); // Use getter here!

    std::cout << "All Player variables verified!" << std::endl;
}

int main() {
    try {
        testPlayerVariables();
        std::cout << "\nALL PLAYER TESTS PASSED!" << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return -1;
    }
    return 0;
}