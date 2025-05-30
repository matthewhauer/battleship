//
// Created by matth on 5/29/2025.
//

#include <gtest/gtest.h>
#include "src/Game.h"

TEST(ShipTest, ShipCollisionOne){
    //battleship::Game game("TestPlayerAdjacent"sv, 12, 12);
    //game.beginSetup();
    battleship::Ship testShip("Destroyer"sv, 2, 2, 2, 'H');
    EXPECT_FALSE(testShip.isStraightOverlap(3, 3, 3, 'V'));
    EXPECT_FALSE(testShip.isCrossOverlap(3, 3, 3, 'V'));
    EXPECT_FALSE(testShip.isOverlapping(3, 3, 3, 'V'));
}

TEST(ShipTest, ShipCollisionTwo){
    //battleship::Game game("TestPlayerAdjacent"sv, 12, 12);
    //game.beginSetup();
    battleship::Ship testShip("Cruiser"sv, 3, 1, 3, 'V');
    EXPECT_FALSE(testShip.isStraightOverlap(2, 1, 4, 'H'));
    EXPECT_TRUE(testShip.isCrossOverlap(2, 1, 4, 'H'));
    EXPECT_TRUE(testShip.isOverlapping(2, 1, 4, 'H'));
}