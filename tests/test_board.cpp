#include <iostream>
#include <cassert>
#include <vector>
#include "../include/Board.h"

void testBoardVariables() {
    Board b;

    // 1. Test Initial State
    assert(b.getBoardPrivileges() == 3);

    // 2. Test Token Manipulation
    std::vector<ColorEnum> initialTokens = { ColorEnum::Red, ColorEnum::Blue };
    b.setBagOfTokens(initialTokens);
    assert(b.getBagOfTokens().size() == 2);

    // 3. Test Visible Cards
    std::array<Card, 5> mockTier1 = b.getVisibleTier1Cards();
    Card tempCard;
    tempCard.setPoints(2);
    mockTier1[0] = tempCard;
    b.setVisibleTier1Cards(mockTier1);

    auto visible = b.getVisibleTier1Cards();
    assert(visible[0].getPoints() == 2);

    // 4. Test 2D Grid Access
    b.tokens[0][0] = ColorEnum::Gold;
    assert(b.tokens[0][0] == ColorEnum::Gold);

    std::cout << "All Board variables verified!" << std::endl;
}

void testTokenGrid() {
    Board b;
    std::vector<ColorEnum> tempBag;

    for (int i = 0; i < 4; i++) { // Adjusted loop to 4 iterations (4*5 = 20)
        tempBag.push_back(ColorEnum::Red);
        tempBag.push_back(ColorEnum::Green);
        tempBag.push_back(ColorEnum::Blue);
        tempBag.push_back(ColorEnum::Black);
        tempBag.push_back(ColorEnum::White);
    }
    tempBag.push_back(ColorEnum::Gold);
    tempBag.push_back(ColorEnum::Gold);
    tempBag.push_back(ColorEnum::Gold);
    tempBag.push_back(ColorEnum::Pearl);
    tempBag.push_back(ColorEnum::Pearl);

    assert(tempBag.size() == 25);
    b.setBagOfTokens(tempBag);
    b.refillGrid();
    b.printBoard();
}

int main() {
    testBoardVariables();
    testTokenGrid();
    std::cout << "\nALL BOARD TESTS PASSED!" << std::endl;
    return 0;
}