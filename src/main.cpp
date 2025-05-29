//
// Created by matth on 5/22/2025.
//

#include "main.h"

using namespace std;
using namespace battleship;

auto shipSizes = {2, 3, 3, 4, 5};
auto shipNames = {"Destroyer", "Submarine", "Cruiser", "Battleship", "Carrier"};

void promptPlayerShipSetup(Game &game){
    auto shipRefs = game.getShipRefs();
    for (const ShipRef &ship : shipRefs) {
        bool placed = false;
        while(!placed) {
            int row, col;
            char orientation;
            std::cout << "Enter ship shipSize: " << ship.length << ", _row, column, and orientation (H/V): ";
            std::cin >> row >> col >> orientation;
            placed = game.addShip(PlayerEnum::HUMAN, ship.length, row, col, orientation, ship.shipName); // may fail
        }
    }
}

void promptRobotShipSetup(Game &game){
    auto shipSizes = game.getShipSizes();
}

int main(int argc, char *argv[]) {
    // Initialize the game
    Game game;
    game.initialize();

    // setup process
    promptPlayerShipSetup(game);
    promptRobotShipSetup(game);

    // Main game loop
    while (!game.isDone()) {
        // Display the game board
        game.displayBoard();

        // Get player input
        std::string input;
        std::cout << "Enter your move (_row and column): ";
        std::cin >> input;

        // Process the input
        if (input == "exit") {
            break;
        } else {
            int row = input[0] - '0';
            int col = input[2] - '0';
            game.makeMove(row, col);
        }
    }

    return 0;
}