//
// Created by matth on 5/22/2025.
//

#include "GameBoard.h"

namespace battleship {
    pair<int, int> GameBoard::getSize() const {
        return pair<int, int>(height, width);
    }
} // battleship