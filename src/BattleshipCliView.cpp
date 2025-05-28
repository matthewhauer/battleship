//
// Created by matth on 5/22/2025.
//

#include "BattleshipCliView.h"

namespace battleship {

    void BattleshipCliView::showBoard(const GameBoard& board, bool revealShips, const PlayerEnum &whichPlayer) const {
        auto [szX, szY] = board.getSize();
        std::cout << "  ";
        for (auto x : views::iota(0, szX))
            std::cout << x << " ";
        std::cout << "\n";

        for (auto y : views::iota(0, szY)) {
            std::cout << y << " ";
            for (auto x : views::iota(0, szX)) {
                /*if (board.wasShotAt(x, y)) {
                    std::cout << (board.isHit(x, y) ? "X " : "O ");
                } else if (revealShips && std::ranges::any_of(board.getShips(), [&](const Ship& s) { return s.occupies(x, y); })) {
                    std::cout << "S ";
                } else {
                    std::cout << ". ";
                }*/
            }
            std::cout << "\n";
        }
    }

    auto BattleshipCliView::promptForCoordinates() const {
        int x, y;
        std::cout << "Enter coordinates (x y): ";
        std::cin >> x >> y;
        return make_pair(x, y);
    }

    void BattleshipCliView::showMessage(const std::string_view& message) const {
        std::cout << message << "\n";
    }
}