//
// Created by matth on 5/22/2025.
//

#include "Game.h"

namespace battleship {
    void Game::initialize() {
        // Initialize the game board and other game settings
        std::cout << "Game initialized." << std::endl;
    }

    bool Game::isDone() const {
        // Check if the game is done (all ships sunk or player quit)
        std::cout << "Checking if game is done." << std::endl;
        if (ranges::fold_left(ships, false, [](bool acc, const Ship &ship) {
            return acc || ship.isSunk();
        })) {
            return true;
        }
        return false;
    }

    void Game::addShip(Player &thePlayer, int size, int row, int col, char orientation) {
        // Add a ship to the game board
        std::cout << "Added ship of size " << size << " at (" << row << ", " << col << ") with orientation " << orientation << "." << std::endl;
    }

    // end of namespace
} // battleship