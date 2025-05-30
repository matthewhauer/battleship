//
// Created by matth on 5/22/2025.
//

#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H

#include <string>
#include <vector>
#include <algorithm>

#include "GameBoard.h"
#include "Ship.h"

using namespace std;

namespace battleship {
    using coord = pair<int, int>;
    class Player {
        public:
            Player(string_view name) : name(name) {}

            // Method to get the player's name
            string getName() const {
                return name;
            }

            void addShotMade(coord shot) {
                shotsFired.push_back(shot);
            }

            void addShotSeen(coord shot) {
                shotsSeen.push_back(shot);
            }

            const vector<coord> &getShotsSeen() {
                return shotsSeen;
            }

            const vector<coord> &getShotsFired() {
                return shotsFired;
            }

            bool addShip(string_view shipName, int size, int row, int col, char orientation);

            bool allShipsSunk() const;

            const vector<Ship> &getShips() const;

        bool checkOverlap(int row, int col, int shipSize, char orientation) const;

        bool hasAllShips() const;

        bool isReady() const;

    protected:
            string name;
            vector<coord> shotsFired, shotsSeen;
            vector<Ship> ships;
    };

} // battleship

#endif //BATTLESHIP_PLAYER_H
