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
        if(state != GameState::SETTING_UP
            &&  (player1.allShipsSunk()
                || player2.allShipsSunk())) {
            std::cout << "Game is done." << std::endl;
            return true; // game is done
        }
        return false;
    }

    bool Game::addShip(PlayerEnum &&playerType, int size, int row, int col, char orientation, string_view shipName) {
        return addShip(playerType == PlayerEnum::HUMAN ? player1 : player2, size, row, col, orientation, shipName);
    }

    bool Game::addShip(Player &thePlayer, int size, int row, int col, char orientation, string_view shipName = "AnonShip"sv) {
        if(size <= 0) {
            std::cout << "Invalid ship size. Must be greater than 0." << std::endl;
            return false; // invalid ship size
        }
        const auto [height, width] = board.getSize();
        // Check if the ship can be placed on the board
        if (row < 0 ||  col < 0) {
            std::cout << "Invalid position." << std::endl;
            return false; // invalid position
        }
        // Check outer bounds of the board
        if ((row+(orientation == 'H' ? size : 0)) >= height ||
                (col+(orientation == 'V' ? size : 0)) >= width) {
            std::cout << "Ship position out of bounds." << std::endl;
            return false; // out of bounds
        }
        // Check if the orientation is valid
        if (orientation != 'H' && orientation != 'V') {
            std::cout << "Invalid orientation. Use 'H' for horizontal or 'V' for vertical." << std::endl;
            return false;
        }
        // Check for overlap with existing ships
        if(thePlayer.checkOverlap(row, col, size, orientation)) {
            cout << "Overlap with existing ships." << endl;
            return false;
        }
        // Add a ship to the game board
        if(thePlayer.addShip(shipName, size, row, col, orientation)) {
            std::cout << "Added ship of shipSize " << size << " at (" << row << ", " << col << ") with orientation "
                      << orientation << "." << std::endl;
            return true; // successfully added
        } else {
            std::cout << "Failed to add ship to player." << std::endl;
            return false; // failed to add ship
        }
        return false; // fall-through
    }

//    void Game::getShipNames() {
//
//    }

    // end of namespace
} // battleship