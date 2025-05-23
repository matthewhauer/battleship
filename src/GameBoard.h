//
// Created by matth on 5/22/2025.
//

#ifndef BATTLESHIP_GAMEBOARD_H
#define BATTLESHIP_GAMEBOARD_H

#include <vector>

using namespace std;

namespace battleship {

    class GameBoard {
    public:
        pair<int, int> getSize() const;

    protected:
        const char WATER{'~'};
        const char HIT{'X'};
        const char MISS{'O'};
        const int height{10};
        const int width{10};
        //vector<vector<char>> board;//{height, vector<char>(width, WATER)}; // 2D vector to represent the game board
    };

} // battleship

#endif //BATTLESHIP_GAMEBOARD_H
