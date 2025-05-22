//
// Created by matth on 5/22/2025.
//

#ifndef BATTLESHIP_SHIP_H
#define BATTLESHIP_SHIP_H

#include <vector>

using namespace std;

namespace battleship {

    class Ship {
    public:
        // Constructor to initialize the ship with size, row, column, and orientation
        Ship(int size, int row, int col, char orientation)
            : size(size), row(row), col(col), orientation(orientation), sunk(false) {}

        // Method to check if the ship is sunk
        bool isSunk() const {
            return sunk;
        }

        // Method to mark the ship as sunk
        void sink() {
            sunk = true;
        }

        // Method to get the size of the ship
        int getSize() const {
            return size;
        }

        // Method to get the position of the ship
        void getPosition(int &r, int &c) const {
            r = row;
            c = col;
        }
    private:
        int size; // Size of the ship
        vector<bool> hits;
        int row;  // Row position on the board
        int col;  // Column position on the board
        char orientation; // Orientation of the ship ('H' for horizontal, 'V' for vertical)
        bool sunk; // Status of the ship (sunk or not)
    };

} // battleship

#endif //BATTLESHIP_SHIP_H
