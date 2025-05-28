//
// Created by matth on 5/22/2025.
//

#include <gtest/gtest.h>
#include "src/Game.h"

TEST(HelloWorldTest, BasicAssertions) {
    // Expect equality.
    EXPECT_EQ(1, 1);
    // Expect inequality.
    EXPECT_NE(1, 2);
}

TEST(BoardTest, AddShipGood){
    // Create a game instance
    battleship::Game game;

    // Add a ship to the game board
    EXPECT_TRUE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 0, 0, 'H', "Cruiser"sv));

    // Check if the ship was added correctly
    EXPECT_FALSE(game.isDone()); // Game should not be done yet
}

TEST(BoardTest, AddShipOOB){
    battleship::Game game;
    EXPECT_FALSE(game.addShip(battleship::PlayerEnum::HUMAN, 2, -1, 0, 'H', "Destroyer"sv));
}

TEST(BoardTest, AddShipOriginOverlap){
    battleship::Game game;
    EXPECT_TRUE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 0, 1, 'H', "Cruiser"sv));
    EXPECT_FALSE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 0, 1, 'V', "Submarine"sv));
}

TEST(BoardTest, AddShipInlineOverlap){
    battleship::Game game;
    EXPECT_TRUE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 0, 0, 'H', "Cruiser"sv));
    EXPECT_FALSE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 0, 1, 'H', "Submarine"sv));
}

TEST(BoardTest, AddShipCrossOverlap){
    battleship::Game game;
    EXPECT_TRUE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 0, 1, 'H', "Cruiser"sv));
    EXPECT_FALSE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 1, 0, 'V', "Submarine"sv));
}