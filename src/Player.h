//
// Created by matth on 5/22/2025.
//

#ifndef BATTLESHIP_PLAYER_H
#define BATTLESHIP_PLAYER_H

#include <string>
#include <vector>

#include "GameBoard.h"
#include "Ship.h"

using namespace std;

namespace battleship {
    using coord = pair<int, int>;
    class Player {
        public:
            Player(string_view name) : name(name), myBoard(), enemyBoard() {}

            // Method to get the player's name
            string getName() const {
                return name;
            }

            // Method to get the player's game board
            GameBoard getMyBoard() const {
                return myBoard;
            }

            // Method to get the enemy's game board
            GameBoard getEnemyBoard() const {
                return enemyBoard;
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

        protected:
            string name;
            GameBoard myBoard, enemyBoard;
            vector<coord> shotsFired, shotsSeen;
            vector<Ship> ships;
    };

} // battleship

#endif //BATTLESHIP_PLAYER_H
