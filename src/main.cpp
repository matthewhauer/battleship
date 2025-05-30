//
// Created by matth on 5/22/2025.
//

#include "main.h"

using namespace std;
using namespace battleship;

void promptPlayerShipSetup(Game &game){
    auto shipRefs = game.getShipRefs();
    for (const ShipRef &ship : shipRefs) {
        bool placed = false;
        while(!placed) {
            int row, col;
            char orientation;
            std::cout << "Enter coords for " << ship.shipName << " (l = " << ship.length << "), row, column, and orientation (H/V): ";
            std::cin >> row >> col >> orientation;
            placed = game.addShip(PlayerEnum::HUMAN, ship.length, row, col, toupper(orientation), ship.shipName); // may fail
        }
    }
}

void promptRobotShipSetup(Game &game){
    auto shipSizes = game.getShipSizes();
}

Game GameFromPlayerName(){
    std::string playerName;
    std::cout << "Enter your name: ";
    std::getline(std::cin, playerName);

    // Create a new game with the player's name
    return Game(playerName, 10, 10); // default board size 10x10
}

int main(int argc, char *argv[]) {
    // Initialize the game
    Game game = GameFromPlayerName();

    game.beginSetup();

    // setup process
    promptPlayerShipSetup(game);
    promptRobotShipSetup(game);

    // Main game loop
    while (!game.isDone()) {
        // Display the game board
        //game.displayBoard();

        // Get player input
        std::string input;
        std::cout << "Enter your move (row and column): ";
        getline(std::cin, input);

        // Process the input
        if (input == "exit") {
            break;
        } else {
            int row, col;
            auto result = sscanf(input.c_str(), "%d %d", &row, &col);
            if(result != 2) {
                std::cout << "Invalid input. Please enter row and column numbers." << std::endl;
                continue; // skip to next iteration
            }
            game.makeMove(row, col);
        }
    }

    return 0;
}