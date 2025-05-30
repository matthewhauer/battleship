//
// Created by matth on 5/22/2025.
//

#include "Ship.h"

namespace battleship {
    bool Ship::isStraightOverlap(int row, int col, int size, char orientation) const {
        if(orientation != _orientation)
            return false; // different orientation, no straight overlap
        if(_orientation == 'H') {
            if(_row == row) {
                return !(_col > col + size - 1 || // left of this not impacted
                         _col + shipSize - 1 < col); // right of this not impacted
             }
        } else { // vertical
            if(_col == col) {
                return !(_row > row + size - 1 || // top of this not impacted
                         _row + shipSize - 1 < row); // bottom of this not impacted
             }
        }
        return false;
    }

    bool Ship::isCrossOverlap(int row, int col, int size, char orientation) const {
        if (orientation == _orientation)
            return false; // same orientation, no cross overlap

        // Horizontal ship details
        int hRow = (orientation == 'H') ? row : _row;
        int hColStart = (orientation == 'H') ? col : _col;
        int hColEnd = hColStart + ((orientation == 'H') ? size : shipSize) - 1;

        // Vertical ship details
        int vCol = (orientation == 'V') ? col : _col;
        int vRowStart = (orientation == 'V') ? row : _row;
        int vRowEnd = vRowStart + ((orientation == 'V') ? size : shipSize) - 1;

        // Check overlap
        if (hRow >= vRowStart && hRow <= vRowEnd) { // horizontal row intersects vertical range
            if (vCol >= hColStart && vCol <= hColEnd) { // vertical column intersects horizontal range
                return true;
            }
        }
        return false;
    }

    bool Ship::isOverlapping(int row, int col, int size, char orientation) const {
        if(_row == row && _col == col) {
            return true; // same origin
        }
        if(orientation == _orientation){
            return isStraightOverlap(row, col, size, orientation);
        } else {
            return isCrossOverlap(row, col, size, orientation);
        }
    }
} // battleship