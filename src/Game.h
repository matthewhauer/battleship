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

using namespace std;

namespace battleship {
    enum class PlayerEnum {
        HUMAN,
        COMPUTER
    };
    class Game {
        const char WATER{'~'};
    public:
        Game() : Game("human"sv, 10, 10){};

        Game(string_view playerName, int h, int w) : player1(playerName), player2("Computer"sv),
            height(h), width(w) {
            // Initialize the game board with empty spaces
            for(int i = 0; i < height; ++i) {
                for(int j = 0; j < width; ++j) {
                    board[i][j] = WATER; // '~' represents empty water
                }
            }
        }
        void initialize();
        bool isDone() const;
        bool addShip(Player &player, int size, int row, int col, char orientation);

        vector<int> getShipSizes() {
            return {2, 3, 4, 5};
        }

        void displayBoard() {
            // Display the current state of the game board
            //std::cout << "Displaying game board." << std::endl;
            // print column header
            cout << "   ";
            for(int j = 0; j < width; ++j) {
                std::cout << j << " ";
            }
            for(int i = 0; i < height; ++i) {
                // print row header
                std::cout << i << " ";
                for(int j = 0; j < width; ++j) {
                    std::cout << board[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }

        void makeMove(int row, int col) {
            // Process the player's move
            std::cout << "Player made a move at (" << row << ", " << col << ")." << std::endl;
        }
    protected:
        // Game board and other protected members can be defined here
        int height, width;
        Player player1, player2;
        vector<vector<char>> board; // Example board size
        vector<Ship> ships; // Example ship sizes
    };

} // battleship

#endif //BATTLESHIP_GAME_H
