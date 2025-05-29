//
// Created by matth on 5/22/2025.
//

#ifndef BATTLESHIP_GAMEBOARD_H
#define BATTLESHIP_GAMEBOARD_H

#include <utility>

using namespace std;

namespace battleship {

    class GameBoard {
    public:
        GameBoard(int h, int w) : height(h), width(w) { }
        pair<int, int> getSize() const;

    protected:
        const int height{10};
        const int width{10};
        // maybe represent the board as a 2D vector in the future, to capture board features.
    };

} // battleship

#endif //BATTLESHIP_GAMEBOARD_H
