//
// Created by matth on 5/28/2025.
//

#include <gtest/gtest.h>
#include "src/Game.h"

TEST(GameTest, InitializeGame) {
    battleship::Game game;
    EXPECT_FALSE(game.isDone());
}