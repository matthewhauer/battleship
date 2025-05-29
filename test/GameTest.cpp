//
// Created by matth on 5/28/2025.
//

#include <gtest/gtest.h>
#include "src/Game.h"

TEST(GameTest, InitializeGame) {
    battleship::Game game;
    EXPECT_FALSE(game.isDone());
}

TEST(GameTest, CreateGame){
    battleship::Game game("Player1", 20, 20);
}

TEST(GameTest, CreateGameNegativeSize){
    EXPECT_THROW(battleship::Game game("Player1", -20, 20), std::invalid_argument);
    EXPECT_THROW(battleship::Game game("Player1", 20, -20), std::invalid_argument);
    EXPECT_THROW(battleship::Game game("Player1", 0, 0), std::invalid_argument);
}

TEST(GameTest, PlaceShipGood){
    battleship::Game game;
    EXPECT_TRUE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 0, 0, 'H', "Cruiser"sv));
}

TEST(GameTest, PlaceShipGoodEdge){
    battleship::Game game;
    EXPECT_TRUE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 0, 9, 'H', "Cruiser"sv));
    EXPECT_TRUE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 9, 0, 'V', "Cruiser"sv));
}

TEST(GameTest, PlaceShipBadEdge){
    battleship::Game game;
    EXPECT_FALSE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 0, 10, 'H', "Cruiser"sv));
    EXPECT_FALSE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 10, 0, 'V', "Cruiser"sv));
}

TEST(GameTest, PlaceShipBadLength){
    battleship::Game game;
    EXPECT_FALSE(game.addShip(battleship::PlayerEnum::HUMAN, 0, 0, 0, 'H', "Cruiser"sv));
    EXPECT_FALSE(game.addShip(battleship::PlayerEnum::HUMAN, -7, 0, 0, 'H', "Cruiser"sv));
    EXPECT_FALSE(game.addShip(battleship::PlayerEnum::HUMAN, 13, 0, 0, 'H', "Cruiser"sv));
}

TEST(GameTest, PlaceShipOobOrigin){
    battleship::Game game;
    EXPECT_FALSE(game.addShip(battleship::PlayerEnum::HUMAN, 2, -1, 0, 'H', "Destroyer"sv));
}

TEST(GameTest, PlaceShipOobEnd){
    battleship::Game game;
    EXPECT_FALSE(game.addShip(battleship::PlayerEnum::HUMAN, 5, 8, 8, 'H', "Destroyer"sv));
}

TEST(GameTest, PlaceShipOriginOverlap){
    battleship::Game game;
    EXPECT_TRUE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 0, 1, 'H', "Cruiser"sv));
    EXPECT_FALSE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 0, 1, 'V', "Submarine"sv));
}

TEST(GameTest, PlaceShipInlineOverlap){
    battleship::Game game;
    EXPECT_TRUE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 0, 0, 'H', "Cruiser"sv));
    EXPECT_FALSE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 0, 1, 'H', "Submarine"sv));
}

TEST(GameTest, PlaceShipCrossOverlap){
    battleship::Game game;
    EXPECT_TRUE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 0, 1, 'H', "Cruiser"sv));
    EXPECT_FALSE(game.addShip(battleship::PlayerEnum::HUMAN, 3, 1, 0, 'V', "Submarine"sv));
}