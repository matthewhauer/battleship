//
// Created by matth on 5/22/2025.
//

#include "Game.h"

namespace battleship {
    bool Game::beginSetup(){
        if(state != GameState::NOT_STARTED) {
            std::cout << "Cannot begin setup, game is not in NOT_STARTED state." << std::endl;
            return false;
        }
        // preconditions?
        // two players present with names?
        // may be more here in the future when it isn't a single player game
        state = GameState::SETTING_UP;

        cout << "Beginning setup with player: " << player1.getName() << endl;

        return true;
    }

    bool Game::beginGame(){
        if(state != GameState::SETTING_UP) {
            std::cout << "Cannot begin game, game is not in SETTING_UP state." << std::endl;
            return false; // game is not in setting up state
        }
        // check that both players have ships
        if(!player1.hasAllShips() || !player2.hasAllShips()) {
            std::cout << "Cannot begin game, one or both players do not have ships." << std::endl;
            return false; // one or both players do not have ships
        }
        // check that both players are ready
        if(ranges::fold_left(players,
                             true,
                             [](bool acc, const Player &p) {return acc && p.isReady();})){
            std::cout << "Cannot begin game, one or both players are not ready." << std::endl;
            return false; // one or both players are not ready
        }
        // all checks passed, begin the game
        state = GameState::PLAYING;
        this->currPlayer = begin(players);
        return true;
    }

    /**
     * Check if the game is done.
     * @return true if the game is done and all ships are sunk while
     */
    bool Game::isDone() const {
        std::cout << "Checking if game is done." << std::endl;
        if(state != GameState::SETTING_UP
            && state != GameState::NOT_STARTED
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
        if(state != GameState::SETTING_UP){
            std::cout << "Cannot add ship, game is not in SETTING_UP state." << std::endl;
            return false; // game is not in setting up state
        }
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
        if ((row+(orientation == 'V' ? size-1 : 0)) >= height ||
                (col+(orientation == 'H' ? size-1 : 0)) >= width) {
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

    const vector<ShipRef> &Game::getShipRefs(){
        if(ships.empty()) {
            makeDefaultShips();
        }
        return ships;
    }

    // end of namespace
} // battleship