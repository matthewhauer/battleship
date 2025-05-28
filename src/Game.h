//
// Created by matth on 5/22/2025.
//

#ifndef BATTLESHIP_GAME_H
#define BATTLESHIP_GAME_H

#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

#include "Ship.h"
#include "Player.h"
#include "PlayerEnum.h"

using namespace std;

namespace battleship {
    class Game {
    public:
        Game() : Game("human"sv, 10, 10){};

        Game(string_view playerName, int h, int w) : player1(playerName), player2("Computer"sv),
            height(h), width(w) {
        }
        void initialize();
        bool isDone() const;
        bool addShip(PlayerEnum &&playerType, int size, int row, int col, char orientation, string_view shipName);
        bool addShip(Player &player, int size, int row, int col, char orientation, string_view shipName);

        vector<int> getShipSizes() {
            return {2, 3, 4, 5};
        }

        void displayBoard() {

        }

        void makeMove(int row, int col) {
            // Process the player's move
            std::cout << "Player made a move at (" << row << ", " << col << ")." << std::endl;
        }
    protected:
        // Game board and other protected members can be defined here
        int height, width;
        Player player1, player2;
        vector<Ship> ships; // Example ship sizes
    };

} // battleship

#endif //BATTLESHIP_GAME_H
