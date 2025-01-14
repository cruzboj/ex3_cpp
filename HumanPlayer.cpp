//humanplayer.cpp

#include "HumanPlayer.h"
void HumanPlayer::placeAllShips() {
        int row, col;
        bool horizontal;
        for (int i = 0; i < 5; ++i) {
            do {
                std::cout << "Enter the row and column (1-10) for " << ships[i]->getName() << ": ";
                std::cin >> row >> col;
                std::cout << "Enter 1 for horizontal, 0 for vertical: ";
                std::cin >> horizontal;
            } while (!grid.inBounds(row - 1, col - 1, ships[i]->getSize(), horizontal) || grid.isTileOccupied(row - 1, col - 1));
            grid.placeShip(row - 1, col - 1, ships[i]->getSize(), horizontal, 'S');
        }
}

void HumanPlayer::makeMove(Player* opponent){
    int row, col;
        std::cout << "Enter the row and column to attack: ";
        std::cin >> row >> col;
        if (opponent->grid.getCell(row - 1, col - 1) == 'S') {
            std::cout << "Hit!" << std::endl;
            opponent->grid.markHit(row - 1, col - 1);
            for (int i = 0; i < 5; ++i) {
                if (opponent->ships[i]->getSize() > 0) {
                    opponent->ships[i]->takeHit();
                    if (opponent->ships[i]->isSunk()) {
                        std::cout << opponent->ships[i]->getName() << " is sunk!" << std::endl;
                    }
                }
            }
        } else {
            std::cout << "Miss!" << std::endl;
            opponent->grid.markMiss(row - 1, col - 1);
        }
}
