//
// Created by matth on 5/22/2025.
//

#ifndef BATTLESHIP_BATTLESHIPCLIVIEW_H
#define BATTLESHIP_BATTLESHIPCLIVIEW_H

#include <iostream>
#include <string_view>

#include "GameBoard.h"
#include "PlayerEnum.h"

using namespace std;

namespace battleship {
    class BattleshipCliView {
    public:
        void showBoard(const GameBoard& board, bool revealShips = false, const PlayerEnum &whichPlayer = PlayerEnum::HUMAN) const;
        pair<int, int> promptForCoordinates() const;
        void showMessage(const string_view& message) const;
    };
}

#endif //BATTLESHIP_BATTLESHIPCLIVIEW_H
