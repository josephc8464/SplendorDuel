#include <iostream>
#include <cassert>
#include "../include/Player.h"

void testPlayerVariables() {
    Player p("TestPlayer");

    // 1. Test basic attributes
    p.setTotalPoints(15);
    p.setCrowns(2);
    assert(p.getTotalPoints() == 15);
    assert(p.getCrowns() == 2);

    // 2. Test Token array (Index 5=Pearl, 6=Gold)
    std::array<int, 7> newTokens = { 1, 1, 1, 0, 0, 2, 1 }; // Red, Green, Blue, W, B, Pearl, Gold
    p.setTokens(newTokens);

    std::array<int, 7> retrievedTokens = p.getTokens();
    assert(retrievedTokens[5] == 2); // Check Pearl
    assert(retrievedTokens[6] == 1); // Check Gold

    // 3. Test Bonus calculation (Private access via friend)
    // Manually setting private bonus array to test state logic
    std::array<int, 7> newBonus = { 3, 0, 0, 0, 0, 0, 0 };
    p.setBonus(newBonus);
    assert(p.getBonus()[0] == 3);

    // 4. Test Bought Cards vector
    Card c;
    c.points = 5;
    p.addBoughtCard(c);
    assert(p.getBoughtCards().size() == 1);
    assert(p.getBoughtCards()[0].points == 5);

    std::cout << "All Player variables verified!" << std::endl;
}

int main() {
    testPlayerVariables();
    return 0;
}