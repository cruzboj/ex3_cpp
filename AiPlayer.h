#ifndef AIPLAYER_H
#define AIPLAYER_H
#include "Player.h"
#include <cstdlib>
#include <ctime>

class AiPlayer : public Player {
public:
    AiPlayer(const char* name) : Player(name) {}

    void placeAllShips() override;

    void makeMove(Player* opponent) override ;
};


//AIplaeyr.cpp
void Aiplayer::placeAllShips(){
    for (int i = 0; i < 5; ++i) {
        int row = rand() % 10;
        int col = rand() % 10;
        bool horizontal = rand() % 2;
        if (!grid.inBounds(row, col, ships[i]->getSize(), horizontal) || grid.isTileOccupied(row, col)) {
            --i;  // Retry
        } else {
            grid.placeShip(row, col, ships[i]->getSize(), horizontal, 'S');
        }
    }
}
void AiPlayer::makeMove(Player* opponent){
        int row = rand() % 10;
        int col = rand() % 10;
        if (opponent->grid.getCell(row, col) == 'S') {
            std::cout << "Computer hit!" << std::endl;
            opponent->grid.markHit(row, col);
        } else {
            std::cout << "Computer missed!" << std::endl;
            opponent->grid.markMiss(row, col);
        }
}
#endif
