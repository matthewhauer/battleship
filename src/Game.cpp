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

    bool Game::addShip(PlayerEnum &playerType, int size, int row, int col, char orientation) {
        return addShip(playerType == PlayerEnum::HUMAN ? player1 : player2, size, row, col, orientation);
    }

    bool Game::addShip(Player &thePlayer, int size, int row, int col, char orientation) {
        // Check if the ship can be placed on the board
        if (row < 0 || (row+size-1) >= height || col < 0 || (col+size-1) >= width) {
            std::cout << "Invalid position." << std::endl;
            return false; // invalid position
        }
        // check for overlap with existing ships
        for (const auto &ship : ships) {
            //int shipRow, shipCol;
            auto [shipRow, shipCol] = ship.getPosition();
            if (ship.isOverlapping(row, col, size, orientation)) {
                std::cout << "Overlap with existing ship." << std::endl;
                return false; // overlap with existing ship
            }
        }
        // Add a ship to the game board
        std::cout << "Added ship of shipSize " << size << " at (" << row << ", " << col << ") with orientation " << orientation << "." << std::endl;
        return true; // successfully added
    }

    // end of namespace
} // battleship