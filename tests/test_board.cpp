#include <iostream>
#include <cassert>
#include "../include/Board.h"

void testBoardVariables() {
    Board b;

    // 1. Test Initial State
    assert(b.getBoardPrivileges() == 3);

    // 2. Test Token Manipulation
    std::vector<ColorEnum> initialTokens = { ColorEnum::Red, ColorEnum::Blue };
    b.setBagOfTokens(initialTokens);
    assert(b.getBagOfTokens().size() == 2);

    // 3. Test Visible Cards (Manual setup)
    std::array<Card, 5> mockTier1;
    mockTier1[0].points = 2;
    b.setVisibleTier1Cards(mockTier1);

    auto visible = b.getVisibleTier1Cards();
    assert(visible[0].points == 2);

    // 4. Test 2D Grid Access (Directly via the friend access)
    b.tokens[0][0] = ColorEnum::Gold;
    assert(b.tokens[0][0] == ColorEnum::Gold);

    std::cout << "All Board variables verified!" << std::endl;
}

int main() {
    testBoardVariables();
    return 0;
}