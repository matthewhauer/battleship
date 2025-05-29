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

struct ShipRef{
    string shipName;
    int length;
};

enum class GameState {
    SETTING_UP,
    PLAYING,
    DONE
};

namespace battleship {
    class Game {
    public:
        Game() : Game("human"sv, 10, 10){};

        Game(string_view playerName, int h, int w) : player1(playerName), player2("Computer"sv),
            board(h, w) {
            if(h <= 0 || w <= 0) {
                throw std::invalid_argument("Board dimensions must be positive integers.");
            }
        }
        void initialize();
        bool isDone() const;
        bool addShip(PlayerEnum &&playerType, int size, int row, int col, char orientation, string_view shipName);
        bool addShip(Player &player, int size, int row, int col, char orientation, string_view shipName);

        vector<int> getShipSizes() {
            return {2, 3, 4, 5};
        }

        void makeDefaultShips(){
            ships = {
                    {"Destroyer", 2},
                    {"Submarine", 3},
                    {"Cruiser", 3},
                    {"Battleship", 4},
                    {"Carrier", 5}
            };
        }

        const vector<ShipRef> &getShipRefs(){
            if(ships.empty()) {
              makeDefaultShips();
            }
            return ships;
        }
        void displayBoard() {

        }

        void makeMove(int row, int col) {
            // Process the player's move
            std::cout << "Player made a move at (" << row << ", " << col << ")." << std::endl;
        }

//        void getShipNames();

    protected:
        // Game board and other protected members can be defined here
        GameBoard board;
        Player player1, player2;
        vector<ShipRef> ships;
        GameState state = GameState::SETTING_UP;
    };

} // battleship

#endif //BATTLESHIP_GAME_H
