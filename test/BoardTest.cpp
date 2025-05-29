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

TEST(BoardTest, PlaceShipGood){
    battleship::Game game;
    EXPECT_TRUE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 0, 0, 'H', "Cruiser"sv));
    EXPECT_FALSE(game.isDone()); // Game should not be done yet
}

TEST(BoardTest, PlaceShipBadLength){
    battleship::Game game;
    EXPECT_FALSE(game.addShip(battleship::PlayerEnum::HUMAN, 0, 0, 0, 'H', "Cruiser"sv));
    EXPECT_FALSE(game.addShip(battleship::PlayerEnum::HUMAN, -7, 0, 0, 'H', "Cruiser"sv));
    EXPECT_FALSE(game.addShip(battleship::PlayerEnum::HUMAN, 13, 0, 0, 'H', "Cruiser"sv));
}

TEST(BoardTest, PlaceShipOobOrigin){
    battleship::Game game;
    EXPECT_FALSE(game.addShip(battleship::PlayerEnum::HUMAN, 2, -1, 0, 'H', "Destroyer"sv));
}

TEST(BoardTest, PlaceShipOobEnd){
    battleship::Game game;
    EXPECT_FALSE(game.addShip(battleship::PlayerEnum::HUMAN, 5, 8, 8, 'H', "Destroyer"sv));
}

TEST(BoardTest, PlaceShipOriginOverlap){
    battleship::Game game;
    EXPECT_TRUE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 0, 1, 'H', "Cruiser"sv));
    EXPECT_FALSE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 0, 1, 'V', "Submarine"sv));
}

TEST(BoardTest, PlaceShipInlineOverlap){
    battleship::Game game;
    EXPECT_TRUE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 0, 0, 'H', "Cruiser"sv));
    EXPECT_FALSE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 0, 1, 'H', "Submarine"sv));
}

TEST(BoardTest, PlaceShipCrossOverlap){
    battleship::Game game;
    EXPECT_TRUE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 0, 1, 'H', "Cruiser"sv));
    EXPECT_FALSE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 1, 0, 'V', "Submarine"sv));
}