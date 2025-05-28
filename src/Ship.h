//
// Created by matth on 5/22/2025.
//

#ifndef BATTLESHIP_SHIP_H
#define BATTLESHIP_SHIP_H

#include <vector>
#include <string_view>
#include <string>

using namespace std;

namespace battleship {

    class Ship {
    public:
        // Constructor to initialize the ship with shipSize, _row, column, and orientation
        Ship(string_view name, int size, int row, int col, char orientation)
            : _name(name), shipSize(size), _row(row), _col(col), _orientation(orientation), sunk(false) {}

        // Method to check if the ship is sunk
        bool isSunk() const {
            return sunk;
        }

        // Method to mark the ship as sunk
        void sink() {
            sunk = true;
        }

        // Method to get the shipSize of the ship
        int getSize() const {
            return shipSize;
        }

        // Method to get the position of the ship
        pair<int, int> getPosition() const {
            return make_pair(_row, _col);
        }

        bool isStraightOverlap(int row, int col, int size, char orientation) const {
            // check same row if 'H' or same column if 'V'

            if(_orientation == 'H') {
                if(_row == row)
                    return (_col > col + size -1 && // left of this not impacted
                            _col + shipSize -1 < col); // right of this not impacted
            } else { // vertical
                if(_col == col)
                    return (_row < row + size && // top of this not impacted
                            _row + shipSize > row); // bottom of this not impacted
            }
            return false;
        }

        bool isCrossOverlap(int row, int col, int size, char orientation) const {
            if(_orientation == 'H') {
                return (_row < row + size
                        && _row + shipSize > row);
            } else { // vertical
                return (_col < col + size
                        && _col + shipSize > col);
            }
        }

        bool isOverlapping(int row, int col, int size, char orientation) const {
            if(_row == row && _col == col) {
                return true; // same origin
            }
            if(orientation == _orientation){
                return isStraightOverlap(row, col, size, orientation);
            } else {
                return isCrossOverlap(row, col, size, orientation);
            }
        }

    private:
        string _name;
        int shipSize; // Size of the ship
        vector<bool> hits;
        int _row;  // Row position on the board
        int _col;  // Column position on the board
        char _orientation; // Orientation of the ship ('H' for horizontal, 'V' for vertical)
        bool sunk; // Status of the ship (sunk or not)
    };

} // battleship

#endif //BATTLESHIP_SHIP_H
