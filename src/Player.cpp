//
// Created by matth on 5/22/2025.
//

#include "Player.h"

namespace battleship {
    /**
     * Add a ship to the player's fleet.
     * @param shipName Name of the ship
     * @param size Number of cells the ship occupies
     * @param row Row number of the ship's starting position
     * @param col Column number of the ship's starting position
     * @param orientation H for horizontal, V for vertical
     * @return true if the ship was mechanically added to the player's Ship container
     */
    bool Player::addShip(std::string_view shipName, int size, int row, int col, char orientation) {
        // by this point, overlap and bounds have been checked by Game
        // Add the ship to the player's fleet
        ships.emplace_back(shipName, size, row, col, orientation);
        return true; // Successfully added ship
    }

    /**
     * Check if all ships of the player are sunk.
     * @return true if all ships have been sunk
     */
    bool Player::allShipsSunk() const {
        if (ranges::fold_left(ships, true, [](bool acc, const Ship &ship) {
            return acc && ship.isSunk();
        })) {
            return true;
        }
        return false;
    }

    const vector<Ship> & Player::getShips() const {
        return ships;
    }

    /**
     * Check if placing a ship at the given position would overlap with existing ships.
     * @param row row number of the ship's starting position
     * @param col column number of the ship's starting position
     * @param shipSize number of cells the ship occupies
     * @param orientation H for horizontal, V for vertical
     * @return true if overlap
     */
    bool Player::checkOverlap(int row, int col, int shipSize, char orientation) const {
        // Check for overlap with existing ships
        for (const auto &ship : ships) {
            if (ship.isOverlapping(row, col, shipSize, orientation)) {
                return true; // Overlap with existing ship
            }
        }
        return false;
    }

    bool Player::hasAllShips() const {
        //TODO implement this
        return false;
    }

    bool Player::isReady() const {
        //TODO implement this
        return false;
    }
} // battleship